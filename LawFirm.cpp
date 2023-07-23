#include "LawFirm.h"

//ctor that create address by user input and put null in the people array
LawFirm:: LawFirm() {
    string street, city;
    int postalCode;
    cout << "please enter the name of the law firm: ";
    cin >> name;
    cout << "please enter the address" << endl;
    cout << "city: ";
    cin >> city;
    cout << "street: ";
    cin >> street;
    cout << "postalCode: ";
    postalCode = getInt();
    address = new Address (city,street,postalCode);
    people = NULL;
    peopleLength = 0;
}

//dtor
LawFirm:: ~LawFirm(){
    delete address;
    if(people != NULL) {
        for (int i = 0; i < peopleLength; ++i) {
            delete people[i];
        }
    }
    delete [] people;
}

// show the user the options he can choose and send him to the write method
void LawFirm:: Menu (){
    bool flag = true;
    int option = -1;
    while(flag){
        cout<<endl << "1. add client" << endl;
        cout<<"2. add lawyer" << endl;
        cout<<"3. choose lawyer for client" << endl;
        cout<<"4. print lawyer" << endl;
        cout<<"5. print active activeClients" << endl;
        cout<<"6. print lawyer max activeClients" << endl;
        cout<<"7. close client case" << endl;
        cout<<"8. exist" << endl;
        cout<<"Please enter you selection: ";
        option = getInt();
        while (option<1 || option>8){
            cout<<"please choose a number between 1 to 8: ";
            option = getInt();
        }
        cout<<endl;
        switch (option) {
            case 1:
                addClient ();
                break;
            case 2:
                addLawyer();
                break;
            case 3:
                chooseLawyerForClient ();
                break;
            case 4:
                printLawyers();
                break;
            case 5:
                printActiveClients();
                break;
            case 6:
                printMaxActiveClientsLawyer();
                break;
            case 7:
                closeClientCase();
                break;
            case 8:
                flag = false;
                break;
        }
    }
}

// adding client to the people array by user input
void LawFirm:: addClient (){
    //get client details
    string name;
    int idNumber;
    cout << "please enter client name: ";
    cin >> name;
    cout << "please enter client id number: ";
    idNumber = getInt();
    bool flag = true;
    Client* newClient = new Client (name,idNumber);
    //check if already exist in the array
    for (int i = 0; i < peopleLength && flag; i++) {
        if((*(people+i))->operator==(*newClient)){
            flag = false;
        }
    }
    if(flag){
        // adding the client to the people array
        Person** newPeople = new Person* [peopleLength+1];
        for (int i = 0; i < peopleLength && flag; i++) {
            (*(newPeople+i)) = (*(people+i));
        }
        newPeople [peopleLength] = newClient;
        delete [] people;
        people = newPeople;
        peopleLength++;
    }else{
        //delete client and send a message
        delete newClient;
        cout<< "this client already exist in the list"<<endl;
    }
}

// adding lawyer to the people array by user input
void LawFirm:: addLawyer(){
    //get lawyer details
    string name;
    int idNumber, seniority;
    cout << "please enter lawyer name: ";
    cin >> name;
    cout << "please enter lawyer id number: ";
    idNumber = getInt();
    cout << "please enter lawyer seniority: ";
    seniority = getInt();
    Lawyer* newLawyer = new Lawyer (name,idNumber,seniority);
    bool flag = true;
    //check if already exist in the array
    for (int i = 0; i < peopleLength && flag; i++) {
        if((*(people+i))->operator==(*newLawyer)){
            flag = false;
        }
    }
    if(flag){
        // adding the lawyer to the people array
        Person** newPeople = new Person* [peopleLength+1];
        for (int i = 0; i < peopleLength && flag; i++) {
            (*(newPeople+i)) = (*(people+i));
        }
        newPeople [peopleLength] = newLawyer;
        delete [] people;
        people = newPeople;
        peopleLength++;
    }else{
        //delete lawyer and send a message
        delete newLawyer;
        cout<< "this lawyer already exist in the list"<<endl;
    }
}

