#include <iostream>
using namespace std;
typedef struct BTree
{
	int    value;
	struct BTree *lchild;
	struct BTree *rchild;
}BTree;

/*
**num ǰ������
**index �±�
*/
BTree *CreateBTree(BTree *node, int *num, int& index)
{
	if (num[index] == 0)
		return NULL;
	else
	{
		node = new BTree;
		node->value = num[index];
		node->lchild = CreateBTree(node->lchild, num, ++index);
		node->rchild = CreateBTree(node->rchild, num, ++index);
	}
	return node;
}

void print(BTree *root, int h)
{
	if (root != NULL)
	{
		print(root->rchild, h + 1);
		for (int i = 0; i < h; i++)
			cout << "   ";
		cout << root->value;
		print(root->lchild, h + 1);
	}
	cout << endl;
}

int Hsize(BTree *root)
{
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;
	return 1 + Hsize(root->lchild) + Hsize(root->rchild);
}

int main()
{
	int num[] = { 1,2,4,8,0,0,9,0,0,5,10,0,0,11,0,0,3,6,12,0,0,13,0,0,7,14,0,0,15,0,0 };
	BTree *root = NULL;
	int index = 0;
	root = CreateBTree(root, num, index);
	cout << "Ҷ����Ϊ��" << Hsize(root);
	cout << "�˶���������״Ϊ: " << endl;
	print(root, 1);

	return 0;
}