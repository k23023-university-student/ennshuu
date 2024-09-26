public class PrimeNumberChecker {
    public  static  void  main(String args[]){
        boolean isPrime = true;//素数かどうか
        java.util.Scanner in = new java.util.Scanner(System.in);
        int num  = Integer.parseInt(in.nextLine());
        if(num <= 1){
            System.out.println("素数ではありません");
            return;
        }
        for(int i=2;i<=num-1;i++){
            if(num%i == 0){
                isPrime = false;
                break;
            }
        }
        System.out.println(isPrime? "素数です" : "素数ではありません");
    }
}
