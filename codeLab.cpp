#include<iostream>
using namespace std;
void sort(int arr[], int counter)	
{
	int temp = 0;
	for(int c = 0; c < counter-1; c++)
	{
		for(int d = 0; d < counter-1-c; d++)
		{
			if(arr[d+1] < arr[d])
			{
				temp = arr[d];
				arr[d] = arr[d+1];
				arr[d+1] = temp;
			}
		}
	}
}

int main(){
	
	int x = 0;
	int arr[200];

	while(x != 110)
	{
		cin >> arr[x];
		x++;
	}

	sort(arr,x);
	
	for(int k = 0; k < x; k++)
	{
		cout << k  << " " << arr[k] << endl;
	}
	
	int proFinalArray[100];
	int n_unduplicated = 0;

	proFinalArray[0] = arr[0];
	n_unduplicated++;
	for (int i = 1; i < x; i++)
	{	
		
		if(arr[i] != arr[i-1])
		{
			proFinalArray[n_unduplicated] = arr[i];
			n_unduplicated++;
		}
	}
	
	for(int j = 0; j < n_unduplicated; j++)
	{
		cout << j << " "<< proFinalArray[j] << endl;	
	}
	
}
