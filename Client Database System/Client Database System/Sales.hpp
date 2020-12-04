//
//  Sales.hpp
//  Client Database System
//
//  Created by Videsh Bridgelal on 11/16/20.
//  Copyright © 2020 Team 5. All rights reserved.
//

#ifndef Sales_h
#define Sales_h

#include <stdio.h>
#include<string>
#include <vector>
#include "BaseClass.h"
#include "Product and Services.hpp"

using namespace std;

class Sales{
    public:
        Sales();
        void ReadFromFile(vector<string>& salesVector);
        void PrintSales(vector<string>& salesVector);
        void PrintClientSales(vector<string>& salesVector);
        void UpdateSales(vector<string>& salesVector);
        void SaveToFile(vector<string>& salesVector);
        
    private:
        vector<string> salesVector;
};

#endif /* Sales_hpp */
