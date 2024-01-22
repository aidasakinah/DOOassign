#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
const int MAX_ITEM = 100;

class Cart
{
private:
    static const int MAX_CART_ITEMS = 100;
    string cartItems[MAX_CART_ITEMS]; // Maintain an array of items
    float cartPrices[MAX_CART_ITEMS]; // Maintain an array of item prices
    int itemCount;                    // Track the number of items in the cart
    char payoption;
    // for panyment
    string cardHolderName;
    string cardNumber;
    string expirationDate;
    string cvv;

public:
    Cart() : itemCount(0) {}
    void setItemDetails(string itemName, float itemPrice)
    {
        if (itemCount < MAX_CART_ITEMS)
        {
            cartItems[itemCount] = itemName;
            cartPrices[itemCount] = itemPrice;
            itemCount++;
        }
        else
        {
            cout << "Cart is full. Cannot add more items." << endl;
        }
    }

    void displayCart()
    {

        float total = 0.0;
        for (int i = 0; i < itemCount; ++i)
        {
            cout << cartItems[i] << " RM" << cartPrices[i] << endl;
            total += cartPrices[i];
        }
        cout << "Total Price: RM" << total << endl;
        cout << "Do you want to proceed to your payment? [Y/N]:";
        cin >> payoption;
        if (payoption == 'Y' || payoption == 'y')
        {

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
        else if (payoption == 'N' || payoption == 'n')
        {
            system("cls");
            return;
        }
    }

    // Accessor methods
    int getItemCount() const
    {
        return itemCount;
    }

    string getCartItem(int index) const
    {
        return cartItems[index];
    }

    float getCartPrice(int index) const
    {
        return cartPrices[index];
    }
};

class Restaurant
{
private:
    float price, itemPrice;
    string itemName;
    Cart C;

public:
    void readFile(Cart &cart)
    {
        string menuFileName = "Menu.txt";
        ifstream menuFile(menuFileName.c_str());
        if (!menuFile)
        {
            cout << "File does not exist";
            exit(1);
        }

        cout << "Food and Beverange" << endl;

        string a[MAX_ITEM];
        float b[MAX_ITEM];
        int itemNumber = 0;

        while (menuFile >> a[itemNumber] >> b[itemNumber])
        {
            itemNumber++;
        }

        for (int i = 0; i < itemNumber; i++)
        {
            cout << i + 1 << ") " << setw(30) << left << a[i] << " RM" << fixed << setprecision(2) << b[i] << endl;
        }

        int choice;
        price = 0;

        while (true)
        {

            cout << "\nSelect a food item by entering its number: ";
            cin >> choice;
            if (choice >= 1 && choice <= itemNumber)
            {
                cout << "You selected: " << choice << ") " << a[choice - 1] << " RM" << b[choice - 1] << endl;
                cart.setItemDetails(a[choice - 1], b[choice - 1]);
                price += b[choice - 1];
                cout << "Current order total: RM" << price << endl;

                char foodchoice;
                cout << "Would you like to make another order? [Y/N]\n";
                cin >> foodchoice;
                C.setItemDetails(a[choice - 1], b[choice - 1]);
                if (!(foodchoice == 'Y' || foodchoice == 'y'))
                {
                    cout << "Your current order price is RM" << price << endl;

                    C.displayCart();
                    break;
                }
            }
            else
            {
                cout << "Invalid choice\n";
            }
        } // end of while loop
        menuFile.close();
    } // end of function

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
        // check if the name already exist
        ifstream checkName("user records.txt");
        string existingUsername;
        do
        {
            if (existingUsername == username)
            {
                cout << "\nUsername already exists. Please try again and choose a different name.\n";
                return;
            }
        } while (checkName >> existingUsername >> email >> address >> contactNumber >> password >> cpassword);

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
        } while (checkEmail >> username >> existingEmail >> address >> contactNumber >> password >> cpassword);

        setAddress(address);
        cout << "\nAddress :";
        getline(cin, address);
        cout << "\nContact Number :";
        getline(cin, contactNumber);

        // ensure the pwd is match
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
    void setUsername(const string &name)
    {
        username = name;
    }

    string getUsername() const
    {
        return username;
    }

    void setAddress(const string &addr)
    {
        address = addr;
    }

    string getAddress() const
    {
        return address;
    }
};

class Receipt
{
public:
    Receipt() {}

    void generateReceipt(const User &user, const Cart &cart)
    {
        system("cls");
        cout << "========== RECEIPT ==========" << endl;
        cout << "Name: " << user.getUsername() << endl;
        cout << "Address: " << user.getAddress() << endl;

        float total = 0.0;
        cout << "Selected Items:" << endl;
        for (int i = 0; i < cart.getItemCount(); ++i)
        {
            cout << cart.getCartItem(i) << " RM" << cart.getCartPrice(i) << endl;
            total += cart.getCartPrice(i);
        }
        cout << "Total Price: RM" << total << endl;
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

        // if (inputId == adminId && inputPass == adminPass)
        // {
        //     count = 1;
        //     //system("cls");
        // }

        // if (count == 1)
        // {
        //     cout << "\n<ADMIN LOGIN SUCCESSFUL>\n";
        //     cout << "Welcome, Admin " << endl;
        // }
        // else
        // {
        //     cout << "\nADMIN LOGIN ERROR\nPlease check your Admin ID and Password\n";
        //     return;
        // }

        if (inputId == adminId && inputPass == adminPass)
        {
            cout << "\n<ADMIN LOGIN SUCCESSFUL>\n";
            cout << "Welcome, Admin " << endl;
        }
        else
        {
            // cout << "Incorrect login details. Please try again.\n";

            do
            {
                system("cls");
                cout << "Incorrect login details. Please try again.\n"; // if the user enter wrong password, it will loop again
                cout << "Administrator Login" << endl;
                cout << "Admin ID: ";
                getline(cin, inputId);
                cout << "Password: ";
                getline(cin, inputPass);

            } while (inputId != adminId || inputPass != adminPass);
        }
    }
};

int main()
{
    int choice;
    string selectedItem;
    float selectedPrice;
    User user;
    Admin admin;
    Receipt Rp;
    string username;
    string address;

    //    Adminpage ap;
    Restaurant R;
    Cart C;

    do
    {
        cout << "\n";
        cout << "---------------------------------------------------------" << endl;
        cout << "\tWelcome to Restaurant Fusion Fare Delight!" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "1. USER LOGIN" << endl;
        cout << "2. USER REGISTER" << endl;
        cout << "3. FORGET PASSWORD" << endl;
        cout << "4. Menu" << endl;
        cout << "5. My Cart" << endl;
        cout << "6. ADMINISTRATOR LOGIN" << endl;
        cout << "7. EXIT" << endl;
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
            system("cls");
            R.readFile(C);
            break;
        case 5:
            system("cls");
            cout << "================Items in your cart================" << endl;
            C.displayCart();
            username = user.getUsername();
            address = user.getAddress();
            Rp.generateReceipt(user, C);
            break;
        case 6:
            admin.adminlogin();
            //                ap.manageMenu();
            break;
        case 7:
            cout << "Thank you for visiting Restaurant Fusion Fare Delights." << endl;
            break;
        default:
            system("cls");
            cout << "Please select again\n"
                 << endl;
        }
    } while (choice != 7);

    return 0;
}
