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

