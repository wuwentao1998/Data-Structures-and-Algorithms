#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>

using namespace std;

template<typename Comparable>
class BST
{

	struct node
	{
		Comparable elements;
		node* left;
		node* right;
		size_t count;

		node(Comparable Elements, node* Left, node* Right, size_t Count)
			:elements(Elements), left(Left), right(Right), count(Count) {}
	};

	node* root;

public:
	explicit BST();
    node* & search(const Comparable& x);
	const Comparable & findMax();
	void insert(Comparable x);
	void del(const Comparable& x);
	bool isEmpty() const;
	size_t size(node* n) const;
	void printTree(const string & x) const;
	size_t height() const;
	const Comparable & rank(size_t x) const;
	const Comparable & precessor(const Comparable& x);
	size_t rangeSum(const Comparable& x, const Comparable& y);
	void rangeSearch(const Comparable& x, const Comparable& y);


private:
    node* & search(node* root, const Comparable& x) ;
	node* & findMax(node* root);
	void insert(node* & root, Comparable x);
	void del(node* & root, const Comparable& x);
	void preOrder( node* const &  root) const; //为什么 root 一定要是常量指针？
	void postOrder( node* const & root) const;
	void inOrder( node* const & root) const;
	void levelOrder( node* const & root) const;
	size_t height(const node* root) const;
	const Comparable & rank(size_t x, const node*  root) const;
	Comparable & precessor(const Comparable& x,  node* root);
	node* getNode( //注意要传入指针的引用才能改变指针
		const Comparable& x, node* root, node* & parent, node* & firstRightParent);
	size_t rangeSum(const Comparable& x, const Comparable& y, node* root);
	void rangeSearch(const Comparable& x, const Comparable& y, node* root);

};



template <typename Comparable>
BST<Comparable>::BST() : root(nullptr)
{
}

template <typename Comparable>
size_t BST<Comparable>::size(node *n) const
{
	return (n == nullptr) ? 0 : n->count;
}

template <typename Comparable>
typename BST<Comparable>::node *&BST<Comparable>::search(const Comparable &x)
{
	return search(root, x);
}

template <typename Comparable>
const Comparable &BST<Comparable>::findMax()
{
	return findMax(root)->elements;
}

template <typename Comparable>
bool BST<Comparable>::isEmpty() const
{
	return root == nullptr;
}

template <typename Comparable>
void BST<Comparable>::insert(Comparable x)
{
	insert(root, std::move(x));
}

template <typename Comparable>
void BST<Comparable>::del(const Comparable &x)
{
	del(root, x);
}

template <typename Comparable>
void BST<Comparable>::printTree(const string &x) const
{
	if (x == "preorder")
		preOrder(root);
	else if (x == "postorder")
		postOrder(root);
	else if (x == "inorder")
		inOrder(root);
	else if (x == "levelorder")
		levelOrder(root);
	else
		throw "Wrong input!";
}

template <typename Comparable>
size_t BST<Comparable>::height() const
{
	return height(root);
}

template <typename Comparable>
const Comparable &BST<Comparable>::rank(size_t x) const
{
	return rank(x, root);
}

template <typename Comparable>
const Comparable &BST<Comparable>::precessor(const Comparable &x)
{
	return precessor(x, root);
}

template <typename Comparable>
size_t BST<Comparable>::rangeSum(const Comparable &x, const Comparable &y)
{
	return rangeSum(x, y, root);
}

template <typename Comparable>
void BST<Comparable>::rangeSearch(const Comparable &x, const Comparable &y)
{
	rangeSearch(x, y, root);
}

/*private*/
/////////////////////////////
////////////////////////////
///////////////////////////

template <typename Comparable>
void BST<Comparable>::rangeSearch(const Comparable &x, const Comparable &y, node *root)
{
	if (root == nullptr)
		return;
	else if (root->elements >= x && root->elements <= y)
	{
		rangeSearch(x, y, root->left);
		cout << root->elements << endl;
		rangeSearch(x, y, root->right);
	}
	else if (root->elements < x)
		rangeSearch(x, y, root->right);
	else
		rangeSearch(x, y, root->left);
}

template <typename Comparable>
size_t BST<Comparable>::rangeSum(const Comparable &x, const Comparable &y, node *root)
{
	if (root == nullptr)
		return 0;
	else if (root->elements >= x && root->elements <= y)
		return root->elements + rangeSum(x, y, root->left) + rangeSum(x, y, root->right);
	else if (root->elements < x)
		return rangeSum(x, y, root->right);
	else
		return rangeSum(x, y, root->left);
}

