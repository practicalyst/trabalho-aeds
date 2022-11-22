#include <iostream>

using namespace std;

#define ANO_MINIMO 1900
#define ANO_MAXIMO 2022


class Data {
    private:
        int dia;
        int mes;
        int ano;

    public:
        void setDia(int dia){
            bool diaInvalido = dia <= 0 || dia > 31;
            
            while(diaInvalido){
                cout << "Dia Inválido, por favor digite novamente: ";
                cin >> dia;

                diaInvalido = dia <= 0 || dia > 31;
            }

            this->dia = dia;
        }

        void setMes(int mes){
            bool mesInvalido = mes <= 0 || mes > 12;

            while(mesInvalido){
                cout << "Mês Inválido, por favor digite novamente: ";
                cin >> mes;

                mesInvalido = mes <= 0 || mes > 12;
            }

            this->mes = mes;
        }

        void setAno(int ano){
            bool anoInvalido = ano < ANO_MINIMO || ano > ANO_MAXIMO;
        
            while(anoInvalido){
                cout << "Ano Inválido, por favor digite novamente: ";
                cin >> ano;

                anoInvalido = ano < ANO_MINIMO || ano > ANO_MAXIMO;
            }

            this->ano = ano;
        }

        void imprimirData(){
            cout << this->dia << "/" << this->mes << "/" << this->ano << endl;       
        }

        Data(int dia, int mes, int ano){
            setDia(dia);
            setMes(mes);
            setAno(ano);
        }

        Data(int dia, int mes){
            setDia(dia);
            setMes(mes);
            setAno(ANO_MAXIMO); // ano atual
        }
        Data(){
            int dia,mes,ano;

            cout << "Por favor, digite uma data: ";
            scanf("%d/%d/%d",&dia, &mes, &ano);

            setDia(dia);
            setMes(mes);
            setAno(ano);

        }
};

class Aluno {
    
    private:
        string nome;
        Data Nascimento;

    public:
        Aluno(){

        }

        ~Aluno(){
            cout << "O aluno morreu kkkkkkkkkkkkkkkkkkkkkkkkkk";
        }
    
};

int main(){
    Data TESTE = Data();
    TESTE.imprimirData();
    //Aluno firmino;
}