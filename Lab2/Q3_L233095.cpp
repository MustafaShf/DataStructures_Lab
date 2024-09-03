#include<iostream>
using namespace std;

int main()
{
	int arr[] = { 1,2,5,3,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ans;
	int k;
    cout<<"Array\n";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
	cout << "What smallest kth digit you want?\n";
	cin >> k;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	if (k < 0 || k >= size)
		cout << "Wrong input\n";
	else
	cout << arr[k];

}