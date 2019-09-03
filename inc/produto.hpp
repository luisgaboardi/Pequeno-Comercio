#ifndef PRODUTO_HPP_
#define PRODUTO_HPP_

class Produto
{
	private:
		string nome;
		//vector<string> categoria;
		int quantidade;
		float valor;
	
	public:
		Produto();
		Produto(string nome, int quantidade, float valor);
		
		~Produto();
		
		string get_nome();
		void set_nome(string nome);
		
		int get_quantidade();
		void set_quantidade();
		
		float get_valor();
		void set_valor(float valor);
};



#endif