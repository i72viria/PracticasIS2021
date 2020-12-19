// administrativo_unittest.cc: Álvaro Roldán Lucena

#include <fstream>
#include <list>
#include "administrativo.h"
#include "reserva.h"
#include "Visitante.h"
#include "parque.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Administrativo, ConstructorParametrosDefecto) {
  Administrativo j;
  
  ASSERT_EQ("", j.getNombre());
  ASSERT_EQ("", j.getApellido1());
  ASSERT_EQ("", j.getApellido2());
  ASSERT_EQ("", j.getDni());
  ASSERT_EQ("", j.getDireccion());
  ASSERT_EQ(0, j.getTelefono());
}

TEST(Administrativo, ConstructorParametros) {
  Administrativo j("Alvaro","Roldan","Lucena","123456789X","Cordoba","i92rolua@uco.es",123456789);
  
  ASSERT_EQ("Alvaro", j.getNombre());
  ASSERT_EQ("Roldan", j.getApellido1());
  ASSERT_EQ("Lucena", j.getApellido2());
  ASSERT_EQ("123456789X", j.getDni());
  ASSERT_EQ("Cordoba", j.getDireccion());
  ASSERT_EQ(123456789, j.getTelefono());
}

TEST(Administrativo, setNombreygetNombre) {
  Administrativo j("Pepe");

  ASSERT_EQ("Pepe", j.getNombre());
  j.setNombre("Paco");
  ASSERT_EQ("Paco", j.getNombre());
}

TEST(Administrativo, setApellido1ygetApellido1) {
  Administrativo j("Pepe","Rodriguez");

  ASSERT_EQ("Rodriguez", j.getApellido1());
  j.setApellido1("Lozano");
  ASSERT_EQ("Lozano", j.getApellido1());
}

TEST(Administrativo, setApellido2ygetApellido2) {
  Administrativo j("Pepe","Rodriguez","Roldan");

  ASSERT_EQ("Roldan", j.getApellido2());
  j.setApellido2("Laguna");
  ASSERT_EQ("Laguna", j.getApellido2());
}

TEST(Administrativo, setDniygetDni) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X");

  ASSERT_EQ("123X", j.getDni());
  j.setDni("876A");
  ASSERT_EQ("876A", j.getDni());
}

TEST(Administrativo, setDireccionygetDireccion) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid");

  ASSERT_EQ("Madrid", j.getDireccion());
  j.setDireccion("Bilbao");
  ASSERT_EQ("Bilbao", j.getDireccion());
}

TEST(Administrativo, setEmailygetEmail) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es");

  ASSERT_EQ("pepe@uco.es", j.getEmail());
  j.setEmail("rodri@uco.es");
  ASSERT_EQ("rodri@uco.es", j.getEmail());
}


TEST(Administrativo, setTelefonoygetTelefono) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123);

  ASSERT_EQ(123, j.getTelefono());
  j.setTelefono(999);
  ASSERT_EQ(999, j.getTelefono());
}

TEST(Administrativo, getUsuario) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123);

  ASSERT_EQ("PepeRodriguezRoldan", j.getUsuario());
  j.setNombre("Paco");
  j.setApellido1("Lozano");
  j.setApellido2("Laguna");
  j.setUsuario();
  ASSERT_EQ("PacoLozanoLaguna", j.getUsuario());
}
TEST(Administrativo, getContrasena) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123);

  ASSERT_EQ("123X", j.getContrasena());
  j.setDni("968A");
  j.setContrasena();
  ASSERT_EQ("968A", j.getContrasena());
}

TEST(Administrativo, crearReserva) {
  
  Administrativo m;

  Reserva j("12/12/2020","123456789X","Bicicleta");
  Reserva w("15/08/2020","987654321A","A pie");

  ASSERT_TRUE(m.creaReserva(j));
  ASSERT_TRUE(m.creaReserva(w));

  ASSERT_FALSE(m.creaReserva(j));
  ASSERT_FALSE(m.creaReserva(w));
}


TEST(Administrativo, deleteDatos) {

  Administrativo m;
  string nombre="";

  ASSERT_EQ(-1,m.deleteDatos(nombre));
  
  Parque j("Pedroches","Cordoba",540.54,"21/03/1989",123456789,"09:00 a 20:00 L-V");

  m.crearParque(j);
  nombre=j.getNombre();

  ASSERT_EQ(1,m.deleteDatos(nombre));

  m.crearParque(j);
  nombre="Caminito del Rey";
  ASSERT_EQ(-2,m.deleteDatos(nombre));
}

TEST(Administrativo, crearParque) {
  
  Administrativo m;

  Parque i("Pedroches","Cordoba",540.54,"21/03/1989",123456789,"09:00 a 20:00 L-V");
  Parque j("Caminito del Rey","Malaga",320.19,"01/11/19759",987654321,"09:00 a 20:00 L-J y 12:00 a 14:00 S-D");

  ASSERT_TRUE(m.crearParque(i));
  ASSERT_TRUE(m.crearParque(j));

  ASSERT_FALSE(m.crearParque(i));
  ASSERT_FALSE(m.crearParque(j));
}

TEST(Administrativo, identificacion) {
  Administrativo j("Pepe","Rodriguez","Roldan","123X","Madrid","pepe@uco.es",123);

  cout<<"\n"<<"El usuario es PepeRodriguezRoldan y la contrasena 123X"<<endl;

  ASSERT_TRUE(j.identificacion());
  cout<<"\n"<<"Ahora introducir mal."<<endl;
  ASSERT_FALSE(j.identificacion());
}