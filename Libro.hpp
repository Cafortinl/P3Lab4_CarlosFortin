#pragma once
#ifndef LIBRO_HPP
#define LIBRO_HPP
#include <string>

class Libro{
	private:
		string titulo, autor;
		int publicacion;
		double precio;
		bool disponible;
	public:
		Libro();
		Libro(string t, string a, int p, double pr, bool e);
		void setTitulo(string x);
		string getTitulo();
		void setAutor(string x);
		string getAutor();
		void setPublicacion(int x);
		int getPublicacion();
		void setPrecio(double x);
		double getPrecio();
		void setDisponible(bool x);
		bool isDisponible();
};
#endif
