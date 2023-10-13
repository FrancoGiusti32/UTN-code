#include <iostream>
#include <string>
using namespace std;
struct Boletin {
	int notas[3];
	int amonestaciones[3];
	int faltas[3];
};

struct Alumno {
	string nombre;
	string apellido;
	int dni;
	char sexo;
	Boletin boleta;
};

int pedirD( int min, int max) {
	int num;
	do {
		cout << "Ingrese un número: ";
		cin >> num;
		if (num < min || num > max) {
			cout << "Número inválido ??" << endl;
		}
	} while (num < min || num > max);
	return num;
}

void llenarB(Alumno &alm, int i) {
	for (int anio = 0; anio < 3; anio++) {
		cout << "Ingrese la nota del alumno " << alm.nombre << " " << alm.apellido << " del año " << anio + 1 << ": ";
		alm.boleta.notas[anio]=pedirD(0, 10);
		
		cout << "Ingrese las amonestaciones del alumno " << alm.nombre << " " << alm.apellido << " del año " << anio + 1 << ": ";
		alm.boleta.amonestaciones[anio]=pedirD(0, 10);
		
		cout << "Ingrese las faltas del alumno " << alm.nombre << " " << alm.apellido << " del año " << anio + 1 << ": ";
		alm.boleta.faltas[anio]=pedirD(0, 10);
	}
}

void mostrarDatos(const Alumno &alum) {
	cout << "Nombre [" << alum.nombre << "]" << endl;
	cout << "Apellido [" << alum.apellido << "]" << endl;
	cout << "DNI [" << alum.dni << "]" << endl;
}

void ordList(Alumno almList[30], int anio) {
	int shift, i;
	do {
		shift = 0;
		for (i = 0; i < 29; i++) {
			if (almList[i].boleta.notas[anio] < almList[i + 1].boleta.notas[anio]) {
				shift = shift + 1;
				Alumno aux = almList[i];
				almList[i] = almList[i + 1];
				almList[i + 1] = aux;
			}
		}
	} while (shift != 0);
}

void mostrarMjProd(Alumno almList[30], int cantAlm) {
	int i, anio, cont = 0;
	cout << "Ingrese el año que desea mostrar: ";
	anio=pedirD(0, 3);
	
	ordList(almList, anio);
	
	cout << "LOS 3 ALUMNOS CON MEJOR PROMEDIO, SIN AMONESTACIONES, Y QUE TENGAN MENOS DE 7 FALTAS SON:" << endl;
	for (i = 0; i < cantAlm; i++) {
		if (cont <= 3 && almList[i].boleta.faltas[anio] < 7 && almList[i].boleta.amonestaciones[anio] == 0) {
			mostrarDatos(almList[i]);
			cont = cont + 1;
		}
	}
}

void mostrarPJ(Alumno almList[30], int cantAlm) {
	int i, anio, cont = 0;
	cout << "Ingrese el año que desea mostrar: ";
	anio=pedirD(0, 3);
	
	cout << "LOS ALUMNOS CON MAS DE 15 AMONESTACIONES Y SUS FALTAS SON:" << endl;
	for (i = 0; i < cantAlm; i++) {
		if (almList[i].boleta.amonestaciones[anio] > 15) {
			mostrarDatos(almList[i]);
			cout << "Sus faltas son: " << almList[i].boleta.faltas[anio] << endl;
			cont = cont + 1;
		}
	}
	cout << "Fueron " << cont << " alumnos los mayores a 15 amonestaciones" << endl;
}

int main() {
	Alumno almList[30];
	int almCant;
	
	cout << "Escriba la cantidad de alumnos: ";
	almCant=pedirD(0, 30);
	
	for (int i = 0; i < almCant; i++) {
		cout << "Escriba el nombre del alumno " << i + 1 << ": ";
		cin >> almList[i].nombre;
		cout << "Escriba el apellido del alumno " << i + 1 << ": ";
		cin >> almList[i].apellido;
		cout << "Escriba el sexo del alumno " << i + 1 << ": ";
		cin >> almList[i].sexo;
		cout << "Escriba el dni del alumno " << i + 1 << ": ";
		almList[i].dni=pedirD( 0, 99999999);
		llenarB(almList[i], i);
	}
	
	mostrarMjProd(almList, almCant);
	mostrarPJ(almList, almCant);
	
	return 0;
}

