

#include <iostream>
#include "BalanceSBinTree.h"


int main()
{
    int arr[] = { 20, 15, 5, 30, 55, 25, 26, 6, 2, 17, 35, 40, 27, 11, 26 };
    BSBinTree tree(arr,6);
    tree.PrintTree(tree.GetRoot(),5);
    tree.Del(tree.FindKey(15, tree.GetRoot()));
    //tree.Del(tree.FindKey(15, tree.GetRoot()));
   //tree.Del(tree.FindKey(25, tree.GetRoot()));

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    tree.PrintTree(tree.GetRoot(), 5);
    tree.Del(tree.FindKey(20, tree.GetRoot()));


}





