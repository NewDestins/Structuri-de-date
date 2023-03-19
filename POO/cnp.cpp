#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

string cnp_gresit(string cnp){
    string gresit = "Cnp-ul '" + cnp + "' este gresit";
    return gresit;
}

int main(){

    //data curenta
    time_t now = time(0);
    tm* Itm = localtime(&now);
    int an_curent = 1900+Itm->tm_year;
    int luna_curenta = 1+Itm->tm_mon;
    int zi_curenta = Itm->tm_mday;

    string sexul;


    string cnp;
    int SEX, AN, VARSTA, LUNA, ZI;

    
    ifstream f("date.in");
    ofstream g("date.out");
    if( ! f ){
        cout<<"Nu s-a putut deschide fisierul de introducere";
        return -1;
    }

    while(!f.eof()){
        //citirea cnp-ului
        f>>cnp;

        bool a = true;

        while(a == true){

            //verificare dimensiune
            if(cnp.size() != 13){
                g<<cnp_gresit(cnp)<<endl<<endl;
                break;
            }

            SEX = stoi(cnp.substr(0, 1));
            AN = stoi(cnp.substr(1, 2));

            if(SEX % 2 == 0)
                sexul = "feminin";
            else
                sexul = "masculin";

            switch (SEX)
            {
            case 1:
                AN = 1900 + AN;
                break;
            case 2:
                AN = 1900 + AN;
                break;
            case 3:
                AN = 1800 + AN;
                break;
            case 4:
                AN = 1800 + AN;
                break;
            case 5:
                AN = 2000 + AN;
                break;
            case 6:
                AN = 2000 + AN;
                break;
            default:
                g<<cnp_gresit(cnp)<<endl<<endl;
                goto exit_loop;
                break;
            }


            LUNA = stoi(cnp.substr(3, 2));
            if(LUNA > 12){
                g<<cnp_gresit(cnp)<<endl<<endl;
                break;
            }
            ZI = stoi(cnp.substr(5, 2));
            if(ZI > 31 || ZI == 0){
                g<<cnp_gresit(cnp)<<endl<<endl;
                break;
            }

            //calcul varsta
            if(luna_curenta<LUNA)
                VARSTA = (an_curent - 1) - AN;
            if(luna_curenta == LUNA){
                if(zi_curenta<ZI)
                    VARSTA = (an_curent - 1) - AN;
                else
                    VARSTA = an_curent - AN;
            }
            if(luna_curenta>LUNA)
                VARSTA = an_curent - AN;

            g<<"Cnp-ul este: "<<cnp<<endl;
            g<<"Sexul este: "<<sexul<<endl;
            g<<"Anul nasterii este: "<<AN<<endl;
            g<<"Luna nasterii este: "<<LUNA<<endl;
            g<<"Ziua nasterii este: "<<ZI<<endl;
            g<<"Varsta este :"<<VARSTA<<endl<<endl;
            exit_loop: ;
            break;}
        }
            
    
    f.close();
    g.close();
    return 0;
}