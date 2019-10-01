#ifndef CLIENTE_HPP_
#define CLIENTE_HPP_

#include "pessoa.hpp"
#include "carrinho.hpp"
#include "produto.hpp"
#include <algorithm>

class Cliente : public Pessoa
{
	private:
		bool socio;
	
	public:
		vector < pair<string,int> > historico;
		Carrinho *carrinho;

		Cliente();
		Cliente(string nome, long long int cpf, string email, bool socio);
		~Cliente();
		
		bool get_socio();
		void set_socio(bool socio);
		string eh_socio();
    
        void historico_categoria(vector<string> categoria, int qtd);
		void imprime_dados();

};

#endif