public class PhonePay implements Payment{
    public void pay(double amount){
        System.out.println("PhonePay: Paying " + amount);
    }
}