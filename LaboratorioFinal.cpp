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
void reporteMayorSalario();//para que imprima la funcion reporteSalario();
void reporteSalario();//funcion
void salir();
void menu();

//declaracion de funciones para busqueda por dpi y codigo
void busquedaDpi();
void busquedaCodigo();

void contador();

//Declaramos variables globales
char nombre[30], nombreDos[30], apellido[30], apelliDos[30];
char dpi[30],codigo[30]; 
bool encontrado=false;//Para saber cuando fue encontrado un registro minimo
char auxDpi[30];//Para compararla con dpi
char auxCodigo[30];//Para compararla con codigo
int clave=0, auxclave=0;//La variable (clave) para crear clave y auxclave para que cada vez que se solicite datos verificamos que no haya otro registro con la misma clave
char report[30];//para el reporte de empleados con salario mayor a 10000
char salario[30],auxsalario[30];

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
				buscar();//empleados es rescrito por auxiliar de la funcion eliminarEmpleado();			
			break;
			case 3:
				eliminarEmpleado();	//eliminar reescribe los datos que estan guardados en auxiliar		
			break;
			case 4:
				mostrarEmpleados();	//empleados es rescrito por auxiliar de la funcion eliminarEmpleado();	
			break;
			case 5:
				//reporteSalario();
				reporteMayorSalario();
				reporteSalario();
			break;
			case 6:
				salir();
				repetir = false;
            	break;		
			break;
			default: 
				cout<<"La opcion que ingreso es incorrecta."<<endl;
				salir();
				repetir = false;
            	break;		
		}
	}while(repetir!=false);
}

void ingresoDatos(){	
	ofstream escritura; //Paso 2
	ifstream consulta;
	bool repet=false;//verifica si no hay repetidos
	//Decirle que agrege informacion al final (que no lo borre) agregamos ios::app (y ios::app sirve para poder escribir en el archivo y que no borre lo que teniamos(lo añade al final)
	escritura.open("empleados.txt",ios::out|ios::app); //paso 3 (ios::out es para poder escribir en el archivo(escritura) pero borra lo que teniamos)
	consulta.open("empleados.txt",ios::in);//Para ver si ya se registro un archivo para ponerle una clave al nuevo archivo
	//Paso 4 (Validacion de apertura del archivo)
	if(escritura.is_open() && consulta.is_open()){
		//Ingreso de datos
		fflush(stdin);
		cout<<"\n Ingrese la clave: ";
		cin>>auxclave;
		consulta>>clave;
		while(!consulta.eof()){//Para buscar si hay alguna clave
			consulta>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//si se cumple la condicion va ha hacer lectura nuevamente
			if(clave==auxclave){//si se cumple la condicion es que ya hay registro y no se puede registrar nuevamente
				cout<<"Ya exite un registro con esta clave"<<endl;
				repet=true;
				break;//Salida del ciclo
			}
			consulta>>clave;//Consulta adelantada
		}
		if(repet==false){//no se encontro nunca un registro con la clave ingresada por usuario entonces se procede a ingresar datos
			cout<<"\n POR FAVOR ingrese los datos sin puntos ni comas \n";
			fflush(stdin);
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
			escritura<<auxclave<<" "<<dpi<<" "<<codigo<<" "<<nombre<<" "<<nombreDos<<" "<<apellido<<" "<<apelliDos<<" "<<salario<<endl;
			cout<<" Registro agregado "<<endl;
		}
	}
	else{
		cout<<"Archivo no se pudo abrir o no ha sido creado"<<endl;
	}
	escritura.close(); //Paso 6
	consulta.close();//cierre de consulta
}//Fin funcion ingresoDatos();

void mostrarEmpleados(){
//Lectura del archivo
//Paso 2
ifstream lectura;
ifstream verificacionRegistro;
//Paso 3
lectura.open("auxiliar.txt",ios::out|ios::in);//ios::in(para poder leer los datos)
verificacionRegistro.open("empleados.txt",ios::out|ios::in);
//Paso 4
lectura>>clave;
verificacionRegistro>>clave;
if(lectura.is_open()){
	lectura>>clave; //Para ver si no ha llegado al final del archivo y asi seguirlo leyendo con while(!lectura.eof())
	cout<<"Registro del archivo empleados.txt"<<endl;
	cout<<"-------------------------------------"<<endl;
	if(lectura.is_open()){
		lectura>>clave;
		while(!lectura.eof()){//eof (while lectura doesn't end of file)
			lectura>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;
			cout<<"Clave :"<<clave<<endl;
			cout<<"Dpi :"<<dpi<<endl;
			cout<<"Codigo :"<<codigo<<endl;
			cout<<"Primer nombre :"<<nombre<<endl;
			cout<<"Segundo nombre :"<<nombreDos<<endl;
			cout<<"Primer apellido :"<<apellido<<endl;
			cout<<"Segundo apellido :"<<apelliDos<<endl;
			cout<<"Salario :"<<salario<<endl;
			encontrado=true;
		}
	}
	else {
		cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
	}
	//paso 6
	lectura.close();
}
else if(verificacionRegistro.is_open()){
	verificacionRegistro>>clave;
	cout<<"Registro del archivo empleados.txt"<<endl;
	cout<<"-------------------------------------"<<endl;
	if(verificacionRegistro.is_open()){
		lectura>>clave;
		while(!verificacionRegistro.eof()){
			verificacionRegistro>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;
			cout<<"Clave :"<<clave<<endl;
			cout<<"Dpi :"<<dpi<<endl;
			cout<<"Codigo :"<<codigo<<endl;
			cout<<"Primer nombre :"<<nombre<<endl;
			cout<<"Segundo nombre :"<<nombreDos<<endl;
			cout<<"Primer apellido :"<<apellido<<endl;
			cout<<"Segundo apellido :"<<apelliDos<<endl;
			cout<<"Salario :"<<salario<<endl;
			encontrado=true;
		}
	}
	else {
		cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
	}
	verificacionRegistro.close();
}
else{
cout<<"Archivo no se pudo abrir o no ha sido creado"<<endl;
}
}

