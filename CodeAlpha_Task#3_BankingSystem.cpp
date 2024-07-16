#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Transaction
{
public:
    string type;
    double amount;
    string date;

    Transaction(string type, double amount, string date)
        : type(type), amount(amount), date(date) {}
};

class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNum, double bal = 0.0)
        : accountNumber(accNum), balance(bal) {}

    void deposit(double amount, string date)
    {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, date));
    }

    bool withdraw(double amount, string date)
    {
        if (amount > balance)
        {
            cout << "\n\033[1;31m Insufficient funds.\n033[0m";
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount, date));
        return true;
    }

    bool transfer(Account &toAccount, double amount, string date)
    {
        if (withdraw(amount, date))
        {
            toAccount.deposit(amount, date);
            transactions.push_back(Transaction(" Transfer to " + to_string(toAccount.getAccountNumber()), amount, date));
            toAccount.addTransaction(Transaction(" Transfer from " + to_string(accountNumber), amount, date));
            return true;
        }
        return false;
    }

    void displayAccountInfo() const
    {
        cout << "\n Account Number : " << accountNumber << "\n"
             << "\n Balance : $" << fixed << setprecision(2) << balance << "\n"
             << "\n\033[1;33m Recent Transactions :\n\033[0m";

        for (const auto &transaction : transactions)
        {
            cout << transaction.date << " - " << transaction.type << ": $" << transaction.amount << "\n";
        }
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void addTransaction(const Transaction &transaction)
    {
        transactions.push_back(transaction);
    }
};

class Customer
{
private:
    string name;
    int customerId;
    vector<Account> accounts;

public:
    Customer(string name, int id)
        : name(name), customerId(id) {}

    void addAccount(Account account)
    {
        accounts.push_back(account);
    }

    void displayCustomerInfo() const
    {
        cout << "\n Customer ID : " << customerId << "\n"
             << "\n Name : " << name << "\n"
             << "\n Accounts :\n";
        for (const auto &account : accounts)
        {
            account.displayAccountInfo();
        }
    }

    Account *getAccount(int accNum)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accNum)
            {
                return &account;
            }
        }
        return nullptr;
    }

    int getCustomerId() const
    {
        return customerId;
    }
};

class BankingService
{
private:
    vector<Customer> customers;

public:
    void createCustomer(string name, int id)
    {
        customers.push_back(Customer(name, id));
    }

    Customer *getCustomer(int id)
    {
        for (auto &customer : customers)
        {
            if (customer.getCustomerId() == id)
            {
                return &customer;
            }
        }
        return nullptr;
    }

    void createAccount(int customerId, int accountNumber, double initialDeposit = 0.0)
    {
        Customer *customer = getCustomer(customerId);
        if (customer)
        {
            customer->addAccount(Account(accountNumber, initialDeposit));
        }
        else
        {
            cout << "\n \033[1;31mCustomer not found.\n\033[0m";
        }
    }
};

int main()
{
    BankingService bankingService;

    cout << "\n\n \033[1;4;36m\t\tBanking System Menu:\n\n\033[0m" ;
    
    while (true)
    {
        cout << "\n\033[1;35m What task do you want to perform : \033[0m\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. View Account Info\n";
        cout << "7. Exit\n";
        cout << "\n Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 7)
            break;

        int customerId, accountNumber;
        double amount;
        string name, date;

        switch (choice)
        {
        case 1:
            cout << "\n Enter Customer ID: ";
            cin >> customerId;
            cout << "\n Enter Name: ";
            cin.ignore();
            getline(cin, name);
            bankingService.createCustomer(name, customerId);
            break;
        case 2:
            cout << "\n Enter Customer ID: ";
            cin >> customerId;
            cout << "\n Enter Account Number: ";
            cin >> accountNumber;
            cout << "\n Enter Initial Deposit: ";
            cin >> amount;
            bankingService.createAccount(customerId, accountNumber, amount);
            break;
        case 3:
            cout << "\n Enter Customer ID: ";
            cin >> customerId;
            cout << "\n Enter Account Number: ";
            cin >> accountNumber;
            cout << "\n Enter Deposit Amount: ";
            cin >> amount;
            cout << "\n Enter Date (dd/mm/yyyy): ";
            cin >> date;
            if (Customer *customer = bankingService.getCustomer(customerId))
            {
                if (Account *account = customer->getAccount(accountNumber))
                {
                    account->deposit(amount, date);
                }
                else
                {
                    cout << "\n\t \033[1;31mAccount not found.\n\033[0m";
                }
            }
            else
            {
                cout << "\n\t \033[1;31mCustomer not found.\n\033[0m";
            }
            break;
        case 4:
            cout << "\n Enter Customer ID: ";
            cin >> customerId;
            cout << "\n Enter Account Number: ";
            cin >> accountNumber;
            cout << "\n Enter Withdrawal Amount: ";
            cin >> amount;
            cout << "\n Enter Date (dd/mm/yyyy): ";
            cin >> date;
            if (Customer *customer = bankingService.getCustomer(customerId))
            {
                if (Account *account = customer->getAccount(accountNumber))
                {
                    account->withdraw(amount, date);
                }
                else
                {
                    cout <<"\n\t \033[1;31mAccount not found.\n\033[0m";
                }
            }
            else
            {
                cout << "\n\t \033[1;31mCustomer not found.\n\033[0m";
            }
            break;
        case 5:
            int toCustomerId, toAccountNumber;
            cout << "\n Enter Your Customer ID: ";
            cin >> customerId;
            cout << "\n Enter Your Account Number: ";
            cin >> accountNumber;
            cout << "\n Enter Transfer Amount: ";
            cin >> amount;
            cout << "\n Enter Date (dd/mm/yyyy): ";
            cin >> date;
            cout << "\n Enter Recipient Customer ID: ";
            cin >> toCustomerId;
            cout << "\n Enter Recipient Account Number: ";
            cin >> toAccountNumber;
            if (Customer *customer = bankingService.getCustomer(customerId))
            {
                if (Account *account = customer->getAccount(accountNumber))
                {
                    if (Customer *toCustomer = bankingService.getCustomer(toCustomerId))
                    {
                        if (Account *toAccount = toCustomer->getAccount(toAccountNumber))
                        {
                            account->transfer(*toAccount, amount, date);
                        }
                        else
                        {
                            cout << "\n\t\033[1;31m Recipient account not found.\n\033[0m";
                        }
                    }
                    else
                    {
                        cout << "\n\t\033[1;31m Recipient customer not found.\n\033[0m";
                    }
                }
                else
                {
                    cout <<"\n\t \033[1;31mAccount not found.\n\033[0m";
                }
            }
            else
            {
                cout << "\n\t \033[1;31mCustomer not found.\n\033[0m";
            }
            break;
        case 6:
            cout << "\n Enter Customer ID: ";
            cin >> customerId;
            if (Customer *customer = bankingService.getCustomer(customerId))
            {
                customer->displayCustomerInfo();
            }
            else
            {
                cout << "\n\t \033[1;31mCustomer not found.\n\033[0m";
            }
            break;
        default:
            cout << "\n\t \033[1;31mInvalid choice!\n\033[0m";
        }
    }

    return 0;
}

