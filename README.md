# EP1 - OO 2019.2 (UnB - Gama)

## Descrição

Victoria possui um pequeno comércio que atende a população de seu bairro. Com o passar do tempo, a pequena empreendedora foi adquirindo experiência e, por conta de seu excelente poder de negociação, ela conseguia reduzir significativamente o preço dos produtos oferecidos.

Entretanto, apenas preços baixos não eram o bastante para manter a clientela. Em uma noite de inspiração, Victoria pensou em duas estratégias para atrair mais pessoas:
- Oferecer descontos de 15% para clientes sócios;
- Oferecer produtos recomendados exclusivamente para cada cliente;

Para colocar as ideias em prática, ela deve abandonar seu velho hábito de utilizar seu estimado caderninho para gerenciar sua loja. Uma amiga te recomendou para desenvolver um *software* que ajude o estabelecimento a implementar as novas estratégias de negócio. Com a sua ajuda, **todas as vendas serão realizadas pelo computador operado por uma funcionária**. Em uma breve conversa com Victoria, foi possível entender algumas características importantes do sistema:
- Victoria está aprendendo C++ em um curso online e, portanto, prefere que o sistema seja feito nesta linguagem para que ela consiga fazer as próprias manutenções quando necessário;
- Devem existir três modos de operação do sistema:
    - **Modo venda**
    - **Modo recomendação**
    - **Modo estoque**

### Modo venda
Em relação ao modo venda, deve-se observar os seguintes pontos:
- Antes de cada venda, deve ser possível inserir os dados do cliente para identificar se ele é sócio ou não;
- Caso o cliente não possuir cadastro, ele é feito antes da compra;
- A cada compra, deve ser possível colocar vários produtos no carrinho;
- No fim da compra, devem ser exibidas na tela as seguintes informações:
    - Lista de produtos vendidos, a quantidade e seus respectivos valores;
    - Valor total dos produtos;
    - Valor do desconto oferecido;
    - Valor final da venda;
- Ao fim, caso a compra apresente algum produto em quantidade maior que a existente no estoque, ela deve ser cancelada sem alterar o estoque e uma mensagem de erro deve ser apresentada;

Para evitar o recadastro de clientes, Victoria deseja que os dados de cadastro sejam salvos em arquivos. Assim, será possível acessar os dados mesmo que se encerre a execução do programa.

### Modo estoque
Para manter o estoque do estabelecimento, deve ser possível cadastrar novos produtos (não haverá a necessidade de se deletar produtos, apenas de se atualizar sua quantidade). Além disso, para evitar o recadastro de produtos e categorias, os dados devem ser armazenados em arquivos.

Aqui estão alguns aspectos importantes deste modo:
- Há várias categorias de produtos existentes no estabelecimento e, sempre que possível, Victoria tenta trazer coisas novas (O número de categorias não é fixo mas, assim como no caso dos produtos, não será necessário deletar nenhuma categoria);
- Um produto pode pertencer a mais de uma categoria;

### Modo recomendação
Para listar os itens recomendados para cada cliente, Victoria pensou em uma solução bem simples. A cada compra, é possível identificar a categoria de cada produto. Com este dado, é possível saber qual categoria que mais interessa o cliente.

Neste modo, também há alguns pontos a serem considerados:
- Ao entrar no modo recomendação, deve ser possível inserir os dados do cliente para buscar os produtos recomendados exclusivamente;
- Caso o cliente não possuir cadastro, uma mensagem de erro deve ser mostrada;
- A lista de recomendações deve ter as seguintes características:
    - Até 10 produtos;
    - Ordenados de acordo com o grau de recomendação (mais recomendados primeiro, menos recomendados por último);
    - Caso o grau de recomendação for o mesmo, o critério de ordenação deve obedecer a ordem lexicográfica;

## Materiais e Dicas

### Standard Template Library - C++

Em C, a constante necessidade da criação de estruturas de dados (listas encadeadas feitas com ponteiros e structs, manipulação de vetores estaticamente alocados, etc) torna o desenvolvimento uma tarefa passível de diversos erros. Além disso, a constante reescrita de algoritmos clássicos (ordenações e buscas, principalmente) pode, rapidamente, se tornar uma prática desagradável.

Baseado, principalmente, no princípio do reuso, os desenvolvedores de linguagens populares buscam disponibilizar bibliotecas que empacotam diversas utilidades para que se evite as situações descritas. No caso do C++, temos a Standard Template Library (STL), que é um compilado de diversos algoritmos e estruturas de dados úteis para o desenvolvimento.

