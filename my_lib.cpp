#include "my_lib.h"

float vidurkis(vector<int> vekt)
{
	size_t size = vekt.size();

	if (size == 0)
	{
		return 0;
	}
	else
	{
		return static_cast<float>(accumulate(vekt.begin(), vekt.end(), 0)) / size;
	}

}

double mediana(vector<int> vekt)
{
	size_t size = vekt.size();

	if (size == 0)
	{
		return 0;
	}
	else
	{
		sort(vekt.begin(), vekt.end());
		if (size % 2 == 0)
		{
			return static_cast<float>(vekt[((size / 2) -1)] + vekt[size / 2]) / 2;
		}
		else
		{
			return vekt[size / 2];
		}
	}
}


vector <int> random(int n)
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };
	uniform_int_distribution<int> dist{ 1, 10 };
	auto gen = [&dist, &mersenne_engine]() {
		return dist(mersenne_engine);
		};
	vector<int> vec(n);
	generate(begin(vec), end(vec), gen);
	return vec;
}

bool pagalvarda(const studentas& a, const studentas& b) {
	return a.vard < b.vard;
}


bool pagalrez(const studentas& a, const studentas& b) {
	return a.mgrez < b.mgrez;
}

bool pagalrez3(const studentas3& a, const studentas3& b) {
	return a.mgrez < b.mgrez;
}

bool pagalrez2(const studentas2& a, const studentas2& b) {
	return a.mgrez < b.mgrez;
}

bool rezultatas(const studentas& a) {
	return a.mgrez >= 5;
}

bool rezultatas3(const studentas3& a) {
	return a.mgrez >= 5;
}
bool rezultatas4(const studentas4& a) {
	return a.mgrez >= 5;
}
bool pagalrez4(const studentas4& a, const studentas4& b) {
	return a.mgrez < b.mgrez;
}