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
