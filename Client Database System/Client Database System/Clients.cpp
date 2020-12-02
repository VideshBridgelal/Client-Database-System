//
//  Clients.cpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#include "Clients.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

Clients::Clients(){
    name = "No name";
    address = "No address";
    sale = "No sale";
}

void Clients::ReadFromFile(vector<string>& clientNameVector,vector<string>& clientAddressVector, vector<string>& clientSalesVector){
    ifstream clientIn;
    clientIn.open("ClientsFile.txt");
    
    while(!clientIn.eof()){                        //Fills the vectors from file
        clientIn >> name;
        clientIn >> address;
        clientIn >> sale;
        
        if(!clientIn.fail()){
            clientNameVector.push_back(name);
            clientAddressVector.push_back(address);
            clientSalesVector.push_back(sale);
        }
    }
    
    clientIn.close();
}

void Clients::AddNewClients(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector){
    cout << "Input name, address, and sale: ";
    cin >> name;
    cin >> address;
    cin >> sale;
    
    clientNameVector.push_back(name);
    clientAddressVector.push_back(address);
    clientSalesVector.push_back(sale);
}

void Clients::UpdateClientInfo(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector){
    string userName;
    cin >> userName;
    unsigned int i;
    
    for (i = 0; i < clientNameVector.size(); ++i) {
        if (clientNameVector.at(i) == userName){
            cout << "Input new name, address, sale: ";
            cin >> name;
            cin >> address;
            cin >> sale;
                                                                                //Inserts new information into vectors.
            clientNameVector.insert(clientNameVector.begin() + i, name);
            clientAddressVector.insert(clientAddressVector.begin() + i, address);
            clientSalesVector.insert(clientSalesVector.begin() + i, sale);
                                                                                //Erases old values in vectors.
                                                                                //In this case, it's one element above.
            clientNameVector.erase(clientNameVector.begin() + i + 1);
            clientAddressVector.erase(clientAddressVector.begin() + i + 1);
            clientSalesVector.erase(clientSalesVector.begin() + i + 1);
        }
    }
}

void Clients::PrintClientInfo(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector){
    unsigned int i;
    for (i = 0; i < clientNameVector.size(); ++i){
        name = clientNameVector.at(i);
        address = clientAddressVector.at(i);
        sale = clientSalesVector.at(i);

        cout << name << endl;
        cout << address << endl;
        cout << sale << endl;
}

void Clients::SaveToFile(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector){
    ofstream clientOut;
    clientOut.open("ClientsFile.txt");
    
    clientOut << setw(10);                    //Changes the width of each column to 10.
    clientOut << "Name:\tAddress\tSale:";
    
    unsigned int i;
    for (i = 0; i < clientNameVector.size(); ++i){
        name = clientNameVector.at(i);
        address = clientAddressVector.at(i);
        sale = clientSalesVector.at(i);
        
        clientOut << name << "\t" << address << "\t" << sale << endl;
    }
    clientIn.close();
}
