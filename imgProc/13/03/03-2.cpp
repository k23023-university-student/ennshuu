#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE_FILE "Mandrill.png"

// トーンカーブ関数の定義
uchar toneR(uchar n) {  // 赤用のトーンカーブ関数
    uchar v;

    if (n <= 128)
        v = 0;
    else if (n <= 192)
        v = static_cast<uchar>((255.0 / (192 - 128)) * (n - 128));
    else
        v = 255;

    return v;
}

uchar toneG(uchar n) {  // 緑用のトーンカーブ関数
    uchar v;

    if (n <= 64)
        v = static_cast<uchar>((255.0 / 64) * n);
    else if (n <= 192)
        v = 255;
    else
        v = static_cast<uchar>(((-255.0) / (255 - 192)) * (n - 255));

    return v;
}

uchar toneB(uchar n) {  // 青用のトーンカーブ関数
    uchar v;

    if (n <= 64)
        v = 255;
    else if (n <= 128)
        v = static_cast<uchar>(((-255.0) / (128 - 64)) * (n - 128));
    else
        v = 0;

    return v;
}

int main() {
    // 画像の読み込み
    cv::Mat src_img = cv::imread(INPUT_IMAGE_FILE, cv::IMREAD_GRAYSCALE);
    if (src_img.empty()) {
        std::cerr << "Error: Could not read the image file." << std::endl;
        return -1;
    }

    // 出力画像用のMat変数
    cv::Mat dst_img(src_img.size(), CV_8UC3);

    // 画像処理（トーンカーブを適用した擬似カラー画像生成）
    for (int y = 0; y < src_img.rows; ++y) {
        for (int x = 0; x < src_img.cols; ++x) {
            uchar intensity = src_img.at<uchar>(y, x);
            dst_img.at<cv::Vec3b>(y, x) = cv::Vec3b(toneB(intensity), toneG(intensity), toneR(intensity));
        }
    }

    // 入力画像の表示
    cv::imshow("Input Grayscale Image", src_img);

    // 出力画像の表示
    cv::imshow("Output Pseudo Color Image", dst_img);

    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
