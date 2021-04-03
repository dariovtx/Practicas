#include <iostream>
#include <windows.h>
#include <stdio.h> 
#include <sstream>
#include <mmsystem.h>
#include "jugada.h"
#define f 110
#define c 110
#define filasT 16
#define columnasT 30
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <istream>
#include <cstring>
#include <cstdio>
#include <string>
#include <fstream>
using namespace std;
void gotoxy(int x,int y);
void menu ( char inicio[f][c]);
void pintar();
void presentacion(char inicio[f][c]);
void logo_inicial(char inicio[f][c]);
int aleatorioEnRango(int minimo, int maximo);
int valorValido (string a);
void colocarMinasAleatoriamente(char tablero[filasT][columnasT],int maximofila, int maximocolumna, int cantidadminas);
void colocarMina(int fila, int columna, char tablero[filasT][columnasT]);
void jugada (char matriz[filasT][columnasT], char matrizvisible[filasT][columnasT], int maximofila, int maximocolumna, int minas);
void mostrarMatriz (char matriz[filasT][columnasT], int fila, int columna);


//Codigo Inicio Etapa 2
struct Puntaje{
	int mejorPuntaje;
	int dia;
	int mes;
	int anio;
};
struct Usuario{
	int TLN;//Tamaño logico usuario
	int TLC;//tamaño logico contraseña
	int TLP1,TLP2,TLP3;
	char nombreUs[10];
	char contrasenaUs[12];
	
	//contadorN 0-Partidas jugadas, 1-Partidas Ganadas, 2-Partidas Perdidas, 3- Partidas Abandonadas.
	int contadorN[4];
	
	//porcentajeN 0-Porcentaje de Victorias, 1-Porcentaje de Perdidas, 2-Porcentaje de Abandonadas
	int porcentajeN[3];
	
	Puntaje nivel1[10];
	Puntaje nivel2[10];
	Puntaje nivel3[10];
	Usuario* sigUsuario;
};

typedef struct Usuario * UsuarioPtr;
void menu (char inicio[f][c] , UsuarioPtr &listaUs, char Us[10],int TLN);
int Jugar(int nivel,UsuarioPtr &listaUs, char Us[10], int TLN);
/* Imprime la lista */

void verpuntaje(char inicio[f][c] , UsuarioPtr &listaUs, char Us[10],int TLN,int contadorUs,UsuarioPtr &listaAux);



bool estaIncluido(char nombre[10],UsuarioPtr listaAux){
	if(listaAux!=NULL){
	
		if(strcmp(nombre,listaAux->nombreUs)==0){ cout<<strcmp(nombre,listaAux->nombreUs);system("pause");
			return true;
		
	}else{return estaIncluido(nombre,listaAux->sigUsuario);}
	}else{return false;}
}
void rankinUsuario(UsuarioPtr listaUs,UsuarioPtr &listaAux){

	UsuarioPtr nuevoNodo = new Usuario();
	UsuarioPtr &nodoFin=listaAux;
	//bool bandera=false;
	if(listaUs!=NULL){
		if(listaAux==NULL){
		strncpy(nuevoNodo->nombreUs,listaUs->nombreUs,listaUs->TLN);
		nuevoNodo->porcentajeN[0]=listaUs->porcentajeN[0];
		nuevoNodo->porcentajeN[1]=listaUs->porcentajeN[1];
		nuevoNodo->porcentajeN[2]=listaUs->porcentajeN[2];
		nuevoNodo->sigUsuario=NULL; 
	    listaUs=listaUs->sigUsuario;
		}else{
			nuevoNodo->porcentajeN[0]=0;
			nuevoNodo->porcentajeN[1]=0;
			nuevoNodo->porcentajeN[2]=0;
			nuevoNodo->sigUsuario=NULL;
		}
		
		while(listaUs!=NULL){
			if(estaIncluido(listaUs->nombreUs,listaAux)!=true){cout<<"llego";system("pause");
				if(nuevoNodo->porcentajeN[0]<listaUs->porcentajeN[0]){
				strncpy(nuevoNodo->nombreUs,listaUs->nombreUs,listaUs->TLN);
				nuevoNodo->porcentajeN[0]=listaUs->porcentajeN[0];
				nuevoNodo->porcentajeN[1]=listaUs->porcentajeN[1];
				nuevoNodo->porcentajeN[2]=listaUs->porcentajeN[2];
			}}
			
		listaUs=listaUs->sigUsuario;
			
		}
		if(nodoFin!=NULL){
		while(nodoFin->sigUsuario!=NULL){
			nodoFin=nodoFin->sigUsuario;
		}nodoFin->sigUsuario=nuevoNodo;//cout<<nuevoNodo->nombreUs;system("pause");
		}else{
		nodoFin=nuevoNodo;cout<<nodoFin->nombreUs;system("pause");
		}
	}	
	
	
	/*	
	int contador=0;
	int aux=0;
	

	while(listaUs!=NULL){
		
		
		if(contador==0 && contaux==0){
			
			porcentajeGanadas=listaUs->porcentajeN[0];
			porcentajeMenorPerdidas=listaUs->porcentajeN[1];
			porcentajeMenorAbandonadas=listaUs->porcentajeN[2];
			strcpy(nombre,listaUs->nombreUs);
			TLN=listaUs->TLN;
			
			
			
		}else	if(contaux>0){
			
			strncpy(nombre,auxiliar,TLN);
			
			
		} 
		
		
		else if(strcmp(listaUs->nombreUs,auxiliar)!=0){		
			
			
			for(aux;aux<=contaux;aux++){
				
					
					if(porcentajeGanadas<listaUs->porcentajeN[0]){
						
						porcentajeGanadas=listaUs->porcentajeN[0];
						porcentajeMenorPerdidas=listaUs->porcentajeN[1];
						porcentajeMenorAbandonadas=listaUs->porcentajeN[2];		
						//strcpy(nombre,listaUs->nombreUs);
						TLN=listaUs->TLN;
						strncpy(nombre,listaUs->nombreUs,TLN);
						
						
					}
					
				
				
			}
			
		} 
		contador++;listaUs=listaUs->sigUsuario;
	}
	
	
	
	*/
}



