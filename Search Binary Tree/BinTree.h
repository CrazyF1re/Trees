#pragma once
#include <iostream>
class Node
{
	int key;//���� ������
	Node* left, * right, * parent;//��������� �� ������ � ������� �������� � ��������

public:
	Node(int k = 0, Node* L = 0, Node* R = 0, Node* P = 0)//����������� �� ���������
	{
		key    = k; 
		left   = L; 
		right  = R; 
		parent = P;
	}
	int GetKey() { return key; }
	friend class BinTree;
	friend class SBinTree;

};
class BinTree
{
protected:Node* root;// ������ ������
	Node* Tree(int n, Node* p);//���������� �������� ����������������� ������ � n ���������, p - ������ ������� �������
	void Copy(Node* q, Node* p, int f);//����������� ������ � ������ q, p - ����, � �������� �������������� �����
	//f=0 - ���������� ������ ����� ����� �������� ��� p;
	//f=1 - ���������� ������ ����� ������ �������� ��� p.
	int cycle(Node* root, int* a, int count, int n);

public:
	BinTree() { root  = new Node();; }//����������� �� ���������
	BinTree(int n);// ����������� � n ���������� �������
	BinTree(int* a, int n);//����������� �������� �� ���� ������ ������ � �� ����������
	BinTree(const BinTree&);//����������� �����������
	BinTree& operator=(const BinTree&);//���������� ��������� ������������
	virtual ~BinTree();//����������
	virtual void Add(int k, Node* p);//�������� � ������ � ������ p ���� � ������ k
	virtual void Del(Node* p);//�������� ���� p
	virtual void DelRoot();//�������� �����



	void TreeTraversal_LCR(Node* p);
	//����� ������ � ������ p, � ������� �� ��������
	//����-������-�����, ����� ��������� �� �������

//�������� ������ ������� ���� �������:
//void TreeTraversal_LCR (Node *p, int *a, int *n);	
	   //����� ������ � ������ p, � ������� �� ��������
	   //����-������-�����, ����� ����������� � ������� a, 
	   //n - ������ ������� a 
	void TreeTraversal_LRC(Node* p);
	//����� ������ � ������ p, � ������� �� ��������
	//����-�����-������, ����� ��������� �� �������
	void TreeTraversal_RLC(Node* p);
	//����� ������ � ������ p, � ������� �� ��������
	//�����-����-������, ����� ��������� �� �������
	void WidthTraversal(Node* p);
	//����� ������ � ������ p, � ������


	virtual Node* FindKey(int k, Node* p);//����� ���� � ������ k � ������ � ������ p
	virtual Node* FindMax(Node* p);//����� ���� � ������������ ������ � ����� � ������ p
	virtual Node* FindMin(Node* p);//����� ���� � min ������ � ������ � ������ p
	int FindHight(Node* p);//����� ������ ������ � ������ p
	int Count(Node* p);//���������� ���������� ����� � ������ � ������ p
	Node* GetRoot() { return root; }//������ ������
	void Clear();//���������� ��� ������, ����� �����
	void PrintTree(Node* p, int k);
		//����� ������ �� �������, 
		//k - ������ �� ����� ������� �������
};