#ifndef __AE_H__
#define __AE_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

struct User {
    string name;
    int gender;
    int age;
    string phone;
    string address;
};


void addUser();

void showUser();

void deleteUser();

User *getUser(string name);

void modifyUser();

void deleteAll();

void quitSystem();

void findUser();

void index();

#endif




