#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./three_objects.jpg"

#define HIGHVAL (255)
#define LOWVAL (0)
#define COLOR_MAX (256)

int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img, R_img,G_img,B_img; // 画像の型と変数

    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR); // 画像の読み込み

    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    //輝度画像へ変換
    // cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    R_img.create(src_img.size(), src_img.type());
    G_img.create(src_img.size(), src_img.type());
    B_img.create(src_img.size(), src_img.type());

    int histR[COLOR_MAX],histG[COLOR_MAX],histB[COLOR_MAX];//ヒストグラム用配列

    for(int i=0;i<COLOR_MAX;i++){//ヒストグラム用の配列の初期化

        histR[i] = 0;
        histG[i] = 0;
        histB[i] = 0;

    }


    double p = (1 - 0.16) / 1;//背景(100-16)%, 図形16%
    int sum = src_img.rows * src_img.cols;//すべての画素数の合計を求める

    for (int y = 0; y < src_img.rows; y++)
    { 
        for (int x = 0; x < src_img.cols; x++)
        {
            cv::Vec3b s = src_img.at<cv::Vec3b>(y,x);//輝度値の取得
            histR[s[2]]++;
            histG[s[1]]++;
            histB[s[0]]++;
        }
    }

    int thR = 0,thG = 0,thB = 0;
    int sumR = 0, sumG = 0,sumB = 0;
    for(int i=0;i<COLOR_MAX;i++){//閾値を求める操作

        if(sum * p > sumR) {
            thR = i;
            sumR += histR[i];
        }

        if(sum * p > sumG) {
            thG = i;
            sumG += histG[i];
        }

        if(sum * p > sumB) {
            thB = i;
            sumB += histB[i];
        }

    }
    printf("R: %d\nG: %d\nB: %d\n",thR,thG,thB);

    for (int y = 0; y < src_img.rows; y++)
    { 
        for (int x = 0; x < src_img.cols; x++)
        {

            cv::Vec3b s = src_img.at<cv::Vec3b>(y,x);
            cv::Vec3b r(LOWVAL,LOWVAL,LOWVAL),g(LOWVAL,LOWVAL,LOWVAL),b(LOWVAL,LOWVAL,LOWVAL);

            if(s[0] > thB){
                b[0] = HIGHVAL;
            } else if(s[1] > thG){
                g[1] = HIGHVAL;
            }else if(s[2] > thR){
                r[2] = HIGHVAL;
            }

            R_img.at<cv::Vec3b>(y,x) = r;
            G_img.at<cv::Vec3b>(y,x) = g;
            B_img.at<cv::Vec3b>(y,x) = b;
        }
    }
    cv::imshow("input image", src_img);
    cv::imshow("color image - R", R_img);
    cv::imshow("color image - G", G_img);
    cv::imshow("color image - B", B_img);
    cv::waitKey();
    return 0;
}