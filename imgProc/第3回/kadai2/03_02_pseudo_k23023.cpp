#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./shell.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_NUM (256)
//関数を定義
uchar toneR(uchar);
uchar toneG(uchar);
uchar toneB(uchar);

int main(int argc, const char * argv[]) {
 int x, y;
 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, cv::IMREAD_GRAYSCALE); //画像の読み込み
 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }

 cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC3);//出力画像のメモリ確保


  for(y=0;y<dst_img.rows;y++){//縦

    for(x=0;x<dst_img.cols;x++){//横

        uchar val = src_img.at<uchar>(y,x);
        cv::Vec3b s = src_img.at<cv::Vec3b>(y,x);
        s[0] = toneB(val);//b
        s[1] = toneG(val);//g
        s[2] = toneR(val);//r
        dst_img.at<cv::Vec3b>(y,x) = s;
    }

 }


 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}



uchar toneR(uchar n){//赤用のトーンカーブ関数
  uchar v;

  if(n <= 128) v = 0;
  else if(n <= 192) v = (255/(192-128)) * (n-128);
  else v = 255;

  return v;
}

uchar toneG(uchar n){//緑用のトーンカーブ関数
  uchar v;

  if(n <= 64) v = (255/64) * n;
  else if(n <= 192) v = 255;
  else v = ((0-255)/(255-192)) * (n - 255);

  return v;
}

uchar toneB(uchar n){//青用のトーンカーブ関数
  uchar v;

  if(n <= 64) v = 255;
  else if(n <= 128) v = ((0-255)/(128-64)) * (n-128);
  else v = 0;

  return v;
}