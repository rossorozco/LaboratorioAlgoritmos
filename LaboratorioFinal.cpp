//Programa de proyecto final 2do. semestre Algoritmos
/*El programa realiza:
1.USUARIO INGRESA LOS DATOS
2.MUESTRA LA LISTA DE EMPLEADOS INGRESADOS
3.REPORTA EMPLEADOS CON SALARIO MAYOR A Q10,000
4.BUSCA EMPLEADO POR DPI Y CODIGO
5.ELIMINAR REGISTRO DEL EMPLEADO POR DPI Y CODIGO
6.SALE DEL PROGRAMA*/

//Creacion del archivo main y colocacion de librerias
/*Libreria cstdlib (cstdlib=libreria para convertir un entero a cadena de caracteres)
  libreria iostream (iostream= para poder tener acceso a los dispositivos estándar de entrada y/o salida)

/*Pasos para crear y/o escribir en un archivo:
1. Incluir libreria fstream (fstream=libreria para manejo de archivos)
2. Crear una variable tipo ofstream(Sirve para crear y escribir en un archivo. Si no existe lo crea y si existe borra lo que tenia anteriormente)
3. Abrir el archivo
4. Validad apertura del archivo
5. Escribir en el archivo
6. Cerrar el archivo
*/

/*Pasos para leer datos de un archivo:
1. Incluir libreria fstream
2. Crear una variable tipo ofstream
3. Abrir el archivo
4. Validar la apertura del archivo
5. Leer los datos del archivo
6. Cerrar el archivo
*/

/*Pasos para realizar el proyecto final
1. Declaracion de clases
2. Declaracion de variables globales
3. Crear la funcion ingresoDatos() y mostrarEmpleados() (que son ingreso de datos e imprimir los datos)
4. Creacion de una variable booleana
6. En buscar() declaramos una variable ifstream
7. Declarar variable que nos servira para buscar dentro del archivo realizamos funcion buscar();
6. Agregamos otra libreria */

#include <cstdlib>
#include <iostream>
#include <fstream> //Paso 1
#include <string.h>

using namespace std; //Permite tener un alcance directo a todas las funciones declaradas en un espacio de nombres "std"

void ingresoDatos();
void buscar();
void eliminarEmpleado();
void mostrarEmpleados();
void reporteMayorSalario();
void salir();
void menu();

//declaracion de funciones para busqueda por dpi y codigo
void busquedaDpi();
void busquedaCodigo();

//Declaramos variables globales
char nombre[30], nombreDos[30], apellido[30], apelliDos[30], resp[1];
char dpi[30],salario[30],codigo[30];
bool encontrado=false;//Para saber cuando fue encontrado un registro minimo
char auxDpi[30];//Para compararla con dpi
char auxCodigo[30];//Para compararla con codigo

int main(){
	menu();
	return 0;
	system("PAUSE");
}

void menu(){
	int opcion=0;
	bool repetir=true;
	do{
		cout<<"*********************************************************"<<endl;
		cout<<"                      MENU PRINCIPAL"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"| 1. Ingreso de datos                                   |"<<endl;
		cout<<"| 2. Buscar empleado                                    |"<<endl;
		cout<<"| 3. Eliminar registro del empleado                     |"<<endl;
		cout<<"| 4. Mostrar lista de empleados                         |"<<endl;
		cout<<"| 5. Reporte de empleados con salario mayor a Q10,000.00|"<<endl;
		cout<<"| 6. Salir                                              |"<<endl;
		cout<<"*********************************************************"<<endl;
		cout<<"Elija una opcion: "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				ingresoDatos();			
			break;
			case 2:
				buscar();			
			break;
			case 3:
				eliminarEmpleado();			
			break;
			case 4:
				mostrarEmpleados();			
			break;
			case 5:
				reporteMayorSalario();			
			break;
			case 6:
				salir();
				repetir = false;
            	break;		
			break;
			default: 
				cout<<"La opción que ingresó es incorrecta.";		
		}
	}while(repetir!=false);
}

void ingresoDatos(){	
ofstream  escritura; //Paso 2
//Decirle que agrege informacion al final (que no lo borre) agregamos ios::app (y ios::app sirve para poder escribir en el archivo y que no borre lo que teniamos(lo añade al final)
escritura.open("empleados.txt",ios::out|ios::app); //paso 3 (ios::out es para poder escribir en el archivo(escritura) pero borra lo que teniamos)
//Paso 4 (Validacion de apertura del archivo)
if(escritura.is_open()){
	//Ingreso de datos
	fflush(stdin);
	cout<<"\n POR FAVOR ingrese los datos sin puntos ni comas \n";
	cout<<"\n Ingrese su Dpi: ";
	cin>>dpi;
	cout<<"\n Ingrese su Codigo de empleado: ";
	cin>>codigo;
	cout<<"\n Ingrese su primer nombre: ";
	cin>>nombre;
	cout<<"\n Ingrese su segundo nombre: ";
	cin>>nombreDos;
	cout<<"\n Ingrese su primer apellido: ";
	cin>>apellido;
	cout<<"\n Ingrese su segundo apellido: ";
	cin>>apelliDos;
	cout<<"\n Ingrese su salario: ";
	cin>>salario;
	
	//Escribiendo datos en el archivo
	escritura<<dpi<<" "<<codigo<<" "<<nombre<<" "<<nombreDos<<" "<<apellido<<" "<<apelliDos<<" "<<salario<<endl;
}
else{
	cout<<"Archivo no abierto"<<endl;
}
escritura.close(); //Paso 6
}//Fin funcion ingresoDatos();

