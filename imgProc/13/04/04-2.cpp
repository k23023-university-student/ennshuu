#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE "image2.jpg"

int main() {
    // 画像の読み込み
    cv::Mat src_img = cv::imread(INPUT_IMAGE, cv::IMREAD_GRAYSCALE);
    if (src_img.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // ヒストグラムを初期化
    int hist_size = 256;
    int hist[256] = {0};

    // ヒストグラムの作成
    for (int i = 0; i < src_img.rows; i++) {
        for (int j = 0; j < src_img.cols; j++) {
            hist[src_img.at<uchar>(i, j)]++;
        }
    }

    // 閾値121より小さい部分の画素数を求める
    int pixel_count_below_threshold = 0;
    for (int i = 0; i < 121; i++) {
        pixel_count_below_threshold += hist[i];
    }

    std::cout << "Pixel count below threshold 121: " << pixel_count_below_threshold << std::endl;

    // 入力画像を表示
    cv::imshow("Input Image", src_img);

    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
