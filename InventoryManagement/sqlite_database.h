#pragma once
#include "InventoryItem.h"

int createDB(const char* s);
int createTable(const char* s);
int insertData(const char* s, InventoryItem inventoryItem);
int displayData(const char* s);
int callback(void* NotUsed, int argc, char** argv, char** azColName);
int deleteData(const char* s, int id);
int updateData(const char* s, int id, std::string property, std::string value);
int searchData(const char* s, std::string name);
