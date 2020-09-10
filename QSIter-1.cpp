#include <iostream>

using namespace std;

void display(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}


void swapIter(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int medianI(int arr[], int l, int h)
{
	int a = l;
	int b = h;
	int c = (l + h) / 2;
	if ((arr[a] < arr[b] && arr[b] < arr[c]) || (arr[c] < arr[b] && arr[b] < arr[a]))
		return b;
	else if ((arr[b] < arr[a] && arr[a] < arr[c]) || (arr[c] < arr[a] && arr[a] < arr[b]))
		return a;
	else
		return c;
}

int partition(int arr[], int l, int h)
	{
	int x = arr[medianI(arr, l, h)];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swapIter(&arr[i], &arr[j]);
		}
	}
	swapIter(&arr[i + 1], &arr[h]);
	return (i + 1);
	}

void quickSortIterative(int arr[], int l, int h)
{
	int stack[150];

	int top = -1;

	stack[++top] = l;
	stack[++top] = h;

	while (top >= 0) {
		//display(arr, 11);
		h = stack[top--];
		l = stack[top--];

		int p = partition(arr, l, h);
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}


int main()
{
	int arr[] = { 12,2,16,30,8,28,4,10,20,6,18 };
	display(arr, 11);
	quickSortIterative(arr, 0, 10);
	display(arr, 11);

	system("PAUSE");

	return 0;
}
