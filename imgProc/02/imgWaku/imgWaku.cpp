#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./aquarium.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
int main(int argc, const char * argv[]) {
 int x, y;
 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME); //画像の読み込み
 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }

 cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC3);

 for(y=0;y<src_img.rows;y++){//縦

    for(x=0;x<src_img.cols;x++){//横

        cv::Vec3b s = src_img.at<cv::Vec3b>(y,x);
        if(x < 10 || x > src_img.cols-10 || y<10 || y>src_img.rows-10){
            s[0] = 0;
            s[1] = 0;
            s[2] = 0;
        }else{
            s[0] = s[0];
            s[1] = s[1];
            s[2] = s[2];
        }

        dst_img.at<cv::Vec3b>(y,x) = s;
    }

 }

 cv::imshow(WINDOW_NAME_INPUT, src_img);

 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);

 cv::waitKey();
 return 0;
}