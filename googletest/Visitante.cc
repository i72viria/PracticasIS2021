#include "Visitante.h"

 void Visitante::getDatos(){
//   visitantes_.clear();
   fstream f;
   f.open("visitantes.txt",std::fstream::in);
   if(f.is_open()){
       char NombreV[225],Apellido1V[225],Apellido2V[225],DniV[225],Fecha_nacimiento[225],TelefonoV[225],Discapacidad[225];

       while(f.getline(NombreV,225,',')){
           f.getline(Apellido1V,225,',');
           f.getline(Apellido2V,225,',');
           f.getline(DniV,225,',');
           f.getline(Fecha_nacimiento,225,',');
           f.getline(TelefonoV,225,',');
           f.getline(Discapacidad,225,'\n');


//           visitantes_.push_back(aux);
           cout<<NombreV<<" "<<Apellido1V<<" "<<Apellido2V<<" "<<DniV<<" "<<Fecha_nacimiento<<" "<<Discapacidad<<endl;
       }
   }
       else{
           cout<<"Error. No se pudo abrir el fichero";
       }
   f.close();
 }
