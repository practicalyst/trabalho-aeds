#include "Data.h"
#include <iostream>

#define ANO_MINIMO 1900
#define ANO_MAXIMO 2022

using namespace std;

bool Data::setDia(int dia){
    bool sucesso = false;
    
    if(dia > 0 && dia <= 31){
        sucesso = true;
        this->dia = dia;
    }

    return sucesso;
}

bool Data::setMes(int mes){
    bool sucesso = false;
    
    if(mes >= 1 && mes <= 12){
        sucesso = true;
        this->mes = mes;
    }

    return sucesso;
}

bool Data::setAno(int ano){
  bool sucesso = false;
    
    if(ano >= ANO_MINIMO && ano <= ANO_MAXIMO){
        sucesso = true;
        this->ano = ano;
    
        if(Data::anoBissexto(ano))
            this->ehBissexto = true;
    }

    return sucesso;
}

bool Data::anoBissexto(int ano){
    bool sucesso = false;
    
    if(ano % 400 == 0)
        sucesso = true;
    else if((ano % 4 == 0) && (ano % 100 != 0))
            sucesso = true;

    return sucesso;
}

bool Data::setData(int dia, int mes, int ano){
    return setDia(dia) && setMes(mes) && setAno(ano) && validaData(dia, mes);
}

bool Data::validaData(int dia, int mes){

    bool sucesso = true;

    switch(mes){
        // para meses que possuem 30 dias, caso dia for igual a 31 -> invalidar
        case 4:
        case 6:
        case 9:
        case 11:
                if(dia == 31){ sucesso = false; } 
                break;
        case 2: // fevereiro, caso especial
                if(dia > 28) { sucesso = false; }
                break;
    }

    return sucesso;
}

int Data::getDia(){ return this->dia;}
int Data::getMes(){ return this->mes;}
int Data::getAno(){ return this->ano;}
bool Data::getBissexto() { return this->ehBissexto; }

void Data::imprimirData(){
    cout << getDia() << "/" << getMes() << "/" << getAno() << endl;       
}

Data::Data(int dia, int mes, int ano){
    setData(dia, mes, ano);
}

// Se o ano não for fornecido, o ano máximo será levado em consideração
Data::Data(int dia, int mes){ 
   setData(dia, mes, ANO_MAXIMO); 
}

Data::Data(){
    int dia,mes,ano;

    do{
        cout << "Por favor, digite uma data válida: ";
        scanf("%d/%d/%d", &dia, &mes, &ano);
    }while(!(setData(dia, mes, ano))); // setData retorna positivo caso as entradas tenham sido corretas
}


