#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string este_palindrom(string cuvant){

    string p = cuvant;
    
    reverse(p.begin(), p.end());

    if(p == cuvant){
        return "ESTE PALINDROM \n";
    }
    else{
        return "NU ESTE PALINDROM \n";
    }

}

int main(){

    string cuvant;

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


    while (!f.eof()){
        f>>cuvant;
        g<<este_palindrom(cuvant);
    }

    return 0;
}