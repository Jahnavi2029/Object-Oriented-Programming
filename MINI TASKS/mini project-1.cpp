#include <iostream>
#include <string>
using namespace std;

int main()
{
    string customerName, address, membership, paymentMethod;
    string itemName[50];

    int day, month, year, hour, minute;
    string phone;

    int n;
    int choice;
    int quantity[50];

    float price[50];
    float itemTotal[50];

    float onionKg, tomatoKg, potatoKg;

    float onionPrice = 40;
    float tomatoPrice = 30;
    float potatoPrice = 25;

    float subtotal = 0;
    float discount = 0;
    float tax;
    float grandTotal;

    cout << "===== SMART GROCERY BILLING SYSTEM =====\n\n";

    cout << "Enter Date (DD MM YYYY): ";
    cin >> day >> month >> year;

    cout << "Enter Time (HH MM): ";
    cin >> hour >> minute;

    cout << "Enter Customer Name: ";
    getline(cin >> ws, customerName);

    cout << "Enter Phone Number: ";
    cin >> phone;

    if(phone.length() > 10)
    {
        cout << "Error: Phone number cannot be more than 10 digits\n";
        return 0;
    }

    cout << "Enter Address: ";
    getline(cin >> ws, address);

    cout << "\nMembership Types: platinum / gold / silver / none\n";
    cout << "Enter Membership: ";
    getline(cin >> ws, membership);

    cout << "\n------- MENU -------\n";
    cout << "1. Juice      - Rs.50\n";
    cout << "2. Chocolate  - Rs.30\n";
    cout << "3. Noodles    - Rs.40\n";
    cout << "4. Chips      - Rs.20\n";
    cout << "--------------------\n";

    cout << "\nHow many packaged items do you want to buy? ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        cout << "Enter Quantity: ";
        cin >> quantity[i];

        if(choice == 1)
        {
            itemName[i] = "Juice";
            price[i] = 50;
        }
        else if(choice == 2)
        {
            itemName[i] = "Chocolate";
            price[i] = 30;
        }
        else if(choice == 3)
        {
            itemName[i] = "Noodles";
            price[i] = 40;
        }
        else if(choice == 4)
        {
            itemName[i] = "Chips";
            price[i] = 20;
        }
        else
        {
            cout << "Invalid choice\n";
            i--;
            continue;
        }

        itemTotal[i] = price[i] * quantity[i];
        subtotal = subtotal + itemTotal[i];
    }

    cout << "\nEnter Onion quantity (kg): ";
    cin >> onionKg;

    cout << "Enter Tomato quantity (kg): ";
    cin >> tomatoKg;

    cout << "Enter Potato quantity (kg): ";
    cin >> potatoKg;

    float onionTotal = onionKg * onionPrice;
    float tomatoTotal = tomatoKg * tomatoPrice;
    float potatoTotal = potatoKg * potatoPrice;

    subtotal = subtotal + onionTotal + tomatoTotal + potatoTotal;

    if(membership == "platinum")
        discount = subtotal * 0.15;
    else if(membership == "gold")
        discount = subtotal * 0.10;
    else if(membership == "silver")
        discount = subtotal * 0.05;
    else
        discount = 0;

    tax = subtotal * 0.18;
    grandTotal = subtotal + tax - discount;

    cout << "\nEnter Payment Method: ";
    getline(cin >> ws, paymentMethod);

    cout << "\n\n========== FINAL BILL ==========\n";

    cout << "Date : " << day << "/" << month << "/" << year << endl;
    cout << "Time : " << hour << ":" << minute << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Phone Number  : " << phone << endl;
    cout << "Address       : " << address << endl;
    cout << "Membership    : " << membership << endl;

    cout << "\n------ Packaged Items ------\n";
    for(int i = 0; i < n; i++)
    {
        cout << itemName[i] << " : Rs. " << itemTotal[i] << endl;
    }

    cout << "\n------ Vegetables ------\n";
    cout << "Onion  : Rs. " << onionTotal << endl;
    cout << "Tomato : Rs. " << tomatoTotal << endl;
    cout << "Potato : Rs. " << potatoTotal << endl;

    cout << "-----------------------------\n";
    cout << "Subtotal   : Rs. " << subtotal << endl;
    cout << "Discount   : Rs. " << discount << endl;
    cout << "Tax (18%)  : Rs. " << tax << endl;
    cout << "Grand Total: Rs. " << grandTotal << endl;

    cout << "Payment Method : " << paymentMethod << endl;

    cout << "==============================\n";
    cout << "Thank you for shopping with us!\n";

    return 0;
}
