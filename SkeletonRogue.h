#pragma once
#include "Skeleton.h"
#include "Rogue.h"

class SkeletonRogue :
    public Skeleton, public Rogue
{
public:
    SkeletonRogue(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    ~SkeletonRogue() override;

    void methodOfRogue() override;
};

