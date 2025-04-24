#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string name, surname;

	cout << "Please enter your name: ";
	cin >> name;
	cout << "Please enter your surname: ";


	cout << "How many items would you like to order(up to 8)?";
	int items;
	cin >> items;

	cout << "Menu Prices:" << endl;
	const double COFFEE_PRICE = 15.00;
	const double SANDWICH_PRICE = 30.00;
	const double SALAD_PRICE = 25.00;
	const double JUICE_PRICE = 10.00;
	const double MUFFIN_PRICE = 20.00;
	const double PIZZA_PRICE = 35.00;
	const double SOUP_PRICE = 18.00;
	const double BURGER_PRICE = 40.00;

	cout << "Coffee - R15.00" << endl;
	cout << "Sandwich - R30.00" << endl;
	cout << "Salad - R25.00" << endl;
	cout << "Juice - R10.00" << endl;
	cout << "Muffin - R20.00" << endl;
	cout << "Pizza - R35.00" << endl;
	cout << "Soup - R18.00" << endl;
	cout << "Burger - R40.00" << endl;

	cout << "Select item 1(1-8): " << endl;
	cin >> items;
	cout << "Select item 2(1-8): " << endl;
	cin >> items;
	cout << "Select item 3(1-8): " << endl;
	cin >> items;
	cout << "Select item 4(1-8): " << endl;
	cin >> items;

	cout << "Total Bill: R80.00" << endl;

	const double DISCOUNT_RATE = 15.00; //10% discount
	const double DISCOUNT_THRESHOLD = 100.00; //Discount applies only if bill is over R100

	if (items > 100) {
		cout << "No discount applied." << endl;
	}
	else if (items < 100) {
		cout << "No discount applied" << endl;
	}
	else {
		cout << "Final Bill: R80.00" << endl;
	}

	//Creating and opening a text file 

	ofstream CafeteriaBill("CafeteriaBill.txt");

	//Writing the customers name, surname and final total bill in the file

	CafeteriaBill << "Name: " << name << endl;
	CafeteriaBill << "Surname: " << surname << endl;
	CafeteriaBill << "Final Bill: R80.00" << endl;

	//Close the file
	CafeteriaBill.close();

	cout << "The bill has been written to CafeteriaBill.txt." << endl;

	return 0;
}