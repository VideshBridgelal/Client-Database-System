//
//  main.cpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Clients.hpp"
#include "Sales Representatives.hpp"
#include "Product and Services.hpp"
#include "Sales.hpp"

using namespace std;

int main() {
    
    vector<string> clientName;          //Client vectors
    vector<string> clientAddress;
    vector<string> clientSale;
    
    vector<string> salesRepName;        //Sales Representatives vectors
    vector<string> salesRepAddress;
    vector<string> salesRepSale;
    vector<int>    bonus;
    
    vector<string> productVector;       //Product and Services vectors
    vector<string> descriptionVector;
    vector<int>    priceVector;
    
    vector<string> sales;               //Sales vector
    
    string name = "No name";                        //Undefined variables for user input
    string address = "No address";
    string sale = "No sale";
    string product = "No product";
    string description = "No description";
    int    price = 0;
    char   userInput = '\0';
    
    Clients clientObj;
    SalesRepresentatives salesRepObj;
    Product_and_Services prodServObj;
    Sales salesObj;
    
    
    while(userInput != 'q'){
        cout << "Welcome to the Client Database System.\n\tEnter one of the following commands:\n";
        
        cout << "\t\tc - Clients\n\t\tr - Sales Representative\n\t\tp - Product & Services\n\t\ts - Sales\n\t\tq - Quit";
    
        cin >> userInput;
        switch (userInput){
            
            case 'c':       //Clients list
                cout << "\t\t\tClients\t\tEnter one of the following commands:\n";
                cout << "\t\t\t\ta - Add new client\n\t\t\t\tu - Update existing client\n\t\t\t\tp - Print client information\n";
                
                cin >> userInput;
                switch(userInput){
                    case 'a':                                                                                           //Adds new clients
                        cout << "Add new client:\tInput name, address, and sale:\n";
                        cin >> name;
                        cin >> address;
                        cin >> sale;
                            
                        clientObj.AddNewClients(name, address, sale, clientName, clientAddress, clientSale);
                        break;
                        
                    case 'u':                                                                                           //Updates existing client
                        cout << "Update exisiting client\tInput name, address, and sale: ";
                        cin >> name;
                        cin >> address;
                        cin >> sale;
                            
                        clientObj.UpdateClientInfo(name, address, sale, clientName, clientAddress, clientSale);
                        break;
                        
                    case 'p':                                                                                           //Prints client information
                        clientObj.PrintClientInfo(clientName, clientAddress, clientSale);
                        break;
                        
                    default:
                        break;
                }
                break;
            
                
            case 'r':       //Sales Representatives list
                cout << "\t\t\tSales Representatives\t\tEnter one of the following commands:\n";
                cout << "\t\t\t\ta - Add new Sales Rep.\n\t\t\t\tu - Update existing Sales Rep.\n\t\t\t\tc - Calculate bonus\n";
                cin >> userInput;
                switch(userInput){
                    case 'a':                                                                                           //Adds new Sales Rep.
                        cout << "Input name, address, and sale: ";
                        cin >> name;
                        cin >> address;
                        cin >> sale;
                        
                        salesRepObj.AddSalesRep(name, address, sale, salesRepName, salesRepAddress, salesRepSale);
                        break;
                        
                    case 'u':                                                                                           //Updates existing Sales Rep.
                        cout << "Input name, address, and sale: ";
                        cin >> name;
                        cin >> address;
                        cin >> sale;
                        
                        salesRepObj.UpdateSalesRep(name, address, sale, salesRepName, salesRepAddress, salesRepSale);
                        break;
                        
                    case 'c':                                                                                           //Calculates bonus

                        salesRepObj.CalculateBonus(bonus);
                        break;
                }
                break;
                
                
            case 'p':       //Product and Services list
                cout << "\t\t\tProduct and Services\t\tEnter one of the following commands:\n";
                cout << "\t\t\t\ta - Add new product\n\t\t\t\tu - Update existing product\n\t\t\t\tp - Print products\n";
                cin >> userInput;
                switch(userInput){
                    case 'a':
                        cout << "Input product and description: ";
                        cin >> product;
                        getline(cin, description);
                        
                        prodServObj.AddNewService(product, description, productVector, descriptionVector, priceVector);
                        break;
                        
                    case 'u':
                        cout << "Input product and description: ";
                        cin >> product;
                        getline(cin, description);
                        
                        prodServObj.UpdateService(product, description, productVector, descriptionVector);
                        break;
                        
                    case 'l':
                        prodServObj.ListServices(productVector, descriptionVector);
                        break;
                        
                    case 'p':
                        prodServObj.PrintServiceReport(productVector, descriptionVector);
                        break;
                }
                break;
                
                
            case 's':       //Sales list
                cout << "\t\t\tEnter one of the following commands:\n";
                cout << "\t\t\t\tu - Update existing sale\n\t\t\t\tc - Print client sales\n\t\t\t\tp - Print sales";
                cin >> userInput;
                switch(userInput){
                    case 'u':
                        salesObj.UpdateSales(sales);
                        break;
                        
                    case 'c':
                        cout << "Input name, address, and sale: ";
                        salesObj.PrintClientSales(sales);
                        break;
                        
                    case 'p':
                        salesObj.PrintSales(sales);
                        break;
                }
                break;
                
                
            case 'q':
                cout << "Closing program\n";
                break;
            
            default:
                cout << "Not an input\n";
            
        }
        cout << endl;
    }
    clientObj.SaveToFile(name, address, sale, clientName, clientAddress, clientSale);
    salesRepObj.SaveToFile(name, address, sale, salesRepName, salesRepAddress, salesRepSale);
    prodServObj.SaveToFile(product, description, productVector, descriptionVector);
    salesObj.SaveToFile(sales);
    return 0;
}
