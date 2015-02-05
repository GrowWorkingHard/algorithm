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

#include <stdlib.h>
#include <stdio.h>  // printf command

#include <algorithm.h>

using namespace std;

int main() {

	vector<double> tmp_vec;

	tmp_vec.push_back(0.8);
	tmp_vec.push_back(2.0);
	tmp_vec.push_back(5.5);

	double min_value = algo::algorithm::min(tmp_vec);
	printf("Min value: %f\n", min_value);

	size_t dim = tmp_vec.size() - 1;
	size_t dim1 = 0;
	double val = 5.5;
	size_t pos = algo::algorithm::binary_search(tmp_vec, val, dim1, dim);
	printf("Position of 5.5: %zu\n", pos);
	return 0;

}
