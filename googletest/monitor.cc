#include "monitor.h"
#include "ruta.h"

//CONSTRUCTOR
Monitor::Monitor(string nombreM, string apellido1M, string apellido2M,
    string dniM, string direccionM,string emailM, int telefonoM){
        setNombreM(nombreM);
        setApellido1M(apellido1M);
        setApellido2M(apellido2M);
        setDniM(dniM);
        setDireccionM(direccionM);
        setEmailM(emailM);
        setApellido1M(apellido1M);
        setApellido2M(apellido2M);
        setDniM(dniM);
        setDireccionM(direccionM);
        setEmailM(emailM);
        setTelefonoM(telefonoM);
        setUsuario();
        setContrasena();
}

//FUNCION IDENTIFICACION
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

//FUNCION CREAR RUTA
bool Monitor::crearRuta(Ruta r){
    //cout<<"Creando una nueva ruta..."<<endl;
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()==r.getCodigo()){
            return false;
        }
    }
    
    rutas_.push_back(r);
    //cout<<"Ruta creada con exito"<<endl;
    return true;   
}

//FUNCION CREAR RUTA PIDIENDO DATOS
bool Monitor::crearRuta(){
    cout<<"Creando una nueva ruta..."<<endl;
    int codigo;
    string nombre, estado, dificultad;
    float longitud, duracion;
    cout<<"Introduce un codigo identificador de la ruta: "<<endl;
    cin>>codigo;
    cout<<"Introduce el nombre: "<<endl;
    cin>>nombre;
    cout<<"Introduce el estado de la ruta: "<<endl;
    cin>>estado;
    cout<<"Introduce el dificultad: "<<endl;
    cin>>dificultad;
    cout<<"Introduce la longitud: "<<endl;
    cin>>longitud;
    cout<<"Introduce la duración aproximada: "<<endl;
    cin>>duracion;

    Ruta aux(codigo, nombre, estado, dificultad, longitud, duracion);
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()==aux.getCodigo()){
            return false;
        }
    }
    
    rutas_.push_back(aux);
    cout<<"Ruta creada con exito"<<endl;
    return true;   
}

//FUNCION ELEMINAR RUTA POR CODIGO
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

//FUNCION ELIMINAR RUTA
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

//FUNCION ESCRIBE RUTAS EN UN FICHERO
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

//FUINCON LEE RUTAS DEL FICHERO
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

//FUNCION CAMBIAR ESTADO Y GUARDARLA EN EL FICHERO
 void Monitor::cambiarEstadoRuta(Ruta r){
    //cout<<"\nCambiando el estado de la ruta "<<r.getCodigo()<<" cuyo estado es "<<r.getEstado()<<endl;
    int codigo=0;
    string nombre="", newestado="", dificultad="";
    float longitud=0.0, duracion=0.0;
    cout<<"Introduce el nuevo estado de la ruta"<<endl;
    cin>>newestado;
    cout<<endl;

        for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
            if(i->getCodigo()== r.getCodigo()){
                codigo=r.getCodigo();
                nombre=r.getNombre();
                dificultad=r.getDificultad();
                longitud=r.getLongitud();
                duracion=r.getDuracion();
                //cout<<"Actualizando.."<<endl;
                cout<<"Ruta actualizada   "<<codigo<<" "<<nombre<<" "<<newestado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<"\n";

            }
        }   
            deleteRuta(codigo);
            
            
            Ruta aux(codigo, nombre, newestado, dificultad, longitud, duracion);
                rutas_.push_back(aux);
}

//FUNCION ELIGE RUTA
int Monitor::seleccionaRuta(Ruta r){
    int codigo;
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()== r.getCodigo()){
            codigo=r.getCodigo();
            cout<<endl<<"Ha seleccionado la ruta con codigo "<<codigo<<endl;
        }
    }

    return codigo;
}

//FUNCION VISUALIZAR LOS VISITANTES EXISTENTES
void Monitor::visualizarVisitantes(){
    cout<<"\nVisualizando visitantes y características..."<<endl;
    fstream f;
    f.open("visitantes.txt",std::fstream::in);
    if(f.is_open()){
        char nombre[225],apellido1[225],apellido2[225],dni[225],
            fecha_nacimiento[225],telefono[225],discapacidad[225];

        
        while(f.getline(nombre,225,',')){
            f.getline(apellido1,225,',');
            f.getline(apellido2,225,',');
            f.getline(dni,225,',');
            f.getline(fecha_nacimiento,225,',');
            f.getline(telefono,225,',');
            f.getline(discapacidad,225,'\n');

            
            cout<<nombre<<apellido1<<apellido2<<discapacidad<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}





 