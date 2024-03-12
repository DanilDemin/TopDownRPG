#include "stdafx.h"
#include "Item.h"

void Item::initVariables()
{

}

//Con / Des
Item::Item(unsigned level, unsigned value)
	: type(ItemTypes::IT_DEFAULT)
	, level(level)
	, value(value)
{
	this->initVariables();
}

Item::~Item()
{

}
