#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Reserva{
    private:
        date fecha_reserva_;
        string dni_reserva_;  
        string tipo_ruta_;

    public:
        inline void setFechaReserva(date fecha_reserva){fecha_reserva_=fechareserva;}
        inline date getFechaReserva(){return fecha_reserva_;}

        inline void setDniReserva(string dni_reserva){dni_reserva_=dni_reserva;}
        inline string getDniReserva(){return dni_reserva_}

        inline void setTipoRuta(string tipo_ruta){tipo_ruta_=tipo_ruta;}
        inline string getTipoRuta(){return tipo_ruta_;}
};

#endif