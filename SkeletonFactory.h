#pragma once
#include "EnemyFactory.h"
class SkeletonFactory :
    public EnemyFactory
{
private:

public:
    SkeletonFactory(const std::map<std::string, sf::Texture>& textures);
    ~SkeletonFactory() override;

    Enemy* createBase(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Warrior* createWarrior(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Mage* createMage(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
    Rogue* createRogue(float x, float y, EnemySpawnerTile& enemy_spawner_tile, Entity& player) override;
};

