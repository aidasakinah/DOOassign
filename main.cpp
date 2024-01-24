#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

//2 additional libraries
#include <conio.h> // for getch() function for password
#include <vector> // for vector (found in manageMenu() function)

using namespace std;
const int MAX_ITEM=100;


class Cart{
	private:
	    static const int MAX_CART_ITEMS = 100;
    	string cartItems[MAX_CART_ITEMS]; // Maintain an array of items
    	float cartPrices[MAX_CART_ITEMS]; // Maintain an array of item prices
    	int itemCount; // Track the number of items in the cart
	    char payoption;
	    //for panyment
	    string cardHolderName;
        string cardNumber;
        string expirationDate;
        string cvv;
        
	public:
		Cart() : itemCount(0) {}
		void setItemDetails(string itemName,float itemPrice){
			if (itemCount < MAX_CART_ITEMS) {
	            cartItems[itemCount] = itemName;
	            cartPrices[itemCount] = itemPrice;
	            itemCount++;
        } 
		else{
            cout << "Cart is full. Cannot add more items." << endl;
        }
    	}

	    void displayCart() {
	        
	        float total = 0.0;
	        for (int i = 0; i < itemCount; ++i) {
	            cout << cartItems[i] << " RM" << cartPrices[i] << endl;
	            total += cartPrices[i];
	        }
	        cout << "Total Price: RM" << total << endl;
	        cout<<"Do you want to proceed to your payment? [Y/N]:";
	        cin>>payoption;
	        if(payoption=='Y'||payoption=='y'){
			
				fflush(stdin);
		        cout << "\n===================Enter payment details===================" << endl;
		        cout << "Cardholder Name: ";
		        getline(cin, cardHolderName);
		        cout << "Card Number: ";
		        getline(cin, cardNumber);
		        cout << "Expiration Date: ";
		        getline(cin, expirationDate);
		        cout << "CVV: ";
		        getline(cin, cvv);
		
		        // Process payment (you can implement your payment logic here)
		        cout << "\nProcessing payment..." << endl;
		        cout << "Payment successful. Thank you for your purchase!" << endl;

			}
	        else if(payoption=='N' || payoption=='n'){
	        	system("cls");
				return;
			}
	    }
	    
	    // Accessor methods
	    int getItemCount() const {
	        return itemCount;
	    }
	
	    string getCartItem(int index) const {
	        return cartItems[index];
	    }
	
	    float getCartPrice(int index) const {
	        return cartPrices[index];
	    }
		
	
};

class Restaurant
{
	private:
		float price,itemPrice;
		string itemName;
		Cart C;
	
	public:
		void readFile(Cart& cart)
		{
            string menuFileName = "Menu.txt";
            ifstream menuFile(menuFileName.c_str());
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
                    cart.setItemDetails(a[choice - 1], b[choice - 1]);
                    price+=b[choice-1];
                    cout << "Current order total: RM" << price << endl;
				
			        char foodchoice;
			        cout << "Would you like to make another order? [Y/N]\n";
			        cin >> foodchoice;
					C.setItemDetails(a[choice - 1], b[choice - 1]);
			        if (!(foodchoice == 'Y' || foodchoice == 'y')){
			            cout << "Your current order price is RM" << price << endl;
			            
			            C.displayCart();
			            break;
			            
			        }
			        
	    		}
	    		else{
	    			cout<<"Invalid choice\n";
				}
			}//end of while loop
   			menuFile.close();
		}//end of function
  
  		void setItemDetails(string itemName, float itemPrice)
  		{
            this->itemName = itemName;
            this->itemPrice = itemPrice;
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
			setUsername(username);
			setAddress(address);
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
        // Check if the name already exists
    ifstream checkName("user records.txt");
    string existingUsername;

    while (checkName >> existingUsername >> email >> address >> contactNumber >> password >> cpassword) 
	{
        if (existingUsername == username) 
		{
            cout << "\nUsername already exists. Please try again and choose a different name.\n";
            return;
        }
    }
    checkName.close();  // Close the file before reopening

    cout << "\nEmail :";
    getline(cin, email);

    // Check if the email already exists
    ifstream checkEmail("user records.txt");
    string existingEmail;

    while (checkEmail >> existingUsername >> existingEmail >> address >> contactNumber >> password >> cpassword) 
	{
        if (existingEmail == email) 
		{
            cout << "\nEmail already exists. Please try again and choose a different email.\n";
            return;
        }
    }
    checkEmail.close(); 
        
        setAddress(address);
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
    void setUsername(const string& name) {
        username = name;
    }

    string getUsername() const {
        return username;
    }

    void setAddress(const string& addr) {
        address = addr;
    }

    string getAddress() const {
        return address;
    }
    
};


class Receipt{
public:
    Receipt() {}

    void generateReceipt(const User& user, const Cart& cart) {
        system("cls");
        cout << "========== RECEIPT ==========" << endl;
        cout << "Name: " << user.getUsername() << endl;
        cout << "Address: " << user.getAddress() << endl;

        float total = 0.0;
        cout << "Selected Items:" << endl;
        for (int i = 0; i < cart.getItemCount(); ++i) {
            cout << cart.getCartItem(i) << " RM" << cart.getCartPrice(i) << endl;
            total += cart.getCartPrice(i);
        }
        cout << "Total Price: RM" << total << endl;
    }
};

class Admin 
{
private:
protected:
    string adminId;
    string adminPass;

public:
    Admin() : adminId("admin"), adminPass("admin123") {}

