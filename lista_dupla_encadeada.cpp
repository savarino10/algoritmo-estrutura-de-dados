#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    sNo *anterior;
    int valor;
    sNo* proximo;
}No;

typedef struct sLista
{
    No* inicio;
    int tamanho;
    No* final;
}Lista;

void criar_lista(Lista *lista)
{
    lista->inicio == NULL;
    lista->final == NULL;
}

void inserir_inicio(Lista *lista, int info)
{
    No *novoNo = new No;
    novoNo->valor = info;
    
    if(lista->inicio == NULL)
    {
        novoNo->proximo = NULL;
        novoNo->anterior = NULL;
        lista->inicio = novoNo;
        lista->final = novoNo;
    
    }else
    {
        novoNo->proximo = lista->inicio;
        novoNo->anterior = NULL;
        lista->inicio->anterior = novoNo;
        lista->inicio = novoNo;
    }
    lista->tamanho++;
}

void inserir_final(Lista* lista, int info)
{
    No *novoNO = new No;
    novoNo->valor = info;
    novoNo->proximo = NULL;
    if(lista->inicio == NULL)
    {
        novoNo->anterior = NULL;
        lista->inicio = novoNo;
        lista->final = novoNo;
    }else
    {
        novoNo->anterior = lista->final;
        lista->final->proximo = novoNo;
        lista->final = novoNo;
    }
    lista->tamanho++;
}

void remover_final(Lista* lista)
{
    
    if(lista->inicio == NULL)
        return;
    
    No *aux = lista->final;
    
    if(lista->inicio == lista->final)
    {
        lista->inicio = NULL;
        lista->final = NULL;
    }else
    {
        lista->final = aux->anterior;
        lista->final->proximo = NULL;
    }
    delete aux;
    lista->tamanho--;
}

int remover_inicio(Lista* lista)
{
    if(lista->inicio == NULL)
    {
        cout << "Lista vazia!" << endl;
        return 0;
    }

    No *temp = lista->inicio;

    if(lista->inicio == lista->final)
    {
        lista->inicio = NULL;
        lista->final = NULL;
      
    }else
    {
        lista->inicio = temp->proximo;
        lista->inicio->anterior = NULL;
    }
    delete temp;
    lista->tamanho--;
    return 1;
}

int main()
{

    return 0;
}