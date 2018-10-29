/*
 * Farmacia.cpp
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#include "Farmacia.h"

Farmacia::Farmacia(string nome,string morada,string gerente){
	this->nome=nome;
	this->morada=morada;
	this->gerente=gerente;

}

Farmacia::~Farmacia() {
	// TODO Auto-generated destructor stub
}

string Farmacia::getNome(){
	return nome;
}
string Farmacia::getMorada(){
	return morada;
}
string Farmacia::getGerente(){
	return gerente;
}
vector <Funcionario*> Farmacia::getFuncionarios(){
	return funcionarios;
}
void Farmacia::addFuncionario(Funcionario &funcionario){
	funcionarios.push_back(funcionario);
}
