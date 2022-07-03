#include <iostream>
#include "ctime"
using namespace std;

class Persona{
    public:
        string nombre;
        int edad;
        float estatura;
};
class Estudiante: public Persona{
    public:
        string cursos;
};
template <class K>
void mostrarClase(K *ptr, int n){
    cout<<"\n\t...TABLA..."<<endl;
    cout<<"N° \tEdad \tEstatura \tNombre"<<endl;
    for (int i = 0; i < n; i++){
        cout<<i+1<<"\t"<<ptr[i].edad<<"\t"<<ptr[i].estatura<<"\t\t"<<ptr[i].nombre<<endl;
    }
}


template <class T>
bool compareMayorClase(T x, T y, string t){
    if(t=="edad")
        return x.edad >= y.edad;
    else if(t=="estatura")
        return x.estatura >= y.estatura;
    else
        return x.nombre >= y.nombre;
}
template <class T>
bool compareMenorClase(T x, T y, string t){
    if(t=="edad")
        return x.edad <= y.edad;
    else if(t=="estatura")
        return x.estatura <= y.estatura;
    else
        return x.nombre <= y.nombre;
}
template <class C>
void insertionsortClase(C * ptr, int size, bool(*p)(C, C, string), string aux){
    for (int i = 1; i < size; i++){
        C temp = ptr[i];
        int j=i-1;

        while (j>=0 && p(temp,ptr[j],aux) ){
            ptr[j+1] = ptr[j]; 
            j--;
        }   
        ptr[j+1]=temp;
    }    
}

int main(){
    string names[]={"Leonidas","Aldo","Jose","Pedro"};
    int edades[]={ 23, 18, 32, 20};
    float esta[]={ 1.74, 1.83, 1.62, 1.74}; 

    Estudiante *ptr = new Estudiante[4];    
   
    for (int i = 0; i < 4; i++){
        ptr[i].nombre = names[i];
        ptr[i].edad = edades[i];
        ptr[i].estatura = esta[i];
    }
    
    mostrarClase(ptr, 4);
    //mostrarClase(arar, 4);
    insertionsortClase(ptr,4,compareMenorClase,"estatura");
    //insertionsortClase(arar,4,compareMenorClase,"nombre");
    //mostrarClase(arar, 4);
    mostrarClase(ptr,4);

    return 0;
}