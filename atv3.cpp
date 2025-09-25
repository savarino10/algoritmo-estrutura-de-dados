#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    sNo *proximo;
    int elemento; 

    sNo(int valor): elemento(valor), proximo(NULL){};
}No;

typedef struct sLista
{
    No *inicio;
    No *final;
    int tamanho;

    sLista(): inicio(NULL), final(NULL), tamanho(0){};

}Lista;

bool inserir_fim(Lista *lista, int valor)
{
    No *novoNo = new No(valor);

    if(lista->inicio == NULL)
    {
        lista->inicio = novoNo;
        lista->final = novoNo;
        lista->tamanho++;
       return true;
    }else
    {
        lista->final->proximo = novoNo;
        lista->final = novoNo;
        lista->tamanho++;
    } 
    return false;
}

void ordernar_lista(Lista* lista)
{
    
    if(lista->inicio == NULL)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    bool trocou;

    do{
        trocou = false;
        No *aux = lista->inicio;    
        while(aux->proximo != NULL)
        {
            if(aux->elemento > aux->proximo->elemento)
            {
                swap(aux->elemento, aux->proximo->elemento);
                trocou = true;
            }
            aux = aux->proximo;
        }
        
    }while(trocou);
}

Lista* merge(Lista *L1, Lista*L2)
{
    Lista *L3 = new Lista;
    No *aux = L1->inicio;
    while(aux != NULL)
    {
        inserir_fim(L3, aux->elemento);
        aux = aux->proximo;        
    }
    aux = L2->inicio;
    while(aux != NULL)
    {
        inserir_fim(L2, aux->elemento);
        aux = aux->proximo;
    }
     ordernar_lista(L3);
    return L3;
}

Lista* dividir_lista(Lista* lista, int n)
{
    Lista *Novalista = new Lista();

    if(lista == NULL || lista->inicio == NULL || n <= 0)
    return Novalista;


    No *aux = lista->inicio;

    int indice = 1;

    while(aux != NULL && indice < n)
    {
        aux = aux->proximo;
        indice++;
    }    
    if(aux == NULL || aux->proximo == NULL)
    {
        return Novalista;
    }

    Novalista->inicio = aux->proximo;
    aux->proximo = NULL;  

    return Novalista;
}

void ordernar_lista(Lista* lista)
{
    if(lista->inicio == NULL)
    {
        cout << "Lista Vazia!" << endl;
        return;
    }

    bool trocou;

    do{
        trocou = false;
        
        while(temp->proximo != NULL)
        {
            if(temp->elemento > temp->proximo->elemento)
            {
                swap(temp->elemento, temp->proximo->elemento);
                trocou = true;
            }
            temp = temp->proximo;
        }

    }while(trocou);
}


