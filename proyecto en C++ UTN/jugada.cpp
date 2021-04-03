#include "jugada.h"
#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <sstream>
#include <cctype>
#include <ctime>
#include <cstdlib>



void jugada (char matriz[filasT][columnasT], char matrizvisible[filasT][columnasT], int maximofila, int maximocolumna, int minas,int contadorPart[Tam], int &tiempo){	
	
	int cordenadasreveladas=0;
	int celdasnobombas=(maximofila*maximocolumna)-minas;
	int filajugada, columnajugada;
	char jugada,eleccion;
	bool termino=false;	
	string fj, cj;
	clock_t start = clock();
	
	contadorPart[0]+=1;
	do{
		
		system ("cls");
		//muestra la matriz visble		
		mostrarMatriz (matrizvisible, maximofila,maximocolumna);		
		
		cout<<"Ingrese una acción."<<endl<<"'M' para marcar/desmarcar una posición como mina."<<endl<<"'D' para descubrir una posición."<<endl
			<<"'K' para volver al menú"<<endl;
		cout<<"Ingrese las coordenadas de la posición a descubirir"<<endl;
		
		cin>>jugada;
		
		if(jugada=='K'||jugada=='k'){ system ("cls");
		cout<<"¿Está seguro que quiere salir del juego?"<<endl;
		cout<<"Si su respuesta es SI precione S/s, de lo contrario presiones N/n"<<endl;
		cin>>eleccion;
		if(eleccion=='S' || eleccion=='s'){
			termino=true;
			contadorPart[3]+=1;
			cout<< "Usted ha salido del nivel con éxito."<<endl;
			
			system("pause");}
		}else if(jugada=='M'||jugada=='m'||jugada=='d'||jugada=='D'||jugada=='g'){
			cout<<"Ingrese la fila: ";
			cin>>fj;
			cout<<"Ingrese la columna: ";
			cin>>cj;		
			
			filajugada= valorValido (fj) ;
			columnajugada= valorValido (cj);
			if(filajugada>=0 && filajugada<maximofila && columnajugada>=0 && columnajugada<maximocolumna){//CONTROLA EL RANGO DE LA FUNCION
				
				if (matrizvisible[filajugada][columnajugada]!='/'&& matrizvisible[filajugada][columnajugada]!='M'){
					// NOS DEVUELVE ERROR SI QUEREMOS MARCAR O DESMARCAR ALGO QUE YA ESTA DESMARCADO
					cout<<"Esta coordenada ya fué Revelada"<<endl;		
					system ("pause");
				}
				if(matrizvisible[filajugada][columnajugada]=='M' && (jugada=='D' || jugada== 'd')){
					cout << "Desmarca esta casilla para poder destruirla" << endl;
					system ("pause");
				}
				else if (cordenadasreveladas==celdasnobombas||jugada=='g'){system ("cls");
				//ESTA FUNCION NOS DEVUELVE LA MATRIZVISIBLE EN EL CASO DE QUE EL JUGADOR GANE.		
				
				cout<<"Ganó el juego."<<endl;	contadorPart[1]+=1;
				mostrarMatriz (matriz, maximofila, maximocolumna);
				tiempo =(((double)clock() - start) / CLOCKS_PER_SEC);
				cout << "El tiempo transcurrido es: " << tiempo << " segundos" << endl;
				
				system ("pause");
				
				termino=true;
				
				}else if(matriz[filajugada][columnajugada]=='*'&&  (jugada== 'D'||jugada== 'd')){// Si explota todo
					//ESTA FUNCION NOS DEVUELVE LA MATRIZVISIBLE EN EL CASO DE QUE EL JUGADOR PIERDE.
					system ("cls");
					cout<<"HAS EXPLOTADO UNA MINA"<<endl << "GAME OVER" << endl;		contadorPart[2]+=1;	
					mostrarMatriz (matriz, maximofila, maximocolumna);		
					termino=true;
					//PlaySound((LPCSTR) "explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
					
					PlaySound("explosion.wav", NULL, SND_ASYNC);
					
					system ("pause");
				}else if (matriz[filajugada][columnajugada]!='*' && (jugada== 'D'||jugada== 'd')){//No exploto nada
					
					cordenadasreveladas++;
					int contador=0;
					for(int i=filajugada-1;i<=filajugada+1;i++){//Esto estaba mal
						for(int j=columnajugada-1; j<=columnajugada+1;j++){
							if( matriz[i][j]=='*'){
								contador++;
							}}
					}			
					contador= contador+48; //convierte el numero decimal a el valor equivalente de la tabla ASCII
					matrizvisible[filajugada][columnajugada]=contador;
				}else if (matrizvisible[filajugada][columnajugada]=='/' && (jugada=='M' || jugada== 'm')){
					matrizvisible[filajugada][columnajugada]='M';// SIRVE PARA MARCAR UN CASILLERO 
				}
				else if (matrizvisible[filajugada][columnajugada]=='M' && (jugada=='M' || jugada== 'm')){//Desmarca la cordenada
					
					matrizvisible[filajugada][columnajugada]='/';//SIRVE PARA DESMARCAR EL CASILLERO
				}
				
			}else{
				cout<<"Entrada no válida o fuera de intervalo, intentelo nuevamente."<<endl; system ("pause");
				
			}}else{ cout<<"Ingrese una letra válida"<<endl; system("pause");}
	}while(termino!=true);
}
	//ESTA FUNCION DEVUELVE UN ENTERO SI EL STRING QUE PASAN POR PARAMETRO NO CONTIENE UNA LETRA SINO DEVUELVE -1
	int valorValido (string a){
		int tam= a.size();//size es para obtener el tamaño de a
		char aux;
		bool bandera=false;
		for (int i=0; i<tam; i++){
			aux=a[i];
			if(isalpha(aux)){//convertimos el valor ubicado en la posicion en la que estamos de a en un char para poder verificar de no sea letra si es letra pasa bandera a true.
				bandera=true;
			}
		}
		
		if(!bandera){//mientras bandera distinta de true se transforma el string a entero  y lo retorna
			return (stoi(a));
		}else {//en el caso contrario devuelve el -1.
			return -1;
		}
		
	}
		
		void imprimirLinea(int columna ){
			
			for(int i=0;i<columna;i++){
				cout<<"----";
			}cout<<"---";
		}
			void mostrarMatriz (char matriz[filasT][columnasT], int fila, int columna){
				imprimirLinea(columna);cout<<endl;
				for(int x=0;x<columna;x++){
					if(x==0){
						cout<<"|  |"<<x;	
					}else if(x<10){cout<<" | "<<x;}else{
						cout<<" |"<<x;
					}
				}cout<<" |"<<endl;
				imprimirLinea(columna);cout<<endl;
				for(int i=0; i<fila; i++){
					
					for(int j=0; j<columna;j++){
						if (j==0){
							if(i<10){
								cout<<"|"<<i<<" |";
							}else{
								cout<<"|"<<i<<"|";
							}
						}
						cout<<matriz[i][j]<<" | ";
						if(j+1==columna){cout<<endl;
						imprimirLinea(columna);
						}
					}
					cout<<endl;
				}
			}

