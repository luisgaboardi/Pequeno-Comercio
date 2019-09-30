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

bool sortbysec(const pair<string,int> &a, const pair<string,int> &b)
{
    return (a.second > b.second);
	
}

void Cliente::recomendacao(vector<Produto *> produtos)
{	
	int max = 1;

	cout << "[Recomendação]" << endl << endl;
	if(!historico.empty())
	{
		sort(historico.begin(), historico.end(), sortbysec);

		for(pair<string, int> h : historico) // Passa por todas as categorias do histórico do cliente
		{
			for(Produto *p : produtos) // Passa por todos os produtos da loja
			{
				for(string cat : p->get_categoria()) // Passa por todas as categorias do produto
				{
					if(h.first == cat) // Compara categoria do historico com as dos produtos
					{
						p->imprime_dados();
						max++;
						if(max == 10)
							return;
					}
				}
			} 	 
		}

		if(max < 10)
		{
			for(pair<string, int> h : historico) // Passa por todas as categorias do histórico do cliente
			{
				for(Produto *p : produtos) // Passa por todos os produtos da loja
				{
					for(string cat : p->get_categoria()) // Passa por todas as categorias do produto
					{
						if(h.first != cat) // Compara categoria do historico com as dos produtos
						{
							p->imprime_dados();
							max++;
							if(max == 10)
								return;
						}
					}
				} 	 
			}
		}
	}
	else
	{
		cout << "Não foi possível gerar uma recomendação." << endl;
		cout << "O cliente " << get_nome() << " ainda não realizou nenhuma compra." << endl << endl;
	}
}

void Cliente::imprime_dados()
{
	cout << "Nome: " << get_nome() << endl;
	cout << "CPF: " << get_cpf() << endl;
	cout << "Email: " << get_email() << endl;
	cout << "Sócio: " << eh_socio() << endl;

	cout << "------------------------------" << endl;
}
