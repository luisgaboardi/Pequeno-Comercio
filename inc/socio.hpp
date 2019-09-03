#ifndef SOCIO_HPP_
#define SOCIO_HPP_

#include "cliente.hpp"

class Socio : public Cliente
{
	private:
		float fidelidade;
		float desconto;
	
	public:
		Socio();
		Socio(string nome, string cpf, string email, string telefone, string endereco, bool ativo, float fidelidade, float desconto);
		~Socio();
		
		float get_fidelidade();
		void set_fidelidade(float fidelidade);
		
		float get_desconto();
		
		void imprime_dados();
};

#endif