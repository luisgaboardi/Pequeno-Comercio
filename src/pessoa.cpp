#include "pessoa.hpp"

Pessoa::Pessoa()
{
	set_nome("");
	set_email("");
	set_cpf("");
}

Pessoa::Pessoa(string nome, string cpf, string email)
{
	set_nome(nome);
	set_cpf(cpf);
	set_email(email);
}

Pessoa::~Pessoa(){
}

string Pessoa::get_nome(){
	return this->nome;
}
void Pessoa::set_nome(string nome){
	if(nome.size() < 50)
		this->nome = nome;
}

string Pessoa::get_cpf(){
	return this->cpf;
}
void Pessoa::set_cpf(string cpf){
	if(cpf.size() < 12)
		this->cpf = cpf;
}

string Pessoa::get_email(){
	return this->email;
}
void Pessoa::set_email(string email){
	this->email = email;
}

void Pessoa::imprime_dados(){}
