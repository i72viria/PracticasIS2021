#include "ruta.h"
#include <iostream>

using namespace std;

Ruta::Ruta(int codigo, string nombre, string estado, string dificultad, float longitud, float duracion)
{
    setCodigo(codigo);
    setNombre(nombre);
    setEstado(estado);
    setDificultad(dificultad);
    setLongitud(longitud);
    setDuracion(duracion);
}

void Ruta::getRutas()
{
    fstream f;
    f.open("rutas.txt",std::fstream::in);
    if(f.is_open()){
        char codigo[225],nombre[225],estado[225],dificultad[225],longitud[225],
            duracion[225];
        
        while(f.getline(codigo,225,',')){
            f.getline(nombre,225,',');
            f.getline(estado,225,',');
            f.getline(dificultad,225,',');
            f.getline(longitud,225,',');
            f.getline(duracion,225,'\n');

            cout<<codigo<<" "<<nombre<<" "<<estado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<"\n";
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}

int main()
{
    Ruta t;
    t.getRutas();
    return 0;
}