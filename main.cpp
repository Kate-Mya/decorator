#include <iostream>
#include "BaseFS.h"
#include "EXT.h"
#include "windows.h"
#include <iomanip>
#include "IteratorEXT.h"
#include "IteratorDecorator.h"
#include "DecoratorFS.h"

using namespace std;

static void hexdump(const BYTE* array, unsigned int length, unsigned int offset) {
    const int bytes_per_line = 16;
    for (size_t i = 0; i < length; i += bytes_per_line) {
        
        std::cout << std::setw(8) << std::setfill('0') << std::hex << offset + i << ": ";

        
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(array[i + j]) << " ";
            }
            else {
                std::cout << "   "; 
            }
        }

        
        std::cout << "  ";
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                char c = array[i + j];
                std::cout << (c >= 32 && c < 127 ? c : '.');
            }
            else {
                std::cout << " "; 
            }
        }

        std::cout << std::endl;
    }
}

int main()
{
    EXT* fs = new EXT;
    if (!fs->Init(L"\\\\.\\C:")) {
        cout << "Init: " << GetLastError();
        return false;
    };

    unsigned int clusterSize = fs->ClusterSize();
    Iterator<MyCluster>* it = new DecoratorFS(
        new IteratorEXT(fs),
        FileTypeEnum::Vmdk
    );

    for (it->First(); !it->IsDone(); it->Next()) {
        MyCluster currentObject = it->GetCurrent();
        unsigned int offset = currentObject.GetNum() * clusterSize;
        hexdump(currentObject.GetContent(), clusterSize, offset);
    }
}