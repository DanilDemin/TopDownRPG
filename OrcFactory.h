#pragma once
#include "EnemyFactory.h"


class OrcFactory :
    public EnemyFactory
{
private:

public:
    OrcFactory(const std::map<std::string, sf::Texture>& textures);
    ~OrcFactory() override;

    Enemy* createBase(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Warrior* createWarrior(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Mage* createMage(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Rogue* createRogue(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
};

