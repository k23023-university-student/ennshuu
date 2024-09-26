package jp.ac.ait.k23023;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class NonUniqueElements implements IKadai08_4{

    private  <T> int countOccurrences(List<T> list, T value) {
        int count = 0;
        for (T item : list) {
            if (item.equals(value)) {
                count++;
            }
        }
        return count;
    }


    @Override
    public void convert(List<Integer> targetList) {

        var itr = targetList.iterator();
        while (itr.hasNext()) {
            int num = itr.next();
            if (countOccurrences(targetList,num) < 2) {
                itr.remove();
            }
        }
    }
    public static void main(String[] args){

        List<Integer> a = new ArrayList<>(Arrays.asList(1, 2, 3, 1, 3));
        new NonUniqueElements().convert(a);
        System.out.println(a);
        List<Integer> b = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        new NonUniqueElements().convert(b);
        System.out.println(b);
        List<Integer> c = new ArrayList<>(Arrays.asList(5, 5, 5, 5, 5));
        new NonUniqueElements().convert(c);
        System.out.println(c);
        List<Integer> d = new ArrayList<>(Arrays.asList(10, 9, 10, 10, 9, 8));
        new NonUniqueElements().convert(d);
        System.out.println(d);
    }
}
