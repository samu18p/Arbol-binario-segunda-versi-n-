#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	Nodo *derecho;
	int dato;
	Nodo *izquierdo;
};

void menu();
Nodo *nDinamico(int dato);
void inNodo(Nodo *&,int);
void imprimirDatos(Nodo *,int);
int numeroRepetido(int [],int&,int);

int main(){
	char opcion;//Variable para movernos dentro del switch
	Nodo *arbol=NULL;//Creando nodo arbol tipo puntero apuntando a NULL
	int *numero;
	int numDatos;
	
	do{
		int contador=0;//Contador para aumentar espacion al imprimir datos dentro de do while para volver a inicializarce en 0
		int contador2=0;
		int auxNum;
		menu();//Llamando a funcion menu
		cin>>opcion;
		fflush(stdin);
		switch(opcion){
			case '1':
				cout<<"\n\t1.Ingresar datos."<<endl;
				cout<<"Cuantos numeros desea agregar? "; cin>>numDatos;
				numero = new int[numDatos];
				for(int i=0; i<numDatos; i++){
					cout<<"Ingresar numero "<<i+1<<" :"; cin>>numero[i];
					auxNum=numero[i];
					contador2+=1;
					numero[i]=numeroRepetido(numero,auxNum,contador2);
					auxNum=numero[i];
					nDinamico(auxNum);
					inNodo(arbol,auxNum);
				}
				break;
			case '2':
				cout<<"\n\t2.Mostrar datos.\n\n\n";
				imprimirDatos(arbol,contador);
				cout<<endl;
				break;
			case '3':
				cout<<"\nSalio del programa."<<endl;
				break;
			default:
				
				cout<<"\nError: Opcion invalida."<<endl;
				break;
		}
		cout<<"\nPresione una tecla para continuar.."<<endl;
		getch();
		system("cls");
	}while(opcion !='3');
	
	return 0;
}

//Funcion para mostrar menu al usuario
void menu(){
	cout<<"\tMENU"<<endl
	    <<"1.Ingresar datos tipo entero."<<endl
	    <<"2.Mostrar datos."<<endl
	    <<"3.Salir."<<endl
	    <<"Ingresar el numero de opcion que desea ejecutar: ";
	    
}
//Funcion tipo nodo para crear nuevo nodo usando memoria dinamica
Nodo *nDinamico(int dato){
    Nodo *nNodo = new Nodo();
    //Los nodos hijos estaran vacion en el nuevo nodo
	nNodo->dato = dato;//Nodo raiz
	nNodo->derecho = NULL;//Nodo hijo
	nNodo->izquierdo = NULL;//Nodo hijo
	
	return nNodo;//Retornando el nuevo nodo con su nuevo valor
}

//Funcion para insertar el nodo 
void inNodo(Nodo *&arbol,int dato){
	
	if(arbol==NULL){
		Nodo *nNodo = nDinamico(dato);
		arbol = nNodo;
	}else{
		if(dato < arbol->dato){
			inNodo(arbol->izquierdo,dato);
		}else{
			inNodo(arbol->derecho,dato);
		}
	}
}
//Funcion para imprimir datos del arbol
void imprimirDatos(Nodo *arbol,int contador){
	
	if(arbol == NULL){
		return;
	}else{
		imprimirDatos(arbol->derecho,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		imprimirDatos(arbol->izquierdo,contador+1);
	}
	
}
//Funcion para verificar que el numero introducido no se repita
int numeroRepetido(int numero[],int &auxNum,int contador2){
	
	if(contador2>1){
	    for(int i=0; i<contador2-1;i++){
		    if(numero[i]==auxNum){
			    cout<<"\nEl numero "<<numero[i]<<" es igual al numero ingresado "<<auxNum<<endl;
			    cout<<"\nIngresar otro numero diferente: "; cin>>auxNum;
			    numeroRepetido(numero,auxNum,contador2);
    		}
	    }
	}else{
		return auxNum;
	}
	return auxNum;
}


