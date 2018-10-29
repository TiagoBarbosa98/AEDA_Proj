/*
 * Farmacia.h
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#ifndef FARMACIA_H_
#define FARMACIA_H_

#include "Funcionario.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Farmacia {
	string nome;
	string morada;
	string gerente;
	vector <Funcionario*> funcionarios;
public:
	Farmacia(string nome,string morada,string gerente);
	virtual ~Farmacia();
	string getNome();
	string getMorada();
	string getGerente();
	vector <Funcionario*> getFuncionarios();
	void addFuncionario(Funcionario &funcionario);
};

#endif /* FARMACIA_H_ */
//receitas que aviam
//vendas
//funcionários
//clientes
