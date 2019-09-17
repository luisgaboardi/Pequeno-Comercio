#include "produto.hpp"

Produto::Produto()
{
	set_nome("");
	set_quantidade(0);
	set_valor(0.0f);
}

Produto::Produto(string nome, int quantidade, float valor)
{
	set_nome(nome);
	set_quantidade(quantidade);
	set_valor(valor);
}

Produto::~Produto(){}

string Produto::get_nome(){
	return nome;
}
void Produto::set_nome(string nome){
	if(nome.size() < 30)
		this->nome = nome;
}

vector<string> Produto::get_categoria(){
	return categoria;
}

void Produto::set_categoria(string categoria){
	if(categoria != "")
		this->categoria.push_back(categoria);
}
		
int Produto::get_quantidade(){
	return quantidade;
}
void Produto::set_quantidade(int quantidade){
	if(quantidade > 0)
		this->quantidade = quantidade;
}
	
float Produto::get_valor(){
	return valor;
}
void Produto::set_valor(float valor){
	if(valor > 0.0)
		this->valor = valor;
}

bool Produto::noEstoque()
{
	if(get_quantidade() > 0){
		return true;
	}
	else{
		return false;
	}
}

void Produto::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "Categoria(s): ";
	for(unsigned int i = 0; i < get_categoria().size(); ++i)
	{
		cout << get_categoria()[i];
		if(i != get_categoria().size() - 1)
			cout << ", ";
	}
	cout << endl << "Quantidade: " << get_quantidade() << endl;
	cout << "Valor Unitário: R$ " << get_valor() << endl;
	cout << "-----------------------------" << endl;
}