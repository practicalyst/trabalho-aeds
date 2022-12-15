#include "Aluno.h"
#include <iostream>
#include <climits>

using namespace std;

Aluno::Aluno(){
    this->leiaAluno();
    cout << "Aluno criado com sucesso!\n" << endl;
    qtdAlunos++;
}

Aluno::Aluno(string nome, Data * nascimento){
    this->nome = nome;
    this->nascimento = nascimento;
    qtdAlunos++;
}

Aluno::Aluno(string nome){
    this->nome = nome;
    this->nascimento = new Data();
    qtdAlunos++;
}

Aluno::~Aluno(){
    cout << "O aluno morreu kkkkkkkkkkkkkkkk" << endl;
    qtdAlunos--;
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
Data * Aluno::getNascimento(){
    return this->nascimento;
}

void Aluno::leiaAluno(){
    string nome;
    Data * nascimento;

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    printf("Por favor, digite o nome do aluno: ");
        
    getline(cin, nome);
       
    Aluno::setNome(nome);

    printf("Data de Nascimento - ");
    nascimento = new Data;
    Aluno::setNascimento(nascimento);

    cout << "\n";

    cin.clear(); // limpa flags de erro de cin
    cin.ignore(INT_MAX, '\n'); // ignora todos os caracteres digitados até encontrar um '\n' - INT_MAX é a quantidade de caracteres, entao é basicamente todos
}

void Aluno::listaAluno(){
    cout << "Aluno: " << this->getNome() << " | Data de Nascimento: "; 
    this->nascimento->imprimirData();
    //cout << '\n';
}
