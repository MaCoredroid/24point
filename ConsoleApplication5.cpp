// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
int num=0;
int ans=0;
int l = 0;
std::vector<double> a(1, 0);
void sou(int sum,int ans)
{
	int q = 1;
	
	bool flag1 = 1;
	
	for (int i = 1; i <= sum; i++)
	{
		q *= a[i];

		if (a[i] < 1)
		{
			flag1 = 0;
		}
		
		
	}
	if (flag1&&ans>q)
	{
		return;
	}
	int m, n;
	if (l == 1)
		return;
	if (sum == 1 &&( (a[1]<=ans+0.000001)&&(a[1] >= ans - 0.000001)))
	{
		std::cout<<"True";
		l = 1;
		exit(0);
	}
	for (int i = 1; i < sum; i++)
		for (int j = i + 1; j <= sum; j++)
		
			

			for (int k = 1; k <= 5; k++)
			{
				m = a[i];
				n = a[j];
				switch (k)
				{
				case 1:
					a[i] += a[j];
					a[j] = a[sum];
					sou(sum - 1, ans);
					break;
				case 2:
					a[i] -= a[j];
					a[j] = a[sum];
					sou(sum - 1, ans);
					break;
				case 3:
					a[i] *= a[j];
					a[j] = a[sum];
					sou(sum - 1, ans);
					break;
				case 4:
					if (a[j])
					{
						a[i] /= a[j];
						a[j] = a[sum];
						sou(sum - 1, ans);
					}
					break;
				case 5:
					a[j] -= a[i];
					a[i] = a[sum];
					sou(sum - 1, ans);
					break;
				/*case 6:
					if (a[i])
					{
						a[j] /= a[i];
						a[i] = a[sum];
						sou(sum - 1, ans);
					}
					break;*/
				}
				a[i] = m;
				a[j] = n;
			}
		
}
int main()
{
	
	std::cin >> num >> ans;
	int q = 1;
	
	a.resize(num+1);
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		std::cin >> temp;
		q *= temp;
	
		a[i + 1] = temp;
	}
	if (ans > q)
	{
		std::cout << "False";
		return 0;
	}
	sou(num,ans);
	std::cout<<"False";
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
