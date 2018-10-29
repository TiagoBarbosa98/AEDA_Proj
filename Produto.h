/*
 * Produto.h
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#ifndef PRODUTO_H_
#define PRODUTO_H_

#include <string>;
using namespace std;

class Produto {
	string codigo;
	string nome;
	float preco;
	string descricao;
public:
	Produto(string codigo,string nome,float preco,string descricao);
	virtual ~Produto();
};

class Medicamento: public Produto {
	bool receita;
public:
	Medicamento(bool receita);
	virtual ~Medicamento();
};

class MedicamentoComReceita: public Medicamento {
	float taxa;
public:
	MedicamentoComReceita(float taxa);
};


#endif /* PRODUTO_H_ */
