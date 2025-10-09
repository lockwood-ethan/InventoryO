#include <sqlite3.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "sqlite_database.h"

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

int insertData(const char* s, std::string name, int quantity, std::string manufacturer, std::string type) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "INSERT INTO INVENTORY (NAME, QUANTITY, MANUFACTURER, TYPE) VALUES('" + name + "', '" + std::to_string(quantity) + "', '" + manufacturer + "', '" + type + "');";
	
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

int updateData(const char* s, std::string name, int quantity) {
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "UPDATE INVENTORY SET QUANTITY = '" + std::to_string(quantity) + "' WHERE NAME = '" + name + "';";

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Updating Quantity" << std::endl;
		sqlite3_free(messageError);
	}
	else {
		std::cout << name << " Updated Successfully!" << std::endl;
	}
	return 0;
}

int selectData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "SELECT * FROM INVENTORY;";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int deleteData(const char* s, int id) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	std::string sql = "DELETE FROM INVENTORY WHERE ID='" + std::to_string(id) + "';";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	for (int i = 0; i < argc; i++) {
		std::cout << azColName[i] << ": " << argv[i] << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
