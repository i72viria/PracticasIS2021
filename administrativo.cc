#include "administrativo.h"
#include "reserva.h"
#include <iostream>
#include "Visitante.h"
#include "parque.h"

using namespace std;

Administrativo::Administrativo(string nombre, string apellido1, string apellido2, string dni, string direccion,string email, int telefono)
{
    setNombre(nombre);
    setApellido1(apellido1);
    setApellido2(apellido2);
    setDni(dni);
    setDireccion(direccion);
    setEmail(email);
    setTelefono(telefono);
    setUsuario();
    setContrasena();
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

void Administrativo::modificaInformacion(Parque r)
{
    cout<<"\nQue elemento desea modificar del parque"<<r.getNombre()<<" ?"<<endl;
    int menu=0;
    
    string nombre,fecha, localizacion, horario;
    float superficie;
    int telefono;
    
    while(menu!=7)
    {
        cout<<"1.Nombre"<<endl;
        cout<<"2.Localizacion"<<endl;
        cout<<"3.Superficie"<<endl;
        cout<<"4.Fecha de reconcomimiento de Parque Natural"<<endl;
        cout<<"5.Telefono del Parque"<<endl;
        cout<<"6.Horario"<<endl;
        cout<<"7.EXIT"<<endl;
        cin>>menu;

        switch (menu)
        {
            case 1:
            {
                string NewName;
                cout<<"Introduce el nuevo nombre del parque: "<<endl;
                cin>>NewName;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        localizacion=r.getLocalizacion();
                        superficie=r.getSuperficie();
                        fecha=r.getFecha_reconocimiento();
                        telefono=r.getTelefono_parque();
                        horario=r.getHorario();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<NewName<<", "<<localizacion<<", "<<superficie<<", "<<fecha<<", "<<telefono<<", "<<horario<<"\n";
                    }
                }
                string nombre=r.getNombre();
                deleteDatos(nombre);
                Parque aux(NewName, localizacion, superficie, fecha, telefono, horario);
                datos_.push_back(aux);
            }
            break;
    
            case 2:
            {
                string NewLocation;
                cout<<"Introduce la nueva localizacion del parque: "<<endl;
                cin>>NewLocation;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        nombre=r.getNombre();
                        superficie=r.getSuperficie();
                        fecha=r.getFecha_reconocimiento();
                        telefono=r.getTelefono_parque();
                        horario=r.getHorario();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<nombre<<", "<<NewLocation<<", "<<superficie<<", "<<fecha<<", "<<telefono<<", "<<horario<<"\n";
                    }
                }   
                deleteDatos(nombre);
                Parque aux1(nombre, NewLocation,superficie, fecha, telefono, horario);
                datos_.push_back(aux1);
            }
            break;

            case 3:
            {
                float NewSurface;
                cout<<"Introduce la nueva superficie del parque: "<<endl;
                cin>>NewSurface;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        nombre=r.getNombre();
                        localizacion=r.getLocalizacion();
                        fecha=r.getFecha_reconocimiento();
                        telefono=r.getTelefono_parque();
                        horario=r.getHorario();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<nombre<<", "<<localizacion<<", "<<NewSurface<<", "<<fecha<<", "<<telefono<<", "<<horario<<"\n";
                    }
                }   
                deleteDatos(nombre);
                Parque aux2(nombre, localizacion, NewSurface, fecha, telefono, horario);
                datos_.push_back(aux2);
            }
            break;

            case 4:
            {
                string NewDate;
                cout<<"Introduce la nueva fecha del reconocimiento del parque: "<<endl;
                cin>>NewDate;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        nombre=r.getNombre();
                        localizacion=r.getLocalizacion();
                        superficie=r.getSuperficie();
                        telefono=r.getTelefono_parque();
                        horario=r.getHorario();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<nombre<<", "<<localizacion<<", "<<superficie<<", "<<NewDate<<", "<<telefono<<", "<<horario<<"\n";
                    }
                }   
                deleteDatos(nombre);
                Parque aux3(nombre, localizacion, superficie, NewDate, telefono, horario);
                datos_.push_back(aux3);
            }
            break;

            case 5:
            {
                int NewPhoneNumber;
                cout<<"Introduce el nuevo numero de telefono del parque: "<<endl;
                cin>>NewPhoneNumber;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        nombre=r.getNombre();
                        localizacion=r.getLocalizacion();
                        superficie=r.getSuperficie();
                        fecha=r.getFecha_reconocimiento();
                        horario=r.getHorario();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<nombre<<", "<<localizacion<<", "<<superficie<<", "<<fecha<<", "<<NewPhoneNumber<<", "<<horario<<"\n";
                    }
                }   
                deleteDatos(nombre);
                Parque aux4(nombre, localizacion, superficie, fecha, NewPhoneNumber, horario);
                datos_.push_back(aux4);
            }
            break;

            case 6:
            {
                string NewSchedule;
                cout<<"Introduce el nuevo horario del parque: "<<endl;
                cin>>NewSchedule;
                cout<<endl;

                for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++)
                {
                    if(i->getNombre()== r.getNombre())
                    {
                        nombre=r.getNombre();
                        localizacion=r.getLocalizacion();
                        superficie=r.getSuperficie();
                        fecha=r.getFecha_reconocimiento();
                        telefono=r.getTelefono_parque();
                        cout<<"Actualizando..."<<endl;
                        cout<<"Parque actualizado "<<nombre<<", "<<localizacion<<", "<<superficie<<", "<<fecha<<", "<<telefono<<", "<<NewSchedule<<"\n";
                    }
                }   
                deleteDatos(nombre);
                Parque aux5(nombre, localizacion, superficie, fecha, telefono, NewSchedule);
                datos_.push_back(aux5);
            }
            break;

            default:
            {
                cout<<"Numero incorretco"<<endl;
            }
            break;
        }
    }
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


bool Administrativo::crearParque(Parque r){
    for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++){
        if(i->getNombre()==r.getNombre()){
            cout<<"ERROR, Parque existente."<<endl;
            return false;
        }
    }
    
    datos_.push_back(r);
    cout<<"Parque creado con exito"<<endl;
    return true;   
}

int Administrativo::deleteDatos(string nombre){
    if(datos_.empty()){
        cout<<"La lista está vacía"<<endl;
        return -1;
    }
    for(list<Parque>::iterator i=datos_.begin();i!=datos_.end();i++){
        if(i->getNombre()== nombre){
            datos_.erase(i);
            cout<<"Parque borrado con éxito"<<endl;
            return 1;
        }
    }
    cout<<"El nombre del parque dado no existe en la lista."<<endl;
    return -2;
}

