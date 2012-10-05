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


// New class representing accounts that bear interest.
class InterestBearingAccount: public BankAccount {
public:
  virtual void creditInterest() = 0;
};


class SavingsAccount: public InterestBearingAccount {
public:
  SavingsAccount(const Person *primaryOwner,
                 const Person *jointOwner);
  ~SavingsAccount();
  void creditInterest();                // add interest to account
};


class CheckingAccount: public InterestBearingAccount {
public:
  void creditInterest();    // add interest to account
};


int main()
{
  list<BankAccount*> allAccounts;         // all accounts at the bank

  // better, but still not perfect
  for (list<BankAccount*>::iterator p = allAccounts.begin();
       p != allAccounts.end();
       ++p) {
     static_cast<InterestBearingAccount*>(*p)->creditInterest();
  }


  // all interest-bearing accounts in the bank
  list<InterestBearingAccount*> allIBAccounts;

  // a loop that compiles and works, both now and forever
  for (list<InterestBearingAccount*>::iterator p = allIBAccounts.begin();
       p != allIBAccounts.end();
       ++p)
  {
    (*p)->creditInterest();
  }

}
