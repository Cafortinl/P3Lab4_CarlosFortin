#include <iostream>
#include <string>
#include <array>
#include "Usuario.hpp"
#include "Libro.hpp"

using namespace std;

Usuario actual;
int contUsuarios = 1, contLibros = 0; 
array<Libro, 10> libros;
array<Usuario, 10> usuarios;

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
}

int menuComun(){
	cout << "---------- Menu ----------" << endl;
	cout << "1. Comprar libro" << endl;
	cout << "2. Buscar por autor" << endl;
	cout << "3. Buscar por titulo" << endl;
	cout << "4. Agregar dinero a mi cuenta" << endl;
	cout << "5. Restablecer clave" << endl;
	cout << "6. Borrar cuenta" << endl;
}

void opcionesComun(int o){
}

void opcionesAdmin(int o){
	switch(opcion){
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
						      }
					       case 2:{
						      }
					       case 3:{
						      }
					       case 4:{
						      }
				       }
			       }
			       else
				       cout << "La posicion ingresada no es valida" << endl;
			       break;
		       }
		case 3:{
			       break;
		       }
		case 4:{
			       break;
		       }
	}
}

void ejecucion(Usuario t, Usuario a){
	int opcion;
	if(actual.getUsuario() == admin.getUsuario()){
                menuAdmin();
		cin >> opcion;
		opcionesAdmin(opcion);
	}
        else{
                menuComun();
		cin >> opcion;
		opcionesComun(opcion);
	}
}

int main(){
	bool entro = false;
	Usuario admin("n.duron", "sybase", "Nicolle Duron", 20, 1000);
	usuarios[0] = admin;
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
        }
	//if(actual.getUsuario() == admin.getUsuario())
	//	opcionesAdmin();
	//else
	//	opcionesComun();
	return 0;
}
