//Programa de proyecto final 2do. semestre Algoritmos
/*El programa realiza:
1.USUARIO INGRESA LOS DATOS
2.MUESTRA LA LISTA DE EMPLEADOS INGRESADOS
3.REPORTA EMPLEADOS CON SALARIO MAYOR A Q10,000
4.BUSCA EMPLEADO POR DPI Y CODIGO
5.ELIMINAR REGISTRO DEL EMPLEADO POR DPI Y CODIGO
6.SALE DEL PROGRAMA*/

#include <stdio.h>//(stdio.h = Devuelve un carácter desde un fichero. Lee caracteres de entrada hasta que encuentra un salto de línea, y los almacena en un único argumento. Usados para imprimir salidas de datos. También utilizado para imprimir salidas.)
#include <stdlib.h>//(stdlib.h= tiene dos funciones útiles para hacer búsqueda y ordenamiento de datos de cualquier tipo.)
#include <iostream>//(iostream= para poder tener acceso a los dispositivos estándar de entrada y/o salida)
#include <conio.h>//(conio.h= usado mayormente por los compiladores de MS-DOS para proveer un sistema de E/S(permiten que el sistema gestionado recopile, almacene y transmita datos) por consola. )
#include <string.h>//(string.h= contiene un conjunto de funciones para manipular cadenas: copiar, cambiar caracteres, comparar cadenas, etc.)
#include <fstream>//(fstream= libreria para manejo de archivos)
#include <math.h>//(math.h= diseñado para operaciones matemáticas básicas)

using namespace std;

//Declaracion de funciones
void menu();
void salidaSistema();
void ingresoDatos();
void lectura();
void reporte();
void buscar();
void eliminar();

//Variables globales
int salario;
int lookfor;
char dpi[15], primernombre[50], segundonombre[50], apellido[50], apellidos[50],respuesta;
char busqueda[15];
bool encontrar=false;

void menu(){//Menu de opciones
	int opcion;
	system("cls");	
	cout<<"*********************************************************"<<endl;
	cout<<"                      MENU PRINCIPAL"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"| 1. Ingreso de datos                                   |"<<endl;
	cout<<"| 2. Buscar empleado                                    |"<<endl;
	cout<<"| 3. Eliminar registro del empleado                     |"<<endl;
	cout<<"| 4. Mostrar lista de empleados                         |"<<endl;
	cout<<"| 5. Reporte de empleados con salario mayor a 10000     |"<<endl;
	cout<<"| 6. Salir                                              |"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"Elija una opcion: "<<endl;
	cin>>opcion;
	switch(opcion){
		
		case 1:
			ingresoDatos();
		break;
			
		case 2:
		  	buscar();//Busqueda entre registros
		break;
		
		case 3:
			eliminar();//Eliminacion de registros
		break;
		
		case 4:
			lectura();//Lectura de registros
		break;
		
		case 5:
			reporte();//Lectura de salarios menores a 10000
		break;
		
		case 6:
			salidaSistema();//Salida del sistema
		break;
		
		default: //La opcion ingresada es erronea
			cout<<"|———————————————————————————————————————————————————————|"<<endl;
			cout<<"                   Opcion Incorrecta"<<endl;
			cout<<"|———————————————————————————————————————————————————————|"<<endl;
			getche();
		    return menu();
		}
}
		
void ingresoDatos(){//Ingreso de datos
	system("cls");
	ofstream archsal("datos.txt", ios::app);
	if(!archsal){
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cerr<<"        Error, no se puede abrir el archivo"<<endl;
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		getch();
	}
	do{
	int cant;
	cout<<"*************************************************************"<<endl;
	cout<<"                     INGRESO DE DATOS"<<endl;
	cout<<"*************************************************************"<<endl;
	cout<<"|———————————————————————————————————————————————————————————|"<<endl;
	cout<<"   Ingrese la cantidad de empleados que desea ingresar:  ";
	cin>>cant;
	for(int i=0;i<cant;i++){
		cout<<"Ingrese su dpi: ";
		cin>>dpi;
		cout<<"Ingrese primer nombre: ";
		cin>>primernombre;
		cout<<"Ingrese segundo nombre: ";
		cin>>segundonombre;
		cout<<"Ingrese primer apellido: ";
		cin>>apellido;
		cout<<"Ingrese segundo apellido: ";
		cin>>apellidos;
		cout<<"Ingrese su salario: ";
		cin>>salario;
		fflush(stdin);
		cout<<"*************************************************************"<<endl;
		cout<<"|———————————————————————————————————————————————————————————|"<<endl;
	}
		archsal<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;
		
		cout<<"*********************************************************"<<endl;
		cout<<"               MENU PARA HACER OTRO INGRESO"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"|¿Desea realizar otro ingreso?                          |"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"|_INGRESE UNA LETRA:____________________________________|"<<endl;
		cout<<"| 1. S (para salir)                                     |"<<endl;
		cout<<"| 2. N (para no salir)                                  |"<<endl;
		cout<<"|_______________________________________________________|"<<endl;
		cout<<"*********************************************************"<<endl;;
		cout<<"Ingrese: ";
		cin>>respuesta;

	}while(toupper(respuesta)=='S');//toupper (Devuelve una copia de esta cadena convertida en mayúsculas, aplicando las reglas de mayúsculas y minúsculas de la referencia cultural especificada)
	
	archsal.close(); //Cerramos el archivo
	getche();
	menu();
}

