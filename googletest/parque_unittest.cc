//PARQUE UNITTEST
#include "parque.h"
#include "ruta.h"
#include "gtest/gtest.h"

//Test el constructor
TEST(Parque, Constructor) {
  Parque p;

  ASSERT_EQ("", p.getNombre());
  ASSERT_EQ("", p.getLocalizacion());
  ASSERT_EQ(0, p.getSuperficie());
  ASSERT_EQ("", p.getFecha_reconocimiento());
  ASSERT_EQ(0, p.getTelefono_parque());
  ASSERT_EQ("", p.getHorario());
  }
  //Tests modificadores y observadores
  TEST(Parque, ModificadoresObservadores) {
    Parque p("MiraBueno","Cordoba","3500","26.10.1999",606682354,"09 a 20");
    p.setNombre("MiraBueno");
    ASSERT_EQ("MiraBueno",p.getNombre());

    p.setLocalizacion("Cordoba");
    ASSERT_EQ("Cordoba",p.getLocalizacion());

    p.setSuperficie("3500");
    ASSERT_EQ("3500",p.getSuperficie());

    p.setFecha_reconocimiento("26.10.1999");
    ASSERT_EQ("26.10.1999",p.getFecha_reconocimiento());

    p.setTelefono_parque("606682354");
    ASSERT_EQ("606682354", p.getTelefono_parque());

    p.setHorario("09 a 20");
    ASSERT_EQ("09 a 20", p.getHorario());
  }
  //Test visualizar rutas
  TEST(Parque, visualizarRutas) {
    Parque p;
    p.visualizarRutas();
  }
  //Test visualizar visitantes reserva
  TEST(Parque,visualizarVisitantesReserva){
    Parque p;
    p.visualizarVisitantesReserva();
  }
//Test mostrar estado de ruta
TEST(Parque,mostrarEstadoRuta){
  Parque p;
  p.mostrarEstadoRuta();
}
//Test buscar Informacion
TEST(Parque,buscarInformacion){
  Parque p;
  p.buscarInformacion();
}
