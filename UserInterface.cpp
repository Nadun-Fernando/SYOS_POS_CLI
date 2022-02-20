//
// Created by Nadun N. T. Fernando on 5/30/2021.
//

#include <iostream>
#include "UserInterface.h"
#include "StockManagement.h"
#include <ctime>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

////Main Menu
void UserInterface::displayUI(StockManagement& stk) {
    char choice;

    do {
        system("cls");
        system("Color F0");  //change the color of the CLI (F - White | 0 - Black > Black on White)
        cout << "\n\t\t\tSYNEX OUTLET STORE\n";
        cout << "\n\t" << getDateString();
        cout << "\n\n\t************ Select the transaction ********\n";
        cout << "\n\t**             1.Purchase Items                    **" << endl;
        cout << "\t**             2.Display Items                     **" << endl;
        cout << "\t**             3.View Reports                      **" << endl;
        cout << "\t**             4.EXIT                              **" << endl;
        cout << "\n\t********************************************\n";
        cout << "\n\tEnter your choice-----> ";
        cin >> choice;
        cout << "\n\n";


        switch (choice) {

            case '1':
                createBill(stk);
                printBillNumber(billNum);
                break;

            case '2':
                displayItems(stk);
                break;

            case '3':
                displayReports(stk);
                choice = '0';
                break;

            case '4': choice = '0';
                break;
            default:
                cout << "\n\tInvalid Choice";
                break;

        }
        if (choice != '0')
        {
            cin.clear();
            cin.sync();
            cout << "\n\n\n\tDo you want another Transaction?\n\tPress 1 to continue. 0. EXIT----> ";
            cin >> choice;
        }
        system("cls");

    } while (choice != '0' && choice == '1');


}

////displays the items
void UserInterface::displayItems(StockManagement& stk) {

    cout << "\n\n";
    cout << "\n\t********************************************\n";
    cout << "\n\t\t\tPRODUCT DETAILS\n";
    cout << "\n\t********************************************\n";
    cout << "\n\n";

    for (int i = 0; i < stk.itemId.size(); ++i) {
        cout << "\t" << i+1 << ". " << "\t" << stk.itemId[i] << "\t" <<stk.itemName[i] << "\t\t\t" << stk.itemPrice[i] << "\n";
    }
}

////reports menu
void UserInterface::displayReports(StockManagement &stk) {
    char choice;

    do {
        system("cls");

        cout << "\n\n";
        cout << "\n\t********************************************\n";
        cout << "\n\t\t\tREPORTS\n";
        cout << "\n\t********************************************\n";
        cout << "\t\t" << "1. SALES Report" << "\n";
        cout << "\t\t" << "2. STOCK Report" << "\n";
        cout << "\t\t" << "3. SHELF Report" << "\n";
        cout << "\t\t" << "4. BILL Report" << "\n";
        cout << "\t\t" << "5. LOW STOCK Items" << "\n";
        cout << "\t\t" << "6. MAIN MENU" << "\n";
        cout << "\n\n";

        cout << "\n\tEnter your choice-----> ";
        cin >> choice;

        switch (choice) {
            case '1':
                salesReport(stk);
                break;
            case '2':
                stockReport(stk);
                break;

            case '3':
                reshelfReport(stk);
                break;

            case '4':
                billReport(stk);
                break;

            case '5':
                for (int i = 0; i < stk.itemId.size(); ++i) {
                    if (stk.itemQuantityInStock[i] < 50) {
                        reorder = true;
                        break;
                    }
                }
                if (reorder) {
                    reorderAlert(stk);
                    break;
                } else{
                    cout << "\n\n\t\t======================================================================";
                    cout << "\n\t\t\t\tALL ITEMS HAVE ENOUGH STOCK! NO NEED TO WORRY\n";
                    cout << "\t\t======================================================================\n";
                    break;
                }

            case '6':
                displayUI(stk);
                choice = '0';
                break;
        }

        if (choice != '0') {
            cout << "\n\n\n\tDo you want to view another report?\n\tPress 1 to continue. 0. MAIN MENU----> ";
            cin >> choice;

            if (choice == '0') {
                displayUI(stk);
            }
        }
        system("cls");

    } while (choice != '0' && choice == '1');



}

