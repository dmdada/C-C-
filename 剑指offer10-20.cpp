
	int  NumberOf1(int n) {//求二进制一的个数
		int count=0;
		while (n)
		{
			n = n&(n - 1);
			count++;
		}
		return count;
	}
	
	
		double Power(double base, int exponent) {//数值次方
			double value = 1;
			int n = exponent;
			if (n == 0)
			{
				return 1;
			}
			else if (n>0)
			{
				while (n)
				{
					value *= base;
					n--;
				}
				return value;
			}
			else
			{
				while (-n)
				{
					value *= base;
					n++;
				}
				return 1.0 / value;
			}
		}
		void reOrderArray(vector<int> &array)//调整数组为前面奇数，后面偶数
		{
			for (int i = 0; i < array.size(); i++)
			{
				for (int j = array.size() - 1; j>i; j--)
				{
					if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) //前偶后奇交换
					{
						swap(array[j], array[j - 1]);
					}
				}
			}
		}
		void boubble_sort(vector<int> &array)//冒泡排序
		{

			for (int  i = 0; i < array.size(); i++)
			{
				for (int j = array.size() - 1; j >= i+1; j--)
				{
					if (array[j]<array[j - 1])
					{
						swap(array[j], array[j - 1]);
					}
				}
			}
		}
		ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {//倒数k个节点
			if (pListHead == NULL | k <= 0)
			{
				return NULL;
			}
			ListNode* node = pListHead;
			for (int i = 0; i<k; ++i)
			{
				if (node->next != NULL){
					node = node->next;
				}
			}
			while (node->next != NULL)
			{
				node = node->next;
				pListHead = pListHead->next;
			}
			return pListHead;
		}
		ListNode* ReverseList(ListNode* pHead) //逆置链表
		{
			if (pHead->next == NULL|pHead==NULL)
			{
				return pHead;
			}
			ListNode*p = pHead, *q = pHead->next, *r = pHead->next->next;
			pHead = NULL;
			while (q->next != NULL)
			{
				q->next = p;
				p = q;
				q = r;
				r = r->next;
			}
			pHead = q;
			return pHead;
		}
		ListNode* Merge(ListNode* pHead1, ListNode* pHead2)//合并链表
		{
			if (pHead1 == NULL)
			{
				return pHead2;
			}
			if (pHead2 == NULL)
			{
				return pHead1;
			}
			else if (pHead1->val < pHead2->val)
			{
				pHead1->next= Merge(pHead1->next, pHead2);
				return pHead1;
			}
			else
				pHead2->next= Merge(pHead1, pHead2->next);
			return pHead2;
		}      

		bool subtree(TreeNode*pRoot, TreeNode *pRoot2)
		{
			if (pRoot2 == NULL)
			{
				return true;
			}
			if (pRoot == NULL)
			{
				return false;
			}
			if (pRoot->val!=pRoot2->val)
			{
				return false;
			}
			else
			{
				return subtree(pRoot->left, pRoot2->left) && subtree(pRoot->right, pRoot2->right);
			}
		}
		bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//找子树
		{
			bool result = false;
			if (pRoot1 != NULL&&pRoot2 != NULL){
				if (pRoot1->val == pRoot2->val)
				{
					result = subtree(pRoot1, pRoot2);
				}
				if (!result)
				{
					result = HasSubtree(pRoot1->left, pRoot2);
				}
				if (!result)
				{
					result = HasSubtree(pRoot1->right, pRoot2);
				}

			}
			return result;
        }

		void Mirror(TreeNode *pRoot)//镜像二叉树
		{
			if (pRoot != NULL)
			{
				TreeNode* tmp = pRoot->left;
				pRoot->left = pRoot->right;
				pRoot->right = tmp;
					Mirror(pRoot->left);
					Mirror(pRoot->left);
				
			}
		}

		/*vector<int> printMatrix(vector<vector<int> > matrix)//第一次瞎写
		{
			
			int rows = matrix.size()-1;
			int cols = matrix[0].size()-1;
			vector<int> ret;
			ret.clear();
			int tmp = 0;
			int left = 0, right = cols, bottom = 0, top = rows;
			while (left != right&&bottom != top)
			{
				if (bottom == left&&left <= right)
				{   
					while (left <= right){
						ret.push_back(matrix[bottom][left]);
						left++;
					}
					bottom++;
					rows--;
				}
				
				if (left == right&&bottom <= top)
				{
					 tmp = bottom;
					while (tmp<=top)
					{
					    ret.push_back(matrix[right][tmp]);
					    tmp++;
				    }
					left = 0;
					right=rows;
					cols--;
				}
				if (left <= right&& tmp== top)
				{
					while (right>=left)
					{
						ret.push_back(matrix[top][right-1]);
						right--;

					}
					cols--;
					top = cols;
				}
				
				if (bottom <=top&&right == left)
				{
					while (top >= bottom)
					{
						ret.push_back(matrix[top-1][left]);
						top--;
					}
					top = cols;
					right = rows;
				}
				left++;

			}
			return ret;
		}*/
		vector<int> printMatrix(vector<vector<int> > matrix) {//打印顺时针矩阵
			int row = matrix.size();
			int col = matrix[0].size();
			vector<int> res;
			int circle = ((row<col ? row : col) - 1) / 2 + 1;
			for (int i = 0; i != circle; i++){
				//从左到右
				for (int j = i; j != col - i; j++){
					res.push_back(matrix[i][j]);
				}
				//从上到下
				for (int k = i + 1; k != row - i; k++){
					res.push_back(matrix[k][col - i - 1]);
				}
				//从右到左
				for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--){
					res.push_back(matrix[row - i - 1][m]);
				}
				//从下往上
				for (int n = row - i - 2; (n>i) && (col - i - 1 != i); n--){
					res.push_back(matrix[n][i]);
				}
			}
			return res;

		}