#include<bits/stdc++.h>
using namespace std;

// EXERCICIO 4 LISTA LSE

//EXERCICIO 2 SIMULADO
int letras_comuns(No* palavra1, No* palavra2)
{
    No *aux = palavra1;

    if(palavra1 == NULL || palavra2 == NULL)
        return 0;

    while(aux != NULL)
    {
        No *temp = palavra2;
        while(temp != NULL)
        {
            if(aux->elemento == temp->elemento)
                return 1;
            temp = temp->proximo;         
        }
        aux = aux->proximo;
    }
    return 0;
}

//EXERCICIO 3 SIMULADO
int palindromo(Lista* palavra)
{
    if(palavra == NULL)
        return 1;

    No *aux = palavra->inicio;
    
    int tamanho = 0;
    
    while(aux->proximo != NULL)
    {
        tamanho++;
        aux = aux->proximo;
    }

    char *palavra = (char*) malloc(tamanho * sizeof(char));
    for(int i = 0; i < tamanho; i++)
    {
        palavra[i] = aux->letra;
        aux = aux->proximo;
    }
    int i = 0;
    int j = tamanho - 1;
    while(i < j)
    {
        if(palavra[i] != palavra[j])
        {
            free(palavra);
            return 0;
        }
        i++;
        j--;
        
    }
    free(palavra);
    return 1;
}

//EXERCICIO 3 DO MANZATO
int palindromo(Lista* palavra)
{
    if(palavra->inicio == NULL)
        return 1;
    
    No *pos_inicial = palavra->inicio;
    No *pos_final = palavra->final;

    while(pos_inical != pos_final && pos_inicial->anterior != pos_final)
    {
        if(pos_inicial->letra != pos_final->letra)
            return 0;
        pos_inicial = pos_inicial->proximo;
        pos_final = pos_final->anterior;
    }
    
    return 1;
}

int letras_comuns(No *palavra1, No*palavra2)
{
    if(palavra1 == NULL || palavra2 == NULL)
        return 0;
    
    No *aux1 = palavra1;
    while(aux1 != NULL)
    {  
        No *aux2 = palavra2;
        while(aux2 != NULL)
        {
        if(aux1->letra == aux2->letra)
            return 1;
        aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;
    }
    return 0;
}

int palindromo(Lista *lista)
{
    if(lista == 0)
        return 1;
    
    int tamanho = 0;
    No *aux = lista->inicio;
    while(aux->proximo != NULL)
    {
        tamanho++;
        aux = aux->proximo;
    }
    char *palavra = (char*) malloc(tamanho * sizeof(char));
    
    for(int i = 0; i < tamanho; i++)
    {
        palavra[i] = aux->letra;
        aux = aux->proximo;
    }

    int i = 0;
    int j = tamanho - 1;
    while(i < j)
    {
        if(palavra[i] != palavra[j])
        {
            free(palavra);
            return 0;
        }
        i++;
        j--;
    }

    free(palavra);
    return 1;
}

int palindromo(Lista *lista)
{
    if(lista == NULL)
        return 1;

    No *posInicio = lista->inicio;
    No *posFim = lista->fim;
    while(posInicio != posFim && posInicio->anterior != posFim)
    {
        if(posInicio->letra != posFim->letra)
            return 0; 
        posInicio = posInicio->proximo;
        posFim = posFim->anterior;
    }
    return 1;
}