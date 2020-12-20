//PARQUE UNITTEST
#include "visitante.h"
#include "gtest/gtest.h"

//Test the constructor
TEST(Visitante, Constructor) {
  Visitantes p;

  ASSERT_EQ("", m.getNombreV());
  ASSERT_EQ("", m.getApellido1V());
  ASSERT_EQ("", m.getApellido2V());
  ASSERT_EQ("", m.getDniV());
  ASSERT_EQ("", m.getFecha_nacimiento());
  ASSERT_EQ("", m.getTelefonoV());
  ASSERT_EQ("", m.getDiscapacidad());
  }
  //Tests modificadores y constructores
  TEST(Visitante, ModificadoresObservadores) {
    Visitante v("Angel","Villegas","del Rio","46069556G","26.10.1999",606682354,"Esguince");
    v.setNombreV("Angel");
    ASSERT_EQ("Angel",m.getNombreV());

    v.setApellido1V("Villegas");
    ASSERT_EQ("Villegas",m.getApellido1V());

    v.setDniV("46069556G");
    ASSERT_EQ("46069556G",m.getApellido2V());

    v.setFecha_nacimiento("26.10.1999");
    ASSERT_EQ("26.10.1999",m.getFecha_nacimiento());

    v.setTelefonoV("606682354");
    ASSERT_EQ("606682354", m.getTelefonoV());

    v.setDiscapacidad("Esguince");
    ASSERT_EQ("Esguince", m.getDiscapacidad());
  }
  //Test get Datos
  TEST(Visitante,getDatos){
    Visitante v;
    v.getDatos();
  }
