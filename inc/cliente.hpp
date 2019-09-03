#include <vector>

class Cliente : public Pessoa
{
	private:
		//vector<Produto> historico;
		bool ativo;
		// Carrinho carrinho;
	
	public:
		Cliente();
		~Cliente();
		
		bool get_trabalhando();
		void set_ativo(bool ativo);
		
		void imprime_dados();
};