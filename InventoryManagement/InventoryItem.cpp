#include "InventoryItem.h"
#include <iostream>
#include <string>

class InventoryItem {
public:
	int id;
	std::string name;
	int quantity;
	std::string manufacturer;
	std::string type;

	InventoryItem(int id, std::string name, int quantity, std::string manufacturer, std::string type) {
		this->id = id;
		this->name = name;
		this->quantity = quantity;
		this->manufacturer = manufacturer;
		this->type = type;
	}

	int getId() {
		return this->id;
	}

	void setId(int id) {
		this->id = id;
	}

	std::string getName() {
		return this->name;
	}

	void setName(std::string name) {
		this->name = name;
	}

	int getQuantity() {
		return this->quantity;
	}

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}

	std::string getManufacturer() {
		return this->manufacturer;
	}

	void setManufacturer(std::string manufacturer) {
		this->manufacturer = manufacturer;
	}

	std::string getType() {
		return this->type;
	}

	void setType(std::string type) {
		this->type = type;
	}
};