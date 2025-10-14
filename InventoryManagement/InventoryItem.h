#include <iostream>
#include <string>
#pragma once

class InventoryItem {
private:
	int mId;
	std::string mName;
	int mQuantity;
	std::string mManufacturer;
	std::string mType;
public:
	InventoryItem();
	InventoryItem(std::string name, int quantity, std::string manufacturer, std::string type);
	InventoryItem(int id, std::string name, int quantity, std::string manufacturer, std::string type);
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