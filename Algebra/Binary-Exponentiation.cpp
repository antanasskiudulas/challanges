#include <iostream>

using namespace std;
typedef long long llint;

llint BinaryExponentiation(llint a, llint n)
{
	if (n == 0)
		return 1;

	llint out = BinaryExponentiation(a, n >> 1);

	if (n & 1)
		return out * out * a;
	else
		return out * out;
}

//iterative approach to binary exponentiation
llint ItBinExp(llint a, llint n)
{
	int out = a;
	while (n != 1)
	{
		out = out * out;
		n >>= 1;
	}
	return out;
}

int main()
{
	int a, n;
	cin >> a >> n;

	cout << ItBinExp(a, n) << "\n";
	
}