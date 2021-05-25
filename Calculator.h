//
// Created by 54326 on 2021/5/24.
//

#ifndef DEMO1_CALCULATOR_H
#define DEMO1_CALCULATOR_H
#include <iostream>
#include <fstream>
using namespace std;

class Calculator {
public :
    int num_1;
    int num_2;
public:
    virtual int operation() = 0;
};


#endif //DEMO1_CALCULATOR_H
