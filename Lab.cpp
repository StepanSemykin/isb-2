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

double bit_pattern_test(int* arr, size_t len)
{
	double share = 0;

	for (size_t i = 0; i < len; ++i) share += arr[i];

	share /= len;

	if (!(abs(share - 0.5) < (2 / sqrt(len)))) return 0;

	double v = 0;

	for (size_t i = 0; i < len - 1; ++i) v += (arr[i] = arr[i + 1] ? 0 : 1);

	return erfc(abs((v - 2 * len * share * (1 - share)) / (2 * sqrt(2 * len) * share * (1 - share))));
}

double long_sequence_test(int* arr, size_t len)
{
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v_max = 0, count = 0;

	for (size_t i = 0; i <= 120; i += 8)
	{
		v_max = 0;
		count = 0;
		for (size_t j = 0; j < 7; ++j)
		{
			if (count > v_max) v_max = count;
			if (arr[j + i] == 1 && arr[j + i + 1] == 1) count++;
			else count = 0;
		}
		if (count > v_max) v_max = count;
		v_max++;
		if (v_max <= 1) v1++;
		else if (v_max == 2) v2++;
		else if (v_max == 3) v3++;
		else if(v_max >= 4) v4++;
	}

	double x = (((v1 - 16 * 0.2148) * (v1 - 16 * 0.2148)) / 16 * 0.2148) + (((v2 - 16 * 0.3672) * (v2 - 16 * 0.3672)) / 16 * 0.3672) + (((v3 - 16 * 0.2305) * (v3 - 16 * 0.2305)) / 16 * 0.2305) + (((v4 - 16 * 0.1875) * (v4 - 16 * 0.1875)) / 16 * 0.1875);

	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int* a = sequence_generation(128);

	for (size_t i = 0; i < 128; ++i)
	{
		cout << a[i];
	}

	cout << endl;

	cout << "Частотный побитовый тест P = " << bit_frequency_test(a, 128) << endl;
	cout << "Тест на одинаковые подряд идущие биты P = " << bit_pattern_test(a, 128) << endl;
	double b = long_sequence_test(a, 128);
	cout << "Тест на самую длинную последовательность единиц в блоке x = " << b << endl;

	return 0;
}
