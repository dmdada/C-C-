#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
struct ListNode { //�������ݽṹ
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
			
		}
	
};
struct TreeNode {//���������ݽṹ
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution //��ά�������
{
public:
	bool Find(int target, vector<vector<int> > array)
	{
		int rows = array.size();//��
		int cols= array[0].size();//��
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
void replaceSpace(char *str, int length) {//�ո��滻
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

	vector<int> printListFromTailToHead(ListNode* head)//���������������
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

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)// ��ԭ������
	{
		int inlen = vin.size();
		if (inlen == 0)
		{
			return NULL;
		}
			vector<int> left_pre, right_pre, left_vin, right_vin;     
			//�������ڵ㣬���ڵ�϶���ǰ������ĵ�һ����
			TreeNode* head = new TreeNode(pre[0]);
			int gen = 0;//�ҵ�����������ڵ�����λ��,����ڱ���gen��
			for (int i = 0; i < inlen; i++)
			{
				if (vin[i] == pre[0])
				{
				    gen = i;
					break;
				}
			}		
			//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�
			for (int i = 0; i < gen; i++)//����������㣬�Զ������ڵ���й鲢
			{
    			left_vin.push_back(vin[i]);
				left_pre.push_back(pre[i + 1]);//ǰ���һ��Ϊ���ڵ�
			}
			for (int i = gen + 1; i < inlen; i++)
			{
				right_vin.push_back(vin[i]);
				right_pre.push_back(pre[i]);
			}
			head->left = reConstructBinaryTree(left_pre, left_vin);//�ݹ飬�ٶ�������������в��裬������������������������ֱ��Ҷ�ڵ�
			head->right = reConstructBinaryTree(right_pre, right_vin);
			return head;	
	}


	class Solution//ջʵ�ֶ���
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

	class Solution {//��ת����
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
	class Solution {//쳲�����/	������̨��
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