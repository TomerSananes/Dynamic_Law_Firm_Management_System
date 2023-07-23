#pragma
#include <string>
#include "iostream"
using namespace std;

class Address {
private:
    string street;
    string city;
    int postalCode;
public:
    // ctor
    Address(string street ="0" , string city="0", int postalCode=0);
    //dtor
    ~Address();
    // print method
    void printAddress()const;
};

