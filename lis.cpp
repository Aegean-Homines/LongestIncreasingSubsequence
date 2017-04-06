#include "lis.h"

std::vector<unsigned> 
longest_increasing_subsequence( std::vector<int> const& sequence ) {
    //allocated/reserve table, init all to 0 - including init case

    //main logic
	int length = sequence.size();
    //reconstruct subsequence
    std::vector<unsigned> answer( length,0 ); //vector of indices corresponding to the LIS
    //....
    return answer;
}
