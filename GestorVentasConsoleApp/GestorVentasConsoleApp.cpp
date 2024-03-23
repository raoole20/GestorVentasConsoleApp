#include <iostream>
#include "App.cpp"
/*
* •	Crear una aplicación que gestione las ventas de una empresa.
•	Implement
•	Utilizar clases para representar productos, clientes, pedidos y facturas.
•	Implementar métodos para gestionar las operaciones CRUD sobre los datos.ar funcionalidades como: registro de productos, registro de clientes, creación de pedidos, generación de facturas, control de stock.
*/

int main()
{
	App app;
	app.init();

	while (app.getRun())
	{
		int option = app.showMenu();
		switch (option)
		{
			case 9:
				app.clear();
				app.init();
				break;
			case 10:
				app.killApp();
				break;
			default:	
				app.clear();
				cout << "Opcion no valida, Intente nuevamente" << endl;	
				cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
				string temp;
				cin >> temp;
				break;
		}
	}

	return 0;
}
