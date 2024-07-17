#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE "apple_grayscale.jpg"
#define FILTER_SIZE 5

int main() {
    // 画像の読み込み
    cv::Mat src_img = cv::imread(INPUT_IMAGE, cv::IMREAD_GRAYSCALE);
    if (src_img.empty()) {
        std::cerr << "入力画像が見つかりません: " << INPUT_IMAGE << std::endl;
        return -1;
    }

    // フィルタサイズが奇数かどうかのチェック
    if (FILTER_SIZE % 2 == 0) {
        std::cerr << "フィルタサイズが偶数です。FILTER_SIZEは奇数でなければなりません。" << std::endl;
        return -1;
    }

    cv::Mat dst_img;

    // 平均化フィルタの適用
    // cv::blur関数を使用して平均化フィルタを適用します。
    cv::blur(src_img, dst_img, cv::Size(FILTER_SIZE, FILTER_SIZE));

    // 入力画像の表示
    cv::imshow("Input Image", src_img);

    // 出力画像の表示
    cv::imshow("Output Image", dst_img);

    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
