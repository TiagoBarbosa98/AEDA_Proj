/*
 * Funcionario.cpp
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#include "Funcionario.h"

Funcionario::Funcionario(string nome,string morada,int nContribuinte,float salario,Farmacia farmacia,string cargo){
	this->nome=nome;
	this->morada=morada;
	this->nContribuinte=nContribuinte;
	this->salario=salario;
	this->farmacia=farmacia;
	this->cargo=cargo;
}

string Funcionario::getNome(){
	return nome;
}
string Funcionario::getMorada(){
	return morada;
}
int Funcionario::getNContribuinte(){
	return nContribuinte;
}
float Funcionario::getSalario(){
	return salario;
}
Farmacia Funcionario::getFarmacia(){
	return farmacia;
}
string Funcionario::getCargo(){
	return cargo;
}
