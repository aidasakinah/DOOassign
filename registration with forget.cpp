#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class User {
private:
    string username;
    string email;
    string address;
    string contactNumber;
    string password;
    string cpassword;

public:

    void login() {
        int count = 0;
        string inputUsername, inputPassword;
        system("cls");
        cout << "User Login" << endl;
        cout << "USERNAME or EMAIL :";
        cin >> inputUsername;
        cout << "PASSWORD :";
        cin >> inputPassword;

        ifstream input("user records.txt");
        while (input >> username >> email >> address >> contactNumber >> password >> cpassword) {
            if ((username == inputUsername || email == inputUsername) && password == inputPassword) {
                count = 1;
                system("cls");
                break;
            }
        }
        input.close();

        if (count == 1) {
            cout << "\nHello " << username << "\n<LOGIN SUCCESSFUL>\nThanks for logging in Restaurant Fusion Fare Delights\n";
            cin.get();
            return;
        } else {
            cout << "\nLOGIN ERROR\nPlease check again your username or email and password\n";
            int main();
        }
    }

    void registration() {
        system("cls");
        cout << "User Register" << endl;
        cout << "\nName : ";
        cin >> username;
        cout << "\nEmail :";
        cin >> email;
        cout << "\nAddress :";
        cin >> address;
        cout << "\nContact Number :";
        cin >> contactNumber;
        cout << "\nPassword :";
        cin >> password;
        cout << "\nPassword Confirmation :";
        cin >> cpassword;

        ofstream reg("user records.txt", ios::app);
        reg << username << ' ' << email << ' ' << address << ' ' << contactNumber << ' ' << password << ' ' << cpassword << endl;
        system("cls");
        cout << "\nRegistration Successful\n";
        
        int main();
    }

    void forgetPassword() {
        string input;
        cout << "Enter your username or email to recover password: ";
        cin >> input;

        ifstream userFile("user records.txt");

        while (userFile >> username >> email >> address >> contactNumber >> password >> cpassword) {
            if (username == input || email == input) {
                cout << "Your password is : " << password << endl;
                return;
            }
        }

        cout << "User not found. Please check your username or email." << endl;
        return;
    }

   
};


class AdminLogin {
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
            return;
        } else {
            cout << "\nADMIN LOGIN ERROR\nPlease check your Admin ID and Password\n";
            return;
        }
    }
};

int main() {
    int choice;
    User user;
    AdminLogin admin;

    do {
        cout << "************************************************\n";
        cout << "\t      Welcome to login page \n";
        cout << "**************      MENU      ******************\n\n";
        cout << "1. USER LOGIN" << endl;
        cout << "2. USER REGISTER" << endl;
        cout << "3. FORGET PASSWORD" << endl;
        cout << "4. ADMINISTRATOR LOGIN" << endl;
        cout << "5. EXIT" << endl;
        cout << "\nEnter your choice :";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                user.login();
                break;
            case 2:
                user.registration();
                break;
            case 3:
                user.forgetPassword();
                break;
            case 4:
                admin.adminlogin();
                break;
            case 5:
                cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
                break;
            default:
                system("cls");
                cout << "Please select again\n" << endl;
        }
    } while (choice != 5);

    return 0;
}
