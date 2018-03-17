// BinarySeachTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node* p;
};

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


void createTree(Node* &T,int nodeNum,int data[]) {
	for (int i =0 ; i < 8; i++) {
		insertTree(T,data[i]);
	}
}

void InorderTree(Node* x)
{
	if (x != NULL)
	{
		InorderTree(x->left);
		cout << x->data << "   ";
		InorderTree(x->right);
	}
	cout << endl;
}

int main()
{
	int data[] = { 2,5,6,1,9,4,3,10 };
	Node *T = NULL;
	createTree(T,8, data);
	InorderTree(T);

    return 0;
}

