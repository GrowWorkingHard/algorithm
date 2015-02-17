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
//************************************************************************************//

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <stdlib.h>
#include <vector>
#include <math.h>       /* round, floor, ceil, trunc */
#include <iostream>     /* cout */

using namespace std;

namespace algo {

/**
 * @class Algorithm
 * @brief
 *
 * @ingroup cplusplus
 * @author francescoS
 * @date   2015-02-02
 */
class Algorithm {
	public:

		/**
		 * @brief This function finds the minimum value contained in an array
		 *
		 * @param  i_vec The vector to process
		 * @return min   The minimum value contained in the input vector
		 */
		template<typename T>
		static void min(vector<T>& i_vec, T* min);

		template<typename T>
		static size_t binary_search(vector<T>& i_vec, T& v);

		/**
		 * @brief This function finds the searched value in a sorted array
		 *
		 * @param  i_vec The sorted vector
		 * @param  v     The searched value
		 * @param  i     The index of the first element of the array
		 * @param  j     The index of the last element of the array
		 * @return m     The index of the search value
		 */
		template<typename T>
		static size_t binary_search(vector<T>& i_vec, T& v, size_t& i, size_t& j);

		/**
		 * @brief This function
		 *
		 * @param i_vec The input vector
		 */
		template<typename T>
		static void selection_sort(vector<T>& i_vec);

	private:

		/**
		 * @brief Exchage the value between two elements
		 *
		 * @param elem_a The A element
		 * @param elem_b The B element
		 */
		template<typename T>
		static void exchage_value(T& elem_a, T& elem_b);

		/**
		 * @brief This function finds the minimum value contained in an part of the array
		 *
		 * @param  i_vec       The vector to process
		 * @param  start_index Index of the first element of the sub-array
		 * @param  end_index   Index of the last element of the sub-array
		 * @return min_index   The index of minimum value contained in the sub part of the input vector
		 */
		template<typename T>
		static size_t min(vector<T>& i_vec, size_t& start_index, size_t& end_index);

};

template<typename T>
void Algorithm::min(vector<T>& i_vec, T* min)
{

	*min = i_vec[0];

	for (size_t i=1; i<i_vec.size(); i++)
		if (i_vec[i] < *min) *min = i_vec[i];

}

template<typename T>
size_t Algorithm::binary_search(vector<T>& i_vec, T& v)
{

	size_t start = 0;
	size_t end = i_vec.size();
	return binary_search(i_vec, v, start, end);

}

template<typename T>
size_t Algorithm::binary_search(vector<T>& i_vec, T& v, size_t& i, size_t& j)
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
void Algorithm::selection_sort(vector<T>& i_vec)
{

	size_t min_index;
	size_t vec_dim = i_vec.size();

	for (size_t i=0; i<vec_dim; i++) {

		min_index = min(i_vec, i, vec_dim);
		exchage_value(i_vec[i], i_vec[min_index]);

	}

}

template<typename T>
void Algorithm::exchage_value(T& elem_a, T& elem_b)
{

	T tmp_val = elem_a;
	elem_a = elem_b;
	elem_b = tmp_val;

}

template<typename T>
size_t Algorithm::min(vector<T>& i_vec, size_t& start_index, size_t& end_index)
{

	size_t min_index = start_index;
	for (size_t i=start_index+1; i<end_index; i++)
		if (i_vec[i] < i_vec[min_index]) min_index = i;

	return min_index;

}

} // end of namespace
#endif
