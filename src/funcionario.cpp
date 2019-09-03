#include "funcionario.hpp"

Funcionario::Funcionario()
{
	set_salario(0.0f);
	set_trabalhando(false);
}

Funcionario::Funcionario(string nome, string cpf, string email, string telefone, string endereco, float salario, bool trabalhando) : Pessoa(nome, email, cpf, telefone, endereco)
{
	set_salario(salario);
	set_trabalhando(trabalhando);
}

Funcionario::~Funcionario(){}

float Funcionario::get_salario(){
	return salario;
}
void Funcionario::set_salario(float salario){
	if(salario >= 0){
		this->salario = salario;
	}
}

bool Funcionario::get_trabalhando(){
	return trabalhando;
}
void Funcionario::set_trabalhando(bool trabalhando){
	this->trabalhando = trabalhando;
}

void Funcionario::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Telefone: " << get_telefone() << endl;
	cout << "Endereço: " << get_endereco() << endl;
	cout << "Salário: " << get_salario() << endl;
	cout << "Trabalhando: " << get_trabalhando() << endl << endl;
}