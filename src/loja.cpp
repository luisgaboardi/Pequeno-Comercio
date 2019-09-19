#include "loja.hpp"

#include <vector>
#include <stdlib.h>

Loja::Loja(){}

Loja::~Loja(){}

float Loja::get_valorNoCaixa(){
	return valorNoCaixa;
}
void Loja::set_valorNoCaixa(float valorNoCaixa){
	if(valorNoCaixa >= 0.0 && valorNoCaixa >= this->valorNoCaixa)
		this->valorNoCaixa = valorNoCaixa;
}

int Loja::confere_cliente()
{
	string cpf;
	
	cout << "[Cliente]" << endl << endl;
	
	cout << "CPF: ";
	cin >> cpf;
	
	system("clear");
	
	for(Cliente *c : clientes)
	{
		if(cpf == c->get_cpf())
			return 1;
	}
	
	return 0;
}

void Loja::cadastrar_cliente()
{
	string nome, cpf, email;
	bool socio = false;
	string escolha;
	
	cout << "[Cadastro]" << endl << endl;
	
	cout << "Nome: ";
	cin >> nome;
	cout << "CPF: ";
	cin >> cpf;
	cout << "Email: ";
	cin >> email;
	
	cout << endl << "Deseja se tornar sócio? (s/n)\n\n>> ";
	cin >> escolha;
	
	if(escolha == "s"){
		socio = true;
	}
	
	clientes.push_back(new Cliente(nome, cpf, email, socio));
}