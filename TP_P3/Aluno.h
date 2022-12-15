#ifndef ALUNO_H
#define ALUNO_H

#include "Data.h"
#include <string>

class Aluno {
    private:
        std::string nome;
        Data * nascimento;
    public:
        static int qtdAlunos; // precisa ser inicializada na main

        Aluno();
        ~Aluno();
        Aluno(std::string nome);
        Aluno(std::string nome, Data * nascimento);
        


        std::string getNome();
        Data * getNascimento();

        void setNome(std::string nome);
        void setNascimento(Data * nascimento);

        void leiaAluno();
        void listaAluno();
    
        
};

#endif