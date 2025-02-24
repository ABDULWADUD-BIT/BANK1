#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


enum AccountStatus {
    active,
    inactive,
    blocked,
    closed
    
};

enum user_selected_options{
    account_create = 1,
    sign_up = 2,
    account_balance,
    account_withdraw,
    account_deposit,
    account_transfer,
    account_close,
    account_block,

}

struct BankUser {
    char my_name[100];
    char fa_name[100];
    char ma_name[100];
    long long id;
    long long pass;
};

void reg() {
    int ui_account_create, sign_up;
    cout << "Account create enter 1: ";
    cin >> ui_account_create;
    cout << "Account sign up enter 2: ";
    cin >> sign_up;
    cin.ignore(); // Clear newline from buffer

    if (ui_account_create == account_create) {
        BankUser s1;

        cout << "Enter name: ";
        cin.getline(s1.my_name, sizeof(s1.my_name));
        cout << "FATHER NAME: ";
        cin.getline(s1.fa_name, sizeof(s1.fa_name));
        cout << "MOTHER NAME: ";
        cin.getline(s1.ma_name, sizeof(s1.ma_name));
        cout << "Enter ID: ";
        cin >> s1.id;
        cout << "Enter PASSWORD: ";
        cin >> s1.pass;
        cin.ignore(); // Clear buffer

        cout << "Name: " << s1.my_name << endl;
        cout << "FATHER Name: " << s1.fa_name << endl;
        cout << "MOTHER Name: " << s1.ma_name << endl;
        cout << "ID: " << s1.id << endl;
        cout << "Password: " << s1.pass << endl;

        ofstream outFile("jibon.txt", ios::app);
        outFile << s1.my_name << " " << s1.fa_name << " " << s1.ma_name << " " << s1.id << " " << s1.pass << "\n";
        outFile.close();
    }
    else if (sign_up == 2) {
        char name[100];
        long long password;
        BankUser s1;

        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> password;

        ifstream inFile("jibon.txt");
        bool found = false;
        while (inFile >> s1.my_name >> s1.fa_name >> s1.ma_name >> s1.id >> s1.pass) {
            if (strcmp(s1.my_name, name) == 0 && s1.pass == password) {
                cout << "Name: " << s1.my_name << endl;
                cout << "Father's Name: " << s1.fa_name << endl;
                cout << "Mother's Name: " << s1.ma_name << endl;
                cout << "ID: " << s1.id << endl;
                cout << "Password: " << s1.pass << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "User not found or incorrect credentials." << endl;
        }
        inFile.close();
    }
}

int main() {
    reg();
    return 0;
}
