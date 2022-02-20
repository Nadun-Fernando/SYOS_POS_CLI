//
// Created by Nadun N. T. Fernando on 5/14/2021.
//
#include <iostream>
#include "StockManagement.h"
#include <vector>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

/**--------------------------------------------sample database(starting database)--------------------------------------------------------**/
void StockManagement::CurrentStock() {

    itemId = {"B001", "B002", "B003", "B004", "B005", "I001", "I002", "I003", "I004", "I005"};
    itemName = {"Maliban-Gold-Marie",
                "Munchee-Tikiri-Marie",
                "Maliban-Cream-Cracker",
                "Maliban-Cho-C/Biscuit",
                "Maliban-Lemon-Puff",
                "C/Magic-Vanilla-2Ltr",
                "E/House-Vanilla-2Ltr",
                "E/House-W/C-Vanilla",
                "E/House-WonderBar",
                "C/Magic-Vanilla-1Ltr"};
    itemPrice = {35.00,
                 40.00,
                 200.00,
                 45.00,
                 60.00,
                 450.00,
                 500.00,
                 60.00,
                 50.00,
                 300.00};

    itemQuantityInStock = {100,
                           100,
                           100,
                           100,
                           100,
                           100,
                           100,
                           100,
                           100,
                           100};

};

void StockManagement::batchDetails() {
    b_itemCode = {
            "B001",
            "B002",
            "B003",
            "B004",
            "B005",
            "I001",
            "I002",
            "I003",
            "I004",
            "I005",
            "B001",
            "I003",
            "B004"
    };

    b_batchCode = {
            "B001_S01",
            "B001_S01",
            "B001_S01",
            "B001_S01",
            "B001_S01",
            "I001_S01",
            "I002_S01",
            "I003_S01",
            "I004_S01",
            "I005_S01",
            "B001_S02",
            "I003_S02",
            "B004_S02"
    };

    b_purchaseDate = {
            "2021-05-18",
            "2021-05-15",
            "2021-05-15",
            "2021-05-18",
            "2021-05-18",
            "2021-05-18",
            "2021-05-15",
            "2021-05-15",
            "2021-05-16",
            "2021-05-16",
            "2021-05-25",
            "2021-05-28",
            "2021-05-30"
    };

    b_expiryDate = {
            "2022-05-02",
            "2022-04-02",
            "2022-04-02",
            "2022-05-02",
            "2022-05-01",
            "2023-01-01",
            "2023-01-15",
            "2023-03-02",
            "2023-02-20",
            "2022-12-02",
            "2021-08-12",
            "2022-07-21",
            "2022-08-28"
    };

    b_quantity = {
            70,
            100,
            100,
            80,
            100,
            100,
            100,
            40,
            100,
            100,
            30,
            20,
            60
    };
}

void StockManagement::currentShelf() {
    sh_itemCode = {
            "B001",
            "B002",
            "B003",
            "B004",
            "B005",
            "I001",
            "I002",
            "I003",
            "I004",
            "I005"
    };

    sh_quantity = {
            20,
            20,
            20,
            20,
            20,
            20,
            20,
            20,
            20,
            20
    };
}

/**-------------------------------------------------------------------------------------------------------------------------------------**/


////returns the indexes for the given itemcode
vector<int> StockManagement::getIndexes(string itemCode) {
    vector<int> indexes;

    for (int i = 0; i < b_itemCode.size(); ++i) {
        if (itemCode == b_itemCode[i]) {
            indexes.push_back(i);
        }
    }

    return indexes;
}

/**
 * update the shelf from stock by comparing the dates
 * if any batch quantity is 0 remove it
 **/
