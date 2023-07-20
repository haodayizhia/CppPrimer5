class Account {
   public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);

   private:
   std::string owner;
   double amount;
    static constexpr int period = 30;
    static double daily_tbl[period];
    static double interestRate;
    static double initRate();
};
double Account::daily_tbl[period] = {0};
void Account::rate(double newRate)
{
    interestRate = newRate;
}
