#pragma once

class InventoryItem {
	int getId();
	void setId(int id);
	std::string getName();
	void setName(std::string);
	int getQuantity();
	void setQuantity(int quantity);
	std::string getManufacturer();
	void setManufacturer(std::string manufacturer);
	std::string getType();
	void setType(std::string type);
};