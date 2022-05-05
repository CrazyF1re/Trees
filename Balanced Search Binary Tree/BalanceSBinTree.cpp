#pragma once
#include <iostream>
#include "BalanceSBinTree.h"


bool BSBinTree::Is_balanced(Node* p) 
{
	if (p == 0)return 0;
	if (p->balance == 2 || p->balance == -2)return 0;
	Is_balanced(p->left);
	Is_balanced(p->right);
	return 1;
}
void BSBinTree::full_reset_balance(Node* p)
{

	if (p == 0)return;
	p->balance = FindHight(p->right) - FindHight(p->left);
	full_reset_balance(p->left);
	full_reset_balance(p->right);
}

void BSBinTree::L(Node *p,Node* gp)
{
	Node* R , * p2;//узлы для листьев и R - узел куда прикреплять сбалансированноое дерево
	R = gp->parent;// если есть предок то init иначе в конце меняем root
	p2 = p->left;//инициализация листка если он есть
	p->left = gp;//ставим p на место gp и меняем связи
	gp->parent = p;
	gp->right = 0;
	if (p2 != 0)//если есть лист, то прикрепляем его к gp
	{
		gp->right = p2;
		p2->parent = gp;
	}
	if (R != 0)// если R - не корень, то прикрепляем сбалансированную ветвь к R
	{
		p->parent = R;
		if (R->right == gp)R->right = p;
		else R->left = p;
	}
	else
	{
		root = p;//иначе меняем root
		p->parent = 0;
	}
}

void BSBinTree::R( Node* p, Node* gp)
{
	Node* R, * p2;//узлы для листьев и R - узел куда прикреплять сбалансированноое дерево
	R = gp->parent;// если есть предок то init иначе в конце меняем root
	p2 = p->right;//инициализация листка если он есть
	p->right = gp;//ставим p на место gp и меняем связи
	gp->parent = p;
	gp->left = 0;
	if (p2 != 0)//если есть лист, то прикрепляем его к gp
	{
		gp->left = p2;
		p2->parent = gp;
	}
	if (R != 0)// если R - не корень, то прикрепляем сбалансированную ветвь к R
	{
		p->parent = R;
		if (R->right == gp)R->right = p;
		else R->left = p;
	}
	else {
		root = p;//иначе меняем root
		p->parent = 0;
	}

}

void BSBinTree::LR(Node* u, Node* p, Node* gp)
{
	Node *R,* u1, * u2;
	R = gp->parent;// либо предок gp либо 0
	u1 = u->left;
	u2 = u->right;//инициализация листьев
	u->left = p;
	p->parent = u;
	u->right = gp;
	gp->parent = u;
	p->right = 0;
	gp->left = 0;
	if (u1 != 0) //прикрепляем листья если таковые имеются
	{
		p->right = u1;
		u1->parent = p;
	}
	if(u2!=0)
	{
		gp->left = u2;
		u2->parent = gp;
	}
	if (R != 0)
	{
		if (R->right == gp)R->right = u;
		else R->left = u;
		u->parent = R;

	}
	else {
		root = u;
		u->parent = 0;
	}

}

void BSBinTree::RL(Node* u, Node* p, Node* gp)
{
	Node* R, * u1, * u2;
	R = gp->parent;// либо предок gp либо 0
	u1 = u->left;
	u2 = u->right;//инициализация листьев
	u->left = gp;
	gp->parent = u;
	u->right = p;
	p->parent = u;
	gp->right = 0;
	p->left = 0;
	if (u1 != 0) //прикрепляем листья если таковые имеются
	{
		gp->right = u1;
		u1->parent = gp;
	}
	if (u2 != 0)
	{
		p->left = u2;
		u2->parent = p;
	}
	if (R != 0)
	{
		if (R->right == gp)R->right = u;
		else R->left = u;
		u->parent = R;

	}
	else {
		root = u; 
		u->parent = 0;
	}
}


