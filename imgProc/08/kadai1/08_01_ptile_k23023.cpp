#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME "ptile.jpg"

#define HIGHVAL (255)
#define LOWVAL (0)
#define COLOR_MAX (256)

int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img, gray_img, bin_img; // 画像の型と変数

    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR); // 画像の読み込み

    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    //輝度画像へ変換
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    bin_img.create(gray_img.size(), gray_img.type());



    int hist[COLOR_MAX];//ヒストグラム用配列

    for(int i=0;i<COLOR_MAX;i++){//ヒストグラム用の配列の初期化

        hist[i] = 0;
    }


    double p = 4.0 / (4.0+1.0);//背景4, 文字1
    int sum = 0;//すべての画素数の合計を求める
    for (int y = 0; y < gray_img.rows; y++)
    { 
        for (int x = 0; x < gray_img.cols; x++)
        {
            unsigned char s = gray_img.at<unsigned char>(y,x);//輝度値の取得
            hist[s]++;
            sum++;
        }
    }

    int th = 0;
    int sum2 = 0;
    for(int i=0;i<COLOR_MAX;i++){//前から順番に画素数をカウントしていく
        th = i;
        if(sum * p < sum2) break;//背景の画素数を超えたらループから抜ける
        sum2 += hist[i];
    }
    printf("%d\n",th);

    for (int y = 0; y < gray_img.rows; y++)
    { 
        for (int x = 0; x < gray_img.cols; x++)
        {
            if(gray_img.at<unsigned char>(y,x) > th){
                bin_img.at<unsigned char>(y,x) = HIGHVAL;
            }else{
                bin_img.at<unsigned char>(y,x) = LOWVAL;
            }
        }
    }
    cv::imshow("input image", src_img);
    cv::imshow("grayscale image", gray_img);
    cv::imshow("binary image", bin_img);
    cv::waitKey();
    return 0;
}