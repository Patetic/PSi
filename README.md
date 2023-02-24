#include <stdio.h>
#include <string.h>
int main()
{
    char portugues[5][30], ingles[5][30];
    char palavra[30];
    int i, enc=0;
    for(i=0; i<5; i++)
    {
        printf("\nIntroduza a %d palavra em portugues - ", i+1);
        fgets(portugues[i], 30, stdin);
        printf("\nIntroduza a %d palavra equivalente em ingles - ", i+1);
        fgets(ingles[i], 30, stdin);

    }
    printf("\nEscreva uma palvra em portugues que esteja no dicionario:   ");
    fgets(palavra, 30, stdin);
    printf("..........Procura-se %s", palavra);
    for(i=0;i<5;i++)
    if(strcmp(palavra,portugues[i])==0)
    {
        printf("\nA palavra equivalente em ingles e - %s", ingles[i]);
        enc=1;
    }
    return 0;
}
