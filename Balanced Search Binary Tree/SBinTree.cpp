#include "SBinTree.h"
#include <queue>
SBinTree::SBinTree(int n)
{
	if (n <= 0)return;
	srand(time(0));
	root->key =rand()%100;
	while (n > 1) 
	{
		int temp = rand()%100;
		Add(temp, root);
		n--;
	}
}

SBinTree::SBinTree(int* a, int n)
{
	if (n == 0) root = NULL;
	else {
		root = new Node(a[0]);
		for (int i = 1; i < n; i++)	Add(a[i], root);
	}

}

SBinTree::SBinTree(const SBinTree& T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
}

SBinTree& SBinTree::operator=(const SBinTree& T)
{
	Clear();
	if (T.root == NULL) root = NULL;
	else
	{
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
	return *this;
}

void SBinTree::Add(int k, Node* p)
{
	Node* q;
	if (k < p->key)
		if (p->left == NULL)
		{
			q = new Node(k);
			p->left = q;
			q->parent = p;
		}
		else SBinTree::Add(k, p->left);
	else if (p->right == NULL)
	{
		q = new Node(k);
		p->right = q;
		q->parent = p;
	}
	else SBinTree::Add(k, p->right);

}

void SBinTree::Del(Node* p)
{
	if (p == root) 
	{
		DelRoot(); 
		return; 
	}
	Node* q = p->parent;

	//удаление листа
	if (p->left == NULL && p->right == NULL)
	{
		if (q->left == p) q->left = NULL;
		else q->right = NULL;
		delete p;
		return;
	}

	//у p нет левой ветви
	if (p->left == NULL && p->right != NULL)
	{
		if (q->left == p) q->left = p->right;
		else q->right = p->right;
		p->right->parent = q;
		delete p;
		return;
	}

	//у p нет правой ветви
	if (p->left != NULL && p->right == NULL)
	{
		if (q->left == p) q->left = p->left;
		else q->right = p->left;
		p->left->parent = q;
		delete p;
		return;
	}

	//у p есть оба поддерева
	Node* t = p->left;
	if (t->right == NULL)
	{
		t->parent = q;
		if (q->left == p) q->left = t;
		else q->right = t;
		t->right = p->right;
		p->right->parent = t;
	}
	else {
		while (t->right != NULL) t = t->right;
		t->parent->right = t->left;
		if (t->left != NULL)
			t->left->parent = t->parent;

		t->left = p->left;
		t->right = p->right;
		p->left->parent = t;
		p->right->parent = t;

		t->parent = q;
		if (q->left == p) q->left = t;
		else q->right = t;
	}

	delete p;
	return;

}

void SBinTree::DelRoot()
{
	
	if (root->left != 0 && root->right != 0) 
	{
		Node* temp = root->right;
		if (temp->left == 0)
		{
			root->key = temp->key;
			if (temp->right != 0)
			{
				root->right = temp->right;
				temp->right->parent = root;
			}
			return;
		}
		while (temp->left != 0)temp = temp->left;
		temp->parent->left = 0;
		if (temp->right != 0) {
			temp->parent->left = temp->right;
			temp->right->parent = temp->parent;
		}
		root->key = temp->key;
		delete temp;
		return;
	}
	BinTree::DelRoot();
}

Node* SBinTree::FindKey(int k, Node* p)
{
	if (p == 0)return 0;
	if (p->key == k)return p;
	if (p->key > k) 
	{
		if (p->left != 0)FindKey(k, p->left);
		else return 0;
	}
	else 
	{
		if (p->right != 0)FindKey(k, p->right);
		else return 0;
	}
}

Node* SBinTree::FindMax(Node* p)
{
	if (p == 0)return 0;
	Node* max = p;
	while (max->right != 0)max = max->right;
	return max;
}

Node* SBinTree::FindMin(Node* p)
{
	if (p == 0)return 0;
	Node* min = p;
	while (min->left != 0)min = min->left;
	return min;
}
