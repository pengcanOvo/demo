//
// Created by 54326 on 2021/5/24.
//
#include "Calculator.h"

class Add : public Calculator {
public:
    Add(int num_1, int num_2) {
        this->num_1 = num_1;
        this->num_2 = num_2;
    }


    int operation() override {
        return num_1 + num_2;
    }
};

class Jian : public Calculator {
public:
    int operation() override {
        return num_1 - num_2;
    }

    Jian(int num_1, int num_2) {
        this->num_1 = num_1;
        this->num_2 = num_2;
    }
};

class Chen : public Calculator {
public:
    int operation() override {
        return num_1 * num_2;
    }

    Chen(int num_1, int num_2) {
        this->num_1 = num_1;
        this->num_2 = num_2;
    }
};

class Chu : public Calculator {
public:
    int operation() override {
        return num_1 / num_2;
    }

    Chu(int num_1, int num_2) {
        this->num_1 = num_1;
        this->num_2 = num_2;
    }
};

int main() {
    fstream fs;
    fs.open("test.txt", ios::in);
    string temp;
    fs.read()
    while (getline(fs,temp)){
        cout<<temp;
    }

    fs.close();
}