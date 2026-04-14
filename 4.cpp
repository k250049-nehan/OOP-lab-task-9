#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(string c) {
        cardNumber = c;
    }

    void processPayment(double amount) {
        if(cardNumber.length() == 16) {
            cout << "Credit Card Payment of " << amount << " successful" << endl;
        } else {
            cout << "Credit Card Payment failed: Invalid card number" << endl;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double b) {
        balance = b;
    }

    void processPayment(double amount) {
        if(balance >= amount) {
            balance -= amount;
            cout << "Wallet Payment of " << amount << " successful" << endl;
        } else {
            cout << "Wallet Payment failed: Insufficient balance" << endl;
        }
    }
};

int main() {
    PaymentMethod* p1 = new CreditCard("1234567812345678");
    PaymentMethod* p2 = new DigitalWallet(5000);

    p1->processPayment(2000);
    p2->processPayment(3000);
    p2->processPayment(2500);

    delete p1;
    delete p2;

    return 0;
}
