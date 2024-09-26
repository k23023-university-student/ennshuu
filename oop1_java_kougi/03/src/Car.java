public class Car {
    double fuelEfficiency;//燃費
    double totalMileage = 0;//累計走行距離
    double expendedFuel = 0;//消費燃料の累計
    double run(double mileage){
        double consumed = mileage / fuelEfficiency;//今回の消費燃料
        totalMileage += mileage;
        expendedFuel += consumed;
        return consumed;//消費燃料を返す
    }
    String getInfo(){
        return String.format("走行距離:%fkm 消費燃料:%fL",totalMileage,expendedFuel);
    }
}
