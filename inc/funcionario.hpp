#include "pessoa.hpp"

class Funcionario : public Pessoa
{
	private:
		float salario;
		bool trabalhando;
	
	public:
		Funcionario();
		~Funcionario();
		
		float get_salario();
		bool get_trabalhando();
		
		void set_salario(float salario);
		void set_trabalhando(bool trabalhando);
		
		void imprime_dados();
};