void rankingdeusurios(UsuarioPtr listaUs, int contadorUs,UsuarioPtr &listaAux){
	
	system("cls");
	
	int contador=0;
	
	int cantidad=0;
	int ganadas=0, perdidas=0, abandonadas=0;
	
	char nombre[100][10];
	int porcentajeN[100][3]={0}, TLN=0;
	
	
	
	cout<<"Cuanto Usuarios quieres Mostrar"<<endl;
	
	cin>>cantidad;
	
	gotoxy(20,10);cout<<"| Usuario |   %Ganadas  | %Perdidas | %Abandonadas |"<<endl;
	if(cantidad<=contadorUs){
	for(int i=0; i<cantidad;i++){
	
		rankinUsuario(listaUs,listaAux);
	
		cout<<listaAux->nombreUs<<"|"<<listaAux->porcentajeN[0]<<"|"<<listaAux->porcentajeN[1]<<"|"<<listaAux->porcentajeN[2]<<"|"<<endl;
		listaAux=listaAux->sigUsuario;
	}
	/*for(int i=0; i<cantidad;i++){
		
		rankinUsuario(listaUs, nombre, TLN, ganadas, perdidas, abandonadas, auxiliar, i);
		
		
		//for(int j=0;j<10;j++){	auxiliar[i]=nombre[j];}
		strncpy(auxiliar,nombre,TLN);
		
		
		//strcpy(auxiliar,nombre);
		cout<<"|";for(int j=0; j<TLN;j++){cout<<nombre[j];}cout<<"|"<<ganadas<<"|"<<perdidas<<"|"<<abandonadas<<"|"<<endl;
		
		
	}*/
		}else{
			cout<<"No hay tantos usuarios"<<endl;
		}
}




void buscarNivel(UsuarioPtr listaUs, int &puntaje, int &TLN, char nombre[10], int nivel){
	
	int contador=0;
	
	
	if(nivel==1){
				
		while(listaUs!=NULL){//Buscar mejor puntaje nivel 1
			
			if(contador==0){//Guarda solo el primer puntaje
				
				puntaje=listaUs->nivel1[0].mejorPuntaje;
				strcpy(nombre,listaUs->nombreUs);
				TLN=listaUs->TLN;
				
			}
			else{
				
				if(puntaje>listaUs->nivel1[0].mejorPuntaje){
					
					puntaje=listaUs->nivel1[0].mejorPuntaje;
					strcpy(nombre,listaUs->nombreUs);
					TLN=listaUs->TLN;
					
				}
				
			} 
			
			contador++;listaUs=listaUs->sigUsuario;
		}
		
	}
	
	else if(nivel==2){
		
		while(listaUs!=NULL){//Buscar mejor puntaje nivel 1
			
			if(contador==0){//Guarda solo el primer puntaje
				
				puntaje=listaUs->nivel2[0].mejorPuntaje;
				strcpy(nombre,listaUs->nombreUs);
				TLN=listaUs->TLN;
				
			}
			else{
				
				if(puntaje>listaUs->nivel2[0].mejorPuntaje){
					
					puntaje=listaUs->nivel2[0].mejorPuntaje;
					strcpy(nombre,listaUs->nombreUs);
					TLN=listaUs->TLN;
					
				}
				
			} 
			
			contador++;listaUs=listaUs->sigUsuario;
		}
		
	}
	
	else if(nivel==3){
		
		
		while(listaUs!=NULL){//Buscar mejor puntaje nivel 1
			
			if(contador==0){//Guarda solo el primer puntaje
				
				puntaje=listaUs->nivel3[0].mejorPuntaje;
				strcpy(nombre,listaUs->nombreUs);
				TLN=listaUs->TLN;
				
			}
			else{
				
				if(puntaje>listaUs->nivel3[0].mejorPuntaje){
					
					puntaje=listaUs->nivel3[0].mejorPuntaje;
					strcpy(nombre,listaUs->nombreUs);
					TLN=listaUs->TLN;
					
				}
				
			} 
			
			contador++;listaUs=listaUs->sigUsuario;
		}
		
		
	}
	
	
	
	
}