////Bill creation process
void UserInterface::createBill(StockManagement &stk) {
    bool updateNeeded = false;
    bool itemCorrect = false;

    for (int i = 0; i < stk.sh_quantity.size(); ++i) {
        if (stk.sh_quantity[i] < 10) {
            updateNeeded = true;
            break;
        }
    }

    if (updateNeeded) {
        stk.updateShelf();
    }

    userInputItemID.clear();
    userInputQuantity.clear();
    totalItemPrice.clear();
    total = 0;
    cash = 0;
    change = 0;

    ////load the BillNumber data
    if (file_exists("BillNumberData.dat")){
        billNum = getIntDataToVector("BillNumberData.dat");
    }


    if (billNum.empty()) {
        billNumber = 1;
        billNum.push_back(billNumber);
    } else {
        billNumber = billNum.back() + 1;
        billNum.push_back(billNumber);
    }

    string itemIDInput;
    int itemQuantityInput;

    cout << "\n\n";
    cout << "\n\t********************************************\n";
    cout << "\n\t\tBILL NUMBER : " <<"\t" << billNumber <<"\n";
    cout << "\n\tPlease Enter 'F' as Product ID when you are done";
    cout << "\n\t********************************************\n";
    cout << "\n\n";

    do {
      cout  << "\t" << "Product ID : \t";
      cin   >> itemIDInput;
      cout  << "\n";

        if (itemIDInput == "F" || itemIDInput == "f") {
            break;
        }

        do {
            for (int i = 0; i < stk.itemId.size(); ++i) {
                if (itemIDInput == stk.itemId[i]) {
                    itemCorrect = true;
                    break;
                }
            }


            if (!itemCorrect) {
                cin.clear();
                cout << "\tINVALID ITEM CODE!!! \n\tPLEASE ENTER A VALID ITEM CODE\n\n";
                cout << "\t" << "Product ID : \t";
                cin >> itemIDInput;
                cout << "\n";
            }
        } while (!itemCorrect);

      cout  << "\t" << "Quantity : \t";
      cin   >> itemQuantityInput;
      cout  << "\n";

        while(itemQuantityInput > 10){
            if (itemQuantityInput > 10) {
                cin.clear();
                cout << "\tMaximum Purchase Quantity Exceeded!!!... \n\t(Maximum Purchase Quantity : 10)\n\n";
                cout  << "\t" << "Quantity : \t";
                cin   >> itemQuantityInput;
                cout  << "\n";
            }
        }

      userInputItemID.push_back(itemIDInput);
      userInputQuantity.push_back(itemQuantityInput);

    } while (itemIDInput != "F");

    for (int i = 0; i < userInputItemID.size(); ++i) {
        for (int j = 0; j < stk.sh_itemCode.size(); ++j) {
            if (userInputItemID[i] == stk.sh_itemCode[j]) {
                totalItemPrice.push_back(userInputQuantity[i] * stk.itemPrice[j]);
                stk.reduceFromShelfStock(userInputItemID[i],userInputQuantity[i]); ////reduce the purchased item from shelf stock
                break;
            }
        }
    }

    for (int i = 0; i < totalItemPrice.size(); ++i) {
        total += totalItemPrice[i];
    }

    cout << "\t\t" << "TOTAL PRICE : " <<"\t" << total<<endl;

    do {
        cout << "\n\t\t" << "CASH AMOUNT : " << "\t";
        cin >> cash;

        if (cash > total) {
            change = cash - total;
        } else if (cash == total) {
            change = 0;
        } else {
            cout << "\n\t" << "Not enough to settle the Bill, Please enter a valid amount" << "\n";
        }
    } while (cash < total);

    cout << "\n\n\t\t" << "CHANGE : " << "\t" << change <<endl;

    cout << "\n\n\t\tPLEASE VISIT AGAIN. HAVE A GOOD DAY!";
    cout << "\n\t\tFor any Queries, Contact: 7202970566\n\n";
    cout << "----------------------------------------------------------------------------\n\n";

    ////store the created bill and the transaction happened in the system
    storeBill(total,cash,change,billNumber,stk);
    printBill(total,cash,change,billNumber,stk);
    storeTransactions(total,billNumber,stk);


}

