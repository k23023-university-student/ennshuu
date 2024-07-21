#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LENGTH 128
#define MAX_DAY 3650    // 記録できる最大の日数(10年)
#define WEIGHT_COLUMN 3 // 体重を表すのはCSVの何列目か
#define MAX_PATH 256    // パスの最大長
#define FILE_NAME "data.csv"
int fileLoader(char *, char (*)[]);
void fileSaver(char *, char *);
double getAverage(double(*), int);
double getBmi(double, double);
void convertToCsv(double[MAX_DAY][4], char *, int);
int parseCsv(char *, double[]);
time_t getEpochTime(int y, int m, int d);

void showStatistic(void);
void addData(void);
void showData(void);
void editData(void);
void showGraph(void);
int main(int argc, const char *argv[])
{
    // キーボードからの入力 すべき処理を格納する変数
    /*
    0-> 終了
    1-> 体重新規入力
    2-> 編集モード（編集＆削除）
    3-> 平均値等表示
    4-> グラフ表示(gnuplot)


    */
    int whatToDo = -1; // 行う処理の種類
    while (whatToDo != 0)
    {                       // プログラムのメインループ
        printf("\x1b[33m"); // 黄色文字ここから
        printf("<<<メインメニュー>>>\n"
               "[0]: プログラムの終了\n"
               "[1]: 体重の新規入力\n"
               "[2]: 入力値の編集\n"
               "[3]: データ一覧表示\n"
               "[4]: 全期間平均データ表示\n"
               "[5]: グラフ表示(gnuplotをインストールしてください)");
        printf("\n\n\x1b[0m"); // 黄色文字ここまで
        printf("上記より行う処理を入力> ");
        scanf("%d", &whatToDo);
        switch (whatToDo) // 作業内容で分岐する
        {
        case 0:
            break;
        case 1:
            addData();
            break;
        case 2:
            editData();
            break;
        case 3:
            showData();
            break;
        case 4:
            showStatistic();
            break;
        case 5:
            showGraph();
            break;
        default:
            printf("無効な処理: %d\n", whatToDo);
            break;
        }
    }
    return 0;
}

int fileLoader(char *path, char (*result)[LINE_LENGTH])
{ // 体重データファイル読み込み関数
    char lineData[LINE_LENGTH];
    int count = 0;

    FILE *fp;

    fp = fopen(path, "r"); // 読み取り専用モードでファイルを開く

    if (fp == NULL)
    {                              // ファイル読み込みエラー発生時
        printf("file load error"); // エラーの出力
        return 0;                  // 読み込みエラー時は行数0
    }

    while (fgets(lineData, sizeof(lineData), fp))
    {                                            // 一行ごとにファイルを読む
        char *kaigyouPointer;                    // 改行文字のある位置へのポインタを格納する変数
        kaigyouPointer = strchr(lineData, '\n'); // 改行文字の位置を検索
        if (kaigyouPointer != NULL)
            *kaigyouPointer = '\0';      // 改行文字をヌル文字へ置き換え
        strcpy(result[count], lineData); // 結果の文字列をコピー
        count++;
    }

    fclose(fp);

    return count; // 行数を返す
}

void fileSaver(char *path, char *content)
{
    FILE *fp;
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        printf("ファイル書き込みエラー: 書き込み対象のファイルを開けません。処理を中止します\n");
        return;
    }
    fprintf(fp, "%s", content);
    fclose(fp);
}

double getAverage(double *array, int size)
{                   // 平均を求める関数
    double sum = 0; // 合計値
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum / size;
}

double getBmi(double weight, double height)
{ // BMIを求める関数 身長はcmで渡す
    return weight / ((height / 100) * (height / 100));
}

void convertToCsv(double input[MAX_DAY][4], char *result, int size)
{ // 二次元配列からCSVに変換する関数

    int currentIndex = 0; // 文字列追加用インデックス

    for (int i = 0; i < size; i++)
    {

        int isContinue = 0; // 内部ループを抜けて外側continueを実行するための変数
        for (int j = 0; j < 4; j++)
        {
            if (input[i][0] == -1)
            { // 年に-1がマークされていたらその行を無しとする
                isContinue = 1;
                break;
            }

            currentIndex += sprintf(&result[currentIndex], "%f", input[i][j]); // resultの後ろに追加
            if (j != 3)
            { // 最後の列以外にコンマを追加、インデックスを１進める
                result[currentIndex++] = ',';
            }
        }

        if (isContinue == 1)
        {
            isContinue = 0;
            continue;
        }

        result[currentIndex++] = '\n'; // 改行を追加し、インデックスを進める
    }
    result[currentIndex] = '\0'; // 最後にnull字を追加
}
int parseCsv(char *str, double result[4])
{
    int commmaCount = 0;                // 月日体重の区切りコンマのカウント用変数
    char devChar[] = ",";               // 分離する文字
    char *token = strtok(str, devChar); // 先頭からコンマで分離する

    while (token != NULL)
    { // コンマの数だけ分離する

        result[commmaCount] = strtod(token, NULL);
        token = strtok(NULL, devChar); // 分離
        commmaCount++;
    }
    return commmaCount;
}

