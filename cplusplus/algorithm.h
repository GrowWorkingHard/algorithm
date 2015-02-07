//************************************************************************************//
//*          - GrowWorkingHard'script - www.growworkinghard.wordpress.com -          *//
//************************************************************************************//
//                                                                                    //
// This file is a script writed to complete our blog's articles (all the external     //
// reference can be found there). It's needed to explain better concepts and give     //
// to the users an example or a reference.                                            //
// We don't give you the warranty that is the best solution, but we do all the        //
// possible to hit it.                                                                //
//                                                                                    //
// You're invited to try our solution and communicate if something does't work or if  //
// there is a better way to do it!                                                    //
//                                                                                    //
// Follow our blog: <http://www.growworkinghard.wordpress.com>                        //
//                                                                                    //
// Author: francescoS                                                                 //
// Date: 2015-02-03                                                                   //
//                                                                                    //
//************************************************************************************//

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <stdlib.h>
#include <vector>
#include <math.h>       /* round, floor, ceil, trunc */
#include <iostream>     /* cout */

using namespace std;

namespace algo {

class algorithm {
	public:
		template<typename T>
		static T min(vector<T>& i_vec);
		template<typename T>
		static size_t min(vector<T>& i_vec, size_t& start_index, size_t& end_index);
		template<typename T>
		static size_t binary_search(vector<T>& i_vec, T& v, size_t& i, size_t& j);
		template<typename T>
		static void selection_sort(vector<T>& i_vec);

};

/**
 * @brief This function finds the minimum value contained in an array
 *
 * @param i_vec The vector to process
 * @return min The minimum value contained in the input vector
 */
template<typename T>
T algorithm::min(vector<T>& i_vec)
{

	T* min = &i_vec[0];

	for (size_t i=1; i<i_vec.size(); i++)
		if (i_vec[i] < *min) min = &i_vec[i];

	return *min;

}

template<typename T>
size_t algorithm::min(vector<T>& i_vec, size_t& start_index, size_t& end_index)
{

	size_t min_index = start_index;
	for (size_t i=start_index+1; i<end_index; i++)
		if (i_vec[i] < i_vec[min_index]) min_index = i;

	return min_index;

}

template<typename T>
size_t algorithm::binary_search(vector<T>& i_vec, T& v, size_t& i, size_t& j)
{

	if ( i > j ) return 0;
	else {

		size_t m = floor((i+j)/2);

		if (i_vec[m] == v) return m;
		else if (i_vec[m] < v) {
			m = m + 1;
			return binary_search(i_vec, v, m, j);
		} else {
			m = m - 1;
			return binary_search(i_vec, v, i, m);
		}

	}

}

template<typename T>
void algorithm::selection_sort(vector<T>& i_vec)
{

	T tmp_val;
	size_t min_index;
	size_t vec_dim = i_vec.size();

	for (size_t i=0; i<vec_dim; i++) {

		min_index = min(i_vec, i, vec_dim);

		tmp_val = i_vec[i];
		i_vec[i] = i_vec[min_index];
		i_vec[min_index] = tmp_val;

	}

}

}

#endif
