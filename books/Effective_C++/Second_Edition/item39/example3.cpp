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
  virtual void creditInterest() {};
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
  list<BankAccount*> allAccounts;         // all accounts at the bank

  // look ma, no cast!
  for (list<BankAccount*>::iterator p = allAccounts.begin();
       p != allAccounts.end();
       ++p)
  {
    (*p)->creditInterest();
  }

}
