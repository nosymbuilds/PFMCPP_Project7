#include "DragonSlayer.h"
#include "Dragon.h"
#include "AttackItem.h"
#include "Utility.h"

DragonSlayer::DragonSlayer( std::string name_, int hp, int armor ) : Character( hp, armor, 4 ), name(name_) 
{
    helpfulItems = makeHelpfulItems(4);
    defensiveItems = makeDefensiveItems(4);
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        if( dragon->getHP() > 0 && attackItem != nullptr ) 
        {
            attackItem->use(this); 
            attackItem.reset();   
        }

        while( dragon->getHP() > 0 )
        {
            dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
}

const std::string& DragonSlayer::getName()
{
    return name;
}

std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}
