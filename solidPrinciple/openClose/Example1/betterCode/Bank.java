public class Bank implements Payment{
    public void pay(double amount){
        System.out.println("Bank: Paying " + amount);
    }
}