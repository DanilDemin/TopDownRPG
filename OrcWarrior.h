#pragma once
#include "Orc.h"
#include "Warrior.h"

class OrcWarrior :
    public Orc, public Warrior
{
public:
    OrcWarrior(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    ~OrcWarrior() override;

    void methodOfWarrior() override;
};

