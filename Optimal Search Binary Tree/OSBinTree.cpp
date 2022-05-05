#include "OSBinTree.h"

void OSBinTree::CreateMatrix(int* p, int* q, int n, int** W, int** C, int** R)
{
	int i, j, t;


	//заполнение главной (t=0) диагонали в W и C
	for (i = 0; i < n + 1; i++)
		W[i][i] = C[i][i] = q[i];

	//заполнение первой (t=1) диагонали в W, C и R
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		W[i][j] = W[i][i] + p[j] + q[j];
		C[i][j] = W[i][j] + C[i][i] + C[j][j];
		R[i][j] = j;
	}

	int min, k, k_min;
	//заполнение остальных (t=2,3,...,n) диагонали в W, C и R
	for (t = 2; t < n + 1; t++)
		for (i = 0; i < n + 1 - t; i++)
		{
			j = i + t;
			W[i][j] = W[i][j - 1] + p[j] + q[j];

			min = C[i][i] + C[i + 1][j]; k_min = i + 1;
			for (k = i + 2; k <= j; k++)
				if (C[i][k - 1] + C[k][j] < min)
				{
					min = C[i][k - 1] + C[k][j]; k_min = k;
				}

			C[i][j] = W[i][j] + min;
			R[i][j] = k_min;

		}

}


Node* OSBinTree::OTree(int* d, int i, int j, int** R)
{
	if (i >= j)return 0;
	int k = R[i][j];
	Node* q = new Node(d[k]);
	q->left = OTree(d, i, k - 1, R);
	if(q->left!=0) q->left->parent = q;
	q->right = OTree(d, k, j, R);
	if(q->right!=0)q->right->parent = q;
	
	return q;
}

OSBinTree::OSBinTree(int* d, int* p, int* q, int n)
{
	int** W = new int* [n];
	int** C = new int* [n];
	int** R = new int* [n];
	for (int i = 0; i < n; i++) //начальная инициализация матриц
	{
		W[i] = new int[n];
		C[i] = new int[n];
		R[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			W[i][j] = -1;
			C[i][j] = -1;
			R[i][j] = -1;
		}
	}
	CreateMatrix(p, q, n - 1, W, C, R);
	root = OTree(d, 0, 5, R);
	for (int i = 0; i < n; i++) 
	{
		delete[] W[i];
		delete[] C[i];
		delete[] R[i];
	}
	delete[] W;
	delete[] C;
	delete[] R;


}

OSBinTree::OSBinTree(const OSBinTree& T) :SBinTree(T) {}

OSBinTree& OSBinTree::operator=(const OSBinTree &T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		Copy(T.root->left, root, 0);
		Copy(T.root->right, root, 1);
	}
	return *this;
}
