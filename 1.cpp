// 1. Create a class Bank Account with private data members for account number, name, and balance.
//  Use public methods for deposit, withdraw, and display.
 // Demonstrate data abstraction and information hiding.


#include<iostream>
using namespace std;


class Bank{
private:
    int acc;
    string name;
    float balance;

public:
    
    Bank(int acc_n , string acc_name){
        acc=acc_n;
        name = acc_name;
        balance = 0;
    }

    void deposit(float amount){
        balance+=amount;
    }

    void withdraw(float amount){
        balance-=amount;
    }

    void display(){
        cout<<"Account name = " <<name<<endl;
        cout<<"Account number = " <<acc<<endl;
        cout<<"Account balance = " <<balance<<endl; 
    }
};

int main (){

    int acc;
    string name;
    cout << "Enter Account Number: ";
    cin >> acc;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

    Bank user(acc, name);

    int choice;
    float amt;

       while (true) {
        cout << "\n========= BANK MENU =========\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount to deposit: ";
            cin >> amt;
            user.deposit(amt);
        } 
        else if (choice == 2) {
            cout << "Enter amount to withdraw: ";
            cin >> amt;
            user.withdraw(amt);
        } 
        else if (choice == 3) {
            user.display();
        } 
        else if (choice == 4) {
            cout << "\nThank you for using our bank system.\n";
            break;
        } 
        else {
            cout <<"invalid";
        }
    }
    return 0;
}