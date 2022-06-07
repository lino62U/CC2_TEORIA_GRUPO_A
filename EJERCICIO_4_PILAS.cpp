#include "iostream"
#include "vector"
using namespace std;


// pila generica 
template <class T>
class Stack{
    public:
        vector<T> datos;
        bool empty() const;
        void push(const T&);
        void pop();
        T &top();
        void print();
};

//metodo para verificar si la pila se encuentra vacia
template <class T>
bool Stack<T>::empty()const{
    return datos.empty();
}

//metodo para ingresar un elemento generico a la pila
template <class T>
void Stack<T>::push(const T &item){
    datos.push_back(item);
}

// eliminar el elemento mas reciente ingresado a la pila (last input)
template <class T>
void Stack<T>::pop(){
    datos.pop_back();
}

// devolver el elemento mas reciente ingresado a la pila (last input)
template <class T>
T &Stack<T>::top(){
    return datos[datos.size()-1];
}

//imprimir pila
template <class T>
void Stack<T>::print(){
    for (auto i = datos.begin(); i != datos.end(); ++i)
        cout << *i << " ";
}

// sobrecarga del operador + 
template <class T>
Stack<T> operator+(Stack <T> const a,Stack <T> const b){
    Stack <T> tmp;
    tmp=a;
    for (auto i = b.datos.begin(); i != b.datos.end(); ++i)
        tmp.push(*i);
    return tmp;
}

int main(){
    Stack <int> a,b;
    // ingresar elementos tipo int al objeto a
    a.push(3);
    a.push(5);
    a.push(9);
    a.pop();     //eliminar el elemento mas reciente ingresado (last  input = 9)
    cout<<"\n"<<a.top()<<endl; // devolver el ultimo elemento 
    cout<<"\nPila a: ";a.print();
   
    // ingresar elementos tipo int al objeto b
    b.push(8);
    b.push(2);
    cout<<"\nPila b: ";b.print();
    
    //suma de pilas mediante la sobrecarga del operador +
    Stack <int>c= a+b;
    cout<<"\nPila c = a + b: ";
    c.print();  //
    
    
    return 0;
    system("pause");
}
