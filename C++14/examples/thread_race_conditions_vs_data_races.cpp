/*
 * Example illustrating what a race condition and a data race is.
 *
 * References:
 *   [1] https://www.heise.de/developer/artikel/Race-Conditions-versus-Data-Races-3717884.html
 */

#include <functional>
#include <iostream>
#include <thread>

struct Account{
  int balance{100};
};
                                                      // 2
void transferMoney(int amount, Account& from, Account& to){
  using namespace std::chrono_literals;
  if (from.balance >= amount){
    from.balance -= amount;  
    std::this_thread::sleep_for(1ns);                 // 3
    to.balance += amount;
  }
}

int main(){
  
  std::cout << std::endl;

  Account account1;
  Account account2;
                                                        // 1
  std::thread thr1(transferMoney, 50, std::ref(account1), std::ref(account2));
  std::thread thr2(transferMoney, 130, std::ref(account2), std::ref(account1));
  
  thr1.join();
  thr2.join();

  std::cout << "account1.balance: " << account1.balance << std::endl;
  std::cout << "account2.balance: " << account2.balance << std::endl;
  
  std::cout << std::endl;

}
