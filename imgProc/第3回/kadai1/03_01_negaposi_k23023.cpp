#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./sakura.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_NUM (256)
int main(int argc, const char * argv[]) {
 int x, y;
 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME); //画像の読み込み
 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }

 cv::Mat gray_img = cv::Mat(src_img.size(), CV_8UC1);//グレースケール画像用のメモリを確保
 cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC1);//出力画像のメモリ確保

  for(y=0;y<src_img.rows;y++){//グレースケール変換

    for(x=0;x<src_img.cols;x++){

        cv::Vec3b s = src_img.at<cv::Vec3b>(y,x);

        s[0] = s[0];
        s[1] = s[1];
        s[2] = s[2];
        uchar val = 0.114 * s[0] //B
                  + 0.587 * s[1] // G
                  + 0.299 * s[2];// R
        gray_img.at<uchar>(y,x) = val;
    }

 }
 

 uchar lut[COLOR_NUM];

 //ネガポジ変換ルックアップデーブルの生成
 for(int i=0;i<COLOR_NUM;i++){
    lut[i] = 255 - i;
 }


  for(y=0;y<dst_img.rows;y++){//縦

    for(x=0;x<dst_img.cols;x++){//横

        uchar s = gray_img.at<uchar>(y,x);
        dst_img.at<uchar>(y,x) = lut[s];
    }

 }


 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}