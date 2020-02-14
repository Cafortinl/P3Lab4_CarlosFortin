#include <iostream>
#include <string>
#include <array>
#include "Usuario.hpp"
#include "Libro.hpp"

using namespace std;

Usuario actual;
bool vive = true, adentro = true;
int contUsuarios = 1, contLibros = 0; 
array<Libro, 10> libros;
array<Usuario, 10> usuarios;

void listarLibros(){
	for(int i=0;i<libros.size();i++){
		if(libros[i].getTitulo() != "")
		cout << i << " - " << libros[i].getTitulo() << "/" << libros[i].getAutor() << "/" << libros[i].getPublicacion() << "/" << libros[i].getPrecio() << "/" << libros[i].isDisponibleS() <<  endl;
	}
}

void listarLibrosAutor(string a){
	bool existe = false;
	for(int i=0;i<libros.size();i++){
		if(a == libros[i].getAutor()){
			existe = true;
			cout << i << " - " << libros[i].getTitulo() << "/" << libros[i].getAutor() << "/" << libros[i].getPublicacion() << "/" << libros[i].getPrecio() << "/" << libros[i].isDisponibleS() <<  endl;
		}
	}
	if(!existe)
		cout << "No hay libros del autor ingresado" << endl;
}

void listarLibrosTitulo(string a){
        bool existe = false;
        for(int i=0;i<libros.size();i++){
                if(a == libros[i].getTitulo()){
                        existe = true;
                        cout << i << " - " << libros[i].getTitulo() << "/" << libros[i].getAutor() << "/" << libros[i].getPublicacion() << "/" << libros[i].getPrecio() << "/" << libros[i].isDisponibleS() <<  endl;
                }
        }
        if(!existe)
                cout << "No hay libros del autor ingresado" << endl;
}


bool valido(string usuario){
	bool valido = true;
	for(int i=0;i<10;i++){
		if(usuario == usuarios[i].getUsuario()){
			valido = false;
			break;
		}
	}
	return valido;
}

bool login(){
	bool entro = false;
 	string usuario, password;
	cout << "Ingrese su usuario:";
	cin >> usuario;
	cout << "Ingrese la clave:";
	cin >> password;
	for(int i=0;i<10;i++){
		if(usuario == usuarios[i].getUsuario() && password == usuarios[i].getPassword()){
			actual = usuarios[i];
			entro = true;
			break;
		}
	}
	if(!entro)
		cout << "Usuario o clave incorrecta" << endl;
	else
		cout << "Se ha ingresado correctamente" << endl;
	return entro;	
}

bool registro(){
	int pos=0, edad;
	string usuario, nombre, password;
	double dinero;
	bool vacio = false;
	Usuario temp;
	if(contUsuarios < 11){
		vacio = true;
		contUsuarios++;
	}
	if(vacio){
		cout << "Ingrese un nombre de usuario:";
		cin >> usuario;
		while(!valido(usuario)){
			cout << "Ese usuario no esta disponible. Ingrese otro usuario:";
			cin >> usuario;
		}
		cout << "Ingrese una clave:";
		cin >> password;
		cout << "Ingrese su nombre:";
		cin >> nombre;
		cout << "Ingrese su edad:";
		cin >> edad;
		cout << "Ingrese una cantidad de dinero:";
		cin >> dinero;
		temp.setUsuario(usuario);
		temp.setPassword(password);
		temp.setNombre(nombre);
		temp.setEdad(edad);
		temp.setDinero(dinero);
		usuarios[contUsuarios-1] = temp;
		actual = usuarios[contUsuarios -1];
	}
	else
		cout << "No hay mas espacios disponibles" << endl;

	return vacio;
}

int menuAdmin(){
	cout << "---------- Menu ----------" << endl;
	cout << "1. Agregar libro" << endl;
	cout << "2. Modificar Libro" << endl;
	cout << "3. Eliminar libro" << endl;
	cout << "4. Borrar registro de libros" << endl;
	cout << "5. Cerrar sesion" << endl;
	cout << "6. Salir" << endl;
}

int menuComun(){
	cout << "---------- Menu ----------" << endl;
	cout << "1. Comprar libro" << endl;
	cout << "2. Buscar por autor" << endl;
	cout << "3. Buscar por titulo" << endl;
	cout << "4. Agregar dinero a mi cuenta" << endl;
	cout << "5. Restablecer clave" << endl;
	cout << "6. Borrar cuenta" << endl;
	cout << "7. Cerrar sesion" << endl;
	cout << "8. Salir" << endl;
}

