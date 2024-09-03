#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 1,2,5,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array\n";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
	int k = size - 1;
	if (size % 2 == 0)
	{
		for (int i = 0; i < size / 2; i++,k--)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
	else {
		for (int i = 0; i < (size / 2)-1; i++, k--)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
    cout<<endl;
    cout<<"New Array\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}