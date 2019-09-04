#include "cliente.hpp"

Cliente::Cliente(){}

Cliente::Cliente(string nome, string cpf, string email) : Pessoa(nome, cpf, email){}

Cliente::~Cliente(){}

void Cliente::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
}
