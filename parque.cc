#include "parque.h"

Parque::Parque(string nombre,string localizacion,float superficie,string fecha_reconocimiento,int telefono_parque,string horario){
        setNombre(nombre);
        setLocalizacion(localizacion);
        setSuperficie(superficie);
        setFecha_reconocimiento(fecha_reconocimiento);
        setTelefono_parque(telefono_parque);
        setHorario(horario);
}

void Parque::visualizarRutas(){
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

            cout<<nombre<<" "<<localizacion<<" "<<fecha_reconocimiento<<" "<<telefono_parque<<" "<<horario<<endl;
        }
    }
        else{
            cout<<"Error. No se pudo abrir el fichero";
        }
    f.close();
  }

void Parque::visualizarVisitantesReserva(){
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

          cout<<nombre<<" "<<apellido1<<" "<<apellido2<<" "<<dni<<" "<<fecha<<" "<<telefono<<" "<<disca<<endl;
      }
  }
      else{
          cout<<"Error. No se pudo abrir el fichero";
      }
  f.close();
}

void Parque::mostrarEstadoRuta(){
  fstream f;
  f.open("rutas.txt",std::fstream::in);
  if(f.is_open()){
      char codigo[225],nombre[225],estado[225],dificultad[225],longitud[225],duracion[225];

      while(f.getline(codigo,225,',')){
          f.getline(nombre,225,',');
          f.getline(estado,225,',');
          f.getline(dificultad,225,',');
          f.getline(longitud,225,',');
          f.getline(duracion,225,',');

          cout<<codigo<<" "<<nombre<<" "<<estado<<" "<<dificultad<<" "<<longitud<<" "<<duracion<<endl;
      }
  }
      else{
          cout<<"Error. No se pudo abrir el fichero";
      }
  f.close();
}

void Parque::buscarInformacion(Parque r){
  cout<<"\nQue elemento desea buscar del parque"<<r.getNombre()<<" ?"<<endl;
  int menu=0;

  string nombre=r.getNombre();
  string fecha=r.getFecha_reconocimiento();
  string localizacion=r.getLocalizacion();
  string horario=r.getHorario(); 
  float superficie=r.getSuperficie();
  int telefono_parque=r.getTelefono_parque();

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
              cout<<"El nombre del parque es:" <<nombre<<","<<endl;
          }
          break;

          case 2:
          {
            cout<<"La localización del parque es:" <<localizacion<<","<<endl;
          }
          break;

          case 3:
          {
              cout<<"La superficie del parque es:" <<superficie<<","<<endl;
          }
          break;

          case 4:
          {
              cout<<"La fecha de reconocimiento del parque es:" <<fecha<<","<<endl;
          }
          break;

          case 5:
          {
              cout<<"El telefono del parque es:" <<telefono_parque<<","<<endl;
          }
          break;

          case 6:
          {
              cout<<"El horario del parque es:" <<horario<<","<<endl;
          }
          break;

          default:
          {
              cout<<"Numero incorrecto"<<endl;
          }
          break;
      }
  }
}