void mejorPuntajePorNivel(UsuarioPtr listaUs ){
	
	system("cls");
	
	pintar();
	
	char nombre[10];
	int puntaje=0, TLN=0;
	int nivel=0;
	
	
	nivel=1;
	
	
	
	buscarNivel(listaUs, puntaje, TLN, nombre,  nivel);
	
	gotoxy(20,10);cout<<"| Nivel |   Usuario  | Puntaje |"<<endl;
	gotoxy(20,11);cout<<"|   "<< nivel<<"   |";
	gotoxy(30,11);for(int i=0; i<TLN;i++){cout<<nombre[i];};
	gotoxy(41,11);cout <<"|";
	gotoxy(46,11);cout<<puntaje;
	gotoxy(51,11);cout<<"|"<<endl;
	
	nivel=2;

	
	buscarNivel(listaUs, puntaje, TLN, nombre,  nivel);

	
	gotoxy(20,12);cout<<"|   "<< nivel<<"   |";
	gotoxy(30,12);for(int i=0; i<TLN;i++){cout<<nombre[i];};
	gotoxy(41,12);cout <<"|";
	gotoxy(46,12);cout<<puntaje;
	gotoxy(51,12);cout<<"|"<<endl;

	nivel=3;
	
	buscarNivel(listaUs, puntaje, TLN, nombre,  nivel);
	
	gotoxy(20,13);cout<<"|   "<< nivel<<"   |";
	gotoxy(30,13);for(int i=0; i<TLN;i++){cout<<nombre[i];};
	gotoxy(41,13);cout <<"|";
	gotoxy(46,13);cout<<puntaje;
	gotoxy(51,13);cout<<"|"<<endl;
	
	
}

void printLista( UsuarioPtr actual ) {	
	/* si la lista estï¿½ vacï¿½a */system("cls");
	if ( actual == NULL ) 
		cout << "La lista esta vacia.\n\n" ;
	else { 
		cout << "La lista de usuarios es:\n";
		
		/* mientras no sea el fin de la lista */
		while ( actual != NULL ) { fflush(stdin);system("pause");
			for(int i=0;i<(actual->TLC);i++){
			cout<<actual->contrasenaUs[i];
			}
			cout<<endl;
			for(int i=0;i<actual->TLN;i++){
			cout << actual->nombreUs[i] ;
			
			}cout<<endl;
			for(int i=0;i<4;i++){
				cout << actual->contadorN[i]<<" " ;
				
			}
			cout<<endl;
			for(int z=0;z<3;z++){
				
				cout << actual->porcentajeN[z]<<" " ;
				
			}
			cout<<endl;
			for(int j=0;j<actual->TLP1;j++){cout<<actual->TLP1<<" ";
				cout<<actual->nivel1[j].mejorPuntaje<<" ";
				cout<<actual->nivel1[j].dia<<" ";
				cout<<actual->nivel1[j].mes<<" ";
				cout<<actual->nivel1[j].anio<<" ";
			}
			cout<<endl;
			actual = actual->sigUsuario;   
		} 
		
		
	} /* end else */system("pause");
	
}

void crearUsuario(int &contadorUsuario , UsuarioPtr &nodo);
bool esCorrecto(UsuarioPtr listaUs, char nom[12],char cont[12],int TLN, int TLC, int ver[2]){
	int contLetraN=0,contLetraC=0;
	bool encontrado=false;
	while(listaUs!=NULL && encontrado!=true){	contLetraC=0; contLetraN=0;
		
		if(listaUs->TLN==TLN){ //compara el tamaño logico
			
			for(int i=0;i<TLN;i++){//compara los digitos
				
				if(listaUs->nombreUs[i]==nom[i]){	
					contLetraN++;		//cada vez que sean iguales los suma		
					//cout<<listaUs->nombreUs[i]<<" "<<nom[i]<<" "<<i<<" ";system("pause");
				}
				
			}}
		
		if(contLetraN==TLN){//se fija si el nombre de usuario es correcto
			ver[0]=1;			
			if(listaUs->TLC==TLC){//  verifica los tamaños logicos
				//cout<<listaUs->TLC<<" "<<TLC<<" ";
				for(int i=0;i<TLC;i++){//compara elemento a elemento
					
					if(listaUs->contrasenaUs[i]==cont[i]){
						contLetraC++;				
					}
					
				}}
			//cout<<contLetraC<<" "<<TLC<<" ";system("pause");
			if(contLetraC == TLC){//cout<<"entro";system("pause");
				encontrado=true;ver[1]=1;	
			}
		}listaUs=listaUs->sigUsuario;
	}
	return encontrado;
}
bool ingresoUsuario(UsuarioPtr listaUs, char us[10],int &TL){fflush(stdin);
	//UsuarioPtr aux;aux= *listaUs;
	int TLN,TLC,fallo=0, ver[2]={0,0};
	bool correctoUs=false;
	char nombreUs [10],contrasenaUs[12];
	
	if(listaUs!=NULL){
	
	do{
		system("cls");
    
		cout<<"presione * para salir en cualquier momento"<<endl;
	    cout<<"Ingrese su usuario: "<<endl;
	    cin>>nombreUs;
	
	if(nombreUs[0]!='*'){
	
	cout<<"Ingrese su contraseña: "<<endl;
	cin>>contrasenaUs;
	
	if(contrasenaUs[0]!='*'){
		
		TLN=strlen(nombreUs);
		TLC=strlen(contrasenaUs);
		correctoUs = esCorrecto(listaUs,nombreUs,contrasenaUs,TLN,TLC,ver);
		
		if(correctoUs==false){
		if(ver[0]==0){
			//cout<<TLC<<" "<<contLetraN<<" ";system("pause");
		fallo++;
		cout<<"Nombre de usuario inexistente."<<endl;system("pause");
	   
		}else if (ver[1]==0){
		
			cout<<"Contrasena incorrecta."<<endl;system("pause");fallo++;
		}}else{
	     
			for(int j=0; j<TLN; j++){
			  us[j]=nombreUs[j];
			}
			 TL=TLN;
	cout<<"Nombre de usuario correcto y contraseña correcta."<<endl; system("pause");
	
	}}}
	}while(correctoUs!=true && nombreUs[0]!='*' && contrasenaUs[0]!='*' && fallo < 3 );
	}else{
		cout<<"no hay usuarios creados."<<endl;system("pause");
	}
return correctoUs;
}
void menuUsuario(int& contadorUsuario,UsuarioPtr &listaUs ,char inicio[f][c],UsuarioPtr &listaAux){
	
	
	
	bool bandera=false;
	int op,TLN;
	char us[10];
	
	do{
		system("cls");
		logo_inicial(inicio);
		system("color 0F");
		pintar();
		if(contadorUsuario<=100){
			
			
			
			
			gotoxy(15,27);cout<<"1. Ingresar"<<endl;
			
			gotoxy(15,28);cout<<"2. Crear usuario"<<endl;
		
			gotoxy(15,29);cout<<"3. Ver Puntaje"<<endl;
			
			gotoxy(15,30);cout<<"4. Salir"<<endl;fflush(stdin);
				
			cin>>op;
				
				switch(op){
				
				case 1: //Ingresar
					
					
					if(ingresoUsuario(listaUs,us,TLN)){
						menu(inicio, listaUs,us,TLN);
					}
					
					break;
					
				case 2://Crear Usuario
					
					crearUsuario(contadorUsuario , listaUs);
					printLista(listaUs);
					break;
					
				case 3://Ver Puntaje
					
					verpuntaje(inicio, listaUs,us,TLN,contadorUsuario,listaAux);
					
					break;
				case 4://Salir	
					
					bandera=true;
					
					break;}
				
		}else {
			
			gotoxy(15,27);cout<<"1. Ingresar"<<endl;
			
			gotoxy(15,28);	cout<<"2. Ver Puntaje"<<endl;
			
			gotoxy(15,29);cout<<"3. Salir"<<endl;fflush(stdin);
				
			
			cin>>op;
			
				switch(op){
				
				case 1: //Ingresar
					
					if(ingresoUsuario(listaUs,us,TLN)){
						menu(inicio, listaUs,us,TLN);
					}
					
					
					break;
					
				case 2://Ver Puntaje
					
					
					
					break;
				case 3://Salir	
					
					bandera=true;
					
					break;}

		}
	
		
	}while(bandera!=true);
	
};


	
	
