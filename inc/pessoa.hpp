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
				cpf;

	public:
		Pessoa();
		Pessoa(string nome, string cpf, string email);
		~Pessoa();

		string get_nome();
		string get_email();
		string get_cpf();

		void set_nome(string nome);
		void set_email(string email);
		void set_cpf(string cpf);

		void imprime_dados();
};

#endif