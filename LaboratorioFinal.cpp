
//Creacion del archivo main y colocacion de librerias
/*Libreria cstdlib (cstdlib=libreria para convertir un entero a cadena de caracteres)
  libreria iostream (iostream= para poder tener acceso a los dispositivos est�ndar de entrada y/o salida)

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
	
	ofstream  escritura; //Paso 2
	escritura.open("datos.txt",ios::out); //paso 3 (ios::out es poder escribir en el archivo(escritura))
	//Paso 5 (Validacion de apertura del archivo)
	if(escritura.is_open()){
		cout<<"Archivo abierto"<<endl;
		escritura<<"Hola, hola, buenos dias"<<endl;
	}
	else{
		cout<<"Archivo no abierto"<<endl;
	}
	/*Segunda forma de hacerlo
	if(!escritura.fail()){
		cout<<"Archivo abierto"<<endl;
		escritura<<"Hola, hola, buenos dias, segunda forma de verificacion"<<endl;
	}
	else{
		cout<<"Archivo no abierto"<<endl;
	}
	*/
	
	escritura.close(); //Paso 6
	return 0;
	system ("Pause");
}