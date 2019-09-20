#ifndef PRODUTO_HPP_
#define PRODUTO_HPP_

#include <iostream>
#include <vector>

using namespace std;

class Produto
{
	private:
		string nome;
		vector<string> categoria;
		int quantidade;
		float valor;
	
	public:
		Produto();
		Produto(string nome, int quantidade, float valor);
		
		~Produto();
				
		string get_nome();
		void set_nome(string nome);
		
		vector<string> get_categoria();
		void set_categoria(string categoria);
		
		int get_quantidade();
		void set_quantidade(int quantidade);
		
		float get_valor();
		void set_valor(float valor);
		
		bool noEstoque();
		void imprime_dados();
		void imprime_dados(int x);
};


#endif