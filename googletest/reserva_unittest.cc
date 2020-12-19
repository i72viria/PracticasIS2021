// MONITOR_UNITTEST_CC

#include "reserva.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Reserva, Constructor) {
  Reserva r;
  
  ASSERT_EQ("",r.getDniReserva());
  ASSERT_EQ("", r.getFechaReserva());
  ASSERT_EQ("", r.getTipoRuta());
}

//Test de Modificadores y Observadores
TEST(Reserva, ModificadoresyObservadores){
    Reserva r;
    r.setDniReserva("123X");
    ASSERT_EQ("123X", r.getDniReserva());
    r.setFechaReserva("01/01/2021");
    ASSERT_EQ("01/01/2021", r.getFechaReserva());
    r.setTipoRuta("Bicicleta");
    ASSERT_EQ("Bicicleta", r.getTipoRuta());
}