#include <iostream>

using namespace std;

void mergeArraysSorted(int* arr1, int size1, int* arr2, int size2, int* MergedArr) 
{
	int i = 0, j = 0, k = 0;

	while (i < size1 && j < size2) 
	{
		if (arr1[i] < arr2[j]) 
		{
			MergedArr[k++] = arr1[i++];
		}
		else 
		{
			MergedArr[k++] = arr2[j++];
		}
	}
	while (i < size1) 
	{
		MergedArr[k++] = arr1[i++];
	}
	while (j < size2)
	{
		MergedArr[k++] = arr2[j++];
	}
}

int main()
{
	int size1, size2;

	cout << "Enter the szie of the first array: ";
	cin >> size1;
	int* arr1 = new int[size1];

	cout << "Enter " << size1 << ", elements: ";

	for (int i = 0; i < size1; i++) 
	{
		cin >> arr1[i];
	}

	cout << "Enter the szie of the second array: ";
	cin >> size2;
	int* arr2 = new int[size2];

	cout << "Enter " << size2 << ", elements: ";

	for (int j = 0; j < size2; j++)
	{
		cin >> arr2[j];
	}

	int* MergedArr = new int[size1 + size2];

	mergeArraysSorted(arr1, size1, arr2, size2, MergedArr);

	cout << "Merged arrays: ";
	for (int k = 0; k < size1 + size2; k++) 
	{
		cout << MergedArr[k];
	}

	delete[] arr1;
	delete[] arr2;
	delete[] MergedArr;


}


