#ifndef FUNCIONARIO_HPP_
#define FUNCIONARIO_HPP_

#include "pessoa.hpp"

class Funcionario : public Pessoa
{
	public:
		Funcionario();
		Funcionario(string nome, string cpf, string email);
		~Funcionario();
		
		void imprime_dados();
};

#endif