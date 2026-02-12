#include <iostream> //input/output 
#include <string> // text data 
using namespace std;

int main() {
	string customerName, paymentMethod;
	int qty1, qty2, qty3;
	float price1, price2, price3;
	float total1, total2, total3;
	float subtotal, tax, grandtotal;
	
	int day, month, year;
	
	cout << "===== SMART BILLING SYSTEM =====\n\n";
	
	cout << "Enter date (DD MM YYYY): "; // display bill
	cin >> day >> month >> year; // user input
	
	cout << "Enter customer name: ";
	cin >> customerName;
	
	cout << "Enter price of item 1: ";
	cin >> price1;
	cout << " Enter quantity of item 1: ";
	cin >> qty1;
	
	cout << "\nEnter price of Item2: ";
	cin >> price2;
	cout << "Enter quantity of item 2: ";
	cin >> qty2;
	
	cout << "\nEnter price of Item3: ";
	cin >> price3;
		cout << "Enter quantity of Item 3: ";
		cin >> qty3;
		
		total1 = price1 * qty1;
		total2 = price2 * qty2;
		total3 = price3 * qty3;
		
		subtotal = total1 + total2 + total3;
		tax = subtotal * 0.18; // 18% tax (compute tax)
		grandtotal = subtotal + tax;
		
		cout << "\nEnter payment method (Cash/UPI/Card): ";
		cin >> paymentMethod;
		
		cout << "\n\n========== BILL ==========\n";
		cout << "Date          : " << day << "/" << month << "/" << year << endl;
		cout << "Customer Name : " << customerName << endl;
		cout << " Item 1 Total : Rs. " << total1 << endl;
		cout << " Item 2 Total : Rs. " << total2 << endl;
		cout << " Item 3 Total : Rs. " << total3 << endl;
		cout << "----------------------------\n";
		cout << "Subtotal       : Rs. " << subtotal << endl;
		cout << "Tax (18%)      : Rs. " << tax << endl;
		cout << "Grandtotal     : Rs. " <<grandtotal << endl;
		cout << "Payment Method : " << paymentMethod << endl;
		cout << "============================\n";
		
		cout << "\n Thank you for shopping with us!\n";
		
		return 0;
   }
