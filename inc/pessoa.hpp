#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include <iostream>
#include <vector>

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
		Pessoa(string nome, string email, string cpf, string telefone, string endereco);
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

#endif