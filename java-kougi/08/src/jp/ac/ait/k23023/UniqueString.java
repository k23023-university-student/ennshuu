package jp.ac.ait.k23023;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class UniqueString {
    private  <T> int countOccurrences(List<T> list, T value) {
        int count = 0;
        for (T item : list) {
            if (item.equals(value)) {
                count++;
            }
        }
        return count;
    }
    public List<String> getUniqueList(List<String> targetList){
        List<String> newList = new ArrayList<>();

        for(String tl : targetList){
            if(countOccurrences(targetList,tl) == 1) newList.add(tl);
        }
        return newList;
    }
    public static void main(String[] args){
        System.out.println(new UniqueString().getUniqueList(new ArrayList<>(Arrays.asList("A", "B", "B", "B", "C"))));
        System.out.println(new UniqueString().getUniqueList(new ArrayList<>(Arrays.asList("A", "A", "A", "A", "A"))));
        System.out.println(new UniqueString().getUniqueList(new ArrayList<>(Arrays.asList("A", "B", "C", "D", "E"))));

    }
}
