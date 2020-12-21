//PARQUE UNITTEST
#include "Visitante.h"
#include "gtest/gtest.h"

//Test the constructor
TEST(Visitante, Constructor) {
  Visitante v;

  ASSERT_EQ("", v.getNombreV());
  ASSERT_EQ("", v.getApellido1V());
  ASSERT_EQ("", v.getApellido2V());
  ASSERT_EQ("", v.getDniV());
  ASSERT_EQ("", v.getFecha_nacimiento());
  ASSERT_EQ("", v.getTelefonoV());
  ASSERT_EQ(0, v.getDiscapacidad());
  }
  //Tests modificadores y observadores
  TEST(Visitante, ModificadoresObservadores) {
    Visitante v("Angel","Villegas","del Rio","46069556G","26.10.1999",606682354,"Esguince");
    v.setNombreV("Angel");
    ASSERT_EQ("Angel",v.getNombreV());

    v.setApellido1V("Villegas");
    ASSERT_EQ("Villegas",v.getApellido1V());

    v.setDniV("46069556G");
    ASSERT_EQ("46069556G",v.getApellido2V());

    v.setFecha_nacimiento("26.10.1999");
    ASSERT_EQ("26.10.1999",v.getFecha_nacimiento());

    v.setTelefonoV("606682354");
    ASSERT_EQ("606682354", v.getTelefonoV());

    v.setDiscapacidad("Esguince");
    ASSERT_EQ("Esguince", v.getDiscapacidad());
  }
  //Test get Datos
  TEST(Visitante,getDatos){
    Visitante v;
    v.getDatos();
  }
