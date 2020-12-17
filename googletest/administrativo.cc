#include "administrativo.h"
#include "reserva.h"
#include <iostream>
#include "Visitante.h"

using namespace std;

Administrativo::Administrativo(string nombre, string apellido1, string apellido2, string dni, string direccion,string email, int telefono, string usuario, string contrasena)
{
    setNombre(nombre);
    setApellido1(apellido1);
    setApellido2(apellido2);
    setDni(dni);
    setDireccion(direccion);
    setEmail(email);
    setTelefono(telefono);
    setUsuario(usuario);
    setContrasena(contrasena);
}

bool Administrativo::identificacion()
{
    cout<<"Identificate para acceder: "<<endl;
    string usuarioID, contrasenaID;
    cout<<"Introduce el usuario: ";
    cin>>usuarioID;
    cout<<"Introduce la contrasena: ";
    cin>>contrasenaID;

    string usuario=getUsuario();
    string contrasena=getContrasena();

    if(usuario==usuarioID)
    {
        if(contrasena==contrasenaID) 
        {
            cout<<"Has accedido al sistema con exito."<<endl;
            return true;
        }
        else 
        {
            cout<<"No has accedido al sistema. ERROR"<<endl;
            return false;
        }
    }
    else 
    {
        cout<<"No has accedido al sistema. ERROR"<<endl;
        return false;
    }

}

bool Administrativo::creaReserva(Reserva y)
{
    for(list<Reserva>::iterator i=reservas_.begin();i!=reservas_.end();i++)
    {
        if(i->getDniReserva()==y.getDniReserva())
        {
            cout<<"Reserva fallida"<<endl;
            return false;
        }
    }
    cout<<"Reserva creada con exito. DNI asociado a la reserva: "<<y.getDniReserva()<<endl;
    reservas_.push_back(y);
    return true;   
}

void Administrativo::setVisitante()
{
    string nombre,apellido1,apellido2,dni,fecha_nacimiento,discapacidad;
    int telefono;

    cout<<"Introduce el nombre del visitante: ";
    cin>>nombre;
    cout<<"Introduce el primer apellido: ";
    cin>>apellido1;
    cout<<"Introduce el segundo apellido: ";
    cin>>apellido2;
    cout<<"Inctroduce el dni: ";
    cin>>dni;
    cout<<"Introduce la fecha de nacmiento: ";
    cin>>fecha_nacimiento;
    cout<<"Introduce el numero de telefono:";
    cin>>telefono;
    cout<<"Introduce si tienes alguna discapacidad, si no, escribe 'Ninguna': ";
    cin>>discapacidad;
            
    Visitante aux(nombre,apellido1,apellido2,dni,fecha_nacimiento,telefono,discapacidad);

    for(list<Visitante>::iterator i=visitantes_.begin();i!=visitantes_.end();i++){
        if(i->getDniV()==aux.getDniV())
        {
            cout<<"Error, mismo DNI"<<endl;
            exit (EXIT_FAILURE);
        }
    }
    visitantes_.push_back(aux);
}

//FUNCIONES DE APOYO

void Administrativo::escribeReservas(){
    string nomfichero="reservas.txt";
    fstream f;
    f.open(nomfichero,std::ios::out);
    for(list<Reserva>::iterator i=reservas_.begin();i!=reservas_.end();i++){
        f<<i->getFechaReserva()<<","+
        i->getDniReserva()<<","+
        i->getTipoRuta()<<"\n";
    }
    f.close();
}

void Administrativo::visualizarReservas(){
    reservas_.clear();
    fstream f;
    f.open("reservas.txt",std::fstream::in);
    if(f.is_open()){
        char fecha[225],dni[225],tipo[225];

        while(f.getline(fecha,225,',')){
            f.getline(dni,225,',');
            f.getline(tipo,225,'\n');
            
            Reserva aux(fecha,dni,tipo);
            reservas_.push_back(aux);
            cout<<fecha<<" "<<dni<<" "<<tipo<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}


void Administrativo::escribeVisitantes(){
    string nomfichero="visitantes.txt";
    fstream f;
    f.open(nomfichero,std::ios::out);
    for(list<Visitante>::iterator i=visitantes_.begin();i!=visitantes_.end();i++){
        f<<i->getNombreV()<<","+
        i->getApellido1V()<<","+
        i->getApellido2V()<<","<<
        i->getDniV()<<","<<
        i->getFecha_nacimiento()<<","<<
        i->getTelefonoV()<<","<<
        i->getDiscapacidad()<<"\n";
    }
    f.close();
}


void Administrativo::visualizarVisitantes(){
    visitantes_.clear();
    fstream f;
    f.open("visitantes.txt",std::fstream::in);
    if(f.is_open()){
        char nombre[225],apellido1[225],apellido2[225],dni[225],fecha[225],telefono[225],disca[255];

        while(f.getline(nombre,225,',')){
            f.getline(apellido1,225,',');
            f.getline(apellido2,225,',');
            f.getline(dni,225,',');
            f.getline(fecha,225,',');
            f.getline(telefono,225,',');
            f.getline(disca,225,'\n');

            Visitante aux(nombre,apellido1,apellido2,dni,fecha,atoi(telefono),disca);
            visitantes_.push_back(aux);
            cout<<nombre<<" "<<apellido1<<" "<<apellido2<<" "<<dni<<" "<<fecha<<" "<<telefono<<" "<<disca<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
}


/////////////////////////////////////////////////////////////////////////////

void Administrativo::modificaInformacion()
{
    //NECESITO LA CLASE PARQUE;
}

void Administrativo::editarOanadirInformacion()
{
    //NECESITO LA CLASE PARQUE;
}
/*

int main()
{
    Administrativo i("Alvaro","Roldan","Lucena","123456789X","Codoba","i92rolua@uco.es",123456789,"AlvaroRoldanLucena","123456789X");

   if(i.identificacion()==0) return 0;
    
    cout<<"Nombre: "<<i.getNombre()<<endl;
    cout<<"Apellidos: "<<i.getApellido1()<<" "<<i.getApellido2()<<endl;
    cout<<"DNI: "<<i.getDni()<<endl;
    cout<<"Direccion: "<<i.getDireccion()<<endl;
    cout<<"Email: "<<i.getEmail()<<endl;
    cout<<"Telfono: "<<i.getTelefono()<<endl;
    cout<<"Usuario: "<<i.getUsuario()<<endl;
    cout<<"Contrasena: "<<i.getContrasena()<<endl;
    
    Reserva j("12/12/2020","123456789X","Bicicleta");
    Reserva m("15/08/2020","987654321A","A pie");
    i.creaReserva(j);
    i.creaReserva(m);
    i.escribeReservas();
    i.visualizarReservas();

    cout<<"\n"<<"Primer visitante"<<endl;
    i.setVisitante();
    cout<<"\n"<<"Segundo visitante"<<endl;
    i.setVisitante();
    i.escribeVisitantes();
    i.visualizarVisitantes();

    return 0;    
}
*/