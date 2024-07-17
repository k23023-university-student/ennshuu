#include <opencv2/opencv.hpp>
#include <iostream>

// 入力画像のファイル名を定義する
#define INPUT_IMAGE_FILE "ptile.jpg"

int main() {
    // 入力画像の読み込み
    cv::Mat src_img = cv::imread(INPUT_IMAGE_FILE, cv::IMREAD_GRAYSCALE);
    if (src_img.empty()) {
        std::cerr << "Error: Could not read the image file." << std::endl;
        return -1;
    }

    // 出力画像の準備（同じサイズで初期化）
    cv::Mat output_img = cv::Mat::zeros(src_img.size(), CV_8UC1);

    // ヒストグラムの作成（画素値ごとの度数を格納する配列）
    int hist[256] = {0};
    for (int y = 0; y < src_img.rows; ++y) {
        for (int x = 0; x < src_img.cols; ++x) {
            int pixel_value = src_img.at<uchar>(y, x);
            hist[pixel_value]++;
        }
    }

    // 背景の面積と文字の面積の比率を計算
    double background_ratio = 4.0 / (4.0 + 1.0);
    int total_pixels = src_img.rows * src_img.cols;
    int required_pixels = static_cast<int>(total_pixels * background_ratio);

    // ヒストグラムを走査してしきい値を決定する
    int threshold = 0;
    int accumulated_pixels = 0;
    for (int i = 0; i < 256; ++i) {
        accumulated_pixels += hist[i];
        if (accumulated_pixels > required_pixels) {
            threshold = i;
            break;
        }
    }

    // ２値化処理
    cv::threshold(src_img, output_img, threshold, 255, cv::THRESH_BINARY);

    // 入力画像と出力画像をimshowで表示
    cv::imshow("Input Image", src_img);
    cv::imshow("Binary Output Image", output_img);
    cv::waitKey(0);

    return 0;
}
