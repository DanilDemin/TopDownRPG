#pragma once
#include "Skeleton.h"
#include "Mage.h"

class SkeletonMage :
    public Skeleton, public Mage
{
public:
    SkeletonMage(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile, Entity& player);
    virtual ~SkeletonMage();
    
    void methodOfMage() override;
};