void buscar(){
	ifstream lectura;//Declaramos variable de tipo lectura
	ifstream verificacionRegistro;//Declaramos variable de tipo lectura
	lectura.open("auxiliar.txt",ios::out|ios::in); //Abrimos el archivo
	verificacionRegistro.open("empleados.txt",ios::out|ios::in);//Abrimos el archivo
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
				if (lectura.is_open()){
					lectura>>clave;
					if(lectura.is_open()){
						cout<<"Ingresa el DPI a buscar: ";
						cin>>auxDpi;
						lectura>>clave;//Lectura adelantada
						encontrado=false;
						while(!lectura.eof()){
							lectura>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
							//comparar cada registro para ver si es encontrado
							if(strcmp(auxDpi,dpi)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
							{
								cout<<"-------------------------------------"<<endl;
								cout<<"Clave :"<<clave<<endl;
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
							lectura>>clave;//lectura adelantada
						}
						if(encontrado==false){
							cout<<"No hay registros con el Dpi: "<<auxDpi<<endl;
						}
					}
					else{
						cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
					}
					//Cerrando el archivo
					lectura.close();
					break;
				}
				else{
					if(verificacionRegistro.is_open()){
						cout<<"Ingresa el DPI a buscar: ";
						cin>>auxDpi;
						verificacionRegistro>>clave;//Lectura adelantada
						encontrado=false;
						while(!verificacionRegistro.eof()){
							verificacionRegistro>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
							//comparar cada registro para ver si es encontrado
							if(strcmp(auxDpi,dpi)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
							{
								cout<<"-------------------------------------"<<endl;
								cout<<"Clave :"<<clave<<endl;
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
							verificacionRegistro>>clave;//lectura adelantada
						}
						if(encontrado==false){
							cout<<"No hay registros con el Dpi: "<<auxDpi<<endl;
						}
					}
					else{
						cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
					}
					//Cerrando el archivo
					verificacionRegistro.close();
					break;
				}
				break;
			case 2:
				cout << " BUSQUEDA POR CODIGO DE EMPLEADO "<< endl;
				if (lectura.is_open()){
					lectura>>clave;
					if(lectura.is_open()){
						cout<<"Ingresa el codigo a buscar: ";
						cin>>auxCodigo;
						lectura>>clave;//Lectura adelantada
						encontrado=false;
						while(!lectura.eof()){
							lectura>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
							//comparar cada registro para ver si es encontrado
							if(strcmp(auxCodigo,codigo)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
							{
								cout<<"-------------------------------------"<<endl;
								cout<<"Clave :"<<clave<<endl;
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
							lectura>>clave;//lectura adelantada
						}
						if(encontrado==false){
							cout<<"No hay registros con el codigo: "<<auxCodigo<<endl;
						}
					}
					else{
						cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
					}
					//Cerrando el archivo
					lectura.close();
					break;
				}
				else{
					if(verificacionRegistro.is_open()){
						lectura>>clave;
						if(verificacionRegistro.is_open()){
						cout<<"Ingresa el codigo a buscar: ";
						cin>>auxCodigo;
						verificacionRegistro>>clave;//Lectura adelantada
						encontrado=false;
						while(!verificacionRegistro.eof()){
							verificacionRegistro>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//Leyendo todos los campos del registro
							//comparar cada registro para ver si es encontrado
							if(strcmp(auxCodigo,codigo)==0)//strcmp (funcion de comparacion de cadenas)(recibe dos parametros(dos cadenas a comparar))(devuelve dos valores 0 cuando son iguales y 1 cuando no)
							{
								cout<<"-------------------------------------"<<endl;
								cout<<"Clave :"<<clave<<endl;
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
							verificacionRegistro>>clave;//lectura adelantada
						}
						if(encontrado==false){
							cout<<"No hay registros con el codigo: "<<auxCodigo<<endl;
						}
					}
					else{
						cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
					}
					//Cerrando el archivo
					verificacionRegistro.close();
					break;
					}	
				}
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
	ofstream eliminar;//ofstream es una clase que permite crear la instancia fich para escribir en un fichero
	ifstream lectura;
	encontrado=false;
	int auxsalida=0;
	eliminar.open("auxiliar.txt",ios::out);
	lectura.open("empleados.txt",ios::in);
	if(eliminar.is_open() && lectura.is_open()){
		cout<<"Ingresa la clave que quieres eliminar: ";
		cin>>auxsalida;
		lectura>>clave;
		while(!lectura.eof()){
			lectura>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;
			if(auxsalida==clave){
				encontrado=true;
				cout<<"Registro eliminado"<<endl;
			}
			else{
				eliminar<<clave<<" "<<dpi<<" "<<codigo<<" "<<nombre<<" "<<nombreDos<<" "<<apellido<<" "<<apelliDos<<" "<<salario<<endl;	
			}
			lectura>>clave;
		}
	}
	else{
		cout<<"No se pudo abrir el archivo, aun no ha sido creado"<<endl;
	}
	lectura.close();
}
void reporteSalario(){
	
	ifstream lecturaReporte;
	lecturaReporte.open("salario.txt",ios::in);
	if(lecturaReporte.is_open()){
	lecturaReporte>>clave;
	cout <<" REPORTE DE LOS SALARIOS MAYORES Al INGRESADO "<< endl;
	cout <<" -------------------------------------------- "<<endl;
		while(!lecturaReporte.eof()){
			lecturaReporte>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;
			cout<<"Clave :"<<clave<<endl;
			cout<<"Dpi :"<<dpi<<endl;
			cout<<"Codigo :"<<codigo<<endl;
			cout<<"Primer nombre :"<<nombre<<endl;
			cout<<"Segundo nombre :"<<nombreDos<<endl;
			cout<<"Primer apellido :"<<apellido<<endl;
			cout<<"Segundo apellido :"<<apelliDos<<endl;
			cout<<"Salario :"<<salario<<endl;
			lecturaReporte>>clave;
		}
	}
	else{
		cout<<"No hay registros mayores al salario ingresado"<<endl;
	}
	//paso 6
	lecturaReporte.close();
}

void reporteMayorSalario(){
	ofstream lecturaReporte;
	lecturaReporte.open("salario.txt",ios::out|ios::app);
	ifstream consulta;
	bool repet=false;
	consulta.open("auxiliar.txt",ios::in);
	//ifstream reporteconsulta;
	//bool repetir=false;
	//reporteconsulta.open("salario.txt",ios::in);
	if(lecturaReporte.is_open() && consulta.is_open()){
		fflush(stdin);
		cout<<"\n Ingresa el monto del salario a buscar: ";
		cin>>auxsalario;
		consulta>>clave;
		while(!consulta.eof()){//Para buscar si hay salarios mayores
			consulta>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;//si se cumple la condicion va ha hacer lectura nuevamente
			if(auxsalario<salario){//si se cumple la condicion es que no hay salarios mayores y no se puede buscar
				cout<<"El numero ingresado es menor que todos los salarios registrados"<<endl;
				repet=true;
				break;//Salida del ciclo
			}
			consulta>>clave;//Consulta adelantada
		}
		if(repet==false){//no se encontro nunca un registro con la clave ingresada por usuario entonces se procede a imprimir datos almacenados en salario
			lecturaReporte<<clave<<" "<<dpi<<" "<<codigo<<" "<<nombre<<" "<<nombreDos<<" "<<apellido<<" "<<apelliDos<<" "<<salario<<endl;
			/*if(lecturaReporte.is_open() && reporteconsulta.is_open()){
				reporteconsulta>>clave;
				while(!reporteconsulta.eof()){
					consulta>>dpi>>codigo>>nombre>>nombreDos>>apellido>>apelliDos>>salario;
					if (){
						repet=true;
						break;	
					}
					reporteconsulta<<clave;//consulta adelantada	
				}
				if(repet==false){
					lecturaReporte<<clave<<" "<<dpi<<" "<<codigo<<" "<<nombre<<" "<<nombreDos<<" "<<apellido<<" "<<apelliDos<<" "<<salario<<endl;
				}
			}
			else{
				cout<<"Archivo no se pudo abrir o no ha sido creado"<<endl;
			}
			lecturaReporte.close();
			reporteconsulta.close();*/
		}	
	}
	else{
		cout<<"Archivo no se pudo abrir o no ha sido creado"<<endl;
	}
	lecturaReporte.close();
	consulta.close();//cierre de consulta
}

void salir(){
	cout<<"Programa Finalizado"<<endl;
}

