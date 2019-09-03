#include "cliente.hpp"

Cliente::Cliente()
{
	set_ativo(false);
}

Cliente::Cliente(string nome, string cpf, string email, string telefone, string endereco, bool ativo) : Pessoa(nome, email, cpf, telefone, endereco)
{
	set_ativo(ativo);
}

Cliente::~Cliente(){}

bool Cliente::get_ativo(){
	return ativo;
}
void Cliente::set_ativo(bool ativo){
	this->ativo = ativo;
}

void Cliente::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Telefone: " << get_telefone() << endl;
	cout << "Endereço: " << get_endereco() << endl;
	cout << "Ativo: " << get_ativo() << endl << endl;
}