template <typename Comparable>
typename BST<Comparable>::node *BST<Comparable>::getNode(
	const Comparable &x, node *root, node *&parent, node *&firstRightParent)
{
	while (root)
	{
		if (root->elements == x)
			return root;

		parent = root;

		if (root->elements > x)
			root = root->left;
		else
		{
			firstRightParent = root;
			root = root->right;
		}
	}

	return nullptr;
}

template <typename Comparable>
Comparable &BST<Comparable>::precessor(const Comparable &x, node *root)
{
	if (root == nullptr)
		throw "emptt tree";

	node *parent = nullptr;
	node *firstRightParent = nullptr;

	node *now = getNode(x, root, parent, firstRightParent);

	if (now == nullptr)
		throw "now such value";
	int a = 0;

	if (now->left != nullptr)
		return findMax(now->left)->elements;
	else if (parent == nullptr)
		throw "no precessor";
	else if (parent->right == now)
		return parent->elements;
	else if (firstRightParent == nullptr)
		throw "no precessor";
	else
		return firstRightParent->elements;
}

template <typename Comparable>
const Comparable &BST<Comparable>::rank(size_t x, const node *root) const
{
	if (root == nullptr)
		throw "empty tree";

	size_t left = size(root->left);
	if (left == x)
		return root->elements;
	else if (left > x)
		return rank(x, root->left);
	else

		return rank(x - left - 1, root->right);
}

template <typename Comparable>
size_t BST<Comparable>::height(const node *root) const
{
	if (root == nullptr)
		return 0;
	else
	{
		size_t left = height(root->left);
		size_t right = height(root->right);
		return 1 + (left > right ? left : right);
	}
}

template <typename Comparable>
typename BST<Comparable>::node *&BST<Comparable>::search(node *root, const Comparable &x)
{
	if (root == nullptr)
		throw "No such element!";
	else if (root->elements == x)
		return root;
	else if (root->elements > x)
		return search(root->left, x);
	else if (root->elements < x)
		return search(root->right, x);
}

template <typename Comparable>
typename BST<Comparable>::node *&BST<Comparable>::findMax(node *root)
{
	if (root == nullptr)
		throw "Empty tree!";
	else if (root->right == nullptr)
		return root;
	else
		return findMax(root->right);
}

template <typename Comparable>
void BST<Comparable>::insert(node *&root, Comparable x)
{
	if (root == nullptr)
	{
		root = new node(x, nullptr, nullptr, 1);
		return;
	}
	else if (root->elements < x)
		insert(root->right, x);
	else if (root->elements > x)
		insert(root->left, x);
	else
		; //duplicated value, do nothing

	root->count = size(root->left) + size(root->right) + 1;
}

template <typename Comparable>
void BST<Comparable>::del(node *&root, const Comparable &x)
{
	if (root == nullptr)
		throw "No such elements!";
	else if (root->elements < x)
		del(root->right, x);
	else if (root->elements > x)
		del(root->left, x);
	else
	{

		if (root->left == nullptr && root->right == nullptr) //no child
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr || root->right == nullptr) // one child
		{
			auto temp = root;
			if (root->left == nullptr)
				root = root->right;
			else if (root->right == nullptr)
				root = root->left;

			delete temp;
		}
		else //two children
		{
			auto &repalce = findMax(root->left);
			root->elements = repalce->elements;
			auto temp = repalce;
			repalce = repalce->left;
			delete temp;
		}
	}
}

template <typename Comparable>
void BST<Comparable>::preOrder(node *const &root) const
{
	if (root != nullptr)
	{
		cout << root->elements << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

template <typename Comparable>
void BST<Comparable>::postOrder(node *const &root) const
{
	if (root != nullptr)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->elements << endl;
	}
}

template <typename Comparable>
void BST<Comparable>::inOrder(node *const &root) const
{
	if (root != nullptr)
	{
		postOrder(root->left);
		cout << root->elements << endl;
		postOrder(root->right);
	}
}

template <typename Comparable>
void BST<Comparable>::levelOrder(node *const &root) const
{
	queue<node *> q;
	q.push(root);
	while (!q.empty())
	{
		auto curNode = q.front();
		cout << curNode->elements << endl;
		q.pop();
		if (curNode->left != nullptr)
			q.push(curNode->left);
		if (curNode->right != nullptr)
			q.push(curNode->right);
	}
}

#endif