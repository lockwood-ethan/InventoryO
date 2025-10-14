#include "InventoryItem.h"
#include <iostream>
#include <string>

InventoryItem::InventoryItem() {}

InventoryItem::InventoryItem(std::string name, int quantity, std::string manufacturer, std::string type) {
	mName = name;
	mQuantity = quantity;
	mManufacturer = manufacturer;
	mType = type;
}

InventoryItem::InventoryItem(int id, std::string name, int quantity, std::string manufacturer, std::string type) {
	mId = id;
	mName = name;
	mQuantity = quantity;
	mManufacturer = manufacturer;
	mType = type;
}

	int InventoryItem::getId() {
		return mId;
	}

	void InventoryItem::setId(int id) {
		mId = id;
	}

	std::string InventoryItem::getName() {
		return mName;
	}

	void InventoryItem::setName(std::string name) {
		mName = name;
	}

	int InventoryItem::getQuantity() {
		return mQuantity;
	}

	void InventoryItem::setQuantity(int quantity) {
		mQuantity = quantity;
	}

	std::string InventoryItem::getManufacturer() {
		return mManufacturer;
	}

	void InventoryItem::setManufacturer(std::string manufacturer) {
		mManufacturer = manufacturer;
	}

	std::string InventoryItem::getType() {
		return mType;
	}

	void InventoryItem::setType(std::string type) {
		mType = type;
	}