import java.sql.Time;
import java.util.Arrays;

public class TimesTable {
    private int width;
    private int height;
    private int [][] array;
    private TimesTable(){}

    public TimesTable(int width, int height){

        this.width = width;
        this.height = height;
        array = new int[height][width];
        for(int h=0;h<this.height;h++){

            for(int w=0;w<this.width;w++){

                array[h][w] = (h+1) * (w+1);
            }

        }

    }

    public int getWidth() {
        return width;
    }

    public int getHeight(){
        return height;
    }

    public int[][] getArray() {
        return array;
    }
    public void print(){
        for(int h=0;h<this.height;h++){

            for(int w=0;w<this.width;w++){

                System.out.printf("|%d",array[h][w]);
            }
                System.out.printf("|\n");

        }
    }
    public static void main(String [] args){

        TimesTable tt1 = new TimesTable(4, 3);//4x3
        System.out.println(Arrays.deepToString(tt1.getArray()));// 配列の中身の確認
        System.out.printf("高さ:%d, 幅:%d\n",tt1.getHeight(),tt1.getWidth());//高さと幅の表示メソッドの確認
        tt1.print();//表を表示


        System.out.print("\n");

        TimesTable tt2 = new TimesTable(1,1);//1x1
        System.out.println(Arrays.deepToString(tt2.getArray()));
        tt2.print();

        System.out.print("\n");

        TimesTable tt3 = new TimesTable(0,0);//0x0
        System.out.println(Arrays.deepToString(tt3.getArray()));
        tt3.print();

        System.out.print("\n");

        TimesTable tt4 = new TimesTable(9,9);//9x9
        System.out.println(Arrays.deepToString(tt4.getArray()));
        tt4.print();
        System.out.print("\n");

        TimesTable tt5 = new TimesTable(3, 4);//3x4
        System.out.println(Arrays.deepToString(tt5.getArray()));
        tt5.print();
        System.out.print("\n");


        TimesTable tt6 = new TimesTable(-9,9);//例外 java.lang.NegativeArraySizeException
    }
}
