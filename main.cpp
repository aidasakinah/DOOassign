#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
//2 additional libraries
#include <conio.h> // for getch() function for password
#include <vector> // for vector (found in manageMenu() function)
using namespace std;
const int MAX_ITEM=100;

class PaymentMethod {
protected:
    string cardHolderName;
    string cardNumber;
    string expirationDate;
    string cvv;

public:
    // Function to validate the card number
    bool isValidCardNumber(const string& cardNumber) {
        // Check if the card number has 16 digits
        return cardNumber.length() == 16 && all_of(cardNumber.begin(), cardNumber.end(), ::isdigit);
    }

    // Function to validate the expiration date
    bool isValidExpirationDate(const string& expirationDate) {
        // Check if the expiration date has 5 characters and follows the MM/YY format
        return expirationDate.length() == 5 && isdigit(expirationDate[0]) && isdigit(expirationDate[1]) &&
            expirationDate[2] == '/' && isdigit(expirationDate[3]) && isdigit(expirationDate[4]);
    }

    // Function to validate the CVV
    bool isValidCVV(const string& cvv) {
        // Check if the CVV has 3 digits
        return cvv.length() == 3 && all_of(cvv.begin(), cvv.end(), ::isdigit);
    }
};

class Cart: public PaymentMethod{
	private:
	    static const int MAX_CART_ITEMS = 100;
    	string cartItems[MAX_CART_ITEMS]; // Maintain an array of items
    	float cartPrices[MAX_CART_ITEMS]; // Maintain an array of item prices
    	int cartQuantities[MAX_CART_ITEMS];
		int itemCount; // Track the number of items in the cart
	    char payoption;
	    
        
	public:
		Cart() : itemCount(0) {}
		void setItemDetails(string itemName,float itemPrice, int quantity){
			if (itemCount < MAX_CART_ITEMS) {
	            cartItems[itemCount] = itemName;
	            cartPrices[itemCount] = itemPrice;
	            cartQuantities[itemCount] = quantity;
	            itemCount++;
        } 
		else{
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }
	

		int getCartQuantity(int index) const {
        if (index >= 0 && index < itemCount) {
            return cartQuantities[index];
        } else {
            cout << "Invalid index. Quantity cannot be retrieved." << endl;
            return 0;
        }
    }
    
    
	    void displayCart() {
	        
	        float total = 0.0;
	        for (int i = 0; i < itemCount; ++i) {
	            cout << cartItems[i] << " x" << cartQuantities[i] << " RM" << cartPrices[i] << endl;
	            total += (cartPrices[i] * cartQuantities[i]) ;
	        }
	        cout << "Total Price: RM" << total << endl;
	        cout<<"Do you want to proceed to your payment? [Y/N]:";
	        cin>>payoption;
	        
	        if(payoption=='Y'||payoption=='y'){
			
				fflush(stdin);
		        cout << "\n===================Enter payment details===================" << endl;
		        cout << "Cardholder Name: ";
		        getline(cin, cardHolderName);
		        fflush(stdin);
		        do {
			        cout << "Card Number (16 digits): ";
			        getline(cin, cardNumber);
			        fflush(stdin);
			    } while (!isValidCardNumber(cardNumber));

			    // Read and validate Expiration Date
			    do {
			        cout << "Expiration Date (MM/YY): ";
			        getline(cin, expirationDate);
			        fflush(stdin);
			    } while (!isValidExpirationDate(expirationDate));

			    // Read and validate CVV
			    do {
			        cout << "CVV (3 digits): ";
			        getline(cin, cvv);
			        fflush(stdin);
			    } while (!isValidCVV(cvv));
		
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
		
		void updateSalesCount() {
        ofstream salesReport("sales_report.txt", ios::app);
        if (!salesReport) {
            cout << "Error opening sales report file." << endl;
            return;
        }

        salesReport << "================ Sales Report ================" << endl;
        for (int i = 0; i < itemCount; ++i) {
            salesReport << cartItems[i] << ": " << cartPrices[i] << " RM" << endl;
        }

        salesReport.close();
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
		
			int choice, quantity;
			price=0;
			
			while(true){
			
	        cout << "\nSelect a food item by entering its number: ";
	        cin >> choice;
	        
		        if (choice >= 1 && choice <= itemNumber){
			        cout << "You selected: " << choice << ") " << a[choice-1] << " RM" << b[choice-1] << endl;
			        
			        cout << "\nEnter the quantity: ";
					cin >> quantity;
					
								        
                    cart.setItemDetails(a[choice - 1], b[choice - 1],quantity);
                    price+=b[choice-1] * quantity;
                    cout << "Current order total: RM" << price << endl;
				
			        char foodchoice;
			        cout << "Would you like to make another order? [Y/N] : ";
			        cin >> foodchoice;
					C.setItemDetails(a[choice - 1], b[choice - 1],quantity);
			        if (!(foodchoice == 'Y' || foodchoice == 'y')){
			            cout << "Your current order price is RM" << price << endl;
			            cout<<"\n\nPlease go to [my cart] for payment.\n"<<endl;
			            system("pause");
			            system("cls");
			            return;
			            
			        }
			        
	    		}
	    		else{
	    			cout<<"Invalid choice\n";
				}
			}//end of while loop
   			menuFile.close();
		}//end of function
  
  		void setItemDetails(string itemName, float itemPrice, int quantity)
  		{
            this->itemName = itemName;
            this->itemPrice = itemPrice * quantity;
        }
    		
			
		void updateSalesCount(const Cart& cart) {
        ifstream menuFile("Menu.txt");
        if (!menuFile) {
            cout << "Error opening menu file." << endl;
            return;
        }

        ofstream salesCountFile("sales_count.txt", ios::out | ios::trunc);
        if (!salesCountFile) {
            cout << "Error opening sales count file." << endl;
            return;
        }

        string itemName;
        float itemPrice;
        int salesCount;

        while (menuFile >> itemName >> itemPrice) {
            salesCount = 0;
            for (int i = 0; i < cart.getItemCount(); ++i) {
                if (itemName == cart.getCartItem(i)) {
                    salesCount++;
                }
            }
            salesCountFile << itemName << " " << salesCount << endl;
        }

        menuFile.close();
        salesCountFile.close();
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
    string inputUsername;
    string inputPassword;
    string existingUsername;
	string existingEmail;
	bool loggedIn;
	bool isValueExists(const string& filename, const string& valueToCheck);
public:
	User() : loggedIn(false) {}
    void login() {
    system("cls");
    cout << "User Login" << endl;
    cout << "USERNAME or EMAIL :";
    getline(cin, inputUsername);
    cout << "PASSWORD :";
    getline(cin, inputPassword);

    ifstream input("user records.txt");
    string line;
    bool loginSuccess = false;
    while (getline(input, line)) {
        stringstream ss(line);
        ss >> username >> email;
        ss.ignore(1, '"'); // Ignore the space before the address opening quote
        getline(ss, address, '"'); // Read the address up to the closing quote
        ss >> contactNumber >> password >> cpassword;
        if ((username == inputUsername || email == inputUsername) && password == inputPassword) {
            loginSuccess = true;
            system("cls");
            setUsername(username);
            setAddress(address);
            break;
        }
    }
    input.close();

    if (loginSuccess) {
        cout << "\nHello " << getUsername() << "\n<LOGIN SUCCESSFUL>\nThanks for logging in Restaurant Fusion Fare Delights\n";  
		loggedIn = true;  
    } else {
        cout << "\nLOGIN ERROR\nPlease check again your username or email and password\n";  
	}
}
	void logout()
	{
		loggedIn = false;
	}
    void registration() {
        system("cls");
        cout << "User Register" << endl;
        cout << "\nName : ";
        getline(cin, username);

        // Check if the name already exists
        ifstream checkName("user records.txt");
        string line;
        while(getline(checkName, line)) {
        	stringstream ss(line);
        	ss >> existingUsername;
        	if(existingUsername == username){
        		cout << "\nUsername already exists. Please try again and choose a different name.\n";
				return;
			}
		}
		checkName.close();
		
		cout << "\nEmail :";
		getline(cin, email);
		
		ifstream checkEmail("user records.txt");
		bool emailExists = false;
		while(getline(checkEmail, line)) {
			stringstream ss(line);
			ss >> existingUsername >> existingEmail;
			if(existingEmail == email){
				emailExists = true;
				break;
			}
		}
		checkEmail.close();
		
		if(emailExists)
		{
			cout << "\nEmail already exists. Please try again and chooes a different email.\n";
			return;
		}
		
		cout << "\nAddress:";
		getline(cin, address);
        cout << "\nContact Number : ";
        getline(cin, contactNumber);
        
        do{
        	cout << "\nPassword :";
        	getline(cin, password);
        	cout << "\nConfirm Password :";
        	getline(cin, cpassword);
        	
        	if(password != cpassword){
        		cout << "\nPasswords do not match. Please try again."<<endl;
			}
		}while(password !=cpassword);

		ofstream reg("user records.txt", ios::app);
		reg << username << ' ' <<email << ' ' << '"' << address << '"' << ' ' << contactNumber << ' ' << password << ' ' << cpassword << '\n';
		reg.close();
		system("cls");
		cout << "\nRegistration Successfully\n";
		
	}
	
	
    void forgetPassword() {
    string input;
    cout << "Enter your username or email to recover password: ";
    getline(cin, input);

    ifstream userFile("user records.txt");
    while (userFile >> ws >> username >> ws >> email >> ws) {
        // Read the entire line for address
        getline(userFile, address);

        userFile >> ws >> contactNumber >> ws >> password >> ws >> cpassword;

        if (username == input || email == input) {
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
    
    bool isLoggedIn() const {
    	return loggedIn;
	}

	void changeName() {
        cout << "Enter your new name: ";
        string newName;
        getline(cin, newName);
        setUsername(newName);

        updateUserInfoFile();  // Update the change in the user records file
        cout << "Name updated successfully!\n";
    }

    void changeAddress() {
        cout << "Enter your new address: ";
        string newAddress;
        getline(cin, newAddress);
        setAddress(newAddress);

        updateUserInfoFile();  // Update the change in the user records file
        cout << "Address updated successfully!\n";
    }

    void updateUserInfoFile() {
        ifstream inputFile("user records.txt");
        ofstream tempFile("temp.txt");

        while (inputFile >> username >> email >> address >> contactNumber >> password >> cpassword) {
            if (username == getUsername()) {
                tempFile << getUsername() << ' ' << email << ' ' << getAddress() << ' ' << contactNumber << ' ' << password << ' ' << cpassword << endl;
            } else {
                tempFile << username << ' ' << email << ' ' << address << ' ' << contactNumber << ' ' << password << ' ' << cpassword << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        remove("user records.txt");
        rename("temp.txt", "user records.txt");
    }
    
    
    // Make Cart a friend of User to access User's private members
    friend class Cart;
};

class Receipt{
public:
    Receipt() {}
		void generateReceipt(const User& user, const Cart& cart)
		{
		system("cls");
        cout << "========== RECEIPT ==========" << endl;
        cout << "Name: " << user.getUsername() << endl;
        cout << "Address: " << user.getAddress() << endl;

        float total = 0.0;
        cout << "\nSelected Items:" << endl;
        for (int i = 0; i < cart.getItemCount(); ++i) {
            float itemTotal = cart.getCartPrice(i) * cart.getCartQuantity(i); 
			cout << cart.getCartItem(i) << " x" << cart.getCartQuantity(i) << " =RM" << itemTotal << endl;
            total += itemTotal;
        }                                
        cout << "\nTotal Price: RM" << total << endl;
        cout << "=============================" << endl;
    }
};

                                                   
class Admin
{
private:
    string adminId;
    string adminPass;

public:
    Admin() : adminId("admin"), adminPass("admin123") {}
    friend class welcomePage;

    void adminlogin()
    {
        int count = 0;
        string inputId, inputPass;

        system("cls");
        cout << "---------------------------------------------------------" << endl;
        cout << "\t>>>>>>>>>> Administrator Login <<<<<<<<<<" << endl;
        cout << "---------------------------------------------------------" << endl;
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
                cout << "\n---------------------------------------------------------" << endl;
                cout << "\t>>>>>>>>>> Administrator Login <<<<<<<<<<" << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "\nAdmin ID: ";
                getline(cin, inputId);
                cout << "Password: ";
                getline(cin, inputPass);

            } while (inputId != adminId || inputPass != adminPass); // end of do-while loop
        }//end of if else  

    }//end of void adminlogin
};

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
        char searchAgain;

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
            do
            {
                cin.ignore(); // Clear the newline character from the buffer
                cout << "Enter the name of the item to search: ";
                getline(cin, itemName);
                searchItem(itemName);

                cout << "Do you want to search again? [Y/N]: ";
                cin >> searchAgain;

            } while (toupper(searchAgain) == 'Y');//end of do while
        } // end of else if pick == 3
        else
        {
            cout << "Invalid choice. Please try again.\n";
        } // end of else
    }     // end of manageMenu

    bool searchItem(const string &itemName)
    {
        string line;

        ifstream menuFile("Menu.txt");
        if (!menuFile.is_open())
        {
            cout << "Error opening Menu.txt for reading.\n";
            return false;
        }

        while (getline(menuFile, line))
        {
            if (line.find(itemName) != string::npos) //string::npos is returned if string is not found
            {
                cout << "Item found in the menu : "<< line << endl;
                menuFile.close();
                return true;
            }
        }

        cout << "Item not found in the menu.\n";

        //close files
        menuFile.close();
        return false;
    }//end of searchItem
    
}; // end of class Adminpage

void editProfile(User& user)
{
    int editChoice;

    do
    {
        cout << "\n1. Edit Name" << endl;
        cout << "2. Edit Address" << endl;
        cout << "3. Back to Menu" << endl;
        cout << "\nEnter your choice: ";
        cin >> editChoice;
        cout << endl;

        cin.ignore();

        switch (editChoice)
        {
            case 1:
                user.changeName();
                break;
            case 2:
                user.changeAddress();
                break;
            case 3:
                // Back to the menu
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please select again.\n" << endl;
        }
    } while (editChoice != 3);
}

void showMenuOptions(User& user, Admin& admin, Adminpage& ap, Restaurant& R, Cart& C)
{
    int choice;
	Receipt receipt;
    do
    {
        cout << "1. Menu" << endl;
        cout << "2. My Cart" << endl;
        cout << "3. Edit Profile" << endl;
        cout << "4. Logout" << endl;
        cout << "5. EXIT" << endl;
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
                receipt.generateReceipt(user, C);
                break;
            case 3:
                editProfile(user);
                break;
            case 4:
                // Logout Logic
                user.logout();
                break;
            case 5:
                cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please select again.\n" << endl;
        }
    } while (choice != 5&&user.isLoggedIn());
}


void welcomePage(User& user, Admin& admin, Adminpage& ap, Restaurant& R, Cart& C)
{
    int choice;
    do
    {
        if (!user.isLoggedIn())
        {
            cout << "\n---------------------------------------------------------" << endl;
            cout << "\tWelcome to Restaurant Fusion Fare Delight!" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "1. USER LOGIN" << endl;
            cout << "2. USER REGISTER" << endl;
            cout << "3. FORGET PASSWORD" << endl;
            cout << "4. ADMINISTRATOR LOGIN" << endl;
            cout << "5. EXIT" << endl;
            cout << "\nEnter your choice :";
            cin >> choice;
            cin.ignore(); // To consume the '\n' character after cin >>

            switch (choice)
            {
                case 1:
                    user.login();
                    if(user.isLoggedIn()){
                        showMenuOptions(user, admin, ap, R, C);
                    }
                    break;
                case 2:
                    user.registration();
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
                    cout << "\nPlease select a valid option\n" << endl;
            }
        }
        else
        {
            showMenuOptions(user, admin, ap, R, C);
        }

    } while (choice != 5);
}


int main() 
{
    int choice;
    string selectedItem;
	float selectedPrice;
    User user;
    Admin admin;
    Adminpage ap;
    Receipt Rp;
	Restaurant R;
	Cart C;
	
    bool userAuthenticated = false;;
    
    welcomePage(user, admin, ap, R, C);

    return 0;
}
