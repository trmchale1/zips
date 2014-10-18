#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
void sortInt(string realFiveDigitZips[], int code[], int fiveDigitZipsCounter)	
{
	string temp;
	int temp2 = 0;
	for(int c = 0; c < fiveDigitZipsCounter-1; c++)
	{
		for(int d = 0; d < fiveDigitZipsCounter-1-c; d++)
		{
			if(code[d+1] > code[d])
			{
				temp2 = code[d];
				temp = realFiveDigitZips[d];
				code[d] = code[d+1];
				realFiveDigitZips[d] = realFiveDigitZips[d+1];
				code[d+1] = temp2;
				realFiveDigitZips[d+1] = temp;

			}

	
		}
	}

}

bool is5Digits(string s){
	bool is5Digits = true;
	
	if(s.size() !=5) return false;
		for (int i = 0; i <5; i++)
		{
			is5Digits = (s[i]<48 ? false : s[i] >57 ? false : true);
		}
	return is5Digits;
}

int main()
{
	const int MAX = 10000;
	string tokenx;
	int fiveDigitZipsCounter = 0;
	cin >> tokenx;
	string realFiveDigitZips[MAX];
	while(!cin.fail())
	{
		if(tokenx=="zip:")
		{	
			cin >> tokenx;
			if(is5Digits(tokenx)){
				realFiveDigitZips[fiveDigitZipsCounter] = tokenx;
				fiveDigitZipsCounter++;
			}
		
		}
	
	cin >> tokenx;
	
	}		

	for (int i = fiveDigitZipsCounter; i < MAX; i++)
	{
		realFiveDigitZips[i] = "NOZIPCODE";
	}

	// Added sort function
	
	sort(realFiveDigitZips, realFiveDigitZips+fiveDigitZipsCounter);

// so far correctly sorted
/*
	for(int b = 0; b < fiveDigitZipsCounter; b++)
	{
		cout << realFiveDigitZips[b] << endl;

	}
*/
//	cout << fiveDigitZipsCounter << endl;

	string proFinalArray[MAX];
	int n_unduplicated = 0;

// starting the array search at 0 could be a problem it is comparing to an 
	proFinalArray[0] = realFiveDigitZips[0];
	n_unduplicated++;
	for (int x = 1; x < fiveDigitZipsCounter; x++)
	{	
		
		if(realFiveDigitZips[x] != realFiveDigitZips[x-1])
		{
			proFinalArray[n_unduplicated] = realFiveDigitZips[x];
			n_unduplicated++;
		}
	}
	
	for(int k = 0; k < n_unduplicated; k++)
	{
		cout << proFinalArray[k] << endl;
	}
	
	int Frequency[MAX];
	int freq_counter = 0;

	for(int i = 0; i < n_unduplicated; i++)
		{
//			cout << finalArray[i] << endl;

			freq_counter = 0;

			for(int p = 0; p < fiveDigitZipsCounter; p++)
			{
				if(proFinalArray[i] == realFiveDigitZips[p])
				{
					freq_counter++;
				}

			Frequency[i] = freq_counter;
		
			
			}
		}

	sortInt(proFinalArray, Frequency, n_unduplicated);

	
	for(int k = 0; k < n_unduplicated; k++)
	{
		cout << "This is the zip code: " << proFinalArray[k] << " and this is its frequency: " << Frequency[k] << endl;
	}

	string temp3;
	for(int a = 0; a < n_unduplicated-1; a++)
	{
		for(int b = 1; b < n_unduplicated-1-a; b++)
		{
			if(Frequency[b-1] == Frequency[b])
			{
				if(proFinalArray[b-1] > proFinalArray[b])
				{
					temp3 = proFinalArray[b];
					proFinalArray[b-1] = proFinalArray[b];
					proFinalArray[b] = temp3;					
				}
			}
		}

	}
	
	for(int k = 0; k < n_unduplicated; k++)
	{
		cout << "This is the zip code: " << proFinalArray[k] << " and this is its frequency: " << Frequency[k] << endl;
	}
	return 0;
	
}	
