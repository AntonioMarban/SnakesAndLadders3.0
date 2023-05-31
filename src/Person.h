#include <iostream>
using namespace std;
#pragma once

class Person {
    string name;
public:
    Person() {};
    Person(const string &name) : name(name){};
    ~Person() {};
    // Getter
    string getName();
    // Setters
    void setName(string);
};

string Person::getName() {
    return name;
}
void Person::setName(string _name) {
    name = _name;
}

