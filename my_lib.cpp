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
			return static_cast<float>((vekt[size / 2 - 1] + vekt[size / 2])) / 2;
		}
		else
		{
			return vekt[size / 2];
		}
	}
}