void opcionesComun(int o){
	switch(o){
		case 1:{
			       int pos;
			       listarLibros();
			       cout << "Ingrese la posicion del libro que desea comprar:";
			       cin >> pos;
			       if(actual.getDinero() >= libros[pos].getPrecio() && libros[pos].isDisponible() == true){
				       actual.setDinero(actual.getDinero() - libros[pos].getPrecio());
				       libros[pos].setDisponible(false);
			       }
			       else
				       cout << "Puede que el libro que ha ingresado no esta disponible o no dispone de los fondos requeridos" << endl;
			       break;
		       }

		case 2:{
			       string autor;
			       cout << "Ingrese el nombre del autor que busca:";
			       cin >> autor;
			       listarLibrosAutor(autor);
			       break;
		       }

		case 3:{
			       string titulo;
			       cout << "Ingrese el titulo del libro que busca:";
			       cin >> titulo;
			       listarLibrosTitulo(titulo);
			       break;
		       }

		case 4:{
			       double dinero;
			       cout << "Ingrese la cantidad a agregar:";
			       cin >> dinero;
			       actual.setDinero(actual.getDinero() + dinero);
			       break;
		       }

		case 5:{
			       string clave1, clave2;
			       cout << "Ingrese la clave anterior para poder restablecerla:";
			       cin >> clave1;
			       if(clave1 == actual.getPassword()){
				       cout << "Ingrese la nueva clave:";
				       cin >> clave2;
				       actual.setPassword(clave2);
				       cout << "Clave restablecida correctamente" << endl;
			       }
			       else
				       cout << "La clave ingresada no es la correcta" << endl;
			       break;
		       }

		case 6:{
		       }

		case 7:{
			       break;
		       }

		case 8:{
			       break;
		       }
	}
}

void opcionesAdmin(int o){
	switch(o){
		case 1:{
			       if(contLibros < 11){
				       string titulo, autor;
				       int publicacion;
				       double precio;
				       Libro temp;
				       cout << "Ingrese el nombre del libro:";
				       cin >> titulo;
				       cout << "Ingrese el autor del libro:";
				       cin >> autor;
				       cout << "Ingrese el año de publicacion:";
				       cin >> publicacion;
				       cout << "Ingrese el precio:";
				       cin >> precio;
				       temp.setTitulo(titulo);
				       temp.setAutor(autor);
				       temp.setPublicacion(publicacion);
				       temp.setPrecio(precio);
				       temp.setDisponible(true);
				       libros[contLibros] = temp;
				       contLibros++;
			       }
			       else
				       cout << "No se pueden agregar mas libros, borre el registro si desea agregar nuevos" << endl;
			       break;
		       }
		case 2:{
			       int pos, op;
			       listarLibros();
			       cout << "Ingrese la posicion del libro que desea modificar:";
			       cin >> pos;
			       if(pos <= libros.size()-1){
				       cout << "1. Modificar titulo" << endl;
				       cout << "2. Modificar autor" << endl;
				       cout << "3. Modificar publicacion" << endl;
				       cout << "4. Modificar Precio" << endl;
				       cin >> op;
				       switch(op){
					       case 1:{
							      string nombre;
							      cout << "Ingrese el nombre del libro:";
							      cin >> nombre;
							      libros[pos].setTitulo(nombre);
							      break;
						      }
					       case 2:{
							      string autor;
							      cout << "Ingrese el nombre del autor:";
							      cin >> autor;
							      libros[pos].setAutor(autor);
							      break;
						      }
					       case 3:{
							      int publicacion;
							      cout << "Ingrese el año de publicacion:";
							      cin >> publicacion;
							      libros[pos].setPublicacion(publicacion);
							      break;
						      }
					       case 4:{
							      double precio;
							      cout << "Ingrese el precio del libro:";
							      cin >> precio;
							      libros[pos].setPrecio(precio);
							      break;
						      }
				       }
			       }
			       else
				       cout << "La posicion ingresada no es valida" << endl;
			       break;
		       }
		case 3:{
			       int pos;
			       listarLibros();
			       cout << "Ingrese la posicion del libro que desea eliminar: ";
			       cin >> pos;
			       break;
		       }
		case 4:{
			       break;
		       }

		case 5:{
			       break;
		       }

		case 6:{
			       break;
		       }
	}
}

bool ejecucion(Usuario t, Usuario a){
	int opcion;
	bool continua = true;
	if(t.getUsuario() == a.getUsuario()){
		while(opcion != 5 && opcion != 6){
                	menuAdmin();
			cin >> opcion;
			opcionesAdmin(opcion);
		}
		if(opcion == 5)
			continua = false;
	}
        else{
		while(opcion != 7 && opcion != 8){
               		menuComun();
			cin >> opcion;
			opcionesComun(opcion);
		}
		if(opcion == 7)
			continua = false;
	}
	return continua;
}

int main(){
	Usuario admin("n.duron", "sybase", "Nicolle Duron", 20, 1000);
	bool entro = false;
	usuarios[0] = admin;
	while(vive){
		adentro = true;
		while(!entro){
                	int log;
               		cout << "Presione 1 para ingresar" << endl;
                	cout << "Presione 2 para registrarse" << endl;
                	cin >> log;

                	if(log == 1)
                        	entro = login();
                	else if (log == 2)
                        	entro = registro();
                	else
                        	cout << "La opcion ingresada no es valida" << endl;

			entro = ejecucion(actual, admin);
		}
		vive = false;
        }
	//if(actual.getUsuario() == admin.getUsuario())
	//	opcionesAdmin();
	//else
	//	opcionesComun();
	return 0;
}
