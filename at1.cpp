#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    int valor;
    struct sNo *proximo;
}No;

typedef struct sLista
{
    No *inicio;
}Lista;

void criar_lista(Lista* lista)
{
    lista->inicio = NULL;
}

bool inserir_lista(Lista* lista, int elemento)
{
    No *aux, *novoNo = (No*) malloc(sizeof(No));
    if(novoNo != NULL)
    {
        novoNo->valor = elemento;
        novoNo->proximo = NULL;

        if(lista->inicio == NULL)
        {
            lista->inicio = novoNo;
        }else
        {
            aux = lista->inicio;
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novoNo;
        }
        return true;
    }else
    {
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

void copiar_lista(Lista* L1, Lista* L2)
{
    No *aux = L1->inicio;
    while(aux != NULL)
    {
        inserir_lista(L2, aux->valor);
        aux = aux->proximo;
    }
}

bool existe_lista(Lista *lista, int elemento)
{
    No* aux = lista->inicio;
    while(aux != NULL)
    {
        if(aux->valor == elemento)
            return true;
        aux = aux->proximo;
    }
    return false;
}

void copia_sem_repetidos(Lista* L1, Lista *L2)
{
    No *aux = L1->inicio;
    while(aux != NULL)
    {
        if(!existe_lista(L2, aux->valor))
            inserir_lista(L2, aux->valor);

        aux = aux->proximo;
    }
}


void imprimir_lista(Lista lista)
{
    No* no = lista.inicio;
    while(no != NULL)
    {
        cout << no->valor << " ";
        no = no->proximo;
    }
    cout << endl;
}

void liberar_lista(Lista* lista)
{
    No *atual = lista->inicio;
    No *prox;
    while(atual != NULL)
    {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
}

int main()
{
    Lista L1, L2;
    criar_lista(&L1);
    criar_lista(&L2);
    int valor;
    int opcao;
    cout << "Lista 1: " << endl;
    cout << "Escolha uma opcao: " << endl;
    cout << "0 - Finalizar" << endl;
    cout << "1 - Inserir elemento" << endl;
    do
    {
        cin >> opcao;
        switch(opcao)
        {
            case 1:
                cout << "Insira um elemento na lista: ";
                cin >> valor;
                inserir_lista(&L1, valor);
                break;
            default:
                if(opcao != 0)
                    cout << "Opcao invalida!" << endl;
            break;
        }
        
    }while(opcao != 0);

    cout << "Lista 1 digitada: ";
    imprimir_lista(L1);

    copia_sem_repetidos(&L1, &L2);
    cout << "Lista 2 sem repetidos: ";
    imprimir_lista(L2);

    


    
    

    return 0;
}

