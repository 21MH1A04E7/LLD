
public class PaymentProcess {

    public void ponepay(double amount) {
        System.out.println("Payment processed using Ponepay " + amount);
    }

    public void paypal(double amount) {
        System.out.println("Payment processed using PayPal " + amount);
    }

    public void paytm(double amount) {
        System.out.println("Payment processed using PayTM  " +amount);
    }
}
//if we need more feature in the future we need to modify this class again
//it's is voilate the open close principle
