#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    string name, surname;

    // Get customer details
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your surname: ";
    cin >> surname;

    // Menu items and prices
    const vector<string> menuItems = { "Coffee", "Sandwich", "Salad", "Juice", "Muffin", "Pizza", "Soup", "Burger" };
    const vector<double> menuPrices = { 15.00, 30.00, 25.00, 10.00, 20.00, 35.00, 18.00, 40.00 };

    // Display menu
    cout << "\nMenu Prices:\n";
    for (size_t i = 0; i < menuItems.size(); ++i) {
        cout << i + 1 << ". " << menuItems[i] << " - R" << fixed << setprecision(2) << menuPrices[i] << endl;
    }

    // Get order details
    int items;
    cout << "\nHow many items would you like to order (1-8)? ";
    cin >> items;

    if (items < 1 || items > 8) {
        cout << "Invalid number of items. Exiting program." << endl;
        return 1;
    }

    vector<int> selectedItems(items);
    double totalBill = 0.0;

    for (int i = 0; i < items; ++i) {
        int choice;
        cout << "Select item " << i + 1 << " (1-8): ";
        cin >> choice;

        if (choice < 1 || choice > 8) {
            cout << "Invalid choice. Exiting program." << endl;
            return 1;
        }

        selectedItems[i] = choice - 1; // Store zero-based index
        totalBill += menuPrices[choice - 1];
    }

    // Apply discount if applicable
    const double DISCOUNT_RATE = 0.10; // 10% discount
    const double DISCOUNT_THRESHOLD = 100.00; // Discount applies if bill > R100
    double discount = 0.0;

    if (totalBill > DISCOUNT_THRESHOLD) {
        discount = totalBill * DISCOUNT_RATE;
        totalBill -= discount;
    }

    // Display final bill
    cout << "\nFinal Bill:\n";
    for (int i : selectedItems) {
        cout << menuItems[i] << " - R" << fixed << setprecision(2) << menuPrices[i] << endl;
    }
    if (discount > 0) {
        cout << "Discount Applied: -R" << fixed << setprecision(2) << discount << endl;
    }
    cout << "Total Bill: R" << fixed << setprecision(2) << totalBill << endl;

    // Write to file
    ofstream CafeteriaBill("CafeteriaBill.txt");
    CafeteriaBill << "Name: " << name << endl;
    CafeteriaBill << "Surname: " << surname << endl;
    CafeteriaBill << "Final Bill:\n";
    for (int i : selectedItems) {
        CafeteriaBill << menuItems[i] << " - R" << fixed << setprecision(2) << menuPrices[i] << endl;
    }
    if (discount > 0) {
        CafeteriaBill << "Discount Applied: -R" << fixed << setprecision(2) << discount << endl;
    }
    CafeteriaBill << "Total Bill: R" << fixed << setprecision(2) << totalBill << endl;
    CafeteriaBill.close();

    cout << "\nThe bill has been written to CafeteriaBill.txt." << endl;

    return 0;
}
