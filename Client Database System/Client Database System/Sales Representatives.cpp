//
//  Sales Representatives.cpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#include "Sales Representatives.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

SalesRepresentatives::SalesRepresentatives(){
    name = "No name";
    address = "No address";
    sale = "No sale";
}

void SalesRepresentatives::ReadFromFile(vector<string>& repNameVector,vector<string>& repAddressVector, vector<string>& repSalesVector){
    ifstream salesRepIn;
    salesRepIn.open("SaleRepresentativesFile.txt");
    
    while(!salesRepIn.eof()){                        //Fills the vectors from file
        salesRepIn >> name;
        salesRepIn >> address;
        salesRepIn >> sale;
        
        if(!salesRepIn.fail()){
            repNameVector.push_back(name);
            repAddressVector.push_back(address);
            repSalesVector.push_back(sale);
        }
    }
    
    salesRepIn.close();
}

void SalesRepresentatives::AddSalesRep(string name, string address, string sale, vector<string>& repNameVector, vector<string>& repAddressVector, vector<string>& repSalesVector){
    cout << "Input name, address, and sale: ";
    cin >> name;
    cin >> address;
    cin >> sale;
    
    repNameVector.push_back(name);
    repAddressVector.push_back(address);
    repSalesVector.push_back(sale);
}

void SalesRepresentatives::UpdateSalesRep(string name, string address, string sale, vector<string>& repNameVector, vector<string>& repAddressVector, vector<string>& repSalesVector){
    string userName;
    cin >> userName;
    unsigned int i;
    
    for (i = 0; i < repNameVector.size(); ++i) {
        if (repNameVector.at(i) == userName){
            cout << "Input new name, address, sale: ";
            cin >> name;
            cin >> address;
            cin >> sale;
                                                                                //Inserts new information into vectors.
            repNameVector.insert(repNameVector.begin() + i, name);
            repAddressVector.insert(repAddressVector.begin() + i, address);
            repSalesVector.insert(repSalesVector.begin() + i, sale);
                                                                                //Erases old values in vectors.
                                                                                //In this case, it's one element above.
            repNameVector.erase(repNameVector.begin() + i + 1);
            repAddressVector.erase(repAddressVector.begin() + i + 1);
            repSalesVector.erase(repSalesVector.begin() + i + 1);
        }
    }
}

int SalesRepresentatives::CalculateBonus(vector<int>& bonusVector){
    int totalBonus = 0;
    unsigned int i;
    
    for (i = 0; i < bonusVector.size(); ++i){
        totalBonus = totalBonus + bonusVector.at(i);
    }
    
    return totalBonus;
}

void SalesRepresentatives::SaveToFile(string name, string address, string sale, vector<string>& repNameVector, vector<string>& repAddressVector, vector<string>& repSalesVector){
    ofstream salesRepOut;
    salesRepOut.open("SaleRepresentativesFile.txt");
    
    salesRepOut << setw(10);                    //Changes the width of each column to 10.
    salesRepOut << "Name:\tAddress\tSale:";
    
    unsigned int i;
    for (i = 0; i < repNameVector.size(); ++i){
        name = repNameVector.at(i);
        address = repAddressVector.at(i);
        sale = repSalesVector.at(i);
        
        salesRepOut << name << "\t" << address << "\t" << sale << endl;
    }
    salesRepOut.close();
}
