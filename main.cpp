#include <iostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

 class Restaurant
{
	private:
	float Nasilemak, Currymee, Friedrice, Meesoup, Asamlaksa, Prawnmee, Teh_hot, Teh_cold, Coffee_hot, Coffee_cold, Milo_hot, Milo_cold, Lemontea_hot, Lemontea_cold;
	float price;
	ifstream menuFile;
	
	public:
	void readFile()
	{
		ifstream menuFile("Menu.txt");
        if (!menuFile)
        {
        	cout<<"File does not exist";
			exit(1);
		}

    	menuFile.close();
	}
	void displayMenu(int nasi, int curry, int fried, int mee, int asam, int prawn, int teh_h, int teh_c, int coffee_h, int coffee_c, int milo_h, int milo_c, int lemon_h, int lemon_c)
	{
		Nasilemak = static_cast<float>(nasi);
		Currymee = static_cast<float>(curry);
 		Friedrice = static_cast<float>(fried);
 		Meesoup = static_cast<float>(mee);
 		Asamlaksa = static_cast<float>(asam);
 		Prawnmee = static_cast<float>(prawn);
 		Teh_hot = static_cast<float>(teh_h);
		Teh_cold = static_cast<float>(teh_c);
		Coffee_hot = static_cast<float>(coffee_h);
		Coffee_cold = static_cast<float>(coffee_c);
		Milo_hot = static_cast<float>(milo_h);
		Milo_cold = static_cast<float>(milo_c);
		Lemontea_hot = static_cast<float>(lemon_h);
		Lemontea_cold = static_cast<float>(lemon_c);
		
		getOrder();
	}
	
	void getOrder()
	{
		cout<<"Total bowls :"<< Nasilemak + Currymee + Friedrice + Meesoup + Asamlaksa + Prawnmee<<endl;
		cout<<"Total cups :"<< Teh_hot + Teh_cold + Coffee_hot + Coffee_cold + Milo_hot + Milo_cold + Lemontea_hot + Lemontea_cold<<endl;
	}
		
	void getPrice()
	{
		price = Nasilemak * 8.50 + Currymee * 7.00 + Friedrice * 7.00 + Meesoup * 6.00 + Asamlaksa * 8.00 + Prawnmee * 6.50 + Teh_hot * 2.00 + Teh_cold * 2.50 + Coffee_hot * 2.30 + Coffee_cold * 2.80 + Milo_hot * 3.00 + Milo_cold * 3.50 + Lemontea_hot * 3.00 + Lemontea_cold * 3.50;
		cout<<"Thank you. Your order price is RM"<<price<<endl;
	}
	
};


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
                cout << "Please select again\n" << endl;
        }
    } while (choice != 5);
  
  Restaurant R;
	//welcome page
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"\tWelcome to Restaurant Fusion Fare Delight!"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"OPENING HOURS"<<endl;
	cout<<"Monday - Friday, 7am until 5pm"<<endl;
	cout<<"Saturday - Sunday, 8am until 3pm\n"<<endl;
	
	R.readFile();
	char choice;
	
	do
	{
		cout<<"---------------------------------------------------"<<endl;
		cout<<"\tRestaurant Fusion Fare Delight"<<endl;
		cout<<"---------------------------------------------------"<<endl;
		cout<<"Looking for a food/drinks? [Y/N]\n";
		cin>>choice;
		
		if (choice == 'Y' || choice == 'y')
		{
			int nasi, curry, fried, mee, asam, prawn, teh_h, teh_c, coffee_h, coffee_c, milo_h, milo_c, lemon_h, lemon_c;
			cout<<"Food/Beverages"<<endl;
			cout<<"1) Nasi Lemak with Fried Chicken (bowl) : ";
			cin>>nasi;
			cout<<"2) Curry Mee (bowl) : ";
			cin>>curry;
			cout<<"3) Fried Rice (bowl) : ";
			cin>>fried;
			cout<<"4) Mee Soup (bowl) : ";
			cin>>mee;
			cout<<"5) Asam Laksa (bowl) : ";
			cin>>asam;
			cout<<"6) Prawn Mee (bowl) : ";
			cin>>prawn;
			cout<<"7) Teh (hot) (cup) : ";
			cin>>teh_h;
			cout<<"8) Teh (cold) (cup) : ";
			cin>>teh_c;
			cout<<"9) Coffee (hot) (cup) : ";
			cin>>coffee_h;
			cout<<"10) Coffee (cold) (cup) : ";
			cin>>coffee_c;
			cout<<"11) Milo (hot) (cup) : ";
			cin>>milo_h;
			cout<<"12) Milo (cold) (cup) : ";
			cin>>milo_c;
			cout<<"13) Lemon Tea (hot) (cup) : ";
			cin>>lemon_h;
			cout<<"14) Lemon Tea (cold) (cup) : ";
			cin>>lemon_c;
			
			R.displayMenu(nasi, curry, fried, mee, asam, prawn, teh_h, teh_c, coffee_h, coffee_c, milo_h, milo_c, lemon_h, lemon_c);
			R.getPrice();
			
			cout << "Would you like to make another order? [Y/N]\n";
            cin >> choice;
		}
	} while (choice == 'Y' || choice == 'y');


    return 0;
}
