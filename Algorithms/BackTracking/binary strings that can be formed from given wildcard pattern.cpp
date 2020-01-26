#include <bits/stdc++.h>
using namespace std;

void printAllCombinations(char pattern[], int idx)
{
	if (pattern[idx] == '\0')
	{
		cout << pattern << endl;
		return;
	}

		if(pattern[idx] == '?'){
			pattern[idx] = '1';
			printAllCombinations(pattern,idx+1);
			pattern[idx] = '?';

			pattern[idx] = '0';
			printAllCombinations(pattern,idx+1);
			pattern[idx] = '?';
			
			return;
		}
	else
		printAllCombinations(pattern,idx+1);

}

// main function
int main()
{
	char pattern[] = "1?11?00?1?";

	printAllCombinations(pattern, 0);

	return 0;
}