#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    int valor;
    struct sNo *proximo;

}No;


//criar lista:
No* criar_lista()
{
    No* lista = NULL;
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

    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}


bool inserir_final(No **lista, int num)
{  
    No *aux, *novo = (No*) malloc(sizeof(No));
    
    if(novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro nó da lista?
        if(*lista == NULL) 
            *lista = novo;
        else
        {
            aux = *lista;
            while(aux->proximo != NULL)
                aux->proximo;
            aux->proximo = novo;
        }
       
        return true;

    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}







int main()
{





    return 0;
}