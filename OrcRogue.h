#pragma once
#include "Orc.h"
#include "Rogue.h"

class OrcRogue :
    public Orc, public Rogue
{
public:
    OrcRogue(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    ~OrcRogue() override;

    void methodOfRogue() override;
};

