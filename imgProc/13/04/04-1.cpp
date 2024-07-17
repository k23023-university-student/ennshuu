#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE "image1.jpg"
#define THRESHOLD_VALUE 133

int main() {
    // 画像をグレースケールで読み込む
    cv::Mat src_img = cv::imread(INPUT_IMAGE, cv::IMREAD_GRAYSCALE);

    // 画像が正しく読み込まれたかを確認
    if(src_img.empty()) {
        std::cerr << "Error: Unable to load image " << INPUT_IMAGE << std::endl;
        return -1;
    }

    // 入力画像を表示
    cv::imshow("Input Image", src_img);

    // 出力画像用のcv::Matを定義
    cv::Mat dst_img = cv::Mat::zeros(src_img.size(), CV_8UC1); // 出力画像を初期化し、全体を黒にする

    // 閾値処理を手動で実行
    for (int y = 0; y < src_img.rows; ++y) {
        for (int x = 0; x < src_img.cols; ++x) {
            if (src_img.at<uchar>(y, x) < THRESHOLD_VALUE) {
                dst_img.at<uchar>(y, x) = 255; // 閾値未満の部分を白にする
            }
        }
    }

    // 出力画像を表示
    cv::imshow("Processed Image", dst_img);

    // 任意のキーが押されるまで待機
    cv::waitKey(0);

    return 0;
}
