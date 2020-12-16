#include "monitor.h"
#include "ruta.h"


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
    cout<<"Creando una nueva ruta..."<<endl;
    for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
        if(i->getCodigo()==r.getCodigo()){
            return false;
        }
    }
    
    rutas_.push_back(r);
    cout<<"Ruta creada con exito"<<endl;
    return true;   
}


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
    cout<<"\nCambiando el estado de la ruta "<<r.getCodigo()<<" cuyo estado es "<<r.getEstado()<<endl;
    int codigo=0;
    string nombre="", newestado="", dificultad="";
    float longitud=0.0, duracion=0.0;
    cout<<"Introduce el nuevo estado de la ruta"<<endl;
    cin>>newestado;
    cout<<endl;
    int a=0;

        for(list<Ruta>::iterator i=rutas_.begin();i!=rutas_.end();i++){
            if(i->getCodigo()== r.getCodigo()){
                codigo=r.getCodigo();
                nombre=r.getNombre();
                dificultad=r.getDificultad();
                longitud=r.getLongitud();
                duracion=r.getDuracion();
                cout<<"Actualizando.."<<endl;
                cout<<"Ruta actualizada "<<codigo<<" "<<nombre<<" "<<newestado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<"\n";

            }
        }   
            deleteRuta(codigo);
            
            
            Ruta aux(codigo, nombre, newestado, dificultad, longitud, duracion);
                rutas_.push_back(aux);
}


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





 

int main()
{
    Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696,"VictoriaPradasLaguna","123456789X");
    Ruta j(1, "Bosque","Accesible", "Basico", 1.3, 2);
    Ruta i(2, "Rio", "Accesible", "medio",1.5,1.3);
    int menu=0;
    /*if( m.identificacion()==0){
        return 0;
    }*/

    while(menu!=5){
    cout<<endl<<endl;
    cout<<"MENU:"<<endl;
    cout<<"1. Crear una ruta"<<endl;
    cout<<"2. Crear una ruta introduciendo los datos."<<endl;
    cout<<"3. Visualiza las rutas existentes."<<endl;
    cout<<"4. Cambiar estado de una ruta determinada."<<endl;
    cout<<"5. Visualizar visitantes. "<<endl;
    cout<<"6. Salir"<<endl;
    cin>>menu;

    cout<<endl<<endl;

    switch(menu){
        case 1:     
            cout<<"1. Crear una ruta"<<endl;
            m.crearRuta(j);
            m.crearRuta(i);
            m.escribeRutas();
            cout<<endl;
            cout<<"Las rutas existentes son:"<<endl;
            m.visualizarRutas();
        break;

        case 2:
            cout<<"2. Crear una ruta introduciendo los datos."<<endl;
            m.crearRuta(); 
            m.escribeRutas();
            cout<<"Las rutas existentes son:"<<endl;
            m.visualizarRutas();
        break;

        case 3:
            cout<<"3. Visualiza las rutas existentes."<<endl;
            m.visualizarRutas();
        break;

        case 4:
            cout<<"4. Cambiar estado de una ruta determinada."<<endl;
            m.cambiarEstadoRuta(i);
            m.cambiarEstadoRuta(j);
            m.escribeRutas();
        break;

        case 5: 
            cout<<"5. Visualizar visitantes. "<<endl;
            m.visualizarVisitantes();
        break;
        case 6:
            exit(EXIT_FAILURE);
        break;

    }
    }

   
   
    return 0;
}