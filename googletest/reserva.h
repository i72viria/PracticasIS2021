#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Reserva{
    private:
        string fecha_reserva_;
        string dni_reserva_;  
        string tipo_ruta_;

    public:
        //CONSTRUCTOR
        Reserva(string fecha_reserva="", string dni_reserva="", string tipo_ruta="");

        //MODIFICADOR Y OBSERVADOR FECHA RESERVA
        inline void setFechaReserva(string fecha_reserva){fecha_reserva_=fecha_reserva;}
        inline string getFechaReserva(){return fecha_reserva_;}

        //MODIFICADOR Y OBSERVADOR DNI RESERVA
        inline void setDniReserva(string dni_reserva){dni_reserva_=dni_reserva;}
        inline string getDniReserva(){return dni_reserva_;}

        //MODIFICADOR Y OBSERVADOR TIPO RUTA
        inline void setTipoRuta(string tipo_ruta){tipo_ruta_=tipo_ruta;}
        inline string getTipoRuta(){return tipo_ruta_;}

        //FUNCIONES
        void getReservas();      //FUNCION QUE MUESTRA LAS RESERVAS
};

#endif