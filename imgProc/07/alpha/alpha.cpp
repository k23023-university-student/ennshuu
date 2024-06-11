#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME1 "input1.jpg"
#define FILE_NAME2 "input2.jpg"
#define WINDOW_NAME_INPUT1 "input1"
#define WINDOW_NAME_INPUT2 "input2"
#define WINDOW_NAME_OUTPUT "output"
#define FILTER_SIZE (9)
#define ALPHA (0.5)
int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img1; // 画像の型と変数
    cv::Mat src_img2;
    src_img1 = cv::imread(FILE_NAME1, 0); // 画像の読み込みグレースケール
    src_img2 = cv::imread(FILE_NAME2, 0); // 画像の読み込みグレースケール

    cv::Mat result_img = cv::Mat(src_img1.size(), CV_8UC1);

    if (src_img1.empty() || src_img2.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    for(int y=0;y<src_img1.rows;y++){
        for(int x=0;x<src_img1.cols;x++){
            //画素値の取得(double)
            double s1 = (double)src_img1.at<unsigned char>(y, x);
            double s2 = (double)src_img2.at<unsigned char>(y, x);

            int s_result = ALPHA * s1 + (1.0-ALPHA) * s2;
            result_img.at<unsigned char>(y,x) = (unsigned char)s_result;
        }
    }

    cv::imshow(WINDOW_NAME_INPUT1, src_img1);
    cv::imshow(WINDOW_NAME_INPUT2, src_img2);
    cv::imshow(WINDOW_NAME_OUTPUT, result_img);
    cv::waitKey();
    return 0;
}