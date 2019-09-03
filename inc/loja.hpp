#ifndef LOJA_HPP_
#define LOJA_HPP_

#include "pessoa.hpp"
#include "produto.hpp"

class Loja
{
	private:
		float valorNoCaixa;
	
	public:
		Loja();
		~Loja();
	
		vector<Produto*> produtos;
		vector<Pessoa*> envolvidos;
		
		float get_valorNoCaixa();
		void set_valorNoCaixa(float valorNoCaixa);
};


#endif