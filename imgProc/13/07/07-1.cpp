#include <opencv2/opencv.hpp>
#include <iostream>

// 入力画像ファイル名の定義
#define INPUT_IMAGE_1 "issue_input2.jpg"
#define INPUT_IMAGE_2 "issue_input1.jpg"
#define FILTER_SIZE 5
#define THRESHOLD_DIFF 20 // 閾値を20に変更

int main() {
    // 画像の読み込み (グレースケール)
    cv::Mat src_img1 = cv::imread(INPUT_IMAGE_1, cv::IMREAD_GRAYSCALE);
    cv::Mat src_img2 = cv::imread(INPUT_IMAGE_2, cv::IMREAD_GRAYSCALE);

    // ガウシアンフィルタを適用する
    cv::Mat filtered_img1;
    cv::GaussianBlur(src_img1, filtered_img1, cv::Size(FILTER_SIZE, FILTER_SIZE), 0);

    // 出力画像の初期化
    cv::Mat output_color = cv::Mat::zeros(src_img1.size(), CV_8UC3);

    // ループ処理で画素ごとの明るさの差を求める
    for (int y = 0; y < src_img2.rows; ++y) {
        for (int x = 0; x < src_img2.cols; ++x) {
            // 画素ごとの明るさの差を計算
            int diff = std::abs(src_img2.at<uchar>(y, x) - filtered_img1.at<uchar>(y, x));
            
            // 差が閾値を超えた場合、赤要素を255とする
            if (diff > THRESHOLD_DIFF) {
                output_color.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 255); // 赤要素を255
            }
        }
    }

    // 画像の表示
    cv::imshow("Color Output Image", output_color);

    // 入力画像の表示
    cv::imshow("Input Image 1", src_img1);
    cv::imshow("Input Image 2", src_img2);

    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
