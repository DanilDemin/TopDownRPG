#pragma once
#include "Orc.h"
#include "Mage.h"

class OrcMage :
    public Orc, public Mage
{
public:
    OrcMage(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    ~OrcMage() override;

    void methodOfMage() override;
};

