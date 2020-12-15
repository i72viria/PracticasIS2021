#include "administrativo.h"
#include <iostream>

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

void Administrativo::creaReserva()
{
    int i;
}

void Administrativo::setVisitante()
{
    int i;
}

void Administrativo::modificaInformacion()
{
    int t;
}

void Administrativo::editarOanadirInformacion()
{
    int t;
}


int main()
{
    Administrativo i("Alvaro","Roldan","Lucena","31023651D","calle murcia","i92rolua@uco.es",603408956,"AlvaroRoldanLucena","31023651D");

    string nombre,apellidos,dni,direccion,email,usuario,contrasena;
    int telefono;
    nombre=i.getNombre();
    apellidos=i.getApellido1()+" "+i.getApellido2();
    dni=i.getDni();
    direccion=i.getDireccion();
    email=i.getEmail();
    telefono=i.getTelefono();
    usuario=i.getUsuario();
    contrasena=i.getContrasena();

    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellidos: "<<apellidos<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Direccion: "<<direccion<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Telfono: "<<telefono<<endl;
    cout<<"Usuario: "<<usuario<<endl;
    cout<<"Contrasena: "<<contrasena<<endl;

    
    i.identificacion();

    return 0;    
}