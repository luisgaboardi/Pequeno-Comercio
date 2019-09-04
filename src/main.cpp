#include "funcionario.hpp"
#include "cliente.hpp"
#include "socio.hpp"
#include "produto.hpp"
#include "loja.hpp"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void identifica_funcionario(Loja *);
void menu(Loja *);

int main()
{
	
	system("clear");
	cout << "Iniciando o sistema\nAguarde..." << endl;
	sleep(3);
	
	system("clear");
	cout << "Bem-vindo(a)!" << endl << endl;
	
	Loja *loja = new Loja();
	
	// Login ou cadastro de funcionário
	identifica_funcionario(loja);
	menu(loja);
	return 0;
}

void identifica_funcionario(Loja *loja)
{
	string escolha;
	string cpfFunc;
	int flag = 0;
	
	do{
		system("clear");
		cout << "     Menu Inicial" << endl << endl;
		cout << "(1) Login" << endl;
		cout << "(2) Cadastrar novo funcionário\n\n>> ";
	
		cin >> escolha;
		
	} while (escolha != "1" && escolha != "2");
	
	if(escolha == "1")
	{
		system("clear");
		cout << "[Login]" << endl << endl;
		
		cout << "CPF: ";
		cin >> cpfFunc;
		
		system("clear");
		
		for(unsigned int i = 0; i < loja->funcionarios.size(); ++i)
		{
			if(cpfFunc == loja->funcionarios[i]->get_cpf()){
				cout << "Funcionário encontrado." << endl << endl;
				loja->funcionarios[i]->imprime_dados();
				getchar();
				getchar();
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			cout << "Funcionário não encontrado." << endl << endl;
			getchar();
			getchar();
			identifica_funcionario(loja);
		}
		

	} else if(escolha == "2")
	{
		string nomeFunc, emailFunc;
		
		system("clear");
		
		cout << "[Cadastro]" << endl << endl;
		cout << "Nome: ";
		cin >> nomeFunc;
		cout << "CPF: ";
		cin >> cpfFunc;
		cout << "Email: ";
		cin >> emailFunc;
		
		Funcionario *f2 = new Funcionario(nomeFunc, cpfFunc, emailFunc);
		loja->funcionarios.push_back(f2);

		system("clear");
		cout << "Funcionário cadastrado com sucesso" << endl << endl;
		loja->funcionarios[loja->funcionarios.size()-1]->imprime_dados();
		getchar();
		getchar();
	}
}

void menu(Loja *loja)
{
}