#include <iostream>
using namespace std;

int main() 
{
	int N, totalBlocks = 1; 
	cin >> N;
	int remainingBlocks = N;
 
	while ( totalBlocks <= remainingBlocks)
	{
          	remainingBlocks = remainingBlocks - totalBlocks; 
		cout << totalBlocks << ", " << remainingBlocks << endl;
        	totalBlocks++; 
	}  	
	return 0;
}
