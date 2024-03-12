#pragma once
#include "Entity.h"
#include "EnemySpawnerTile.h"

class Entity;
class EnemySpawnerTile;


class Enemy :
    public Entity
{
private:
    //Variables
   /*float scale;*/

    EnemySpawnerTile& enemySpawnerTile;
    unsigned gainExp;

    
    //Initializer functions
    virtual void initVariavles() = 0;
    virtual void initAnimation() = 0;


public:
    //Con / Des
    Enemy(EnemySpawnerTile& enemy_spawner_tile);
    virtual ~Enemy() override;

    //Accessors
    virtual const AttributeComponent* getAttributeComp() const;
    const unsigned& getGainExp() const;

    EnemySpawnerTile& getEnemySpawnerTile();



    //Functions
    virtual void generateAttributes(const unsigned level);

    virtual const bool isDead() const;
    virtual void loseHp(const int hp);
    virtual void updateAnimation(const float& dt) = 0;
    virtual void update(const float& dt, sf::Vector2f& mouse_pos_view) = 0;
    virtual void render(sf::RenderTarget& target, const bool show_hitbox = false) = 0;
};

