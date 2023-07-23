#pragma
#include "Person.h"

class Client : public Person {
private:
    bool activeClient;
public:
    //ctor
   Client(string name = "unknown",  int idNumber = 111111111);
    //implement dtor
   virtual ~Client();
   //set
   void setActiveClient(bool temp);
   //get
   bool getActiveClient()const;
};
