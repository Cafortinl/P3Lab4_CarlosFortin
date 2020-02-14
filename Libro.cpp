#include "Libro.hpp"
#include <string>

Libro::Libro(){
}

Libro::Libro(string t, string a, int p, double pr, bool e){
	titulo = t;
	autor = a;
	publicacion = p;
	precio = pr;
	disponible = e;
}

void Libro::setTitulo(string x){
	titulo = x;
}

string Libro::getTitulo(){
	return titulo;
}

void Libro::setAutor(string x){
	autor = x;
}

string Libro::getAutor(){
	return autor;
}

void Libro::setPublicacion(int x){
	publicacion = x;
}

int Libro::getPublicacion(){
	return publicacion;
}

void Libro::setPrecio(double x){
	precio = x;
}

double Libro::getPrecio(){
	return precio;
}

void Libro::setDisponible(bool x){
	disponible = x;
}

bool Libro::isDisponible(){
	return disponible;
}