////function to store all the bills in one file
void UserInterface::storeBill(double total, double cashTendered, double changeIssued, int billNum, StockManagement &stk) {
    ofstream fout;
    fout.open("BILLHISTORY_FILE.txt", ios::app);

    fout << "\n\n----------------------------------------------------------------------------\n";
    fout << "\n\n\t\t\t\tBILL No: " << billNum << "\n";
    fout << "\n\n\t\t\t\tSYNEX OUTLET STORE\n";
    fout << "----------------------------------------------------------------------------\n";
    fout << "\n\t\tDate: " << getDateString() << "\t\tTime: " << getTimeString();
    fout << "\n\n\t\t\t\tITEMS\n";
    fout << "----------------------------------------------------------------------------\n\n";
    int i = 1;
    //list<Product>::iterator itr;
    fout << "\nNo.\tITEM ID.\tName\t\t\tQuantity\t\tCost\n";
    int srno = 1;
    for (int j = 0; j < userInputItemID.size(); ++j) {
        for (int k = 0; k < stk.itemId.size(); ++k) {
            if (userInputItemID[j] == stk.sh_itemCode[k]) {
                fout <<"\n"<< srno << "\t" <<stk.sh_itemCode[k] << "\t" << stk.itemName[k] << "\t\t" << userInputQuantity[j] << "\t\t\t" << userInputQuantity[j] * stk.itemPrice[k] << endl;
            } else {
                continue;
            }

        }
        ++srno;
    }
    fout << "\n\n----------------------------------------------------------------------------";
    fout << "\n\t\tGRAND TOTAL\t\t\t\t\t" << total;
    fout << "\n\t\tCash\t\t\t\t\t\t" << cashTendered;
    fout << "\n\t\tChange\t\t\t\t\t\t" << changeIssued;

    fout << "\n\n\t\tPLEASE COME AGAIN. HAVE A GOOD DAY!";
    fout << "\n\t\tFor any Queries, Contact: 7202970566\n\n";
    fout << "----------------------------------------------------------------------------\n\n";
}

////store bill Numbers issued in a file
void UserInterface::printBillNumber(vector<int> billNumbers) {

    ofstream output_ID ("BillNumberData.dat");

    ostream_iterator<int> quantity_iterator(output_ID,"\n");
    copy(billNumbers.begin(),billNumbers.end(),quantity_iterator);
//    output_ID<<"\n";
}

////Save the bill to a file named as Bill_<billlserial>.txt
void UserInterface::printBill(double total, double cashTendered, double changeIssued, int billNum, StockManagement &stk) {
    ofstream fout;
    fout.open("BILL_" + to_string(billNum) + ".txt", ios::app);

    fout << "\n\n----------------------------------------------------------------------------\n";
    fout << "\n\n\t\t\t\tBILL No: " << billNum << "\n";
    fout << "\n\n\t\t\t\tSYNEX OUTLET STORE\n";
    fout << "----------------------------------------------------------------------------\n";
    fout << "\n\t\tDate: " << getDateString() << "\t\tTime: " << getTimeString();
    fout << "\n\n\t\t\t\tITEMS\n";
    fout << "----------------------------------------------------------------------------\n\n";
    int i = 1;
    //list<Product>::iterator itr;
    fout << "\nNo.\tITEM ID.\tName\t\t\tQuantity\t\tCost\n";
    int srno = 1;
    for (int j = 0; j < userInputItemID.size(); ++j) {
        for (int k = 0; k < stk.itemId.size(); ++k) {
            if (userInputItemID[j] == stk.sh_itemCode[k]) {
                fout <<"\n"<< srno << "\t" <<stk.sh_itemCode[k] << "\t" << stk.itemName[k] << "\t\t" << userInputQuantity[j] << "\t\t\t" << userInputQuantity[j] * stk.itemPrice[k] << endl;
            } else {
                continue;
            }

        }
        ++srno;
    }
    fout << "\n\n----------------------------------------------------------------------------";
    fout << "\n\t\tGRAND TOTAL\t\t\t\t\t" << total;
    fout << "\n\t\tCash\t\t\t\t\t\t" << cashTendered;
    fout << "\n\t\tChange\t\t\t\t\t\t" << changeIssued;

    fout << "\n\n\t\tPLEASE COME AGAIN. HAVE A GOOD DAY!";
    fout << "\n\t\tFor any Queries, Contact: 7202970566\n\n";
    fout << "----------------------------------------------------------------------------\n\n";
}

