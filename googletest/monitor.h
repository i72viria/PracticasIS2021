#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cstdlib>
#include "ruta.h"
#include "Visitante.h"

using namespace std;


class Monitor{
    private:
        string nombreM_;
        string apellido1M_;
        string apellido2M_;
        string dniM_;
        string direccionM_;
        string emailM_;
        int telefonoM_;
        string usuario_;
        string contrasena_;
        list<Ruta> rutas_;
        list<Visitante> visitantes_;

    public:
        //CONSTRUCTOR CLASE MONITOR
        Monitor(string nombreM="", string apellido1M="", string apellido2M="",
            string dniM="", string direccionM="",string emailM="", int telefonoM=0, string usuario="", string contrasena="");
        //MODIFICADOR Y OBSERVADOR NOMBRE MONITOR
        inline void setNombreM(string nombreM){nombreM_=nombreM;}
        inline string getNombreM(){return nombreM_;}
        
        //MODIFICADOR Y OBSERVADOR APELLIDO1 MONITOR
        inline void setApellido1M(string apellido1M){apellido1M_=apellido1M;}
        inline string getApellido1M(){return apellido1M_;}

        //MODIFICADOR Y OBSERVADOR APELLIDO2 MONITOR
        inline void setApellido2M(string apellido2M){apellido2M_=apellido2M;}
        inline string getApellido2M()const{return apellido2M_;}     

        //MODIFICADOR Y OBSERVADOR DNI MONITOR
        inline void setDniM(string dniM){dniM_=dniM;}
        inline string getDniM()const{return dniM_;}

        //MODIFICADOR Y OBSERVADOR DIRECCION MONITOR
        inline void setDireccionM(string direccionM){direccionM_=direccionM;}
        inline string getDireccionM()const{return direccionM_;}

        //MODIFICADOR Y OBSERVADOR EMAIL MONITOR
        inline void setEmailM(string emailM){emailM_=emailM;}
        inline string getEmailM()const {return emailM_;}

        //MODIFICADOR Y OBSERVADOR TELEFONO MONITOR
        inline void setTelefonoM(int telefonoM){telefonoM_=telefonoM;}
        inline int TelefonoM()const{return telefonoM_;}

        //MODIFICADOR Y OBSERVADOR USUARIO MONITOR
        inline void setUsuario(string usuario){usuario=getNombreM()+getApellido1M()+getApellido2M(); usuario_= usuario;}
        inline string getUsuario()const{return usuario_;}

        //MODIFICADOR Y OBSERVADOR CONSTRASEÑA MONITOR
        inline void setContrasena(string contrasena){contrasena=getDniM(); contrasena_=contrasena;}   
        inline string getContrasena()const{return contrasena_;}

        //LISTA RUTAS Y VISITANTES
        inline list<Ruta> getRutas()const{return rutas_;}
        inline list<Visitante> getVisitantes()const{return visitantes_;}

        //FUNCIONES 
        bool identificacion();          //Identifiación de usuario
        bool crearRuta(Ruta r);         //Crea una nueva ruta 
        bool crearRuta();               //Crear una ruta pidiendo datos
        int deleteRuta(int codigo);     //Elinima una ruta a partir del codigo
        int deleteRuta(Ruta r);         //Elimina una ruta a partir de la clase
        void escribeRutas();            //Escribe las rutas existentes en un fichero
        void visualizarRutas();         //Visualiza rutas existentes del parque
        void cambiarEstadoRuta(Ruta r); //Cambia el estado de la ruta.
        void visualizarVisitantes();    //Visualiza datos del visitante
};

#endif