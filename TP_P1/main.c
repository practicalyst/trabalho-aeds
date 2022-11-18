#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_MIN 1900
#define DATA_MAX 2022
#define MAX 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    char nome[50];
    Data nascimento;
} Aluno;


void leiaData(Data * data){
    bool dataInvalida;

    do{
        dataInvalida = false;

        printf("[dd/mm/aaaa]: ");
        scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);

        if(data->dia <= 0 || data->mes <= 0 || data->mes > 12 || data->ano <= DATA_MIN || data->ano >= DATA_MAX){
            dataInvalida = true;
        }
        else{
            switch(data->mes){
                case 1:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 2: // fevereiro caso especial
                    if(data->dia > 28) dataInvalida = true;
                    break;
                case 3:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 5:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 6:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 8:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 10:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                case 12:
                    if(data->dia > 31) dataInvalida = true;
                    break;
                default:
                    if(data->dia > 30) dataInvalida = true; // restante dos meses com 30 dias  
            }    
        }
    if(dataInvalida == true) printf("Data Inválida, tente novamente! ");
    }while(dataInvalida);
}

void imprimaData(Data data){
    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}

void imprimaAluno(Aluno aluno){
    printf("%s, ", aluno.nome);
    imprimaData(aluno.nascimento);
    printf("\n");
}

void listaAlunos(Aluno * alunos[], int qtdAlunos){
    printf("\n");
    for(int i = 0; i < qtdAlunos; i++){
        printf("%d) ", i+1); // Mostra a contagem de alunos ao lado
        imprimaAluno(*alunos[i]);
    }
}

void leiaAluno(Aluno * aluno){
    // fflush(stdin);
    __fpurge(stdin); // Linux
    
    printf("Nome do Aluno: ");
    gets(aluno->nome);
    leiaData(&aluno->nascimento);
}

// c é a quantidade de alunos que já estão na estrutura
int leiaAlunos(Aluno * alunos[], int c){
    int qtdAlunos;

    do{
        printf("\nPor favor, digite a quantidade de alunos a serem cadastradas: ");
        scanf("%d", &qtdAlunos);
    }while(qtdAlunos <= 0);
    
    for(int i = c; i < (qtdAlunos+c); i++){
        
        alunos[i] = (Aluno *) malloc(sizeof(Aluno));

        printf("%d) ", i+1); // Mostra a contagem de alunos ao lado
        leiaAluno(alunos[i]); // escola[i] = *(escola+i)
        printf("\n");
    } 

    return qtdAlunos;
}

int listarAniversarios(Aluno * alunos[], int indices){
    int mesAniversario;
    bool dataInvalida;

    do{
        printf("Verificar aniversariantes em qual mês?: ");
        scanf("%d", &mesAniversario);

        dataInvalida = mesAniversario <= 0 || mesAniversario > 12;
        if(dataInvalida) printf("Data inválida, tente novamente!\n");
    }while(dataInvalida);

    for(int i = 0; i < indices; i++){
        if(alunos[i]->nascimento.mes == mesAniversario){
            printf("\n");
            imprimaAluno(*alunos[i]);
        }
    }
}

int menu(){
    int opcao;
    bool ERRO;

    printf("\nMenu de Opções\n\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Cadastrar Alunos em Massa\n");
    printf("3 - Listar Alunos\n");
    printf("4 - Aniversariantes do Mês\n");
    
    do{
        printf("\nPor favor selecione uma opção: ");
        scanf("%d", &opcao);
        ERRO = (opcao < 0) || (opcao > 4); 

        if(ERRO) printf("Opção inválida! Tente novamente.");

    }while(ERRO);
    return opcao;
}

int main(){

    Aluno * escolaX[MAX];

    int opcao;
    int indice = 0;

    do{
        opcao = menu();

        switch (opcao){

        case 1:
            escolaX[indice] = (Aluno * ) malloc(sizeof(Aluno));
            leiaAluno(escolaX[indice]);
            indice++;
            break;
        case 2:
            indice += leiaAlunos(escolaX, indice);
            break;
        case 3:
            listaAlunos(escolaX, indice);
            break;
        case 4:
            listarAniversarios(escolaX, indice);
            break;
        
        default:
            break;
        }

    }while (opcao != 0);
    
}