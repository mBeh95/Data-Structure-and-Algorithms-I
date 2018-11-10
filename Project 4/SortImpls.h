
#include <iostream>
#include <vector>
using namespace std;

//DONE
void Merge(vector<int> &arr, int first, int mid, int last)
{
	int *tempArr;
	int size = last - first + 1;
	tempArr = new int[size];
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = 0;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (arr[first1] < arr[first2])
		{
			tempArr[index] = arr[first1];
			first1++;
		}
		else
		{
			tempArr[index] = arr[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1)
	{
		tempArr[index] = arr[first1];
		first1++;
		index++;
	}

	while (first2 <= last2)
	{
		tempArr[index] = arr[first2];
		first2++;
		index++;
	}

	for (index = 0; index < size; index++)
	{
		arr[first] = tempArr[index];
		first++;
	}

	delete[] tempArr;
}

//DONE
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//DONE
void MergeSort(vector<int> &arr, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(arr, first, mid);
		MergeSort(arr, mid + 1, last);
		Merge(arr, first, mid, last);
	}
}


void IterativeMergeSort(vector<int> &arr, int first, int last)
{
	/*int *tempArr;
	int size = last - first + 1;
	int mid = (first + last) / 2;
	tempArr = new int[size];

	int index = 0;
	int index1 = 0;
	int index2 = 2;


	for (int i = 0; i < arr.size() - 1; i += 2)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	for (int i = 0; i < arr.size() - 1; i += 4)
	{
		while ((index1 < index1 + 2) && (index2 < index2 + 2))
		{
			if (arr[index1] > arr[index2])
			{
				tempArr[index] = arr[index2];
				index2++;
				index++;
			}
			else
			{
				tempArr[index] = arr[index1];
				index1++;
				index++;
			}
		}
	}

	for (index = 0; index < arr.size(); index++)
	{
		arr[index] = tempArr[index];
	}

	delete[] tempArr;*/

}



//BUBBLE DONE!!!
void BubbleSort(vector<int> &arr, int first, int last)
{
	int size = (last - first) + 1;
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//INSERTION DONE
void InsertionSort(vector<int> &arr, int first, int last)
{
	int size = (last - first) + 1;
	for (int i = 1; i < size; i++)
	{
		int j = i;
		int copy = arr[i];

		while ((j > 0) && (arr[j - 1] > copy))
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = copy;

	}
}

//QUICKSORT DONE
void QuickSort(vector<int> &arr, int first, int last)
{
	if (last - first < 4)
	{
		InsertionSort(arr, 0 ,arr.size()-1);
		return;
	}
	int mid = (first + last) / 2;
	if (arr[first] > arr[last])
	{
		swap(arr[first], arr[last]);
	}
	if (arr[first] > arr[mid])
	{
		swap(arr[first], arr[mid]);
	}
	else if (arr[mid] > arr[last])
	{
		swap(arr[mid], arr[last]);
	}
	int pivot = arr[mid];
	swap(arr[mid], arr[last - 1]);
	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done)
	{
		while (arr[left] < pivot)
		{
			left++;
		}
		while (arr[right] > pivot)
		{
			right--;
		}
		if (right > left)
		{
			swap(arr[left], arr[right]);
			right--;
			left++;
		}
		else
		{
			done = true;
		}
	}
	swap(arr[left], arr[last - 1]);
	QuickSort(arr, first, left - 1);
	QuickSort(arr, left + 1, last);


}

//SHELLSORT DONE
void ShellSort(vector<int> &arr, int first, int last)
{
	int gap;
	int size = (last - first) + 1;
	for (gap = size / 2; gap > 0; gap = int(gap / 2.2))
	{
		for (int i = gap; i < size; i++)
		{
			for (int j = i - gap; j >= 0; j -= gap)
			{
				while (arr[j] > arr[j + gap])
				{
					swap(arr[j], arr[j + gap]);
				}
			}
		}
	}
}
