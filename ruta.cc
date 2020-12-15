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
