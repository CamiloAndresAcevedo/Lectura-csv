//Programa que lee un archivo CSV para texto.
//Creado por Camilo Acevedo.
//Inspirado lector de archivos Cesar Aceros.


#include <fstream> //
#include <string> //
#include <vector> //
#include <sstream> //
#include <iostream> //
using namespace std; //

void parseCSV() //
{
    ifstream data("Book1.csv"); //
    string line; //
    vector<vector<string>> parsedCsv; //
    int rowcount=0; //
    int colcount=0; //
    while(getline(data,line)) //
    {
        stringstream lineStream(line); //
        string cell; //
        vector<string> parsedRow; //
        colcount=0; //
        while(getline(lineStream,cell,',')) //
        {
            parsedRow.push_back(cell); //
            colcount++; //
        }
        rowcount++; //
        parsedCsv.push_back(parsedRow); //
    }
    for (int i=0; i<rowcount; i++){ //
        for (int j=0; j < colcount ; j++){ //
        cout << parsedCsv[i][j] << " -- "; //
        }
        cout << '\n'; //
    }
}


int main() //
{
    parseCSV(); //
    return 0; //
}