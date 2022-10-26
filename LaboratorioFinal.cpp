
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

#include <cstdlib>
#include <iostream>
#include <fstream> //Paso 1

using namespace std; //Permite tener un alcance directo a todas las funciones declaradas en un espacio de nombres "std"

int main(){
	char dpi[15], nombre[30], apellido[30], salario[30],resp[1];
	int codigo=0;
	ofstream  escritura; //Paso 2
	
	//Decirle que agrege informacion al final (que no lo borre) agregamos ios::app (y ios::app sirve para poder escribir en el archivo y que no borre lo que teniamos(lo añade al final)
	escritura.open("empleados.txt",ios::out|ios::app); //paso 3 (ios::out es para poder escribir en el archivo(escritura) pero borra lo que teniamos)
	//Paso 4 (Validacion de apertura del archivo)
	if(escritura.is_open()){
		do{
			fflush(stdin);
			cout<<"Archivo abierto"<<endl;
			//Ingreso de datos
			cout<<"\n Empleado No."<<endl;
			cout<<"\n Ingrese su Dpi: ";
			cin>>dpi;
			cout<<"\n Ingrese su Codigo de empleado: ";
			cin>>codigo;
			cout<<"\n Ingrese su Nombre: ";
			cin>>nombre;
			cout<<"\n Ingrese su Apellido: ";
			cin>>apellido;
			cout<<"\n Ingrese su salario: ";
			cin>>salario;
			
			//Escribiendo datos en el archivo
			escritura<<dpi<<" "<<codigo<<" "<<nombre<<" "<<apellido<<" "<<salario<<endl;
			cout<<"\n Deseas ingresar datos de otro empleado (S/N))?: ";
			cin>>resp[0];
			cout<<"Registro Ageragado"<<endl;
		}while(resp[0]=='S'|resp[0]=='s');//condicion de do while
		//fin de do while
	}
	else{
		cout<<"Archivo no abierto"<<endl;
	}
	escritura.close(); //Paso 6
	return 0;
	system ("Pause");
}
