#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

typedef struct
{
    char nome[20];
    int turma;
    int idade;
    float nota;
} aluno;

void verAlunos(aluno alu[MAX])
{
    int i;
    printf("      Nome            Turma    Idade    Nota PSI\n");
    for(i=0; i<MAX; i++)
    {
        printf("\n%-15s",alu[i].nome);
        printf("%10d",alu[i].turma);
        printf("%10d",alu[i].idade);
        printf("%10.2f\n",alu[i].nota);


    }
}
void maisNovo(aluno alu[MAX])
{
    int x=0;
    int a=0;
    for(int i=0; i<MAX; i++)
    {
        x = alu[0].idade;
        if(x>alu[i].idade)
        {
            x=alu[i].idade;
            a=i;
        }
    }
    printf("\nO aluno mais novo e %s",alu[a].nome);
}
float media(aluno alu[MAX])
{
    float soma=0;
    for (int i=0; i < MAX; i++)
    {
        soma+=alu[i].nota;
    }
    float media = soma / MAX;
    return media;
}
void menu()
{
    printf("\n\n\n");
    printf("\n********MENU - ALUNOS************************\n");
    printf("*  1 - Ver alunos                           *\n");
    printf("*  2 - Procurar Nome Aluno                  *\n");
    printf("*  3 - Nome alunos mais novos               *\n");
    printf("*  4 - Media das Notas                      *\n");
    printf("*  5 - Sair do Programa                     *\n");
    printf("*********************************************\n");
    printf("*  opcao ==> ");
}
int main()
{
    aluno alu[MAX]= {{"Joao Salvador",10,16,16.2},{"Manuel Dias",10,16,9.5}, {"Carlos Pais",10,17,10.5},{"Andre Silva",10,15,17.1}};
    int opc;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (1)
    {
        SetConsoleTextAttribute(hConsole, 30);
        menu();
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            system("cls");
            verAlunos(alu);
            break;
        case 2:
            break;
        case 3:
            maisNovo(alu);
            break;
        case 4:
            printf("A media das notas e %f", media(alu));
            break;
        case 5:
            exit(0);
        default:
            printf("Tem de introduzir um numero entre 1 e 5!");
            break;
        }
    }
    return 0;
}

