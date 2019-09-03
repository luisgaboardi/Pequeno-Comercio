#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_

#include <vector>
#include "pessoa.hpp"
#include "carrinho.hpp"
#include "produto.hpp"

class Cliente : public Pessoa
{
	private:
		vector<Produto*> historico;
		bool ativo;
		Carrinho *carrinho;
	
	public:
		Cliente();
		Cliente(string nome, string cpf, string email, string telefone, string endereco, bool ativo);
		~Cliente();
		
		bool get_ativo();
		void set_ativo(bool ativo);
		
		void imprime_dados();
};

#endif