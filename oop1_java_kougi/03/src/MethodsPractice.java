public class MethodsPractice {
    void printCurrency(double num){
        System.out.printf("%.2f\n",num);
    }
    int add(int a, int b){
        return  a + b;
    }
    double division(int a, int b){
        return (double) a / b;
    }

    String getTheAnswerToTheUltimateQuestionOfLife_TheUniverse_And_Everything(){
        try{
            Thread.sleep(750);
        }catch(InterruptedException e){}
        return "42";
    }

    public static void main(String args[]){
        MethodsPractice app = new MethodsPractice();
        app.printCurrency(4); // 4.00
        System.out.println(app.division(1,2)); // 0.5
        System.out.println(app.division(2,1)); // 2.0
        System.out.println(app.add(1,2)); // 3
        System.out.println(app.getTheAnswerToTheUltimateQuestionOfLife_TheUniverse_And_Everything()); // "42"
    }

}
