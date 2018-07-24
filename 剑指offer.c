#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
struct ListNode { //链表数据结构
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
			
		}
	
};
struct TreeNode {//二叉树数据结构
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution //二维数组查找
{
public:
	bool Find(int target, vector<vector<int> > array)
	{
		int rows = array.size();//行
		int cols= array[0].size();//列
		int i = rows - 1;
		int j = 0;
		while (i >= 0 && j < cols)
		{
			if (array[i][j] > target)
			{
				i--;
			}
			else if (array[i][j] < target)
			{
				j++;
			}
			else
				return true;
		}
		return false;
		
	}
};



/*void replaceSpace(char *str,  int length)
{
	char arr[15] = { 0 };
	char *tmp = str;
	int i = 0;
	while (*tmp!= '\0')
	{
		if (*tmp == ' ')
		{
			arr[i] = '%';
			arr[++i] = '2';
			arr[++i] = '0';
			tmp++;
			i++;
		}
		else
			arr[i++] = *tmp++;
	}
	arr[i++] = '\0';
	cout << arr;
}*/
void replaceSpace(char *str, int length) {//空格替换
	int count = 0;
	for (int i = 0; i<length; i++){
		if (str[i] == ' ')
			count++;
	}
	for (int i = length - 1; i >= 0; i--){
		if (str[i] != ' '){
			str[i + 2 * count] = str[i];
		}
		else{
			count--;
			str[i + 2 * count] = '%';
			str[i + 2 * count + 1] = '2';
			str[i + 2 * count + 2] = '0';
		}
	}
}

	vector<int> printListFromTailToHead(ListNode* head)//反向输出链表数据
	{
		stack<int> s;
		while (head!=NULL)
		{
			s.push(head->val);
			head = head->next;
		}
		vector<int> array;
		while(!s.empty())
		{
			array.push_back(s.top());
			s.pop();
		}
		return array;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)// 复原二叉树
	{
		int inlen = vin.size();
		if (inlen == 0)
		{
			return NULL;
		}
			vector<int> left_pre, right_pre, left_vin, right_vin;     
			//创建根节点，根节点肯定是前序遍历的第一个数
			TreeNode* head = new TreeNode(pre[0]);
			int gen = 0;//找到中序遍历根节点所在位置,存放于变量gen中
			for (int i = 0; i < inlen; i++)
			{
				if (vin[i] == pre[0])
				{
				    gen = i;
					break;
				}
			}		
			//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
			for (int i = 0; i < gen; i++)//利用上述这点，对二叉树节点进行归并
			{
    			left_vin.push_back(vin[i]);
				left_pre.push_back(pre[i + 1]);//前序第一个为根节点
			}
			for (int i = gen + 1; i < inlen; i++)
			{
				right_vin.push_back(vin[i]);
				right_pre.push_back(pre[i]);
			}
			head->left = reConstructBinaryTree(left_pre, left_vin);//递归，再对其进行上述所有步骤，即再区分子树的左、右子树，直到叶节点
			head->right = reConstructBinaryTree(right_pre, right_vin);
			return head;	
	}


	class Solution//栈实现队列
	{
	public:
		void push(int node) {

			stack1.push(node);


		}

		int pop() {
			if (stack2.empty())
			{
				
				while (!stack1.empty())
				{
					int tmp = stack1.top();
					stack1.pop();
					stack2.push(tmp);
				}
				if (stack2.empty())
				{
					return -1;
				}
				
				
			}
			int root = stack2.top();
			stack2.pop();
			return root;
		}

	private:
		stack<int> stack1;
		stack<int> stack2;
	};

	class Solution {//旋转数组
	public:
		int minNumberInRotateArray(vector<int> rotateArray) {
			if (rotateArray.size() == 0)
			{
				return 0;
			}
			int min = rotateArray[0];
			for (int  i = 1; i < rotateArray.size(); i++)
			{
				if (rotateArray[i] < min)
					min = rotateArray[i];
			}
			return min;
		}

	};
	class Solution {//斐波那契/	青蛙跳台阶
	public:
		int Fibonacci(int n) {
			int a = 1;
			int b = 1;
			int value = 0;
			if (n == 0){
				return 0;
			}
			else if (n == 1|n == 2){
				return 1; 
			}
			else
			{
				for (int i = 0; i < n-2; i++)
				{
					value = a + b;
					a = b;
					b = value;
				}
				return b;
			}
		
		}
	};