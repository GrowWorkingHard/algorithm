#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <stdlib.h>
#include <vector>

using namespace std;

namespace algo {

class algorithm {
	public:
		template<typename T>
		static T min(vector<T>& i_vec);

};

template<typename T>
T algorithm::min(vector<T>& i_vec)
{

	T min = i_vec[0];

	for (size_t i=1; i<i_vec.size(); i++)
		if (i_vec[i] < min) min = i_vec[i];

	return min;

}

}

#endif