// choose lawyer for client by selecting from the people array
void LawFirm:: chooseLawyerForClient (){
    int counter = 1, indexClient, indexLawyer;
    // print the not active client by name and id
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Client))
            if (!((Client &) (*people[i])).getActiveClient()) {
                cout<<counter<<". " ;
                (*(people + i))->printDetail();
                counter++;
            }
    }
    // if there is no not active client print a message
    if (counter==1){
        cout<< "There is no client without lawyer"<<endl;
        return;
    }
    //user selecting the client he wants by index
    cout<<"please choose client from the list by index: ";
    indexClient = getInt();
    while (indexClient<1 || indexClient>counter){
        cout<<"please enter a number between 1 to "<< counter<< ": ";
        indexClient = getInt();
    }
    cout<<endl;

    counter = 1;
    // print the lawyers by name and id
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Lawyer)) {
            cout<<counter<<". " ;
            (*(people + i))->Person::printDetail();
            counter++;
        }
    }
    // if there is no lawyers print a message
    if (counter==1){
        cout<< "There is no lawyers in the list"<<endl;
        return;
    }
    //user selecting the lawyers he wants by index
    cout<<"please choose lawyer from the list by index: ";
    indexLawyer = getInt();
    while (indexLawyer<1 || indexLawyer>counter){
        cout<<"please enter a number between 1 to "<< counter<< ": ";
        indexLawyer = getInt();
    }
    // get the client index location in the people array
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Client)) {
            if (!((Client &) (*people[i])).getActiveClient()) {
                indexClient--;
            }
            if (indexClient == 0) {
                indexClient = i;
                break;
            }
        }
    }

    // get the lawyer index location in the people array
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Lawyer)) {
            indexLawyer--;
            if (indexLawyer == 0) {
                indexLawyer = i;
                break;
            }
        }
    }
    // call the method in lawyer class that add client to the active client array
    ((Lawyer&)(*people[indexLawyer]))+=((Client&)(*people[indexClient]));
    //change the client variable activeClient to true
    ((Client&)(*people[indexClient])).setActiveClient(true);
}

// print lawyers
void LawFirm:: printLawyers()const{
    bool flag = true;
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Lawyer)) {
            flag = false;
            (*(people + i))->printDetail();
            cout <<"salary: " << ((Lawyer&)(*people[i])).salary()<<endl<<endl;
        }
    }
    if(flag) {
        cout << "there is no lawyers in the array"<<endl;
    }
}

//print active clients
void LawFirm:: printActiveClients()const{
    bool flag = true;
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Client))
            if (((Client &) (*people[i])).getActiveClient()) {
                flag = false;
                (*(people + i))->printDetail();
            }
    }
    if(flag) {
        cout << "there is no activeClients in the array"<<endl;
    }
}

// print all the lawyers with the max number of active clients
void LawFirm:: printMaxActiveClientsLawyer()const{
    int max = 0;
    // check what is the max number of client from all the lawyers in the people array
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Lawyer))
            if(((Lawyer&)(*people[i])).getClientsNum() > max)
                max = ((Lawyer&)(*people[i])).getClientsNum();
    }
    // if there is no lawyers with clients print a message
    if(max == 0){
        cout<<"there is no Lawyer with client in the array"<<endl;
        return;
    }

    //print the lawyers with the max number of clients
    for (int i = 0; i < peopleLength; i++) {
        if (typeid(*people[i]) == typeid(Lawyer))
            if(((Lawyer&)(*people[i])).getClientsNum() == max) {
                (*people[i]).printDetail();
                cout<<endl;
            }

    }
}

// method that close client case, the method get the client ID and the lawyer ID by user input
void LawFirm:: closeClientCase(){
    if(people == NULL){
        cout<<"there is no people in the array"<<endl;
        return;
    }
    int idNumberClient, idNumberLawyer;
    cout << "please enter the client id number: ";
    idNumberClient = getInt();
    cout << "please enter the lawyer of this client id number: ";
    idNumberLawyer = getInt();
    // check if there is lawyer with this id number and if there is call closeClientCase from lawyer class
    bool flagMethod = true, flagLawyer = true;
    for (int i = 0; i < peopleLength && flagLawyer; i++) {
        if (typeid(*people[i]) == typeid(Lawyer))
            if((*people[i]).getIdNumber() == idNumberLawyer) {
                flagMethod = ((Lawyer&)(*people[i])).closeClientCase(idNumberClient);
                flagLawyer = false;
            }
    }
    //update the activeClient variable to false;
    if(flagMethod) {
        for (int i = 0; i < peopleLength; i++) {
            if (typeid(*people[i]) == typeid(Client))
                if ((*people[i]).getIdNumber() == idNumberClient) {
                    ((Client &) (*people[i])).setActiveClient(false);
                }
        }
        return;
    }
    if(flagLawyer)
        cout<< "there is no lawyer with this id number"<<endl;
}

//method that return int by user input
int LawFirm:: getInt(){
    int input = 0;
    cin>>input;
    while (!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<< "plaese enter only digits: ";
        cin>>input;
    }
    return input;
}