Seguem, abaixo, algumas boas fontes para melhorar o entendimento do C++ usando STL:
- [Explicação sobre a STL e o que ela implementa (em inglês)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- Material da disciplina Tópicos Especiais em Programação (Programação Para Competições, pelo prof. Edson Alves)
    - [Slide - Introdução sobre C/C++](https://github.com/edsomjr/TEP/blob/master/Introducao/slides/RC-1/RC-1.pdf)
    - [Slide - Uso de structs, classes e como realizar debug](https://github.com/edsomjr/TEP/blob/master/Introducao/slides/RC-2/RC-2.pdf)
    - [Slide - Principais estruturas de dados presentes na STL](https://github.com/edsomjr/TEP/blob/master/Introducao/slides/RC-3/RC-3.pdf)
    - [Slide - Busca e ordenação utilizando C e C++](https://github.com/edsomjr/TEP/blob/master/Introducao/slides/BO-4/BO-4.pdf)
    - [Repositório completo da disciplina contendo todo o conteúdo ministrado](https://github.com/edsomjr/TEP)
- [Guia sobre a função sort() em C++ (em inglês)](https://www.geeksforgeeks.org/sort-c-stl/)

Um bom exemplo sobre as facilidades oferecidas pela STL é o ```vector```. Um dos grandes problemas dos arrays em C/C++ é a sua falta de dinamicidade. Caso um array de 3 posições for criado, ele nunca poderá armazenar mais do que três elementos. Sabemos que é comum a situação onde não é possível saber a quantidade exata de elementos a serem registrados. Para isso, o ```vector``` da STL nos permite inserir os elementos de forma dinâmica e, de forma transparente para o desenvolvedor, há a alocação de memória extra sempre que necessário. Por exemplo:

```c++
#include <iostream>
#include <vector>

int main(){
    std::vector<int> numeros; // Declaração de um vector que armazena ints

    numeros.push_back(2); // Inserção do int 2 no fim do vector -> [2]
    numeros.push_back(1); // Inserção do int 1 no fim do vector -> [2, 1]

    std::cout << numeros[0] << std::endl;
    std::cout << numeros[1] << std::endl;

    return 0;
}
```
Output:
```
2
1
```

Outra grande vantagem do ```vector``` é a sua integração com outros algoritmos da STL. Ordenar um array torna-se uma tarefa simples com a função ```sort()```:

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> numeros; // Declaração de um vector que armazena ints

    numeros.push_back(2); // Inserção do int 2 no fim do vector -> [2]
    numeros.push_back(1); // Inserção do int 1 no fim do vector -> [2, 1]

    std::sort(numeros.begin(), numeros.end()); // Ordena-se do menor valor para o maior -> [1, 2]

    std::cout << numeros[0] << std::endl;
    std::cout << numeros[1] << std::endl;

    return 0;
}
```
Output:
```
1
2
```

### Ordenação customizada (C++ 11)

A função ```sort()``` permite que seja passada uma função de comparação como o terceiro parâmetro. Assim, pode-se modificar os critérios de ordenação de um ```vector```, por exemplo:

```c++
#include <iostream>
#include <vector>
#include <algorithm>

bool maior_menor(int A, int B){
    return A > B;
}

bool menor_maior(int A, int B){
    return A < B;
}

int main(){
    std::vector<int> numeros = {1, 2};

    // Ordena do menor para o maior (comportamento padrão)
    std::sort(numeros.begin(), numeros.end(), menor_maior);

    // Ordena do maior para o menor
    std::sort(numeros.begin(), numeros.end(), maior_menor);

    return 0;
}
```
A função passada como parâmetro recebe, sempre, dois argumentos do mesmo tipo que o armazenado pela estrutura ordenada (```int```, neste caso) e retorna ```true``` (tipo ```bool```) sempre que o elemento na posição N está na posição correta quando comparado com o elemento na posição N+1 e ```false``` (tipo ```bool```) caso contrário.

### Percorrendo um ```vector```

Assim como em arrays em C, é possível percorrer um ```vector``` usando um ```for``` que incrementa uma variável índice e acessa cada posição da estrutura. Para saber até quando incrementar, devemos saber o tamanho máximo do ```vector```. Para isso, usamos o método ```.size()```, que retorna o tamanho atual:

```c++
#include <iostream>
#include <vector>

int main(){
    std::vector<int> numeros;
    numeros.push_back(1);
    numeros.push_back(2);

    // Imprimindo todos os valores do vetor
    for(int i = 0; i < numeros.size(); i++){ // for(int i = 0; i < 2; i++)
        std::cout << numeros[i] << std::endl;
    }
}
```
Output:
```
1
2
```
### Algoritmo de recomendação

Descrição e imagens #TODO

### Escrita e leitura em arquivo

Descrição e code snippet #TODO