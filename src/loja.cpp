#include "loja.hpp"

#include <vector>

Loja::Loja(){}

Loja::~Loja(){}

float Loja::get_valorNoCaixa(){
	return valorNoCaixa;
}
void Loja::set_valorNoCaixa(float valorNoCaixa){
	if(valorNoCaixa >= 0.0 && valorNoCaixa >= this->valorNoCaixa)
		this->valorNoCaixa = valorNoCaixa;
}