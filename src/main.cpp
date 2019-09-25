#include "carrinho.hpp"
#include "cliente.hpp"
#include "loja.hpp"
#include "funcionario.hpp"
#include "produto.hpp"



#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void menu(Loja *);
void modoVenda(Loja *);
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
	string entrada;
	
	do{
		system("clear");
		cout << "     Menu" << endl << endl;
		cout << "(1) Venda" << endl;
		cout << "(2) Recomendação" << endl;
		cout << "(3) Estoque" << endl;
		cout << "(4) Lista de Clientes" << endl;
		cout << "(5) Lista de Funcionários" << endl;
		cout << "(0) Sair\n\n>> ";
		
		cin >> entrada;
		
	} while (entrada != "1" && entrada != "2" && entrada != "3" && entrada != "4" && entrada != "5" && entrada != "0");
	
	if(entrada == "1"){
		modoVenda(loja);
	} else if(entrada == "2"){
		modoRecomendacao(loja);
	} else if(entrada == "3"){
		modoEstoque(loja);
	} else if(entrada == "4"){
		loja->imprime_clientes();
		menu(loja);
	} else if(entrada == "5"){
		loja->imprime_funcionarios();
		menu(loja);
	} else if(entrada == "0"){
		system("clear");
		exit(-1);
	}
	
}

void modoVenda(Loja *loja)
{
	string escolha;
	Cliente *c;
	pair<Produto*, int> compra;
	string nome;
	Produto *prod;
	int qtd;
	float valorEntregue;
	int flagVazio = 0;
	system("clear");
	
	c = loja->confere_cliente();

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

				cout << endl << "Produtos à passar no caixa (vindos do carrinho que estou montando agora)";
		
				cout << endl << endl << "Nome: ";
				cin >> nome;
				prod = loja->checa_produto(nome);
				if(prod){
					cout << "Quantidade: ";
					cin >> qtd;
					c->carrinho->add_item(prod, qtd, loja->produtos);
					c->historico.push_back(prod);
				} else {
					escolha = "s";
					continue;
				}

				cout << endl << "Deseja comprar outro item? (s/n)\n\n>> ";
				cin >> escolha;
			} while (escolha != "n");

			system("clear");
			c->carrinho->imprime_dados();

			cout << endl << "Valor entregue: R$ ";
			cin >> valorEntregue;
			cout << "Troco: R$ " << valorEntregue - c->carrinho->get_valorTotal() << endl << endl;
			cout << "----------------------\nVenda realizada.";

			cout << endl << "Pressione enter para retornar ao menu...";
			getchar();
			getchar();
		}
		
	} else {
		cout << "[Registro]" << endl << endl;
		cout << "Cliente não encontrado." << endl;
		cout << " (1) Cadastrar cliente" << endl;
		cout << " (0) Voltar\n\n>> ";
		cin >> escolha;
		
		if(escolha == "1")
			loja->cadastrar_cliente();
		else
			menu(loja);
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
	float valorP;
	int flagQtd = 0;
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
		cout << "[Estoque]\n\nProduto cadastrado:" << endl << endl;
		
		loja->produtos[loja->produtos.size()-1]->imprime_dados();
		
		cout << endl << "Pressione enter para voltar ao menu...";
		getchar();
		getchar();
		
	} else if(escolha == "2"){
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
		getchar();
		
	}
	
	menu(loja);
	
}