
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

#include <cstdlib>
#include <iostream>
#include <fstream> //Paso 1

using namespace std; //Permite tener un alcance directo a todas las funciones declaradas en un espacio de nombres "std"

int main(){
	char nombre[30], nombreDos[30], apellido[30], apelliDos[30], resp[1];
	string dpi,salario,codigo;
	
	ofstream  escritura; //Paso 2
	//Decirle que agrege informacion al final (que no lo borre) agregamos ios::app (y ios::app sirve para poder escribir en el archivo y que no borre lo que teniamos(lo añade al final)
	escritura.open("empleados.txt",ios::out|ios::app); //paso 3 (ios::out es para poder escribir en el archivo(escritura) pero borra lo que teniamos)
	//Paso 4 (Validacion de apertura del archivo)
	if(escritura.is_open()){
		do{
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
			cout<<"\n Deseas ingresar datos de otro empleado (S/N))?: ";
			cin>>resp[0];
			cout<<"Registro Agregado"<<endl;
		}while(resp[0]=='S'|resp[0]=='s');//condicion de do while
		//fin de do while
	}
	else{
		cout<<"Archivo no abierto"<<endl;
	}
	escritura.close(); //Paso 6
	
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
	return 0;
	system ("Pause");
}
