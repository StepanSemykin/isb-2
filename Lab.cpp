#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

int* sequence_generation(size_t len)
{
	int* arr = new int[len];
	srand(time(0));

	for (size_t i = 0; i < len; ++i)
	{
		arr[i] = rand() % 2;
	}

	return arr;
}

double bit_frequency_test(int* arr, size_t len)
{
	double sum = 0;

	for (size_t i = 0; i < len; ++i) sum += arr[i] ? 1 : -1;

	//cout << sum << endl;
	sum /= sqrt(len);
	//cout << sum << endl;
	//cout << erfc(sum / sqrt(2)) << endl;
	return erfc(sum / sqrt(2));
}

