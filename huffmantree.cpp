#include<iostream>
#include<vector>
using namespace std;
typedef int  DataType;
 struct HTreeNode
{
	DataType data;
 	HTreeNode* leftChild;
	HTreeNode* rightChild;
};

class HuffTree
{
	HTreeNode * root;
	int len;
public:
	HuffTree();
	~HuffTree();
	void creatHuffTree(DataType arr[], int n);
	void githuffcode();
	void githuffcode(HTreeNode*HBT, int n);
private:
	
};

HuffTree::HuffTree()
{
	root = NULL;
	len = 0;
}

HuffTree::~HuffTree()
{
}
void HuffTree::creatHuffTree(DataType arr[], int n)
{
	HTreeNode** b;
	HTreeNode* q=NULL;
	b = new HTreeNode*[n];
	int i, j;
	for ( i = 0; i < n; i++)
	{
		b[i]=new HTreeNode;
		b[i]->data = arr[i];
		b[i]->leftChild = NULL;
		b[i]->rightChild = NULL;
	}
	for ( i = 1; i < n; i++)
	{
		int k1 = -1;
		int k2;
		for (j = 0; j < n; j++)
		{
			if (k1 == -1 && b[j] != NULL)
			{
				k1 = j;
				continue;
			}
			if (b[j] != NULL)
			{
				k2 = j; break;

			}
		}
			for (j = k2; j < n; j++)
			{
				if (b[j] != NULL){
					if (b[j]->data < b[k1]->data)
					{
						k2 = k1; k1 = j;
					}
					else if (b[j]->data < b[k2]->data)

					{
						k2 = j;
					}
				}
			}
			q = new HTreeNode;
			q->data = b[k1]->data + b[k2]->data;
			q->leftChild = b[k1];
			q->rightChild = b[k2];
			b[k1] = q;
			b[k2] = NULL;

		
		
	}
	delete[]b;
	root = q;
}

void HuffTree::githuffcode()
{
  githuffcode(root,len);
}

void HuffTree::githuffcode(HTreeNode* BHT, int len)
{
	static int  arr[15];
	if (BHT != NULL)
	{

		if (BHT->leftChild==NULL&&BHT->rightChild==NULL)
   		{  
			cout << "½áµã" << BHT->data << "µÄ¹þ·òÂü±àÂëÎª" << endl;
		for  (int i = 0; i < len;  i++)
			{
				cout << arr[i];

			}
		cout << endl;

		}
		else{
			arr[len] = 0;
			githuffcode(BHT->leftChild, len + 1);
			arr[len] = 1;
			githuffcode(BHT->rightChild,len + 1);
		}
	}
}
int main()
{
	DataType arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	HuffTree HFT;
	HFT.creatHuffTree(arr,10);
	HFT.githuffcode();
	return 0;
}
