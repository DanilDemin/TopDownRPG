#pragma once

enum ItemTypes
{
	IT_DEFAULT = 0,
	IT_RANGEDWEAPON,
	IT_MELEEWEAPON
};

enum ItemRarities
{
	COMMON = 0,
	UNCOMON,
	RARE,
	EPIC,
	LEGENGARY,
	MYTHIC
};

class Item
{
private:
	void initVariables();

protected:
	//Variables
	short unsigned type;
	unsigned level;
	unsigned value;

public:
	//Con / Des
	Item(unsigned level, unsigned value);
	virtual ~Item();

	//Functions
	virtual Item* clone() = 0;

};

