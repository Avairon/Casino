#include <iostream>
#include <stdio.h>
#include <fstream>
#include <locale.h>
#include "Game.h"


#define CRT_SECURE_NO_WARNINGS

//D:\

using namespace std;

//fstream Database;

ifstream Database;

class member {
public:
    string login, password;
    member() {

    }
    member(string Login, string Password) {
        login = Login;
        password = Password;
    }
};

class balance {
public:
    int bal;
    string login;
    balance() {

    }
    balance(int Bal, string Login) {
        bal = Bal;
        login = Login;
    }
};

void write(string input, string fileName) {
    ofstream Database1;
    Database1.open(fileName + ".txt", ios::app);
    if (Database1.is_open()) {
        Database1 << input << "\n";
    }
    Database1.close();
}

string read(int line, string fileName) {
    string out;
    Database.open(fileName + ".txt");

    for (int i = 0; i < line; i++) {
        Database >> out;
    }

    Database.close();

    return out;
}

bool inAuth = false;

int main()
{
    string log, pass;

    int choose;

    while (true) {
        if (inAuth == false) {
            choose = 0;
            cout << "Choose action: 1 - autorisation; 2 - registration; 3 - exit;\n";
            cin >> choose;
            if (choose == 3) return 0;
            member* user = new member;

            int i = 1;
            switch (choose) {

            case(1):
                cout << "Enter login\n";
                cin >> user->login;

                cout << "Searching...\n";


                while (read(i, "Users") != "") {

                    log = read(i, "Users");
                    pass = read(i + 1, "Users");

                    if (user->login == log) {
                        cout << "Enter password\n";
                        cin >> user->password;
                        if (user->password == pass) {
                            cout << "Hello, dear user!\n";
                            inAuth = true;
                            break;
                        }
                        else {
                            cout << "Incorrect password, please try again\n";
                            break;
                        }
                    }
                    if (log == "") {
                        cout << "Account not alive!";

                        break;
                    }

                    i += 2;
                }
                break;
            case(2):
                cout << "Enter login\n";
                cin >> user->login;

                i = 1;
                

                
                while (1) {
                    ifstream Database;
                    Database.open("Users.txt");

                    if (!Database.eof()) break;
                    Database.close();
                    log = read(i, "Users");

                    if (user->login == log) {
                        cout << "This login is used!\n";
                        i = -1;
                        break;
                    }

                    i += 2;
                }

                if (i != -1) {
                    cout << "Enter password\n";
                    cin >> user->password;
                    cout << "Creating...\n";

                    write(user->login, "Users");
                    write(user->password, "Users");

                    cout << "You account was created!\n";

                    break;
                }
                else {
                    break;
                }
            }
        } 

        else {     //сама программа
            int choose;
            cout << "Choose action: 1 - Blackjack, 2 - Wheelspin, 3 - YouBalance, 4 - Logout\n";
            cin >> choose;
            switch (choose)
            {
            case(1):
                blackJack();
                break;
            case(2):
                wheelSpin();
                break;
            case(3):
                cout << "Choose action: 1 - check, 2 - totup, 3 - back\n";
                cin >> choose; //манипуляции с балансом

                break;
            case(4):
                inAuth = false;
                break;
            }
        }
    }
}