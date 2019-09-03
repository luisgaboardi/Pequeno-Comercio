#include "cliente.hpp"

class Socio : public Cliente
{
	private:
		float fidelidade;
		float desconto;
	
	public:
		Socio();
		~Socio();
		
		float get_fidelidade();
		void set_fidelidade(float fidelidade);
		
		float get_desconto();
		void set_desconto(float desconto);
		
		void imprime_dados();
};