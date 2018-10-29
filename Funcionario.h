/*
 * Funcionario.h
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include "Farmacia.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Funcionario {
	string nome;
	string morada;
	int nContribuinte;
	float salario;
	Farmacia farmacia;
	string cargo;
public:
	Funcionario(string nome,string morada,int nContribuinte,float salario,Farmacia farmacia,string cargo);
	virtual ~Funcionario();
	string getNome();
	string getMorada();
	int getNContribuinte();
	float getSalario();
	Farmacia getFarmacia();
	string getCargo();
};

#endif /* FUNCIONARIO_H_ */
