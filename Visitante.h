#ifndef VISITANTE_H
#define VISITANTE_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

  class Visitante{
      private:
        string NombreV_;
        string Apellido1V_;
        string Apellido2V_;
        string DniV_;
        date Fecha_nacimiento_;
        int TelefonoV_;
        string Discapacidad_;
      public:
        Visitante(){}
        Visitante(string NombreV,string Apellido1V,string Apellido2V,string DniV,date Fecha_nacimiento,int TelefonoV,string Discapacidad){
          NombreV_=NombreV;
          Apellido1V_=Apellido1V;
          Apellido2V_=Apellido2V;
          DniV_=DniV;
          Fecha_nacimiento_=Fecha_nacimiento;
          TelefonoV_=TelefonoV;
          Discapacidad_=Discapacidad;
        }
        inline void setNombreV(string NombreV){NombreV=NombreV_;}
        inline string getNombreV(){return NombreV_;}

        inline void setApellido1V(string Apellido1V){Apellido1V=Apellido1V_;}
        inline string getApellido1V(){return getApellido1V_;}

        inline void setApellido2V(string Apellido2V){Apellido2V=Apellido2V_;}
        inline string getApellido2V(){return Apellido2V_;}

        inline void setDniV(string DniV){DniV=DniV_;}
        inline string getDniV(){return DniV_;}

        inline void setFecha_nacimiento(date Fecha_nacimiento){Fecha_nacimiento=Fecha_nacimiento_;}
        inline date getFecha_nacimiento(){return Fechanacimiento_;}

        inline void setTelefonoV(int TelefonoV){TelefonoV=TelefonoV_;}
        inline int getTelefonoV(){return TelefonoV_;}

        inline void setDiscapacidad(string Discapacidad){Discapacidad=Discapacidad_;}
        inline string getDiscapacidad(){return Discapacidad_;}

};
#endif