////store the transaction that has taken place in the system
void UserInterface::storeTransactions(double total, int billNum, StockManagement& stk) {
    if (file_exists("TRANSACTIONS.txt")) {
        ofstream fout;
        fout.open("TRANSACTIONS.txt", ios::app);

        fout << "\n\t\t\t" + to_string(billNum) + "\t\t\t" + to_string(total) + "\n";

        fout.close();
    } else {
        ofstream fout;
        fout.open("TRANSACTIONS.txt", ios::app);

        fout << "\n\n\t\t======================================================================";
        fout << "\n\t\t\t\tCUSTOMER TRANSACTIONS REPORT\n";
        fout << "\t\t======================================================================\n";

        fout << "\n\n\t\t\tBILL NUMBER\t\tTOTAL AMOUNT\n";
        fout << "\n\t\t\t" + to_string(billNum) + "\t\t\t" + to_string(total) + "\n";
        fout.close();
    }

}

/**-------------------------------------------------REPORTS-------------------------------------------------------------**/

////display and store the sales report
void UserInterface::salesReport(StockManagement& stk){
    ofstream salesFile;
    salesFile.open("SALES_REPORT.txt", std::ofstream::out | std::ofstream::trunc);

    vector<double> totalSales;
    double totalRevenue = 0;

    printSameTime(salesFile,"\n\n");
    printSameTime(salesFile,"\n\t\t\t********************************************\n");
    printSameTime(salesFile,"\n\t\t\t\t\tSALES REPORT\n");
    printSameTime(salesFile,"\n\t\t\tDate: " + getDateString() + "\tTime: " + getTimeString());
    printSameTime(salesFile,"\n\t\t\t********************************************\n");
    printSameTime(salesFile,"\n\n");

    printSameTime(salesFile,"\t\tITEM ID\t    ITEM NAME\t\tITEMS SOLD\tTOTAL PRICE\n");

    if (stk.itemQuantitySold.size() == stk.sh_itemCode.size()) {
        for (int i = 0; i < stk.itemQuantitySold.size(); ++i) {
            if (stk.itemQuantitySold[i] != 0) {
                printSameTime(salesFile,"\n\t\t" + stk.sh_itemCode[i] + "\t" + stk.itemName[i] + "\t\t" + to_string(stk.itemQuantitySold[i]) + "\t" + to_string(stk.itemQuantitySold[i] * stk.itemPrice[i]) + "\n");
                totalSales.push_back(stk.itemQuantitySold[i] * stk.itemPrice[i]);
            }
        }
    }

    for (int i = 0; i < totalSales.size(); ++i) {
        totalRevenue += totalSales[i];
    }

    printSameTime(salesFile,"\n\n\t\t======================================================================");
    printSameTime(salesFile,"\n\t\t\t\tTOTAL REVENUE OF THE DAY   =   " + to_string(totalRevenue) + "\n");
    printSameTime(salesFile,"\t\t======================================================================\n");

    salesFile.close();


}

////display and save the stock report
void UserInterface::stockReport(StockManagement &stk) {
    ofstream stockFile;
    stockFile.open("STOCK_REPORT.txt", std::ofstream::out | std::ofstream::trunc);

    printSameTime(stockFile,"\n\n");
    printSameTime(stockFile,"\n\t\t\t********************************************\n");
    printSameTime(stockFile,"\n\t\t\t\t\tSTOCK REPORT\n");
    printSameTime(stockFile,"\n\t\t\t\tDate: " + getDateString() + "\tTime: " + getTimeString());
    printSameTime(stockFile,"\n\t\t\t********************************************\n");
    printSameTime(stockFile,"\n\n");


    StockManagement s;
    s.batchDetails();
    vector<int> receivedStock = s.b_quantity;

    printSameTime(stockFile,"\tITEM ID\t\tBATCH CODE\tPURCHASE DATE\tEXPIRY DATE\tQUANTITY RECEIVED\tAVAILABLLE QUANTITY\n");

    for (int i = 0; i < stk.b_itemCode.size(); ++i) {
        printSameTime(stockFile,("\n\t" + (stk.b_itemCode[i]) +  "\t\t" + stk.b_batchCode[i] + "\t" + stk.b_purchaseDate[i] + "\t" + stk.b_expiryDate[i] + "\t\t" + to_string(receivedStock[i])  + "\t\t\t" + to_string(stk.b_quantity[i]) +"\n"));
    }


    stockFile.close();

}

