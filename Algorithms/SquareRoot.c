/*
* Feito por Thiago Vieira <thiagovieiraas@gmail.com>
*
* Programa que calcula a raiz de um número real qualquer.
* Para desenvolver este algoritmo usei o método de Newton-Raphson.
*
* Data: 18-11-2012
*/

#include<stdio.h>
#define NIVELAPROX 100 //Não significa que o resultado vai ter uma aproximação de NIVELAPROX casas decimais.

double calculaRaiz(double n)
{
    register int i = 0;
    double raiz = 1;
    while(i++ < NIVELAPROX)
        raiz = (raiz*raiz + n)/(2*raiz);
    return raiz;
}

int main()
{
    double n;
    while(1)
    {
        printf("Informe um valor: ");
        scanf("%lf", &n);
        if(n < 0)
            break;
        
        printf("Raiz quadrada de %.10lf é %.10lf\n\n", n, calculaRaiz(n));
    }
    return 0;
}
