#include "socio.hpp"

Socio::Socio()
{
	this->fidelidade = 0;
	this->desconto = 0.15f;
}

Socio::~Socio(){}
		
float Socio::get_fidelidade(){
	return fidelidade;
}
void Socio::set_fidelidade(float fidelidade){
	this->fidelidade = fidelidade;
}

float Socio::get_desconto(){
	return desconto;
}

void Socio::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Telefone: " << get_telefone() << endl;
	cout << "Endereço: " << get_endereco() << endl;
	cout << "Ativo: " << get_ativo() << endl;
	cout << "Fidelidade: " << get_fidelidade() << endl << endl;
}