////read the stored data of transactions and display
void UserInterface::billReport(StockManagement &stk) {
    ifstream myFile("TRANSACTIONS.txt");

    /**
     * ifstream myFile;
     * myFile.open("TRANSACTIONS.txt");
     * */
    string getContent;
    if (myFile.is_open()) {
        while (!myFile.eof()) {
            getline(myFile, getContent);
            cout << "\n\t" << getContent;
        }
    }

    myFile.close();
}

////print and save the reshelf status report
void UserInterface::reshelfReport(StockManagement &stk) {

    ofstream shelfFile;
    shelfFile.open("SHELF_REPORT.txt", std::ofstream::out | std::ofstream::trunc);

    printSameTime(shelfFile,"\n\n");
    printSameTime(shelfFile,"\n\t\t\t********************************************\n");
    printSameTime(shelfFile,"\n\t\t\t\t\tSHELF REPORT\n");
    printSameTime(shelfFile,"\n\t\t\t\tDate: " + getDateString() + "\tTime: " + getTimeString());
    printSameTime(shelfFile,"\n\t\t\t********************************************\n");
    printSameTime(shelfFile,"\n\n");

    printSameTime(shelfFile,"\n\t\tITEM CODE\tITEM NAME\t\tSHELF STOCK LEVEL\tQUANTITY NEEDED TO RESTOCK\n");

    for (int i = 0; i < stk.sh_itemCode.size(); ++i) {
        printSameTime(shelfFile,"\n\t\t" + stk.sh_itemCode[i] + "\t\t" + stk.itemName[i] + "\t\t" + to_string(stk.sh_quantity[i]) + "\t\t\t" + to_string((20 - stk.sh_quantity[i])) + "\n");
    }

    shelfFile.close();

}

void UserInterface::reorderAlert(StockManagement& stk) {
    ofstream reorderFile;
    reorderFile.open("ITEMS_TO_REORDER.txt", std::ofstream::out | std::ofstream::trunc);

    printSameTime(reorderFile,"\n\n");
    printSameTime(reorderFile,"\n\t\t\t********************************************\n");
    printSameTime(reorderFile,"\n\t\t\t\t\tLOW STOCK LEVEL ITEMS\n");
    printSameTime(reorderFile,"\n\t\t\t\tDate: " + getDateString() + "\tTime: " + getTimeString());
    printSameTime(reorderFile,"\n\t\t\t********************************************\n");
    printSameTime(reorderFile,"\n\n");

    printSameTime(reorderFile,"\n\t\tITEM CODE\tITEM NAME\t\tCURRENT STOCK\n");

    for (int i = 0; i < stk.itemQuantityInStock.size(); ++i) {
        if (stk.itemQuantityInStock[i] < 50) {
            printSameTime(reorderFile,"\n\t\t" + stk.itemId[i] + "\t\t" + stk.itemName[i] + "\t\t" + to_string(stk.itemQuantityInStock[i]) + "\n");
        }
    }

    reorderFile.close();
}


inline bool UserInterface::file_exists (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

////function to get the data into a int type vector from a file
vector<int> UserInterface::getIntDataToVector(string fileName) {

    ifstream myfile(fileName);
    string line;
    vector<int> myLines;
    while (std::getline(myfile, line))
    {
        myLines.push_back(stoi(line));
    }
    return myLines;
}

////returns the current date
const std::string getDateString()
{
    time_t     now = time(0);
    struct tm  tstruct;
    localtime_s(&tstruct, &now);
    return std::string(std::to_string(tstruct.tm_mon+1)+"/"+ std::to_string(tstruct.tm_mday)+"/" + std::to_string(tstruct.tm_year+1900));
}

////returns the current time
const std::string getTimeString()
{
    time_t     now = time(0);
    struct tm  tstruct;
    localtime_s(&tstruct,&now);
    return std::string(std::to_string(tstruct.tm_hour) + ":" + std::to_string(tstruct.tm_min) + ":" + std::to_string(tstruct.tm_sec));
}

////stores and displays a text at same time
void UserInterface::printSameTime(ofstream& file, const string& str) {
    cout << str;
    file << str;
}



