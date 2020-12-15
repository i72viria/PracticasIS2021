#include "monitor.h"
#include "ruta.h"
//#include "Visitante.h"

Monitor::Monitor(string nombreM, string apellido1M, string apellido2M,
    string dniM, string direccionM,string emailM, int telefonoM){
        setNombreM(nombreM);
        setApellido1M(apellido1M);
        setApellido2M(apellido2M);
        setDniM(dniM);
        setDireccionM(direccionM);
        setEmailM(emailM);
        setTelefonoM(telefonoM);
}

bool Monitor::crearRuta(Ruta r){
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()==r.getCodigo()){
            return false;
        }
    }
    rutas_.push_back(r);
    return true;   
}

int Monitor::deleteRuta(int codigo){
    if(rutas_.empty()){
        return -1;
    }
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()== codigo){
            rutas_.erase(i);
            return 1;
        }
    }
    return -2;
}

int Monitor::deleteRuta(Ruta r){
    if(rutas_.empty()){
        return -1;
    }
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()== r.getCodigo()){
            rutas_.erase(i);
            return 1;
        }
    }
    return -2;
}

void Monitor::escribeRutas(){
    string nomfichero="rutas.txt";
    fstream f;
    f.open(nomfichero,std::ios::out);
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        f<<i->getCodigo()<<","+
        i->getNombre()<<","+
        i->getEstado()<<","<<
        i->getDificultad()<<","<<
        i->getLongitud()<<","<<
        i->getDuracion()<<"\n";
    }
    f.close();
}

void Monitor::visualizarRutas(){
    rutas_.clear();
    fstream f;
    f.open("rutas.txt",std::fstream::in);
    if(f.is_open()){
        char codigo[225],nombre[225],estado[225],dificultad[225],longitud[225],
            duracion[225];

        
        while(f.getline(codigo,225,',')){
            f.getline(nombre,225,',');
            f.getline(estado,225,',');
            f.getline(dificultad,225,',');
            f.getline(longitud,225,',');
            f.getline(duracion,225,'\n');

            Ruta aux(atoi(codigo),nombre,estado,dificultad,atof(longitud),atof(duracion));
            rutas_.push_back(aux);
            cout<<codigo<<" "<<nombre<<" "<<estado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<"\n";
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}



int main()
{
    Monitor m("Pepe","Pradas","Roldan","123456789X", "San blas", "pepemola@gmail.com",696969696);
    Ruta j(1, "Bosque","Accesible", "Basico", 1.3, 2);
    Ruta i(2, "Rio", "Accesible", "medio",1.5,1.3);
    m.crearRuta(j);
    m.crearRuta(i);
    m.escribeRutas();
    m.visualizarRutas();
    return 0;
}