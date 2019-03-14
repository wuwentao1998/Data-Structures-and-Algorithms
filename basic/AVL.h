#ifndef AVL_H
#define AVL_H
#include <iostream>
using namespace std;

template<typename Comparable>
class AVL
{
	struct Node
	{
		Comparable elements;
		Node* left;
		Node* right;
		size_t height;

		Node(Comparable Elements, Node* Left, Node* Right, size_t Height)
			:elements(Elements), left(Left), right(Right), height(Height) {}
	};

	Node* root;

public:
	AVL();
	void insert(Comparable x);
	void remove(Comparable x);


private:
	void insert(Comparable&& x, Node* & t); //注意要使用引用来改变t
	int height(Node* t);
	int balanceFactor(Node* t);
	void changeHeight(Node* t);
	void balance(Node* t);
	void LLrotation(Node* & t);
	void LRrotation(Node* & t);
	void RRrotation(Node* & t);
	void RLrotation(Node* & t);
	void remove(Comparable&& x, Node* & t);
};


template <typename Comparable>
AVL<Comparable>::AVL() : root(nullptr)
{
}

template <typename Comparable>
void AVL<Comparable>::insert(Comparable x)
{
	insert(std::move(x), root);
}

template <typename Comparable>
void AVL<Comparable>::remove(Comparable x)
{
	remove(std::move(x), root);
}

/*

private function

*/

template <typename Comparable>
void AVL<Comparable>::remove(Comparable &&x, Node *&t)
{
	if (t == nullptr)
		return;

	if (x < t->elements)
		remove(std::move(x), t->left);
	else if (x > t->elements)
		remove(std::move(x), t->right);
	else
	{
		if (t->left == nullptr && t->right == nullptr)
		{
			delete t;
			t = nullptr; //不要忘了这一步
		}
		else if (t->left == nullptr || t->right == nullptr)
		{
			auto temp = t;
			if (t->left == nullptr)
			{
				t = t->right;
				delete temp;
			}
			else
			{
				t = t->left;
				delete temp;
			}
		}
		else
		{
			auto &repalce = findMax(t->left);
			t->elements = repalce->elements;
			auto temp = repalce;
			repalce = repalce->left;
			delete temp;
		}
	}

	balance(t);
}

template <typename Comparable>
void AVL<Comparable>::insert(Comparable &&x, Node *&t)
{
	if (t == nullptr)
		t = new Node(std::move(x), nullptr, nullptr, 0); //这里必须显示调用std::move，因为虽然x指向一个右值，但是x本身是一个左值
	else if (x < t->elements)
		insert(std::move(x), t->left); //注意这里也要用move
	else if (x > t->elements)
		insert(std::move(x), t->right);
	else
		;

	balance(t);
}

template <typename Comparable>
int AVL<Comparable>::height(Node *t)
{
	if (t == nullptr)
		return -1;
	else
		return t->height;
}

template <typename Comparable>
int AVL<Comparable>::balanceFactor(Node *t)
{
	if (t == nullptr)
		return 0;

	return t->left->height - t->right->height;
}

template <typename Comparable>
void AVL<Comparable>::changeHeight(Node *t)
{
	if (t == nullptr)
		return;

	int left = height(t->left);
	int right = height(t->right);
	t->height = left < right ? right : left;
}

template <typename Comparable>
void AVL<Comparable>::balance(Node *t) //TODO: 参数应该是引用
{
	if (t == nullptr)
		return;

	int factor = balanceFactor(t);

	if (factor > 1)
	{
		if (balanceFactor(t->left) >= 0) //>=而不是>的原因在于删除
			LLrotation(t);
		else
			LRrotation(t);
	}
	else if (factor < -1)
	{
		if (balanceFactor(t->right) <= 0)
			RRrotation(t);
		else
			RLrotation(t);
	}
	else
		changeHeight(t);
}

template <typename Comparable>
void AVL<Comparable>::RRrotation(Node *&t)
{
	auto right = t->right;
	auto rightLeft = right->left;
	t->right = rightLeft;
	right->left = t;
	t = right;
	changeHeight(t);
	changeHeight(t->right);
}

template <typename Comparable>
void AVL<Comparable>::LLrotation(Node *&t)
{
	auto left = t->left;
	auto leftRight = left->right;
	t->left = leftRight;
	left->right = t;
	t = left;
	changeHeight(t);
	changeHeight(t->left);
}

template <typename Comparable>
void AVL<Comparable>::RLrotation(Node *&t)
{
	LLrotation(t->left);
	RRrotation(t);
}

template <typename Comparable>
void AVL<Comparable>::LRrotation(Node *&t)
{
	RRrotation(t->right);
	LLrotation(t);
}

#endif // !AVL_H
