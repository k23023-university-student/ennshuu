package jp.ac.ait.k23023;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FizzBuzz implements IKadai08_2 {
    public List<String> getConverted(List<Integer> targetList){
        List<String> newList = new ArrayList<>();
        int count = 0;
        for(int t : targetList){
            if(t % 3 == 0 && t % 5 == 0){

                newList.add("FizzBuzz");

            }else if(t % 3 == 0){

                newList.add("Fizz");

            }else if(t % 5 == 0){
                newList.add("Buzz");
            }else{
                newList.add(targetList.get(count).toString());
            }
            count++;
        }
        return newList;
    }
    public static void main(String[] args){

        FizzBuzz fb = new FizzBuzz();
        List<Integer> test1 = new ArrayList<>(Arrays.asList(1,2,3,4,5));
        List<Integer> test2 = new ArrayList<>(Arrays.asList(1,2,4));
        List<Integer> test3 = new ArrayList<>(Arrays.asList(12,13,14,15,16));
        List<Integer> test4 = new ArrayList<>(Arrays.asList(3,30,300));
        List<Integer> test5 = new ArrayList<>(Arrays.asList());
        System.out.println(fb.getConverted(test1).toString());
        System.out.println(fb.getConverted(test2).toString());
        System.out.println(fb.getConverted(test3).toString());
        System.out.println(fb.getConverted(test4).toString());
        System.out.println(fb.getConverted(test5).toString());
    }
}
