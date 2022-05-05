#pragma once
#include "SBinTree.h"

class OSBinTree : public SBinTree
{
private:
	void CreateMatrix(int* p, int* q, int n, int** W, int** C, int** R);
	Node* OTree(int* d, int i, int j, int** R);

public:
	OSBinTree() : SBinTree() {};
	OSBinTree(int* d, int* p, int* q, int n);
	OSBinTree(const OSBinTree&);
	OSBinTree& operator= (const OSBinTree &);
	virtual ~OSBinTree() {};
};
