#ifndef FUNCIONARIO_HPP_
#define FUNCIONARIO_HPP_

#include "pessoa.hpp"
#include <string>

class Funcionario : public Pessoa
{
	private:
		string senha;
	public:
		Funcionario();
		Funcionario(string nome, long long int cpf, string email, string senha);
		~Funcionario();
		
		string get_senha();
		void set_senha(string senha);
		
		void imprime_dados();
};

#endif