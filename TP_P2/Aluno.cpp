#include "Aluno.h"
#include <iostream>
#include <climits>

using namespace std;

Aluno::Aluno(){
    this->leiaAluno();
    cout << "Aluno criado com sucesso!" << endl;
}

Aluno::~Aluno(){
    cout << "O aluno morreu kkkkkkkkkkkkkkkk" << endl;
}

void Aluno::setNome(string nome){
    this->nome = nome;
}

void Aluno::setNascimento(Data * nascimento){
    this->nascimento = nascimento;
}

string Aluno::getNome(){
    return this->nome;
}

void Aluno::leiaAluno(){
    string nome;
    Data * nascimento;

    printf("Por favor, digite o nome do aluno: ");
        
    getline(cin, nome);
       
    Aluno::setNome(nome);

    printf("Data de Nascimento - ");
    nascimento = new Data;
    Aluno::setNascimento(nascimento);

    cin.clear(); // limpa flags de erro de cin
    cin.ignore(INT_MAX, '\n'); // ignora todos os caracteres digitados até encontrar um '\n' - INT_MAX é a quantidade de caracteres, entao é basicamente todos
}

void Aluno::listaAluno(){
    cout << "Aluno: " << this->getNome() << " Data de Nascimento: "; 
    this->nascimento->imprimirData();
}
