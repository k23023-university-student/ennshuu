#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
// #define FILE_NAME "red_rectangle.jpg"
#define FILE_NAME "canvas.jpg"
#define HIGHVAL (255)
#define LOWVAL (0)
// #define TH (100)
#define TH (127)

int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img, gray_img, bin_img; // 画像の型と変数

    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR); // 画像の読み込み

    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    //輝度画像へ変換
    // cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    bin_img.create(src_img.size(), src_img.type());
    // cv::threshold(gray_img, bin_img, TH, HIGHVAL, cv::THRESH_BINARY);
    cv::threshold(src_img, bin_img, TH, HIGHVAL, cv::THRESH_BINARY_INV);
    cv::imshow("input image", src_img);
    // cv::imshow("grayscale image", gray_img);
    cv::imshow("binary image", bin_img);
    cv::waitKey();
    return 0;
}