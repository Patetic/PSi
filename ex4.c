#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
int cont=-1;
typedef struct
{
    char nomep[10];
    char apelido[10];
    char telefone[10];
    char email[20];
    int idade;
} amigo;
void inserir(amigo tm[MAX])
{
    if (cont <MAX-1)
    {
        cont++;
        printf("Nome Proprio: ");
        fflush(stdin);
        scanf("%s", &tm[cont].nomep);
        printf("Apelido: ");
        fflush(stdin);
        scanf("%s", &tm[cont].apelido);
        printf("Telefone (+351-xxxxxxxxx: ");
        fflush(stdin);
        scanf("%s", &tm[cont].telefone);
        printf("Email: ");
        scanf("%s",&tm[cont].email);
        printf("Idade: ");
        fflush(stdin);
        scanf("%d", &tm[cont].idade);
    }
    else
        printf("Ja introduziu todos os amigos! (10 max)\n");
}
void menu()
{
    printf("\n\n\n");
    printf("\n******** AGENDA TM **************************\n");
    printf("*  1 - Inserir Contacto (ate %d)            *\n",MAX);
    printf("*  2 - Mostrar Contacto                     *\n");
    printf("*  3 - Procurar Contacto por TM             *\n");
    printf("*  4 - Apagar Contacto por Nome Proprio     *\n");
    printf("*  5 - Sair do Programa                     *\n");
    printf("*********************************************\n");
    printf("*  opcao ==> ");
}
void mostrar(amigo tm[MAX])
{
    int i;
    for(i=0; i<=cont; i++)
    {
        printf("\nNome: %s  %s\n", tm[i].nomep,tm[i].apelido);
        printf("Telefone: %s",tm[i].telefone);
        printf("\nE-mail: %s",tm[i].email);
        printf("\nIdade: %d",tm[i].idade);
        printf("\n----------------------");

    }
}
int procura(amigo tm[MAX], char valor[], int c)
{
    int i;
    for(i=0; i<=cont; i++)
    {
        if(c=0)
        {
            strcmp(tm[i].telefone,valor);
            return i;
        }
        else
        {
            strcmp(tm[i].nomep,valor);
            return i;
        }
    }
    return -1;
}
void apagar(amigo tm[MAX],int loc)
{
    int i,j;
    amigo aux;
    for(i=loc; i<cont; i++)
    {
        for(j=i+1; j<=cont; j++)
        {
            aux=tm[i];
            tm[i]=tm[j];
            tm[j]=aux;
        }
    }
    cont-=1;
}
int main()
{
    amigo tm[MAX];
    int tel[9];
    char nome [10];
    int opc;
    while(1)
    {
        menu();
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            system("cls");
            inserir(tm);
            break;
        case 2:
            system("cls");
            mostrar(tm);
            break;
        case 3:
            system("cls");
            printf("Introduza o numero que queria procurar\n");
            fflush(stdin);
            scanf("%s",&tel);
            if(procura(tm,tel,0)== -1)
                printf("\nNumero %s NAO encontrado!!!", tel);
            else
                printf("\nContacto %s encontrado e chama-se %s!!!",tm[procura(tm,tel,0)].telefone, tm[procura(tm,tel,0)].nomep);
            break;
        case 4:
            system("cls");
            printf("\nIntroduza um nome proprio para apagar:\n");
            printf("Nome ==> ");
            fflush(stdin);
            gets(nome);
            if(procura(tm,nome,1)== -1)
                printf("\nNome %s NAO encontrado!!!", nome);
            else
            {
                printf("\nNome %s encontrado!!!",tm[procura(tm,nome,1)].nomep);
                apagar(tm,procura(tm,nome,1));
                printf("\nNome %s APAGADO de agenda", nome);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("\nIntroduza um  numero entre 1 e 5!");
        }
    }
    return 0;
}
