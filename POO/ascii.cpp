#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int cod_ascii(char caracter){

    int valoare;

    valoare = int(caracter);

    return valoare;

}

int main(){
    ifstream f("date.in");
    ofstream g("date.out");

    if(!f){
        cout<<"Fisierul de intrare nu s-a putut deschide";
        return 1;
    }
    if(!g){
        cout<<"Fisierul de iesire nu s-a putut deschide";
        return 1;
    }

    char caracter;



    while(!f.eof()){
        f>>caracter;
        g<<cod_ascii(caracter)<<endl;
    }

    f.close();
    g.close();

    return 0;
}