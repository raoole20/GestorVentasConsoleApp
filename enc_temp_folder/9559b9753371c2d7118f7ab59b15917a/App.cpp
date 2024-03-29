#include <iostream>
#include <vector>
#include <cstdlib>

#include "Customer.cpp"
#include "Product.cpp"

using namespace std;

class App
{
public:
	App() {
		Customers customerInstace("", "", "", "");
		this->customerService = customerInstace;

		Product productInstance("", "", "", 0, 0, false, 0);
		this->productService = productInstance;
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
		cout << "2. Modulo de Producto" << endl;
		cout << "-. Realizar Venta" << endl; // TODO: implementar
		//cout << "5. Crear Pedido" << endl;
		//cout << "6. Listar Pedidos" << endl;
		//cout << "7. Generar Factura" << endl;
		//cout << "8. Listar Facturas" << endl;
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
			cout << "5. Buscar Cliente por ID" << endl;
			cout << "6. Volver al menu principal" << endl;

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
				case 4: {
					this->clear();
					this->printTitle("Eliminar Cliente");
					cout << "Ingrese el ID del cliente a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					auto index = 0;
					auto countIteration = 0;
					for (auto c : this->customerList) {
						if (id == c.getId()) {
							cout << "Detalles del cliente: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
							index= countIteration;
						}
						countIteration++;
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Cliente no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					else {
						cout << "Desea eliminar al Cliente? " << endl;
						cout << "(En caso de no escojer una opcion valida el usuario será eliminado)" << endl << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						int deleteOption;
						cin >> deleteOption;

						switch (deleteOption)
						{
							case 2:
								cout << "el usuario no ha sido eliminado" << endl;
								break;
							case 1:	
							default:
								this->customerList.erase(std::next(customerList.begin(), index));
								cout << "el usuario ha sido eliminado" << endl;
								this->printSeparator(1);
								break;
						}

					}
					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;

				}
					break;
				case 5: {
					this->clear();
					this->printTitle("Buscar Cliente");
					cout << "Ingrese el ID del cliente a buscar: " << endl;
					string id;
					cin >> id;

					auto find = false;
					for (auto c : this->customerList) {
						if (id == c.getId()) {	
							cout << "Detalles del cliente: " << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							c.displayUserInformation();
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
							find = true;
						}	
					}

					if (!find) {
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl << endl << endl;
						cout << "Cliente no encontrado" << endl;
						cout << endl << endl << endl;
						this->printSeparator(1);
						this->printSeparator(1);
						cout << endl;
					}
					cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
					string temp;
					cin >> temp;
						
				}
					  break;
				case 6:
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

	void productMenu() {
		auto continueProcess = true;

		do {
			this->clear();
			this->printTitle("MENU DE PRODUCTOS");
			cout << "Seleccione una opcion:" << endl << endl;
			cout << "1. Registrar Producto" << endl;
			cout << "2. Listar Productos" << endl;
			cout << "3. Modificar Producto" << endl;
			cout << "4. Eliminar Producto" << endl;
			cout << "5. Buscar Producto por ID" << endl;
			cout << "6. Volver al menu principal" << endl;

			int option;
			cin >> option;
			switch (option)
			{
				case 1: {
						this->clear();
						this->printTitle("REGISTRO De Productos");
						cout << "Por favor ingrese los datos del producto";
						cout << endl << endl << endl;
						auto producto = this->productService.createNewProduct();
						cout << endl << endl << endl;

						this->printTitle("Producto");
						cout << endl;
						cout << "detalles del producto:";
						cout << endl << endl << endl;
						producto.displayProductInformation();
						cout << endl << endl << endl;

						cout << "Desea guardar el Producto" << endl;
						cout << "1. Si" << endl;
						cout << "2. No" << endl;
						string temp;
						cin >> temp;

						if (temp == "1") {
							this->productList.push_back(producto);
							cout << "Producto guardado con exito" << endl;
						}
						else {
							cout << "Producto no guardado" << endl;
						}

						cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
						cin >> temp;
					}
					break;
				case 2: {
						this->clear();
						this->printTitle("Lista de Productos");
						cout << "Lista de productos registrados" << endl;
						

						if (this->productList.size() == 0) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "No hay productos registrados" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						else {
							for (auto p : this->productList) {
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
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
				case 3:
					break;
				case 4:
					break;
				case 5:
					{
						this->clear();
						this->printTitle("Buscar Producto");
						cout << "Ingrese el ID del producto a buscar: " << endl;
						string id;
						cin >> id;

						auto find = false;
						for (auto p : this->productList) {
							if (id == p.getId()) {
								cout << "Detalles del producto: " << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl << endl << endl;
								p.displayProductInformation();
								cout << endl << endl << endl;
								this->printSeparator(1);
								this->printSeparator(1);
								cout << endl;
								find = true;
							}
						}

						if (!find) {
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl << endl << endl;
							cout << "Producto no encontrado" << endl;
							cout << endl << endl << endl;
							this->printSeparator(1);
							this->printSeparator(1);
							cout << endl;
						}
						cout << "Para continuar presione cualquier tecla y luego Enter" << endl;
						string temp;
						cin >> temp;	
					}
					break;
				case 6:
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
		} while (continueProcess);
	}

	bool getRun() {
		return this->run;
	}
private:
	bool run = true;
	vector<Customers> customerList;
	vector<Product> productList;
	Customers customerService;
	Product productService;
};