void lectura(){
	system("cls");
	ifstream archivo;
	string texto; 
	archivo.open("datos.txt", ios::in); //Se abre para que lo podamos leer
	if(archivo.fail()){
		cout<<"*********************************************************"<<endl;
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"|_ERROR 404_____________________________________________|"<<endl;
		cout<<"|_No se pudo abrir el archivo___________________________|"<<endl;
		cout<<"|_______________________________________________________|"<<endl;
		cout<<"*********************************************************";
	}else{
		cout<<"*************************************************************************************"<<endl;
		cout<<"                             REGISTROS DE TRABAJADORES"<<endl;
		cout<<"*************************************************************************************"<<endl<<endl;
	while(!archivo.eof()){ // eof(end of file)= Mientras que este al final del archivo, mostramos todo el texto
		getline(archivo,texto); 
		cout<<texto<<endl;
	}
}
	archivo.close(); //Cerrardo el archivo
	getche();
	menu();
}

void reporte(){
	system("cls");
	
	cout<<"*************************************************************************************"<<endl;
	cout<<"                             REGISTROS DE TRABAJADORES"<<endl;
	cout<<"*************************************************************************************"<<endl<<endl;
	ifstream archivo("datos.txt", ios::in);
	
	if(!archivo){
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"     No se puede abrir el archivo o no ha sido creado"<<endl;
		cout<<"|———————————————————————————————————————————————————————|\n";
		getch();
		menu();
	}

	int n=10000;
	while(archivo>>dpi>>primernombre>>segundonombre>>apellido>>apellidos>>salario){
		if (salario>=n){	
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"*************************************************************************************\n";
		}
	}
	getche();
	archivo.close();
	system("pause");
	menu();		
}

void buscar(){
	system("cls");
	cout<<"*************************************************************************************"<<endl;
	cout<<"                             REGISTROS DE TRABAJADORES"<<endl;
	cout<<"*************************************************************************************"<<endl<<endl;
	ifstream archivo;
	archivo.open("datos.txt",ios::out|ios::in);
	//Seleccionar de que forma buscar  
	int OpEm;
	
	cout<<"*********************************************************"<<endl;
	cout<<"                     MENU DE BUSQUEDA"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"|¿Desea buscar a un empleado?                          |"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"|———————————————————————————————————————————————————————|"<<endl;
	cout<<"|_INGRESE UN NUMERO:____________________________________|"<<endl;
	cout<<"| 1. Dpi                                                |"<<endl;
	cout<<"| 2. Nombres                                            |"<<endl;
	cout<<"| 3. Apellidos                                          |"<<endl;
	cout<<"| 4. Salario                                            |"<<endl;
	cout<<"|_______________________________________________________|"<<endl;
	cout<<"*********************************************************"<<endl;;
	cout<<"Ingrese el numero: "<<char(162)<<"n \n";
	cin>>OpEm;

	switch(OpEm)
	{
		case 1:
			system("cls");
			if(archivo.is_open()){
			cout<<"*************************************************************"<<endl;
			cout<<"Ingresa el dpi del empleado a buscar \n";
			cin>>busqueda;
			archivo>>dpi;//lectura adelantada
			encontrar=false;
			while(!archivo.eof()){
			archivo>>primernombre>>segundonombre>>apellido>>apellidos>>salario;//leyendo los campos del registro
			//comparar cada registro para ver si lo encontramos 
			if (strcmp(busqueda, dpi)==0){
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"****************************************************************************************************\n";
			encontrar=true;		
			}
				archivo>>dpi;//lectura adelantada	
			}
			if(encontrar==false){
				cout<<"|———————————————————————————————————————————————————————|"<<endl;
				cout<<"            No se encontro a ningun registro"<<endl;
				cout<<"|———————————————————————————————————————————————————————|\n";
			}
			getche();
			menu();	
			}
		break;
		
		
		case 2:
			system("cls");
			if(archivo.is_open()){
			cout<<"*************************************************************"<<endl;
			cout<<"Ingresa el nombre del empleado a buscar \n";
			cin>>busqueda;
			archivo>>dpi;//lectura adelantada
			encontrar=false;
			while(!archivo.eof()){
			archivo>>primernombre>>segundonombre>>apellido>>apellidos>>salario;//leyendo los campos del registro
			//comparar cada registro para ver si lo encontramos 
			if (strcmp(busqueda, primernombre)==0){
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"****************************************************************************************************\n";
			encontrar=true;	
			} else if(strcmp(busqueda, segundonombre)==0){
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"****************************************************************************************************\n";
			encontrar=true;	
			}
						
				archivo>>dpi;//lectura adelantada	
			}
			if(encontrar==false){
				cout<<"|———————————————————————————————————————————————————————|"<<endl;
				cout<<"            No se encontro a ningun registro"<<endl;
				cout<<"|———————————————————————————————————————————————————————|\n";
			}
			getche();
			menu();	
		}
		break;
		
		
		case 3:
			system("cls");
			if(archivo.is_open()){
			cout<<"*************************************************************"<<endl;
			cout<<"Ingresa el apellido del empleado a buscar \n";
			cin>>busqueda;
			archivo>>dpi;//lectura adelantada
			encontrar=false;
			while(!archivo.eof()){
			archivo>>primernombre>>segundonombre>>apellido>>apellidos>>salario;//leyendo los campos del registro
			
			//comparar cada registro para ver si lo encontramos 
			if (strcmp(busqueda, apellido)==0){
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"****************************************************************************************************\n";
			encontrar=true;	
			} else if(strcmp(busqueda, apellidos)==0){
			cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
			cout<<"****************************************************************************************************\n";
			encontrar=true;	
			}
	
				archivo>>dpi;//lectura adelantada	
			}
			if(encontrar==false){				
				cout<<"|———————————————————————————————————————————————————————|"<<endl;
				cout<<"            No se encontro a ningun registro"<<endl;
				cout<<"|———————————————————————————————————————————————————————|\n";
			}
			getche();
			menu();	
			}
		break;
		
		case 4:
			system("cls");
			ifstream archivo("datos.txt", ios::in);
			if(!archivo){
				cout<<"No se puede abrir el archivo o no ha sido creado\n";
				getch();
				menu();
			}
			cout<<"*************************************************************"<<endl;
			cout<<"Ingresa el empleado a buscar \n";
			cin>>lookfor;
			while(archivo>>dpi>>primernombre>>segundonombre>>apellido>>apellidos>>salario){
					if(lookfor==salario){
						cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
					cout<<"****************************************************************************************************\n";
					}
				
			if(encontrar==false){
				cout<<"|———————————————————————————————————————————————————————|"<<endl;
				cout<<"            No se encontro a ningun registro"<<endl;
				cout<<"|———————————————————————————————————————————————————————|\n";
			}
			getche();
			menu();
		}
		
		break;
	}
}

