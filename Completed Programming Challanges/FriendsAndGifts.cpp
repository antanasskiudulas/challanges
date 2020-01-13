// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> Solution(vector<int> gifts)
{
	vector<int> counter(gifts.size());
	for (int i = 0; i < gifts.size(); i++)
		if (gifts[i] != 0)
			counter[gifts[i] - 1]++;

	list<int> missingNumbers;
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i] == 0)
			missingNumbers.push_front(i + 1);
	}

	int lastInsertedPos;
	for (int i = 0; i < gifts.size(); i++)
	{
		if (gifts[i] == 0)
		{
			if (i + 1 != missingNumbers.front())
			{
				gifts[i] = missingNumbers.front();
				missingNumbers.pop_front();
			}
			else if (missingNumbers.size() == 1 && i+1 == missingNumbers.front())
			{
				int temp = missingNumbers.front();
				gifts[i] = gifts[lastInsertedPos];
				gifts[lastInsertedPos] = temp;
				missingNumbers.pop_back();
			}
			else
			{
				gifts[i] = missingNumbers.back();
				missingNumbers.pop_back();
			}
			lastInsertedPos = i;
		}
	}
	return gifts;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> input(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input[i] = temp;
	}


	auto answer = Solution(input);

	for (int i : answer)
		cout << i << " ";

	return 0;
}