void verpuntaje(char inicio[f][c] , UsuarioPtr &listaUs, char Us[10],int TLN,int contadorUS,UsuarioPtr &listaAux){
	
	bool bandera=false;
	int opt, opt2;
	
	
	do{
		system("cls");
		
		
		logo_inicial(inicio);
		pintar();
		
		
		
		gotoxy(15,27);cout<<"1. Mejor puntaje por nivel:  "<<endl;
		
		gotoxy(15,28);cout<<"2. Ranking de usuarios:"<<endl;
		
		gotoxy(15,29);cout<<"3. Mejor puntaje por usuario y nivel"<<endl;
		
		gotoxy(15,30);cout<<"4. volver al Menu anterior"<<endl;
		
		cin>>opt;
		
		switch(opt){
			
		case 1: // Mejor puntaje por nivel:
			
			mejorPuntajePorNivel(listaUs);
			
			break;
			
		case 2://Ranking de usuarios
			
			rankingdeusurios( listaUs, contadorUS,listaAux);//rankingdeusurios();
			
		case 3://Mejor puntaje por usuario y nivel
			
			
			
			break;
		case 4://Salir	
			system("cls");
			
			logo_inicial(inicio);
			pintar();
			
			gotoxy(15,27);cout<<"Estas seguro que desea salir, si es así marque 1, si no marque 2"<<endl;
			
			cin>>opt2;
			
			if(opt2==1){bandera=false;}
			else if (opt2!=1 && opt2!=2){cout<<"telca invalida"<<endl;}
			break;}
		
		
		
		
		
	}while(bandera==true);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
}	

