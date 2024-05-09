import java.util.Arrays;

public class NonUniqueElements {
    public IntCollector convert(IntCollector arr){

        for(int i=0;i<arr.getArray().length;i++){

            if(arr.countOf(arr.getArray()[i]) == 1){//値の存在箇所が一箇所のみのとき
                arr.remove(i);//その値を削除
                i--;//切り詰めた分iを前にシフト
            }

        }
        return arr;
    }
    public static void main(String [] args){

        NonUniqueElements nuElem = new NonUniqueElements();
        IntCollector clct1 = new IntCollector();

        clct1.add(1);
        clct1.add(2);
        clct1.add(3);
        clct1.add(1);
        clct1.add(3);

        System.out.println(Arrays.toString(nuElem.convert(clct1).getArray())); // [1, 3, 1, 3]


        IntCollector clct2 = new IntCollector();
        clct2.add(1);
        clct2.add(2);
        clct2.add(3);
        clct2.add(4);
        clct2.add(5);
        System.out.println(Arrays.toString(nuElem.convert(clct2).getArray()));

        IntCollector clct3 = new IntCollector();
        clct3.add(5);
        clct3.add(5);
        clct3.add(5);
        clct3.add(5);
        clct3.add(5);
        System.out.println(Arrays.toString(nuElem.convert(clct3).getArray()));//[5, 5, 5, 5, 5]

        IntCollector clct4 = new IntCollector();
        clct4.add(10);
        clct4.add(9);
        clct4.add(10);
        clct4.add(10);
        clct4.add(9);
        clct4.add(8);
        System.out.println(Arrays.toString(nuElem.convert(clct4).getArray()));//[10, 9, 10, 10, 9]

    }
}
