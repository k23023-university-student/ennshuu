#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./image2.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_MAX (256)
int main(int argc, const char * argv[]) {

 int i, x, y;//アクセス用の変数
 
 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール




 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }



//閾値を超えたピクセル数を計算

int pixelCount = 0;//ピクセル数のカウント
for(int y=0;y<src_img.rows;y++){
    for(x=0;x<src_img.cols;x++){

        //画素値の取得
        unsigned char s = src_img.at<unsigned char>(y,x);
        if(s < 121){ //閾値が121より小さいとき
            
            pixelCount++;
        }

    }

}
fprintf(stdout,"%d\n",pixelCount);
 return 0;
}