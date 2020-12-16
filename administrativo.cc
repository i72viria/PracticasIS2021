#include "administrativo.h"
#include "reserva.h"
#include <iostream>
#include "Visitante.h"

using namespace std;

Administrativo::Administrativo(string nombre, string apellido1, string apellido2, string dni, string direccion,string email, int telefono, string usuario, string contrasena)
{
    setNombre(nombre);
    setApellido1(apellido1);
    setApeliido2(apellido2);
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

bool Administrativo::creaReserva(Reserva r)
{
    for(list<Reserva>::iterator i=reservas_.begin();i!=reservas_.end();i++)
    {
        if(i->getDniReserva()==r.getDniReserva())
        {
            cout<<"Reserva fallida"<<endl;
            return false;
        }
    }
    cout<<"Reserva creada con exito"<<endl;
    reservas_.push_back(r);
    return true;   
}

bool Administrativo::setVisitante(Visitante v)
{
    string nombre,apellido1,apellido2,dni,fecha_nacimiento,discapacidad;
    int telefono;

    for(list<Visitante>::iterator i=visitantes_.begin();i!=visitantes_.end();i++)
    {
        if(i->getDniV()==v.getDniV()){
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
            cout<<"IUntroduce el numero de telefono:";
            cin>>telefono;
            cout<<"Introduce si tienes alguna discapacidad, si no, escribe 'Ninnguna': ";
            cin>>discapacidad;
            
            v.setNombreV(nombre);
            v.setApellido1V(apellido1);
            v.setApellido2V(apellido2);
            v.setDniV(dni);
            v.setFecha_nacimiento(fecha_nacimiento);
            v.setTelefonoV(telefono);
            v.setDiscapacidad(discapacidad);
        }
    } 
    visitantes_.push_back(v);
    return true; 

}


void Administrativo::modificaInformacion()
{
    //NECESITO LA CLASE PARQUE;
}

void Administrativo::editarOanadirInformacion()
{
    //NECESITO LA CLASE PARQUE;
}


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
    
    Reserva j("123456789X","12/12/2020","Bicileta");
    i.creaReserva(j);
   
    return 0;    
}