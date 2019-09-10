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
void modoVenda(Loja *);
void modoRecomendacao(Loja *);
void modoEstoque(Loja *);

int main()
{
	
	system("clear");
	cout << "Iniciando o sistema\nAguarde..." << endl;
	sleep(3);
	
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
		
		for(Pessoa *f: loja->pessoas)
		{
			if(cpfFunc == f->get_cpf()){
				cout << "Bem vindo(a), " << f->get_nome() << endl << endl;
				cout << "Pressione enter para continuar...";
				getchar();
				getchar();
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			cout << "Funcionário não encontrado.\n\nPressione enter para retornar...";
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

		loja->pessoas.push_back(new Funcionario(nomeFunc, cpfFunc, emailFunc));

		cout << endl << "Funcionário cadastrado com sucesso" << endl;
		cout << endl << "Pressione enter para voltar...";
		getchar();
		getchar();
		identifica_funcionario(loja);

	}
}

void menu(Loja *loja)
{
	string entrada;
	
	do{
		system("clear");
		cout << "     Menu" << endl << endl;
		cout << "(1) Venda" << endl;
		cout << "(2) Recomendação" << endl;
		cout << "(3) Estoque" << endl;
		cout << "(0) Sair\n\n>> ";
		
		cin >> entrada;
		
	} while (entrada != "1" && entrada != "2" && entrada != "3" && entrada != "0");
	
	if(entrada == "1"){
		modoVenda(loja);
	} else if(entrada == "2"){
		modoRecomendacao(loja);
	} else if(entrada == "3"){
		modoEstoque(loja);
	} else if(entrada == "0"){
		system("clear");
		exit(-1);
	}
	
}

void modoVenda(Loja *loja)
{
	system("clear");
	cout << "Olá" << endl;
}

void modoRecomendacao(Loja *loja)
{
	system("clear");
	cout << "Olá" << endl;
}

void modoEstoque(Loja *loja)
{
	string escolha, nomeP, categoriaP;
	int qtdP;
	float valorP;
	int flag = 0, count = 1;
	
	do{
		system("clear");
		cout << "  [Estoque]" << endl << endl;
		cout << "(1) Adicionar um produto" << endl;
		cout << "(2) Produtos em estoque" << endl;
		cout << "(0) Voltar\n\n>> ";
		
		cin >> escolha;
	
	}while(escolha != "1" && escolha != "2" && escolha != "0");
	
	if(escolha == "1"){
		
		system("clear");
		cout << "  [Estoque]" << endl << endl;
		
		Produto *p1 = new Produto();

		cout << "Nome: ";
		cin >> nomeP;
		p1->set_nome(nomeP);
		
		do{
			cout << "Categoria " << count << ": ";
			cin >> categoriaP;
			p1->set_categoria(categoriaP);
			
			cout << endl << "O produto tem outra categoria? (s/n)\n>> ";
			cin >> escolha;
			
			if(escolha != "s"){
				flag = 1;
			}
			count++;
			system("clear");

		} while(flag == 0);
		
		cout << "Quantidade: ";
		cin >> qtdP;
		p1->set_quantidade(qtdP);
		
		cout << "Valor unitário: ";
		cin >> valorP;
		p1->set_valor(valorP);
		
		loja->produtos.push_back(p1);
		
		system("clear");
		
		loja->produtos[loja->produtos.size()-1]->imprime_dados();
		
		cout << endl << "Pressione enter para voltar ao menu...";
		getchar();
		getchar();
		
	} else if(escolha == "2"){
		system("clear");
		cout << "[Estoque]" << endl << endl;
		
		if(loja->produtos.size() == 0)
		{
			cout << "O estoque está vazio!" << endl;
		}
		else
		{
			for(Produto *p:loja->produtos)
			{
				p->imprime_dados();
			}
		}
		
		cout << endl << "Pressione enter para voltar ao menu...";
		getchar();
		getchar();
		
	}
	
	menu(loja);
	
}