#ifndef CARRINHO_HPP_
#define CARRINHO_HPP_

#include "produto.hpp"

class Carrinho
{
	private:
		float valorTotal;
		vector< pair<Produto*, int> > item; // Produto no carrinho e sua quantidade
	
	public:
		Carrinho();
		~Carrinho();
		
		float get_valorTotal();
		void set_valorTotal(float valorTotal);
		
		void imprime_dados();
		//void add_item();
};

#endif