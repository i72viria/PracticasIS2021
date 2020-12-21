#ifndef PARQUE_H
#define PARQUE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
#include "reserva.h"
#include "ruta.h"

using namespace std;

  class Parque{
    private:
      string nombre_;
      string localizacion_;
      float superficie_;
      string fecha_reconocimiento_;
      int telefono_parque_;
      string horario_;
      list <Ruta> rutas_;
      list <Reserva> reservas_;
      list <Parque> parque_;
    public:
      Parque(){}
      Parque(string nombre=",",string localizacion=",",float superficie=0,string fecha_reconocimiento=",",int telefono_parque=0,string horario=",");
      inline void setNombre(string nombre){nombre_=nombre;}
      inline string getNombre(){return nombre_;}

      inline void setLocalizacion(string localizacion){localizacion_=localizacion;}
      inline string getLocalizacion(){return localizacion_;}

      inline void setSuperficie(float superficie){superficie_=superficie;}
      inline float getSuperficie(){return superficie_;}

      inline void setFecha_reconocimiento(string fecha_reconocimiento){fecha_reconocimiento_=fecha_reconocimiento;}
      inline string getFecha_reconocimiento(){return fecha_reconocimiento_;}

      inline void setTelefono_parque(int telefono_parque){telefono_parque_=telefono_parque;}
      inline int getTelefono_parque(){return telefono_parque_;}

      inline void setHorario(string horario){horario_=horario;}
      inline string getHorario(){return horario_;}


      void visualizarRutas();
      void visualizarVisitantesReserva();
      void mostrarEstadoRuta();
      void buscarInformacion(Parque r);
};
#endif
