#include<bits/stdc++.h>
using namespace std;

typedef struct sNo
{
    int valor;
    struct sNo *proximo;

}No;

typedef struct sLista
{
    No* inicio;
    int tamanho;
}Lista;


//criar lista:
void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->tamanho = 0;
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

    return false;
}


bool inserir_final(Lista *lista, int num)
{  
    No *aux, *novo = (No*) malloc(sizeof(No));
    
    if(novo != NULL)
    {
        novo->valor = num;
        novo->proximo = NULL;

        //é o primeiro nó da lista?
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
        cout << "Erro ao alocar memoria!" << endl;
        return false;
    }
}

bool inserir_meio(Lista *lista, int num, int ant)
{
    No *aux, *novo = (No*) malloc(sizeof(No));

    if(novo != NULL)
    {
        novo->valor = num;

        //é o primeiro nó da lista?
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

void imprimir_lista(Lista lista)
{
    No *no = lista.inicio;
    cout << "Lista de tamanho " << lista.tamanho << ": "; 
    while(no != NULL)
    {
        cout << no->valor << " ";
        no = no->proximo; 
    }
    cout << endl;
}

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
            {
                aux = aux->proximo;
            }
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

No* remover_no(Lista* lista, int num)
{
    No *aux, *remover = NULL;
    if(lista->inicio != NULL)
    {
        if(lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tamanho--;
        }else
        {
            aux = lista->inicio;
            while(aux->proximo != NULL && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo != NULL)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tamanho--;
            }
        }
    }

    return remover;
}

No *buscar(Lista* lista, int num)
{
    No *aux, *no = NULL;

    aux = lista->inicio;  
    while(aux != NULL && aux->valor != num)
        aux = aux->proximo;
    
    if(aux != NULL)
        no = aux;

    return no;
}



int main()
{
    Lista lista;
    criar_lista(&lista);
    int opcao;
    int valor;  
    int ant;
    No* elemento;

    cout << "MENU: " << endl;
    cout << "0 - SAIR" << endl;
    cout << "1 - INSERIR NO INICIO" << endl;
    cout << "2 - INSERIR NO MEIO" << endl;
    cout << "3 - INSERIR NO FIM " << endl;
    cout << "4 - INSERIR ORDENADO " << endl;    
    cout << "5 - BUSCAR ELEMENTO " << endl;
    cout << "6 - REMOVER ELEMENTO " << endl;
    cout << "7 IMPRIMIR LISTA " << endl;

    do
    {
        cin >> opcao;

        switch(opcao)
        {
            case 1:
                cout << "Digite um valor a ser inserido: ";
                cin >> valor;
                inserir_inicio(&lista, valor);
            break;

            case 2:
                cout << "Digite o valor e o elemento de referencia: ";
                cin >> valor >> ant;
                inserir_meio(&lista, valor, ant);
            break;
            
            case 3:
                cout << "Digite um valor a ser inserido: ";
                cin >> valor;
                inserir_final(&lista, valor);
            break;

            case 4:
                cout << "Digite um valor a ser inserido: ";
                cin >> valor;
                inserir_ordenado(&lista, valor);
            break;

            case 5:
                cout << "Digite um valor a ser buscado: ";
                cin >> valor;
                elemento = buscar(&lista, valor);
                if(elemento != NULL)
                {
                    cout << "Elemento encontrado: " << elemento->valor;
                }else
                    cout << "Elemento nao encontrado!" << endl;
            break;

            case 6:
            cout << "Digite um valor a ser removido: ";
            cin >> valor;
            elemento = remover_no(&lista, valor);
            if(elemento != NULL)
            {
                cout << "Elemento removido: " << elemento->valor;   
                free(elemento);
            }
            else
                cout << "Elemento nao encontrado!" << endl;
            break;

            case 7:
                imprimir_lista(lista);
            break;

            default:
                if(opcao != 0)
                    cout << "Opcao invalida!" << endl;
            break;   
        }

    }while(opcao != 0);





    return 0;
}