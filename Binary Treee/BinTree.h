#pragma once
#include <iostream>
class Node
{
	int key;//поле данных
	Node* left, * right, * parent;//указатель на левого и правого потомков и родителя

public:
	Node(int k = 0, Node* L = 0, Node* R = 0, Node* P = 0)//конструктор по умолчанию
	{
		key    = k; 
		left   = L; 
		right  = R; 
		parent = P;
	}
	int GetKey() { return key; }
	friend class BinTree;

};
class BinTree
{
	Node* root;// корень дерева
	Node* Tree(int n, Node* p);//построение идеально сбалансированного дерева с n вершинами, p - предок вершины дререва
	void Copy(Node* q, Node* p, int f);//копирование дерева с корнем q, p - узел, к которому присоединяется копия
	//f=0 - копируемое дерево будет левым потомком для p;
	//f=1 - копируемое дерево будет правым потомком для p.
	int cycle(Node* root, int* a, int count, int n);

public:
	BinTree() { root = 0; }//конструктор по умолчанию
	BinTree(int n);// конструктор с n случайными ключами
	BinTree(int* a, int n);//конструктор получает на вход массив ключей и их количество
	BinTree(const BinTree&);//конструктор копирования
	BinTree& operator=(const BinTree&);//перегрузка оператора присваивания
	~BinTree();//деструктор
	void Add(int k, Node* p);//добавить в дерево с корнем p узел с ключем k
	void Del(Node* p);//удаление узла p
	void DelRoot();//удаление корня



	void TreeTraversal_LCR(Node* p);
	//обход дерева с корнем p, в глубину по принципу
	//лево-корень-право, ключи выводятся на консоль

//возможен другой вариант этой функции:
//void TreeTraversal_LCR (Node *p, int *a, int *n);	
	   //обход дерева с корнем p, в глубину по принципу
	   //лево-корень-право, ключи сохраняются в массиве a, 
	   //n - размер массива a 
	void TreeTraversal_LRC(Node* p);
	//обход дерева с корнем p, в глубину по принципу
	//лево-право-корень, ключи выводятся на консоль
	void TreeTraversal_RLC(Node* p);
	//обход дерева с корнем p, в глубину по принципу
	//право-лево-корень, ключи выводятся на консоль
	void WidthTraversal(Node* p);
	//обход дерева с корнем p, в ширину


	Node* FindKey(int k, Node* p);//поиск узла с ключем k в дереве с корнем p
	Node* FindMax(Node* p);//поиск узла с максимальным ключем в дерев с корнем p
	Node* FindMin(Node* p);//поиск узла с min ключом в дереве с корнем p
	int FindHight(Node* p);//поиск высоты дерева с корнем p
	int Count(Node* p);//нахождение количества узлов в дереве с корнем p
	Node* GetRoot() { return root; }//корень дерева
	void Clear();//уничтожает все дерево, кроме корня
	void PrintTree(Node* p, int k);
		//вывод дерева на консоль, 
		//k - отступ от левой границы консоли
};