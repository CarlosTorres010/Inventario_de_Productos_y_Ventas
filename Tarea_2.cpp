/* 
2. Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar
productos, as� como gestionar las ventas.
Requisitos:
� Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
� Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad
(entero), precioTotal (flotante).
� Implementa un men� con las siguientes opciones:
A: Registrar un nuevo producto.
B: Listar los productos registrados.
C: Buscar un producto por nombre.
D: Actualizar los datos de un producto.
E: Eliminar un producto.
F: Registrar una venta.
G: Listar las ventas realizadas.
H: Calcular el total de ventas realizadas.
S: Salir del programa.
� El men� debe estar ciclado y permitir volver al men� principal despu�s de cada opci�n.
*/

#include <iostream>
#include <string>
using namespace std;

const int limite_productos = 50; 

struct Producto{
  string nombre;
  float precio;
};
    
struct Venta{
   int idVenta;
   string producto;
   int cantidad;
   float precioTotal;
};

void registrarProducto(Producto articulo[], int &cantidadProductos){
	if(cantidadProductos>=limite_productos){
		cout<<"Ya no queda espacio suficiente para registrar mas productos. \n"; 
	}
	
	Producto art;
	cout<<"Ingrese el nombre del producto: ";
	cin.ignore();
	getline(cin,art.nombre); 
	cout<<"Ingrese el precio que tendra el producto: "; 
	cin>>art.precio; 
	cout<<"\n"; 
	
	articulo[cantidadProductos] = art; 
	cantidadProductos++; 
	
	cout<<"Producto registrado satisfacoriamente! \n";	 
}

void listarProductos(Producto articulo[], int cantidadProductos){
	if(cantidadProductos == 0){
		cout<<"No se han registrado productos hasta el momento. \n";
	}
	else{
		cout<<"Listando productos...\n"<<endl;	
 	   for(int i=0; i<cantidadProductos; ++i){
 	   	cout<<"Producto: "<<i+1<<" | "<<" -> "<<"Indice: "<<i<<endl; 
 		cout<<"Nombre del producto: "<<articulo[i].nombre<<endl;
 		cout<<"Precio: "<<articulo[i].precio<<endl;
		cout<<"\n";
		 
 	   }
	}
}

void buscarProducto(Producto articulo[], int cantidadProductos, const string& nombre){ 
        
		bool confirmacion = false; 
        
        cout<<"BUSCANDO EL PRODUCTO...\n"; 
	 	for(int i=0; i<cantidadProductos; ++i){
	 		if(articulo[i].nombre == nombre){
	 			
	 			cout<<"Producto: "<<i+1<<" | "<<" -> "<<"INDICE: "<<i<<endl; 
 				cout<<"Nombre del producto: "<<articulo[i].nombre<<endl;
 				cout<<"Precio: "<<articulo[i].precio<<endl;
				cout<<"\n";
				
				confirmacion = true; 
				
		 		break; 
 	        }
         }
 	        if (confirmacion == false){
    	        cout<<"\nEl contacto con el nombre '"<<nombre<<"' no fue encontrado.\n";
   		    }
}

// void actualizarProducto
int main(){
	Producto articulo[limite_productos];
 	Venta    vent[limite_productos];
  	int opcion; 
   	int cantidadProductos = 0; 
      
      do{
		    cout<<"\n"; 
			cout<<"Buenos dias, se encuentra en el programa de inventarios de productos y ventas" <<endl; 
			cout<<endl<<"Digite una de las siguientes opciones: "<<endl; 
			cout<<"[1] Registrar un producto. "<<endl; 
			cout<<"[2] Listar los productos registrados. "<<endl; 
			cout<<"[3] Buscar algun producto por su nombre. "<<endl; 
	  		cout<<"[4] Actualizar los datos de un producto. "<<endl; 
		   	cout<<"[5] Eliminar un producto. "<<endl;
		   	cout<<"[6] Registrar una venta. "<<endl; 
		   	cout<<"[7] Listar las ventas realizadas. "<<endl; 
		   	cout<<"[8] Calcular el total de ventas realizadas. "<<endl; 
		   	cout<<"[9] Salir del programa. ";
		   	cout<<endl<<"Digite el numero de la opcion: ";
  	   		cin>>opcion;
  	   		cout<<"\n";
          
        switch(opcion){
   		        case 1: 
       	        registrarProducto(articulo, cantidadProductos); 
   		        break; 
   		        case 2: 
	      	    listarProductos(articulo, cantidadProductos); 
	      	    break;
	      	    case 3: {
   		         string nombre; 
	      	     cout<<"\nDigite el nombre del producto a buscar: "; 
	      	     cin.ignore(); 
	      	     getline(cin, nombre); 
	      	     
       	         buscarProducto(articulo, cantidadProductos, nombre); 
   		        break; 
   		        } 
   		        //case 4: 
   		      
   		      
   		        default: break; 
          	}
       }while(opcion != 9);
      
  return 0;
}
