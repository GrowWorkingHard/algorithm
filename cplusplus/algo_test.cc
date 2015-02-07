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

#include <stdlib.h>
#include <stdio.h>  // printf command

#include <algorithm.h>

using namespace std;

int main() {

	vector<char> tmp_vec;

	tmp_vec.push_back('a');
	tmp_vec.push_back('w');
	tmp_vec.push_back('f');
	tmp_vec.push_back('c');
	tmp_vec.push_back('s');
	tmp_vec.push_back('z');
	tmp_vec.push_back('n');

	char min_value = algo::Algorithm::min(tmp_vec);
	printf("Min value: %c\n", min_value);

	algo::Algorithm::selection_sort(tmp_vec);

	for (size_t i=0; i<tmp_vec.size(); i++) {

		printf("Position %zu, value %c\n", i+1, tmp_vec[i]);

	}

	return 0;

}