void crearUsuario(int &contadorUsuario , UsuarioPtr &nodo){
		
		int contadorContrasenaMayusculas=0;
		int contadorContrasenaMinusculas=0;
		int contadorContrasenaEspecial=0;
		int TLC,TLN;
		
		bool encontrado=false;
		char nombreUsuario[10];
		char claveUsuario[12];
		
		UsuarioPtr aux, nodoNuevo; aux=nodo;
		
		nodoNuevo = new Usuario;
		
		do{fflush(stdin);system("cls");
			cout<<"Ingrese su Nombre de Usuario"<<endl;fflush(stdin);
			
			cin>>nombreUsuario;
								
			
			TLN=strlen(nombreUsuario);
			cout<<TLN;
			if(TLN>10){
				cout<<"Se supero la cantidad maxima de 10 caracteres para el nombre"<<endl;
			
			}else { 
				if(aux!=NULL){
					while(aux!=NULL && encontrado!=true){int aux1=0;
					
					if(aux->TLN==TLN){
						for(int i=0;i<TLN;i++){
					if(aux->nombreUs[i]==nombreUsuario[i]){	
						aux1++;
						
					}}}
					if(aux1==TLN){
					cout<<"Este Usuario ya Existe "<<nombreUsuario<<endl;
					encontrado=true;system("pause");
					}
					
					aux=aux->sigUsuario;
				}}
			if(encontrado==false){
						
						cout<<"Ingrese su Contraseña de Usuario"<<endl;fflush(stdin);
						
						cin>>claveUsuario;
						
						TLC=strlen(claveUsuario);
						if(TLC>=12){
							
							cout<<"Se supero la cantidad maxima de 12 caracteres para la contraseña"<<endl;system("pause");
							encontrado=true;
						}else{
							
							for(int i=0;i<TLC;i++){
								
								if(claveUsuario[i]>=65 && claveUsuario[i]<=90){//Verficiar Mayusculas
								
								contadorContrasenaMayusculas++;
								}
								 if(claveUsuario[i]>=97 && claveUsuario[i]<=122){//verifica Minusculas
									
									contadorContrasenaMinusculas++;
								}
								 if(claveUsuario[i]=='$'||claveUsuario[i]=='#'||claveUsuario[i]=='%'||claveUsuario[i]=='&'){//verifica simbolos especiales
									
									contadorContrasenaEspecial++;
								}
							}
							if(contadorContrasenaEspecial==0 || contadorContrasenaMayusculas==0 || contadorContrasenaMinusculas==0){
								cout<<"La contraseña debe tener al menos un simbolos especiales ($#%&)"<<endl;
								cout<<"La contraseña debe tener al menos una mayuscula"<<endl;
								cout<<"La contraseña debe tener al menos una minuscula"<<endl;
								encontrado=true; system("pause");
							}
							if(encontrado==false){
								nodoNuevo->TLP1=0;nodoNuevo->TLP2=0;nodoNuevo->TLP3=0;
								for(int i=0;i<TLN;i++){
									nodoNuevo->nombreUs[i]=nombreUsuario[i];	
								}
									for(int i=0;i<TLC;i++){
										nodoNuevo->contrasenaUs[i]=claveUsuario[i];
										
									}
									nodoNuevo->TLN=TLN;
									nodoNuevo->TLC=TLC;
									for(int i=0;i<4;i++){
									
										nodoNuevo->contadorN[i]=0;
									
									if(i<3){
									nodoNuevo->porcentajeN[i]=0;
									
							}}
									nodoNuevo->sigUsuario = nodo;
									nodo = nodoNuevo;
									encontrado=true;contadorUsuario++;						
							}}}
			
		}}while(encontrado!=true);
		
	}
//Fin codigo Etapa 2
void cargarArchivo(Usuario user,UsuarioPtr lista){
	
	if(lista!=NULL){
	ofstream recordar;
	recordar.open("datosUario.bin", ios::binary );
	
	if (!recordar){
		cout<<"Error abriendo el fichero";
		
	}else{
		
		while (lista!=NULL){ 
		
			user.TLN=lista->TLN;
			user.TLC=lista->TLC;
			user.TLP1=lista->TLP1;
			user.TLP2=lista->TLP2;
			user.TLP3=lista->TLP3;
			strcpy(user.nombreUs,lista->nombreUs);
			strcpy(user.contrasenaUs,lista->contrasenaUs);
			
			for(int i=0;i<10;i++){
			
				user.nivel1[i].mejorPuntaje=lista->nivel1[i].mejorPuntaje;
				user.nivel1[i].dia=lista->nivel1[i].dia;
				user.nivel1[i].mes=lista->nivel1[i].mes;
				user.nivel1[i].anio=lista->nivel1[i].anio;
				user.nivel2[i].mejorPuntaje=lista->nivel2[i].mejorPuntaje;
				user.nivel2[i].dia=lista->nivel2[i].dia;
				user.nivel2[i].mes=lista->nivel2[i].mes;
				user.nivel2[i].anio=lista->nivel2[i].anio;
				user.nivel3[i].mejorPuntaje=lista->nivel3[i].mejorPuntaje;
				user.nivel3[i].dia=lista->nivel3[i].dia;
				user.nivel3[i].mes=lista->nivel3[i].mes;
				user.nivel3[i].anio=lista->nivel3[i].anio;
			
			if(i<4){
			user.contadorN[i]=lista->contadorN[i];
			}
			if(i<3){
			user.porcentajeN[i]=lista->porcentajeN[i];
			}
			
			}
			
			recordar.write((char*)(& user), sizeof(struct Usuario));
			
		lista=lista->sigUsuario;	
		}
	
	recordar.close();
	}}
	
}

