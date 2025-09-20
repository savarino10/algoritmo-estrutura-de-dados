
Vantagens:
    - Melhor utilização dos recursos de memória;
    - Não precisa movimentar elementos para inserção ou remoção.
        *A mudança é para onde os ponteiros vão apontar.

Desvantagens: 
    - Acesso indireto aos elementos;
    - Necessidade de percorrer a lista para acessar um elemento.

Quando utilizar esta "Lista": 
    - Não há necessidade de garantir um espaço mínimo de memória;
    - As operações de inserção e remoção de forma ordenada são mais frequentes.
        *Operações de deslocamento.

//APLICAÇÃO:

"ARQUIVO.H" definir:
    -protótipo das funções;
    -tipo de dado armazenado na lista;
    -o ponteiro "Lista";

"ARQUIVO.CPP" definir:
    -tipo de dados "lista";
    -implementação das funções;

#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    int valor;
    struct sNo* proximo;
}No;


//criar lista:
No* criar_lista()
{
    No *lista = NULL;
return lista;
}


//inserir no início:
bool inserir_inicio(No **lista, int num)
{
    No *novo = (No*) malloc(sizeof(No));

    if(novo != NULL)
    {    
    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
   
    return true;
    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

//inserir no fim:
bool inserir_final(No **lista, int num)
{   
    No *aux, *novo = (No*) malloc(sizeof(No));
    if(novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
    
    //é o primeiro da lista?
        if(*lista == NULL)
            *lista = novo;
        else
        {
            aux = *lista;
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novo;
        }

        return true;

    }else
    {
        cout << "Erro ao alocar memoria" << endl;
        return false;
    }   
}

//inserir no meio:
bool inserir_meio(**Lista, int num, int ant)
{
    No *novo = (No*) malloc(sizeof(No));
    
    if(novo != NULL)
    {
        novo->valor = num;
        //é o primeir nó da lista?
        

    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}





//FUNÇÃO PRINCIPAL: 
int main()  
{
    int opcao, valor, anterior;
    No* lista = criar_lista();
    

    do
    {
    cout << "======MENU=====: " << endl;
    cout << "1 - Inserir no Inicio. " << endl;
    cout << "2 - Inserir no Final. " << endl;
    cout << "3 - Inserir no Meio. " << endl;
    cout << "4 - Imprimir Lista." << endl;
    cout << endl << "Escolha sua opcao: ";
    cin >> opcao;
    
    switch(opcao)
    {
        case 1: 
            cout << "Digite um valor: ";
            cin >> valor;
            inserir_inicio(&lista, valor);
        break;

        case 2:
            cout << "Digite um valor: ";
            cin >> valor;
            inserir_final(&lista, valor);
        break;

        case 3:
            cout << "Digite um valor e o valor de referencia: ";
            cin >> valor >> anterior;
            inserir_meio(&lista, valor, anterior);
        break;

        case 4:
            imprimir(lista);
        break;

        default:
            if(opcao != 0)
                cout << "Opcao Invalida!" << endl;
    }

    }while(opcao != 0);

    liberar_lista(lista);



    return 0;
}


