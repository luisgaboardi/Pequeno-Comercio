#include <iostream>

using namespace std;

class Pessoa
{
	private:
		string nome,
				email,
				cpf,
				telefone,
				endereco;

	public:
		Pessoa();
		~Pessoa();

		string get_nome();
		string get_email();
		string get_cpf();
		string get_telefone();
		string get_endereco();

		void set_nome(string nome);
		void set_email(string email);
		void set_cpf(string cpf);
		void set_telefone(string telefone);
		void set_endereco(string endereco);

		void imprime_dados();
};
