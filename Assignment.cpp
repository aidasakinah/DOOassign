#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <string.h>


using namespace std;
const int MAX_ITEM=100;

class Restaurant
{
	private:
		float price;
	
	public:
		void readFile()
		{
			ifstream menuFile("Menu.txt");
	        if (!menuFile)
	        {
	        	cout<<"File does not exist";
				exit(1);
			}
		
			cout<<"Food and Beverange"<<endl;
			
			string a[MAX_ITEM];
			float b[MAX_ITEM];
			int itemNumber =0;
			
			while(menuFile >> a[itemNumber] >> b[itemNumber]){
				itemNumber++;
			}
				
			for(int i=0;i<itemNumber;i++){
				cout << i+1 << ") " <<setw(30)<<left<< a[i]<< " RM" <<fixed<<setprecision(2)<< b[i] << endl;
			}
		
			int choice;
			price=0;
			
			while(true){
			
	        cout << "\nSelect a food item by entering its number: ";
	        cin >> choice;
		        if (choice >= 1 && choice <= itemNumber){
			        cout << "You selected: " << choice << ") " << a[choice-1] << " RM" << b[choice-1] << endl;
			        price += b[choice-1];
			        cout << "Current order total: RM" << price << endl;
			
			        char foodchoice;
			        cout << "Would you like to make another order? [Y/N]\n";
			        cin >> foodchoice;
	
			        if (!(foodchoice == 'Y' || foodchoice == 'y')){
			            cout << "Thank you. Your order price is RM" << price << endl;
			            break;
			            
			        }
			        
	    		}
	    		else{
	    			cout<<"Invalid choice\n";
				}
			}//end of while loop
   			menuFile.close();
		}//end of function
    			
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
        } 
		else 
		{
            cout << "\nLOGIN ERROR\nPlease check again your username or email and password\n";
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
	Restaurant R;
	
    do 
	{
        cout << "\n";
      	cout<<"---------------------------------------------------------"<<endl;
		cout<<"\tWelcome to Restaurant Fusion Fare Delight!"<<endl;
		cout<<"---------------------------------------------------------"<<endl;
        cout << "1. USER LOGIN" << endl;
        cout << "2. USER REGISTER" << endl;
        cout << "3. FORGET PASSWORD" << endl;
        cout << "4. Menu"<<endl;
        cout << "5. ADMINISTRATOR LOGIN" << endl;
        cout << "6. EXIT" << endl;
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
				R.readFile();
				break;
            case 5:
                admin.adminlogin();
                break;
            case 6:
                cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
                break;
            default:
                system("cls");
                cout << "Please select again\n" << endl;
        }
    } while (choice != 6);
  
	


    return 0;
}
