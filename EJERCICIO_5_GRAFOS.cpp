#include "iostream"
#include "vector"
#include <stdexcept>

using namespace std;

// Generar una clase grafo
template <class T>
class Graph{
public:

    vector <vector <T>> nodo;
    vector<T>* aux; //almacena la direccion de memoria del vector que contiene los nodos adyacentes
    
    ~Graph();
    Graph(const vector <T> &starts, const vector<T> &ends);
    int numOutgoing(const int nodeID) const;
    const vector<T> & adjacent(const int nodeID) ;
    void print();

};

// desctructor 
template <class T>
Graph<T>::~Graph(){}

// constructor de la clase grafo: con dos vectores como argumentos
template <class T>
Graph<T>::Graph(const vector<T> &starts, const vector<T> &ends){
    nodo.resize(5);
    for (int i=0; i < starts.size(); i++){
        nodo[starts[i]-1].push_back(ends[i]);
    }

}

// imprimir el nodo y sus nodos adyacentes
template <class T>
void Graph<T>::print(){
    int k=1;
    cout<<"Nodos \tNodos Adayacentes"<<endl;
    for (auto i = nodo.begin(); i!=nodo.end(); i++){
        cout<<k<<"  --> \t";
        for (auto j = (*i).begin(); j != (*i).end() ; j++){
            cout<<*j<<" ";
        }
        k++;
        cout<<endl;
    }
}

// devolver el numero de nodos adyacentes a un nodo ingresado por el usuario
template <class T>
int Graph<T>::numOutgoing(const int nodeID) const{
    int n;
    for (int i = 0; i < 5; i++){
        if(i==(nodeID-1)){
            n=nodo[i].size();
        }
    }
    return n;
}


// devolver la direccion del vector de los nodos adyacentes a un nodo ingreado por el usuario
template <class T>
const vector<T>& Graph<T>::adjacent(const int nodeID) {

    if(numOutgoing(nodeID)>0){
        for(int i=0;i<5;i++){
            if(i==nodeID-1){
                aux =&nodo[i];  
                break;
            }
        }
    }else{
        for (int i = 0; i < nodo.size(); i++){
            if(numOutgoing(i+1)==0){
                aux=&nodo[i];
                break;
            }
        }
        
    }
    return *aux;
    
}

int main(){

    vector<int> start = {1 ,1 ,1, 5, 5, 4};
    vector<int> end   = {2, 3, 4, 4, 2, 2};
    Graph <int> grafo(start,end);
    grafo.print();

    // NODO A INGRESAR
    int n=1; 
    cout<<endl;

    // RESULTADOS
    cout<<"Numero de nodos adjayecentes a "<<n<<": "<<grafo.numOutgoing(n)<<endl;
    cout<<endl;
    
    // obtener los nodos adyacentes en un vector
    vector <int> dd= grafo.adjacent(n);
    cout<<"Nodos adayacentes a "<<n<<": "<<endl;
    for(auto i=dd.begin();i!=dd.end();i++ ){
        cout<<*i<<" ";
    }
    
    cout<<endl;
    return 0;
    system("pause");
}
