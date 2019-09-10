#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_

#include "pessoa.hpp"
#include "carrinho.hpp"
#include "produto.hpp"

class Cliente : public Pessoa
{
	private:
		vector<Produto*> historico;
		Carrinho *carrinho;
	
	public:
		Cliente();
		Cliente(string nome, string cpf, string email);
		~Cliente();
		
		void virtual imprime_dados();
};

#endif