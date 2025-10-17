#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include "sqlite_database.h"
#include "InventoryItem.h"

const int DISPLAY = 1;
const int ADD_ITEM = 2;
const int UPDATE_ITEM = 3;
const int DELETE_ITEM = 4;
const int QUIT = 5;

std::string requestName();
int requestQuantity();
std::string requestManufacturer();
std::string requestType();
int displayMenuOptions();

int main() {
	// Create database for storing inventory items
	const char* dir = ".\\INVENTORY.db";
	sqlite3* DB;

	createDB(dir);
	createTable(dir);

	// Main UI
	int id;
	std::string name;
	int quantity;
	std::string manufacturer;
	std::string type;
	InventoryItem inventoryItem;

	std::cout << "*****     Inventory Management System     *****" << std::endl;
loop_label:
	int choice = displayMenuOptions();

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Create, Read, Update, Delete inventory items
	switch (choice) {
	case DISPLAY:
		std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|          ID               Name               Quantity          Manufacturer           Type         |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
		selectData(dir);
		goto loop_label;
	case ADD_ITEM:
		// Set InventoryItem properties and insert it into the database
		inventoryItem.setName(requestName());

		inventoryItem.setQuantity(requestQuantity());
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		inventoryItem.setManufacturer(requestManufacturer());

		inventoryItem.setType(requestType());

		insertData(dir, inventoryItem);
		goto loop_label;
	case UPDATE_ITEM:
		name = requestName();

		quantity = requestQuantity();

		updateData(dir, name, quantity);
		goto loop_label;
	case DELETE_ITEM:
		std::cout << "Enter the ID # of the item to delete: ";
		std::cin >> id;
		deleteData(dir, id);
		goto loop_label;
	case QUIT:
		break;
	}

	return 0;
}

std::string requestName() {
	std::string name;
	std::cout << "Enter the item name: ";
	std::getline(std::cin, name);
	return name;
}

int requestQuantity() {
	int quantity;
	std::cout << "Enter the item quantity: ";
	std::cin >> quantity;
	return quantity;
}

std::string requestManufacturer() {
	std::string manufacturer;
	std::cout << "Enter the manufacturer: ";
	std::getline(std::cin, manufacturer);
	return manufacturer;
}

std::string requestType() {
	std::string type;
	std::cout << "Enter the item type: ";
	std::getline(std::cin, type);
	return type;
}

int displayMenuOptions() {
	int choice;
	std::cout << std::endl;
	std::cin.clear();
	do {
		std::cout << "1. Display inventory" << std::endl;
		std::cout << "2. Add a new item to inventory" << std::endl;
		std::cout << "3. Update quantity of existing inventory item" << std::endl;
		std::cout << "4. Delete item from inventory" << std::endl;
		std::cout << "5. Quit" << std::endl;
		std::cout << "Choose an option: ";
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice < 1 && choice > 5);
	return choice;
}