#include <iostream>
#include <string>

#include "Data.h"
#include "Aluno.h"

using namespace std;

int main(){

    Aluno escolaX[3];

    for(int i = 0; i < 3; i++){
        escolaX[i].listaAluno();
    }
}