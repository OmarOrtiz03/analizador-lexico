#include <bits/stdc++.h>

using namespace std;
//definicion de las variables
int tokenreservadas;
int cont=0;
string linea,token,cadenat[100],cadenavacia;
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

int main()
{
    //este es el main por el momento hay cosas temporales sobretodo como separo las cadenas
    getline(cin,linea);
    for (int i = 0; i <linea.length(); i++){
        if (linea[i] == 32 or linea[i] == 10){
            cadenat[cont] = token;
            token =cadenavacia;
            cont++;
        }
        else{
            token += linea[i];
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