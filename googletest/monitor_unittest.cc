// MONITOR_UNITTEST_CC

#include "monitor.h"
#include "ruta.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Monitor, Constructor) {
  Monitor m;
  
  ASSERT_EQ("", m.getNombreM());
  ASSERT_EQ("", m.getApellido1M());
  ASSERT_EQ("", m.getApellido2M());
  ASSERT_EQ("", m.getDniM());
  ASSERT_EQ("", m.getDireccionM());
  ASSERT_EQ("", m.getEmailM());
  ASSERT_EQ(0, m.getTelefonoM());
  ASSERT_EQ("", m.getUsuario());
  ASSERT_EQ("", m.getContrasena());
}


// Tests modificadores y constructores
TEST(Monitor, ModificadoresObservadores) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  m.setNombreM("Victoria");
  ASSERT_EQ("Victoria",m.getNombreM());

  m.setApellido1M("Pradas");
  ASSERT_EQ("Pradas",m.getApellido1M());

  m.setApellido2M("Laguna");
  ASSERT_EQ("Laguna",m.getApellido2M());

  m.setDniM("123456789X");
  ASSERT_EQ("123456789X",m.getDniM());

  m.setEmailM("i92prlav");
  ASSERT_EQ("i92prlav", m.getEmailM());

  m.setDireccionM("San Juan");
  ASSERT_EQ("San Juan", m.getDireccionM());

  m.setTelefonoM(666885577);
  ASSERT_EQ(666885577, m.getTelefonoM());

  m.setUsuario();
  ASSERT_EQ("VictoriaPradasLaguna", m.getUsuario()); 

  m.setContrasena();
  ASSERT_EQ("123456789X", m.getContrasena());
}

//Test crea Ruta 
TEST(Monitor, crearRuta) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  Ruta r3(3,"Bosque","Cerrado","Avanzado",10.2,13.8);
  
  ASSERT_TRUE(m.crearRuta(r1));
  ASSERT_TRUE(m.crearRuta(r2));
  ASSERT_FALSE(m.getRutas().empty());
  ASSERT_EQ(2, m.getRutas().size());
  ASSERT_EQ(1, m.getRutas().begin()->getCodigo());
  ASSERT_EQ("Camino", m.getRutas().begin()->getNombre());
  ASSERT_EQ(2, (--m.getRutas().end())->getCodigo());
  ASSERT_EQ("Rio", (--m.getRutas().end())->getNombre());
  ASSERT_FALSE(m.crearRuta(r1));
  ASSERT_FALSE(m.crearRuta(r2));
}


//Test elimina una Ruta
TEST(Monitor, deleteRuta) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  
  m.crearRuta(r1); 
  m.crearRuta(r2);

  ASSERT_EQ(1,m.deleteRuta(r1));
  ASSERT_EQ(1, m.getRutas().size());
  ASSERT_EQ(2, m.getRutas().begin()->getCodigo());
  ASSERT_EQ("Rio", m.getRutas().begin()->getNombre());
  ASSERT_EQ(1, m.getRutas().size());
  r1.setCodigo(3);
  ASSERT_EQ(-2,m.deleteRuta(r1));
  ASSERT_EQ(1,m.deleteRuta(r2));
  
  ASSERT_EQ(-1,m.deleteRuta(r1));
  ASSERT_EQ(0, m.getRutas().size());
}


//Test elimina una Ruta a partir del codigo
TEST(Monitor, deleteRutaCodigo) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  
  m.crearRuta(r1); 
  m.crearRuta(r2);

  ASSERT_EQ(1,m.deleteRuta(1));
  ASSERT_EQ(1, m.getRutas().size());
  ASSERT_EQ(2, m.getRutas().begin()->getCodigo());
  ASSERT_EQ("Rio", m.getRutas().begin()->getNombre());
  ASSERT_EQ(1, m.getRutas().size());
  ASSERT_EQ(-2,m.deleteRuta(3));
  ASSERT_EQ(1,m.deleteRuta(2));
  ASSERT_EQ(-1,m.deleteRuta(2));
  ASSERT_EQ(0, m.getRutas().size());
}


//Test que comprueba lo escrito y visualizado en el fichero
TEST(Monitor, escribeLeeRutas) {
 
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "yo@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Avanzado",13.5,18.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);

  m.crearRuta(r1); 
  m.crearRuta(r2);

  m.escribeRutas();
  
  Monitor l("Maria","Borrador","Lapiz","987654321Y", "San juan", "ella@gmail.com",666998855);
  
  l.visualizarRutas();
  ASSERT_FALSE(l.getRutas().empty());
  ASSERT_EQ(2, l.getRutas().size());
  ASSERT_EQ(1, l.getRutas().begin()->getCodigo());
  ASSERT_EQ(2, (--l.getRutas().end())->getCodigo());
}

TEST(Monitor, elegirRuta){
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "yo@gmail.com",696969696);
  Ruta r1(15,"Playa","Accesible","Básico",3.2,4.2);
  Ruta r2(20,"Bosque","Cerrado","Medio",8.2,10.1);

  m.crearRuta(r1);
  m.crearRuta(r2);

  ASSERT_EQ(2, m.getRutas().size());

  ASSERT_EQ(15,m.elegirRuta(r1));
  ASSERT_EQ(20,m.elegirRuta(r2));

}

//Test cambiar estado de la ruta
//DEBE INTRODUCIR CORRECTAMENTE EL ESTADO 
TEST(Monitor, cambiarEstado){

  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "yo@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Accesible","Medio",6.2,8.6);

  m.crearRuta(r1); 
  m.crearRuta(r2);

  m.escribeRutas();
  //m.visualizarRutas();
  ASSERT_EQ("Accesible", m.getRutas().begin()->getEstado());
  cout<<endl<<"Cambiar estado a <Mantenimiento>"<<endl;
  m.cambiarEstadoRuta(r1);
  m.escribeRutas();
  m.visualizarRutas();
  ASSERT_EQ("Mantenimiento", (--m.getRutas().end())->getEstado());

}


//ESTE TEST FUNCIONA PERO DEBEMOS INTRODUCIR PRIMERO MAL LA IDENTIFICACIÓN Y 
// POSTERIORMENTE CORRECTA E IDENTICAMENTE EL USUARIO Y CONTRASEÑA


/*
// Tests funcion Identificacion
TEST(Monitor, Identificacion) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
    cout<<endl;
    cout<<"Identificase con datos erroneos"<<endl<<endl;
   
    ASSERT_FALSE(m.identificacion());
    cout<<endl;
    cout<<"Identificase correctamente"<<endl;
    cout<<"Usuario:  VictoriaPradasLaguna\n"<<endl;
    cout<<"Contrasena:  123456789X"<<endl;
    ASSERT_TRUE(m.identificacion());
    
}
*/