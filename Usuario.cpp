#include "Usuario.hpp"
#include <string>

Usuario::Usuario(){
}

Usuario::Usuario(string u, string p, string n, int e, double d){
	usuario = u;
	password = p;
	nombre = n;
	edad = e;
	dinero = d;
}

void Usuario::setUsuario(string x){
	usuario = x;
}

string Usuario::getUsuario(){
	return usuario;
}

void Usuario::setPassword(string x){
	password = x;
}

string Usuario::getPassword(){
	return password;
}

void Usuario::setNombre(string x){
	nombre = x;
}

string Usuario::getNombre(){
	return nombre;
}

void Usuario::setEdad(int x){
	edad = x;
}

int Usuario::getEdad(){
	return edad;
}

void Usuario::setDinero(double x){
	dinero = x;
}

double Usuario::getDinero(){
	return dinero;
}

