#include "Address.h"

//ctor with all the parameters and default option
Address:: Address(string street, string city, int postalCode){
    this->street = street;
    this->city = city;
    this->postalCode = postalCode;
}

//dtor
Address:: ~Address(){}

// print address method
void Address:: printAddress()const{
    cout<< street << ", "<<city << ", "<<postalCode<< endl;
}