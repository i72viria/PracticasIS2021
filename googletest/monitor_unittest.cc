// MONITOR_UNITTEST_CC

#include "monitor.h"
#include "ruta.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Monitor, Constructor) {
  Monitor m;
  
  EXPECT_EQ("", m.getNombreM());
  EXPECT_EQ("", m.getApellido1M());
  EXPECT_EQ("", m.getApellido2M());
  EXPECT_EQ("", m.getDniM());
  EXPECT_EQ("", m.getDireccionM());
  EXPECT_EQ("", m.getEmailM());
  EXPECT_EQ(0, m.getTelefonoM());
  EXPECT_EQ("", m.getUsuario());
  EXPECT_EQ("", m.getContrasena());
}

//ESTE TEST FUNCIONA PERO DEBEMOS INTRODUCIR PRIMERO MAL LA IDENTIFICACIÓN Y 
// POSTERIORMENTE CORRECTA E IDENTICAMENTE EL USUARIO Y CONTRASEÑA


/*
// Tests funcion Identificacion
TEST(Monitor, Identificacion) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
    cout<<endl;
    cout<<"Identificase con datos erroneos"<<endl<<endl;
   
    EXPECT_FALSE(m.identificacion());
    cout<<endl;
    cout<<"Identificase correctamente"<<endl;
    cout<<"Usuario:  VictoriaPradasLaguna\n"<<endl;
    cout<<"Contrasena:  123456789X"<<endl;
    EXPECT_TRUE(m.identificacion());
    
}
*/

// Tests modificadores y constructores
TEST(Monitor, ModificadoresObservadores) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  m.setNombreM("Victoria");
  EXPECT_EQ("Victoria",m.getNombreM());

  m.setApellido1M("Pradas");
  EXPECT_EQ("Pradas",m.getApellido1M());

  m.setApellido2M("Laguna");
  EXPECT_EQ("Laguna",m.getApellido2M());

  m.setDniM("123456789X");
  EXPECT_EQ("123456789X",m.getDniM());

  m.setEmailM("i92prlav");
  EXPECT_EQ("i92prlav", m.getEmailM());

  m.setDireccionM("San Juan");
  EXPECT_EQ("San Juan", m.getDireccionM());

  m.setTelefonoM(666885577);
  EXPECT_EQ(666885577, m.getTelefonoM());

  m.setUsuario();
  EXPECT_EQ("VictoriaPradasLaguna", m.getUsuario()); 

  m.setContrasena();
  EXPECT_EQ("123456789X", m.getContrasena());
}

//Test crea Ruta 
TEST(Monitor, crearRuta) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  Ruta r3(3,"Bosque","Cerrado","Avanzado",10.2,13.8);
  
  EXPECT_TRUE(m.crearRuta(r1));
  EXPECT_TRUE(m.crearRuta(r2));
  EXPECT_FALSE(m.getRutas().empty());
  EXPECT_EQ(2, m.getRutas().size());
  EXPECT_EQ(1, m.getRutas().begin()->getCodigo());
  EXPECT_EQ("Camino", m.getRutas().begin()->getNombre());
  EXPECT_EQ(2, (--m.getRutas().end())->getCodigo());
  EXPECT_EQ("Rio", (--m.getRutas().end())->getNombre());
  EXPECT_FALSE(m.crearRuta(r1));
  EXPECT_FALSE(m.crearRuta(r2));
}


//Test elimina una Ruta
TEST(Monitor, deleteRuta) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  
  m.crearRuta(r1); 
  m.crearRuta(r2);

  EXPECT_EQ(1,m.deleteRuta(r1));
  EXPECT_EQ(1, m.getRutas().size());
  EXPECT_EQ(2, m.getRutas().begin()->getCodigo());
  EXPECT_EQ("Rio", m.getRutas().begin()->getNombre());
  EXPECT_EQ(1, m.getRutas().size());
  r1.setCodigo(3);
  EXPECT_EQ(-2,m.deleteRuta(r1));
  EXPECT_EQ(1,m.deleteRuta(r2));
  
  EXPECT_EQ(-1,m.deleteRuta(r1));
  EXPECT_EQ(0, m.getRutas().size());
}


//Test elimina una Ruta a partir del codigo
TEST(Monitor, deleteRutaCodigo) {
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "pepemola@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);
  
  m.crearRuta(r1); 
  m.crearRuta(r2);

  EXPECT_EQ(1,m.deleteRuta(1));
  EXPECT_EQ(1, m.getRutas().size());
  EXPECT_EQ(2, m.getRutas().begin()->getCodigo());
  EXPECT_EQ("Rio", m.getRutas().begin()->getNombre());
  EXPECT_EQ(1, m.getRutas().size());
  EXPECT_EQ(-2,m.deleteRuta(3));
  EXPECT_EQ(1,m.deleteRuta(2));
  EXPECT_EQ(-1,m.deleteRuta(2));
  EXPECT_EQ(0, m.getRutas().size());
}


//Test que comprueba lo escrito y visualizado en el fichero
TEST(Monitor, escribeLeeRutas) {
 
  Monitor m("Victoria","Pradas","Laguna","123456789X", "San blas", "yo@gmail.com",696969696);
  Ruta r1(1,"Camino","Accesible","Básico",1.2,1.4);
  Ruta r2(2,"Rio","Mantenimiento","Medio",6.2,8.6);

  m.crearRuta(r1); 
  m.crearRuta(r2);

  m.escribeRutas();
  
  Monitor l("Maria","Borrador","Lapiz","987654321Y", "San juan", "ella@gmail.com",666998855);
  
  l.visualizarRutas();
  EXPECT_FALSE(l.getRutas().empty());
  EXPECT_EQ(2, l.getRutas().size());
  EXPECT_EQ(1, l.getRutas().begin()->getCodigo());
  EXPECT_EQ(2, (--l.getRutas().end())->getCodigo());
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
  m.visualizarRutas();
  EXPECT_EQ("Accesible", m.getRutas().begin()->getEstado());
  cout<<endl<<"Cambiar estado a <Mantenimiento>"<<endl;
  m.cambiarEstadoRuta(r1);
  m.escribeRutas();
  m.visualizarRutas();
  EXPECT_EQ("Mantenimiento", (--m.getRutas().end())->getEstado());

}
