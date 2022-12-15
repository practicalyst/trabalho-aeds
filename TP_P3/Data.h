#ifndef DATA_H
#define DATA_H

class Data {
    private:
        int dia;
        int mes;
        int ano;

        bool ehBissexto = false;

    public:
        bool setDia(int);
        bool setMes(int);
        bool setAno(int);
        bool setData(int, int, int);
        bool validaData(int, int);
        bool anoBissexto(int);

        int getDia(); // conceitos de encapsulamento
        int getMes(); // variáveis private acessíveis apenas por métodos da própria classe
        int getAno();
        bool getBissexto();

        void imprimirData();

        Data(int dia, int mes, int ano);
        Data(int dia, int mes);
        Data();
};

#endif