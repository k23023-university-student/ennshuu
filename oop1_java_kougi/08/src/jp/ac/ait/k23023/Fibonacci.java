package jp.ac.ait.k23023;

import java.util.ArrayList;
import java.util.List;

public class Fibonacci implements IKadai08_1{
    @Override
    public List<Integer> get(int max_value){


        List<Integer> fib = new ArrayList<>();

        if(max_value < 0) return fib;

        fib.add(0);
        if(max_value == 0) return fib;
        fib.add(1);
        if(max_value == 1) return fib;

        int count = 2;//すでに二つ挿入したので2

        while(true){
            int n_1 = fib.get(count - 1);
            int n_2 = fib.get(count - 2);
            int currentKou = n_1 + n_2;
            if(currentKou > max_value) break;
            fib.add(currentKou);
            count++;
        }

        return fib;
    }
    public static void main(String[] args){
        System.out.println(new Fibonacci().get(10000).toString());
        System.out.println(new Fibonacci().get(2).toString());
        System.out.println(new Fibonacci().get(1).toString());
        System.out.println(new Fibonacci().get(0).toString());
        System.out.println(new Fibonacci().get(-1).toString());
        System.out.println(new Fibonacci().get(-231).toString());
    }
}
