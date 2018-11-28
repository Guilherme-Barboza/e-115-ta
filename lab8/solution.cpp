//@author: Mark Freeman

#include<iostream>
using namespace std;

class ATM {
    private:
        int balance;
        static const int CASH_DEPOSIT = 0;
        static const int CHECK_DEPOSIT = 1;
        static const int CASH_DEPOSIT_MAXIMUM = 100; //don't worry about these for now
        static const int MAX_WITHDRAWAL_AMOUNT = 200; 
        static const int WITHDRAWAL_MULTIPLE_OF = 20;

        void deposit_to_account(int amount) { //private function that handles actual posting to account
            balance += amount;
            cout << "Deposited " << amount << " dollars" << endl;
        }

    public:
        ATM(int amount = 0) { //default value
            balance = amount;
        }

        void deposit(int amount, int depositType) {
            if(depositType == CASH_DEPOSIT) {
                if(amount > CASH_DEPOSIT_MAXIMUM)
                    cout << "Cash deposit exceeds max of " << CASH_DEPOSIT_MAXIMUM << endl;
                else
                    deposit_to_account(amount);
            }
            else if(depositType == CHECK_DEPOSIT) {
                deposit_to_account(amount);
            }
            else {
                cout << "Invalid deposit type" << endl;
            }
        }

        void withdraw(int amount) {
            if(amount > MAX_WITHDRAWAL_AMOUNT) {
                cout << "Cannot withdraw more than " << MAX_WITHDRAWAL_AMOUNT <<" dollars" << endl;
            }
            else if(amount % WITHDRAWAL_MULTIPLE_OF != 0) {
                cout << "Withdrawals can only be in multiples of " << WITHDRAWAL_MULTIPLE_OF << endl;
            }
            else if(balance - amount < 0) {
                cout << "Insufficient funds" << endl;
            }
            else {
                balance -= amount;
                cout << "Withdrew " << amount << " dollars" << endl;
            }
        }

        void check() {
            cout << "Current balance: " << balance << " dollars" << endl;
        }

};

void printMenu() {
    cout << endl;
    cout << "What would you like to do?" << endl;
    cout << "0: Make a deposit" << endl;
    cout << "1: Withdraw" << endl;
    cout << "2: Check balance" << endl;
    cout << "Any other number to quit, no letters please" << endl;
    //we are using >> so cin will fail on numbers, check link for more info:
    //https://stackoverflow.com/questions/36732225/switch-case-infinite-loop-bug-in-c
    cout << endl;
}

int main() {
    ATM atm = ATM(1000); //make an atm with 1000 dollars
    cout << "Welcome to Fake Bank Inc., you have been given a complimentary account with 1000 dollars" << endl;
    
    bool keep_going = true;
    int choice;
    while(keep_going) {
        printMenu();
        cin >> choice;

        switch(choice) {
            int amount;
            case 0:
                cout << "How much?" << endl;
                cin >> amount;

                int depositType;
                cout << "Is this a cash or check deposit?" << endl;
                cout << "0: Cash" << endl;
                cout << "1: Check" << endl;
                cin >> depositType;

                atm.deposit(amount, depositType);
                break;
            case 1:
                cout << "How much?" << endl;
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 2:
                atm.check();
                break;
            default:
                cout << "Goodbye!" << endl;
                keep_going = false;
                break;
        }
    }
}