#include <opencv2/opencv.hpp>
#include <iostream>

#define INPUT_IMAGE "aquarium.jpg"

int main() {
    // 画像を読み込む
    cv::Mat input_image = cv::imread(INPUT_IMAGE);

    // 画像が正しく読み込まれたか確認
    if (input_image.empty()) {
        std::cerr << "画像を読み込めませんでした: " << INPUT_IMAGE << std::endl;
        return -1;
    }

    // 画像のサイズを取得
    int height = input_image.rows;
    int width = input_image.cols;

    // 新しい画像を作成（入力画像と同じサイズ、同じタイプ）
    cv::Mat output_image(height, width, input_image.type());

    // 上半分を元の画像と同じにする
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            output_image.at<cv::Vec3b>(y, x) = input_image.at<cv::Vec3b>(y, x);
        }
    }

    // 下半分を赤成分のみにする
    for (int y = height / 2; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cv::Vec3b pixel = input_image.at<cv::Vec3b>(y, x);
            // 赤成分のみ残し、他の成分は0に設定
            output_image.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, pixel[2]);
        }
    }

    // 生成された画像を保存
    cv::imwrite("output_image.jpg", output_image);

    // 生成された画像を表示
    cv::imshow("Output Image", output_image);
    cv::waitKey(0);

    return 0;
}
