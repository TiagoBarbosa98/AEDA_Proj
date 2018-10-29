/*
 * Cliente.h
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cliente {
	string nome;
	string morada;
	int nContribuinte;
	vector<string> historial;
public:
	Cliente(string nome,string morada,int nContribuinte,vector<string> historial);
	virtual ~Cliente();
	string getNome();
	string getMorada();
	int getNContribuinte();
	//vector<string> getHistorial(); COMPRAS
};

#endif /* CLIENTE_H_ */
