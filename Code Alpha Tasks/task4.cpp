#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class bank
{
    char name[30];
    int accno;
    char acctype[25];
    int bal;
    string lasttransaction;
    
    public:
    void opbal(void);
    void deposit(void);
    void withdraw(void);
    void display(void);
    void displaylasttransaction(void);
};


void bank :: opbal(void)
{
    cout<<endl<<endl;
    cout<<"Enter Name of the Account Holder : "<<endl;
    cout<<"NOTE : (Please don't use space in entering account name) "<<endl;
    cin>>name;
    cout<<"Enter Account Number : "<<endl;
    cin>>accno;
    cout<<"Enter Account Type : "<<endl;
    cin>>acctype;
    cout<<"Enter Opening Balance : "<<endl;
    cin>>bal;
    lasttransaction = "Account opened with balance : " + to_string(bal);
}

void bank :: deposit(void){
    int deposit = 0;
    cout<<"Enter Deposit amount of your account : "<<endl;
    cin>>deposit;
    bal = deposit + bal;
    cout<<" Deposite Balance = "<<bal<<endl;
    lasttransaction = "Deposited: " + to_string(deposit) + ", New Balance: " + to_string(bal);
}

void bank :: withdraw(void)
{
    int withdraw;
    cout<<"Balance Amount of your account "<<endl;
    cout<<"Please enter your withdraw Amount "<<endl;
    cin>>withdraw;
    if(bal>withdraw)
    {
        bal = bal-withdraw;
        cout<<"After withdraw Balance is : "<<bal<<endl;
        lasttransaction = "Withdraw: " + to_string(withdraw) + ", New Balance: " + to_string(bal);
    }
    else
    {
        cout<<"NO Balance in your account "<<endl;
        lasttransaction = "Failed withdraw of: " + to_string(withdraw) + " due to insufficient funds.";
    }
}


void bank :: display(void)
{
    cout<<endl<<endl<<endl;
    cout<<setw(50)<<" Details "<<endl;
    cout<<setw(50)<<" Name "<<name<<endl;
    cout<<setw(50)<<" A/C. No. "<<accno<<endl;
    cout<<setw(50)<<" A/C Type "<<acctype<<endl;
    cout<<setw(50)<<" Balance "<<bal<<endl;
    cout<<setw(50)<<" Last Transaction: "<<lasttransaction<<endl;
}


void bank :: displaylasttransaction(void)
{
    cout<<endl<<endl;
    cout<<"Last Transaction : "<<lasttransaction<<endl;
}



int main()
{
    bank ol;
    int option;
    system("cls");
    do{
        cout<<"\t\t\t --------------------Banking System------------------------ "<<endl;
        cout<<" ----------Option List------------"<<endl;
        cout<<" 1) To Create New account "<<endl;
        cout<<" 2) To Deposit "<<endl;
        cout<<" 3) To Withdraw "<<endl;
        cout<<" 4) To Display All Detail of your Account "<<endl;
        cout<<" 5) To Display Last Transaction of your Account "<<endl;
        cout<<" 6) Exit \n"<<endl;
        cin>>option;

        switch(option)
        {
            case 1 :
            system("cls");
            ol.opbal();
            break;
            
            case 2 :
            system("cls");
            ol.deposit();
            break;

            case 3:
            system("cls");
            ol.withdraw();
            break;

            case 4 :
            system("cls");
            ol.display();
            break;

            case 5 :
            system("cls");
            ol.displaylasttransaction();
            break;

            case 6 : goto end;
            break;

            default: cout<<"Invalid option !!!!!"<<endl;
        }
    }
    while(1);
    end:
    return 0;
}