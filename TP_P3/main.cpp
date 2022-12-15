#include <iostream>
#include <string>

#include "Data.h"
#include "Aluno.h"

using namespace std;

int Aluno::qtdAlunos = 0;

int menu(){
    int opcao;

    cout << endl;
    cout << "|----------------------------------------------------|" << endl;
    cout << "|----- Bem vindo ao sistema de Cadastro de Alunos ---|" << endl;
    cout << "|----------------------------------------------------|" << endl;
    cout << "| 1 - Cadastrar Aluno -------------------------------|" << endl;
    cout << "| 2 - Listar Alunos   -------------------------------|" << endl;
    cout << "| 3 - Remover Aluno   -------------------------------|" << endl;
    cout << "| 0 - Sair do Programa ------------------------------|" << endl;
    cout << "|----------------------------------------------------|" << endl;
        
    do {
        cout << "|- Digite a sua opção: ";
        cin >> opcao;
    }while(opcao < 0);
    
    cout << endl;
    
    return opcao;
}
bool estaVazio() {
    return (Aluno::qtdAlunos == 0);
}
void listarAlunos(Aluno * escola[]){
    if(estaVazio()){
        cout << "Não há elementos para serem exibidos! ";
    }
    else {
        for(int i = 0; i < Aluno::qtdAlunos; i++){
            cout << "ID: " << i+1 << " | ";
            escola[i]->listaAluno();
        }
    }
}

// recebe o array e o indice do elemento que será excluido, sendo assim, todos os outros elementos andaram 1 pra esquerda;
void reorganizarArranjo(Aluno * escola[], int indice){
    int tamArray = Aluno::qtdAlunos - 1; // aqui nunca será negativo porque isso é tratado na função que chama

    cout << "Tamanho do Array: " << tamArray << endl;

    // quando isso acontecer, significa que estamos no último elemento    
    if(indice == tamArray){
        delete(escola[indice]);
    }else{
        int i = indice;

        while(i < tamArray){
            /*
                Essa foi a "única" maneira que encontrei para fazer o que eu tinha em mente
                possível de melhoria futura    
            */
            delete(escola[i]);
            escola[i] = new Aluno(escola[i+1]->getNome(), escola[i+1]->getNascimento());
            i++;
        }
        delete(escola[i]);
    }
}

void deletarAluno(Aluno * escola[]){
    if(estaVazio())
        cout << "Array Vazio!";
    else{
        int id;
        listarAlunos(escola);
        cout << '\n';
        do{
            cout << "Digite o ID do usuário que você quer deletar: ";
            cin >> id;
        }while(id <= 0 || id > Aluno::qtdAlunos);
        
        reorganizarArranjo(escola, id-1); // array e o indice do item que se quer remover
    }
} 

int main(){

    Aluno * escolaX[100];

    int indice;
    int opcao;

    do{
        opcao = menu();

        switch(opcao){
            case 0:
                break;
            case 1:
                indice = Aluno::qtdAlunos;
                escolaX[indice++] = new Aluno(); // sempre vai adicionar na última posição
                break;
            case 2:
                listarAlunos(escolaX);
                break;
            case 3:  
                deletarAluno(escolaX);
                break;
            case 4:
                break;
                           
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }

    }while(opcao != 0);
}