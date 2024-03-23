#include <iostream>
#include <vector>
#include <cstdlib>

#include "Customer.cpp"

using namespace std;

class App
{
public:
	App() {};
	void init() {
		this->printTitle("GESTOR DE VENTAS");				
		this->printIntegrators();
	};

	void killApp() {
		run = false;
	}

	int showMenu() {
		this->clear();
		this->printTitle("MENU PRINCIPAL");
		cout << "Seleccione una opcion:" << endl << endl;
		cout << "1. Registrar Cliente" << endl;
		cout << "2. Listar Clientes" << endl;
		cout << "3. Registrar Producto" << endl;
		cout << "4. Listar Productos" << endl;
		cout << "5. Crear Pedido" << endl;
		cout << "6. Listar Pedidos" << endl;
		cout << "7. Generar Factura" << endl;
		cout << "8. Listar Facturas" << endl;
		cout << "9. Mostrar Integrantes" << endl;
		cout << "10. Salir" << endl;

		auto tempOption = 0;
		cin >> tempOption;
	
		return tempOption;
	}

	void printSeparator(int type = 0) {
		switch (type) {
		case 1: 
			cout << "---------------";
			break;
		default:
			cout << "=========================================" << endl;
		}
	}

	void printTitle(string message) {
		this->printSeparator();
		cout << "\t   " << message << endl;
		this->printSeparator();
	}

	void printIntegrators() {
		cout << endl;
		this->printSeparator(1);
		cout << "Integrantes";
		this->printSeparator(1);
		cout << endl << endl << endl;
		cout << "* Raul Espina: 30.643.473" << endl;
		cout << "* Arelenys Dávila: 00.000.000" << endl;
		cout << "Pulsar cualquier tecla para continuar..." << endl;	
		string temp;
		cin >> temp;
	}

	void clear() {
		// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
		std::cout << "\x1B[2J\x1B[H";
	}

	bool getRun() {
		return run;
	}
private:
	bool run = true;
	vector<Customers> customerList;
};
