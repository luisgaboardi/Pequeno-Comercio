#ifndef CARRINHO_HPP_
#define CARRINHO_HPP_

#include "produto.hpp"

class Carrinho
{
	private:
		float valorTotal;
	
	public:

		vector< pair<Produto*, int> > item; // Produto no carrinho e sua quantidade

		Carrinho();
		~Carrinho();
		
		float get_valorTotal();
		void set_valorTotal(float valorTotal);
        int confere_carrinho(vector<pair<string, int> > &historico);

		void add_item(Produto *nome, int qtd, vector<Produto*> lista);
		void imprime_dados(bool socio);
};

#endif