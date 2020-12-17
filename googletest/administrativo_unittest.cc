// jugador_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <fstream>
#include <list>
#include "administrativo.h"
#include "reserva.h"
#include "Visitante.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Administrativo, ConstructorParametrosDefecto) {
  Administrativo j;
  
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getApellido1());
  EXPECT_EQ("", j.getApellido2());
  EXPECT_EQ("", j.getDni());
  EXPECT_EQ("", j.getDireccion());
  EXPECT_EQ(0, j.getTelefono());
  EXPECT_EQ("", j.getUsuario());
  EXPECT_EQ("", j.getContrasena());
}

TEST(Administrativo, ConstructorParametros) {
  Administrativo j("Alvaro","Roldan","Lucena","123456789X","Cordoba","i92rolua@uco.es",123456789,"AlvaroRoldanLucena","123456789X");
  
  EXPECT_EQ("Alvaro", j.getNombre());
  EXPECT_EQ("Roldan", j.getApellido1());
  EXPECT_EQ("Lucena", j.getApellido2());
  EXPECT_EQ("123456789X", j.getDni());
  EXPECT_EQ("Cordoba", j.getDireccion());
  EXPECT_EQ(123456789, j.getTelefono());
  EXPECT_EQ("AlvaroRoldanLucena", j.getUsuario());
  EXPECT_EQ("123456789X", j.getContrasena());
}

TEST(Administrativo, setNombreygetNombre) {
  Administrativo j("Pepe");

  EXPECT_EQ("Pepe", j.getNombre());
  j.setNombre("Paco");
  EXPECT_EQ("Paco", j.getNombre());
}

TEST(Administrativo, setApellido1ygetApellido1) {
  Administrativo j("Pepe","Rodriguez");

  EXPECT_EQ("Rodriguez", j.getApellido1());
  j.setApellido1("Lozano");
  EXPECT_EQ("Lozano", j.getApellido1());
}

TEST(Administrativo, setApellido2ygetApellido2) {
  Administrativo j("Pepe","Rodriguez","Roldan");

  EXPECT_EQ("Roldan", j.getApellido2());
  j.setApellido2("Laguna");
  EXPECT_EQ("Laguna", j.getApellido2());
}

TEST(Administrativo, setDniygetDni) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X");

  EXPECT_EQ("123X", j.getDni());
  j.setDni("876A");
  EXPECT_EQ("876A", j.getDni());
}

TEST(Administrativo, setDireccionygetDireccion) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid");

  EXPECT_EQ("Madrid", j.getDireccion());
  j.setDireccion("Bilbao");
  EXPECT_EQ("Bilbao", j.getDireccion());
}

TEST(Administrativo, setEmailygetEmail) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es");

  EXPECT_EQ("pepe@uco.es", j.getEmail());
  j.setEmail("rodri@uco.es");
  EXPECT_EQ("rodri@uco.es", j.getEmail());
}


TEST(Administrativo, setTelefonoygetTelefono) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123);

  EXPECT_EQ(123, j.getTelefono());
  j.setTelefono(999);
  EXPECT_EQ(999, j.getTelefono());
}

TEST(Administrativo, getUsuario) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123,"PepeRodriguezRoldan");

  EXPECT_EQ("PepeRodriguezRoldan", j.getUsuario());
  j.setNombre("Paco");
  j.setApellido1("Lozano");
  j.setApellido2("Laguna");
  EXPECT_EQ("PacoLozanoLaguna", j.getUsuario());
}
TEST(Administrativo, getContrasena) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123,"PepeRodriguezRoldan","124X");

  EXPECT_EQ("123X", j.getContrasena());
  j.setDni("968A");
  EXPECT_EQ("968A", j.getContrasena());
}

/*
TEST(Jugador, setApuestasygetApuestas) {
  Jugador j("33XX", "1");
  string nomfich=j.getDNI()+".txt";
  ofstream salida(nomfich.c_str());
  salida << 1 << "," << "10" << "," << 15<< "\n";
  salida << 2 << "," << "rojo" << "," << 25<< "\n";
  salida << 3 << "," << "par" << "," << 35<< "\n";
  salida << 4 << "," << "bajo" << "," << 45<< "\n";
  salida.close();
  list<Apuesta> l;
  j.setApuestas();
  l= j.getApuestas();
  EXPECT_EQ(4, l.size());
  list<Apuesta>::iterator i;
  i=l.begin();
  EXPECT_EQ(1, (*i).tipo);
  EXPECT_EQ("10", (*i).valor);
  EXPECT_EQ(15, (*i).cantidad);
  i++;
  EXPECT_EQ(2, (*i).tipo);
  EXPECT_EQ("rojo", (*i).valor);
  EXPECT_EQ(25, (*i).cantidad);
  i++;
  EXPECT_EQ(3, (*i).tipo);
  EXPECT_EQ("par", (*i).valor);
  EXPECT_EQ(35, (*i).cantidad);
  i++;
  EXPECT_EQ(4, (*i).tipo);
  EXPECT_EQ("bajo", (*i).valor);
  EXPECT_EQ(45, (*i).cantidad);
}
*/
