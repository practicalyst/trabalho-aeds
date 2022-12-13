#ifndef ALUNO_H
#define ALUNO_H

#include "Data.h"
#include <string>

class Aluno {
    private:
        std::string nome;
        Data * nascimento;
    public:

        Aluno();
        ~Aluno();

        std::string getNome();

        void setNome(std::string nome);
        void setNascimento(Data * nascimento);

        void leiaAluno();
        void listaAluno();
        
        /*
        void listarAlunos(Aluno *);
        void listarAluno(Aluno);
        */
        

};

#endif