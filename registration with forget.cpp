#include <iostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class User 
{
private:
    string username;
    string email;
    string address;
    string contactNumber;
    string password;
    string cpassword;

public:
	
    void login() 
	{
        int count = 0;
        string inputUsername, inputPassword;

        system("cls");
        cout << "User Login" << endl;
        cout << "USERNAME or EMAIL :";
        getline(cin, inputUsername);
        cout << "PASSWORD :";
        getline(cin, inputPassword);

        ifstream input("user records.txt");
        while (input >> username >> email >> address >> contactNumber >> password >> cpassword) 
		{
            if ((username == inputUsername || email == inputUsername) && password == inputPassword) 
			{
                count = 1;
                system("cls");
                break;
            }
        }
        input.close();

        if (count == 1) 
		{
            cout << "\nHello " << username << "\n<LOGIN SUCCESSFUL>\nThanks for logging in Restaurant Fusion Fare Delights\n";    
            int main();
        } 
		else 
		{
            cout << "\nLOGIN ERROR\nPlease check again your username or email and password\n";
            int main();
        }
    }

    void registration() 
	{
        system("cls");
        cout << "User Register" << endl;
        cout << "\nName : ";
        getline(cin, username);
        //check if the name already exist
        ifstream checkName("user records.txt");
		string existingUsername;		
		do 
		{
		    if (existingUsername == username) 
			{
		        cout << "\nUsername already exists. Please try again and choose a different name.\n";
		       return;
		    }
		}while (checkName >> existingUsername >> email >> address >> contactNumber >> password >> cpassword);
        
        cout << "\nEmail :";
        getline(cin, email);     
       // Check if the email already exists
		ifstream checkEmail("user records.txt");
		string existingEmail;
		do 
		{
		    if (existingEmail == email) 
			{
		        cout << "\nEmail already exists. Please try again and choose a different email.\n";
		        return;  
		    }
		}while (checkEmail >> username >> existingEmail >> address >> contactNumber >> password >> cpassword);
        
        cout << "\nAddress :";
        getline(cin, address);
        cout << "\nContact Number :";
        getline(cin, contactNumber);
        
        //ensure the pwd is match
        do 
		{
        cout << "\nPassword :";
        getline(cin, password);
        cout << "\nPassword Confirmation :";
        getline(cin, cpassword);

	        if (password != cpassword) 
			{
	            cout << "\nPassword and confirmation password do not match. Please try again.\n";
	        }
    	} while (password != cpassword);
    	
    	

        ofstream reg("user records.txt", ios::app);
        reg << username << ' ' << email << ' ' << address << ' ' << contactNumber << ' ' << password << ' ' << cpassword << endl;
        system("cls");
        cout << "\nRegistration Successful\n";
    }

    void forgetPassword() 
	{
        string input;
        cout << "Enter your username or email to recover password: ";
        getline(cin, input);

        ifstream userFile("user records.txt");

        while (userFile >> username >> email >> address >> contactNumber >> password >> cpassword) 
		{
            if (username == input || email == input) 
			{
                cout << "Your password is : " << password << endl;
                return;
            }
        }

        cout << "User not found. Please check your username or email." << endl;
        return;
    }
};

class Admin 
{
private:
    string adminId;
    string adminPass;

public:
    Admin() : adminId("admin"), adminPass("admin123") {}

    void adminlogin() 
	{
        int count = 0;
        string inputId, inputPass;

        system("cls");
        cout << "Administrator Login" << endl;
        cout << "Admin ID: ";
        getline(cin, inputId);
        cout << "Password: ";
        getline(cin, inputPass);

        if (inputId == adminId && inputPass == adminPass) 
		{
            count = 1;
            system("cls");
        }

        if (count == 1) 
		{
            cout << "\n<ADMIN LOGIN SUCCESSFUL>\n";
            cout << "Welcome, Admin " << endl;
            return;
        } 
		else 
		{
            cout << "\nADMIN LOGIN ERROR\nPlease check your Admin ID and Password\n";
            return;
        }
    }
};

int main() 
{
    int choice;
    User user;
    Admin admin;

    do 
	{
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

        cin.ignore();  

        switch (choice) 
		{
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
                cout << "Invalid Choice! Please select again\n" << endl;
        }
    } while (choice != 5);

    return 0;
}
