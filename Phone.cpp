//
// Created by 54326 on 2021/5/23.
//

#include <iostream>
#include "Phone.h"

Phone::~Phone() {
    cout<<"phone 的析构函数"<<endl;
}

Phone::Phone(const string &name) : name(name) {
    cout<<"phone的构造函数"<<endl;
}

