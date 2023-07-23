#include "Person.h"

//ctor with all the parameters and default option
Person:: Person(string name,  int idNumber){
    this->name = name;
    this->idNumber = idNumber;
}

//dtor
Person:: ~Person(){}

// virtual method that print the object
void Person::printDetail()const{
    cout<< "name: " << name << ", "<< "ID number: "<< idNumber<< endl;
}

//operator == check if the id number is the same
bool Person:: operator==(Person const& other)const{
    if(idNumber == other.idNumber)
        return true;
    return false;
}

// get
int Person:: getIdNumber()const{
    return idNumber;
}