void mostrarEmpleados(){
//Lectura del archivo
//Paso 2
ifstream lectura;
//Paso 3
lectura.open("empleados.txt",ios::out|ios::in);//ios::in(para poder leer los datos)
//Paso 4
if(lectura.is_open()){
	//cout<<"Archivo abierto"<<endl;
	lectura>>dpi; //Para ver si no ha llegado al final del archivo y asi seguirlo leyendo con while(!lectura.eof())
	cout<<"Registro del archivo empleados.txt"<<endl;
	cout<<"-------------------------------------"<<endl;
	while(!lectura.eof()){//eof (while lectura doesn't end of file)
		lectura>>codigo;
		lectura>>nombre;
		lectura>>nombreDos;
		lectura>>apellido;
		lectura>>apelliDos;
		lectura>>salario;
		cout<<"Dpi :"<<dpi<<endl;
		cout<<"Codigo :"<<codigo<<endl;
		cout<<"Primer nombre :"<<nombre<<endl;
		cout<<"Segundo nombre :"<<nombreDos<<endl;
		cout<<"Primer apellido :"<<apellido<<endl;
		cout<<"Segundo apellido :"<<apelliDos<<endl;
		cout<<"Salario :"<<salario<<endl;
		lectura>>dpi;
	}
}
else{
	cout<<"Archivo no abierto"<<endl;
}
//paso 6
lectura.close();
}//fin funcion mostrarEmpleados();


void buscar(){
	ifstream lectura;//Declaramos variable de tipo lectura
	lectura.open("empleados.txt",ios::out|ios::in); //Abrimos el archivo
	int opcion_busqueda;
	bool repeticion=false;
	do
	{
		cout<< endl <<" BUSQUEDA DE EMPLEADOS\n";
		cout<< endl <<"Ingrese que tipo de busqueda desea realizar\n";
		cout<< endl <<"1. Desea buscar por DPI?\n";
		cout<< endl <<"2. Desea buscar por codigo empleado?\n";
		cout<< endl <<"3. Salir\n";
		cout << endl <<" Escoja una Opcion: ";
		cin >> opcion_busqueda;
		switch(opcion_busqueda){
			case 1:
				cout <<" BUSQUEDA DPI "<< endl;
				if(lectura.is_open()){
				cout<<"Ingresa el DPI a buscar: ";
				cin>>auxDpi;
				lectura>>dpi;//Lectura adelantada
				encontrado=false;
				while(!lectura.eof()){
					lectura>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
					//comparar cada registro para ver si es encontrado
					if(strcmp(auxDpi,dpi)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
					{
						cout<<"-------------------------------------"<<endl;
						cout<<"Dpi :"<<dpi<<endl;
						cout<<"Codigo :"<<codigo<<endl;
						cout<<"Primer nombre :"<<nombre<<endl;
						cout<<"Segundo nombre :"<<nombreDos<<endl;
						cout<<"Primer apellido :"<<apellido<<endl;
						cout<<"Segundo apellido :"<<apelliDos<<endl;
						cout<<"Salario :"<<salario<<endl;
						cout<<"-------------------------------------"<<endl;
						encontrado=true;
					}
					lectura>>dpi;//lectura adelantada
				}
					if(encontrado==false){
						cout<<"No hay registros con el Dpi: "<<auxDpi<<endl;
					}
				}
				break;
			case 2:
				cout << " BUSQUEDA POR CODIGO DE EMPLEADO "<< endl;
				if(lectura.is_open()){
					cout<<"Ingresa el codigo a buscar: ";
					cin>>auxCodigo;
					lectura>>dpi;//Lectura adelantada
					encontrado=false;
					while(!lectura.eof()){
						lectura>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
						//comparar cada registro para ver si es encontrado
						if(strcmp(auxCodigo,codigo)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
						{
							cout<<"-------------------------------------"<<endl;
							cout<<"Dpi :"<<dpi<<endl;
							cout<<"Codigo :"<<codigo<<endl;
							cout<<"Primer nombre :"<<nombre<<endl;
							cout<<"Segundo nombre :"<<nombreDos<<endl;
							cout<<"Primer apellido :"<<apellido<<endl;
							cout<<"Segundo apellido :"<<apelliDos<<endl;
							cout<<"Salario :"<<salario<<endl;
							cout<<"-------------------------------------"<<endl;
							encontrado=true;
						}
						lectura>>dpi;//lectura adelantada
					}
					if(encontrado==false){
						cout<<"No hay registros con el codigo: "<<auxCodigo<<endl;
					}
				}
				else{
					cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
					cout<<"O contiene un error"<<endl;
				}
				//Cerrando el archivo
				lectura.close();
				break;
			case 3:
				cout <<" Programa finalizado..."<< endl;
				repeticion = true;
				break;
			default:
				cout <<" Opcion No Valida "<< endl;
		}
	}while(repeticion!=true);
}
void eliminarEmpleado(){
}
void reporteMayorSalario(){	
}
void salir(){
	cout<<"Programa Finalizado"<<endl;
}

