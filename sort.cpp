//�Ƚ������㷨��
//      �㷨               ����       ���Ӷ�   /ʱ        /��      �ȶ���

//	1.��������--><1>ð������ bubblesort (O(n)-O(n^2),O(1))          �ȶ�
//				 <2>�������� quicksort  (O(nlogn)-O(n^2),O(logn))  ���ȶ�
//	2.��������--><1>�������� Insertsort (O(n)-O(n^2),O(1))          �ȶ�
//				 <2>ϣ������ shellsort  (O(n^1.3)-O(n^2),O(1))	   ���ȶ�
//	3.ѡ������--><1>ѡ������ selectsort (O(n^2)-O(n^2),O(1))        �ȶ�
//				 <2>������   heapsort   (O(nlogn)-O(nlogn),O(1))   ���ȶ�
//  4.�鲢����--><1>��·�鲢 mergesort  (O(nlogn)-O(nlogn),O(n))    �ȶ�
//				 <2>��·�鲢 moremergesort (O(nlogn)-O(nlogn),O(n)) �ȶ�
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//ð�������Ż���
void bubblesort(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		bool flag = false;
		for (int j = 0; j < v.size() - i - 1; ++j)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

//��������
int partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int pLeft = left + 1;
	int pRight = right;
	while (pLeft <= pRight)
	{
		while (pLeft <= pRight && v[pLeft] <= pivot) pLeft++;
		while (pLeft <= pRight && v[pRight] >= pivot) pRight--;
		if (pLeft < pRight) {
			swap(v[pLeft], v[pRight]);
		}
	}

	swap(v[left], v[pRight]);
	return pRight;
}
void quicksort(vector<int>& v, int left, int right)
{
	if (left >= right) return;
	int pivot = partition(v, left, right);
	quicksort(v, left, pivot - 1);
	quicksort(v, pivot + 1, right);
}


//��������
void Insertsort(vector<int>& v)
{
	for (int i = 1; i < v.size(); ++i)
	{
		int mark = i;
		for (int j = i - 1; j >= 0; --j)
		{
			if (v[mark] < v[j])
			{
				swap(v[mark--], v[j]);
			}
		}
	}
}
	
//ϣ������
void shellsort(vector<int>& v)
{
	for (int grp = v.size() / 2; grp >= 1; grp /= 2)
	{
		for (int i = grp; i < v.size(); ++i)
		{
			int compval = v[i];
			int j = i - grp;
			while (j >= 0 && v[j] >= compval)
			{
				v[j + grp] = v[j];//v[i]=v[j];
				j -= grp;
			}
			v[j + grp] = compval;//v[j]=v[i];
		}
	}
}


//ѡ������
void selectsort(vector<int>& v)
{
	int minidx = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		minidx = i;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] < v[minidx])
			{
				minidx = j;
			}
		}
		swap(v[i], v[minidx]);
	}
}

//������
void heapsort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < v.size(); ++i)
	{
		q.push(v[i]);
	}
	for (int j = 0; j < v.size(); ++j)
	{
		v[j] = q.top();
		q.pop();
	}
}



//�鲢����
void merge(vector<int>& v, int left, int mid, int right)
{
	vector<int> v1(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		v1[k++] = v[i] < v[j] ? v[i++] : v[j++];
	}
	while (i <= mid)v1[k++] = v[i++];
	while (j <= right)v1[k++] = v[j++];
	for (i = 0; i < v1.size(); ++i)
	{
		v[left + i] = v1[i];
	}
}
void mergesort(vector<int>& v, int left, int right)
{
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	mergesort(v, left, mid);
	mergesort(v, mid + 1, right);
	merge(v, left, mid, right);
}


int main()
{
	vector<int> v1;
	v1.emplace_back(49);
	v1.emplace_back(38);
	v1.emplace_back(65);
	v1.emplace_back(97);
	v1.emplace_back(76);
	v1.emplace_back(13);
	v1.emplace_back(27);
	v1.emplace_back(49);
	//bubblesort(v1);
	//quicksort(v1,0,v1.size()-1);
	//Insertsort(v1);
	//shellsort(v1);
	//selectsort(v1);
	//heapsort(v1);
	
	//mergesort(v1,0,v1.size()-1);
	
	//int num = 0;
	////ѭ������һ������
	//while (cin >> num) 
	//{
	//	v1.emplace_back(num);
	//	if ('\n' == cin.get()) 
	//	{
	//		break;
	//	}
	//}
	for (auto &it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}