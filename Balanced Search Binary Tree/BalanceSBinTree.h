#pragma once
#include "SBinTree.h"

class BSBinTree :public SBinTree
{
private:
	Node* reset_balance(Node* p);
	bool Is_balanced(Node* p);
	void full_reset_balance(Node* p);
	void Balance_tree(Node* p);
	void L( Node* h2, Node* h3);
	void R( Node* h2, Node* h3);
	void LR(Node* h1, Node* h2, Node* h3);
	void RL(Node* h1, Node* h2, Node* h3);

public:
	BSBinTree() :SBinTree() {};//по умолчанию

	BSBinTree(const BSBinTree& T) :SBinTree(T) {};// копировани€
	/// <summary>
	///  онструктор
	/// </summary>
	/// <param name="a"> массив типа int</param>
	/// <param name="n">количество элементов</param>
	BSBinTree(int* a, int n)
	{
		if (n == 0) root = NULL;
		else {
			root = new Node(a[0]);
			for (int i = 1; i < n; i++)	Add(a[i], root);
		}
	};//массив длиной n
	/// <summary>
	/// случайные n ключей
	/// </summary>
	/// <param name="n"></param>
	BSBinTree(int n) :SBinTree(n) {};//случайные n чисел
	virtual ~BSBinTree() {};// деструктор
	virtual void Add(int k, Node* p) override ;//добавление узла с ключем k в дерево p
	virtual void Del(Node* p) override;//удаление узла

};