#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ================= CONSTANT =================
const char FILE_NAME[] = "vehicle.dat";

// ================= CLASS =================
class Vehicle {
private:
    int id;
    char name[50];
    float rentPerDay;
    int available;

public:
    Vehicle() {
        id = 0;
        rentPerDay = 0;
        available = 0;
        strcpy(name, "Unknown");
    }

    Vehicle(int i, const char n[], float r, int a) {
        id = i;
        rentPerDay = r;
        available = a;
        strcpy(name, n);
    }

    // Input with validation
    void input() {
        cout << "\nEnter Vehicle ID: ";
        cin >> id;

        cout << "Enter Vehicle Name: ";
        cin.ignore();
        cin.getline(name, 50);

        do {
            cout << "Enter Rent per Day (>0): ";
            cin >> rentPerDay;
        } while (rentPerDay <= 0);

        do {
            cout << "Enter Available Units (>=0): ";
            cin >> available;
        } while (available < 0);
    }

    // Display
    void display() const {
        cout << "\n==============================";
        cout << "\n ID       : " << id;
        cout << "\n Name     : " << name;
        cout << "\n Rent/Day : " << rentPerDay;
        cout << "\n Available: " << available;
        cout << "\n==============================\n";
    }

    inline int getID() const {
        return id;
    }

    char* getName() {
        return name;
    }

    int getAvailable() {
        return available;
    }

    float getRent() {
        return rentPerDay;
    }

    void update() {
        cout << "\nUpdating Vehicle ID: " << id;

        do {
            cout << "\nEnter New Rent (>0): ";
            cin >> rentPerDay;
        } while (rentPerDay <= 0);

        do {
            cout << "Enter New Availability (>=0): ";
            cin >> available;
        } while (available < 0);
    }

    void rentVehicle(int qty) {
        available -= qty;
    }

    // Friend function
    friend void showVehicle(Vehicle v);
};

// Friend function
void showVehicle(Vehicle v) {
    cout << "\n[Vehicle Details]";
    v.display();
}

// ================= INHERITANCE =================
class LuxuryVehicle : public Vehicle {
private:
    float extraCharge;

public:
    void setExtraCharge(float e) {
        extraCharge = e;
    }

    void showLuxuryInfo() {
        cout << "\nLuxury Extra Charge: " << extraCharge << endl;
    }
};

// ================= FUNCTIONS =================

// Add Vehicle
void addVehicle() {
    Vehicle v;
    ofstream file(FILE_NAME, ios::binary | ios::app);

    if (!file) {
        cout << "\nError opening file!\n";
        return;
    }

    v.input();
    file.write((char*)&v, sizeof(v));

    file.close();
    cout << "\nVehicle Added Successfully!\n";
}

// Display All
void displayAll() {
    Vehicle v;
    ifstream file(FILE_NAME, ios::binary);

    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\n===== VEHICLE LIST =====\n";

    while (file.read((char*)&v, sizeof(v))) {
        v.display();
    }

    file.close();
}

// Function Overloading - Search by ID
void searchVehicle(int searchID) {
    Vehicle v;
    bool found = false;

    ifstream file(FILE_NAME, ios::binary);

    while (file.read((char*)&v, sizeof(v))) {
        if (v.getID() == searchID) {
            showVehicle(v);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nVehicle Not Found!\n";

    file.close();
}

// Function Overloading - Search by Name
void searchVehicle(char searchName[]) {
    Vehicle v;
    bool found = false;

    ifstream file(FILE_NAME, ios::binary);

    while (file.read((char*)&v, sizeof(v))) {
        if (strcmp(v.getName(), searchName) == 0) {
            showVehicle(v);
            found = true;
        }
    }

    if (!found)
        cout << "\nVehicle Not Found!\n";

    file.close();
}

// Rent Vehicle (NEW FEATURE ??)
void rentVehicle() {
    int id, days, qty;
    Vehicle v;
    bool found = false;

    fstream file(FILE_NAME, ios::binary | ios::in | ios::out);

    cout << "\nEnter Vehicle ID to Rent: ";
    cin >> id;

    while (file.read((char*)&v, sizeof(v))) {
        if (v.getID() == id) {
            cout << "\nVehicle Found:";
            v.display();

            cout << "Enter Quantity: ";
            cin >> qty;

            if (qty > v.getAvailable()) {
                cout << "\nNot enough vehicles available!\n";
                return;
            }

            cout << "Enter Number of Days: ";
            cin >> days;

            float total = qty * days * v.getRent();

            v.rentVehicle(qty);

            file.seekp(-sizeof(v), ios::cur);
            file.write((char*)&v, sizeof(v));

            cout << "\n====== BILL ======";
            cout << "\nVehicle: " << v.getName();
            cout << "\nDays: " << days;
            cout << "\nQuantity: " << qty;
            cout << "\nTotal Rent: " << total;
            cout << "\n==================\n";

            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nVehicle Not Found!\n";

    file.close();
}

// Update Vehicle
void updateVehicle() {
    int searchID;
    Vehicle v;
    bool found = false;

    fstream file(FILE_NAME, ios::binary | ios::in | ios::out);

    cout << "\nEnter Vehicle ID to update: ";
    cin >> searchID;

    while (file.read((char*)&v, sizeof(v))) {
        if (v.getID() == searchID) {
            v.display();
            v.update();

            file.seekp(-sizeof(v), ios::cur);
            file.write((char*)&v, sizeof(v));

            cout << "\nUpdated Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nVehicle Not Found!\n";

    file.close();
}

// Delete Vehicle
void deleteVehicle() {
    int searchID;
    Vehicle v;

    ifstream inFile(FILE_NAME, ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    cout << "\nEnter Vehicle ID to delete: ";
    cin >> searchID;

    bool found = false;

    while (inFile.read((char*)&v, sizeof(v))) {
        if (v.getID() != searchID)
            outFile.write((char*)&v, sizeof(v));
        else
            found = true;
    }

    inFile.close();
    outFile.close();

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        cout << "\nDeleted Successfully!\n";
    else
        cout << "\nVehicle Not Found!\n";
}

// ================= MENU =================
void menu() {
    int choice;

    do {
        cout << "\n========= VEHICLE RENTAL SYSTEM =========";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Display All Vehicles";
        cout << "\n3. Search by ID";
        cout << "\n4. Search by Name";
        cout << "\n5. Rent Vehicle";
        cout << "\n6. Update Vehicle";
        cout << "\n7. Delete Vehicle";
        cout << "\n8. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addVehicle(); break;
        case 2: displayAll(); break;
        case 3: {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            searchVehicle(id);
            break;
        }
        case 4: {
            char name[50];
            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(name, 50);
            searchVehicle(name);
            break;
        }
        case 5: rentVehicle(); break;
        case 6: updateVehicle(); break;
        case 7: deleteVehicle(); break;
        case 8: cout << "\nExiting...\n"; break;
        default: cout << "\nInvalid Choice!\n";
        }

    } while (choice != 8);
}

// ================= MAIN =================
int main() {
    menu();
    return 0;
}
