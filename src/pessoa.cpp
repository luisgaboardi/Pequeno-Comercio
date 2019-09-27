#include "pessoa.hpp"

Pessoa::Pessoa()
{
	set_nome("");
	set_email("");
	set_cpf(0);
}

Pessoa::Pessoa(string nome, long long int cpf, string email)
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

long long int Pessoa::get_cpf(){
	return this->cpf;
}
void Pessoa::set_cpf(long long int cpf){
	if(cpf != 0)
		this->cpf = cpf;
}

string Pessoa::get_email(){
	return this->email;
}
void Pessoa::set_email(string email){
	this->email = email;
}

void Pessoa::imprime_dados(){}
