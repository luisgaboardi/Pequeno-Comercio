#ifndef FUNCIONARIO_HPP_
#define FUNCIONARIO_HPP_

#include "pessoa.hpp"

class Funcionario : public Pessoa
{
	private:
		float salario;
		bool trabalhando;
	
	public:
		Funcionario();
		Funcionario(string nome, string cpf, string email, string telefone, string endereco, float salario, bool trabalhando);
		~Funcionario();
		
		float get_salario();
		bool get_trabalhando();
		
		void set_salario(float salario);
		void set_trabalhando(bool trabalhando);
		
		void imprime_dados();
};

#endif