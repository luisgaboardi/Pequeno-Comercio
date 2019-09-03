#include "carrinho.hpp"

Carrinho::Carrinho()
{
	set_valorTotal("");
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
}