#include <iostream>
#include "Estudiante.h"
using namespace std;
int main() {
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;
	Estudiante v; 
	while(true) {

		cout << "Ingrese Codigo: ";
		cin >> codigo;

		v.setCodigo(codigo);

		if (v.validarCodigo()) {
			break;
		}
	}
	cin.ignore();
	while (true) {

		cout << "Ingrese Nombres: ";
		getline(cin, nombres);

		v.setNombres(nombres);

		if (v.validarNombres()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);

		v.setApellidos(apellidos);

		if (v.validarApellidos()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Direccion: ";
		getline(cin, direccion);

		v.setDireccion(direccion);

		if (v.validarDireccion()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Telefono: ";
		cin >> telefono;

		v.setTelefono(telefono);

		if (v.validarTelefono()) {
			break;
		}
	}
	cin.ignore();

	while (true) {

		cout << "Ingrese Fecha Nacimiento: ";
		getline(cin, fecha_nacimiento);

		v.setFecha_Nacimiento(fecha_nacimiento);

		if (v.validarFecha()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Tipo Sangre: ";
		cin >> id_tipo_sangre;

		v.setId_Tipo_Sangre(id_tipo_sangre);

		if (v.validarTipoSangre()) {
			break;
		}
	}
	Estudiante e (id_estudiante, codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre);
	e.crear();
	e.leer();
	//actualizar
	cout << "Ingrese ID A MODIFICAR: ";
	cin >> id_estudiante;
	while (true) {

		cout << "Ingrese Codigo: ";
		cin >> codigo;

		v.setCodigo(codigo);

		if (v.validarCodigo()) {
			break;
		}
	}
	cin.ignore();
	while (true) {

		cout << "Ingrese Nombres: ";
		getline(cin, nombres);

		v.setNombres(nombres);

		if (v.validarNombres()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Apellidos: ";
		getline(cin, apellidos);

		v.setApellidos(apellidos);

		if (v.validarApellidos()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Direccion: ";
		getline(cin, direccion);

		v.setDireccion(direccion);

		if (v.validarDireccion()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Telefono: ";
		cin >> telefono;

		v.setTelefono(telefono);

		if (v.validarTelefono()) {
			break;
		}
	}
	cin.ignore();

	while (true) {

		cout << "Ingrese Fecha Nacimiento: ";
		getline(cin, fecha_nacimiento);

		v.setFecha_Nacimiento(fecha_nacimiento);

		if (v.validarFecha()) {
			break;
		}
	}
	while (true) {

		cout << "Ingrese Tipo Sangre: ";
		cin >> id_tipo_sangre;

		v.setId_Tipo_Sangre(id_tipo_sangre);

		if (v.validarTipoSangre()) {
			break;
		}
	}
	e.setId_estudiante(id_estudiante);
	e.setCodigo(codigo); 
	e.setNombres(nombres);
	e.setApellidos(apellidos);
	e.setDireccion(direccion);
	e.setTelefono(telefono);
	e.setFecha_Nacimiento(fecha_nacimiento);
	e.setId_Tipo_Sangre(id_tipo_sangre);
	e.actualizar();
	e.leer();
	cout << "Ingrese ID A eliminar: ";
	cin >> id_estudiante;
	e.setId_estudiante(id_estudiante);
	e.eliminar();
	e.leer();
 }
