#include "DecoratorFS.h"

void DecoratorFS::First()
{
	It->First();
	while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile) {
		It->Next();
	}

}
void DecoratorFS::Next()
{
	do {
		It->Next();
	} while (!It->IsDone() && It->GetCurrent().GetFileType() != TargetFile);
}