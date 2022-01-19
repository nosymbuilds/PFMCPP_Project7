#include "HelpfulItem.h"
#include "Utility.h"

void HelpfulItem::use(Character *character)
{
    return useHelpfulItem( character , this );
}
