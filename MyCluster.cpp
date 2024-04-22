
#include "MyCluster.h"
#include <iostream>
using namespace std;

MyCluster::~MyCluster()
{
    delete[] content;
}

FileTypeEnum MyCluster::GetFileType()
{
    if (content[0] == 0x50 && content[1] == 0x4B && content[2] == 0x03 && content[3] == 0x04) {
        return  FileTypeEnum::Zip;
    }
    else if (content[0] == 0x4B && content[1] == 0x44 && content[2] == 0x4D) {
        return  FileTypeEnum::Vmdk;
    }
    return FileTypeEnum::Underfind;
}

MyCluster::MyCluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
    clusterNum = num;
}
void MyCluster::SetContent(BYTE* data, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
}