void eliminar(){
	system("cls");
	cout<<"*************************************************************************************"<<endl;
	cout<<"                             REGISTROS DE TRABAJADORES"<<endl;
	cout<<"*************************************************************************************"<<endl<<endl<<endl<<endl;
	ifstream archivo;
	archivo.open("datos.txt",ios::out|ios::in);
	ofstream auxi;
	auxi.open("auxiliar.txt",ios::out);
	if(auxi.is_open() && archivo.is_open()){
		cout<<"*************************************************************"<<endl;
		cout<<"Ingresa el dpi del empleado a buscar \n";
		cin>>busqueda;
		archivo>>dpi;//lectura adelantada
		encontrar=false;
		while(!archivo.eof()){
		archivo>>primernombre>>segundonombre>>apellido>>apellidos>>salario;//leyendo los campos del registro
		//comparar cada registro para ver si lo encontramos 
		if (strcmp(busqueda, dpi)==0){
		cout<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
		cout<<"****************************************************************************************************\n";
		encontrar=true;	
		cout<<"Este registro eliminado";	
		}else{
			auxi<<dpi<<"	"<<primernombre<<"	"<<segundonombre<<"	"<<apellido<<"	"<<apellidos<<"	"<<salario<<endl;	
		}
			archivo>>dpi;//lectura adelantada	
		} 
	}
	else {
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"    No se puede abrir el archivo o no ha sido creado"<<endl;
		cout<<"|———————————————————————————————————————————————————————|\n";
		getch();
		menu();
	}    
	if(encontrar==false){
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"            No se encontro a ningun registro"<<endl;
		cout<<"|———————————————————————————————————————————————————————|\n";
	}	
	auxi.close();
	archivo.close();
	remove("datos.txt");
	rename("auxiliar.txt","datos.txt");
	getche();
	menu();		
}

void salidaSistema (){
	system("cls");
	int opc;
	cout<<"*********************************************************"<<endl;
	cout<<"                     MENU DE SALIDA"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"|Desea Realmente salir del sistema?                     |"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"|———————————————————————————————————————————————————————|"<<endl;
	cout<<"|_INGRESE EL NUMERO:____________________________________|"<<endl;
	cout<<"| 1. SI (para salir)                                    |"<<endl;
	cout<<"| 2. NO (para no salir)                                 |"<<endl;
	cout<<"|_______________________________________________________|"<<endl;
	cout<<"*********************************************************"<<endl;
	cout<<"Elija una opcion: "<<endl;
	cin>>opc;
	if(opc == 1){
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"                       ADIOSITO"<<endl;
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
	}else if(opc == 2){
		menu();
	}else{
		system("cls");
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		cout<<"                   Opcion Incorrecta"<<endl;
		cout<<"|———————————————————————————————————————————————————————|"<<endl;
		getche();
		salidaSistema();
	}
}

int main(){ //Inicio del programa
	setlocale(LC_CTYPE, "Spanish");
	menu();
	getch();
}
