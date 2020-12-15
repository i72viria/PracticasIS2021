#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

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
        inline void setNombre(string nombre){nombre_=nombre;}
        inline void setEstado(string estado){estado_=estado;}
        inline void setDificultad(string dificultad){dificultad_=dificultad;}
        inline void setLongitud(float longitud){longitud_=longitud;}
        inline void setDuracion(float duracion){duracion_=duracion;}

        //OBSERVADORES       
        inline int getCodigo()const{return codigo_;}
        inline string getNombre()const{return nombre_;}
        inline string getEstado()const{return estado_;}
        inline string getDificultad()const{return dificultad_;}
        inline float getLongitud()const{return longitud_;}
        inline float getDuracion()const{return duracion_;}


        //OTRAS FUNCIONES
        void getRutas();
};

#endif