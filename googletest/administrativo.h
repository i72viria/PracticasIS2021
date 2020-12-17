#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include "reserva.h"
#include "Visitante.h"

using namespace std;

class Administrativo
{
    private:
        string nombreA;
        string apellido1A;
        string apellido2A;
        string dniA;
        string direccionA;
        string emailA;
        int telefonoA;
        string usuario_;
        string contrasena_;
        list<Reserva> reservas_;
        list<Visitante> visitantes_;

    public:
        Administrativo(string nombre="", string apellido1="", string apellido2="", string dni="",
        string direccion="",string email="", int telefono=0, string usuario="", string contrasena="");

        //MODIFICADORES
        inline void setNombre(string nombre){nombreA=nombre;}
        inline void setApellido1(string apellido1){apellido1A=apellido1;}
        inline void setApellido2(string apellido2){apellido2A=apellido2;}
        inline void setDni(string dni){dniA=dni;}
        inline void setDireccion(string direccion){direccionA=direccion;}
        inline void setEmail(string email){emailA=email;}
        inline void setTelefono(int telefono){telefonoA=telefono;}
        inline void setUsuario(string usuario){usuario=getNombre()+getApellido1()+getApellido2(); usuario_= usuario;}
        inline void setContrasena(string contrasena){contrasena=getDni(); contrasena_=contrasena;}

        //OBSERVADORES       
        inline string getNombre()const{return nombreA;}
        inline string getApellido1()const{return apellido1A;}
        inline string getApellido2()const{return apellido2A;}
        inline string getDni()const{return dniA;}
        inline string getDireccion()const{return direccionA;}
        inline string getEmail()const{return emailA;}
        inline int getTelefono()const{return telefonoA;}
        inline string getUsuario()const{return usuario_;}
        inline string getContrasena()const{return contrasena_;}


        //OTRAS FUNCIONES
        bool identificacion();
        bool creaReserva(Reserva y);
        void setVisitante();
        void modificaInformacion();
        void editarOanadirInformacion();

        //FUNCIONES DE APOYO
        void escribeReservas();
        void visualizarReservas();
        void escribeVisitantes();
        void visualizarVisitantes();
};

#endif