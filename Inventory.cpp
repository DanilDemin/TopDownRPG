#include "stdafx.h"
#include "Inventory.h"

//Private functions
void Inventory::initialize()
{
	/*this->nroItems = 0;
	this->itemArray = new Item * [this->capasity];*/
	
	this->nullify();

}

 

void Inventory::nullify(const unsigned from)
{
	for (size_t i = from; i < this->capasity; i++)
	{
		this->itemArray[i]= nullptr;
	}
}

void Inventory::freeMemory()
{
	for (size_t i = 0; i < this->nroItems; i++)
	{
		delete this->itemArray[i];
	}

	delete[] this->itemArray;
}



//Con / Des
Inventory::Inventory(unsigned capasity)
	: itemArray(new Item* [capasity])
	, nroItems(0)
	, capasity(capasity)
{
	this->initialize();

}

Inventory::~Inventory()
{
	this->freeMemory();
}

const unsigned& Inventory::size() const
{
	return this->nroItems;
}

const unsigned& Inventory::maxSize() const
{
	return this->capasity;
}


//Functions
void Inventory::clear()
{
	for (size_t i = 0; i < this->nroItems; i++)
	{
		delete this->itemArray[i];
	}
	this->nroItems = 0;
	this->nullify();
}

const bool Inventory::empty() const
{
	return this->nroItems == 0;
}

const bool Inventory::add(Item* item)
{
	if (this->nroItems < this->capasity)
	{
		this->itemArray[this->nroItems++] = item->clone();

		return true;
	}

	return false;
}

const bool Inventory::remove(const unsigned index)
{

	if (this->nroItems > 0)
	{
		if (index < 0 || index >= this->capasity) { return false; }

		delete this->itemArray[index];
		this->itemArray[index] = nullptr;

		this->nroItems--;

		return true;
	}

	return false;
}

const bool Inventory::saveToFile(const std::string file_name)
{
	return false;
}

const bool Inventory::loadToFile(const std::string file_name)
{
	return false;
}
