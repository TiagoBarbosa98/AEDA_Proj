#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub

}
DataBase::DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile){
	 this->productsFile = productsFile;
	    this->clientsFile = clientsFile;
	    this->pharmaciesFile = pharmaciesFile;
	    this->staffFile = staffFile;

	    try {
	      //  openproductsFile();
	        openClientsFile();
	        openpharmaciesFile();
	    //    openstaffFile();
	    } catch (ErrorOpeningFile &name) {
	        cout << "Error opening the file " << name.getFileName() << endl
	             << "No data was imported\n";

	}
}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
}

vector<Client> DataBase::getClients() const {
	return clients;
}

vector<Pharmacy> DataBase::getPharmacies() const {
	return pharmacies;
}

const vector<Product*>& DataBase::getProducts() const {
	return products;
}

vector<Receipt> DataBase::getReceipts() const {
	return receipts;
}

vector<StaffMember> DataBase::getStaff() const {
	return staff;
}

void DataBase::showAllClients(){
	for(unsigned int i = 0; i < clients.size();i++)
		cout << clients.at(i).getInfo() << endl;
}

void DataBase::showAllPharmacies(){
	for(unsigned int i = 0; i < pharmacies.size();i++)
		cout << pharmacies.at(i).getInfo()<< endl;
}

void DataBase::showAllStaff(){
	for(unsigned int i = 0; i < staff.size();i++)
		cout << staff.at(i).getInfo()<< endl;
}

void DataBase::addClient(){
	string n;
	string addr;
	unsigned int  contribNo;
	cout  << "name: ";
	cin >> n;
	cout << "adress: ";
	cin >> addr;
	cout << "contrib number: ";
	cin >> contribNo;
	Client * cli = new Client(n, addr, contribNo);
	clients.push_back(*cli);
}

void DataBase::addFarmacy(){
	string n;
	string addr;
	string m;
	cout  << "name: ";
	cin >> n;
	cout << "adress: ";
	cin >> addr;
	cout << "manager: ";
	cin >> m;
	Pharmacy * f = new Pharmacy(n, addr, m);
	pharmacies.push_back(*f);
}

/*   OPEN FILES  */
void DataBase::openClientsFile(){
    ifstream infich;
    char aux;
    string textLine,adress, name;
    unsigned int contribNo;

    infich.open(clientsFile);
    if (!infich.fail()) {

        while (getline(infich, textLine)) {

            istringstream cardStream (textLine);


            name = readComplexString(cardStream, ';');

            adress = readComplexString(cardStream, ';');

			cardStream >> contribNo >> aux;

			clients.push_back(Client(name,adress,contribNo));
        }
    }else {
        throw ErrorOpeningFile(clientsFile);
    }
}

void DataBase::openpharmaciesFile(){
    ifstream infich;
    string textLine,adress, name, manager="joao";

    infich.open(clientsFile);
    if (!infich.fail()) {

        while (getline(infich, textLine)) {

            istringstream cardStream (textLine);

            name = readComplexString(cardStream, ';');

            adress = readComplexString(cardStream, ';');

         //   manager = readComplexString(cardStream, ' ');

            pharmacies.push_back(Pharmacy(name,adress,manager));
        }
    }else {
        throw ErrorOpeningFile(pharmaciesFile);
    }
}


void DataBase::closePharmaciesFile() {
    ofstream saveData;

    saveData.open(pharmaciesFile, ios::out | ios::trunc);

    if (saveData.fail()){
        throw ErrorOpeningFile (pharmaciesFile);
    }

    for (unsigned int i = 0; i < pharmacies.size(); i++) {

         saveData << pharmacies[i].getName()<< " ; " << pharmacies[i].getAddress()<< " ; " << pharmacies[i].getManager() << endl;
         }
         saveData << endl;

    saveData.close();
}

void DataBase::closeClientsFile() {
    ofstream saveData;

    saveData.open(clientsFile, ios::out | ios::trunc);

    if (saveData.fail()){
        throw ErrorOpeningFile (clientsFile);
    }

    for (unsigned int i = 0; i < clients.size(); i++) {

         saveData << clients[i].getName()<< " ; " << clients[i].getAddress()<< " ; " << clients[i].getContribNo() << endl;
         }
         saveData << endl;

    saveData.close();
}
string DataBase::readComplexString (istringstream &ss, char separate) {
    string final, auxString;
    char aux;

    do {
        ss >> auxString;
        final += auxString;
        ss.get(aux);
        ss.get(aux);

        if (aux != separate) {
            final += " ";
            ss.unget();
        }
    } while (aux != separate);

    return final;
}
