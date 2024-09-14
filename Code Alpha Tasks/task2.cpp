#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool loggingin()
{
    string username, password, un, pw;
    cout<<" Enter username : ";
    cin>>username;
    cout<<" Password : ";
    cin>>password;


    ifstream read("C:\\Users\\shiva\\OneDrive\\Documents\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    int choice;

    system("cls");
    cout<<"\t\t\t WELCOME TO THE REGISTRATION AND LOGIN SCREEN "<<endl;
    cout<<" 1 : Register "<<endl;
    cout<<" 2 : Login "<<endl;
    cout<<" Select any option "<<endl;
    cin>>choice;
    if(choice == 1)
    {
        string username, password;
        cout<<" Enter a Username : ";
        cin>>username;
        cout<<" Enter password : ";
        cin>>password;

        ofstream file;
        file.open("C:\\Users\\shiva\\OneDrive\\Documents\\" + username + ".txt");
        file << username << endl;
        file << password << endl;
        file.close();
        cout << "Registration Successfull" << endl;

        main();
    }

    else if(choice == 2)
    {
        bool status = loggingin();
        if (!status)
        {
            cout<<" Invalid login! "<<endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout<<" Successfully logged in !! "<<endl;
        }
    }

    else
    {
        cout<<" Invalid Choice !!!"<<endl;
    }

    return 0;
}