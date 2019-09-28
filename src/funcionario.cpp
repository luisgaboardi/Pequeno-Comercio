#include "funcionario.hpp"

Funcionario::Funcionario(){}

Funcionario::Funcionario(string nome, long long int cpf, string email, string senha) : Pessoa(nome, cpf, email){
	set_senha(senha);
}

Funcionario::~Funcionario(){}

string Funcionario::get_senha(){
	return senha;
}
void Funcionario::set_senha(string senha){
	if(senha.size() < 11)
		this->senha = senha;
}


void Funcionario::imprime_dados()
{
	int flag = 0;
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Senha: ";
	for(char c : get_senha())
	{
		if(flag < 2){
			cout << c;
			flag++;
			continue;
		}
		cout << "*";
	}
	cout << endl << endl;
}

void Funcionario::imprime_dados(int x)
{
	x++;
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "----------------------" << endl;
}
