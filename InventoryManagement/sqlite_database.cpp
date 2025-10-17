#include <sqlite3.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "sqlite_database.h"
#include "InventoryItem.h"

int createDB(const char* s) {
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB);

	return 0;
}

int createTable(const char* s) {
	sqlite3* DB;

	std::string sql = "CREATE TABLE IF NOT EXISTS INVENTORY("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME		TEXT NOT NULL, "
		"QUANTITY	INT NOT NULL, "
		"MANUFACTURER TEXT, "
		"TYPE		TEXT NOT NULL);";

	try {
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			std::cerr << "Error Creating Table" << std::endl;
			sqlite3_free(messageError);
		}
		else {
			std::cout << "Table Created Successfully" << std::endl;
			sqlite3_close(DB);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what();
	}

	return 0;
}

int insertData(const char* s, InventoryItem inventoryItem) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "INSERT INTO INVENTORY (NAME, QUANTITY, MANUFACTURER, TYPE) VALUES('" + inventoryItem.getName() + "', '" + std::to_string(inventoryItem.getQuantity()) + "', '" + inventoryItem.getManufacturer() + "', '" + inventoryItem.getType() + "');";
	
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Inserting Data" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		std::cout << "Records Created Successfully!" << std::endl;
	}

	return 0;
}

int updateData(const char* s, int id, int quantity) {
	/*sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "UPDATE INVENTORY SET QUANTITY = '" + std::to_string(quantity) + "' WHERE ID = '" + std::to_string(id) + "';";

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Updating Item" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		std::cout << "Item Updated Successfully!" << std::endl;
	}*/
	return 0;
}

int displayData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "SELECT * FROM INVENTORY;";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int deleteData(const char* s, int id) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "DELETE FROM INVENTORY WHERE ID='" + std::to_string(id) + "';";
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Deleting Item" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		std::cout << "Item Deleted Successfully!" << std::endl;
	}
	return 0;
}

int searchData(const char* s, std::string name) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "SELECT * FROM INVENTORY WHERE NAME='" + name + "';";
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Item Not Found" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		std::cout << "Item Found!" << std::endl;
	}

	return 0;
}

int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	std::cout << '|';
	for (int i = 0; i < argc; i++) {
		int subtractSpaces1 = strlen(argv[i]) / 2;
		double subtractSpaces2 = strlen(argv[i]) / 2.0;
		subtractSpaces2 = ceil(subtractSpaces2);
		std::cout << std::string(10 - subtractSpaces1, ' ') + argv[i] + std::string(10 - subtractSpaces2, ' ');
	}
	std::cout << '|';
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;

	return 0;
}


