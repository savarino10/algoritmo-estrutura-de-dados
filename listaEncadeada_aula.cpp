
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

typedef struct sLista
{
    No* inicio;
    int tamanho;
}Lista;

//criar lista:
void criar_lista(Lista* lista)
{
    lista->inicio = NULL;
    int tamanho = 0;
}

//inserir no início:
bool inserir_inicio(Lista *lista, int num)
{
    No *novo = (No*) malloc(sizeof(No));

    if(novo != NULL)
    {    
    novo->valor = num;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
   
    return true;
    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

//inserir no fim:
bool inserir_final(Lista *lista, int num)
{   
    No *aux, *novo = (No*) malloc(sizeof(No));
    if(novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;
    
    //é o primeiro da lista?
        if(lista->inicio == NULL)
            lista->inicio = novo;
        else
        {
            aux = lista->inicio;
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novo;
        }

        lista->tamanho++;

        return true;

    }else
    {
        cout << "Erro ao alocar memoria" << endl;
        return false;
    }   
}

//inserir no meio:
bool inserir_meio(Lista *lista, int num, int ant)
{
    No *aux, *novo = (No*) malloc(sizeof(No));
    
    if(novo != NULL)
    {
        novo->valor = num;
        //é o primeir nó da lista?
        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }else
        {
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo != NULL)
                aux = aux->proximo;
                novo->proximo = aux->proximo;
                aux->proximo = novo;

        }

        lista->tamanho++;

        return true;

    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

//imprimir lista
void imprimir_lista(Lista lista)
{
    No *no = lista.inicio;
    cout << endl << "Lista: ";
    while(no != NULL)
    {
        cout << no->valor;
        no->proximo;
    }
    cout << endl;
}


//inserir ordenado
bool inserir_ordenado(Lista* lista, int num)
{
    No *aux, *novo = (No*) malloc(sizeof(No));
    if(novo != NULL)
    {
        novo->valor = num;
        if(lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            while(aux->proximo != NULL && novo->valor > aux->proximo->valor)
                    aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;

        }

        return true;


    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

//remover um nó da lista:
No* remover_no(Lista* lista, int num)
{
    No *aux, *remover = NULL;
    if(lista->inicio != NULL)
    {
        if(lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
        }else
        {
            aux = lista->inicio;
            while(aux->proximo != NULL && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo 
            }
        }
    }

    return remover;
}


