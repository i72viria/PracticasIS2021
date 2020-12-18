// ruta_unittest.cc: Álvaro Roldán Lucena
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
#include "ruta.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Ruta, ConstructorParametrosDefecto) {
  Ruta j;
  
  EXPECT_EQ(0, j.getCodigo());
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getEstado());
  EXPECT_EQ("", j.getDificultad());
  EXPECT_EQ(0, j.getLongitud());
  EXPECT_EQ(0, j.getDuracion());
}

TEST(Ruta, ConstructorParametros) {
  Ruta j(2001,"Valle Encantado","Accesible","Media",5.7,3);
  
  EXPECT_EQ(2001, j.getCodigo());
  EXPECT_EQ("Valle Encantado", j.getNombre());
  EXPECT_EQ("Accesible", j.getEstado());
  EXPECT_EQ("Media", j.getDificultad());
  EXPECT_FLOAT_EQ(5.7, j.getLongitud());
  EXPECT_FLOAT_EQ(3, j.getDuracion());
}

TEST(Ruta, setCodigoygetCodigo) {
  Ruta j(33);
  EXPECT_EQ(33, j.getCodigo());
  j.setCodigo(55);
  EXPECT_EQ(55, j.getCodigo());
}

TEST(Ruta, setEstadoygetEstado) {
  Ruta j(33,"Valle Encantado","Abierto");
  EXPECT_EQ("Abierto", j.getEstado());
  j.setEstado("Cerrado");
  EXPECT_EQ("Cerrado", j.getEstado());
}

TEST(Ruta, setDificultadygetDificultad) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil");
  EXPECT_EQ("Dificil", j.getDificultad());
  j.setDificultad("Facil");
  EXPECT_EQ("Facil", j.getDificultad());
}

TEST(Ruta, setLongitudygetLongitud) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil",1.7);
  EXPECT_FLOAT_EQ(1.7, j.getLongitud());
  j.setLongitud(19.6);
  EXPECT_FLOAT_EQ(19.6, j.getLongitud());
}

TEST(Ruta, setDuracionygetDuracion) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil",1.7,2.30);
  EXPECT_FLOAT_EQ(2.30, j.getDuracion());
  j.setDuracion(1.45);
  EXPECT_FLOAT_EQ(1.45, j.getDuracion());
}

TEST(Ruta, getRutas) {
  Ruta j;
  j.getRutas();
  
}

