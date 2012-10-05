#include <list>
using namespace std;

class Person {};

class BankAccount {
public:
  BankAccount(const Person *primaryOwner,
              const Person *jointOwner);
  virtual ~BankAccount();
  virtual void makeDeposit(double amount) = 0;
  virtual void makeWithdrawal(double amount) = 0;
  virtual double balance() const = 0;
};


class SavingsAccount: public BankAccount {
public:
  SavingsAccount(const Person *primaryOwner,
                 const Person *jointOwner);
  ~SavingsAccount();
  void creditInterest();                // add interest to account
};


class CheckingAccount: public BankAccount {
public:
  void creditInterest();    // add interest to account
};


int main()
{
  list<BankAccount*> allAccounts;         // all accounts at the
                                          // bank

  // A loop that won't compile (see below if you've never
  // seen code using "iterators" before).
  // The compiler error is:
  //   ‘class BankAccount’ has no member named ‘creditInterest’
  //for (list<BankAccount*>::iterator p = allAccounts.begin();
  //     p != allAccounts.end();
  //     ++p)
  //{
  //  (*p)->creditInterest();      // error!
  //}


  // A loop that will compile, but that is nonetheless evil.
  for (list<BankAccount*>::iterator p = allAccounts.begin();
       p != allAccounts.end();
       ++p)
  {
    static_cast<SavingsAccount*>(*p)->creditInterest();
  }

}
