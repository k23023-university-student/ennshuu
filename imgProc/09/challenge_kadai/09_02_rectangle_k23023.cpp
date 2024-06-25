

#include <iostream>
#include <opencv2/opencv.hpp>

// ファイル
#define FILE_NAME "sample.jpg"
// ウィンドウ名
#define WINDOW_NAME_INPUT "input"

#define WINDOW_NAME_OUTPUT "output"

// 二値化しきい値
#define BIN_TH (100)

int main(int argc, const char *argv[])
{
    // 1. 画像の宣言 (入力画像，グレースケール画像，二値画像，一時的な画像，出力画像)
    cv::Mat src_img, gray_img, bin_img, tmp_img, dst_img;

    // 2. 輪郭の座標リストの宣言 (New!)
    std::vector<std::vector<cv::Point>> contours;

    // 3. 画像の入力 (カラーで入力)
    src_img = cv::imread(FILE_NAME);
    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    // 4. 入力画像を出力画像にコピー (New!)

    dst_img = src_img.clone();

    // 5. グレースケール化
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    // 6. 二値化 (固定しきい値で実装．しきい値: 100)

    cv::threshold(gray_img, bin_img, BIN_TH, 255, cv::THRESH_BINARY);
    // 二値画像コピー (New!)
    tmp_img = bin_img.clone();
    // 7. 輪郭追跡 (New!)

    cv::findContours(tmp_img, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

    // 8.1 領域特徴量の取得・表示

    int targetIndex = 0;
    for (int i = 0; i < (int)contours.size(); i++)
    {
        double L = cv::arcLength(contours[i], true);
        double S = cv::contourArea(contours[i]);

        double R = (4 * M_PI) * S / (L * L);

        if(R > 0.64 && R < 0.65) targetIndex = i;
    }
    // 8.2 輪郭塗りつぶし描画

    cv::drawContours(dst_img, contours, targetIndex, CV_RGB(255, 0, 255), -1);//index=10

    // 9. 表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);

    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
    cv::waitKey();

    return 0;
}
