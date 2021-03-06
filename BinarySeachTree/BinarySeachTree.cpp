// BinarySeachTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<algorithm>
using namespace std;

// 树的基本数据结构
struct Node
{
	int data; // 数据域
	Node* left; // 指向左孩子
	Node* right; // 指向右孩子
	Node* p; // 指向双亲节点
};

// 插入节点
void insertTree(Node* &T,int d) 
{
		Node* y = NULL;
		Node* x = T;

		Node* node = new Node;
		node->data = d;
		node->left = NULL;
		node->right = NULL;
		node->p = NULL;
		
		while (x != NULL)
		{
			y = x; 
			if (node->data < x->data)
				x = x->left;
			else
				x = x->right;
		}
		node->p = y;
		if (y == NULL)
			T = node;
		else if (node->data < y->data)
			y->left = node;
		else
			y->right = node;
}

//创建二叉搜索树
void createTree(Node* &T,int nodeNum,int data[]) {
	for (int i =0 ; i < nodeNum; i++) {
		insertTree(T,data[i]);
	}
}

//中序遍历
void InorderTree(Node* x)
{
	if (x != NULL)
	{
		InorderTree(x->left);
		cout << x->data << "   " << endl;
		InorderTree(x->right);
	}
}

//树中的最大值
Node* TreeMax(Node* x)
{
	while (x->right != NULL)
	{
		x = x->right;
	}
	cout << "Max=" << x->data << endl;
	return x;
}

//树中的最小值
Node* TreeMin(Node* x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	cout << "Min=" << x->data << endl;
	return x;
}

// 递归的方法
/*void TreeSearch(Node* T, int data)
{
	if (data < T->data&&T->left!=NULL)
		TreeSearch(T->left, data);
	else if (data > T->data&&T->right!=NULL)
		TreeSearch(T->right, data);
	else if (T->data == data)
		cout << "data exists!" << endl;
	else
		cout << "data doesn't exist!" << endl;
}*/

//非递归的方法
void TreeSearch(Node* T, int data)
{
	while (T != NULL)
	{
		if (data < T->data)
			T = T->left;
		else if (data > T->data)
			T = T->right;
		else
		{
			cout << "data exists!" << endl;
			return;
		}
	}
	cout << "data doesn't exist!" << endl;
}

// 把v子树移植到u子树处
void transplant(Node* &T,Node* u, Node* v)
{	
	if (u->p == NULL)
		T = v;
	else if (u->p->left == u)
		u->p->left = v;
	else if (u->p->right == u)
		u->p->right = v;

	if(v!=NULL)
		v->p = u->p;
}

//删除节点
void TreeDelete(Node* &T, Node* z)
{
	if (z->left == NULL)
		transplant(T, z, z->right);
	else if (z->right == NULL)
		transplant(T, z, z->left);
	else
	{
		Node* y = TreeMin(z->right);
		if (y->p != z)
		{
			transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
	}
}
int main()
{
	int data[] = {2,4,3,13,1,6,7,9,17,15,18,20};
	Node *T = NULL;
	createTree(T,sizeof(data)/sizeof(int), data);
	InorderTree(T);
	TreeMax(T);
	TreeMin(T);
	TreeSearch(T, 1);

	/*transplant(T, T,T->left);
	InorderTree(T);*/

	TreeDelete(T, T->right);
	InorderTree(T);
    return 0;
}

