#include <bits/stdc++.h>

using namespace std;
//definicion de las variables
int tokenreservadas;
int cont,iteradorCad;
string linea,token,cadenat[100],tokencadena,cadenavacia;
string reservadas[13]={"and","else","false","for","fun","if","null","or","print","return","true","var","while"};
//Funcion para identificacion de las palabras reservadas
bool palabrasR(string linea){
    tokenreservadas=0;
    for (int i = 0; i < 13; i++)
    {
        if (linea==reservadas[i]){
            if (i==0) tokenreservadas=1;
            if (i==1) tokenreservadas=2;
            if (i==2) tokenreservadas=3;
            if (i==3) tokenreservadas=4;
            if (i==4) tokenreservadas=5;
            if (i==5) tokenreservadas=6;
            if (i==6) tokenreservadas=7;
            if (i==7) tokenreservadas=8;
            if (i==8) tokenreservadas=9;
            if (i==9) tokenreservadas=10;
            if (i==10) tokenreservadas=11;
            if (i==11) tokenreservadas=12;
            if (i==12) tokenreservadas=13;
            return true;
        }
    }
    return false;
}

string Racionales(char token,int posicion){
    switch (token){
    case '>':
        if (linea[posicion+1]=='=') return "GE";
        else return "GT";
        break;
    case '<':
        if (linea[posicion+1]=='=') return "LE";
        else return "LT";
        break;
    case '=':
        if (linea[posicion+1]=='=') return "EQO";
        else return "EQ";
        break;
    case '!':
        if (linea[posicion+1]=='=') return "NE";
        else return "BANG";
        break;
    default:
        return "UNKNOWN";
        break;
    }
}

bool Icadenas(string linea,int posicion){
    posicion ++;
    for (posicion; posicion < linea.length(); posicion++){
        if(linea[posicion]=='"') return true;
        tokencadena += linea[posicion];
        iteradorCad++;
    }
    return false;
}

int main()
{
    //este es el main por el momento hay cosas temporales sobretodo como separo las cadenas
    getline(cin,linea);
    for (int i = 0; i <linea.length(); i++){
        if (linea[i]=='"'){
            if(Icadenas(linea,i)==true){
                cout<<tokencadena<<"\n";
                tokencadena=cadenavacia;
                i=iteradorCad+i+2;
                iteradorCad=0;
            }
            else {
                cout<<"ERROOOOOOOOOR"<<"\n";
                //break;
            }
        }
        if (linea[i] == '>' || linea[i] == '<' || linea[i] == '=' || linea[i] =='!'){
            if (linea[i-1] != '>' && linea[i-1] != '<' && linea[i-1] != '=' && linea[i-1] !='!'){
                cout<<Racionales(linea[i],i)<<"\n";
            }
        }
        if ( (linea[i] >= 65 && linea[i] <= 90) || (linea[i] >= 97 && linea[i] <= 122) ){
            token += linea[i];
        }
        else{
            cadenat[cont] = token;
            token =cadenavacia;
            cont++;
        }
    }
    cout << "Palabras reservadas: ";
    for(int i=0; i<cont; i++){
        if(palabrasR(cadenat[i])==true){
            cout << cadenat[i] <<" ";
        }
    }
    cout<<"\n";
    cout << "Identificadores: ";
    for(int i=0; i<cont; i++){
        if(palabrasR(cadenat[i])==false){
            cout << cadenat[i] <<" ";
        }
    }
    return 0;
}