time_t getEpochTime(int y, int m, int d)
{ // 1970年1月1日からの秒数を算出する関数

    struct tm timeStruct;

    timeStruct.tm_year = y - 1900; // 年は1900年からの経過年数
    timeStruct.tm_mon = m - 1;     // 月は0から始まる（1月は0）,1を引く
    timeStruct.tm_mday = d;        // 日
    timeStruct.tm_hour = 0;        // 時
    timeStruct.tm_min = 0;         // 分
    timeStruct.tm_sec = 0;         // 秒
    timeStruct.tm_isdst = -1;      // 夏時間の情報を自動判定

    time_t epoch_time = mktime(&timeStruct); // epochタイム算出

    return (epoch_time != -1 ? epoch_time : 0);
}

void showStatistic(void)
{ // 統計を表示する関数

    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH];
    int line = fileLoader(path, loadedData);
    double height; // 身長を格納する変数

    printf("平均値からBMIを求めます。身長(cm)を入力してください> ");
    scanf("%lf", &height);
    double weightList[MAX_DAY];

    for (int i = 0; i < line; i++)
    { // ファイルの行数だけ繰り返す
        double valueData[4] = {};
        int rowCount = parseCsv(loadedData[i], valueData);
        for (int j = 0; j < rowCount; j++)
        {
            if (j == WEIGHT_COLUMN)
            {
                weightList[i] = valueData[j];
            }
        }
    }

    double weightAverage = getAverage(weightList, line);
    printf("------------\n"
           "あなたの平均体重は %f\n"
           "あなたの平均BMIは %fです。\n"
           "------------\n",
           weightAverage, getBmi(weightAverage, height));
}

void addData(void)
{
    printf("ファイルの読み込み中\n");

    // 一旦現在のファイルの内容をプログラム中に読み出す
    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH]; // ファイルから読み取ったコンマを含む値
    int line = fileLoader(path, loadedData);
    double dataArray[MAX_DAY][4]; // 月日体重を格納する二次元配列

    for (int i = 0; i < line; i++)
    {
        double valueData[4] = {};
        int rowCount = parseCsv(loadedData[i], valueData);
        for (int j = 0; j < rowCount; j++)
        {
            dataArray[i][j] = valueData[j];
        }
    }

    char answer;
    printf("今日の日付を記録として使用しますか？(y/n)> ");
    rewind(stdin); // 標準入力のバッファをクリア
    answer = getchar();
    double year, month, day, weight; // 全てdouble型

    if (answer == 'y')
    {

        time_t timeObj = time(NULL);
        struct tm *localTime = localtime(&timeObj);
        year = localTime->tm_year + 1900;
        month = localTime->tm_mon + 1;
        day = localTime->tm_mday;
        printf("今日は %d年 %d月 %d日です。この値を使用します。\n", (int)year, (int)month, (int)day);
    }
    else
    {

        printf("年を入力してください> ");
        scanf("%lf", &year);
        printf("月を入力してください> ");
        scanf("%lf", &month);
        printf("日を入力してください> ");
        scanf("%lf", &day);
    }
    rewind(stdin); // バッファをクリア
    printf("体重を入力してください> ");
    scanf("%lf", &weight);

    dataArray[line][0] = year;
    dataArray[line][1] = month;
    dataArray[line][2] = day;
    dataArray[line][3] = weight;
    char res[LINE_LENGTH]; // CSVへの変換後文字列を格納する変数
    convertToCsv(dataArray, res, line + 1);
    fileSaver(FILE_NAME, res);
    printf("追加しました\n");
}

