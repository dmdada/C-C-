20.操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
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
21.输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

```
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> res;
        int circle=((row<col?row:col)-1)/2+1;
        for (int i=0;i!=circle;i++){
            //从左到右
            for (int j=i;j!=col-i;j++){
                res.push_back(matrix[i][j]);
            }
            //从上到下
            for(int k=i+1;k!=row-i;k++){
                res.push_back(matrix[k][col-i-1]);
            }
            //从右到左
            for(int m=col-i-2;(m>=i)&&(row-i-1!=i);m--){
                res.push_back(matrix[row-i-1][m]);
            }
            //从下往上
            for (int n=row-i-2;(n>i)&&(col-i-1!=i);n--){
                res.push_back(matrix[n][i]);
            }
        }
        return res;
  
    }
};
```
22.定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

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
23.输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

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


24.从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
25.输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

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