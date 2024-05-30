#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME "apple_tree.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "Gaussian"
#define WINDOW_NAME_OUTPUT2 "Sobel"
#define FILTER_SIZE (5)
int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img; // 画像の型と変数

    src_img = cv::imread(FILE_NAME); // 画像の読み込みカラーで
    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    cv::Mat gray_img = cv::Mat(src_img.size(), CV_8UC1); // グレースケール変換後の画像データ
    cv::Mat gaussian_img;                                // ガウシアンフィルタ適用後の画素データ
    cv::Mat dst_img;                                     // 最終出力先の画像データ

    // グレースケールへ変換
    for (int y = 0; y < src_img.rows; y++)
    { // 縦

        for (int x = 0; x < src_img.cols; x++)
        { // 横

            cv::Vec3b s = src_img.at<cv::Vec3b>(y, x);

            s[0] = s[0];
            s[1] = s[1];
            s[2] = s[2];
            uchar val = 0.114 * s[0]    // B
                        + 0.587 * s[1]  // G
                        + 0.299 * s[2]; // R
            gray_img.at<uchar>(y, x) = val;
        }
    }

    cv::GaussianBlur(gray_img, gaussian_img, cv::Size(FILTER_SIZE, FILTER_SIZE), 0);

    cv::Sobel(gray_img, dst_img, CV_32F, 0, 1);//ソーベルフィルタ
    cv::convertScaleAbs(dst_img,dst_img);//適切な値に変換

    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_OUTPUT, gaussian_img);
    cv::imshow(WINDOW_NAME_OUTPUT2, dst_img);
    cv::waitKey();
    return 0;
}
