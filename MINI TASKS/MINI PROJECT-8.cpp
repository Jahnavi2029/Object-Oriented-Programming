#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
using namespace std;

// ================= TEMPLATE CLASS =================
template <typename T>
class DataProcessor {
private:
    vector<T> data;

public:
    // Add Data
    void addData(T value) {
        if (value < 0)
            throw invalid_argument("Negative values not allowed!");
        data.push_back(value);
    }

    // Display Data
    void displayData() const {
        if (data.empty()) {
            cout << "No data available.\n";
            return;
        }

        cout << "Data: ";
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Compute Sum
    T computeSum() const {
        if (data.empty())
            throw runtime_error("No data!");

        T sum = 0;
        for (size_t i = 0; i < data.size(); i++) {
            sum += data[i];
        }
        return sum;
    }

    // Compute Average
    double computeAverage() const {
        if (data.empty())
            throw runtime_error("No data!");

        return (double)computeSum() / data.size();
    }

    // Sort Data
    void sortData() {
        sort(data.begin(), data.end());
        cout << "Data sorted successfully!\n";
    }

    // Search Data
    void searchData(T key) const {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == key) {
                cout << "Element found at position: " << i << endl;
                return;
            }
        }
        cout << "Element not found.\n";
    }

    // Save to File
    void saveToFile() const {
        ofstream fout("data.txt");
        if (!fout) {
            throw runtime_error("File error!");
        }

        for (size_t i = 0; i < data.size(); i++) {
            fout << data[i] << " ";
        }

        fout.close();
        cout << "Data saved to file!\n";
    }

    // Load from File
    void loadFromFile() {
        ifstream fin("data.txt");
        if (!fin) {
            throw runtime_error("File not found!");
        }

        data.clear();
        T value;

        while (fin >> value) {
            data.push_back(value);
        }

        fin.close();
        cout << "Data loaded from file!\n";
    }

    // Clear Data
    void clearData() {
        data.clear();
        cout << "All data cleared!\n";
    }
};

// ================= MAIN FUNCTION =================
int main() {
    DataProcessor<int> processor;

    int choice, value;

    do {
        cout << "\n=============================\n";
        cout << " SAFE DATA PROCESSOR MENU\n";
        cout << "=============================\n";
        cout << "1. Add Data\n";
        cout << "2. Display Data\n";
        cout << "3. Compute Sum\n";
        cout << "4. Compute Average\n";
        cout << "5. Sort Data\n";
        cout << "6. Search Data\n";
        cout << "7. Save to File\n";
        cout << "8. Load from File\n";
        cout << "9. Clear Data\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        try {
            switch (choice) {

                case 1:
                    cout << "Enter value: ";
                    while (!(cin >> value)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input! Enter number: ";
                    }
                    processor.addData(value);
                    cout << "Data added!\n";
                    break;

                case 2:
                    processor.displayData();
                    break;

                case 3:
                    cout << "Sum = " << processor.computeSum() << endl;
                    break;

                case 4:
                    cout << "Average = " << processor.computeAverage() << endl;
                    break;

                case 5:
                    processor.sortData();
                    break;

                case 6:
                    cout << "Enter value to search: ";
                    cin >> value;
                    processor.searchData(value);
                    break;

                case 7:
                    processor.saveToFile();
                    break;

                case 8:
                    processor.loadFromFile();
                    break;

                case 9:
                    processor.clearData();
                    break;

                case 10:
                    cout << "Exiting program...\n";
                    break;

                default:
                    throw invalid_argument("Invalid choice!");
            }
        }
        catch (invalid_argument &e) {
            cout << "Invalid Argument: " << e.what() << endl;
        }
        catch (runtime_error &e) {
            cout << "Runtime Error: " << e.what() << endl;
        }
        catch (...) {
            cout << "Unknown error occurred!\n";
        }

    } while (choice != 10);

    return 0;
}
