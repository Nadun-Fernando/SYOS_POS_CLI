#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "StockManagement.h"
#include <string>
#include <fstream>
#include <iterator>
#include "UserInterface.h"
#include "colors.h"
#include "windows.h"

using namespace std;

inline bool file_exists (const std::string& name);
string toLowerCase(string str);
void sleep(float seconds);
void CashierLogin();
string toUpperCase(string str);

int main() {

    ////load the login screen
    CashierLogin();

    ////Create a StockManagement object named stk
    StockManagement stk;
    ////Create a UserInterface object named stk
    UserInterface usr;

    ////check whether the data files are already exits in the program location
    if (file_exists("store.txt") && file_exists("shelf.txt") && file_exists("batch.txt")) {
        ////load the data to vectors from files
        stk.getStoreDataFromFile();
        stk.getBatchDataFromFile();
        stk.getShelfDataFromFile();
    } else {
        ////calling the hard coded stock to load into vectors
        stk.CurrentStock();
        stk.batchDetails();
        stk.currentShelf();
    }

    ////Displays the MainMenu
    usr.displayUI(stk);

    ////update the shelf
    stk.updateShelf();

    ////store the data to files
    stk.saveStoreItems();
    stk.saveBatchItems();
    stk.saveShelfItems();

    return 0;
}

/**Log In Validation for Cashier**/
void CashierLogin() {
    string cashierNameInput, cashierPasswordInput;
    string usernameInput, passwordInput;
    bool userValidated = false;
    const int NumOfUsers = 5;

    const string usernames[NumOfUsers] = {"nadun" , "hiranya" , "denura" , "keshan" , "danidu"};
    const string passwords[NumOfUsers] = {"nadun@16$", "hh@18$" , "denura@399$" , "kesh@995$" , "danidu@490$"};

    cout << "\n\n\n\n\n\t\t\t============SYNEX OUTLET STORE LOGIN============\n";
    cout << "\n\t\t\t\tUSERNAME \t:\t";
    cin >> usernameInput;
    cout << "\n";

    cout << "\n\t\t\t\tPASSWORD \t:\t";
    cin >> passwordInput;
    cout << "\n";
    cout << "\n\n\t\t\t================================================\n";




    cashierNameInput = toLowerCase(usernameInput);
    cashierPasswordInput = passwordInput;


        for (int i = 0; i < NumOfUsers; i++) {
            if (cashierNameInput == usernames[i] && cashierPasswordInput == passwords[i]) {
                userValidated = true;
                break;
            }
        }
        if (!userValidated) {
            cout<<"Username or Password is Incorrect. Please Try Again...";
            sleep(1.0);
            system("cls");
            cin.clear();
            cin.sync();
            CashierLogin();
        } else if (userValidated) {
            system("cls");
            cout<< dye::green_on_black("\n\n\t\t================================================================================\n");
            cout<<dye::yellow_on_black("\n\t\t\t\tWELCOME TO THE SYNEX OUTLET STORE\t" + toUpperCase(usernameInput) + "\n");
            cout<<dye::green_on_black("\n\t\t================================================================================\n");

            cout << "\n\n\n\t\t\t\tLOADING --> \t";
            for (int j = 0; j < 10; ++j) {
                sleep(0.8);
                cout << "#";
            }

        }



}

////function to check whether the given file is available
inline bool file_exists (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

////convert the string to lowercase
string toLowerCase(string str) {
    int str_len = str.length();
    string final_str = "";

    for(int i=0; i<str_len; i++) {
        char character = str[i];
        if(character>=65 && character<=92) {
            final_str += (character+32);
        } else {
            final_str += character;
        }
    }
    return final_str;
}

////convert the string to uppercase
string toUpperCase(string str) {
    int str_len = str.length();
    string final_str = "";

    for(int i=0; i<str_len; i++) {
        char character = str[i];
        if(character>=97 && character<=122) {
            final_str += (character-32);
        } else {
            final_str += character;
        }
    }
    return final_str;
}

////function to add a delay
void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}





