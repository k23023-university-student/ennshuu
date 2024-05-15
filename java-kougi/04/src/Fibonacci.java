import java.util.Arrays;

public class Fibonacci {
    public IntCollector get(int n){

        IntCollector clct = new IntCollector();
        if(n < 0) return clct;
        clct.add(0);
        if(n == 0) return clct;
        clct.add(1);
        if(n == 1) return clct;
        int count = 2;//すでに2つ挿入したのでカウンタを2に
        while(true){
            int n_2=0,n_1 = 0;
            n_2 = clct.getArray()[count-2];
            n_1 = clct.getArray()[count-1];
            if(n_1 + n_2 >= n) break;
            clct.add(n_1 + n_2);
            count++;
        }

        return clct;
    }
    public static void main(String[] args){
        Fibonacci fib = new Fibonacci();
        System.out.print("get(10000): ");
        fib.get(10000).print();// [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765]
        System.out.print("get(200): ");
        fib.get(200).print();// [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144]
        System.out.print("get(-1): ");
        fib.get(-1).print();
        System.out.print("get(0): ");
        System.out.println(Arrays.toString(fib.get(0).getArray()));
        System.out.print("get(1): ");
        System.out.println(Arrays.toString(fib.get(1).getArray()));
        System.out.print("get(2): ");
        System.out.println(Arrays.toString(fib.get(2).getArray()));
    }
}
