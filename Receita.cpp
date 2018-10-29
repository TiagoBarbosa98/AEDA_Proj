/*
 * Receita.cpp
 *
 *  Created on: 29/10/2018
 *      Author: up201605542
 */

#include "Receita.h"

Receita::Receita(int numero,Cliente cliente,string medico,vector<string> produtos) {
	this->cliente=cliente;
	this->medico=medico;
	this->numero=numero;
	this->produtos=produtos;
}

int Receita::getNumero(){
	return numero;
}
Cliente Receita::getCliente(){
	return cliente;
}
string Receita::getMedico(){
	return medico;
}
vector<Produto> Receita::getProdutos(){
	return produtos;
}

void Receita::addProduto(Produto produto){
	produtos.push_back(produto);
}