void descargarArchivo(Usuario user,UsuarioPtr &lista, int &cant){
			
		
		int contador=0;
		
		ifstream recordar;
	    recordar.open("datosUario.bin",ios::binary );
	
		if (!recordar){ cout<<"llego";system("pause");}else{
		while ((contador * sizeof(struct Usuario))< recordar.seekg(0,ios::end).tellg()){ 
			recordar.seekg((contador) * sizeof(struct Usuario)); 
			recordar.read((char*)(& user), sizeof(user));UsuarioPtr aux=new Usuario();fflush(stdin);
			aux->TLN=user.TLN;
			aux->TLC=user.TLC;
			aux->TLP1=user.TLP1;
			aux->TLP2=user.TLP2;
		    aux->TLP3=user.TLP3;
			strcpy(aux->nombreUs,user.nombreUs);
			strcpy(aux->contrasenaUs,user.contrasenaUs);			
			for(int i=0;i<10;i++){
					aux->nivel1[i].mejorPuntaje=user.nivel1[i].mejorPuntaje;
					aux->nivel1[i].dia=user.nivel1[i].dia;
					aux->nivel1[i].mes=user.nivel1[i].mes;
					aux->nivel1[i].anio=user.nivel1[i].anio;
					aux->nivel2[i].mejorPuntaje=user.nivel2[i].mejorPuntaje;
					aux->nivel2[i].dia=user.nivel2[i].dia;
					aux->nivel2[i].mes=user.nivel2[i].mes;
					aux->nivel2[i].anio=user.nivel2[i].anio;
					aux->nivel3[i].mejorPuntaje=user.nivel3[i].mejorPuntaje;
					aux->nivel3[i].dia=user.nivel3[i].dia;
					aux->nivel3[i].mes=user.nivel3[i].mes;
					aux->nivel3[i].anio=user.nivel3[i].anio;
						
				if(i<4){
					aux->contadorN[i]=user.contadorN[i];
				}
				if(i<3){
					aux->porcentajeN[i]=user.porcentajeN[i];
				}
				
			}				
			
			contador++;
			aux->sigUsuario=lista;
			lista=aux;}}cant=contador;
	recordar.close();
}
int main() {
	char inicio[f][c] =
	{
		"                                                                                ",
			"     aaaaa    aaaaa    aaaaa                                               ",
			"      aaaaa   aaaaa   aaaaa                                                ",
			"       aaaaa  aaaaa  aaaaa                                                 ",
			"        aaaaa aaaaa aaaaa                                                  ",
			"   aaaaaaaaaaaaaaaaaaaaaaaaaaa                                             ",
			"   aaaaaaaaaaaaaaaaaaaaaaaaaaa                                             ",
			"        aaaaa aaaaa aaaaa                                                  ", 
			"       aaaaa  aaaaa  aaaaa                                                 ",
			"      aaaaa   aaaaa   aaaaaa                                               ",
			"     aaaaa    aaaaa    aaaaaa                                              ",
			"                                                                           ",
			"         aa  aa   aa   aaaaaa   aaaaaa  aa   aa  aaaaaaa  aaaa    aa      ",
			"         aa  aa   aa   aa      aa       aa   aa     aa    aa aa   aa       ",
			"    aa   aa  aa   aa   aaaa    aa  aaaa aa   aa     aa    aa  aa  aa       ",
			"    aa   aa  aaaaaaa   aa      aa    aa aaaaaaa     aa    aa   aa aa       ",
			"     aa aa   aaaaaaa   aaaaaa   aaaaaa  aaaaaaa     aa    aa    aaaa       ",
			
			
	};
	system("mode con: cols=100 lines=45");
	presentacion(inicio);
	
	Usuario user;
	UsuarioPtr listaUs=NULL;
	UsuarioPtr listaAux=NULL;
	int contadorUsuario=0;
	descargarArchivo(user,listaUs,contadorUsuario);system("cls");
	
	
	
	
	
	
	menuUsuario(contadorUsuario, listaUs, inicio,listaAux);
	
	cargarArchivo(user,listaUs);
	
	return 0;
}
void menu (char inicio[f][c] , UsuarioPtr &listaUs, char Us[10],int TLN){
	int opc=0, ban=2;
	
	

	do{
		
		system("cls");
		
		logo_inicial(inicio);
		system("color 1B");
		pintar();
		gotoxy(45,27);cout<<"Menu principal"<<endl;
		gotoxy(45,28);cout<<"Elija una opcion"<<endl;
		gotoxy(45,29);cout<<"Opcion 1: Facil"<<endl;
		gotoxy(45,30);cout<<"Opcion 2: Normal"<<endl;
		gotoxy(45,31);cout<<"Opcion 3: Difï¿½cil"<<endl;
		gotoxy(45,32);cout<<"Ingrese una opcion u oprima 0 para salir."<<endl;fflush(stdin);
		gotoxy(45,33);cin>>opc;
		
		
		
		
		switch(opc){
	
		case 1: 
			
			
			Jugar(opc,listaUs, Us, TLN);
			
			printLista( listaUs );system("pause");
			break;
		
		case 2://se utilizara para opcion 1: medio
			//colocar funcion nivel	
			
			
			Jugar(opc,listaUs, Us, TLN);
			break;
		case 3://se utilizara para opcion 1: dificil
			//colocar funcion nivel	
			
			
			Jugar(opc,listaUs, Us, TLN);
			break;
		}
		if(opc==0){system ("cls");
		cout<<"ï¿½Estï¿½ seguro de salir?"<<endl;
		cout<<"Si = 1"<<" "<<"No = 2"<<endl;
		cin>>ban;
		cout<<endl;
		if(ban!=1 && ban!=2){
			cout<<"Debe ingresar 1 o 2. Intentelo de nuevo."<<endl;
			system("pause");
			ban=2;
			
		}
		}
		
	}while (ban!=1 );
	
	cout<<"Gracias por jugar, vuelve pronto."<<endl;
	system("pause");
}
	
