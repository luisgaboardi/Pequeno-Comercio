#include "pessoa.hpp"

Pessoa::Pessoa()
{
	this->nome = "";
	this->email = "";
	this->cpf = "";
	this->telefone = "";
	this->endereco = "";
}

Pessoa::~Pessoa(){
}

string Pessoa::get_nome(){
	return this->nome;
}
void Pessoa::set_nome(string nome){
	this->nome = nome;
}

string Pessoa::get_cpf(){
	return this->cpf;
}
void Pessoa::set_cpf(string cpf){
	this->cpf = cpf;
}

string Pessoa::get_email(){
	return this->email;
}
void Pessoa::set_email(string email){
	this->email = email;
}

string Pessoa::get_telefone(){
	return this->telefone;
}
void Pessoa::set_telefone(string telefone){
	this->telefone = telefone;
}

string Pessoa::get_endereco(){
	return this->endereco;
}
void Pessoa::set_endereco(string endereco){
	this->endereco = endereco;
}

void Pessoa::imprime_dados(){
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Telefone: " << get_telefone() << endl;
	cout << "Endereço: " << get_endereco() << endl << endl;
}

