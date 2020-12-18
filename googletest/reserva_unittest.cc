// MONITOR_UNITTEST_CC

#include "reserva.h"
#include "gtest/gtest.h"

// Tests the constructor.
TEST(Reserva, Constructor) {
  Reserva r;
  
  EXPECT_EQ("",r.getDniReserva());
  EXPECT_EQ("", r.getFechaReserva());
  EXPECT_EQ("", r.getTipoRuta());
}

//Test de Modificadores y Observadores
TEST(Reserva, ModificadoresyObservadores){
    Reserva r;
    r.setDniReserva("123X");
    EXPECT_EQ("123X", r.getDniReserva());
    r.setFechaReserva("01/01/2021");
    EXPECT_EQ("01/01/2021", r.getFechaReserva());
    r.setTipoRuta("Bicicleta");
    EXPECT_EQ("Bicicleta", r.getTipoRuta());
}