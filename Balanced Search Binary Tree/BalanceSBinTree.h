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
	BSBinTree() :SBinTree() {};//�� ���������

	BSBinTree(const BSBinTree& T) :SBinTree(T) {};// �����������
	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="a"> ������ ���� int</param>
	/// <param name="n">���������� ���������</param>
	BSBinTree(int* a, int n)
	{
		if (n == 0) root = NULL;
		else {
			root = new Node(a[0]);
			for (int i = 1; i < n; i++)	Add(a[i], root);
		}
	};//������ ������ n
	/// <summary>
	/// ��������� n ������
	/// </summary>
	/// <param name="n"></param>
	BSBinTree(int n) :SBinTree(n) {};//��������� n �����
	virtual ~BSBinTree() {};// ����������
	virtual void Add(int k, Node* p) override ;//���������� ���� � ������ k � ������ p
	virtual void Del(Node* p) override;//�������� ����

};