    void adminlogin()
    {
        int count = 0;
        string inputId, inputPass;

        system("cls");
        cout << " >>>>>>>>>> Administrator Login <<<<<<<<<<" << endl;
        cout << "Admin ID: ";
        getline(cin, inputId);
        cout << "Password: ";
        getline(cin, inputPass);

        if (inputId == adminId && inputPass == adminPass)
        {
            system("cls"); // clearing the screen
            cout << "<ADMIN LOGIN SUCCESSFUL>\n";
            cout << "Welcome, Admin " << endl;
        }
        else
        {
            do
            {
                system("cls");
                cout << "Incorrect login details. Please try again." << endl; // if the user enter wrong password, it will loop again
                cout << "Administrator Login" << endl;
                cout << "\n\nAdmin ID: ";
                getline(cin, inputId);
                cout << "Password: ";
                getline(cin, inputPass);

            } while (inputId != adminId || inputPass != adminPass); // end of do-while loop
        }// end of if-else
    }// end of adminlogin
}; //end of class Admin

// class Adminpage
// this class is for admin to manage the menu :D
class Adminpage : public Admin
{
private:
    int choice;

protected:
public:
    void displayAdmin()
    {
        cout << "\n\n >>>>>>>>>> Welcome to Admin Page <<<<<<<<<<" << endl;
        cout << "1. Manage Menu" << endl;
        cout << "2. Manage User" << endl;
        cout << "3. Manage Order" << endl;
        cout << "4. Exit" << endl;
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manageMenu();
            break;
        case 2:
            // manageUser();
            break;
        case 3:
            // manageOrder();
            break;
        case 4:
            cout << "Exiting, Returning to Main Menu" << endl;
            break;
        }
    } // end of displayAdmin

    void manageMenu()
    {

        string itemName;
        float itemPrice;
        int pick;

        system("cls"); // clearing the screen
        cout << "Enter [1] to add item to menu OR [2] to remove item from menu OR [3] to search for item from menu : ";
        cin >> pick;

        if (pick == 1)
        {
            // add items to menu
            cin.ignore(); // Clear the newline character from the buffer
            cout << "Enter the name of the new item : ";
            getline(cin, itemName);

            cout << "Enter the price of the new item : RM ";
            cin >> itemPrice;

            ofstream menuFile("Menu.txt", ios::app); // Open the file in append mode
            if (menuFile.is_open())
            {
                menuFile << itemName << " " << fixed << setprecision(2) << itemPrice << endl; // adds item into a new line
                cout << "Item added successfully.\n";
                menuFile.close();
            }
            else
            {
                cout << "Error opening Menu.txt for writing.\n";
            } // end of if else for add to Menu.txt
        }// end of if pick == 1
        else if (pick == 2)
        {
            cout << "Enter the name of the item to delete: ";
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, itemName);

            ifstream inFile("Menu.txt");
            ofstream outFile("temp.txt");

            string line;
            bool found = false;

            while (getline(inFile, line))
            {
                if (line.find(itemName) != string::npos)
                {
                    // Skip the line to delete the item
                    found = true;
                    continue;
                }
                outFile << line << endl;
            }

            inFile.close();
            outFile.close();

            if (found)
            {
                remove("Menu.txt");
                rename("temp.txt", "Menu.txt");
                cout << "Item deleted successfully.\n";
            }
            else
            {
                cout << "Item not found in the menu.\n";
                remove("temp.txt");
            }//end of if else if found
        }//end of else if pick == 2
        else if (pick == 3)
        {
            //this code is incomplete 
            ifstream menuFile("Menu.txt"); //this is to open the file
            string line; //this is to store each line of text
            vector<int> items; //vector to store search string found
            int lineNumber = 1; //line number counter

            while (getline(menuFile, line)) //this is to read the file line by line
            {
                if (line.find(itemName) != string::npos) //if search string is found
                {
                    items.push_back(lineNumber); //store the line number in the vector
                }
                lineNumber++; //increment line number
            }
        
        }//end of else if pick == 3
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }//end of else
    }// end of manageMenu
}; // end of class Adminpage

int main() 
{
    int choice;
    string selectedItem;
    float selectedPrice;
    User user;
    Admin admin;
    Adminpage ap;
    Restaurant R;
    Cart C;

    bool userAuthenticated = false;

    do 
    {
        cout << "\n";
        cout << "---------------------------------------------------------" << endl;
        cout << "\tWelcome to Restaurant Fusion Fare Delight!" << endl;
        cout << "---------------------------------------------------------" << endl;

        if (!userAuthenticated) 
        {
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
                	system("cls");
                    user.login();
                    userAuthenticated = true;
                    break;
                case 2:
                    user.registration();
                    userAuthenticated = true;
                    break;
                case 3:
                    user.forgetPassword();
                    break;
                case 4:
                    admin.adminlogin();
                    ap.displayAdmin();
                    break;
                case 5:
                    cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
                    break;
                default:
                    cout << "Please select again\n" << endl;
            }
        } 
        else 
        {
            cout << "1. Menu" << endl;
            cout << "2. My Cart" << endl;
            cout << "3. Logout" << endl;
            cout << "4. EXIT" << endl;
            cout << "\nEnter your choice :";
            cin >> choice;
            cout << endl;

            cin.ignore();

            switch (choice) 
            {
                case 1:
                    R.readFile(C);
                    break;
                case 2:
                    C.displayCart();
                    break;
                case 3:
                    // Logout Logic
                    userAuthenticated = false;
                    break;
                case 4:
                    cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
                    break;
                default:
                    system("cls");
                    cout << "Please select again\n" << endl;
            }
        }

    } while (choice != 4 && choice != 5);

    return 0;
}

