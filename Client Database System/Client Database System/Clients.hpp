//
//  Clients.hpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#ifndef Clients_hpp
#define Clients_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clients {
    public:
    Clients();
    void ReadFromFile(vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector);
    void AddNewClients(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector);
    void UpdateClientInfo(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector);
    void PrintClientInfo(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector);
    void SaveToFile(string name, string address, string sale, vector<string>& clientNameVector, vector<string>& clientAddressVector, vector<string>& clientSalesVector);
    
    protected:
    vector<string> clientNameVector;
    vector<string> clientAddressVector;
    vector<string> clientSalesVector;
};

#endif /* Clients_hpp */
