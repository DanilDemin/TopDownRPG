#pragma once

#include "Item.h"

//class Item;

class Inventory
{
private:
	Item** itemArray;
	unsigned nroItems;
	unsigned capasity;

	//Private functions
	void initialize();
	void nullify(const unsigned from = 0);
	void freeMemory();

public:
	//Con / Des
	Inventory(unsigned capasity);
	virtual ~Inventory();

	//Accessors
	const unsigned& size() const;
	const unsigned& maxSize() const;


	//Modifires


	//Functions
	void clear();
	const bool empty() const;

	const bool add(Item* item);
	const bool remove(const unsigned index);

	const bool saveToFile(const std::string file_name);
	const bool loadToFile(const std::string file_name);
	
};

