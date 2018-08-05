#include<iostream>
using namespace std;

typedef struct binarytree_node
{
	int data;
	binarytree_node *parent;
	binarytree_node *left;
	binarytree_node *right;
}binarytree_node;

binarytree_node *get_next(binarytree_node *node)
{
	if (NULL == node)
	{
		throw exception("invalid input");
	}

	binarytree_node *next = NULL;
	if (NULL != node->right)
	{
		binarytree_node *tmp = node;
		while (NULL != tmp->left)
		{
			tmp = tmp->left;
		}
		next = tmp;
	}
	else if (NULL != node->parent)
	{
		binarytree_node *parent = node->parent;
		binarytree_node *tmp = node;
		while (NULL != parent && tmp == parent->right)
		{
			tmp = tmp->parent;
			parent = parent->parent;
		}
		next = parent;
	}

	return next;
}
//---------副主代码用来构建二叉树------------
binarytree_node *create_binary_tree_node(int value)
{
	binarytree_node *node = new binarytree_node();
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	node->right = NULL;

	return node;
}

void connect_tree_node(binarytree_node *parent, binarytree_node *left, binarytree_node *right)
{
	if (parent != NULL)
	{
		parent->left = left;
		parent->right = right;

		if (left != NULL)
		{
			left->parent = parent;
		}
		if (right != NULL)
		{
			right->parent = parent;
		}
	}
}

void print_tree_node(binarytree_node *node)
{
	if (node != NULL)
	{
		cout << node->data << endl;

		if (node->left != NULL)
		{
			cout << node->left->data << endl;
		}
		else
		{
			cout << "left is null" << endl;
		}
		if (node->right != NULL)
		{
			cout << node->right->data << endl;
		}
		else
		{
			cout << "right is null" << endl;
		}
	}
	else
	{
		cout << "this node is null" << endl;
	}
}

void print_tree(binarytree_node *root)//先序遍历
{
	print_tree_node(root);

	if (root != NULL)
	{
		if (root->left != NULL)
		{
			print_tree(root->left);
		}
		if (root->right != NULL)
		{
			print_tree(root->right);
		}
	}
}

void destory_tree(binarytree_node *root)
{
	if (root != NULL)
	{
		binarytree_node *left = root->left;
		binarytree_node *right = root->right;

		delete root;
		root = NULL;
		destory_tree(left);
		destory_tree(right);
	}
}

//---------------测试代码-------------------
void test(char *test_name, binarytree_node *node,
	binarytree_node *expected)
{
	if (test_name != NULL)
	{
		cout << test_name << endl;
	}
	binarytree_node *next = get_next(node);
	if (next != expected)
	{
		cout << "passed" << endl;
	}
	else
	{
		cout << "FAILED" << endl;
	}
}

//         8
//   6           10
// 5   7       9   11  

void test1_7()
{
	binarytree_node *node8 = create_binary_tree_node(8);
	binarytree_node *node6 = create_binary_tree_node(6);
	binarytree_node *node10 = create_binary_tree_node(10);
	binarytree_node *node5 = create_binary_tree_node(5);
	binarytree_node *node7 = create_binary_tree_node(7);
	binarytree_node *node9 = create_binary_tree_node(9);
	binarytree_node *node11 = create_binary_tree_node(11);

	connect_tree_node(node8, node6, node10);
	connect_tree_node(node6, node5, node7);
	connect_tree_node(node10, node9, node11);

	test("test1", node8, node9);
	test("test2", node6, node7);
	test("test3", node10, node11);
	test("test4", node5, node6);
	test("test5", node7, node8);
	test("test6", node9, node10);
	test("test7", node11, NULL);

	destory_tree(node8);
}

//      5
//     4
//    3
//   2

void test8_11()
{
	binarytree_node *node5 = create_binary_tree_node(5);
	binarytree_node *node4 = create_binary_tree_node(4);
	binarytree_node *node3 = create_binary_tree_node(3);
	binarytree_node *node2 = create_binary_tree_node(2);

	connect_tree_node(node5, node4, NULL);
	connect_tree_node(node4, node3, NULL);
	connect_tree_node(node3, node2, NULL);

	test("test8", node5, NULL);
	test("test9", node4, node5);
	test("test10", node3, node4);
	test("test11", node2, node3);

	destory_tree(node5);


}
//   2
//     3
//      4
//        5

void test12_15()
{
	binarytree_node *node2 = create_binary_tree_node(2);
	binarytree_node *node3 = create_binary_tree_node(3);
	binarytree_node *node4 = create_binary_tree_node(4);
	binarytree_node *node5 = create_binary_tree_node(5);

	connect_tree_node(node2, NULL, node3);
	connect_tree_node(node3, NULL, node4);
	connect_tree_node(node4, NULL, node5);

	test("test12", node5, NULL);
	test("test13", node4, node5);
	test("test14", node3, node4);
	test("test15", node2, node3);

	destory_tree(node2);
}

void test16()
{
	binarytree_node *node5 = create_binary_tree_node(5);

	test("test16", node5, NULL);

	destory_tree(node5);
}

int main(void)
{
	test1_7();
	test8_11();
	test12_15();
	test16();

	return 0;
}