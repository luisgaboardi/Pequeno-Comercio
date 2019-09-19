#include "cliente.hpp"

Cliente::Cliente(){}

Cliente::Cliente(string nome, string cpf, string email, bool socio) : Pessoa(nome, cpf, email){
	this->socio = socio;
}

Cliente::~Cliente(){}

bool Cliente::get_socio(){
	return socio;
}
void Cliente::set_socio(bool socio){
	this->socio = socio;
}

void Cliente::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Sócio: " << get_socio() << endl;
	cout << "-----------------------" << endl;
}
