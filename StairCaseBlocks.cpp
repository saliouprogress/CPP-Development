#include <iostream>

using namespace std;

int main() 
{
	int N, totalBlocks = 1; 
	cin >> N;
	int remainingBlocks = N;
 
	for (totalBlocks = 1; totalBlocks <= remainingBlocks; totalBlocks++)
	{
          	remainingBlocks = remainingBlocks - totalBlocks; 
		cout << totalBlocks << ", " << remainingBlocks << endl;
        	//totalBlocks++; 
	}  	
	return 0;
}
