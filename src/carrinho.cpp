#include "carrinho.hpp"

Carrinho::Carrinho()
{
	set_valorTotal(0.0f);
}

Carrinho::~Carrinho(){}

float Carrinho::get_valorTotal(){
	return valorTotal;
}
void Carrinho::set_valorTotal(float valorTotal){
	if(valorTotal > 0.0)
		this->valorTotal = valorTotal;
}
		
void Carrinho::imprime_dados()
{
	if(!item.empty())
	{
		cout << "[Carrinho]" << endl << endl;
		for(pair<Produto*, int> p : item)
		{
			cout << "Nome: " << p.first->get_nome() << endl;
			cout << "Categoria(s): ";
			for(unsigned int i = 0; i < p.first->get_categoria().size(); ++i)
			{
				cout << p.first->get_categoria()[i];
				if(i != p.first->get_categoria().size() - 1)
					cout << ", ";
			}
			cout << endl << "Quantidade: " << p.second << endl;
			cout << "Valor: R$ " << p.second * p.first->get_valor() << endl;
			cout << "-----------------------------" << endl;
		}
	}
}