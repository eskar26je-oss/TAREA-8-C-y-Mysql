#pragma once
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
#include <mysql.h>
using namespace std;
class Estudiante : public Persona {
	//atributos
private:
	int id_estudiante = 0;
	string codigo = "";
	// constructores
public:
	Estudiante() {}
	Estudiante(int id_est, string cod, string nom, string ape, string dir, int tel, string fn, int id_ts)
		: Persona(nom, ape, dir, tel, fn, id_ts) {
		id_estudiante = id_est;
		codigo = cod;
	}
	//metodos get y set
	//set modificar atributos
	void setId_estudiante(int e) { id_estudiante = e; }
	void setCodigo(string c) { codigo = c; }
	void setNombres(string n) { nombres = n; }
	void setApellidos(string a) { apellidos = a; }
	void setDireccion(string d) { direccion = d; }
	void setTelefono(int t) { telefono = t; }
	void setFecha_Nacimiento(string f) { fecha_nacimiento = f; }
	void setId_Tipo_Sangre(int ts) { id_tipo_sangre = ts; }

	// get (mostrar el contenido del atribo)

	int getId_estudiante() { return id_estudiante; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_nacimiento() { return fecha_nacimiento; }
	int getId_tipo_sangre() { return id_tipo_sangre; }

	// metodos
	// metodo leer estudiantes desde la base de datos por medio de un query Select * from estudiantes
	void crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.get_conexion()) {
			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string consulta = "INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre)VALUES('" + codigo + "', '" + nombres + "', '" + apellidos + "', '" + direccion + "', " + t + ", '" + fecha_nacimiento + "', " + id_ts + ");";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.get_conexion(), c);
			if (!q_estado) {
				cout << "Ingreso de datos exitoso" << endl;
			}
			else {
				cout << "Error al insertar: " << mysql_error(cn.get_conexion()) << endl;
			}
		}
		cn.cerrar_conexion();
	}
		void leer(){
			ConexionBD conexion;
			conexion.abrir_conexion();
			MYSQL* conn = conexion.get_conexion();
			if (conn) {
				string consulta = "SELECT * FROM estudiantes";
				const char* c = consulta.c_str();
				mysql_query(conn, c);
				MYSQL_RES* resultado = mysql_store_result(conn);
				int num_filas = mysql_num_rows(resultado);
				for (int i = 0; i < num_filas; i++) {
					MYSQL_ROW fila = mysql_fetch_row(resultado);
					cout << "ID: " << fila[0] <<
						" Codigo: " << fila[1] <<
						" Nombres: " << fila[2] <<
						" Apellidos: " << fila[3] <<
						" Direccion: " << fila[4] <<
						" Telefono: " << fila[5] <<
						" Fecha de Nacimiento: " << fila[6] <<
						" ID Tipo Sangre: " << fila[7] << endl;

				}
			}
			else {
				cout << "Error al conectar a la base de datos" << endl;
			}
			conexion.cerrar_conexion();
		}
		void actualizar() {
			int q_estado = 0;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.get_conexion()) {
				string t = to_string(telefono);
				string id_ts = to_string(id_tipo_sangre);
				string id_est = to_string(id_estudiante);
				string consulta = "update estudiantes set codigo='" + codigo + "', nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono=" + t + ", fecha_nacimiento='" + fecha_nacimiento + "', id_tipo_sangre=" + id_ts + " where id_estudiante=" + id_est;
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.get_conexion(), c);
				if (!q_estado) {
					cout << "Modificación de datos exitoso" << endl;
				}
				else {
					cout << "Error al modificar: " << mysql_error(cn.get_conexion()) << endl;
				}
			}
			cn.cerrar_conexion();
		}
		void eliminar() {
			int q_estado = 0;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.get_conexion()) {
				string t = to_string(telefono);
				string id_ts = to_string(id_tipo_sangre);
				string id_est = to_string(id_estudiante);
				string consulta = "DELETE FROM estudiantes WHERE id_estudiante=" + id_est;
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.get_conexion(), c);
				if (!q_estado) {
					cout << "Eliminación de datos exitosa" << endl;
				}
				else {
					cout << "Error al eliminar: " << mysql_error(cn.get_conexion()) << endl;
				}
			}
			cn.cerrar_conexion();
		}
	 
};