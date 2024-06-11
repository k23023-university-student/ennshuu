#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME "apple_grayscale.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define FILTER_SIZE (9)
int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img; // 画像の型と変数

    src_img = cv::imread(FILE_NAME, 0); // 画像の読み込みグレースケール

    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }
    cv::Mat median_img;
    cv::medianBlur(src_img, median_img, FILTER_SIZE);
    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_OUTPUT, median_img);
    cv::waitKey();
    return 0;
}