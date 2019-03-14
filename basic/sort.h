#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;

template <typename Object, typename Comparator = less<Object>>//默认为调用<functional>中的less比较函数
class Sort
{
	Comparator lessThan;

public:

	void bubble(vector<Object> & arr);
	void insert(vector<Object> & arr);
	void select(vector<Object> & arr);
	void merge(vector<Object> & arr);
	void mergeWithoutRecursive(vector<Object> & arr);
	void quick(vector<Object> & arr);
	void shell(vector<Object> & arr);
	void heap(vector<Object> & arr);


private:

	void swap(Object & a, Object & b);
	void merge(vector<Object> & arr,size_t low, size_t high, vector<Object> & tempArr);
	void mergeHelper(vector<Object> & arr, size_t low, size_t mid, size_t high, vector<Object> & tempArr);
	void quick(vector<Object> & arr, int low, int high);
	void quickWithDuplication(vector<Object> & arr, int low, int high);
	int partition(vector<Object> & arr, int low, int high);
	int midThreePartition(vector<Object> & arr, int low, int high);
	void sink(vector<Object> & arr, int pos, int N);
};



//升序排列

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::bubble(vector<Object> &arr)
{
	for (size_t i = arr.size() - 1; i > 0; --i)
		for (size_t j = 0; j < i; ++j)
			if (lessThan(arr.at(j + 1), arr.at(j)))
				swap(arr.at(j + 1), arr.at(j));
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::insert(vector<Object> &arr)
{
	for (size_t i = 1; i < arr.size(); ++i) // i应该初始化为size_t，因为arr.size()返回值是无符号的
	{
		auto temp = std::move(arr.at(i));
		size_t j = i;										 // j不要初始化为i - 1，否则第24行必须是 j+1
		for (; j >= 1 && lessThan(temp, arr.at(j - 1)); --j) //可以将判断条件移至循环头
			arr.at(j) = std::move(arr.at(j - 1));

		arr.at(j) = std::move(temp);
	}
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::select(vector<Object> &arr)
{
	for (size_t i = 0; i < arr.size() - 1; ++i)
	{
		auto offset = i;
		for (size_t j = i + 1; j < arr.size(); ++j)
		{
			if (lessThan(arr.at(j), arr.at(offset)))
				offset = j;
		}
		swap(arr.at(i), arr.at(offset));
	}
}

//递归版归并排序
template <typename Object, typename Comparator>
void Sort<Object, Comparator>::merge(vector<Object> &arr)
{
	vector<Object> tempArr(arr.size());
	merge(arr, 0, arr.size() - 1, tempArr);
}

//非递归版归并排序
template <typename Object, typename Comparator>
void Sort<Object, Comparator>::mergeWithoutRecursive(vector<Object> &arr)
{
	size_t N = arr.size();
	vector<Object> tempArr(N);
	for (size_t size = 1; size < N; size *= 2)
		for (size_t low = 0; low < N - size; low += 2 * size)
		{
			size_t high = (low + size + size - 1 > N - 1) ? N - 1 : low + size + size - 1;
			mergeHelper(arr, low, low + size - 1, high, tempArr);
		}
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::quick(vector<Object> &arr)
{
	quickWithDuplication(arr, 0, arr.size() - 1);
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::shell(vector<Object> &arr)
{
	size_t len = arr.size();

	size_t N = len / 2;

	while (N > 0)
	{
		for (size_t i = N; i < len; ++i)
		{
			auto temp = std::move(arr.at(i));
			size_t j = i;
			for (; j >= N; j -= N)
			{
				if (lessThan(temp, arr.at(j - N)))
					arr.at(j) = std::move(arr.at(j - N));
				else
					break;
			}
			arr.at(j) = std::move(temp);
		}
		N /= 2;
	}
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::heap(vector<Object> &arr)
{
	//构造堆
	int N = arr.size() - 1;
	for (int k = (N - 1) / 2; k >= 0; --k) //涉及减法的循环最好还是用int型循环变量
		sink(arr, k, N);

	//依次将最大数放到最后
	while (N > 0)
	{
		swap(arr.at(0), arr.at(N--));
		sink(arr, 0, N);
	}
}

/*


private


*/

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::sink(vector<Object> &arr, int pos, int N)
{
	while ((2 * pos + 1) <= N) //一般的堆是从1开始计数的，这里从0开始，所以不是通常的2*pos
	{
		int j = 2 * pos + 1;
		if (j < N && lessThan(arr.at(j), arr.at(j + 1))) //挑更大的交换上去
			++j;

		if (lessThan(arr.at(pos), arr.at(j)))
			swap(arr.at(pos), arr.at(j));
		else
			break;

		pos = j;
	}
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::quick(vector<Object> &arr, int low, int high)
{

	if (low >= high)
		return;

	int position = midThreePartition(arr, low, high);
	quick(arr, low, position - 1);
	quick(arr, position + 1, high);
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::quickWithDuplication(vector<Object> &arr, int low, int high)
{
	if (low >= high)
		return;

	int lt = low, i = lt + 1, gt = high;
	auto par = arr.at(low);

	while (i <= gt)
	{
		if (lessThan(arr.at(i), par))
			swap(arr.at(i++), arr.at(lt++));
		else if (lessThan(par, arr.at(i)))
			swap(arr.at(i), arr.at(gt--));
		else
			i++;
	}
	quickWithDuplication(arr, low, lt - 1);
	quickWithDuplication(arr, gt + 1, high);
}

template <typename Object, typename Comparator>
int Sort<Object, Comparator>::partition(vector<Object> &arr, int low, int high)
{
	int shuffle = low + rand() % (high - low + 1);
	swap(arr.at(low), arr.at(shuffle));
	auto par = arr.at(low);
	int i = low, j = high + 1;

	while (true)
	{
		while (lessThan(arr.at(++i), par))
			if (i == high) //由于切分元素可能是最大值，所以不可忽略这一步
				break;

		while (lessThan(par, arr.at(--j)))
			if (j == low)
				break;

		if (i >= j) //应该在这里判断，而不是while循环头
			break;

		swap(arr.at(i), arr.at(j));
	}
	swap(arr.at(low), arr.at(j));
	return j;
}

template <typename Object, typename Comparator>
int Sort<Object, Comparator>::midThreePartition(vector<Object> &arr, int low, int high)
{
	int mid = (low + high) / 2;

	if (lessThan(arr.at(mid), arr.at(low)))
		swap(arr.at(mid), arr.at(low));

	if (lessThan(arr.at(high), arr.at(low)))
		swap(arr.at(high), arr.at(low));

	if (lessThan(arr.at(high), arr.at(mid)))
		swap(arr.at(high), arr.at(mid));

	swap(arr.at(high - 1), arr.at(mid));

	//由于mid是向下取整的，所以只能把par放在右边而不是左边，否则在low与high相邻的时候会下标越界
	int i = low, j = high - 1;
	auto par = arr.at(high - 1);

	while (true)
	{
		while (lessThan(arr.at(++i), par))
			;
		while (lessThan(par, arr.at(--j)))
			;
		if (i >= j)
			break;
		swap(arr.at(i), arr.at(j));
	}

	swap(arr.at(i), arr.at(high - 1));

	return i;
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::merge(vector<Object> &arr, size_t low, size_t high, vector<Object> &tempArr)
{
	if (low >= high)
		return;

	size_t mid = (low + high) / 2;

	merge(arr, low, mid, tempArr);
	merge(arr, mid + 1, high, tempArr);
	mergeHelper(arr, low, mid, high, tempArr);
}

template <typename Object, typename Comparator>
void Sort<Object, Comparator>::mergeHelper(vector<Object> &arr, size_t low, size_t mid, size_t high, vector<Object> &tempArr)
{
	size_t i = low, j = mid + 1;
	for (size_t k = low; k <= high; ++k)
	{
		if (i > mid)
			tempArr.at(k) = std::move(arr.at(j++));
		else if (j > high)
			tempArr.at(k) = std::move(arr.at(i++));
		else if (lessThan(arr.at(i), arr.at(j)))
			tempArr.at(k) = std::move(arr.at(i++));
		else
			tempArr.at(k) = std::move(arr.at(j++));
	}

	for (size_t p = low; p <= high; p++)
		arr.at(p) = std::move(tempArr.at(p));
}

template <typename Object, typename Comparator>
inline void Sort<Object, Comparator>::swap(Object &a, Object &b)
{
	auto temp = std::move(b);
	b = std::move(a);
	a = std::move(temp);
}

#endif // !SORT_H

