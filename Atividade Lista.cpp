#include <stdio.h>

struct No
{
    int valor;
    No* prox;

    No()
    {
        prox = NULL;
    }

    No(int _valor)
    {
        valor = _valor;
        prox = NULL;
    }
};

struct Lista
{
    No* inicio;
    No* fim;
    int n;

    Lista()
    {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor)
    {
        No* novo = new No(valor);
        if(inicio == NULL)
        {
            inicio = novo;
            fim = novo;
        }
        else
        {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor)
    {
        No* novo = new No(valor);
        if(inicio == NULL)
        {
            inicio = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio()
    {
        if(n == 0) return;
        if(n == 1)
        {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal()
    {
        if(n == 0) return;
        if(n == 1)
        {
            delete inicio;
            inicio = NULL;
            fim = NULL;
            n--;
        }
        No* aux = inicio;
        while(aux->prox != fim)
        {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    //exercicio 01
    void removeUltimosElementos(int e)
    {
        for(int i = 0; i < e && n > 0; i++)
        {
            removerFinal();
        }
    }

    //exercicio 02
    void removerSegundoElemento()
    {
        if(n <= 1) return;
        if(n == 2)
        {
            removerFinal();
            return;
        }

        No* segundoElemento = inicio->prox;
        inicio->prox = segundoElemento->prox;
        delete(segundoElemento);
        n--;
    }

    //exercicio 03
    void inserirFinalTamanhoLista()
    {
        inserirFinal(n);
    }

    //exercicio 04
    void inserirNElementos(int y)
    {
        for(int i = 0; i < y ; i++)
        {
            inserirFinal(i);
        }
    }

    //exercicio 05
    void inserirPenultimoElemento(int v)
    {
        if(n <= 1) return;
        No* aux = inicio;
        while(aux->prox != fim)
        {
            aux = aux->prox;
        }
        No* novo = new No(v);
        aux->prox = novo;
        novo->prox = fim;
        n++;
    }

    //imprimir dados
    void imprimir()
    {
        No* aux = inicio;
        while (aux != NULL)
        {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
};


int main()
{
    Lista l;

    //inserindo dados
    l.inserirInicio(8);
    l.inserirInicio(20);
    l.inserirInicio(45);
    l.inserirInicio(31);
    l.inserirInicio(97);

    //removendo ultimos elementos
    l.removeUltimosElementos(2);

    //removendo segundo elemento
    l.removerSegundoElemento();

    //inserindo no final o tamanho da lista
    l.inserirFinalTamanhoLista();

    //inserindo N elementos
    l.inserirNElementos(5);

    //inserindo penultimo elemento
    l.inserirPenultimoElemento(200);

    //imprimindo dados
    l.imprimir();

    return 0;
}
