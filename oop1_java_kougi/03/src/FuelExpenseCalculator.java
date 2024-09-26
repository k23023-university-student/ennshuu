import java.util.Scanner;
public class FuelExpenseCalculator {
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);
        Car carObj = new Car();
        carObj.fuelEfficiency = 31;//燃費を設定
        while (true){
            System.out.print("実数またはendを入力> ");
            String dist = in.nextLine();
            if(dist.equals("end")) break;
            carObj.run(Double.parseDouble(dist));
            System.out.println(carObj.getInfo());
        }
    }
}
