/*
* Feito por Thiago Vieira <thiagovieiraas@gmail.com>
* Este algoritmo converte a data do calendário gregoriano para o juliano.
* Depois de converter, pego o mod 7 da data em juliano, o resultado me informa qual o é dia da semana da data informada.
*/
 
#include<stdio.h>
 
int paraJuliana(int ano, int mes, int dia)
{
    //Converte a data do calendário gregoriano para o juliano.
    return (1461*(ano+4800+(mes-14)/12))/4 + (367*(mes-2-12*((mes-14)/12)))/12- (3*((ano + 4900+(mes-14)/12)/100))/4 + dia-32075;
}

int main()
{
    int ano, mes, dia, resultado;
 
    printf("Informe o dia: ");
    scanf("%d", &dia);
    printf("Informe o mes: ");
    scanf("%d", &mes);
    printf("Informe o ano: ");
    scanf("%d", &ano);
 
    resultado = paraJuliana(ano, mes, dia)%7;
    
    switch(resultado)
    {
        case 0:
            printf("Segunda-feira\n");
            break;
        case 1:
            printf("Terca-feira\n");
            break;
        case 2:
            printf("Quarta-feira\n");
            break;
        case 3:
            printf("Quinta-feira\n");
            break;
        case 4:
            printf("Sexta-feira\n");
            break;
        case 5:
            printf("Sabado\n");
            break;
        case 6:
            printf("Domingo\n");
            break;
}
    return 0;
}
