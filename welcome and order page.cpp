#include<iostream>
#include<string>
using namespace std; 

class Food
{
	private:
	string title;
	float price;
	
	public:
	void displayMenu()
	{
		cout<<"---------------------------------------------------"<<endl;
		cout<<"\tRestaurant Fusion Fare Delight"<<endl;
		cout<<"---------------------------------------------------"<<endl;
		cout<<"Food/Beverage"<<endl;
		cout<<"1) Nasi Lemak with Fried Chicken  RM8.50"<<endl;
		cout<<"2) Chicken Satay (10stick)  RM10.00"<<endl;
		cout<<"3) Curry Mee  RM7.00"<<endl;
		cout<<"4) Kampung Fried Rice  RM7.50"<<endl;
		cout<<"5) Mee Soup  RM6.00"<<endl;
		cout<<"6) Asam Laksa  RM8.00"<<endl;
		cout<<"7) Prawn Mee  RM6.50"<<endl;
		cout<<"8) Sambal Fried Rice  RM7.00"<<endl; 
		cout<<"9) Teh (hot)  RM2.00"<<endl;
		cout<<"10) Teh (cold)  RM2.50"<<endl;
		cout<<"11) Coffee (hot)  RM2.30"<<endl;
		cout<<"12) Coffee (cold)  RM2.80"<<endl;
		cout<<"13) Milo (hot)  RM3.00"<<endl;
		cout<<"14) Milo (cold)  RM3.50"<<endl;
		cout<<"15) Lemon Tea (hot)  RM3.00"<<endl;
		cout<<"16) Lemon Tea (cold)  RM3.50"<<endl;
	}
	
	void getOrder()
	{
		int choice;
		cout<<"Please select your item : ";
		cin>>choice;
		
		if (choice == 1)
		{
			title = "Nasi Lemak with Fried Chicken";
			price = 8.50;
		}
		else if (choice == 2)
		{
			title = "Chicken Satay (10stick)";
			price = 10.00;
		}
		else if (choice == 3)
		{
			title = "Curry Mee";
			price = 7.00;
		}
		else if (choice == 4)
		{
			title = "Kampung Fried Rice";
			price = 7.50;
		}
		else if (choice == 5)
		{
			title = "Mee Soup";
			price = 6.00;
		}
		else if (choice == 6)
		{
			title = "Asam Laksa";
			price = 8.00;
		}
		else if (choice == 7)
		{
			title = "Prawn Mee";
			price = 6.50; 
		}
		else if (choice == 8)
		{
			title = "Sambal Fried Rice";
			price = 7.00;
		}
		else if (choice == 9)
		{
			title = "Teh (hot)";
			price = 2.00;
		}
		else if (choice == 10)
		{
			title = "Teh (cold)";
			price = 2.50;
		}
		else if (choice == 11)
		{
			title = "Coffee (hot)";
			price = 2.30;
		}
		else if (choice == 12)
		{
			title = "Coffee (cold)";
			price = 2.80;
		}
		else if (choice == 13)
		{
			title = "Milo (hot)";
			price = 3.00;
		}
		else if (choice == 14)
		{
			title = "Milo (cold)";
			price = 3.50;
		}
		else if (choice == 15)
		{
			title = "Lemon Tea (hot)";
			price = 3.00;
		}
		else if (choice == 16)
		{
			title = "Lemon Tea (cold)";
			price = 3.50;
		}
		else
		{
			title = "No title";
			price = 0.00;
		}
	}
	
	double getPrice()
	{
		return price;
	}
	
	string getTitle()
	{
		return title;
	}
};

class Drink
{
	private:
		string Menu_title;
		double payment;
		
	Food F;
		
	public:
		void showOrder()
		{
			F.displayMenu();
			F.getOrder();
			payment = F.getPrice();
			Menu_title = F.getTitle();
		}
		
		void details()
		{
			cout<<Menu_title<<", add successfully"<<endl;
			cout<<"Price : RM"<<payment<<endl;
		}
};

int main()
{
	//welcome page
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"\tWelcome to Restaurant Fusion Fare Delight!"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"OPENING HOURS"<<endl;
	cout<<"Monday - Friday, 7am until 5pm"<<endl;
	cout<<"Saturday - Sunday, 8am until 3pm\n"<<endl;
	
	Drink D;
	D.showOrder();
	D.details();
	
	return 0;
}
