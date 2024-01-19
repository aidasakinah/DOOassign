#include<iostream>
#include<iomanip>
#include<fstream>
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

int main()
{
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
