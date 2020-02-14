#pragma once
#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>

class Usuario{
	private:
		string usuario, password, nombre;
		int edad;
		double dinero;
	public:
		Usuario();
		Usuario(string u, string p, string n, int e, double d);
		void setUsuario(string x);
		string getUsuario();
		void setPassword(string x);
		string getPassword();
		void setNombre(string x);
		string getNombre();
		void setEdad(int x);
		int getEdad();
		void setDinero(double x);
		double getDinero();
};
#endif
