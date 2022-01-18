#include "Utility.h"
#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Character.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "Dragon.h"
#include "DragonSlayer.h"

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<HelpfulItem>(new HelpfulItem()) );
    }
    
    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<DefensiveItem>(new DefensiveItem()) );
    }
    
    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::string getCharacterStats(Character* ch)
{
    std::string str;
    
    str += "    hitPoints: " + std::to_string(ch->getHP()) + "\n";
    str += "    armor: " + std::to_string(ch->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(ch->getAttackDamage()) + "\n";
    str += "    is defending: " + std::string((ch->getIsDefending() ? "true" : "false" )) + "\n";
    str += "    " + std::to_string(ch->getHelpfulItems().size()) + " helpful items,  " + std::to_string(ch->getDefensiveItems().size()) + " defensive items";
    return str;
}

void useDefensiveItem(Character* character, Item& item)
{
    //dwarves, paladins, and DragonSlayers get extra boosts from defensive item.
    if( auto* dwarf = dynamic_cast<Dwarf*>(character) )
    {
        dwarf->boostArmor( item.getBoost() * 1.1 );
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(character) )
    {
        //same with paladins
        paladin->boostArmor( item.getBoost() * 1.3 );
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(character))
    {
        dragonSlayer->boostArmor( item.getBoost() * 1.5 );
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't need defensive items
    }  
}
void useHelpfulItem(Character* character, Item* item)
{
    if( auto* dwarf = dynamic_cast<Dwarf*>(character) )
    {
        dwarf->boostHitPoints(item->getBoost() * 2);
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(character) )
    {
        paladin->boostHitPoints(item->getBoost() * 1.5);
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(character))
    {
        dragonSlayer->boostHitPoints(item->getBoost() * 1.25);
    }
    else if( auto* dragon = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry helpful items!
    }
}
void useAttackItem(Character* character, Item* item)
{
    if( auto* dwarf = dynamic_cast<Dwarf*>(character) )
    {
        dwarf->boostAttackDamage(item->getBoost() * 1.5);
    }
    else if( auto* paladin = dynamic_cast<Paladin*>(character) )
    {
        paladin->boostAttackDamage(item->getBoost() * 1.33);
    }
    else if( auto* dragonSlayer = dynamic_cast<DragonSlayer*>(character))
    {
        dragonSlayer->boostAttackDamage( dragonSlayer->getAttackDamage() * item->getBoost() );
    }
    else if( auto* dragon = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry attack items!
        std::cout << "dragons don't carry attack items!" << std::endl;
    }
}
