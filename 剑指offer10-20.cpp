
	int  NumberOf1(int n) {//�������һ�ĸ���
		int count=0;
		while (n)
		{
			n = n&(n - 1);
			count++;
		}
		return count;
	}
	
	
		double Power(double base, int exponent) {//��ֵ�η�
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
		void reOrderArray(vector<int> &array)//��������Ϊǰ������������ż��
		{
			for (int i = 0; i < array.size(); i++)
			{
				for (int j = array.size() - 1; j>i; j--)
				{
					if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) //ǰż���潻��
					{
						swap(array[j], array[j - 1]);
					}
				}
			}
		}
		void boubble_sort(vector<int> &array)//ð������
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
		ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {//����k���ڵ�
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
		ListNode* ReverseList(ListNode* pHead) //��������
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
		ListNode* Merge(ListNode* pHead1, ListNode* pHead2)//�ϲ�����
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
		bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//������
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

		void Mirror(TreeNode *pRoot)//���������
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

		/*vector<int> printMatrix(vector<vector<int> > matrix)//��һ��Ϲд
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
		vector<int> printMatrix(vector<vector<int> > matrix) {//��ӡ˳ʱ�����
			int row = matrix.size();
			int col = matrix[0].size();
			vector<int> res;
			int circle = ((row<col ? row : col) - 1) / 2 + 1;
			for (int i = 0; i != circle; i++){
				//������
				for (int j = i; j != col - i; j++){
					res.push_back(matrix[i][j]);
				}
				//���ϵ���
				for (int k = i + 1; k != row - i; k++){
					res.push_back(matrix[k][col - i - 1]);
				}
				//���ҵ���
				for (int m = col - i - 2; (m >= i) && (row - i - 1 != i); m--){
					res.push_back(matrix[row - i - 1][m]);
				}
				//��������
				for (int n = row - i - 2; (n>i) && (col - i - 1 != i); n--){
					res.push_back(matrix[n][i]);
				}
			}
			return res;

		}