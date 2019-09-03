#include "produto.hpp"

class Carrinho
{
	private:
		float valorTotal;
		//vector< pair<Produto, int> >
	
	public:
		Carrinho();
		~Carrinho();
		
		float get_valorTotal();
		void set_valorTotal(float valorTotal);
		
		void imprime_dados();
};