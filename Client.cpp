#include "Client.h"

//ctor with 2 the parameters and default option
Client:: Client(string name,  int idNumber): Person(name,idNumber){
    this->activeClient = false;
}

// implement dtor
Client:: ~Client(){}

//set
void Client:: setActiveClient(bool temp){
    activeClient = temp;
}

//get
bool Client:: getActiveClient()const{
    return activeClient;
}