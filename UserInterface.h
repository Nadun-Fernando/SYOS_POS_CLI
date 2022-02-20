//
// Created by Nadun N. T. Fernando on 5/30/2021.
//
#include <iostream>
#include "StockManagement.h"
#ifndef FIRSTSEMFINALPROJECT_USERINTERFACE_H
#define FIRSTSEMFINALPROJECT_USERINTERFACE_H

class UserInterface {
public:
    void displayUI(StockManagement& stk);

private:
    void displayItems(StockManagement& stk);
    void createBill(StockManagement& stk);
    void displayReports(StockManagement& stk);
    void salesReport(StockManagement& stk);
    void reshelfReport(StockManagement& stk);
    void reorderAlert(StockManagement& stk);
    void stockReport(StockManagement& stk);
    void billReport(StockManagement& stk);
    vector<string> userInputItemID;
    vector<int> userInputQuantity;
    vector<double> totalItemPrice;
    double total;
    int billNumber;
    double cash;
    double change;
    void storeBill(double total, double cashTendered, double changeIssued, int billNum,StockManagement &stk);
    void storeTransactions(double total, int billNum, StockManagement& stk);
    vector<int> billNum;
    void printBillNumber(vector<int> billNumbers);
    void printBill(double total, double cashTendered, double changeIssued, int billNum, StockManagement &stk);
    inline bool file_exists (const std::string& name);
    vector<int> getIntDataToVector(string fileName);
    void printSameTime(ofstream& file, const string& str);
    bool reorder = false;
};

const std::string getDateString();
const std::string getTimeString();

#endif //FIRSTSEMFINALPROJECT_USERINTERFACE_H


