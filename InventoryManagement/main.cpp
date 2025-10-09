#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include "sqlite_database.h"

int main() {
	// Create database for storing inventory items
	const char* dir = "C:\\Users\\lockw\\source\\repos\\InventoryManagement\\InventoryManagement\\INVENTORY.db";
	sqlite3* DB;

	createDB(dir);
	createTable(dir);

	// Main UI
	int choice;

	std::cout << "*****     Inventory Management System     *****" << std::endl;
	
	std::cout << "1. Display inventory" << std::endl;
	std::cout << "2. Add a new item to inventory" << std::endl;
	std::cout << "3. Update quantity of existing inventory item" << std::endl;
	std::cout << "4. Delete item from inventory" << std::endl;
	std::cout << "Choose an option:";
	std::cin >> choice;

	return 0;
}