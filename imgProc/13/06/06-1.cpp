#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE "apple_tree.jpg"

int main() {
    // 入力画像を読み込む
    cv::Mat src_img = cv::imread(INPUT_IMAGE);

    // 入力画像が読み込まれたか確認する
    if(src_img.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // 入力画像を表示
    cv::imshow("Input Image", src_img);

    // ガウシアンフィルタを適用する
    cv::Mat gaussian_img;
    cv::GaussianBlur(src_img, gaussian_img, cv::Size(5, 5), 1.5);

    // ガウシアンフィルタ適用済み画像を表示
    cv::imshow("Gaussian Blurred Image", gaussian_img);

    // ソーベルフィルタ（縦）を適用する
    cv::Mat sobel_img;
    cv::Sobel(gaussian_img, sobel_img, CV_8U, 1, 0);

    // ソーベルフィルタ適用済み画像を表示
    cv::imshow("Sobel Image", sobel_img);

    // すべてのウィンドウを表示する
    cv::waitKey(0);

    return 0;
}
