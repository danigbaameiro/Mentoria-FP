/*

====================================

Resuelto por: Alvaro Casado Molinero

====================================
*/


#include<iostream>
#include<fstream>
using namespace std;
#include<string>
#include<locale.h>
#include<ctime>
#include<cctype>
#include <cstdlib>
#include<cmath>
#include<iomanip>
const int tam = 10;
typedef enum {soltero, casado, divorciado, viudo, con_pareja}tEstado;

typedef enum {hombre, mujer}tSexo;
typedef struct {
	long int dni;
	char letra;
	
}tDni;
typedef struct {
	tDni dni;
	string nombre;
	string apellidos;
	tSexo sexo;
	tEstado estado;
}tPersona;

typedef tPersona tArray[tam];

string cambiarestado(tArray persona, int i);
string cambiarsexo(tArray persona, int i);
int menu();
int lectura();
void busqueda();
tArray personas;
void addmember(int e);
void ordenar(int e);
void mostrar(int e);
int main(){
setlocale(LC_CTYPE, "Spanish");
	
	
	 int op = 0,e;
	 
	
		do{
			op = menu();
			switch(op){
				case 1: busqueda();break;
				case 2: e=lectura();break;
				case 3: addmember(e);break;
				case 4: ordenar(e);break;
				case 5: mostrar(e);
			}
		}while(op!=0);
	
	
	
	
	
	return 0;
}
string cambiarestado(tArray personas,int i){
	string transformar;
	if(personas[i].sexo==hombre){
	switch(personas[i].estado){
		case soltero: transformar = "Soltero";break;
		case casado: transformar = "Casado";break;
		case divorciado: transformar = "Divorciado";break;
		case viudo: transformar = "Viudo";break;
		case con_pareja:transformar = "Con Pareja"; break;
	}
	}else{
		switch(personas[i].estado){
		case soltero: transformar = "Soltera";break;
		case casado: transformar = "Casada";break;
		case divorciado: transformar = "Divorciada";break;
		case viudo: transformar = "Viuda";break;
		case con_pareja:transformar = "Con Pareja"; break;
	}
	}
	return transformar;

}
string cambiarsexo(tArray personas, int i){
	string sexo;
	switch(personas[i].sexo){
	case hombre: sexo = "Hombre"; break;
	case mujer: sexo = "Mujer"; break;
	
	}
	return sexo;
}

