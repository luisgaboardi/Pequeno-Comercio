#ifndef LOJA_HPP_
#define LOJA_HPP_

#include "funcionario.hpp"
#include "cliente.hpp"
#include "produto.hpp"

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
		void cadastrar_cliente();
		void imprime_clientes();
		void imprime_funcionarios();
		Produto* checa_produto(string nome);
};


#endif