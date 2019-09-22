#include "loja.hpp"

#include <vector>
#include <stdlib.h>

Loja::Loja(){}

Loja::~Loja(){}

void Loja::identifica_funcionario()
{
	string escolha;
	string cpfFunc, senhaFunc;
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
		cout << "Senha: ";
		cin >> senhaFunc;
		
		system("clear");
		
		for(Funcionario *f: funcionarios)
		{
			if(cpfFunc == f->get_cpf() && senhaFunc == f->get_senha())
			{
				cout << "Bem vindo(a), " << f->get_nome() << endl << endl;
				//f->imprime_dados();
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
			identifica_funcionario();
		}

	} else if(escolha == "2") {
	
		string nomeFunc, emailFunc;
	
		system("clear");
		
		cout << "[Cadastro]" << endl << endl;
		cout << "Nome: ";
		cin >> nomeFunc;
		cout << "CPF: ";
		cin >> cpfFunc;
		cout << "Email: ";
		cin >> emailFunc;
		cout << "Senha: ";
		cin >> senhaFunc;

		funcionarios.push_back(new Funcionario(nomeFunc, cpfFunc, emailFunc, senhaFunc));

		cout << endl << "Funcionário cadastrado com sucesso" << endl;
		cout << endl << "Pressione enter para voltar...";
		getchar();
		getchar();
		identifica_funcionario();
	}
}


Cliente* Loja::confere_cliente()
{
	string cpf;
	system("clear");

	
	cout << "[Cliente]" << endl << endl;
	
	cout << "CPF: ";
	cin >> cpf;
	
	system("clear");
	
	for(Cliente *c : clientes)
	{
		if(cpf == c->get_cpf())
			return c;
	}
	return NULL;
}

void Loja::cadastrar_cliente()
{
	string nome, cpf, email;
	bool socio = false;
	string escolha;
	
	system("clear");

	
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
