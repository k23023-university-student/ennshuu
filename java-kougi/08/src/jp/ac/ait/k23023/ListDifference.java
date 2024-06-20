package jp.ac.ait.k23023;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListDifference implements IKadai08_5{
    @Override public <T> List<T> find(List<T> list1, List<T> list2){

        List<T> newList = new ArrayList<>();
        for(T tl : list1){

            if(!list2.contains(tl)) newList.add(tl);//リスト1にあってリスト2にないものを抽出
        }
        return newList;
    }
    public static void main(String[] args){
        ListDifference kadai5 = new ListDifference();
        List<Integer> list1 = Arrays.asList(1, 2, 3, 4, 5);
        List<Integer> list2 = Arrays.asList(3, 4, 6);
        List<Integer> output1 = kadai5.find(list1, list2);
        System.out.println(output1); // output: [1, 2, 5]

        List<Integer> list3 = Arrays.asList(1, 2, 2, 2, 3);
        List<Integer> list4 = Arrays.asList(3, 3, 3, 3);
        List<Integer> output2 = kadai5.find(list3, list4);
        System.out.println(output2);// output: [1, 2, 2, 2]

        List<String> list5 = Arrays.asList("apple", "banana", "cherry", "date");
        List<String> list6 = Arrays.asList("banana", "date");
        List<String> output3 = kadai5.find(list5, list6);
        System.out.println(output3);// output: ["apple", "cherry"]

    }
}
