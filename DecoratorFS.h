#pragma once
#include "IteratorDecorator.h"
#include "MyCluster.h"
#include <iostream>
class DecoratorFS :public IteratorDecorator<MyCluster>
{
private:
	FileTypeEnum TargetFile;
public:
	DecoratorFS(Iterator<MyCluster>* it, FileTypeEnum targetFile) : IteratorDecorator(it) {
		TargetFile = targetFile;
	}
	void First();
	void Next();
};