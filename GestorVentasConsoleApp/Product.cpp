#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "UUID.cpp"
using namespace std;

class Product
{
public:	
	Product(string id = "", string name = "", string description = "", float price = 0, int stock = 0, bool isOffer = false, float offerPrice = 0) {
		this->id = id;
		this->name = name;
		this->description = description;
		this->price = price;
		this->stock = stock;
		this->isOffer = isOffer;
		this->offerPrice = offerPrice;
	}

	void displayProductInformation() {
		cout << "ID del producto: " << this->id << endl;
		cout << "Nombre del producto: " << this->name << endl;
		cout << "Descripcion del producto: " << this->description << endl;
		cout << "Precio del producto: " << this->price << endl;
		cout << "Stock del producto: " << this->stock << endl;
		cout << "Oferta del producto: " << this->isOffer << endl;
		cout << "Precio de oferta del producto: " << this->offerPrice << endl;
	};

	Product createNewProduct() {
		string colums[5] = { "Nombre", "Descripcion", "Precio", "Stock", "Oferta" };
		Product newProduct("", "", "", 0, 0, false, 0);
		Identify id;
		newProduct.setId(to_string(id._id));
		for (auto colum : colums) {
			auto valid = false;
			do {
				if (colum != "Oferta") {
					cout << "Ingrese el " << colum << " del producto: ";
					string value;
					cin >> value;

					if (colum == "Nombre") {
						newProduct.setName(value);
					}
					else if (colum == "Descripcion") {
						newProduct.setDescription(value);
					}
					else if (colum == "Precio") {
						auto price = stof(value);
						newProduct.setPrice(price);
					}
					else {
						newProduct.setStock(stoi(value));
					}

					valid = true;
				}
				else {
					cout << endl << endl << endl;
					cout << "El producto tiene oferta? Si/No: " << endl;
					cout << "Cualquier otra respuesta sera considerada como 'No'" << endl;
					string offer;
					cin >> offer;
					if (offer == "Si" || offer == "si") {
						newProduct.setIsOffer(true);
						cout << "Ingrese el precio de oferta del producto" << endl;
						string offerPrice;
						cin >> offerPrice;
						auto offerPriceParser = stof(offerPrice);
						newProduct.setOfferPrice(offerPriceParser);
					}	
					valid = true;
				}
			} while (!valid);
		}
		return newProduct;
	}

	void displayProductDetails() {
		cout << "ID del producto: " << this->id << endl;
		cout << "Nombre del producto: " << this->name << endl;
		cout << "Descripcion del producto: " << this->description << endl;
		cout << "Precio del producto: " << this->price << endl;
		cout << "Stock del producto: " << this->stock << endl;
		cout << "Oferta del producto: " << this->isOffer << endl;
		cout << "Precio de oferta del producto: " << this->offerPrice << endl;
	}		

	string getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getDescription() {
		return this->description;
	}
	float getPrice() {
		return this->price;
	}
	int getStock() {
		return this->stock;
	}
	bool getIsOffer() {
		return this->isOffer;
	}
	float getOfferPrice() {
		return this->offerPrice;
	}
	void setName(string name) {
		this->name = name;
	}
	void setDescription(string description) {
		this->description = description;
	}
	void setPrice(float price) {
		this->price = price;
	}
	void setStock(int stock) {
		this->stock = stock;
	}

	void setIsOffer(bool isOffer) {
		this->isOffer = isOffer;
	}

	void setOfferPrice(float offerPrice) {
		this->offerPrice = offerPrice;
	}

	void setId(string id) {
		this->id = id;
	}

private:
	string id;
	string name;
	string description;
	float price;
	int stock;
	bool isOffer;
	float offerPrice;
};