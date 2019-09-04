#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(string nome, string cpf, string email) : Pessoa(nome, cpf, email){}

Funcionario::~Funcionario(){}

void Funcionario::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
}