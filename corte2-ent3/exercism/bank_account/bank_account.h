#pragma once

#include <mutex>

namespace Bankaccount {

class Bankaccount {
private:
    int balance_amount;
    bool is_open;
    mutable std::mutex mtx;

public:
    Bankaccount();
    
    void open();
    void close();
    
    int balance() const;
    void deposit(int amount);
    void withdraw(int amount);
};

}  // namespace Bankaccount
