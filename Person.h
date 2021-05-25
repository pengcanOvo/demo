//
// Created by 54326 on 2021/5/23.
//

#ifndef DEMO1_PERSON_H
#define DEMO1_PERSON_H
#include <string>
#include "Phone.h"
#include <iostream>
using namespace std;


class Person {
public :
    string name;
    int age;
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    Person operator+(Person person){
        name += person.name;
        age +=person.age;
        return *this;
    }
    virtual ~Person();

    friend ostream &operator<<(ostream &os, const Person &person);
public:
    Person& operator++(){
        this->age += 1;
        return *this;
    }

    Person operator++(int){
        Person temp = *this;
        this->age += 1;
        return temp;
    }
};


#endif //DEMO1_PERSON_H
