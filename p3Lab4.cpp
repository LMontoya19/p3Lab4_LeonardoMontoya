#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int** crearmatriz(int);
void printmatriz(int,int**);
void submatriz(int,int,int,int**);
void ejercicio3(int x,int y,int**);
void printmatriz2(int x,char** mat);
int main(){
  char resp = 's';
  while(resp=='s'){
    cout<<"***MENU***"<<endl;
    cout<<"1)Ejercicio 1"<<endl;
    cout<<"2)Ejercicio 2"<<endl;
    cout<<"3)Salir"<<endl;
    cout<<"Ingrese su opcion"<<endl;
    int opcion;
    cin>>opcion;
    cout<<endl;
    while (cin.fail()){
      cin.clear();
      cin.ignore();      
      cout<<"No ingreso un numero"<<endl;
      cout<<"***MENU***"<<endl;
      cout<<"1)Ejercicio 1"<<endl;
      cout<<"2)Ejercicio 2"<<endl;
      cout<<"3)Salir"<<endl;
      cout<<"Ingrese su opcion"<<endl;
      cin>>opcion;    
    }
    switch(opcion){
    	case 1 :{
		int size;
		int** matriz;
		cout<<"Ingrese el numero tamaño"<<endl;
		cin>>size;
		while(cin.fail()||size<=0){
			if(cin.fail()){
			    cin.clear();
			    cin.ignore();
			    cout<<"No ingreso un numero"<<endl;
			}else{
			    cout<<"Numero ingresado no es valido"<<endl;
			}
			cin>>size;
			cin.clear();
		}//Ingresar size 
		matriz = crearmatriz(size);
		cout<<"Matriz"<<endl;
		printmatriz(size,matriz);
		int num1,num2;
		cout<<"Ingrese el primer numero"<<endl;
                cin>>num1;
		while(cin.fail()||num1<0||num1>size-1){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>num1;
                        cin.clear();
                }
		cout<<"Ingrese el segundo numero"<<endl;
                cin>>num2;
		while(cin.fail()||num2<0||num2>size-1){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>num2;
                        cin.clear();
                }
		submatriz(num1,num2,size,matriz);
		cout<<"El numero de esa posicion es: ";
		  if((num1%2==0&&num2%2==0)||(num1%2!=0&&num2%2!=0)){
                cout<<"+"<<matriz[num1][num2]<<endl;
              }else{
                cout<<(matriz[num1][num2])*-1<<endl;
	      }
		}//fin case1
	case 2:{
	       char** tablero;
	       tablero = new char*[8];
	       for(int i=0;i<8;i++){
  		  tablero[i] = new char[8];
   	        }
		for(int i = 0;i<8;i++){
		      for(int j = 0;j<8;j++){
          		tablero[i][j] = '*';
      			}
  		}
		tablero[3][3]='A';
		tablero[4][4]='A';
	        tablero[4][3]='R';
	        tablero[3][4]='R';
		printmatriz2(8,tablero);
		int contador=0;
		while(contador<60){
		int x,y;
		cout<<"Turno Jugador 1: "<<endl;
		cout<<"Ingrese primera coordenada: "<<endl;
		cin>>x;
                while(cin.fail()||x<0||x>7){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>x;
                        cin.clear();
                }
		cout<<"Ingrese Segunda coordenada: "<<endl;
		cin>>y;
                while(cin.fail()||y<0||y>7){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>y;
                        cin.clear();
                }
		cout<<"Turn jugador 2:  "<<endl;
		cout<<"Ingrese primera coordenada: "<<endl;
                cin>>x;
                while(cin.fail()||x<0||x>7){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>x;
                        cin.clear();
                }
                cout<<"Ingrese Segunda coordenada: "<<endl;
                cin>>y;
                while(cin.fail()||y<0||y>7){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore();
                            cout<<"No ingreso un numero"<<endl;
                        }else{
                            cout<<"Numero ingresado no es valido"<<endl;
                        }
                        cin>>y;
                        cin.clear();
                }

		contador+=2;
		}
	       }
    
    }
   }

}
int** crearmatriz(int x){
  int ** retval = new int*[x];
  for(int i=0;i<x;i++){
  retval[i] = new int[x];
  }
  for(int i = 0;i<x;i++){
      for(int j = 0;j<x;j++){
          retval[i][j] = 1+rand() %6;
      }
  }
  return retval;
}

void printmatriz(int x,int** mat){
 for(int i = 0;i<x;i++){
   for(int j=0;j<x;j++){
	cout<<mat[i][j];
   }
   cout<<endl;
 }
}
void submatriz(int num1,int num2,int size,int** matriz){
for(int i = 0;i<num1;i++){
                      for(int j=0;j<num2;j++){
                        cout<<matriz[i][j];
                   }

                      for(int n=num2+1;n<size;n++){
                        cout<<matriz[i][n];
                      }
                cout<<endl;
                }
                for(int k = num1+1;k<size;k++){
                    for(int j=0;j<num2;j++){
                        cout<<matriz[k][j];
                    }
                    for(int n=num2+1;n<size;n++){
                        cout<<matriz[k][n];
                     }

                 cout<<endl;
                }
}
void printmatriz2(int x,char** mat){
 for(int i = 0;i<x;i++){
   if(i==0){
	cout<<" ABCDEFGH"<<endl;
   }
   for(int j=0;j<x;j++){
	if(j==0){
	cout<<i;
	}
        cout<<mat[i][j];
   }
   cout<<endl;
 }
}