int menu(){
	int op = 0;
	

	do{
	cout<<"5 - mostrar\n";
	cout<<"4 - ordenar\n";
	cout<<"3 - Agregar una persona al registro\n";
	cout<<"2 - Cargar\n";
	cout<<"1 - Cambiar estado civil de una persona\n";
	cout<<"0 - Salir\n";
	cout<<"Opcion: ";
	cin>>op;
	cout<<endl;
	
	}while(op<0||op>5);
	
	return op;
}
int lectura(){
	 char c, letra;
	 

	 int i = 0, e = 1;
	 int estado;
	 int sexo,numero;
	 ifstream lectura;
	lectura.open("input.txt");
	if(lectura.is_open()){
	while(i<tam&&numero>-1){
		
		lectura>>numero;
		
		if(numero>-1){
			
		personas[i].dni.dni=numero;
		
		lectura>>letra;
		personas[i].dni.letra=letra;
		
		lectura>>personas[i].nombre;
		
		lectura.get(c);
		
		getline(lectura, personas[i].apellidos);
		
		lectura>>sexo;
		personas[i].sexo=tSexo (sexo);
		
		lectura>>estado;
		personas[i].estado=tEstado (estado);
		
		
		i++;
		e++;
	}}
	
	}else cout<<"No se ha podido abrir el archivo\n";
	
	
	
	lectura.close();
	e--;
	return e;
}
void busqueda(){
	string estado;
	ofstream escritura;
	

	
	int i = 0, e = 0, dni;
	bool encontrado = false, correcto = false;
	cout<<"Inserte el DNI de la persona, SIN LA LETRA: ";
	cin>>dni;
	while(!encontrado&&i<tam){
		if(dni==personas[i].dni.dni){encontrado=true;}
		else i++;
		
	}
	if(encontrado==true){
		escritura.open("input.txt");
	cout<<"DNI encontrado, por favor escriba el nuevo estado(solter@, casad@, divorciad@, viud@, con pareja): ";
		getline(cin, estado);
	do{
		getline(cin, estado);
		correcto=false;
	if(estado=="soltero"||estado=="soltera")personas[i].estado=soltero;
	else if(estado=="divorciado"||estado=="divorciada")personas[i].estado=divorciado;
	else if(estado=="casado"||estado=="casada")personas[i].estado=casado;
	else if(estado=="viudo"||estado=="viuda")personas[i].estado=viudo;
	else if(estado=="con pareja")personas[i].estado=con_pareja;
		else{cout<<"Estado no valido!\n"; 
		correcto= true;}
	
	}while(correcto == true);
		cout<<endl;
		cout<<setw(14)<<"DNI:         "<<setw(16)<<personas[i].dni.dni<<personas[i].dni.letra<<endl;
		
		cout<<setw(14)<<"Nombre:      "<<setw(17)<<personas[i].nombre<<endl;
		
		cout<<setw(14)<<"Apellidos:   "<<setw(17)<<personas[i].apellidos<<endl;
		
		cout<<setw(14)<<"Sexo:        "<<setw(17)<<cambiarsexo(personas, i)<<endl;
		
		cout<<setw(14)<<"Estado civil:"<<setw(17)<<cambiarestado(personas, i)<<endl<<endl;
	
	while(e<tam){
	
		escritura<<personas[e].dni.dni<<personas[e].dni.letra<<endl;
		
		escritura<<personas[e].nombre<<endl;
		
		escritura<<personas[e].apellidos<<endl;
		
		escritura<<personas[e].sexo<<endl;
		
		escritura<<personas[e].estado<<endl;
	e++;
	}
		escritura<<-1;
	
	
	escritura.close();
	}else cout<<"No se ha encontrado ese DNI en la base de datos\n";
	
	
}
void addmember(int e){
	

	int i = 0;
	ofstream escritura;
	string sexo, estado;
	bool valido=false, correcto = false;

	
		cout<<"Escriba el numero del DNI: ";
		cin>>personas[e].dni.dni;
		
		cout<<"Escriba la letra del DNI: ";
		cin>>personas[e].dni.letra;
		
		cout<<"Escriba el nombre de la persona: ";
		cin>>personas[e].nombre;
		
		/*cout<<"Apellidos: ";
		getline(cin, personas[e].apellidos);
		getline(cin, personas[e].apellidos);*/
		cout<<"Sexo: ";
	do{
			cin>>sexo;
			valido=false;
			
			
			if(sexo=="hombre")personas[e].sexo=hombre;
			else if(sexo=="mujer")personas[e].sexo=mujer;
			else if(sexo!="hombre"||sexo!="mujer") {cout<<"Sexo no valido\n";
			valido=true;
			}
	}while(valido==true);
		
		cout<<"Estado civil: ";
		getline(cin, estado);
		do{
		getline(cin, estado);
		correcto=false;
		if(estado=="soltero"||estado=="soltera")personas[e].estado=soltero;
		else if(estado=="divorciado"||estado=="divorciada")personas[e].estado=divorciado;
		else if(estado=="casado"||estado=="casada")personas[e].estado=casado;
		else if(estado=="viudo"||estado=="viuda")personas[e].estado=viudo;
		else if(estado=="con pareja")personas[e].estado=con_pareja;
		else{cout<<"Estado no valido!\n"; 
		correcto= true;}
	
	}while(correcto == true);
		
	escritura.open("input.txt");
	while(i<(e+1)){
	
		escritura<<personas[i].dni.dni<<personas[i].dni.letra<<endl;
		
		escritura<<personas[i].nombre<<endl;
		
		escritura<<personas[i].apellidos<<endl;
		
		escritura<<personas[i].sexo<<endl;
		
		escritura<<personas[i].estado<<endl;
	i++;
	}
		escritura<<-1;
	
	
	
escritura.close();






}
void ordenar(int e){
	string aux, aux1;
	int dni;
	char letra;
	tEstado estadoaux;
	tSexo sexoaux;
	for(int u = 0; u<e;u++){
	for(int i = 1; i<e;i++){
		if(personas[i].nombre<personas[i-1].nombre){
			aux = personas[i-1].nombre;
			aux1 = personas[i-1].apellidos;
			dni = personas[i-1].dni.dni;
			letra = personas[i-1].dni.letra;
			estadoaux = personas[i-1].estado;
			sexoaux = personas[i-1].sexo;
			
			personas[i-1].nombre=personas[i].nombre;
			personas[i-1].apellidos=personas[i].apellidos;
			personas[i-1].dni=personas[i].dni;
			personas[i-1].estado=personas[i].estado;
			personas[i-1].sexo=personas[i].sexo;
			
			personas[i].nombre=aux;
			personas[i].apellidos = aux1;
			personas[i].estado = estadoaux;
			personas[i].dni.dni = dni;
			personas[i].dni.letra = letra;
			personas[i].estado = estadoaux;
			personas[i].sexo = sexoaux;
			
			
		}
		
	}
	}
	
	
	
	
	
	
}
void mostrar(int e){
	
	
	
	for(int i = 0; i<e; i++){
	
		cout<<"DNI:         "<<setw(16)<<personas[i].dni.dni<<personas[i].dni.letra<<endl;
		
		cout<<"Nombre:      "<<setw(17)<<personas[i].nombre<<endl;
		
		cout<<"Apellidos:   "<<setw(17)<<personas[i].apellidos<<endl;
		
		cout<<"Sexo:        "<<setw(17)<<cambiarsexo(personas, i)<<endl;
		
		cout<<"Estado civil:"<<setw(17)<<cambiarestado(personas, i)<<endl<<endl;
	
	
	
}

	
	
}
























