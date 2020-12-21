#include "reserva.h"

//CONSTRUCTOR
Reserva::Reserva(string fecha_reserva, string dni_reserva, string tipo_ruta){
   setFechaReserva(fecha_reserva);
   setDniReserva(dni_reserva);
   setTipoRuta(tipo_ruta);
}

//FUNCION QUE MUESTRA LAS RESERVAS
void Reserva::getReservas(){
    fstream f;
    f.open("rutas.txt",std::fstream::in);
    if(f.is_open()){
        char fecha[225], dni[225], tipo[225];

        while(f.getline(fecha,225,',')){
            f.getline(dni,225,',');
            f.getline(tipo,225,'\n');
            
            cout<<" "<<fecha<<" "<<dni<<" "<<tipo<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
}
   
