#include <sqlite3.h>
#include <iostream>
#include <stdio.h>
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