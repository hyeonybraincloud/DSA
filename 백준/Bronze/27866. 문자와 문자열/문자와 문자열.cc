#include <iostream>
#define MAXLEN 1000

using namespace std;

int main()
{
	char S[MAXLEN];
	int i;

	cin >> S;
	cin >> i;

	cout << S[i - 1] << endl;

	return 0;
}