void editData(void)
{

    double year, month;

    printf("編集対象のデータが含まれる年を入力してください> ");
    scanf("%lf", &year);
    printf("編集対象のデータが含まれる月を入力してください(1-12)> ");
    scanf("%lf", &month);

    char loadedData[MAX_DAY][LINE_LENGTH];
    double dataArray[MAX_DAY][4];
    int line = fileLoader(FILE_NAME, loadedData);

    for (int i = 0; i < line; i++)
    {

        double valueData[4] = {};
        int rowCount = parseCsv(loadedData[i], valueData);

        for (int j = 0; j < rowCount; j++)
        {
            dataArray[i][j] = valueData[j];
        }

        if (dataArray[i][0] == year && dataArray[i][1] == month)
        {
            printf("%d 年 %d月 %d日 体重: %fkg 編集ID: %d\n", (int)dataArray[i][0], (int)dataArray[i][1], (int)dataArray[i][2], dataArray[i][3], i);
        }
    }

    int editId;
    char deleteOrEdit;

    printf("上記の中から編集IDを選択してください> ");
    scanf("%d", &editId);
    rewind(stdin); // バッファをクリア
    printf("指定した項目を削除する場合はd、編集する場合はeと入力してください> ");
    deleteOrEdit = getchar();

    if (deleteOrEdit == 'd')
    {
        dataArray[editId][0] = -1; // 年に-1を設定して削除としてマーク
    }
    else
    {
        printf("修正後の年を入力してください> ");
        scanf("%lf", &dataArray[editId][0]);
        printf("修正後の月を入力してください> ");
        scanf("%lf", &dataArray[editId][1]);
        printf("修正後の日を入力してください> ");
        scanf("%lf", &dataArray[editId][2]);
        printf("修正後の体重を入力してください> ");
        scanf("%lf", &dataArray[editId][3]);
    }

    char res[LINE_LENGTH]; // CSVへの変換後文字列を格納する変数
    convertToCsv(dataArray, res, line);
    fileSaver(FILE_NAME, res);
    printf("処理を完了しました\n");
}
void showGraph(void)
{

    // ファイルの読み出し
    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH];
    int line = fileLoader(path, loadedData);
    int x_count = 0; // x軸の数字のカウント用変数

    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;

    printf("いつからのグラフを表示しますか(年 月 日)> ");

    scanf("%d %d %d", &startYear, &startMonth, &startDay);
    int rangeEpochFrom = getEpochTime(startYear, startMonth, startDay);
    printf("いつまでのグラフを表示しますか(年 月 日)> ");

    scanf("%d %d %d", &endYear, &endMonth, &endDay);
    int rangeEpochTo = getEpochTime(endYear, endMonth, endDay);

    FILE *gnuplotPipe = popen("gnuplot -persist", "w");
    if (gnuplotPipe == NULL)
    {
        printf("gnuplot実行失敗。\n");
        return;
    }
    fprintf(gnuplotPipe, "plot '-' with lines title 'Weights'\n");

    for (int i = 0; i < line; i++)
    { // ファイルの行数だけ繰り返す

        double valueData[4] = {};
        int rowCount = parseCsv(loadedData[i], valueData);
        int lineEpoch = getEpochTime((int)valueData[0], (int)valueData[1], (int)valueData[2]); // 秒に変換

        if (lineEpoch >= rangeEpochFrom && lineEpoch <= rangeEpochTo)
        { // 指定された期間内の値を抽出

            fprintf(gnuplotPipe, "%d %lf\n", x_count, valueData[3]);
            x_count++;
        }
    }
    fprintf(gnuplotPipe, "e\n");
    pclose(gnuplotPipe);
}

void showData()
{ // 指定した期間内のデータを一覧表示する関数
    char path[MAX_PATH] = FILE_NAME;
    char loadedData[MAX_DAY][LINE_LENGTH];
    int line = fileLoader(path, loadedData);
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;

    printf("いつからのデータを表示しますか(年 月 日)> ");

    scanf("%d %d %d", &startYear, &startMonth, &startDay);
    int rangeEpochFrom = getEpochTime(startYear, startMonth, startDay);

    printf("いつまでのデータを表示しますか(年 月 日)> ");

    scanf("%d %d %d", &endYear, &endMonth, &endDay);
    int rangeEpochTo = getEpochTime(endYear, endMonth, endDay);

    for (int i = 0; i < line; i++)
    { // ファイルの行数だけ繰り返す
        double valueData[4] = {};
        int rowCount = parseCsv(loadedData[i], valueData);

        int lineEpoch = getEpochTime((int)valueData[0], (int)valueData[1], (int)valueData[2]); // 秒に変換

        if (lineEpoch >= rangeEpochFrom && lineEpoch <= rangeEpochTo)
        {
            printf("%d年 %d月 %d日 体重: %fkg\n", (int)valueData[0], (int)valueData[1], (int)valueData[2], valueData[3]);
        }
    }
}