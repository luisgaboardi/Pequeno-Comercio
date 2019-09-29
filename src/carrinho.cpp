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

int Carrinho::confere_carrinho(vector<pair<string, int> > &historico)
{
	system("clear");
	
	int flagPossivel = 1;
	int unico = 0;
	int i = 0;
	
	for(pair<Produto *, int> p : item)
	{
		if(p.first->get_quantidade() < 0){
			flagPossivel = 0;
			if(unico == 0) {
				cout << "Não foi possível concluir esta compra." << endl << endl;
				unico = 1;
			}
			cout << "O produto " << p.first->get_nome() << " não possui " << p.second << " unidades." << endl;
			cout << "Unidades disponíveis: " << p.first->get_quantidade() + p.second << endl;
		}
		
		i++;
	}
	if(flagPossivel == 0)
	{
		for(pair<Produto *, int> p : item)
			p.first->set_quantidade(p.first->get_quantidade() + p.second);
		while (historico.empty())
			historico.pop_back();
			
	}
	
	return flagPossivel;
}

void Carrinho::imprime_dados(bool socio)
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
		if(socio){
			set_valorTotal(get_valorTotal()*0.85);
		}
		set_valorTotal(0.0f);

		cout << "Valor Total: R$ " << get_valorTotal() << endl;
		
		set_valorTotal(0.0f);
	}
}