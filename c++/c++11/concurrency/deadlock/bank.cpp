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
    mMoney += amount;
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

  bool transferMoney(Account* accountA, Account* accountB, double amount) {
    // lock(*accountA->getLock(), *accountB->getLock()); // crucial step to avoid deadlock
    // lock_guard<mutex> guardA(*accountA->getLock(), adopt_lock);
    // lock_guard<mutex> guardB(*accountB->getLock(), adopt_lock);
    // 等价写法 1：
    unique_lock guardA(*accountA->getLock(), defer_lock);
    unique_lock guardB(*accountB->getLock(), defer_lock);
    lock(guardA, guardB);
    // 等价写法 2：
    // scoped_lock guardAll(*accountA->getLock(), *accountB->getLock());

    // 这里没有调用lock方法，而是直接使用lock_guard来锁定互斥体。
    // 在方法结束的时候，局部变量std::lock_guard<std::mutex> guardA/B会被销毁，它对互斥体的锁定也就解除了。
    // 类似的有：
    // lock_guard	  C++11	实现严格基于作用域的互斥体所有权包装器
    // unique_lock	C++11	实现可移动的互斥体所有权包装器
    // shared_lock	C++14	实现可移动的共享互斥体所有权封装器
    // scoped_lock	C++17	用于多个互斥体的免死锁 RAII 封装器
    // 使用 RAII 的编程技巧实现的，可总结如下:
    // 将每个资源封装入一个类，其中：
      // 构造函数请求资源，并建立所有类不变式，或在它无法完成时抛出异常，
      // 析构函数释放资源并决不抛出异常；
    // 始终经由 RAII 类的实例使用满足要求的资源，该资源
      // 自身拥有自动存储期或临时生存期，或
      // 具有与自动或临时对象的生存期绑定的生存期

    // 锁定策略有：
    // defer_lock  	C++11	类型为 defer_lock_t，不获得互斥的所有权
    // try_to_lock	C++11	类型为 try_to_lock_t，尝试获得互斥的所有权而不阻塞
    // adopt_lock  	C++11	类型为 adopt_lock_t，假设调用方已拥有互斥的所有权

    // lock_guard<mutex> guardA(*accountA->getLock());
    // lock_guard<mutex> guardB(*accountB->getLock());

    if (amount > accountA->getMoney()) { // ②
      return false;
    }

    accountA->changeMoney(-amount); // ③
    accountB->changeMoney(amount);
    return true;
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

void randomTransfer(Bank* bank, Account* accountA, Account* accountB) {
  while(true) {
    double randomMoney = ((double)rand() / RAND_MAX) * 100;
    if (bank->transferMoney(accountA, accountB, randomMoney)) {
      cout << "Transfer " << randomMoney << " from " << accountA->getName()
           << " to " << accountB->getName()
           << ", Bank totalMoney: " << bank->totalMoney() << endl;
    } else {
      cout << "Transfer failed, "
           << accountA->getName() << " has only $" << accountA->getMoney() << ", but "
           << randomMoney << " required" << endl;
    }
  }
}

mutex sCoutLock;
void randomTransfer_with_cout_lock(Bank* bank, Account* accountA, Account* accountB) {
  while(true) {
    double randomMoney = ((double)rand() / RAND_MAX) * 100;
    if (bank->transferMoney(accountA, accountB, randomMoney)) {
      sCoutLock.lock();
      cout << "Transfer " << randomMoney << " from " << accountA->getName()
          << " to " << accountB->getName()
          << ", Bank totalMoney: " << bank->totalMoney() << endl;
      sCoutLock.unlock();
    } else {
      sCoutLock.lock();
      cout << "Transfer failed, "
           << accountA->getName() << " has only " << accountA->getMoney() << ", but "
           << randomMoney << " required" << endl;
      sCoutLock.unlock();
    }
  }
}

int main() {
  srand(time(NULL));
  Bank bank;
  Account accountA("A", 1000);
  Account accountB("B", 1000);
  bank.addAccount(&accountA);
  bank.addAccount(&accountB);

  thread t1(randomTransfer_with_cout_lock, &bank, &accountA, &accountB);
  thread t2(randomTransfer_with_cout_lock, &bank, &accountB, &accountA);
  t1.join();
  t2.join();

  return 0;
}