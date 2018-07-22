#include<iostream>
using namespace std;

typedef struct binarytree_node
{
	int data;
	binarytree_node *parent;
	binarytree_node *left;
	binarytree_node *right;
}binarytree_node;

binarytree_node* construct_core(int *start_preorder, int *end_preorder,
	int *start_inorder, int *end_inorder)
{
	//前序遍历序列的第一个数字是根节点
	int rootdata = start_preorder[0];
	binarytree_node* root = new binarytree_node();
	root->data = rootdata;
	root->left = root->right = NULL;

	if (start_preorder == end_preorder)
	{
		if (start_inorder == end_inorder &&
			*start_preorder == *end_inorder)
		{
			return root;
		}
		else
		{
			throw std::exception("invalid input!");
		}
	}
	//中序遍历序列中找到根节点的值
	int *root_inorder = start_inorder;
	while (root_inorder <= end_inorder && *root_inorder != rootdata)
	{
		++root_inorder;
	}
	if (root_inorder == end_inorder && *root_inorder != rootdata)
	{
		throw std::exception("invalid input");
	}
	int left_length = root_inorder - start_inorder;
	int *left_preorder_end = start_preorder + left_length;
	if (left_length > 0)
	{
		//构建左子树
		root->left = construct_core(start_preorder + 1, left_preorder_end,
			start_inorder, root_inorder - 1);
	}
	if (left_length < end_preorder - start_preorder)
	{
		//构建右子树
		root->right = construct_core(left_preorder_end + 1, end_preorder,
			root_inorder + 1, end_inorder);
	}
	return root;
}

binarytree_node* construct(int *preorder, int *inorder, int length)
{
	if (NULL == preorder || NULL == inorder)
	{
		return NULL;
	}
	return construct_core(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
	
}

void pre_order(binarytree_node* root)
{
	if (NULL == root)
	{
		throw std::exception("invalid input");
	}
	if (NULL != root)
	{
		cout << root->data << "  ";
	}
	if (NULL != root->left)
	{
		pre_order(root->left);
	}
	if (NULL != root->right)
	{
		pre_order(root->right);
	}

}



int main()
{
	int preorder[] = { 1,2,4,7,3,5,6,8 };
	int inorder[] = { 4,7,2,1,5,3,8,6 };
	binarytree_node* root = construct(preorder, inorder, sizeof(preorder) / sizeof(int));
	pre_order(root);
	cout << endl;
	return 0;
}