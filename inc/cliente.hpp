#include <vector>
#include "pessoa.hpp"

class Cliente : public Pessoa
{
	private:
		//vector<Produto> historico;
		bool ativo;
		// Carrinho carrinho;
	
	public:
		Cliente();
		~Cliente();
		
		bool get_ativo();
		void set_ativo(bool ativo);
		
		void imprime_dados();
};