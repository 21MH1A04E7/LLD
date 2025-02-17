
public class Main {

    public static void main(String[] args) {
        PhonePay p1 = new PhonePay();
        PaymentProcess process = new PaymentProcess(p1);
        process.paymentProcess(52.2);
        Gpay p2 = new Gpay();
        process.cretePaymentProcess(p2);
        process.paymentProcess(48.3);
        Bank p3 = new Bank();
        process.cretePaymentProcess(p3);
        process.paymentProcess(755.5);

    }
}
