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

void Carrinho::add_item(Produto *prod, int qtd, vector<Produto*> lista)
{
	pair <Produto *, int> compra;
	compra.first = prod;
	compra.second = qtd;
	for(Produto *p : lista)
	{
		if(p == prod){
			p->set_quantidade(p->get_quantidade() - qtd);
			break;
			// Se cancelar comprar, reverter isso tudo
		}
	}
	item.push_back(compra);

	valorTotal += compra.second * compra.first->get_valor();
}

		
void Carrinho::imprime_dados()
{
	if(!item.empty())
	{
		cout << "[Carrinho]" << endl << endl;
		for(pair<Produto*, int> p : item)
		{
			cout << "Nome: " << p.first->get_nome() << endl;
			cout << "Quantidade: " << p.second << endl;
			cout << "Valor: R$ " << p.second * p.first->get_valor() << endl;
			cout << "-----------------------" << endl;
		}

		cout << "Valor Total: R$ " << get_valorTotal() << endl;
	}
}