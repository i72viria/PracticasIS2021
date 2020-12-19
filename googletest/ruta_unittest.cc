// ruta_unittest.cc: Álvaro Roldán Lucena

#include <fstream>
#include <list>
#include "ruta.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Ruta, ConstructorParametrosDefecto) {
  Ruta j;
  
  ASSERT_EQ(0, j.getCodigo());
  ASSERT_EQ("", j.getNombre());
  ASSERT_EQ("", j.getEstado());
  ASSERT_EQ("", j.getDificultad());
  ASSERT_EQ(0, j.getLongitud());
  ASSERT_EQ(0, j.getDuracion());
}

TEST(Ruta, ConstructorParametros) {
  Ruta j(2001,"Valle Encantado","Accesible","Media",5.7,3);
  
  ASSERT_EQ(2001, j.getCodigo());
  ASSERT_EQ("Valle Encantado", j.getNombre());
  ASSERT_EQ("Accesible", j.getEstado());
  ASSERT_EQ("Media", j.getDificultad());
  ASSERT_FLOAT_EQ(5.7, j.getLongitud());
  ASSERT_FLOAT_EQ(3, j.getDuracion());
}

TEST(Ruta, setCodigoygetCodigo) {
  Ruta j(33);
  ASSERT_EQ(33, j.getCodigo());
  j.setCodigo(55);
  ASSERT_EQ(55, j.getCodigo());
}

TEST(Ruta, setEstadoygetEstado) {
  Ruta j(33,"Valle Encantado","Abierto");
  ASSERT_EQ("Abierto", j.getEstado());
  j.setEstado("Cerrado");
  ASSERT_EQ("Cerrado", j.getEstado());
}

TEST(Ruta, setDificultadygetDificultad) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil");
  ASSERT_EQ("Dificil", j.getDificultad());
  j.setDificultad("Facil");
  ASSERT_EQ("Facil", j.getDificultad());
}

TEST(Ruta, setLongitudygetLongitud) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil",1.7);
  ASSERT_FLOAT_EQ(1.7, j.getLongitud());
  j.setLongitud(19.6);
  ASSERT_FLOAT_EQ(19.6, j.getLongitud());
}

TEST(Ruta, setDuracionygetDuracion) {
  Ruta j(33,"Valle Encantado","Abierto","Dificil",1.7,2.30);
  ASSERT_FLOAT_EQ(2.30, j.getDuracion());
  j.setDuracion(1.45);
  ASSERT_FLOAT_EQ(1.45, j.getDuracion());
}

TEST(Ruta, getRutas) {
  Ruta j;
  j.getRutas();
  
}

