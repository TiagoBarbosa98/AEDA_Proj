/*
 * Cliente.cpp
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#include "Cliente.h"

Cliente::Cliente(string nome,string morada,int nContribuinte,vector<string> historial) {
this->nome=nome;
this->morada=morada;
this->nContribuinte=nContribuinte;
this->historial=historial;
}


string Cliente::getNome(){
	return nome;
}
string Cliente::getMorada(){
return morada;
}
int Cliente::getNContribuinte(){
	return nContribuinte;
}
