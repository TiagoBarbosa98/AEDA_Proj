/*
 * Produto.cpp
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#include "Produto.h"

Produto::Produto(string codigo,string nome,float preco,string descricao){
	this->codigo=codigo;
	this->descricao=descricao;
	this->nome=nome;
	this->preco=preco;

}

Medicamento::Medicamento(bool receita) {
	this->receita=receita;

}

MedicamentoComReceita::MedicamentoComReceita(float taxa){
this->taxa=taxa;
}


