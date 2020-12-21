#ifndef VISITANTE_H
#define VISITANTE_H


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

  class Visitante{
      private:
        string NombreV_;
        string Apellido1V_;
        string Apellido2V_;
        string DniV_;
        string Fecha_nacimiento_;
        int TelefonoV_;
        string Discapacidad_;
      public:
        Visitante(){}
        Visitante(string NombreV="",string Apellido1V="",string Apellido2V="",string DniV="",string Fecha_nacimiento="",int TelefonoV=0,string Discapacidad=""){
          NombreV_=NombreV;
          Apellido1V_=Apellido1V;
          Apellido2V_=Apellido2V;
          DniV_=DniV;
          Fecha_nacimiento_=Fecha_nacimiento;
          TelefonoV_=TelefonoV;
          Discapacidad_=Discapacidad;
        }
        inline void setNombreV(string NombreV){NombreV_=NombreV;}
        inline string getNombreV(){return NombreV_;}

        inline void setApellido1V(string Apellido1V){Apellido1V_=Apellido1V;}
        inline string getApellido1V(){return Apellido1V_;}

        inline void setApellido2V(string Apellido2V){Apellido2V_=Apellido2V;}
        inline string getApellido2V(){return Apellido2V_;}

        inline void setDniV(string DniV){DniV_=DniV;}
        inline string getDniV(){return DniV_;}

        inline void setFecha_nacimiento(string Fecha_nacimiento){Fecha_nacimiento_=Fecha_nacimiento;}
        inline string getFecha_nacimiento(){return Fecha_nacimiento_;}

        inline void setTelefonoV(int TelefonoV){TelefonoV_=TelefonoV;}
        inline int getTelefonoV(){return TelefonoV_;}

        inline void setDiscapacidad(string Discapacidad){Discapacidad_=Discapacidad;}
        inline string getDiscapacidad(){return Discapacidad_;}

        void getDatos();
};
#endif
