//Programa que lee un archivo CSV para texto.
//Creado por Camilo Acevedo.
//Inspirado lector de archivos Cesar Aceros.


#include <fstream> // Libreria para leer y escribir desde / hacia archivos.
#include <string> //Archivo de la biblioteca que contiene la defincion de constantes, funciones y algunas operaciones.
#include <vector> //Libreria para operar con arreglos unidimensionales de datos
#include <sstream> //Libreria que proporciona plantillas y tipos que permiten la interoperación entre búferes de flujo y objetos de cadena .
#include <iostream> //Componente de la biblioteca, utilizado para operaciones de entrada / salida.
using namespace std; //Creamos un bloque que asocie nuestras funciones

void parseCSV() //Indicamos el tipo de datos.
{
    ifstream data("Book1.csv"); //Buscamos nuestro archivo csv para ser leido.
    string line; // secuencia de caracteres guardados como una fila.
    vector<vector<string>> parsedCsv; //Almacenamos nuestros datos de la secuencia de caracteres.
    int rowcount=0; //Declaramos una variable.
    int colcount=0; //Declaramos una variable.
    while(getline(data,line)) //Ciclo para ejecutar nuestars instrucciones.
    {
        stringstream lineStream(line); //Tratamos un string como un stream, eso nos permite la inserción y la extracción desde y a strings
        string cell; //secuencia de caracteres guardados.
        vector<string> parsedRow; //Almacenamos nuestros datos.
        colcount=0; //Miramos la cantidad de columnas del archivo.
        while(getline(lineStream,cell,',')) //Ciclo para ejecutar nuestars instrucciones.
        {
            parsedRow.push_back(cell); // recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector
            colcount++; //Miramos la cantidad de columnas del archivo.
        }
        rowcount++; //Miramos la cantidad de filas del archivo.
        parsedCsv.push_back(parsedRow); //recibe como parámetro un elemento del mismo tipo del que se compone nuestro vector
    }
    for (int i=0; i<rowcount; i++){ //Ciclo de control para ejecutar nuestro bloque de columnas.
        for (int j=0; j < colcount ; j++){ //Ciclo de control para ejecutar nuestro bloque de filas.
        cout << parsedCsv[i][j] << " -- "; // imprimimos nuestro resultado separado por --.
        }
        cout << '\n'; //Se imprime nuestro resultado con un salto de linea.
    }
}


int main() //Declaramos nuestra variable para iniciar la ejecucion del programa.
{
    parseCSV(); //Analizamos nuestro archivo para determinar su estructura.
    return 0; //Se abandona el main.
}