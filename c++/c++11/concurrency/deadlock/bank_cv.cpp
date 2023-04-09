// need c++17

#include <iostream>
#include <thread>
#include <mutex>
#include <set>
#include <condition_variable>

using namespace std;

class Account {
public:
  Account(string name, double money): mName(name), mMoney(money) {};

public:
  void changeMoney(double amount) {
    // 使用的是unique_lock，是为了与条件变量相配合。因为条件变量会解锁和重新锁定互斥体。
    unique_lock lock(mMoneyLock);
    // 使用条件变量，等待条件（lambda 表达式）满足
    // 如果不满足，则解锁 mMoneyLock，并阻塞当前线程，直到条件满足，再重新锁定 mMoneyLock
    mConditionVar.wait(lock, [this, amount] {
      return mMoney + amount > 0;
    });
    mMoney += amount;
    // 金额发生变动后，通知所有等待在条件变量上的线程，此时调用wait的线程会被唤醒，并尝试获取锁
    mConditionVar.notify_all();
  }

  string getName() {
    return mName;
  }
  double getMoney() {
    return mMoney;
  }
  mutex* getLock() {
    return &mMoneyLock;
  }

private:
  string mName;
  double mMoney;
  mutex mMoneyLock;
  condition_variable mConditionVar;
};

class Bank {
public:
  void addAccount(Account* account) {
    mAccounts.insert(account);
  }

  void transferMoney(Account* accountA, Account* accountB, double amount) {
    accountA->changeMoney(-amount);
    accountB->changeMoney(amount);
  }

  double totalMoney() const {
    double sum = 0;
    for (auto a : mAccounts) {
      sum += a->getMoney();
    }
    return sum;
  }

private:
  set<Account*> mAccounts;
};

mutex sCoutLock;
void randomTransfer(Bank* bank, Account* accountA, Account* accountB) {
  while(true) {
    double randomMoney = ((double)rand() / RAND_MAX) * 100;
    {
      lock_guard guard(sCoutLock);
      cout << "Try to Transfer " << randomMoney
           << " from " << accountA->getName() << "(" << accountA->getMoney()
           << ") to " << accountB->getName() << "(" << accountB->getMoney()
           << "), Bank totalMoney: " << bank->totalMoney() << endl;
    }
    bank->transferMoney(accountA, accountB, randomMoney);
  }
}

int main() {
  srand(time(NULL));
  Bank bank;
  Account accountA("A", 1000);
  Account accountB("B", 1000);
  bank.addAccount(&accountA);
  bank.addAccount(&accountB);

  thread t1(randomTransfer, &bank, &accountA, &accountB);
  thread t2(randomTransfer, &bank, &accountB, &accountA);
  t1.join();
  t2.join();

  return 0;
}