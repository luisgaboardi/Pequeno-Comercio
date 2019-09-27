#include "loja.hpp"

#include <vector>
#include <stdlib.h>
#include <string>

string getString();
template <typename T1>
T1 getInput();

Loja::Loja(){}

Loja::~Loja(){}

void Loja::identifica_funcionario()
{
	int escolha;
	long long int cpfFunc;
	string senhaFunc;
	int flag = 0;
	
	do{
		system("clear");
		cout << "     Menu Inicial" << endl << endl;
		cout << "(1) Login" << endl;
		cout << "(2) Cadastrar novo funcionário\n\n>> ";
	
		escolha = getInput<int>();
		
	} while (escolha != 1 && escolha != 2);
	
	if(escolha == 1)
	{
		system("clear");
		cout << "[Login]" << endl << endl;
		
		cout << "CPF: ";
		cpfFunc = getInput<long long int>();
		cout << "Senha: ";
		senhaFunc = getString();
		
		system("clear");
		
		for(Funcionario *f: funcionarios)
		{
			if(cpfFunc == f->get_cpf() && senhaFunc == f->get_senha())
			{
				cout << "Bem vindo(a), " << f->get_nome() << endl << endl;
				cout << "Pressione enter para continuar...";
				getchar();
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			cout << "Funcionário não encontrado.\n\nPressione enter para retornar...";
			getchar();
			identifica_funcionario();
		}

	} else if(escolha == 2) {
	
		string nomeFunc, emailFunc;
	
		system("clear");
		
		cout << "[Cadastro]" << endl << endl;
		cout << "Nome: ";
		nomeFunc = getString();
		cout << "CPF: ";
		cpfFunc = getInput<long long int>();
		cout << "Email: ";
		emailFunc = getString();
		cout << "Senha: ";
		senhaFunc = getString();

		funcionarios.push_back(new Funcionario(nomeFunc, cpfFunc, emailFunc, senhaFunc));

		cout << endl << "Funcionário cadastrado com sucesso" << endl;
		cout << endl << "Pressione enter para voltar...";
		getchar();
		identifica_funcionario();
	}
}


Cliente* Loja::confere_cliente()
{
	long long int cpf;
	system("clear");

	
	cout << "[Cliente]" << endl << endl;
	
	cout << "CPF: ";
	cpf = getInput<long long int>();
	
	system("clear");
	
	for(Cliente *c : clientes)
	{
		if(cpf == c->get_cpf())
			return c;
	}
	return NULL;
}

Cliente* Loja::confere_cliente(long long int cpf)
{
	system("clear");
	
	for(Cliente *c : clientes)
	{
		if(cpf == c->get_cpf())
			return c;
	}
	return NULL;
}

long long int Loja::cadastrar_cliente()
{
	string nome, email;
	long long int cpf;
	bool socio = false;
	string escolha;
	
	system("clear");

	
	cout << "[Cadastro]" << endl << endl;
	
	cout << "Nome: ";
	nome = getString();
	cout << "CPF: ";
	cpf = getInput<long long int>();
	cout << "Email: ";
	email = getString();
	
	cout << endl << "Deseja se tornar sócio? (s/n)\n\n>> ";
	cin >> escolha;
	
	if(escolha == "s"){
		socio = true;
	}
	
	clientes.push_back(new Cliente(nome, cpf, email, socio));
	
	system("clear");
	
	cout << "[Cadastro]" << endl << endl;
	cout << "Cliente cadastrado!" << endl << endl;
	cout << "Pressione enter para prosseguir com a compra...";
	getchar();
	getchar();

	return cpf;
}

void Loja::imprime_clientes()
{
	system("clear");
	cout << "[Registro]" << endl << endl;

	if (!clientes.empty())
	{
		for(Cliente *c : clientes){
			c->imprime_dados();
		}
	} else {
		cout << "A loja ainda não tem nenhum cliente." << endl;
	}
	
	cout << endl << "Pressione enter para voltar...";
	getchar();
}

void Loja::imprime_funcionarios()
{
	system("clear");
	cout << "[Registro]" << endl << endl;

	for(Funcionario *f : funcionarios)
	{
		f->imprime_dados(0);
	}
	
	cout << endl << "Pressione enter para voltar...";
	getchar();
}

Produto* Loja::checa_produto(string nome)
{
	for(Produto *p : produtos)
	{
		if(nome == p->get_nome() && p->noEstoque()){
			return p;
		}
	}
	//cout << "Não existe um produto com esse nome." << endl;
	return NULL;
}
