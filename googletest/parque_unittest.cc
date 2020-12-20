//PARQUE UNITTEST
#include "parque.h"
#include "ruta.h"
#include "gtest/gtest.h"

//Test the constructor
TEST(Parque, Constructor) {
  Parque p;

  ASSERT_EQ("", m.getNombre());
  ASSERT_EQ("", m.getLocalizacion());
  ASSERT_EQ("", m.getSuperficie());
  ASSERT_EQ("", m.getFecha_reconocimiento());
  ASSERT_EQ("", m.getTelefono_parque());
  ASSERT_EQ("", m.getHorario());
  }
  //Tests modificadores y constructores
  TEST(Parque, ModificadoresObservadores) {
    Parque p("MiraBueno","Cordoba","3500","26.10.1999",606682354,"09 a 20");
    p.setNombre("MiraBueno");
    ASSERT_EQ("MiraBueno",m.getNombre());

    p.setLocalizacion("Cordoba");
    ASSERT_EQ("Cordoba",m.getLocalizacion());

    p.setSuperficie("3500");
    ASSERT_EQ("3500",m.getSuperficie());

    p.setFecha_reconocimiento("26.10.1999");
    ASSERT_EQ("26.10.1999",m.getFecha_reconocimiento());

    p.setTelefono_parque("606682354");
    ASSERT_EQ("606682354", m.getTelefono_parque());

    p.setHorario("09 a 20");
    ASSERT_EQ("09 a 20", m.getHorario());
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
