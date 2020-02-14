#include "Usuario.hpp"
#include <string>

Usuario::Usuario(){
}

Usuario(string u, string p, string n, int e, double d){
	usuario = u;
	password = p;
	nombre = n;
	edad = e;
	dinero = d;
}

void setUsuario(string x){
	usuario = x;
}

string getUsuario(){
	return usuario;
}

void setPassword(string x){
	password = x;
}

string getPassword(){
	return password;
}

void setNombre(string x){
	nombre = x;
}

string getNombre(){
	return nombre;
}

void setEdad(int x){
	edad = x;
}

int getEdad(){
	return edad;
}

void setDinero(double x){
	dinero = x;
}

double getDinero(){
	return dinero;
}

