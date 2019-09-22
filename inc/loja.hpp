#ifndef LOJA_HPP_
#define LOJA_HPP_

#include "funcionario.hpp"
#include "cliente.hpp"
#include "produto.hpp"

class Loja
{
	private:
		float valorNoCaixa;
		
	public:
		Loja();
		~Loja();
		
		vector<Produto*> produtos;
		vector<Funcionario*> funcionarios;
		vector<Cliente*> clientes;
		
		float get_valorNoCaixa();
		void set_valorNoCaixa(float valorNoCaixa);
		
		void identifica_funcionario();
		Cliente *confere_cliente();
		void cadastrar_cliente();
		void imprime_clientes();
		void imprime_funcionarios();
};


#endif