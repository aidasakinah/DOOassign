#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void login();
void registration();
void recoverPassword();

class AdminLogin 
{
private:
    string adminId;
    string adminPass;

public:
    AdminLogin() : adminId("admin"), adminPass("admin123") {}

    void adminlogin() {
        int count = 0;
        string inputId, inputPass;

        system("cls");
        cout << "Administrator Login" << endl;
        cout << "Admin ID: ";
        cin >> inputId;
        cout << "Password: ";
        cin >> inputPass;

        if (inputId == adminId && inputPass == adminPass) {
            count = 1;
            system("cls");
        }

        if (count == 1) {
            cout << "\n<ADMIN LOGIN SUCCESSFUL>\n";
            cout << "Welcome, Admin " << adminId << endl;
        } else {
            cout << "\nADMIN LOGIN ERROR\nPlease check your Admin ID and Password\n";
            int main();
        }
    }
}; //end of class

int main()
{
    int choice;
    cout << "************************************************\n";
    cout << "\t      Welcome to login page \n";
    cout << "**************      MENU      ******************\n\n";
    cout << "1. LOGIN" << endl;
        cout << "2. REGISTER" << endl;
        cout << "3. RECOVER PASSWORD" << endl;
        cout << "4. ADMINISTRATOR LOGIN" << endl;
        cout << "5. Exit" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    
    switch (choice)
    {
    case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                recoverPassword();
                break;
            case 4:
                {
                    AdminLogin adminAuth;
                    adminAuth.adminlogin();
                    break;
                }
            case 5:
                cout << "Thank You." << endl;
                break;
    default:
        system("cls");
        cout << "Please select again\n"
             << endl;
        main();
    }

    return 0;
}//end of main

void login() {
    int count = 0;
    string username, pass, n, e, a, cn, p;  // Added variables for email, address, and contact number
    system("cls");
    cout << "User Login" << endl;
    cout << "USERNAME or EMAIL :";
    cin >> username;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("user records.txt");
    while (input >> n >> e >> a >> cn >> p) 
	{
        if ((n == username || e == username) && p == pass) 
		{
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();

    if (count == 1) 
	{
        cout << "\nHello " << n << "\n<LOGIN SUCCESSFUL>\nThanks for logging in Restaurant Fusion Fare Delights\n";
        cin.get();
 
        main();
    } else 
	{
        cout << "\nLOGIN ERROR\nPlease check again your username or email and password\n";
        main();
    }
}


void registration()
{
    string rname, email, address, cn, rpass, crpass, rn, rp;
    system("cls");
    cout << "User Register" << endl;
    cout << "\nName : ";
    cin >> rname;
    cout << "\nEmail :";
    cin >> email;
    cout << "\nAddress :";
    cin >> address;
    cout << "\nContact Number :";
    cin >> cn;
    cout << "\nPassword :";
    cin >> rpass;
    cout << "\nPassword Confirmation:";
    cin >> crpass;

    ofstream reg("user records.txt", ios::app);
    reg << rname << ' ' << email << ' ' << address << ' ' << cn << ' ' << rpass << endl;
    system("cls");
    cout << "\nRegistration Successful\n";
    main();
}

void recoverPassword() 
{
    string username;
    cout << "Enter your username or email to recover password: ";
    cin >> username;

    ifstream userFile("user records.txt");
    string name, email, address, cn, password;

    while (userFile >> name >> email >> address >> cn >> password) 
	{
        if (name == username || email == username) 
		{
            cout << "Your password is : " << password << endl;
            return;
        }
    }

    cout << "User not found. Please check your username or email." << endl;
}
