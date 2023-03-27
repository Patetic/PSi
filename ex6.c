#include <stdio.h>
#include <string.h>
#define MAX 10
int cont=4;
typedef struct
{
    char nomep[15];
    char apelido[20];
    int idade;
    char morada[40];
    char funcao[20];
    char departam[30];
    float ordenado;
} empregados;
void inserir(empregados xpto[MAX])
{
    int i,op=0;
    if(cont<MAX-1)
    {
        cont++;
        printf("Nome: ");
        fflush(stdin);
        scanf("%s",&xpto[cont].nomep);
        printf("Apelido: ");
        scanf("%s",&xpto[cont].apelido);
        fflush(stdin);
        printf("Idade: ");
        fflush(stdin);
        scanf("%d",&xpto[cont].idade);
        printf("Morada: ");
        fflush(stdin);
        scanf("%s",&xpto[cont].morada);
        printf("Sua Funcao: ");
        fflush(stdin);
        scanf("%s",&xpto[cont].funcao);
        printf("Departamento: ");
        fflush(stdin);
        scanf("%s",&xpto[cont].departam);
        printf("Ordenado: ");
        fflush(stdin);
        scanf("%f",&xpto[cont].ordenado);
    }
    else
        printf(" Ja Introduzio todos os Empregados! (max %d)\n ",MAX);
}
void menu()
{
    printf("\n\n\n");
    printf("\n---------Empresa XPTO----------------------------\n");
    printf("|  1 - Inserir novos empregados (ate %d)        |\n",MAX);
    printf("|  2 - Mostrar empregados                       |\n");
    printf("|  3 - Qual o empregado que ganha mais?         |\n");
    printf("|  4 - Ordenar os empregados por ordenado       |\n");
    printf("|  5 - Pesquisar os empregados por departamento |\n");
    printf("|  6 - Sair do Programa                         |\n");
    printf("-------------------------------------------------\n");
    printf("                 opcao ==> ");
}
mostrar(empregados xpto[MAX])
{
    for(int i=0; i<=cont; i++)
    {
        printf("\nNome: %s %s",xpto[i].nomep, xpto[i].apelido);
        printf("\nIdade: %d",xpto[i].idade);
        printf("\nMorada: %s",xpto[i].morada);
        printf("\nFuncao: %s",xpto[i].funcao);
        printf("\nDepartamento: %s", xpto[i].departam);
        printf("\nOrdenado %.f",xpto[i].ordenado);
        printf("\n------------------------------------");
    }

}
void GanhaMais(empregados xpto[MAX])
{
    float x;
    int a;
    x = xpto[0].ordenado;
    for(int i=0; i<cont; i++)
    {
        if(x<xpto[i].ordenado)
        {
            x=xpto[i].ordenado;
            a=i;
        }
    }
    printf("O empregado que ganha mais e %.f e chama-se %s %s",x,xpto[a].nomep,xpto[a].apelido);
}

int procura(empregados xpto[MAX], char departamento[], int c)
{
    int i;
    for(i=0; i<=cont; i++)
    {
        if(c=0)
        {
            strcmp(xpto[i].departam,departamento);
            return i;
        }
        else
        {
            strcmp(xpto[i].nomep,departamento);
            return i;
        }
    }
    return -1;
}
void ordenar(empregados xpto[MAX])
{
    int troca, i, j;
    empregados aux;
    for (i = cont; i > 0; i--)
    {
        troca = 0;
        for (j =0 ; j < i; j++)
        {
            if (xpto[j].ordenado > xpto[j+1].ordenado)
            {
                aux = xpto[j];
                xpto[j] = xpto[j+1];
                xpto[j+1] = aux;
                troca = 1;
            }
        }
    }
}

int main()
{
    empregados xpto[MAX]= {{"Joao", "Salvador",20,"Rua Estrada Benfica","Tecnico de TI","Gesta De Computadores",4000},
        {"Manuel", "Dias",31,"Avenida Elefante","CEO","Principal",150000},
        {"Carlos", "Pais",45,"Rua Andre Tontes","Limpador","Limpeza",1200},
        {"Andre", "Silva",24,"Avenida Patos","Entrada","Primeiro Andrar",3000},
        {"Diogo", "Mendes",37,"Rua Torta","Contabilista","Gestao",6000}
    };
    int opc;
    char departamento[30];
    while (1)
    {
        menu();
        fflush(stdin);
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            inserir(xpto);
            break;
        case 2:
            system("cls");
            mostrar(xpto);
            break;
        case 3:
            system("cls");
            GanhaMais(xpto);
            break;
        case 4:
            system("cls");
            ordenar(xpto);
            mostrar(xpto);
            break;
        case 5:
            printf("Introduza o departamento que quer procurar:\n");
            fflush(stdin);
            gets(departamento);
            if(procura(xpto,departamento,0)== -1)
                printf("\nDepartamento %s NAO encontrado!!!", departamento);
            else
                printf("\nDepartamento %s encontrado e o nome do empregado que trabalha nele e: %s %s!!!",xpto[procura(xpto,departamento,0)].departam, xpto[procura(xpto,departamento,0)].nomep,xpto[procura(xpto,departamento,0)].apelido);
            break;
        case 6:
            exit(0);
        default:
            printf("Introduza um numero entre 1 e 6!");
        }
    }
    return 0;
}
