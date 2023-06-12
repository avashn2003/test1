#include <iostream>
#include <vector>
using namespace std;
////////////////////////////////////////////
class Admin
{
private:
    string name, lastName, codeMeli, password;

    vector<Employee> employees;
    vector<Customer> customers;
    vector<Account> accounts;
    vector<Loan> loans;
    vector<Transaction> transactions;

public:
//////////////////////////////////////////////
    Admin(string name, string lastName, string codeMeli, string password) // sazande admin
    {
        this->name = name;
        this->lastName = lastName;
        this->codeMeli = codeMeli;
        this->password = password;
    }
//----------------------------------------employee------------------------------------------//
/////////////////////see employees////////////////////////////
    void searchEmployees()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            cout << employees[i].name << " " << employees[i].salary << endl;
        }
    }
/////////////////////add employee/////////////////////////////
    void addEmployee(Employee employee)
    {
        employees.push_back(employee);
    }
/////////////////////change employee salary///////////////////////////
    void updateEmployeeSalary(string employeeName, int newSalary)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].name == employeeName)
            {
                employees[i].salary = newSalary;
                break;
            }
        }
    }
////////////////////remove employee////////////////////////////
    void removeEmployee(string employeeName)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].name == employeeName)
            {
                employees.erase(employees.begin() + i);
                break;
            }
        }
    }
//----------------------------------------customer------------------------------------------//
/////////////////see customers////////////////////////
    void searchCustomers()
    {
        for (int i = 0; i < customers.size(); i++)
        {
            cout << customers[i].name << endl;
        }
    }
/////////////////////add customer/////////////////////////////
    void addCustomer(Customer customer)
    {
        customers.push_back(customer);
    }
///////////////////////change customer information////////////////////////////
    void updateCustomerAge(string customerName, int newAge)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].name == customerName)
            {
                customers[i].age = newAge;
                break;
            }
        }
    }

    void updateCustomerName(string customerName, string newName,string newLastName)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].name == customerName)
            {
                customers[i].name = newName;
                customers[i].lastName = newLastName;
                break;
            }
        }
    }
///////////////////////remove customer////////////////////////////
    void removeCustomer(string customerName)
    {
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].name == customerName)
            {
                customers.erase(customers.begin() + i);
                break;
            }
        }
    }
//----------------------------------------account------------------------------------------//
/////////////////see accounts////////////////////////
    void searchAccounts()
    {
        for (int i = 0; i < customers.size(); i++)
        {
            cout << accounts[i].name << endl;
        }
    }
///////////////////add account//////////////////////////
    void addAccount(Account account)
    {
        accounts.push_back(account);
    }
//////////////////////change account information/////////////////////////????????????????
    void updateAccountInfo(string accountNumber, int newTest)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountNumber == accountNumber)
            {
                accounts[i].test = newTest;
                break;
            }
        }
    }
/////////////////////remove account////////////////////////
    void removeAccount(string accountNumber)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].accountNumber == accountNumber)
            {
                accounts.erase(accounts.begin() + i);
                break;
            }
        }
    }
//----------------------------------------loan------------------------------------------//
///////////////////add loan//////////////////////////
    void addLoan(Loan loan)
    {
        loans.push_back(loan);
    }
///////////////////change loan information////////////////
    void updateLoanInfo(string loanNumber, int newAmount)
    {
        for (int i = 0; i < loans.size(); i++)
        {
            if (loans[i].loanNumber == loanNumber)
            {
                loans[i].amount = newAmount;
                break;
            }
        }
    }
//////////////////see loans////////////////////////////
    void searchLoan()
    {
        for (int i = 0; i < loans.size(); i++)
        {
            cout << loans[i].loanNumber << " " << loans[i].amount << endl;
        }
    }
//----------------------------------------tarakonesh------------------------------------------//
///////////////////add transaction////////////////////////
    void addTransaction(Transaction transaction)
    {
        transactions.push_back(transaction);
    }

    void updateTransactionInfo(string transactionNumber, int newAmount)
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            if (transactions[i].transactionNumber == transactionNumber)
            {
                transactions[i].amount = newAmount;
                break;
            }
        }
    }
//////////////////search transaction//////////////////////
    void searchTransactions()
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            cout << transactions[i].transactionNumber << " " << transactions[i].amount << endl;
        }
    }
};