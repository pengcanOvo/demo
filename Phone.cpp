//
// Created by 54326 on 2021/5/23.
//

#include <iostream>
#include "Phone.h"

Phone::~Phone() {
    cout<<"phone ����������"<<endl;
}

Phone::Phone(const string &name) : name(name) {
    cout<<"phone�Ĺ��캯��"<<endl;
}

