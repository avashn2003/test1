#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdio.h>

using namespace std;
///////////////////hash///////////////////////
unsigned int Hash(string &data)
{
    unsigned int result(0);

    for (unsigned int ch : data)
        result = ch + (result << 4) + (result << 10) - result;

    return result;
}
////////////////////class////////////////////////
class Admin
{
private:
    string name, lastName, codeMeli, password;

public:
    //------------------------------------------------admin-----------------------------------------------------//
    Admin(string name, string lastName, string codeMeli, string password) // sazande admin
    {
        this->name = name;
        this->lastName = lastName;
        this->codeMeli = codeMeli;
        this->password = password;
    }
    //----------------------------------------employee------------------------------------------//

    /////////////////////search employees///////////////////////// OKKKK
    void searchEmployee()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to see : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("employee.csv");

        string line;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, email, nationalcode, salary;

            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, personalcode, ',');
            getline(ss, salary, ',');
            getline(ss, gender, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, email, ',');
            if (nationalcode == searchNationalCode)
            {
                isNational = true;

                cout << "national code is : " << nationalcode << "\n";
                cout << "password is : " << password << "\n";
                cout << "personal code is : " << personalcode << "\n";
                cout << "salary is : " << salary << "\n";
                cout << "gender is : " << gender << "\n";
                cout << "firstname is : " << firstname << "\n";
                cout << "lastname is : " << lastname << "\n";
                cout << "phone number is : " << phonenumber << "\n";
                cout << "birth is : " << birth << "\n";
                cout << "email is : " << email << "\n";
                cout << "*****************************\n";
                goto error;
            }
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist."
                 << "\n";
            cout << "*****************************\n";
        }
    }

    /////////////////////see employees//////////////////////////// okkkkk
    void seeEmployees()
    {

        ifstream inputFile1("employee.csv");

        string line;
        int i = 1;

        while (inputFile1 >> line)
        {

            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, email, nationalcode, salary;

            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, personalcode, ',');
            getline(ss, salary, ',');
            getline(ss, gender, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, email, ',');

            cout << "national code " << i << " is : " << nationalcode << "\n";
            cout << "password " << i << " is : " << password << "\n";
            cout << "personal code " << i << " is : " << personalcode << "\n";
            cout << "salary" << i << " is : " << salary << "\n";
            cout << "gender " << i << " is : " << gender << "\n";
            cout << "firstname " << i << " is : " << firstname << "\n";
            cout << "lastname " << i << " is : " << lastname << "\n";
            cout << "phone number " << i << " is : " << phonenumber << "\n";
            cout << "email " << i << " is : " << email << "\n";
            cout << "*****************************\n";

            i++;
        }
    }
    /////////////////////add employee///////////////////////////// okkkk
    void addEmployee()
    {
        ofstream file;

        string a = ",";

        string firstname, lastname, personalcode, password, gender, phonenumber, birth, email, nationalcode, salary;
        cout << "*****************************\n";
        cout << "national code : ";
        cin >> nationalcode;
        cout << endl;
        cout << "password : ";
        cin >> password;
        cout << endl;
        cout << "personal code : ";
        cin >> personalcode;
        cout << endl;
        cout << "salary : ";
        cin >> salary;
        cout << endl;
        cout << "gender : ";
        cin >> gender;
        cout << endl;
        cout << "firstname : ";
        cin >> firstname;
        cout << endl;
        cout << "lastname : ";
        cin >> lastname;
        cout << endl;
        cout << "phone number : ";
        cin >> phonenumber;
        cout << endl;
        cout << "birth : ";
        cin >> birth;
        cout << endl;
        cout << "email : ";
        cin >> email;
        cout << endl;
        cout << "*****************************\n";

        file.open("employee.csv", ios::app);
        file << nationalcode << a << password << a << personalcode << a << salary << a << gender << a << firstname
             << a << lastname << a << phonenumber << a << birth << a << email << endl;
    }
    /////////////////////change employee salary/////////////////////////// okkkkkkk
    void updateEmployeeSalary()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code want to delete : ";
        string newNationalCode;
        cin >> newNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("employee.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, email, nationalcode, salary;

            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, personalcode, ',');
            getline(ss, salary, ',');
            getline(ss, gender, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, email, ',');

            if (nationalcode == newNationalCode)
            {
                string newSalary;
                cout << "enter new salary : ";
                cin >> newSalary;

                int m = 0;
                isNational = true;
                ofstream outputFile("temp.csv", ios::app);
                ifstream inputFile2("employee.csv");
                string a = ",";

                while (inputFile2 >> line2)
                {
                    if (m == n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, password, ',');
                        getline(ss, personalcode, ',');
                        getline(ss, salary, ',');
                        getline(ss, gender, ',');
                        getline(ss, firstname, ',');
                        getline(ss, lastname, ',');
                        getline(ss, phonenumber, ',');
                        getline(ss, birth, ',');
                        getline(ss, email, ',');

                        outputFile << nationalcode << a << password << a << personalcode << a << newSalary << a << gender << a << firstname
                                   << a << lastname << a << phonenumber << a << birth << a << email << endl;
                    }

                    if (m != n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, password, ',');
                        getline(ss, personalcode, ',');
                        getline(ss, salary, ',');
                        getline(ss, gender, ',');
                        getline(ss, firstname, ',');
                        getline(ss, lastname, ',');
                        getline(ss, phonenumber, ',');
                        getline(ss, birth, ',');
                        getline(ss, email, ',');

                        outputFile << nationalcode << a << password << a << personalcode << a << salary << a << gender << a << firstname
                                   << a << lastname << a << phonenumber << a << birth << a << email << endl;
                    }
                    m++;
                }
                outputFile.close();
                inputFile2.close();
                inputFile1.close();

                remove("employee.csv");

                rename("temp.csv", "employee.csv");

                cout << "change successfully." << endl;
                cout << "*****************************\n";
                goto error;
            }
            n++;
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    ////////////////////remove employee//////////////////////////// OKKK
    void removeEmployee()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code want to delete : ";
        string removeNationalCode;
        cin >> removeNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("employee.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, email, nationalcode, salary;

            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, personalcode, ',');
            getline(ss, salary, ',');
            getline(ss, gender, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, email, ',');
            if (nationalcode == removeNationalCode)
            {
                int m = 0;
                isNational = true;
                ofstream outputFile("temp.csv", ios::app);
                ifstream inputFile2("employee.csv");
                string a = ",";

                while (inputFile2 >> line2)
                {
                    if (m != n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, password, ',');
                        getline(ss, personalcode, ',');
                        getline(ss, salary, ',');
                        getline(ss, gender, ',');
                        getline(ss, firstname, ',');
                        getline(ss, lastname, ',');
                        getline(ss, phonenumber, ',');
                        getline(ss, birth, ',');
                        getline(ss, email, ',');

                        outputFile << nationalcode << a << password << a << personalcode << a << salary << a << gender << a << firstname
                                   << a << lastname << a << phonenumber << a << birth << a << email << endl;
                    }
                    m++;
                }
                outputFile.close();
                inputFile2.close();
                inputFile1.close();

                remove("employee.csv");

                rename("temp.csv", "employee.csv");

                cout << "delete successfully,";
                cout << "*****************************\n";
                goto error;
            }
            n++;
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }

    //----------------------------------------customer------------------------------------------------//

    /////////////////////search customers///////////////////////// OKKKK
    void searchCustomer()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to see : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("customer.csv");

        string line;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, nationalcode, membership;
            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, gender, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, membership, ',');
            if (nationalcode == searchNationalCode)
            {
                isNational = true;
                cout << "national code is : " << nationalcode << "\n";
                cout << "password is : " << password << "\n";
                cout << "firstname is : " << firstname << "\n";
                cout << "lastname is : " << lastname << "\n";
                cout << "gender is : " << gender << "\n";
                cout << "phone number is : " << phonenumber << "\n";
                cout << "birth is : " << birth << "\n";
                cout << "membership number is : " << membership << "\n";
                cout << "*****************************\n";
                goto error;
            }
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    /////////////////see customers//////////////////////// okkkkkk
    void seeCustomer()
    {

        ifstream inputFile1("customer.csv");

        string line;
        int i = 1;

        while (inputFile1 >> line)
        {

            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, nationalcode, membership;
            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, gender, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, membership, ',');

            cout << "firstname " << i << " is : " << firstname << "\n";
            cout << "lastname " << i << " is : " << lastname << "\n";
            cout << "password " << i << " is : " << password << "\n";
            cout << "gender " << i << " is : " << gender << "\n";
            cout << "phone number " << i << " is : " << phonenumber << "\n";
            cout << "birth " << i << " is : " << birth << "\n";
            cout << "membership number " << i << " is : " << membership << "\n";
            cout << "*****************************\n";

            i++;
        }
    }
    /////////////////////add customer///////////////////////// okkkkkkkkkkk
    void addCustomer()
    {
        ofstream file;

        string a = ",";

        string firstname, lastname, personalcode, password, gender, phonenumber, birth, nationalcode, membership;
        cout << "*****************************\n";
        cout << "national code : ";
        cin >> nationalcode;
        cout << endl;
        cout << "password : ";
        cin >> password;
        cout << endl;
        cout << "membership : ";
        cin >> membership;
        cout << endl;
        cout << "gender : ";
        cin >> gender;
        cout << endl;
        cout << "firstname : ";
        cin >> firstname;
        cout << endl;
        cout << "lastname : ";
        cin >> lastname;
        cout << endl;
        cout << "phone number : ";
        cin >> phonenumber;
        cout << endl;
        cout << "birth : ";
        cin >> birth;
        cout << endl;
        cout << "*****************************\n";

        file.open("customer.csv", ios::app);
        file << nationalcode << a << password << a << firstname << a << lastname << a << gender
             << a << phonenumber << a << birth << a << membership << endl;
    }
    ///////////////////////change customer information//////////////////////////// okkkkkkkk
    void updateCustomerPassOrPhonenumber()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code want to delete : ";
        string newNationalCode;
        cin >> newNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("customer.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, nationalcode, membership;
            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, gender, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, membership, ',');

            if (nationalcode == newNationalCode)
            {
                cout << "what wholud you need to change : ";
                string answer;
                getline(cin, answer);

                if (answer == "password")
                {
                    string newPass;
                    cout << "enter new password : ";
                    cin >> newPass;

                    unsigned int pass2 = Hash(newPass);

                    int m = 0;
                    isNational = true;
                    ofstream outputFile("temp.csv", ios::app);
                    ifstream inputFile2("customer.csv");
                    string a = ",";

                    while (inputFile2 >> line2)
                    {
                        if (m == n)
                        {
                            stringstream ss(line2);

                            getline(ss, nationalcode, ',');
                            getline(ss, password, ',');
                            getline(ss, firstname, ',');
                            getline(ss, lastname, ',');
                            getline(ss, gender, ',');
                            getline(ss, phonenumber, ',');
                            getline(ss, birth, ',');
                            getline(ss, membership, ',');

                            outputFile << nationalcode << a << pass2 << a << firstname << a << lastname << a << gender
                                       << a << phonenumber << a << birth << a << membership << endl;
                        }

                        if (m != n)
                        {
                            stringstream ss(line2);

                            getline(ss, nationalcode, ',');
                            getline(ss, password, ',');
                            getline(ss, firstname, ',');
                            getline(ss, lastname, ',');
                            getline(ss, gender, ',');
                            getline(ss, phonenumber, ',');
                            getline(ss, birth, ',');
                            getline(ss, membership, ',');

                            outputFile << nationalcode << a << password << a << firstname << a << lastname << a << gender
                                       << a << phonenumber << a << birth << a << membership << endl;
                        }
                        m++;
                    }
                    outputFile.close();
                    inputFile2.close();
                    inputFile1.close();

                    remove("customer.csv");

                    rename("temp.csv", "customer.csv");

                    cout << "change successfully." << endl;
                    cout << "*****************************\n";
                    goto error;
                }

                if (answer == "phone number")
                {
                    string newPhone;
                    cout << "enter new phone : ";
                    cin >> newPhone;

                    int m = 0;
                    isNational = true;
                    ofstream outputFile("temp.csv", ios::app);
                    ifstream inputFile2("customer.csv");
                    string a = ",";

                    while (inputFile2 >> line2)
                    {
                        if (m == n)
                        {
                            stringstream ss(line2);

                            getline(ss, nationalcode, ',');
                            getline(ss, password, ',');
                            getline(ss, firstname, ',');
                            getline(ss, lastname, ',');
                            getline(ss, gender, ',');
                            getline(ss, phonenumber, ',');
                            getline(ss, birth, ',');
                            getline(ss, membership, ',');

                            outputFile << nationalcode << a << password << a << firstname << a << lastname << a << gender
                                       << a << newPhone << a << birth << a << membership << endl;
                        }

                        if (m != n)
                        {
                            stringstream ss(line2);

                            getline(ss, nationalcode, ',');
                            getline(ss, password, ',');
                            getline(ss, firstname, ',');
                            getline(ss, lastname, ',');
                            getline(ss, gender, ',');
                            getline(ss, phonenumber, ',');
                            getline(ss, birth, ',');
                            getline(ss, membership, ',');

                            outputFile << nationalcode << a << password << a << firstname << a << lastname << a << gender
                                       << a << phonenumber << a << birth << a << membership << endl;
                        }
                        m++;
                    }
                    outputFile.close();
                    inputFile2.close();
                    inputFile1.close();

                    remove("customer.csv");

                    rename("temp.csv", "customer.csv");

                    cout << "change successfully." << endl;
                    cout << "*****************************\n";
                    goto error;
                }

                n++;
            }
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }

    /////////////////////remove customers///////////////////////// OKKKK
    void removeCustomer()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to delete : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("customer1.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string firstname, lastname, personalcode, password, gender, phonenumber, birth, nationalcode, membership;
            getline(ss, nationalcode, ',');
            getline(ss, password, ',');
            getline(ss, firstname, ',');
            getline(ss, lastname, ',');
            getline(ss, gender, ',');
            getline(ss, phonenumber, ',');
            getline(ss, birth, ',');
            getline(ss, membership, ',');
            if (nationalcode == searchNationalCode)
            {
                int m = 0;
                isNational = true;
                ofstream outputFile("temp.csv", ios::app);
                ifstream inputFile2("customer.csv");
                string a = ",";

                while (inputFile2 >> line2)
                {
                    if (m != n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, password, ',');
                        getline(ss, firstname, ',');
                        getline(ss, lastname, ',');
                        getline(ss, gender, ',');
                        getline(ss, phonenumber, ',');
                        getline(ss, birth, ',');
                        getline(ss, membership, ',');

                        outputFile << nationalcode << a << password << a << firstname << a << lastname << a << gender
                                   << a << phonenumber << a << birth << a << membership << endl;
                        m++;
                    }
                    outputFile.close();
                    inputFile2.close();
                    inputFile1.close();

                    remove("customer.csv");

                    rename("temp.csv", "customer.csv");

                    cout << "remove successfully." << endl;
                    cout << "*****************************\n";
                    goto error;
                }
                n++;
            }

        error:
            if (isNational == false)
            {
                cout << "the national code is not exist.";
            }
        }
    }
    //----------------------------------------account------------------------------------------//

    /////////////////see accounts//////////////////////// okkkkkkkkk
    void searchAccounts()
    {
        ifstream inputFile1("account.csv");

        string line;
        int i = 1;

        while (inputFile1 >> line)
        {

            stringstream ss(line);
            string nationalcode, number, type, expYear, expMonth, cvv2, password, balance;
            getline(ss, nationalcode, ',');
            getline(ss, number, ',');
            getline(ss, type, ',');
            getline(ss, expYear, ',');
            getline(ss, expMonth, ',');
            getline(ss, cvv2, ',');
            getline(ss, password, ',');
            getline(ss, balance, ',');

            cout << "national code " << i << " is : " << nationalcode << "\n";
            cout << "number " << i << " is : " << number << "\n";
            cout << "type " << i << " is : " << type << "\n";
            cout << "expire year " << i << " is : " << expYear << "\n";
            cout << "expire month " << i << " is : " << expMonth << "\n";
            cout << "cvv2 " << i << " is : " << cvv2 << "\n";
            cout << "password " << i << " is : " << password << "\n";
            cout << "balance " << i << " is : " << balance << "\n";
            cout << "*****************************\n";

            i++;
        }
    }
    ///////////////////add account////////////////////////// okkkkkkkkkkk
    void addAccount()
    {
        string nationalcode,type;
        ofstream file;
        file.open("account.csv", ios::app);
        
        cout<<"*****************************\n";
        cout<<"Enter your national code: ";
        getline(cin,nationalcode);

        srand(time(NULL));
        unsigned long long int number=rand()*10;

        cout<<"Enter your acoount type: 1:current account 2:short term account 3:long term account : ";
        getline(cin,type);

        time_t expYear= time(nullptr);
        tm* local_time = localtime(&expYear);
        expYear=local_time->tm_year+1900 +5;

        time_t expMonth= time(nullptr);
        tm* local_time1 = localtime(&expMonth);
        expMonth=local_time1->tm_mon+1;

        srand(time(NULL));
        unsigned long long pin=(rand()/10)+111;
        string pin1=to_string(pin);
        unsigned int pin2= Hash(pin1);
        

        srand(time(NULL));
        unsigned long long int cvv2=rand(),balance;
        cout<<"Enter your balance: ";
        cin>>balance;
        

        string c=",";
        //writing in account file
        file<<nationalcode<<c<<number<<c<<type<<c<<expYear<<c<<expMonth<<c<<cvv2<<c<<pin2<<c<<balance<<endl;

        cout<<"*****************************\n"<<"your card number:"<<number<<'\n'<<"exp year:"<<expYear<<'\n'
        <<"exp month:"<<expMonth<<'\n'<<"cvv2: "<<cvv2<<'\n'<<"pin:"<<pin<<"\n*****************************"<<endl;

        file.close();
    }
    //////////////////////change account information///////////////////////// okkkkkkkkkkkk
    void updateAccountpass(string accountNumber, int newTest)
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code want to change : ";
        string newNationalCode;
        cin >> newNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("account.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string nationalcode, number, type, expYear, expMonth, cvv2, password, balance;
            getline(ss, nationalcode, ',');
            getline(ss, number, ',');
            getline(ss, type, ',');
            getline(ss, expYear, ',');
            getline(ss, expMonth, ',');
            getline(ss, cvv2, ',');
            getline(ss, password, ',');
            getline(ss, balance, ',');

            if (nationalcode == newNationalCode)
            {
                string newPass;
                cout << "enter new password : ";
                cin >> newPass;

                unsigned int pass2 = Hash(newPass);

                int m = 0;
                isNational = true;
                ofstream outputFile("temp.csv", ios::app);
                ifstream inputFile2("account.csv");
                string a = ",";

                while (inputFile2 >> line2)
                {
                    if (m == n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, number, ',');
                        getline(ss, type, ',');
                        getline(ss, expYear, ',');
                        getline(ss, expMonth, ',');
                        getline(ss, cvv2, ',');
                        getline(ss, password, ',');
                        getline(ss, balance, ',');

                        outputFile << nationalcode << a << number << a << type << a << expYear << a << expMonth
                                   << a << cvv2 << a << pass2 << a << balance << endl;
                    }

                    if (m != n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, number, ',');
                        getline(ss, type, ',');
                        getline(ss, expYear, ',');
                        getline(ss, expMonth, ',');
                        getline(ss, cvv2, ',');
                        getline(ss, password, ',');
                        getline(ss, balance, ',');

                        outputFile << nationalcode << a << number << a << type << a << expYear << a << expMonth
                                   << a << cvv2 << a << password << a << balance << endl;
                    }
                    m++;
                }
                outputFile.close();
                inputFile2.close();
                inputFile1.close();

                remove("account.csv");

                rename("temp.csv", "account.csv");

                cout << "change successfully." << endl;
                cout << "*****************************\n";
                goto error;
            }
            n++;
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    /////////////////////remove account//////////////////////// okkkkkkkkkk
    void removeAccount()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to delete : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("account.csv");

        string line, line2;
        int n = 0;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string nationalcode, number, type, expYear, expMonth, cvv2, password, balance;
            getline(ss, nationalcode, ',');
            getline(ss, number, ',');
            getline(ss, type, ',');
            getline(ss, expYear, ',');
            getline(ss, expMonth, ',');
            getline(ss, cvv2, ',');
            getline(ss, password, ',');
            getline(ss, balance, ',');

            if (nationalcode == searchNationalCode)
            {
                int m = 0;
                isNational = true;
                ofstream outputFile("temp.csv", ios::app);
                ifstream inputFile2("account.csv");
                string a = ",";

                while (inputFile2 >> line2)
                {
                    if (m != n)
                    {
                        stringstream ss(line2);

                        getline(ss, nationalcode, ',');
                        getline(ss, number, ',');
                        getline(ss, type, ',');
                        getline(ss, expYear, ',');
                        getline(ss, expMonth, ',');
                        getline(ss, cvv2, ',');
                        getline(ss, password, ',');
                        getline(ss, balance, ',');

                        outputFile << nationalcode << a << number << a << type << a << expYear << a << expMonth
                                   << a << cvv2 << a << password << a << balance << endl;
                    }
                    m++;
                }
                outputFile.close();
                inputFile2.close();
                inputFile1.close();

                remove("account.csv");

                rename("temp.csv", "account.csv");

                cout << "remove successfully." << endl;
                cout << "*****************************\n";
                goto error;
            }
            n++;
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    //----------------------------------------loan------------------------------------------//
    
    //////////////////see loans//////////////////////////// okkkkkkkkkk
    void seeLoan()
    {
        ifstream inputFile1("loan.csv");

        string line;
        int i = 1;

        while (inputFile1 >> line)
        {

            stringstream ss(line);
            string nationalcode,code,amount,returnamount,date;
            getline(ss, nationalcode, ',');
            getline(ss, code, ',');
            getline(ss, amount, ',');
            getline(ss, returnamount, ',');
            getline(ss, date, ',');

            cout << "national code " << i << " is : " << nationalcode << "\n";
            cout << "code " << i << " is : " << code << "\n";
            cout << "amount " << i << " is : " << amount << "\n";
            cout << " return amount " << i << " is : " << returnamount << "\n";
            cout << "date " << i << " is : " << date << "\n";
            cout << "*****************************\n";

            i++;
        }
    }

    //////////////////////search loan///////////////////////////////
    void searchLoan()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to see : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("loan.csv");

        string line;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string nationalcode,code,amount,returnamount,date;
            getline(ss, nationalcode, ',');
            getline(ss, code, ',');
            getline(ss, amount, ',');
            getline(ss, returnamount, ',');
            getline(ss, date, ',');

            if (nationalcode == searchNationalCode)
            {
                isNational = true;
                cout << "national code is : " << nationalcode << "\n";
                cout << "code is : " << code << "\n";
                cout << "amount is : " << amount << "\n";
                cout << "return amount is : " << returnamount << "\n";
                cout << "date is : " << date << "\n";
                cout << "*****************************\n";
                goto error;
            }
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    //////////////////////update loan return amount//////////////////
    void updateLoanReturn()
    {

    }
    //----------------------------------------tarakonesh------------------------------------------//

    //////////////////see transaction/////////////////////////
    void seeTransaction()
    {
        ifstream inputFile1("transaction.csv");

        string line;
        int i = 1;

        while (inputFile1 >> line)
        {

            stringstream ss(line);
            string nationalcode,code,amount,returnamount,date;
            getline(ss, nationalcode, ',');
            getline(ss, code, ',');
            getline(ss, amount, ',');
            getline(ss, returnamount, ',');
            getline(ss, date, ',');

            cout << "national code " << i << " is : " << nationalcode << "\n";
            cout << "code " << i << " is : " << code << "\n";
            cout << "amount " << i << " is : " << amount << "\n";
            cout << " return amount " << i << " is : " << returnamount << "\n";
            cout << "date " << i << " is : " << date << "\n";
            cout << "*****************************\n";

            i++;
        }
    }
    //////////////////search transaction//////////////////////
    void searchTransactions()
    {
        bool isNational = false;
        cout << "*****************************\n";
        cout << "enter national code that you want to see : ";
        string searchNationalCode;
        cin >> searchNationalCode;
        cout << "*****************************\n";

        ifstream inputFile1("customer.csv");

        string line;

        while (inputFile1 >> line)
        {
            stringstream ss(line);
            string nationalcode,code,amount,returnamount,date;
            getline(ss, nationalcode, ',');
            getline(ss, code, ',');
            getline(ss, amount, ',');
            getline(ss, returnamount, ',');
            getline(ss, date, ',');

            if (nationalcode == searchNationalCode)
            {
                isNational = true;
                cout << "national code is : " << nationalcode << "\n";
                cout << "code is : " << code << "\n";
                cout << "amount is : " << amount << "\n";
                cout << "return amount is : " << returnamount << "\n";
                cout << "gender is : " << gender << "\n";
                cout << "date is : " << date << "\n";
                cout << "*****************************\n";
                goto error;
            }
        }

    error:
        if (isNational == false)
        {
            cout << "the national code is not exist.";
        }
    }
    //////////////////////update transaction //////////////////
    void updateTransaction()
    {

    }
};