void StockManagement::updateShelf() {

    for (int i = 0; i < sh_itemCode.size(); ++i) {
        if (sh_quantity[i] < 20) {
            vector<int> locations = getIndexes(sh_itemCode[i]);
            if (locations.size() == 1) {
                int neededStock = 20 - sh_quantity[i];
                if (b_quantity[locations[0]] >= neededStock) {
                    sh_quantity[i] += neededStock;
                    b_quantity[locations[0]] -= neededStock;
                    for (int j = 0; j < itemId.size(); ++j) {
                        if (sh_itemCode[i] == itemId[j]) {
                            itemQuantityInStock[j] -= neededStock;
                        }
                    }
                } else {
                    sh_quantity[i] += b_quantity[locations[0]];
                    b_quantity[locations[0]] = 0;
                    for (int j = 0; j < itemId.size(); ++j) {
                        if (sh_itemCode[i] == itemId[j]) {
                            itemQuantityInStock[j] = 0;
                        }
                    }
                    eraseEmptyBatch();
                }

            } else if (locations.size() == 2) {

                int neededStock = 20 - sh_quantity[i];
//                vector<int> ex_date_1 = split(b_expiryDate[locations[0]],"-");
//                vector<int> ex_date_2 = split(b_expiryDate[locations[1]],"-");

                if (split(b_expiryDate[locations[0]],"-")[0] < split(b_expiryDate[locations[1]],"-")[0]) {
                    if (b_quantity[locations[0]] >= neededStock) {
                        sh_quantity[i] += neededStock;
                        b_quantity[locations[0]] -= neededStock;
                        for (int j = 0; j < itemId.size(); ++j) {
                            if (sh_itemCode[i] == itemId[j]) {
                                itemQuantityInStock[j] -= neededStock;
                            }
                        }
                    } else {
                        sh_quantity[i] += b_quantity[locations[0]];
                        b_quantity[locations[0]] = 0;
                        for (int j = 0; j < itemId.size(); ++j) {
                            if (sh_itemCode[i] == itemId[j]) {
                                itemQuantityInStock[j] = 0;
                            }
                        }
                        if (sh_quantity[i] != 20) {
                            neededStock = 20 - sh_quantity[i];
                            if (b_quantity[locations[1]] >= neededStock) {
                                sh_quantity[i] += neededStock;
                                b_quantity[locations[1]] -= neededStock;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] -= neededStock;
                                    }
                                }
                            } else {
                                sh_quantity[i] += b_quantity[locations[1]];
                                b_quantity[locations[1]] = 0;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] = 0;
                                    }
                                }
                            }
                        }
                    }
                    eraseEmptyBatch();

                } else if (split(b_expiryDate[locations[0]],"-")[0] > split(b_expiryDate[locations[1]],"-")[0]) {

                    if (b_quantity[locations[1]] >= neededStock) {
                        sh_quantity[i] += neededStock;
                        b_quantity[locations[1]] -= neededStock;
                        for (int j = 0; j < itemId.size(); ++j) {
                            if (sh_itemCode[i] == itemId[j]) {
                                itemQuantityInStock[j] -= neededStock;
                            }
                        }
                    } else {
                        sh_quantity[i] += b_quantity[locations[1]];
                        b_quantity[locations[1]] = 0;
                        for (int j = 0; j < itemId.size(); ++j) {
                            if (sh_itemCode[i] == itemId[j]) {
                                itemQuantityInStock[j] = 0;
                            }
                        }
                        if (sh_quantity[i] != 20) {
                            neededStock = 20 - sh_quantity[i];
                            if (b_quantity[locations[0]] >= neededStock) {
                                sh_quantity[i] += neededStock;
                                b_quantity[locations[0]] -= neededStock;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] -= neededStock;
                                    }
                                }
                            } else {
                                sh_quantity[i] += b_quantity[locations[0]];
                                b_quantity[locations[0]] = 0;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] = 0;
                                    }
                                }
                            }
                        }
                    }
                    eraseEmptyBatch();

                } else if (split(b_expiryDate[locations[0]],"-")[0] == split(b_expiryDate[locations[1]],"-")[0]){

                    if (split(b_expiryDate[locations[0]],"-")[1] < split(b_expiryDate[locations[1]],"-")[1]) {
                        if (b_quantity[locations[0]] >= neededStock) {
                            sh_quantity[i] += neededStock;
                            b_quantity[locations[0]] -= neededStock;
                            for (int j = 0; j < itemId.size(); ++j) {
                                if (sh_itemCode[i] == itemId[j]) {
                                    itemQuantityInStock[j] -= neededStock;
                                }
                            }
                        } else {
                            sh_quantity[i] += b_quantity[locations[0]];
                            b_quantity[locations[0]] = 0;
                            for (int j = 0; j < itemId.size(); ++j) {
                                if (sh_itemCode[i] == itemId[j]) {
                                    itemQuantityInStock[j] = 0;
                                }
                            }
                            if (sh_quantity[i] != 20) {
                                neededStock = 20 - sh_quantity[i];
                                if (b_quantity[locations[1]] >= neededStock) {
                                    sh_quantity[i] += neededStock;
                                    b_quantity[locations[1]] -= neededStock;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] -= neededStock;
                                        }
                                    }
                                } else {
                                    sh_quantity[i] += b_quantity[locations[1]];
                                    b_quantity[locations[1]] = 0;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] = 0;
                                        }
                                    }
                                }
                            }
                        }
                        eraseEmptyBatch();

                    } else if (split(b_expiryDate[locations[0]],"-")[1] > split(b_expiryDate[locations[1]],"-")[1]) {

                        if (b_quantity[locations[1]] >= neededStock) {
                            sh_quantity[i] += neededStock;
                            b_quantity[locations[1]] -= neededStock;
                            for (int j = 0; j < itemId.size(); ++j) {
                                if (sh_itemCode[i] == itemId[j]) {
                                    itemQuantityInStock[j] -= neededStock;
                                }
                            }
                        } else {
                            sh_quantity[i] += b_quantity[locations[1]];
                            b_quantity[locations[1]] = 0;
                            for (int j = 0; j < itemId.size(); ++j) {
                                if (sh_itemCode[i] == itemId[j]) {
                                    itemQuantityInStock[j] = 0;
                                }
                            }
                            if (sh_quantity[i] != 20) {
                                neededStock = 20 - sh_quantity[i];
                                if (b_quantity[locations[0]] >= neededStock) {
                                    sh_quantity[i] += neededStock;
                                    b_quantity[locations[0]] -= neededStock;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] -= neededStock;
                                        }
                                    }
                                } else {
                                    sh_quantity[i] += b_quantity[locations[0]];
                                    b_quantity[locations[0]] = 0;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] = 0;
                                        }
                                    }
                                }
                            }
                        }
                        eraseEmptyBatch();

                    } else if (split(b_expiryDate[locations[0]],"-")[1] == split(b_expiryDate[locations[1]],"-")[1]) {

                        if (split(b_expiryDate[locations[0]],"-")[2] < split(b_expiryDate[locations[1]],"-")[2]) {
                            if (b_quantity[locations[0]] >= neededStock) {
                                sh_quantity[i] += neededStock;
                                b_quantity[locations[0]] -= neededStock;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] -= neededStock;
                                    }
                                }
                            } else {
                                sh_quantity[i] += b_quantity[locations[0]];
                                b_quantity[locations[0]] = 0;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] = 0;
                                    }
                                }
                                if (sh_quantity[i] != 20) {
                                    neededStock = 20 - sh_quantity[i];
                                    if (b_quantity[locations[1]] >= neededStock) {
                                        sh_quantity[i] += neededStock;
                                        b_quantity[locations[1]] -= neededStock;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] -= neededStock;
                                            }
                                        }
                                    } else {
                                        sh_quantity[i] += b_quantity[locations[1]];
                                        b_quantity[locations[1]] = 0;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] = 0;
                                            }
                                        }
                                    }
                                }
                            }
                            eraseEmptyBatch();

                        } else if (split(b_expiryDate[locations[0]],"-")[2] > split(b_expiryDate[locations[1]],"-")[2]) {

                            if (b_quantity[locations[1]] >= neededStock) {
                                sh_quantity[i] += neededStock;
                                b_quantity[locations[1]] -= neededStock;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] -= neededStock;
                                    }
                                }
                            } else {
                                sh_quantity[i] += b_quantity[locations[1]];
                                b_quantity[locations[1]] = 0;
                                for (int j = 0; j < itemId.size(); ++j) {
                                    if (sh_itemCode[i] == itemId[j]) {
                                        itemQuantityInStock[j] = 0;
                                    }
                                }
                                if (sh_quantity[i] != 20) {
                                    neededStock = 20 - sh_quantity[i];
                                    if (b_quantity[locations[0]] >= neededStock) {
                                        sh_quantity[i] += neededStock;
                                        b_quantity[locations[0]] -= neededStock;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] -= neededStock;
                                            }
                                        }
                                    } else {
                                        sh_quantity[i] += b_quantity[locations[0]];
                                        b_quantity[locations[0]] = 0;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] = 0;
                                            }
                                        }
                                    }
                                }
                            }
                            eraseEmptyBatch();

                        } else {
                            if (split(b_purchaseDate[locations[0]],"-")[0] < split(b_purchaseDate[locations[1]],"-")[0]) {
                                if (b_quantity[locations[0]] >= neededStock) {
                                    sh_quantity[i] += neededStock;
                                    b_quantity[locations[0]] -= neededStock;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] -= neededStock;
                                        }
                                    }
                                } else {
                                    sh_quantity[i] += b_quantity[locations[0]];
                                    b_quantity[locations[0]] = 0;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] = 0;
                                        }
                                    }
                                    if (sh_quantity[i] != 20) {
                                        neededStock = 20 - sh_quantity[i];
                                        if (b_quantity[locations[1]] >= neededStock) {
                                            sh_quantity[i] += neededStock;
                                            b_quantity[locations[1]] -= neededStock;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] -= neededStock;
                                                }
                                            }
                                        } else {
                                            sh_quantity[i] += b_quantity[locations[1]];
                                            b_quantity[locations[1]] = 0;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                                eraseEmptyBatch();

                            } else if (split(b_purchaseDate[locations[0]],"-")[0] > split(b_purchaseDate[locations[1]],"-")[0]) {

                                if (b_quantity[locations[1]] >= neededStock) {
                                    sh_quantity[i] += neededStock;
                                    b_quantity[locations[1]] -= neededStock;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] -= neededStock;
                                        }
                                    }
                                } else {
                                    sh_quantity[i] += b_quantity[locations[1]];
                                    b_quantity[locations[1]] = 0;
                                    for (int j = 0; j < itemId.size(); ++j) {
                                        if (sh_itemCode[i] == itemId[j]) {
                                            itemQuantityInStock[j] = 0;
                                        }
                                    }
                                    if (sh_quantity[i] != 20) {
                                        neededStock = 20 - sh_quantity[i];
                                        if (b_quantity[locations[0]] >= neededStock) {
                                            sh_quantity[i] += neededStock;
                                            b_quantity[locations[0]] -= neededStock;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] -= neededStock;
                                                }
                                            }
                                        } else {
                                            sh_quantity[i] += b_quantity[locations[0]];
                                            b_quantity[locations[0]] = 0;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                                eraseEmptyBatch();

                            } else if (split(b_purchaseDate[locations[0]],"-")[0] == split(b_purchaseDate[locations[1]],"-")[0]) {

                                if (split(b_purchaseDate[locations[0]], "-")[1] <
                                    split(b_purchaseDate[locations[1]], "-")[1]) {
                                    if (b_quantity[locations[0]] >= neededStock) {
                                        sh_quantity[i] += neededStock;
                                        b_quantity[locations[0]] -= neededStock;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] -= neededStock;
                                            }
                                        }
                                    } else {
                                        sh_quantity[i] += b_quantity[locations[0]];
                                        b_quantity[locations[0]] = 0;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] = 0;
                                            }
                                        }
                                        if (sh_quantity[i] != 20) {
                                            neededStock = 20 - sh_quantity[i];
                                            if (b_quantity[locations[1]] >= neededStock) {
                                                sh_quantity[i] += neededStock;
                                                b_quantity[locations[1]] -= neededStock;
                                                for (int j = 0; j < itemId.size(); ++j) {
                                                    if (sh_itemCode[i] == itemId[j]) {
                                                        itemQuantityInStock[j] -= neededStock;
                                                    }
                                                }
                                            } else {
                                                sh_quantity[i] += b_quantity[locations[1]];
                                                b_quantity[locations[1]] = 0;
                                                for (int j = 0; j < itemId.size(); ++j) {
                                                    if (sh_itemCode[i] == itemId[j]) {
                                                        itemQuantityInStock[j] = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    eraseEmptyBatch();

                                } else if (split(b_purchaseDate[locations[0]], "-")[1] >
                                           split(b_purchaseDate[locations[1]], "-")[1]) {

                                    if (b_quantity[locations[1]] >= neededStock) {
                                        sh_quantity[i] += neededStock;
                                        b_quantity[locations[1]] -= neededStock;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] -= neededStock;
                                            }
                                        }
                                    } else {
                                        sh_quantity[i] += b_quantity[locations[1]];
                                        b_quantity[locations[1]] = 0;
                                        for (int j = 0; j < itemId.size(); ++j) {
                                            if (sh_itemCode[i] == itemId[j]) {
                                                itemQuantityInStock[j] = 0;
                                            }
                                        }
                                        if (sh_quantity[i] != 20) {
                                            neededStock = 20 - sh_quantity[i];
                                            if (b_quantity[locations[0]] >= neededStock) {
                                                sh_quantity[i] += neededStock;
                                                b_quantity[locations[0]] -= neededStock;
                                                for (int j = 0; j < itemId.size(); ++j) {
                                                    if (sh_itemCode[i] == itemId[j]) {
                                                        itemQuantityInStock[j] -= neededStock;
                                                    }
                                                }
                                            } else {
                                                sh_quantity[i] += b_quantity[locations[0]];
                                                b_quantity[locations[0]] = 0;
                                                for (int j = 0; j < itemId.size(); ++j) {
                                                    if (sh_itemCode[i] == itemId[j]) {
                                                        itemQuantityInStock[j] = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    eraseEmptyBatch();

                                } else if (split(b_purchaseDate[locations[0]], "-")[1] ==
                                           split(b_purchaseDate[locations[1]], "-")[1]) {

                                    if (split(b_purchaseDate[locations[0]], "-")[2] <
                                        split(b_purchaseDate[locations[1]], "-")[2]) {
                                        if (b_quantity[locations[0]] >= neededStock) {
                                            sh_quantity[i] += neededStock;
                                            b_quantity[locations[0]] -= neededStock;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] -= neededStock;
                                                }
                                            }
                                        } else {
                                            sh_quantity[i] += b_quantity[locations[0]];
                                            b_quantity[locations[0]] = 0;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] = 0;
                                                }
                                            }
                                            if (sh_quantity[i] != 20) {
                                                neededStock = 20 - sh_quantity[i];
                                                if (b_quantity[locations[1]] >= neededStock) {
                                                    sh_quantity[i] += neededStock;
                                                    b_quantity[locations[1]] -= neededStock;
                                                    for (int j = 0; j < itemId.size(); ++j) {
                                                        if (sh_itemCode[i] == itemId[j]) {
                                                            itemQuantityInStock[j] -= neededStock;
                                                        }
                                                    }
                                                } else {
                                                    sh_quantity[i] += b_quantity[locations[1]];
                                                    b_quantity[locations[1]] = 0;
                                                    for (int j = 0; j < itemId.size(); ++j) {
                                                        if (sh_itemCode[i] == itemId[j]) {
                                                            itemQuantityInStock[j] = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        eraseEmptyBatch();

                                    } else if (split(b_purchaseDate[locations[0]], "-")[2] >
                                               split(b_purchaseDate[locations[1]], "-")[2]) {

                                        if (b_quantity[locations[1]] >= neededStock) {
                                            sh_quantity[i] += neededStock;
                                            b_quantity[locations[1]] -= neededStock;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] -= neededStock;
                                                }
                                            }
                                        } else {
                                            sh_quantity[i] += b_quantity[locations[1]];
                                            b_quantity[locations[1]] = 0;
                                            for (int j = 0; j < itemId.size(); ++j) {
                                                if (sh_itemCode[i] == itemId[j]) {
                                                    itemQuantityInStock[j] = 0;
                                                }
                                            }
                                            if (sh_quantity[i] != 20) {
                                                neededStock = 20 - sh_quantity[i];
                                                if (b_quantity[locations[0]] >= neededStock) {
                                                    sh_quantity[i] += neededStock;
                                                    b_quantity[locations[0]] -= neededStock;
                                                    for (int j = 0; j < itemId.size(); ++j) {
                                                        if (sh_itemCode[i] == itemId[j]) {
                                                            itemQuantityInStock[j] -= neededStock;
                                                        }
                                                    }
                                                } else {
                                                    sh_quantity[i] += b_quantity[locations[0]];
                                                    b_quantity[locations[0]] = 0;
                                                    for (int j = 0; j < itemId.size(); ++j) {
                                                        if (sh_itemCode[i] == itemId[j]) {
                                                            itemQuantityInStock[j] = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        eraseEmptyBatch();

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

////reduce PurchasedItems from shelf
void StockManagement::reduceFromShelfStock(string itemIdParsed, int quantityParsed) {
    int i = 0;
    reduceFromShelf = false;

    for (i; i < sh_itemCode.size(); i++) {
            if (itemIdParsed == sh_itemCode[i]) {
                sh_quantity[i] = sh_quantity[i] - quantityParsed;
                reduceFromShelf = true;
                break;
            }
        }

        if (reduceFromShelf) {
            if (itemQuantitySold.size() == itemId.size()) {
                itemQuantitySold[i] += quantityParsed;
            } else {
                itemQuantitySold.resize(itemId.size() - itemQuantitySold.size());
                itemQuantitySold[i] += quantityParsed;
            }


        }

}

////add new items to the vector
/*Not yet developed - under development*/
void StockManagement::addItem(string itemIdParsed, string itemNameParsed, double itemPriceParsed, int itemQuantityParsed) {
    itemId.resize(itemId.size() + 1);
    itemName.resize(itemName.size() + 1);
    itemPrice.resize(itemPrice.size() + 1);
    itemQuantityInStock.resize(itemQuantityInStock.size() + 1);

    itemId.back() = itemIdParsed;
    itemName.back() = itemNameParsed;
    itemPrice.back() = itemPriceParsed;
    itemQuantityInStock.back() = itemQuantityParsed;
}

////save store data to a file
void StockManagement::saveStoreItems() {
    //saving itemID vector;
    ofstream output_ID ("store.txt");
    ostream_iterator<string> id_iterator(output_ID," ");   //output_ID<<"\n";
    copy(itemId.begin(),itemId.end(),id_iterator);
    output_ID<<"\n";

    ostream_iterator<string> name_iterator(output_ID," ");
    copy(itemName.begin(),itemName.end(),name_iterator);
    output_ID<<"\n";

    ostream_iterator<double> price_iterator(output_ID," ");
    copy(itemPrice.begin(),itemPrice.end(),price_iterator);
    output_ID<<"\n";

    ostream_iterator<int> quantity_iterator(output_ID," ");
    copy(itemQuantityInStock.begin(),itemQuantityInStock.end(),quantity_iterator);
    output_ID<<"\n";
}

////save shelf data to a file
void StockManagement::saveShelfItems() {
    ofstream output_ID ("shelf.txt");

    ostream_iterator<string> id_iterator(output_ID," ");
    copy(sh_itemCode.begin(),sh_itemCode.end(),id_iterator);
    output_ID<<"\n";

    ostream_iterator<double> quantity_iterator(output_ID," ");
    copy(sh_quantity.begin(),sh_quantity.end(),quantity_iterator);
    output_ID<<"\n";
}

////save batch data to a file
void StockManagement::saveBatchItems() {
    ofstream output_ID ("batch.txt");
    ostream_iterator<string> id_iterator(output_ID," ");   //output_ID<<"\n";
    copy(b_itemCode.begin(),b_itemCode.end(),id_iterator);
    output_ID<<"\n";

    ostream_iterator<string> batch_iterator(output_ID," ");
    copy(b_batchCode.begin(),b_batchCode.end(),batch_iterator);
    output_ID<<"\n";

    ostream_iterator<string> exp_iterator(output_ID," ");
    copy(b_expiryDate.begin(),b_expiryDate.end(),exp_iterator);
    output_ID<<"\n";

    ostream_iterator<string> pshd_iterator(output_ID," ");
    copy(b_purchaseDate.begin(),b_purchaseDate.end(),pshd_iterator);
    output_ID<<"\n";

    ostream_iterator<int> quantity_iterator(output_ID," ");
    copy(b_quantity.begin(),b_quantity.end(),quantity_iterator);
    output_ID<<"\n";
}


////read the string data from file and assign it to a vector
vector<string> StockManagement::getLine(string line) {
    char * tokens;
    char * line_chararr = const_cast< char *>(line.c_str());
    tokens = strtok(line_chararr, " ");
    vector<string> vs;

    while (tokens != NULL)
    {
        vs.push_back(tokens);
        tokens = strtok (NULL, " ");
    }

    return vs;
}

////read the double data from file and assign it to a vector
vector<double> StockManagement::getLineDoubleValues(string line) {
    char * tokens;
    char * line_chararr = const_cast< char *>(line.c_str());
    tokens = strtok(line_chararr, " ");
    vector<double> dc;

    while (tokens != NULL)
    {
        double cc = atof(tokens);
        dc.push_back(cc);
        tokens = strtok (NULL, " ");
    }

    return dc;
}

/**-------------------------------------------Read the Data from the files and assign data to vectors-------------------------**/
void StockManagement::getStoreDataFromFile() {
    //clearVectors();
    myFile.open("store.txt");

    if (myFile.is_open())
    {
        short line_num = 1;
        for (std::string line; std::getline(myFile, line); ) {
            if (line_num == 1) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    itemId.push_back(getLine(line)[i]);
                }
            } else if (line_num == 2) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    itemName.push_back(getLine(line)[i]);
                }
            } else if (line_num == 3) {
                for (int i = 0; i < getLineDoubleValues(line).size(); ++i) {
                    itemPrice.push_back(getLineDoubleValues(line)[i]);
                }
            } else if (line_num == 4) {
                for (int i = 0; i < getLineDoubleValues(line).size(); ++i) {
                    itemQuantityInStock.push_back(getLineDoubleValues(line)[i]);
                }
            } else {
                break;

            }
            line_num++;
        }
        myFile.close();
    }
}

void StockManagement::getBatchDataFromFile() {

    myFile.open("batch.txt");


    if (myFile.is_open())
    {
        short line_num = 1;
        for (std::string line; std::getline(myFile, line); ) {
            if (line_num == 1) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    b_itemCode.push_back(getLine(line)[i]);
                }
            } else if (line_num == 2) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    b_batchCode.push_back(getLine(line)[i]);
                }
            } else if (line_num == 3) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    b_purchaseDate.push_back(getLine(line)[i]);
                }
            } else if (line_num == 4) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    b_expiryDate.push_back(getLine(line)[i]);
                }
            } else if (line_num == 5) {
                for (int i = 0; i < getLineDoubleValues(line).size(); ++i) {
                    b_quantity.push_back(getLineDoubleValues(line)[i]);
                }
            }
            else {
                break;
            }
            line_num++;
        }
        myFile.close();
    }
}

