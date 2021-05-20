//
// Created by 54326 on 2021/5/20.
//
#include "demo.h"
#include "global.h"

User creatUser();

void printUser(User user);

void addUser() {
    User user = creatUser();

    users[userCount++] = user;
    index();
}

User creatUser() {
    User user;
    cout << "请输入用户名：";
    cin >> user.name;

    cout << "请输入用户性别";
    string temp;
    cin >> temp;
    if (temp == "男") {
        user.gender = 0;
    } else if (temp == "女") {
        user.gender = 1;
    } else {
        cout << "请输入正确的性别";
    }

    cout << "请输入年龄";
    cin >> user.age;

    cout << "请输入电话";
    cin >> user.phone;

    cout << "请输入地址";
    cin >> user.address;
    return user;
}

void showUser() {
    for (int i = 0; i < userCount; ++i) {
        User temp = users[i];
        printUser(temp);

    }
    index();
}

void printUser(User user) {
    cout << "姓名：" << user.name << endl;

    int temp = user.gender;
    string gender;
    gender = temp ? "女" : "男";
    cout << "性别：" << gender << endl;

    cout << "年龄" << user.age << endl;
    cout << "电话：" << user.phone << endl;
    cout << "地址：" << user.address << endl;
}

void deleteUser() {
    string name;
    cout << "请输入用户名：";
    cin >> name;
    User *deleteUser = getUser(name);
    User temp;
    *deleteUser = temp;
    userCount--;

    index();
}

User *getUser(string name) {
    User * user;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].name == name) {
            user = &users[i];
            break;
        }
    }
    return user;
}

void modifyUser() {
    string name;
    cout << "请输入用户名：";
    cin >> name;
    User *modifyUser = getUser(name);
    User user = creatUser();
    *modifyUser = user;
    index();
}

void deleteAll() {
    User temp[1000];
    user = temp;
    userCount = 0;
    index();
}

void findUser() {
    string name;
    cout << "请输入用户名：";
    cin >> name;
    User * temp = getUser(name);
    printUser(*temp);
    index();
}


void quitSystem() {
    cout<<"欢迎继续使用";
}

void index() {
    int temp;
    cout << "请选择需要的功能：";
    cin >> temp;
    switch (temp) {
        case 1:
            addUser();
            break;
        case 2:
            showUser();
            break;
        case 3:
            deleteUser();
            break;
        case 4:
            findUser();
            break;
        case 5:
            modifyUser();
            break;
        case 6:
            deleteAll();
            break;
        case 0:
            quitSystem();
            break;
        default:
            cout << "请正确输入";
            index();
    }
}
