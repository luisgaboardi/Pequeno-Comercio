#ifndef LOJA_HPP_
#define LOJA_HPP_

#include "funcionario.hpp"
#include "cliente.hpp"
#include "produto.hpp"
    
#include <string>

class Loja
{
	private:
		
	public:
		Loja();
		~Loja();
		
		vector<Produto*> produtos;
		vector<Funcionario*> funcionarios;
		vector<Cliente*> clientes;
		
		void identifica_funcionario();
		Cliente *confere_cliente();
    	Cliente *confere_cliente(long long int cpf);
		long long int cadastrar_cliente();
		void imprime_clientes();
		void imprime_funcionarios();
		Produto* checa_produto(string nome);
		void recomendacao(Cliente *c);

};


#endif