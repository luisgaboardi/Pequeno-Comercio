#include "cliente.hpp"

Cliente::Cliente(){}

Cliente::Cliente(string nome, long long int cpf, string email, bool socio) : Pessoa(nome, cpf, email){
	this->socio = socio;
	carrinho = new Carrinho();
}

Cliente::~Cliente(){}

bool Cliente::get_socio(){
	return socio;
}
void Cliente::set_socio(bool socio){
	this->socio = socio;
}
string Cliente::eh_socio(){
	if(get_socio() == true)
		return "Sim";
	else
		return "Não";
}

void Cliente::historico_categoria(vector<string> categoria, int qtd)
{
	int flag;
	for(string s : categoria)
	{
		flag = 1;
		
		for(unsigned int j = 0; j < historico.size(); j++)
		{
			if(s == historico[j].first)
			{
				flag = 0;
				historico[j].second += qtd;
				break;
			}
		}
		
		if(flag == 1)
			historico.push_back(make_pair(s,qtd));
	}
}

void Cliente::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Sócio: " << eh_socio() << endl;

	cout << "--------------------------" << endl;
}
