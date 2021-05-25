//
// Created by 54326 on 2021/5/23.
//

#include "Person.h"
#include "Phone.h"



Person::~Person() {

}

ostream &operator<<(ostream &os, const Person &person) {
    os << "name: " << person.name << " age: " << person.age;
    return os;
}



//Person::Person(const string &name) : name(name) {
//    cout<<"person 构造函数调用"<<endl;
//}
