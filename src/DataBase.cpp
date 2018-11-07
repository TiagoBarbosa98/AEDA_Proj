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
	        openclientsFile ();
	     //   openpharmaciesFile();
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

void DataBase::addClient(){
	string n;
	string addr;
	unsigned int  contribNo;
	cout << "name: ";
	cin >> n;
	cout << "adress: ";
	cin >> addr;
	cout << "contrib number: ";
	cin >> contribNo;
	clients.push_back(Client(n, addr, contribNo));
	ofstream myfile;
	myfile.open ("clients.txt");
  myfile << n << ", "<< addr<< ", " << contribNo << endl;
  myfile.close();
}

/*   OPEN FILES  */
void DataBase::openclientsFile(){
    ifstream infich;
    char aux;
    string textLine,adress, name;
    unsigned int contribNo;

    infich.open(clientsFile);

    if (!infich.fail()) {
        while (getline(infich, textLine)) {

            istringstream cardStream (textLine);

            cardStream >> name >> aux;

            name = readComplexString(cardStream, ';');

            cardStream >> adress >> aux;

            adress = readComplexString(cardStream, ';');

			cardStream >> contribNo >> aux;

			 adress = readComplexString(cardStream, '\n');


        }
    } else {
        throw ErrorOpeningFile(clientsFile);
    }
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