void StockManagement::getShelfDataFromFile() {

    myFile.open("shelf.txt");


    if (myFile.is_open())
    {
        short line_num = 1;
        for (std::string line; std::getline(myFile, line); ) {
            if (line_num == 1) {
                for (int i = 0; i < getLine(line).size(); ++i) {
                    sh_itemCode.push_back(getLine(line)[i]);
                }
            } else if (line_num == 2) {
                for (int i = 0; i < getLineDoubleValues(line).size(); ++i) {
                    sh_quantity.push_back(getLineDoubleValues(line)[i]);
                }
            } else {
                break;
            }
            line_num++;
        }
        myFile.close();
    }
}

/**-----------------------------------------------------------------------------------------------------------------------------**/

////erases the batch details if the batch stock is 0
void StockManagement::eraseEmptyBatch() {
    for (int i = 0; i < b_itemCode.size(); ++i) {
        if (b_quantity[i] == 0) {
            b_quantity.erase(b_quantity.begin() + i);
            b_itemCode.erase(b_itemCode.begin() + i);
            b_expiryDate.erase(b_itemCode.begin() + i);
            b_purchaseDate.erase(b_itemCode.begin() + i);
            b_batchCode.erase(b_itemCode.begin() + i);
        }
    }
}

////function to clear all the vectors
void StockManagement::clearVectors() {
    itemId.clear();
    itemName.clear();
    itemPrice.clear();
    itemQuantityInStock.clear();

    b_itemCode.clear();
    b_batchCode.clear();
    b_purchaseDate.clear();
    b_expiryDate.clear();
    b_quantity.clear();

    sh_quantity.clear();
    sh_itemCode.clear();
}

//// for string delimiter
vector<int> StockManagement::split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<int> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        int tValue = stoi(token);
        res.push_back (tValue);
    }

    res.push_back (stoi(s.substr (pos_start)));
    return res;
}

string StockManagement::getItemId(int index) {
    return itemId[index];
}

string StockManagement::getItemName(int index) {
    return itemName[index];
}

double StockManagement::getItemPrice(int index) {
    return itemPrice[index];
}

int StockManagement::getItemQuantitySold(int index) {
    return itemQuantitySold[index];
}

