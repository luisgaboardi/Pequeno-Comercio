#include "carrinho.hpp"
#include "cliente.hpp"
#include "loja.hpp"
#include "funcionario.hpp"
#include "produto.hpp"

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>

using namespace std;

string getString();
template <typename T1>
T1 getInput();

string getString()
{
    string valor;
    getline(cin, valor);
    return valor;
}


template <typename T1>
T1 getInput()
{
    while(true){
		T1 valor;
		cin >> valor;
		if(cin.fail()){
			cin.clear();
			cin.ignore(32767,'\n');
			cout << "Entrada inválida!" << endl;
		}
    	else
    	{
			cin.ignore(32767,'\n');
			return valor;
		}
    }
}

void menu(Loja *);
void modoVenda(Loja *, long long int);
void modoRecomendacao(Loja *);
void modoEstoque(Loja *);


int main()
{
	
	system("clear");
	cout << "Iniciando o sistema\nAguarde..." << endl;
	sleep(2);
	
	Loja *loja = new Loja();
	
	loja->identifica_funcionario();
	menu(loja);
	
	delete loja;
	
	return 0;
}

void menu(Loja *loja)
{
	int entrada;
	
	do{
		system("clear");
		
		cout << "     Menu" << endl << endl;
		cout << "(1) Venda" << endl;
		cout << "(2) Recomendação" << endl;
		cout << "(3) Estoque" << endl;
		cout << "(4) Lista de Clientes" << endl;
		cout << "(5) Lista de Funcionários" << endl;
		cout << "(0) Sair" << endl << endl;
		
		entrada = getInput<long long int>();
		
	} while (entrada < 0 || entrada > 5);
	
	if(entrada == 1){
		modoVenda(loja, 0);
	} else if(entrada == 2){
		modoRecomendacao(loja);
	} else if(entrada == 3){
		modoEstoque(loja);
	} else if(entrada == 4){
		loja->imprime_clientes();
		menu(loja);
	} else if(entrada == 5){
		loja->imprime_funcionarios();
		menu(loja);
	} else if(entrada == 0){
		system("clear");
		exit(-1);
	}
	
}

void modoVenda(Loja *loja, long long int cpf)
{
	string escolha;
	int opcao;
	Cliente *c;
	pair<Produto*, int> compra;
	string nome;
	Produto *prod;
	long long int cpfCadastrado;
	int qtd;
	float valorEntregue;
	int flagVazio = 0;
	system("clear");
	
	if(cpf == 0)
		c = loja->confere_cliente();
	else
		c = loja->confere_cliente(cpf);
		
	for(Produto *p : loja->produtos){
		if(p->noEstoque()){
			flagVazio = 1;
			break;
		}
	}
	
	if(c)
	{
		if(loja->produtos.empty() || flagVazio == 0)
		{
			cout << "[Estoque]" << endl << endl;
			cout << "O estoque está vazio!" << endl;
			cout << endl << "Aperte enter para retornar ao menu...";
			getchar();
		}
		else
		{
			do {
				system("clear");
				cout << "[Venda]" << endl << endl;
				cout << "Cliente: " << c->get_nome() << endl;
				cout << "Sócio: " << c->eh_socio() << endl << endl;
				cout << "Produtos disponíveis:" << endl << endl;
	
				for(Produto *p:loja->produtos)
					p->imprime_dados(0);

				cout << endl << "Produtos à passar no caixa:";
		
				cout << endl << endl << "Nome: ";
				nome = getString();
				prod = loja->checa_produto(nome);
				if(prod){
					cout << "Quantidade: ";
					qtd = getInput<int>();
					c->carrinho->add_item(prod, qtd, loja->produtos);
					c->historico.push_back(prod);
				} else {
					escolha = "s";
					continue;
				}

				cout << endl << "Deseja comprar outro item? (s/n)\n\n>> ";
				cin >> escolha;
				
				flagVazio = 0;
				
				for(Produto *p : loja->produtos){
					if(p->noEstoque()){
						flagVazio = 1;
						break;
					}
				}
				
			} while (escolha != "n" && flagVazio == 1);
			
			if(escolha == "s" && flagVazio == 0)
			{
				cout << endl << "O estoque está vazio." << endl << "Pressione enter para encerrar a compra." << endl;
				getchar();
				getchar();
			}
			
			if(c->carrinho->confere_carrinho())
			{
				c->carrinho->imprime_dados(c->get_socio());
				cout << endl << "Valor entregue: R$ ";
				do{
					valorEntregue = getInput<float>();
					if(valorEntregue < c->carrinho->get_valorTotal())
						cout << "O valor inserido é insuficiente." << endl << "R$ ";
				}while (valorEntregue < c->carrinho->get_valorTotal());
				
				cout << "Troco: R$ " << valorEntregue - c->carrinho->get_valorTotal() << endl << endl;
				cout << "----------------------\nVenda realizada.";
			}
			
			while (!c->carrinho->item.empty())
			{
				c->carrinho->item.pop_back();
			}
			
			c->carrinho->set_valorTotal(0.0f);


			cout << endl << "Pressione enter para retornar ao menu...";
			getchar();
			getchar();
		}
		
	} else {
		
		do{
			system("clear");
			cout << "[Registro]" << endl << endl;
			cout << "Cliente não encontrado." << endl;
			cout << " (1) Cadastrar cliente" << endl;
			cout << " (0) Voltar\n\n>> ";
			opcao = getInput<int>();
		} while (opcao != 1 && opcao != 2);
		
		if(opcao == 1){
			cpfCadastrado = loja->cadastrar_cliente();
			modoVenda(loja, cpfCadastrado);
		} else {
			menu(loja);
		}
	}
	
	menu(loja);
	
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
	int opcao;
	float valorP;
	int flagQtd = 0;
	int flag = 0, count = 1;
	
	do{
		system("clear");
		cout << "  [Estoque]" << endl << endl;
		cout << "(1) Adicionar um produto" << endl;
		cout << "(2) Produtos em estoque" << endl;
		cout << "(0) Voltar\n\n>> ";
		
		opcao = getInput<int>();
	
	}while(opcao != 1 && opcao != 2 && opcao != 0);
	
	if(opcao == 1){
		
		system("clear");
		cout << "  [Estoque]" << endl << endl;
		
		Produto *p1 = new Produto();

		cout << "Nome: ";
		nomeP = getString();
		p1->set_nome(nomeP);
		
		do{
			cout << "Categoria " << count << ": ";
			categoriaP = getString();
			p1->set_categoria(categoriaP);
			
			cout << endl << "O produto tem outra categoria? (s/n)\n>> ";
			escolha = getString();
			
			if(escolha != "s"){
				flag = 1;
			}
			count++;
			system("clear");

		} while(flag == 0);
		
		cout << "Quantidade: ";
		qtdP = getInput<int>();
		p1->set_quantidade(qtdP);
		
		cout << "Valor unitário: ";
		valorP = getInput<float>();
		p1->set_valor(valorP);
		
		loja->produtos.push_back(p1);
		
		system("clear");
		cout << "[Estoque]\n\nProduto cadastrado:" << endl << endl;
		
		loja->produtos[loja->produtos.size()-1]->imprime_dados();
		
		cout << endl << "Pressione enter para voltar ao menu...";
		getchar();

	} else if(opcao == 2){
		system("clear");
		cout << "[Estoque]" << endl << endl;

		for(Produto* p : loja->produtos)
		{
			if(p->get_quantidade() > 0)
			{
				flagQtd = 1;
				break;
			}
		}
		
		if(loja->produtos.size() == 0 || !flagQtd)
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
		
	}
	
	menu(loja);
	
}