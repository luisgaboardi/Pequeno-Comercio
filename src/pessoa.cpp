#include "pessoa.hpp"

Pessoa::Pessoa()
{
	set_nome("");
	set_email("");
	set_cpf("");
	set_telefone("");
	set_endereco("");
}

Pessoa::Pessoa(string nome, string email, string cpf, string telefone, string endereco)
{
	set_nome(nome);
	set_email(email);
	set_cpf(cpf);
	set_telefone(telefone);
	set_endereco(endereco);
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

string Pessoa::get_telefone(){
	return this->telefone;
}
void Pessoa::set_telefone(string telefone){
	if(telefone.size() < 10)
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

