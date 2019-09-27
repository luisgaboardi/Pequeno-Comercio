#ifndef PESSOA_HPP_
#define PESSOA_HPP_

#include <iostream>
#include <vector>

using namespace std;

class Pessoa
{
	private:
		string nome,
				email;
		long long int cpf;

	public:
		Pessoa();
		Pessoa(string nome, long long int cpf, string email);
		~Pessoa();

		string get_nome();
		string get_email();
		long long int get_cpf();

		void set_nome(string nome);
		void set_email(string email);
		void set_cpf(long long int cpf);

		virtual void imprime_dados();
};

#endif