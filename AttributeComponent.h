#pragma once


class AttributeComponent
{
private:
public:
	//Leveling
	int level;
	int exp;
	int expNext;
	int attributePoints;

	//Attributes
	int vitality;
	int strength;
	int dexterity;
	int agility;
	int intelligence;

	//Stats
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;
	


	//Constructor Destructor
	AttributeComponent(int level);
	virtual ~AttributeComponent();


	//Functions
	std::string debugPrint() const;


	void loseHp(const int hp);
	void gainHp(const int hp);
	void loseEXP(const int exp);
	void gainExp(const int exp);

	const bool isDead() const;
	
	void updateStats(const bool reset);
	void updateLevel();


	void update();
};

