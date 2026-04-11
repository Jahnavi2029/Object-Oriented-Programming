#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class Encryptor
{
private:
    string text;
    int key;
    string history;

public:
    Encryptor(string t = "", int k = 3)
    {
        text = t;
        key = k;
        history = "";
    }

    void input()
    {
        cout << "\nEnter text: ";
        getline(cin, text);
    }

    void display()
    {
        cout << "\nCurrent Text: " << text << endl;
    }

    string encrypt(int key)
    {
        string result = text;

        for (int i = 0; i < result.length(); i++)
        {
            if (isalpha(result[i]))
            {
                char base = islower(result[i]) ? 'a' : 'A';
                result[i] = (result[i] - base + key) % 26 + base;
            }
        }

        history = result;
        return result;
    }

    string decrypt(int key)
    {
        string result = text;

        for (int i = 0; i < result.length(); i++)
        {
            if (isalpha(result[i]))
            {
                char base = islower(result[i]) ? 'a' : 'A';
                result[i] = (result[i] - base - key + 26) % 26 + base;
            }
        }

        return result;
    }

    string reverseEncrypt()
    {
        string result = text;

        for (int i = 0; i < result.length() / 2; i++)
        {
            swap(result[i], result[result.length() - i - 1]);
        }

        history = result;
        return result;
    }

    void statistics()
    {
        int vowels = 0, words = 0;

        for (int i = 0; i < text.length(); i++)
        {
            char ch = tolower(text[i]);

            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                vowels++;

            if ((i==0 || text[i-1]==' ') && text[i] != ' ')
                words++;
        }

        cout << "\nLength: " << text.length();
        cout << "\nWords: " << words;
        cout << "\nVowels: " << vowels << endl;
    }

    void showHistory()
    {
        cout << "\nLast Encrypted Text: " << history << endl;
    }
};

class Menu
{
public:
    void show()
    {
        cout << "\n========== FILE ENCRYPTOR ==========\n";
        cout << "1. Enter Text\n";
        cout << "2. Encrypt\n";
        cout << "3. Decrypt\n";
        cout << "4. Reverse\n";
        cout << "5. Display\n";
        cout << "6. Statistics\n";
        cout << "7. History\n";
        cout << "8. Exit\n";
        cout << "====================================\n";
        cout << "Enter choice: ";
    }
};

int main()
{
    Encryptor obj;
    Menu m;

    int choice, key;

    while (true)
    {
        m.show();
        cin >> choice;
        cin.ignore(1000, '\n');

        if (choice == 8)
        {
            cout << "\nExiting program...\n";
            break;
        }

        switch (choice)
        {
        case 1:
            obj.input();
            break;

        case 2:
            cout << "Enter key: ";
            cin >> key;
            cin.ignore(1000, '\n');
            cout << "Encrypted: " << obj.encrypt(key) << endl;
            break;

        case 3:
            cout << "Enter key: ";
            cin >> key;
            cin.ignore(1000, '\n');
            cout << "Decrypted: " << obj.decrypt(key) << endl;
            break;

        case 4:
            cout << "Reversed: " << obj.reverseEncrypt() << endl;
            break;

        case 5:
            obj.display();
            break;

        case 6:
            obj.statistics();
            break;

        case 7:
            obj.showHistory();
            break;

        default:
            cout << "Invalid choice!\n";
        }

        // ?? IMPORTANT (Prevents infinite feel)
        cout << "\nPress Enter to continue...";
        cin.get();
    }

    return 0;
}
