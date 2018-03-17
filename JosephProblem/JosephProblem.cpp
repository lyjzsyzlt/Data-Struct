// JosephProblem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

// 遍历整个循环链表
void traversal(Node* &L)
{
	Node* p = L;
	while (p->next != L)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << p->data<<endl;
}
//创建循环链表
void createList(Node* &L,int nodeNum,int data[])
{
	Node* p = L;
	for (int i = 1; i < nodeNum-1; i++)
	{
		Node* node = new Node;
		node->data = data[i];
		node->next = NULL;
		p->next = node;
		p = p->next;
	}
	Node* node = new Node;
	node->data = data[nodeNum - 1];
	node->next = L;
	p->next = node;
}

//解决约瑟夫环问题
void solve(Node* L, int length,int num)
{
	Node* p = L;
	while (length >= num)
	{
		int count = 1;
		while (count < num - 1)
		{
			p = p->next;
			count++;
		}
		p->next = p->next->next;//删除报数为num的节点
		length--;
		p == p->next;
	}
	traversal(p);
}
int main()
{
	int data[] = { 1,2,3,4,5,6,7,8 };
	//建立头结点
	Node* L = new Node;
	L->data = data[0];

	createList(L,sizeof(data)/sizeof(int),data);
	traversal(L);
	solve(L, 8, 3);
    return 0;
}

