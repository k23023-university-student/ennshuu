#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./kagoshima.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"


int main(int argc, const char * argv[]) {

 int x, y;//アクセス用の変数

 unsigned char Imin, Imax, Dmin, Dmax;
 //2. 初期値の入力
 Imax = 0;
 Imin = 255;

 //変換後の画素値入力

  Dmin = 0;
  Dmax = 255;

 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "File is not opened\n");
 return (-1);
 }

 //グレースケール向けに出力画像のメモリ確保
 cv::Mat dst_img = cv::Mat(src_img.size(), CV_8UC1);
 

for(int y=0;y<src_img.rows;y++){
    for(x=0;x<src_img.cols;x++){

        //画素値の取得
        unsigned char s = src_img.at<unsigned char>(y,x);
        //最小値の取得

        if(Imin > s){
            Imin = s;
        }
        if(Imax < s){
            Imax = s;
        }

    }

}

 fprintf(stderr,"Imin=%d\n,Imax=%d\n", Imin, Imax);

 //線形変換(入力画像、出力画像)
 for(int y=0;y<src_img.rows;y++){
    for(x=0;x<src_img.cols;x++){

        //画素値の取得
        unsigned char s = src_img.at<unsigned char>(y,x);

        s = (Dmax - Dmin)/(Imax - Imin)* (s - Imin) + Dmin;
        dst_img.at<unsigned char>(y,x) = s;

    }

}
 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}