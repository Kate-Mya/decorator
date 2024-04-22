#pragma once
#include "windows.h"
#include "MyCluster.h"
class FS
{
protected:
	HANDLE fileHandler = NULL;
	unsigned int clusterSize = { 0 };
	unsigned int clusterCount = { 0 };
	virtual bool ReadClusterSize();
public:
	bool Init(LPCWSTR);
	bool ReadCluster(MyCluster* asd, unsigned int);
	unsigned int ClusterSize() const { return clusterSize; };
	unsigned int ClusterCount() const { return clusterCount; };
	virtual ~FS();
};