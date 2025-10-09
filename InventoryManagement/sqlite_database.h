#pragma once

int createDB(const char* s);
int createTable(const char* s);
int insertData(const char* s, std::string name, int quantity, std::string manufacturer, std::string type);
int selectData(const char* s);
int callback(void* NotUsed, int argc, char** argv, char** azColName);
int deleteData(const char* s, int id);
int updateData(const char* s, std::string name, int quantity);
