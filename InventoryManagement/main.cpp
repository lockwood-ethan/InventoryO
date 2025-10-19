#include <iostream>
#include <limits>
#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include "sqlite_database.h"
#include "InventoryItem.h"

const int DISPLAY = 1;
const int SEARCH = 2;
const int ADD_ITEM = 3;
const int UPDATE_ITEM = 4;
const int DELETE_ITEM = 5;
const int QUIT = 6;

int requestId();
std::string requestName();
int requestQuantity();
std::string requestManufacturer();
std::string requestType();
int displayMenuOptions();
int displayUpdateOptions();
void displaySearchHeader();

int main() {
	// Create database for storing inventory items
	const char* dir = ".\\INVENTORY.db";
	sqlite3* DB;

	createDB(dir);
	createTable(dir);

	// Main UI
	int id;
	std::string searchName;
	std::string name;
	int quantity;
	std::string manufacturer;
	std::string type;
	InventoryItem inventoryItem;
	int updateChoice;
	int updateId;
	std::string property;
	std::string value;

	std::cout << "*****     Inventory Management System     *****" << std::endl;
loop_label:
	int choice = displayMenuOptions();

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Create, Read, Update, Delete inventory items
	switch (choice) {
	case DISPLAY:
		displaySearchHeader();
		displayData(dir);
		goto loop_label;
	case SEARCH:
		searchName = requestName();
		displaySearchHeader();
		searchData(dir, searchName);
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
		updateId = requestId();
		updateChoice = displayUpdateOptions();
		if (updateChoice == 1) {
			property = "NAME";
			value = requestName();
		}
		else if (updateChoice == 2) {
			property = "QUANTITY";
			value = std::to_string(requestQuantity());
		}
		else if (updateChoice == 3) {
			property = "MANUFACTURER";
			value = requestManufacturer();
		}
		else if (updateChoice == 4) {
			property = "TYPE";
			value = requestType();
		}
		else if (updateChoice == 5) {
			goto loop_label;
		}
		std::cout << property << " " << value << std::endl;
		updateData(dir, updateId, property, value);
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

int requestId() {
	int id;
	std::cout << "Enter the item ID: ";
	std::cin >> id;
	return id;
}

std::string requestName() {
	std::string name;
	do {
		std::cout << "Enter the item name: ";
		std::getline(std::cin, name);
	} while (name.length() > 20);
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
	do {
		std::cout << "Enter the manufacturer: ";
		std::getline(std::cin, manufacturer);
	} while (manufacturer.length() > 20);
	return manufacturer;
}

std::string requestType() {
	std::string type;
	do {
		std::cout << "Enter the item type: ";
		std::getline(std::cin, type);
	} while (type.length() > 20);
	return type;
}

int displayMenuOptions() {
	int choice;
	std::cout << std::endl;
	std::cin.clear();
	do {
		std::cout << "1. Display inventory" << std::endl;
		std::cout << "2. Search inventory" << std::endl;
		std::cout << "3. Add a new item to inventory" << std::endl;
		std::cout << "4. Update existing inventory item" << std::endl;
		std::cout << "5. Delete item from inventory" << std::endl;
		std::cout << "6. Quit" << std::endl;
		std::cout << "Choose an option: ";
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice < 1 && choice > 6);
	return choice;
}

int displayUpdateOptions() {
	int choice;
	std::cout << std::endl;
	std::cin.clear();
	do {
		std::cout << "1. Update Name" << std::endl;
		std::cout << "2. Update Quantity" << std::endl;
		std::cout << "3. Update Manufacturer" << std::endl;
		std::cout << "4. Update Type" << std::endl;
		std::cout << "5. Quit" << std::endl;
		std::cout << "Choose an option: ";
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice < 1 && choice > 5);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return choice;
}

void displaySearchHeader() {
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|          ID               Name               Quantity          Manufacturer           Type         |" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
}
