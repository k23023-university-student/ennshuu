#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./fruit_image.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_NUM (256)
int main(int argc, const char * argv[]) {
 int x, y;
 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, cv::IMREAD_GRAYSCALE); //画像の読み込み
 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }

 cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC1);//出力画像のメモリ確保

 uchar lut[COLOR_NUM];

 //ルックアップデーブルの生成（４段階)
 for(int i=0;i<COLOR_NUM;i++){
    if(i <= 63){
        lut[i] = 0;
    }else if(64 <= i && i<= 127){
        lut[i] = 85;
    }else if(128 <= i && i<= 191){
        lut[i] = 170;
    }else{
        lut[i] = 255;
    }
 }


  for(y=0;y<dst_img.rows;y++){//縦

    for(x=0;x<dst_img.cols;x++){//横

        uchar s = src_img.at<uchar>(y,x);
        dst_img.at<uchar>(y,x) = lut[s];
    }

 }


 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}