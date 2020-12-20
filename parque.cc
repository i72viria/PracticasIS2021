#include "parque.h"

void Parque::visualizarRutas(){
    parque_.clear();
    fstream f;
    f.open("parque.txt",std::fstream::in);
    if(f.is_open()){
        char nombre[225],localizacion[225],superficie[225],fecha_reconocimiento[225],telefono_parque[225],horario[225];

        while(f.getline(nombre,225,',')){
            f.getline(localizacion,225,',');
            f.getline(superficie,225,',');
            f.getline(fecha_reconocimiento,225,',');
            f.getline(telefono_parque,225,',');
            f.getline(horario,225,'\n');

            Parque aux(nombre,localizacion,superficie,fecha_reconocimiento,telefono_parque,horario);
            parque_.push_back(aux);
            cout<<nombre<<" "<<localizacion<<" "<<fecha_reconocimiento<<" "<<telefono_parque<<" "<<horario<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}
