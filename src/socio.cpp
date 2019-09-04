#include "socio.hpp"

Socio::Socio()
{
	set_fidelidade(0.0);
	this->desconto = 0.15f;
}

Socio::Socio(string nome, string cpf, string email, float fidelidade, float desconto) : Cliente(nome, cpf, email)
{
	set_fidelidade(fidelidade);
	if(desconto >= 0.0)
		this->desconto = desconto;
}

Socio::~Socio(){}
		
float Socio::get_fidelidade(){
	return fidelidade;
}
void Socio::set_fidelidade(float fidelidade){
	if(fidelidade >= 0 && fidelidade >= this->fidelidade)
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
	cout << "Fidelidade: " << get_fidelidade() << endl << endl;
}