#include "stdafx.h"
#include "SkillComponent.h"

SkillComponent::SkillComponent()
{
	this->skills.push_back(Skill(SKILLS::HEALTH));
	this->skills.push_back(Skill(SKILLS::ATTACK));
	this->skills.push_back(Skill(SKILLS::ACCURACY));
	this->skills.push_back(Skill(SKILLS::ENDURANCE));
}

SkillComponent::~SkillComponent()
{

}

const int SkillComponent::getSkill(const int skill) const
{
	if (this->skills.empty() || skill < 0 || skill >= this->skills.size())
		throw("ERROR::SKILLCOMPONENT::GETSKILL DOES NOT EXIST" + skill);
	else
		return this->skills[skill].getLevel();
}

const void SkillComponent::gainEXP(const int skill, const int exp)
{
	if (this->skills.empty() || skill < 0 || skill >= this->skills.size())
		throw("ERROR::SKILLCOMPONENT::GETEXP DOES NOT EXIST" + skill);
	else
	{
		this->skills[skill].gainExp(exp);
	}
		 
}
