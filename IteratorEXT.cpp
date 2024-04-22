#include "IteratorEXT.h"

MyCluster IteratorEXT::GetCurrent()
{
    MyCluster item;
    if (!ext->ReadCluster(&item, Cursor)) {
        throw std::invalid_argument("Error read cluster!");
    }
    return item;
}