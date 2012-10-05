#include <list>
#include <string>
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

void error(const string& msg);      // error-handling function;
                                    // see below

int main()
{
  list<BankAccount*> allAccounts;         // all accounts at the
                                          // bank

  // well, ma, at least the casts are safe...
  for (list<BankAccount*>::iterator p = allAccounts.begin();
       p != allAccounts.end();
       ++p)
  {
    // try safe-downcasting *p to a SavingsAccount*; see
    // below for information on the definition of psa
    if (SavingsAccount *psa = dynamic_cast<SavingsAccount*>(*p))
    {
      psa->creditInterest();
    }
     // try safe-downcasting it to a CheckingAccount
    else if (CheckingAccount *pca = dynamic_cast<CheckingAccount*>(*p)) {
      pca->creditInterest();
    }
     // uh oh ; unknown account type
    else {
      error("Unknown account type!");
    }
  }
}
