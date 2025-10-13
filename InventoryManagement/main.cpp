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


int main() {
	// Create database for storing inventory items
	const char* dir = ".\\INVENTORY.db";
	sqlite3* DB;

	createDB(dir);
	createTable(dir);

	// Main UI
	int choice;
	int id;
	std::string name;
	int quantity;
	std::string manufacturer;
	std::string type;

	std::cout << "*****     Inventory Management System     *****" << std::endl;
loop_label:
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
		std::cout << "Enter the item name: ";
		std::getline(std::cin, name);

		std::cout << "Enter the item quantity: ";
		std::cin >> quantity;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Enter the manufacturer: ";
		std::getline(std::cin, manufacturer);

		std::cout << "Enter the item type: ";
		std::getline(std::cin, type);

		insertData(dir, name, quantity, manufacturer, type);
		goto loop_label;
	case UPDATE_ITEM:
		std::cout << "Enter the name of the item you are updating: ";
		std::getline(std::cin, name);

		std::cout << "Enter the new quantity of the item: ";
		std::cin >> quantity;

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