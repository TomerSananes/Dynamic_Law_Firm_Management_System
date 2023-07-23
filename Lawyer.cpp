#include "Lawyer.h"

//ctor with 3 parameters and default option
Lawyer:: Lawyer(string name,  int idNumber, int seniority): Person(name,idNumber){
    this->seniority = seniority;
    activeClients = new Client * [0];
    activeClientsNum = 0;
    pastClients = new Client *  [0];
    pastClientsNum = 0;
}

//copy ctor
Lawyer:: Lawyer(Lawyer& other){
    seniority = other.seniority;
    activeClientsNum = other.activeClientsNum;
    pastClientsNum = other.pastClientsNum;
    activeClients = new Client * [activeClientsNum];
    for(int i = 0 ; i < activeClientsNum; i++){
        //to create new client
        activeClients[i] = new Client (*other.activeClients[i]);
    }
    pastClients = new Client *  [pastClientsNum];
    for(int i = 0 ; i <pastClientsNum; i++){
        //to create new client
        pastClients[i] = new Client (*other.activeClients[i]);
    }
}

//implement dtor
Lawyer:: ~Lawyer(){
    for(int i = 0 ; i < activeClientsNum; i++){
        delete activeClients[i];
    }
    delete [] activeClients;
    for(int i = 0 ; i <pastClientsNum; i++){
        delete pastClients[i];
    }
    delete [] pastClients;
}

//virtual print method
void Lawyer:: printDetail()const{
    // print person
    Person:: printDetail();
    //print active clients if there are
    if(activeClientsNum == 0){
        cout<< "there is no client for this lawyer"<<endl;
        return;
    }
    cout << "the lawyer active clients:"<< endl;
    for(int i = 0 ; i < activeClientsNum; i++){
        cout<<"  " << i+1 << ". ";
        activeClients[i]->printDetail();
    }
}

//calculating the lawyer salary
int Lawyer:: salary() const{
    return (activeClientsNum * 1000 + seniority * 500);
}

/* close client case method
 * get client ID and check if there is client with this ID in the employee active client array
 * if there is, delete the client from the active client array, put the client is the past clients array,
 * and change client activeClient variable to false
 * */
bool Lawyer:: closeClientCase(int idNumber){
    //check if there is a client with this id number
    int index = -1;
    bool flag = true;
    for (int i = 0; i < activeClientsNum && flag; i++) {
        if((*(activeClients + i))->getIdNumber() == idNumber){
            index = i;
            flag = false;
        }
    }
    if(index == -1){
        cout<< "The client with this ID number is not exist in the active activeClients of this lawyer";
        return false;
    }
    // put the client in the past clients array
    Client** newPastClients = new Client * [pastClientsNum+1];
    for (int i = 0; i < pastClientsNum; i++) {
        *(newPastClients+i) = *(pastClients+i);
    }
    *(newPastClients+pastClientsNum)=*(activeClients + index);
    //change client activeClient variable to false
    (*(activeClients + index))->setActiveClient(false);
    delete [] pastClients;
    pastClients = newPastClients;
    pastClientsNum++;

    // delete the client from the active client array
    Client** newClients = new Client * [activeClientsNum - 1];
    for (int i = 0; i < activeClientsNum; i++) {
        if((*(activeClients + i))->getIdNumber() != idNumber){
            *(newClients+i) = *(activeClients + i);
        }
    }
    delete [] activeClients;
    activeClients = newClients;
    activeClientsNum--;
    return true;
}

//get client and add it to the active clients array
void Lawyer:: operator+=(Client & tempClient){
    Client** newClients = new Client * [activeClientsNum + 1];
    for (int i = 0; i < activeClientsNum; i++) {
        *(newClients+i) = *(activeClients + i);
    }
    *(newClients + activeClientsNum) = new Client (tempClient);
    delete [] activeClients;
    activeClients = newClients;
    activeClientsNum++;
}

//get
int Lawyer:: getClientsNum()const{
    return activeClientsNum;
}

