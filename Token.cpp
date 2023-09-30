#include <bits/stdc++.h>

using namespace std;
//definicion de las variables

int cont=0;
string linea,token,cadenat[100],cadenavacia;
string reservadas[13]={"and","else","false","for","fun","if","null","or","print","return","true","var","while"};
//Funcion para identificacion de las palabras reservadas
bool palabrasR(string linea){
    for (int i = 0; i < 13; i++)
    {
        if (linea==reservadas[i]) return true;
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
    for(int i=0; i<cont; i++){
        if(palabrasR(cadenat[i])==true){
            cout << cadenat[i] <<" ";
        }
    }
    return 0;
}