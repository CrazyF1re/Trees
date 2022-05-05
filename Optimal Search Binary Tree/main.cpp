#include <iostream>
#include "OSBinTree.h"

void main() 
{
	int d[] = {-1,10,20,30,40,50};
	int p[] = {-1,2,1,1,5,3};
	int q[] = {1,10,1,4,10,6};

	OSBinTree Tree(d, p, q, 6);
	Tree.PrintTree(Tree.GetRoot(),5);
	
	//int d[] = { -1,10,20,30,40,50 };
	//int p[] = { -1,6,2,5,3,1 };
	//int q[] = { 1,8,1,3,2,4 };
}