void gotoxy(int x,int y) {
		
		HANDLE hcon;  
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
		COORD dwPos;  
		dwPos.X = x;  
		dwPos.Y= y; 
		SetConsoleCursorPosition(hcon,dwPos); 
}
//-------------------------------------------------------------------------------------------
// Diseï¿½o de la presentaciï¿½n. 
	void pintar(){
		for (int i=2; i< 98 ;i++){
			gotoxy(i,3); printf("%c",205);
			gotoxy(i,23); printf ("%c",205);
			gotoxy(i,40); printf ("%c",205);
		}
		for (int i=4; i< 40 ;i++){
			gotoxy(1,i); printf("%c",186);
			gotoxy(98,i); printf ("%c",186);
		}
		gotoxy(1,3); printf("%c",201);
		gotoxy(1,40); printf("%c",200);
		gotoxy(98,3); printf("%c",187);
		gotoxy(98,40); printf("%c",188);
	}
	void presentacion(char inicio[f][c]){
		pintar();
		
		logo_inicial(inicio);
		
		system("color 0C");
		gotoxy(15,27);cout<<"Grupo Nï¿½:";
		gotoxy(15,29);cout<<"Integrantes:";
		gotoxy(15,30);cout<<"Barboso Darï¿½o";
		gotoxy(15,31);cout<<"Adam Eduardo josï¿½";
		gotoxy(15,32);cout<<"Bolaï¿½o Senn Nicolï¿½s"<<endl;
		gotoxy(15,34);cout<<"";
		
		gotoxy(50,27);cout<<"Comisiï¿½n : B.";
		gotoxy(50,29);cout<<"Direciï¿½n email:";
		gotoxy(50,30);cout<<"...dariovictorbarboso@hotmail.com...";
		gotoxy(50,31);cout<<"...eduardo.j.adam@gmail.com...";
		gotoxy(50,32);cout<<"...nicobolanio_S@hotmail.com..."<<endl;
		gotoxy(25,35);cout<<"Version: Beta-1.0 Aï¿½o: 2020"<<endl;
		gotoxy(25,35);cout<<"Build: 06102020"<<endl;
		
		gotoxy(25,39);cout<<""; system("pause");
	}
	void logo_inicial(char inicio[f][c]){
				int contar=1;
				do{SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),contar);
				for(int i = 0 ; i< 17 ; i++){
					for(int j = 0 ; j < 71 ; j++){
						if(inicio[i][j] == 'a'){
							gotoxy(j+5,i+5); printf("*");
						}
					}
				} contar++;
				}while (contar!=20);
			}
//-------------------------------------------------------------------------------------------
	// Coloca minas de manera aleatoria. El numero depende de CANTIDAD_MINAS
void colocarMinasAleatoriamente(char tablero[filasT][columnasT],int maximofila, int maximocolumna, int cantidadminas) {
	
	for ( int i= 0;  i<= cantidadminas-1; i++) {//Esto estaba mal
	int fila = aleatorioEnRango(0, maximofila);
	int columna = aleatorioEnRango(0, maximocolumna );
	if(tablero[fila][columna] != '*'){
	tablero[fila][columna] = '*';
		}else{
		i--;
	}}
}
int aleatorioEnRango(int minimo, int maximo) {
	return rand()%(maximo - minimo);//Esto estaba mal
	}
			

