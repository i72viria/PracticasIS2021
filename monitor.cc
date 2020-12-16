#include "monitor.h"
#include "ruta.h"
//#include "Visitante.h"

Monitor::Monitor(string nombreM, string apellido1M, string apellido2M,
    string dniM, string direccionM,string emailM, int telefonoM, string usuario, string contrasena){
        setNombreM(nombreM);
        setApellido1M(apellido1M);
        setApellido2M(apellido2M);
        setDniM(dniM);
        setDireccionM(direccionM);
        setEmailM(emailM);
        setTelefonoM(telefonoM);
        setUsuario(usuario);
        setContrasena(contrasena);
}

bool Monitor::identificacion(){
    cout<<"Identificate para acceder: "<<endl;
    string usuarioID, contrasenaID;
    cout<<"Introduce el usuario: ";
    cin>>usuarioID; cout<<endl;
    cout<<"Introduce la contrasena: ";
    cin>>contrasenaID; cout<<endl;

    string usuario=getUsuario();
    string contrasena=getContrasena();

    if(usuario==usuarioID)
    {
        if(contrasena==contrasenaID) 
        {
            cout<<"Has accedido al sistema con exito"<<endl;
            return true;
        }
        else 
        {
            cout<<"No has accedido al sistema. CONTRASEÑA ERRONEA"<<endl;
            return false;
        }
    }
    else 
    {
        cout<<"No has accedido al sistema. USUARIO ERRONEO"<<endl;
        return false;
    }

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

 void Monitor::cambiarEstadoRuta(Ruta r){
    int codigo=0;
    string nombre="", newestado="", dificultad="";
    float longitud=0.0, duracion=0.0;
    cout<<"Introduce el nuevo estado de la ruta"<<endl;
    cin>>newestado;
    int a=0;

        for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
            if(i->getCodigo()== r.getCodigo()){
                codigo=r.getCodigo();
                nombre=r.getNombre();
                dificultad=r.getDificultad();
                longitud=r.getLongitud();
                duracion=r.getDuracion();
                cout<<"Actualizando.."<<endl;
                cout<<"Nueva ruta "<<codigo<<" "<<nombre<<" "<<newestado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<"\n";

            }
        }   
            deleteRuta(codigo);
            cout<<"borrado"<<endl;
            
            Ruta aux(codigo, nombre, newestado, dificultad, longitud, duracion);
                cout<<"Y ahora introducirla en la lista"<<endl;
                rutas_.push_back(aux);
                escribeRutas();
                visualizarRutas();

}

int main()
{
    Monitor m("Pepe","Pradas","Roldan","123456789X", "San blas", "pepemola@gmail.com",696969696,"PepePradasRoldan","123456789X");
    Ruta j(1, "Bosque","Accesible", "Basico", 1.3, 2);
    Ruta i(2, "Rio", "Accesible", "medio",1.5,1.3);
    if( m.identificacion()==0){
        return 0;
    }
    m.crearRuta(j);
    m.crearRuta(i);
    m.escribeRutas();
    m.visualizarRutas();
    m.cambiarEstadoRuta(i);
    m.cambiarEstadoRuta(j);
    return 0;
}