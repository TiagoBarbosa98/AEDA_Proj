/*
 * Receita.h
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#ifndef RECEITA_H_
#define RECEITA_H_

#include "Cliente.h"
#include "Produto.h"

class Receita {
	int numero;
	Cliente cliente;
	string medico;
	vector<Produto> produtos;
public:
	Receita(int numero,Cliente cliente,string medico,vector<string> produtos);
	virtual ~Receita();
	int getNumero();
	Cliente getCliente();
	string getMedico();
	vector<Produto> getProdutos();
	void addProduto(Produto produto);
};

#endif /* RECEITA_H_ */
