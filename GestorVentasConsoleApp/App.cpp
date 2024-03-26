#include <iostream>
#include <vector>
#include <cstdlib>

#include "Customer.cpp"

using namespace std;

class App
{
public:
	App() {
		Customers customerInstace("", "", "", "");
		this->customerService = customerInstace;
	};
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
		cout << "1. Modulo de Clientes" << endl;
		//cout << "3. Registrar Producto" << endl;
		//cout << "4. Listar Productos" << endl;
		//cout << "5. Crear Pedido" << endl;
		//cout << "6. Listar Pedidos" << endl;
		//cout << "7. Generar Factura" << endl;
		//cout << "8. Listar Facturas" << endl;
		//cout << "9. Mostrar Integrantes" << endl;
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
		std::cout << "\x1B[2J\x1B[H";
	}

	void customerMenu() {
		auto continueProcess = true;
		while (continueProcess) {
			this->clear();
			this->printTitle("MENU DE CLIENTES");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Registrar Cliente" << endl;
			cout << "2. Listar Clientes" << endl;
			cout << "3. Modificar Cliente" << endl;
			cout << "4. Eliminar Cliente" << endl;
			cout << "5. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1: {
					this->clear();
					this->printTitle("REGISTRO DE CLIENTES");
					cout << "Por favor ingrese los datos del cliente";
					cout << endl << endl << endl;
					auto customer = customerService.createNewCustomer();
					cout << endl << endl << endl;

					this->printTitle("Cliente");
					cout << endl;
					cout << "detalles del usuario:";
					cout << endl << endl << endl;
					customer.displayUserInformation();
					cout << endl << endl << endl;

					cout << "Desea guardar al Cliente" << endl;
					cout << "1. Si" << endl;
					cout << "2. No" << endl;
					string temp;
					cin >> temp;

					if (temp == "1") {
						this->customerList.push_back(customer);
						cout << "Cliente guardado con exito" << endl;
					}
					else {
						cout << "Cliente no guardado" << endl;
					}

					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					cin >> temp;
				}
				  break;
				case 2: {
					this->clear();
					this->printTitle("Lista Cliente");
					cout << "Lista de clientes registrados" << endl;

					if (customerList.size() == 0) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "No hay clientes registrados" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						for (auto c : this->customerList) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
					}


					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp; 
					cin >> temp;
				}
					  break;
				case 3: {
					this->clear();
					this->printTitle("Modificar Cliente");
					cout << "Ingrese el ID del cliente a modificar" << endl;
					string id;
					cin >> id;

					auto customerFound = false;
					for (auto c : this->customerList) {
						if (c.getId() == id) {
							customerFound = true;
							this->printTitle("Cliente");
							cout << endl;
							cout << "detalles del usuario:";
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;

							cout << "Desea modificar al Cliente" << endl;
							cout << "1. Si" << endl;
							cout << "2. No" << endl;
							string temp;
							cin >> temp;

							if (temp == "1") {	
								c.modifiCustomer();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								cout << "Cliente modificado con exito: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl;

								c.displayUserInformation();
							}
							else {
								cout << "Cliente no modificado" << endl;
							}
						}
					}

					if (!customerFound) {
						cout << "Cliente no encontrado" << endl;
					}

					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
				}
					  break;
				case 5:
					continueProcess = false;
					break;
				default:
					this->clear();
					cout << "Opcion no valida, Intente nuevamente" << endl;
					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
					break;
			}
		}
	}

	bool getRun() {
		return this->run;
	}
private:
	bool run = true;
	vector<Customers> customerList;
	Customers customerService;
};
