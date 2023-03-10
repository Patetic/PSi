#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1
typedef struct
{
    char nome[30];
    char sexo;
    int idade;
    char saude[3];
} pessoa;
void lerDados(pessoa pess[MAX])
{
    int i;
    for(i=0; i<MAX; i++)
    {
        printf("Introduza os seus dados: \nNome:");
        fflush(stdin);
        scanf("%s",&pess[i].nome);
        do
        {
            printf("Introduza o seu sexo:\nMasculino=M\nFemino=F\n");
            fflush(stdin);
            scanf("%c",&pess[i].sexo);
        }
        while(pess[i].sexo != 'F' && pess[i].sexo != 'M');
        printf("Introduza a sua idade: \n");
        fflush(stdin);
        scanf("%d",&pess[i].idade);
        do
        {
            printf("Tem algum problema de saude?\n(Sim/Nao)\n");
            fflush(stdin);
            scanf("%s",&pess[i].saude);
        }
        while((strcmp(pess[i].saude,"Sim")==0)  && (strcmp(pess[i].saude,"Nao")==0));
    }
    printf("-----------------------------\n");
}
void mostrarDados(pessoa pess[MAX])
{
    printf("Os dados introduzidos foram: \n");
    for(int i=0; i<MAX; i++)
    {
        printf("Nome: %s",pess[i].nome);
        printf("\nSexo: %c",pess[i].sexo);
        printf("\nIdade: %d",pess[i].idade);
        printf("\nSaude: %s",pess[i].saude);
    }
}
void militar(pessoa pess[MAX])
{
    int mil=0;
    for(int i=0; i<MAX; i++)
        if(pess[i].idade < 22 && strcmp(pess[i].saude,"Nao")==0)
        {
            printf("\nA pessoa cujo nome e %s tem requisitos para o servico militar",pess[i].nome);
            mil=1;
        }
    if(mil==0)
        printf("\nNenhuma pessoa esta apta para o servico militar");
}
int main()
{
    pessoa pess[MAX];
    lerDados(pess);
    mostrarDados(pess);
    militar(pess);
    return 0;
}
