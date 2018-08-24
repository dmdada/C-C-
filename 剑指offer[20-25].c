20.���������Ķ�����������任ΪԴ�������ľ���
��������:
�������ľ����壺Դ������ 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	���������
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

```
class Solution {
public:
  

void Mirror(TreeNode *pRoot)
		{
			if (pRoot != NULL)
			{
				TreeNode* tmp = pRoot->left;
				pRoot->left = pRoot->right;
				pRoot->right = tmp;
					Mirror(pRoot->left);
					Mirror(pRoot->right);
				
			}
		}

};
```
21.����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

```
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> res;
        int circle=((row<col?row:col)-1)/2+1;
        for (int i=0;i!=circle;i++){
            //������
            for (int j=i;j!=col-i;j++){
                res.push_back(matrix[i][j]);
            }
            //���ϵ���
            for(int k=i+1;k!=row-i;k++){
                res.push_back(matrix[k][col-i-1]);
            }
            //���ҵ���
            for(int m=col-i-2;(m>=i)&&(row-i-1!=i);m--){
                res.push_back(matrix[row-i-1][m]);
            }
            //��������
            for (int n=row-i-2;(n>i)&&(col-i-1!=i);n--){
                res.push_back(matrix[n][i]);
            }
        }
        return res;
  
    }
};
```
22.����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������

```
class Solution {
		public:
			void push(int value) 
			{
				m_data.push(value);
				if (m_min.size() == 0 || value < m_min.top())
				{
					m_min.push(value);
				}
				else
				{
					m_min.push(m_min.top());
				}
			}
			void pop() {
				
				m_data.pop();
				m_min.pop();
			}
			int top() {
				return m_data.top();
			}
			int min() {
				
				return m_min.top();
			}
		private:
			stack<int> m_data;
			stack<int> m_min;
		};
```
23.���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

```
class Solution {
public:
   bool IsPopOrder(vector<int> pushV, vector<int> popV) {
			if (pushV.size() == 0) return false;
			vector<int> stack;
			for (int i = 0, j = 0; i < pushV.size();){
				stack.push_back(pushV[i++]);
				while (j < popV.size() && stack.back() == popV[j]){
					stack.pop_back();
					j++;
				}
			}
			return stack.empty();
   }
};
```


24.�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

```
class Solution {
public:
   vector<int> PrintFromTopToBottom(TreeNode* root) 
		{
			
			queue<TreeNode*> ret;
			ret.push(root);
			vector<int> result;
			if (root == NULL)
				return result;
			while (!ret.empty())
			{
				 TreeNode*tmp= ret.front();
				result.push_back(tmp->val);
				ret.pop();
				if (tmp->left != nullptr)
				{
					ret.push(tmp->left);
				}
				if (tmp->right!=nullptr)
				{
					ret.push(tmp->right);
				}
			}
			return result;
		}
};
```
25.����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��

```
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
		{
			if (sequence.size() <= 0)
			{
				return false;
			}
			vector<int> left;
			vector<int> right;
			int i = 0;
			int tmp = sequence[sequence.size()-1];
			for (i = 0; i < sequence.size() - 1; i++)
			{
				if (sequence[i]>tmp)
				{
					break;
				}
				left.push_back(sequence[i]);
			}
			for (int j = i; j < sequence.size() - 1; j++)
			{
				right.push_back(sequence[i]);
				if (sequence[j]<tmp)
					return false;
			}
			bool lef = true;
			if (!left.empty())
			lef = VerifySquenceOfBST(left);
			bool rig = true;
			if (!right.empty())
			rig = VerifySquenceOfBST(right);
			return (lef&&rig);
		}
};
```