#include<iostream>
using namespace std;
#define max 15
typedef char  data;

typedef struct binarytree
{
	data _arr[max];
	int sz;

}bintree;

void initbinarytree(binarytree& s)
{

	for (int i = 0; i < max; i++) {
		s._arr[i] = '0';
		s.sz = 0;
	}

}

int insertroot(binarytree&s, data e)
{
	s._arr[0] = e;
	s.sz++;
	return 1;
}

int insert_left(binarytree& s, int i, data e)
{
	if (2 * i + 1>max || i<0)
	{
		return -1;
	}
	if (s._arr[2 * i + 1] == '0'){
		s._arr[(2 * i + 1)] = e;
		s.sz++;
		return 1;
	}
	return -1;
}

int insert_right(binarytree &s, int i, data e)
{
	if (2 * i + 2>max || i<0) {
		return -1;
	}
	if (s._arr[2 * i + 2] == '0'){
		s._arr[2 * i + 2] = e;
		s.sz++;
		return 1;
	}
	return -1;
}
void  printftree(binarytree &s)
{
	if (s.sz == 0) {
		cout << "空树";
	}
	for (int i = 0; i<s.sz; i++)
	{
		cout << s._arr[i];
		if (i==2||i==6||i==0)
		{
			cout << "" << endl;
		}
		
	}
	cout << endl;
}

void creat_binarytree(binarytree &s)
{
	data n = 0;
	cout << "请从上到下从左往右输入结点的值，空结点用0代替，输入-1结束，你最多可以输入" << max << "个结点" << endl;
	while (cin >> n)
	{
         s._arr[s.sz] = n;
		s.sz++;
		if (s.sz == 15)
		{
			return;
		}
	}
}
void preorder(binarytree s, int i)//递归前序遍历
{
	if (i < max)
	{	
	cout << s._arr[i] << " ";
	if (s._arr[2 * i + 1] != '0')
		preorder(s, 2 * i + 1);
	if (s._arr[2 * i + 2] != '0')
		preorder(s, 2 * i + 2);
    }
}
void inorder(binarytree s, int i)//中序递归
{
	if (i < max)
	{	
	if (s._arr[2 * i + 1] != '0')
		preorder(s, 2 * i + 1);
	cout << s._arr[i] << " ";
	if (s._arr[2 * i + 2] != '0')
		preorder(s, 2 * i + 2);
    }
}
void postorder(binarytree s, int i)//后续递归
{
	if (i < max)
	{
		if (s._arr[2 * i + 2] != '0')
			preorder(s, 2 * i + 2);
		cout << s._arr[i] << " ";
		if (s._arr[2 * i + 1] != '0')
			preorder(s, 2 * i + 1);
		
		
	}
}
int main()
{ 
	binarytree s;
	initbinarytree(s);
	creat_binarytree(s);
	printftree(s);
	cout << "前序遍历：";
	preorder(s, 0);
	cout <<endl;
	cout << "中序遍历：";
	inorder(s, 0);
	cout << endl;
	cout << "后序遍历：";
	postorder(s, 0);
	cout << endl;
	return 0;
}
