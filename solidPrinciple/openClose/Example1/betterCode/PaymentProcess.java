public class PaymentProcess  {
    private Payment process;
    public PaymentProcess(Payment process){
        this.process= process;
    }
    public void cretePaymentProcess(Payment process){
        this.process=process;
    }
    public void paymentProcess(double amount){
        // code to process payment
        this.process.pay(amount);
     }
}

