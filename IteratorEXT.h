#pragma once
#include "Iterator.h"
#include "EXT.h"
class IteratorEXT :
    public Iterator<MyCluster>
{
private:
    EXT* ext;
    unsigned int Count;
    unsigned int Cursor;
public:
    IteratorEXT(EXT* fsItem) :Iterator(fsItem->ClusterCount()) {
        ext = fsItem;
        Count = ext->ClusterCount();
        Cursor = 0;
    }
    void First() { Cursor = 0; }
    void Next() { Cursor++; }
    bool IsDone() const { return (Cursor >= Count); }
    MyCluster GetCurrent();
};