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
    cout << "�������û�����";
    cin >> user.name;

    cout << "�������û��Ա�";
    string temp;
    cin >> temp;
    if (temp == "��") {
        user.gender = 0;
    } else if (temp == "Ů") {
        user.gender = 1;
    } else {
        cout << "��������ȷ���Ա�";
    }

    cout << "����������";
    cin >> user.age;

    cout << "������绰";
    cin >> user.phone;

    cout << "�������ַ";
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
    cout << "������" << user.name << endl;

    int temp = user.gender;
    string gender;
    gender = temp ? "Ů" : "��";
    cout << "�Ա�" << gender << endl;

    cout << "����" << user.age << endl;
    cout << "�绰��" << user.phone << endl;
    cout << "��ַ��" << user.address << endl;
}

void deleteUser() {
    string name;
    cout << "�������û�����";
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
    cout << "�������û�����";
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
    cout << "�������û�����";
    cin >> name;
    User * temp = getUser(name);
    printUser(*temp);
    index();
}


void quitSystem() {
    cout<<"��ӭ����ʹ��";
}

void index() {
    int temp;
    cout << "��ѡ����Ҫ�Ĺ��ܣ�";
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
            cout << "����ȷ����";
            index();
    }
}
