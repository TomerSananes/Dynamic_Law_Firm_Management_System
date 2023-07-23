#pragma
#include "Client.h"

class Lawyer: public Person{
private:
    int seniority;
    //client pointer array
    Client** activeClients;
    int activeClientsNum;
    //client pointer array
    Client** pastClients;
    int pastClientsNum;
public:
    //ctor
    Lawyer(string name = "unknown",  int idNumber = 111111111, int seniority = 0);
    //copy ctor
    Lawyer(Lawyer& other);
    //implement dtor
    virtual ~Lawyer();
    // virtual print method
    virtual void printDetail()const;
    // calculating the lawyer salary
    int salary()const;
    //method that close case for the client
    bool closeClientCase(int idNumber);
    // operator +=
    void operator+=(Client & tempClient);
    //get
    int getClientsNum()const;
};

