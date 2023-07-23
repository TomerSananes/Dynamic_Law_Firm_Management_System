#pragma
#include <string>
#include "iostream"
using namespace std;

class Person {
private:
    string name;
    int idNumber;
public:
    //ctor
    Person(string name = "unknown",  int idNumber = 111111111);
    //abstract dtor
    virtual~Person()=0;
    // virtual print method
    virtual void printDetail() const;
    //operator ==
    bool operator==(const Person& other)const;
    int getIdNumber()const;
};


