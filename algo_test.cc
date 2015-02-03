#include <stdlib.h>
#include <stdio.h>  // printf command

#include <algorithm.h>

using namespace std;

int main() {

	vector<double> tmp_vec;

	tmp_vec.push_back(2.0);
	tmp_vec.push_back(5.5);
	tmp_vec.push_back(0.8);

	double min_value = algo::algorithm::min(tmp_vec);
	printf("Min value: %f\n", min_value);

	return 0;

}
