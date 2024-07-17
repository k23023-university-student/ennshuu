#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE_FILE "sakura.jpg"

int main() {
    // 画像を読み込む
    cv::Mat src_img = cv::imread(INPUT_IMAGE_FILE);
    
    // 画像が正常に読み込まれたかチェック
    if (src_img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // 入力画像を表示
    cv::imshow("Original Image (Color)", src_img);

    // カラー画像をグレースケールに変換
    cv::Mat gray_img;
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    // ネガポジ変換のためのLUTを作成
    cv::Mat lut(1, 256, CV_8UC1);
    for (int i = 0; i < 256; i++) {
        lut.at<uchar>(i) = 255 - i;
    }

    // ネガポジ変換のためのループ
    cv::Mat neg_img = gray_img.clone();
    for (int y = 0; y < gray_img.rows; y++) {
        for (int x = 0; x < gray_img.cols; x++) {
            uchar pixel_value = gray_img.at<uchar>(y, x);
            neg_img.at<uchar>(y, x) = lut.at<uchar>(pixel_value);
        }
    }

    // グレースケール画像を表示
    cv::imshow("Gray Image", gray_img);

    // ネガポジ変換画像を表示
    cv::imshow("Negative Image", neg_img);

    // 任意のキーが押されるまで待機
    cv::waitKey(0);

    return 0;
}
