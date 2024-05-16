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
        IntCollector collector1 = new IntCollector();

        collector1.add(1);
        collector1.add(2);
        collector1.add(3);
        collector1.add(1);
        collector1.add(3);

        System.out.println(Arrays.toString(nuElem.convert(collector1).getArray())); // [1, 3, 1, 3]


        IntCollector collector2 = new IntCollector();
        collector2.add(1);
        collector2.add(2);
        collector2.add(3);
        collector2.add(4);
        collector2.add(5);
        System.out.println(Arrays.toString(nuElem.convert(collector2).getArray()));

        IntCollector collector3 = new IntCollector();
        collector3.add(5);
        collector3.add(5);
        collector3.add(5);
        collector3.add(5);
        collector3.add(5);
        System.out.println(Arrays.toString(nuElem.convert(collector3).getArray()));//[5, 5, 5, 5, 5]

        IntCollector collector4 = new IntCollector();
        collector4.add(10);
        collector4.add(9);
        collector4.add(10);
        collector4.add(10);
        collector4.add(9);
        collector4.add(8);
        System.out.println(Arrays.toString(nuElem.convert(collector4).getArray()));//[10, 9, 10, 10, 9]

    }
}
