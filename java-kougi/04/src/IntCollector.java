import java.util.Arrays;

public class IntCollector {

    private int[] array;

    public IntCollector(){

        array = new int[0];

    }

    public  IntCollector(int[] values){

        this.setArray(values);//setArrayを呼び出して設定

    }

    public int[] getArray(){
        return array;
    }

    public void setArray(int[] values){
        array = new int[values.length];
        array = values.clone();
    }

    public void add(int value){

        int[] newArray = new int[array.length + 1];

        System.arraycopy(array,0,newArray,0,array.length);

        newArray[array.length] = value;
        setArray(newArray);//元の配列arrayに設定

    }

    public int countOf(int value){
        int count = 0;

        for(int i=0;i<array.length;i++){
            if(array[i] == value) count++;
        }
        return count;
    }

    public int indexOf(int value){
        int index = -1;

        for(int i=0;i<array.length;i++){

            if(array[i] == value){
                index = i;
                break;
            }
        }
        return index;
    }


    public void remove(int index){

        for(int i = index;i<array.length-1;i++){//index以後の配列要素を前へシフト
            array[i] = array[i+1];
        }

        int[] newArray = new int[array.length - 1];//新しい配列
        System.arraycopy(array,0,newArray,0,array.length - 1);//元の配列から一つ減らした分だけ新しい配列へコピー
        setArray(newArray);//元の配列に設定

    }

    public void print(){
        System.out.println(Arrays.toString(array));
    }

    public static void main (String[] args){

        //テストコード

        IntCollector collectTest1 = new IntCollector();//配列の要素を空として宣言
        collectTest1.print();//[]
        //要素の追加
        collectTest1.add(1);
        //追加されたことを確認
        collectTest1.print();//[1]
        collectTest1.add(2);
        collectTest1.add(3);
        collectTest1.add(4);

        System.out.println(collectTest1.countOf(3));//1

        //3の二つ目を追加
        collectTest1.add(3);
        System.out.println(collectTest1.countOf(3));//2


        collectTest1.print(); //[1, 2, 3, 4, 3]
        collectTest1.remove(3);//インデックス3番の削除
        collectTest1.print();// [1, 2, 3, 3]
        collectTest1.remove(0);//先頭を削除
        collectTest1.print();// [2, 3, 3]

        System.out.println(collectTest1.indexOf(2));// 0
        System.out.println(collectTest1.indexOf(5));// -1



        int [] arr1 = new int[3];//追加用の配列
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;

        IntCollector collectTest2 = new IntCollector(arr1);//コンストラクタありで初期化してみる
        collectTest2.print();//[10, 20, 30]
    }
}