Node* BSBinTree::reset_balance(Node* p) 
{


	Node* temp = p;
	Node* h1 = 0, * h2 = 0, * h3 = 0;
	if (temp->parent != 0)//изначальная инициализация где h1 - отец h2 - дед h3 - если h2 сбалансирован
	{
		h1 = temp->parent;
		h1->balance = this->FindHight(h1->right) - this->FindHight(h1->left);
		p->parent->balance = h1->balance;
	}
	if (h1!=0 && h1->parent != 0)//все еще инициализация
	{
		h2 = h1->parent;
		h2->balance = this->FindHight(h2->right) - this->FindHight(h2->left);
		p->parent->parent->balance = h2->balance;
	}
	if (h1!=0 && h2!=0 && h2->balance != 2 && h2->balance!= -2)	// проверяем сбалансированность h1 и h2
	{															//если да, то идем дальше
																//до первого balance = 2/-2 или до корня дерева      
	
		temp = h2;
		while (temp->parent != 0 && temp->balance!=-2 && temp->balance!=2) // цикл до первого несбалансированного элемента или до корня
		{

			temp = temp->parent;
			temp->balance = this->FindHight(temp->right) - this->FindHight(temp->left);
		}
		if (temp->parent == 0 && temp->balance!=-2 && temp->balance != 2)return 0;//если мы дошли до корня - дерево сбалансированно, возвращаем 0
		else return temp;// иначе возвращаем несбалансированный элемент
	}
	else return h2;	//если оказалось что h1 или h2 несбалансированны, то возвращаем h2
					//тк если бы h1 не был сбалансирован, то мы бы добавляли узел
					//в несбалансированное дерево чего быть не должно
}




void BSBinTree::Add(int k, Node* p)
{
	Node *h,* hp, * hgp, * h3;
	this->SBinTree::Add(k, p);
	Node* temp = this->FindKey(k, p);
	h3= reset_balance(temp);
	if (h3 == 0) {
		std::cout << "-" << std::endl;
		return; //балансировка не нужна
	}
	if (h3 == temp->parent->parent)
	{
		h = temp;
		hp = temp->parent;
	}
	else 
	{
		h = temp->parent;
		hp = h->parent;

	}
	hgp = h3;

	if (hgp->balance * hp->balance > 0) 
	{
		if (hp->balance < 0) 
		{
			R( hp, hgp);
			std::cout << "R" << std::endl;
		}
		else 
		{
			L( hp, hgp);
			std::cout << "L" << std::endl;

		}
	}
	else
	{
		if (hp->balance > 0) 
		{
			LR(h, hp, hgp);
			std::cout << "LR" << std::endl;

		}
		else 
		{
			RL(h, hp, hgp);
			std::cout << "RL" << std::endl;

		}
	}
}

void BSBinTree::Del(Node* p)
{
	Node * hp=0, *hgp=0;
	if (p->parent) hp = p->parent;
	if (hp && hp->parent)hgp = hp->parent;
	this->SBinTree::Del(p);
	this->full_reset_balance(root);
	if (Is_balanced(root))return;
	if ( hp != 0) 
	{
		Node* temp = hp;
		if (temp->balance != -2 && temp->balance != 2 && hgp!=0)temp = hgp;
		if (temp->balance == 2) //L or RL
		{
			if (temp->right->balance > 0)//L
			{
				L( temp->right, temp);
				std::cout << "L" << std::endl;
			}
			else//RL 
			{
				RL(temp->right->left, temp->right, temp);
				std::cout << "RL" << std::endl;

			}
		}
		else//R or LR
		{
			if (temp->left->balance < 0) //R
			{
				R(temp->left, temp);
				std::cout << "R" << std::endl;

			}
			else//LR
			{
				LR(temp->left->right, temp->left, temp);
				std::cout << "LR" << std::endl;

			}
		}
	}
	else 
	{

		if (root->balance == 2) 
		{
			if (root->right->balance > 0)//L
			{
				L(root->right, root);
				std::cout << "L" << std::endl;
			}
			else//RL 
			{
				RL(root->right->left,root->right, root);
				std::cout << "RL" << std::endl;

			}
		}
		else//R or LR
		{
			if (root->left->balance < 0) //R
			{
				R(root->left, root);
				std::cout << "R" << std::endl;

			}
			else//LR
			{
				LR(root->left->right, root->left, root);
				std::cout << "LR" << std::endl;

			}
		}
	}
}
