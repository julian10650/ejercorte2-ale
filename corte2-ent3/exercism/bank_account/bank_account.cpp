#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {

Bankaccount::Bankaccount() : balance_amount(0), is_open(false) {}

void Bankaccount::open() {
    std::lock_guard<std::mutex> lock(mtx);
    if (is_open) {
        throw std::runtime_error("Account is already open");
    }
    is_open = true;
    balance_amount = 0;
}

void Bankaccount::close() {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is already closed");
    }
    is_open = false;
    balance_amount = 0;
}

int Bankaccount::balance() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed");
    }
    return balance_amount;
}

void Bankaccount::deposit(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed");
    }
    if (amount < 0) {
        throw std::runtime_error("Cannot deposit negative amounts");
    }
    balance_amount += amount;
}

void Bankaccount::withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (!is_open) {
        throw std::runtime_error("Account is closed");
    }
    if (amount < 0 || amount > balance_amount) {
        throw std::runtime_error("Invalid withdrawal amount");
    }
    balance_amount -= amount;
}

}  // namespace Bankaccount
