#pragma once
#include "Skeleton.h"
#include "Warrior.h"


class SkeletonWarrior :
    public Skeleton, public Warrior
{
private:
public:
    SkeletonWarrior(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    ~SkeletonWarrior() override;

    void methodOfWarrior() override;
};

