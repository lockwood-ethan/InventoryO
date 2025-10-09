#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include "sqlite_database.h"

int main() {
	// Create database for storing inventory items
	const char* dir = "C:\\Users\\lockw\\source\\repos\\InventoryManagement\\InventoryManagement\\INVENTORY.db";
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
	case 1:
		selectData(dir);
		goto loop_label;
	case 2:
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
	case 3:
		std::cout << "Enter the name of the item you are updating: ";
		std::getline(std::cin, name);

		std::cout << "Enter the new quantity of the item: ";
		std::cin >> quantity;

		updateData(dir, name, quantity);
		goto loop_label;
	case 4:
		std::cout << "Enter the ID # of the item to delete: ";
		std::cin >> id;
		deleteData(dir, id);
		goto loop_label;
	case 5:
		break;
	}

	return 0;
}