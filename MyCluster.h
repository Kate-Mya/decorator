#pragma once
#include <iostream>
#include "windows.h"
using namespace std;
enum class FileTypeEnum { Underfind, Zip, Vmdk};
class MyCluster
{
private:
	unsigned int clusterNum = 0;
	BYTE* content = NULL;

public:
	void SetClusterNum(unsigned int num) { clusterNum = num; }
	void SetContent(BYTE* arr, unsigned int ClusterSize);
	BYTE* GetContent() { return content; };
	unsigned int GetNum() const { return clusterNum; };
	FileTypeEnum GetFileType();
	MyCluster(BYTE* data, unsigned int num, unsigned int ClusterSize);
	MyCluster() {};
	~MyCluster();
};