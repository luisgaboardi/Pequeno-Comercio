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
		bool socio;
	
	public:
		Cliente();
		Cliente(string nome, string cpf, string email, bool socio);
		~Cliente();
		
		bool get_socio();
		void set_socio(bool socio);
		string eh_socio();
		
		void imprime_dados();
};

#endif