#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct ;

class Ruta
{
    private:
        int codigo_;
        string nombre_;
        string estado_;
        string dificultad_;
        float longitud_;
        float duracion_;

    public:
        Ruta(int codigo=0, string nombre="", string estado="", string dificultad="", float longitud=0, float duracion=0);

        //MODIFICADORES
        inline bool setCodigo(int codigo){if(codigo=000000)return false; else codigo_=codigo; return true;}
        inline void setNombre(string nombre){nombre=nombre_;}
        inline void setEstado(string estado){estado=estado_;}
        inline void setDificultad(stirng dificultad){dificultad=dificultad_;}
        inline void setLongitud(float longitud){longitud=longitud_;}
        inline void setDuracion(float duracion){duracion=duracion_;}

        //OBSERVADORES       
        inline int getCodigo()const{return codigo_;}
        inline void setNombre()const{return nombre_;}
        inline void setEstado()const{return estado_;}
        inline void setDificultad()const{return dificultad_;}
        inline void setLongitud()const{return longitud_;}
        inline void setDuracion()const{return duracion_;}


        //OTRAS FUNCIONES
        void getRutas();
};

#endif