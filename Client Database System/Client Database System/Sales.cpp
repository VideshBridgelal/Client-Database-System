//
//  Sales.cpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#include "Sales.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

Sales::Sales(){

}

void Sales::ReadFromFile(vector<string>& salesVector){
    ifstream salesFileIn;
    salesFileIn.open("SalesFile.txt");
    
    string sales;
    while(!salesFileIn.eof()){
        salesFileIn >> sales;
        salesVector.push_back(sales);
    }
}

void Sales::PrintSales(vector<string>& salesVector){
    unsigned int i;
    
    for (i = 0; i < salesVector.size(); ++i){
        cout << salesVector.at(i);
    }
}

void Sales::PrintClientSales(vector<string>& salesVector){
    unsigned int i;
    for (i = 0; i < salesVector.size(); ++i){
        cout << salesVector.at(i) << endl;
    }
}

void Sales::UpdateSale(vector<string>& salesVector){
    string userSale;
    
    cin >> userSale;                            //FIXME: Get client vector and use their index with sales vector.
    
    unsigned int i;
    for(i = 0; i < salesVector.size(); ++i){
        if (userSale == salesVector.at(i)){
            cout << "Input new sale: " << endl;
            cin >> userSale;
        }
    }
}

void Sales::SaveToFile(vector<string>& salesVector){
    ofstream salesFileOut;
    salesFileOut.open("SalesFile.txt");
    
    unsigned int i;
    for (i = 0; i < salesVector.size(); ++i){
        salesFileOut << salesVector.at(i) << endl;
    }
}
