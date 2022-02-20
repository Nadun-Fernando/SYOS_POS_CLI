//
// Created by Nadun N. T. Fernando on 5/14/2021.
//
#include <iostream>
#include <vector>
#include <fstream>
#ifndef FIRSTSEMFINALPROJECT_STOCKMANAGEMENT_H
#define FIRSTSEMFINALPROJECT_STOCKMANAGEMENT_H

using namespace std;

class StockManagement {
public:
    vector<string> itemId;
    vector<string> itemName;
    vector<double> itemPrice;
    vector<int> itemQuantityInStock;
    vector<int> itemQuantitySold;
    vector<string> b_itemCode;
    vector<string> b_batchCode;
    vector<string> b_purchaseDate;
    vector<string> b_expiryDate;
    vector<int> b_quantity;
    vector<string> sh_itemCode;
    vector<int> sh_quantity;
    bool reduceFromShelf;
    void CurrentStock();
    void currentShelf();
    void reduceFromShelfStock(string itemID, int quantity);
    void addItem(string itemIdParsed, string itemNameParsed, double itemPriceParsed, int itemQuantityParsed);
    void saveStoreItems();
    void saveBatchItems();
    void saveShelfItems();
    double getItemPrice(int index);
    string getItemName(int index);
    string getItemId(int index);
    int getItemQuantitySold(int index);
    fstream myFile;
    void getStoreDataFromFile();
    void getBatchDataFromFile();
    void getShelfDataFromFile();
    void clearVectors();
    void batchDetails();
    void updateShelf();
    string getLowItemCode();


private:
    vector<string> getLine(string line);
    vector<double> StockManagement::getLineDoubleValues(string line);
    vector<int> getIndexes(string itemCode);
    vector<int> split (string s, string delimiter);
    void eraseEmptyBatch();

};


#endif //FIRSTSEMFINALPROJECT_STOCKMANAGEMENT_H
