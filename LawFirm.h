#pragma
#include <string>
#include "iostream"
#include "Address.h"
#include "Lawyer.h"
using namespace std;

class LawFirm {
private:
    string name;
    Address* address;
    // pointer array of person
    Person** people;
    int peopleLength;
    //add client to the people array
    void addClient ();
    //add lawyer to the people array
    void addLawyer();
    // choosing lawyer to client by user selection
    void chooseLawyerForClient ();
    //print lawyers from the people array
    void printLawyers()const;
    //print active clients from the people array
    void printActiveClients()const;
    //print the lawyers with max client number from the people array
    void printMaxActiveClientsLawyer()const;
    //delete client from lawyer
    void closeClientCase();
    // method that return int
    int getInt();
public:
    //ctor
    LawFirm();
    //dtor
    ~LawFirm();
    void Menu ();
};

