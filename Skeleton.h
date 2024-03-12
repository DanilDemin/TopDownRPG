#pragma once
#include "Enemy.h"



class Skeleton :
    public Enemy
{
private:
    //Variables
    float scale;

    //Initializer functions
    void initVariavles() override;
    void initAnimation() override;
    void initGUI();

    sf::RectangleShape hpBar;

public:
    //Con / Des
    Skeleton(float x, float y, sf::Texture& texture_sheet, EnemySpawnerTile& enemy_spawner_tile);
    virtual ~Skeleton() override;
    
    //Accessors


   //Functions
    
    void updateAnimation(const float& dt) override;
    void update(const float& dt, sf::Vector2f& mouse_pos_view) override;
    void render(sf::RenderTarget& target, const bool show_hitbox = false) override;

};