int Jugar(int nivel,UsuarioPtr &listaUs, char Us[10], int TLN){
	
	char tablero[filasT][columnasT];//en caso de que no se este pasando los valores colocar el & en la funcion 
	char tablerociego[filasT][columnasT];
	int maximofila, maximocolumna, cantidadminas,esIgual=0,contadorPart[]={0,0,0,0},tiempo=0;
	
	UsuarioPtr aux =new Usuario; aux= listaUs;
	int aux1[4] ;
	//int porcentajeJugadas[2]={0};
	bool encontrado=false;
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	
	if(nivel==1){
		
		maximofila=8;//define las filas en la dificultad 
		maximocolumna=8;//define las columnas en la dificultad
		cantidadminas=10;
		
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablero[i][j]='.';
			}
		}
		
		
		
		colocarMinasAleatoriamente(tablero, maximofila, maximocolumna, cantidadminas);
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablerociego[i][j]='/';
			}
		}
	}
	
	else if(nivel==2){
		
		maximofila=16;
		maximocolumna=16;
		cantidadminas=40;
		
		
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablero[i][j]='.';
			}
		}
		
		colocarMinasAleatoriamente(tablero, maximofila, maximocolumna, cantidadminas);
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablerociego[i][j]='/';
			}
		}
	}
	
	else if(nivel==3){
			
		maximofila=16;
		maximocolumna=30;
		cantidadminas=99;
		
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablero[i][j]='.';
			}
		}
		system("mode con: cols=150 lines=45");
		colocarMinasAleatoriamente(tablero, maximofila, maximocolumna, cantidadminas);
		for(int i=0; i<maximofila; i++){
			for(int j=0; j<maximocolumna;j++){
				tablerociego[i][j]='/';
			}
		}
	}
	
	system("cls");
	
	jugada (tablero, tablerociego,maximofila, maximocolumna, cantidadminas, contadorPart,tiempo );
	while(aux!=NULL && encontrado!=true){
	if(aux->TLN==TLN){
		for(int i=0;i<TLN;i++){//compara
			if(aux->nombreUs[i]==Us[i]){	
				esIgual++;				cout<<aux->nombreUs[i]<<" "<<Us[i];
			}else{esIgual=0;}}}
	
	cout<<esIgual<<endl;
	if(esIgual==TLN){//compara los tamaños logicos
		for(int i=0;i<4;i++){
			aux->contadorN[i]+=contadorPart[i];
			cout<<aux->contadorN[i];
		}
		for(int i=0;i<3;i++){
			aux->porcentajeN[i]=((aux->contadorN[i+1])*100)/aux->contadorN[0];
		}
		//guardar puntajes
		if(nivel == 1 && contadorPart[1]){//verifica nivel, si gano y que no se supere el tamaÃ±o maximo
			if(aux->TLP1 < 10){
			aux->TLP1=+1;
			}
			if(aux->TLP1 != 1){//ve si hay algo cargado 
		for(int i = 0;i < aux->TLP1; i++ ){
		if(aux->nivel1[i].mejorPuntaje > tiempo ){//verifica que el puntaje sea el mayor sino corre todas las posiciones
			aux1[0]=tiempo;
			aux1[1]=now->tm_mday;
			aux1[2]=(now->tm_mon + 1);
			aux1[3]=(now->tm_year + 1900);
		for(int j=9;j>=i;j--){

         aux->nivel1[j].mejorPuntaje=aux->nivel1[j-1].mejorPuntaje;
         aux->nivel1[j].dia=aux->nivel1[j-1].dia;
         aux->nivel1[j].mes=aux->nivel1[j-1].mes;
         aux->nivel1[j].anio=aux->nivel1[j-1].anio;
		}
		aux->nivel1[i].mejorPuntaje=aux1[0];
        aux->nivel1[i].dia=aux1[1];
        aux->nivel1[i].mes=aux1[2];
        aux->nivel1[i].anio=aux1[3];
		
		}else if(i == aux->TLP1-1 && aux->nivel1[i].mejorPuntaje==0){
          aux->nivel1[i].mejorPuntaje=tiempo;
			aux->nivel1[i].dia=now->tm_mday;
			aux->nivel1[i].mes=(now->tm_mon + 1);
			aux->nivel1[i].anio=(now->tm_year + 1900);
		}}}else{
			aux->nivel1[0].mejorPuntaje=tiempo;
			aux->nivel1[0].dia=now->tm_mday;
			aux->nivel1[0].mes=(now->tm_mon + 1);
			aux->nivel1[0].anio=(now->tm_year + 1900);
		}
		}
		else if(nivel == 2 && contadorPart[1]){//verifica nivel, si gano y que no se supere el tamaÃ±o maximo
			if(aux->TLP2 < 10){
				aux->TLP2=+1;
			}
			if(aux->TLP2 != 1){//ve si hay algo cargado 
				for(int i = 0;i < aux->TLP2; i++ ){
					if(aux->nivel2[i].mejorPuntaje > tiempo ){//verifica que el puntaje sea el mayor sino corre todas las posiciones
						aux1[0]=tiempo;
						aux1[1]=now->tm_mday;
						aux1[2]=(now->tm_mon + 1);
						aux1[3]=(now->tm_year + 1900);
						for(int j=9;j>=i;j--){
							
							aux->nivel2[j].mejorPuntaje=aux->nivel2[j-1].mejorPuntaje;
							aux->nivel2[j].dia=aux->nivel2[j-1].dia;
							aux->nivel2[j].mes=aux->nivel2[j-1].mes;
							aux->nivel2[j].anio=aux->nivel2[j-1].anio;
						}
						aux->nivel2[i].mejorPuntaje=aux1[0];
						aux->nivel2[i].dia=aux1[1];
						aux->nivel2[i].mes=aux1[2];
						aux->nivel2[i].anio=aux1[3];
						
					}else if(i == aux->TLP2-1 && aux->nivel2[i].mejorPuntaje==0){
						aux->nivel2[i].mejorPuntaje=tiempo;
						aux->nivel2[i].dia=now->tm_mday;
						aux->nivel2[i].mes=(now->tm_mon + 1);
						aux->nivel2[i].anio=(now->tm_year + 1900);
					}}}else{
				aux->nivel2[0].mejorPuntaje=tiempo;
				aux->nivel2[0].dia=now->tm_mday;
				aux->nivel2[0].mes=(now->tm_mon + 1);
				aux->nivel2[0].anio=(now->tm_year + 1900);
			}
		}
		
		else if(nivel == 3 && contadorPart[1]){//verifica nivel, si gano y que no se supere el tamaÃ±o maximo
			if(aux->TLP3 < 10){
				aux->TLP3=+1;
			}
			if(aux->TLP3 != 1){//ve si hay algo cargado 
				for(int i = 0;i < aux->TLP3; i++ ){
					if(aux->nivel3[i].mejorPuntaje > tiempo ){//verifica que el puntaje sea el mayor sino corre todas las posiciones
						aux1[0]=tiempo;
						aux1[1]=now->tm_mday;
						aux1[2]=(now->tm_mon + 1);
						aux1[3]=(now->tm_year + 1900);
						for(int j=9;j>=i;j--){
							
							aux->nivel3[j].mejorPuntaje=aux->nivel3[j-1].mejorPuntaje;
							aux->nivel3[j].dia=aux->nivel3[j-1].dia;
							aux->nivel3[j].mes=aux->nivel3[j-1].mes;
							aux->nivel3[j].anio=aux->nivel3[j-1].anio;
						}
						aux->nivel3[i].mejorPuntaje=aux1[0];
						aux->nivel3[i].dia=aux1[1];
						aux->nivel3[i].mes=aux1[2];
						aux->nivel3[i].anio=aux1[3];
						
					}else if(i == aux->TLP3-1 && aux->nivel3[i].mejorPuntaje==0){
						aux->nivel3[i].mejorPuntaje=tiempo;
						aux->nivel3[i].dia=now->tm_mday;
						aux->nivel3[i].mes=(now->tm_mon + 1);
						aux->nivel3[i].anio=(now->tm_year + 1900);
					}}}else{
				aux->nivel3[0].mejorPuntaje=tiempo;
				aux->nivel3[0].dia=now->tm_mday;
				aux->nivel3[0].mes=(now->tm_mon + 1);
				aux->nivel3[0].anio=(now->tm_year + 1900);
			}
		}
		
		
		encontrado=true;
		system("pause");
		
	}
	
	aux=aux->sigUsuario;
	}
	
	system("mode con: cols=100 lines=45");
	return 0;
}


