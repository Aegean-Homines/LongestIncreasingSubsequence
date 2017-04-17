#include "lis.h"
#include <utility>

#define IS_ITERATIVE true

#if IS_ITERATIVE
// I need a 2D array for iterative implementation
//typedef std::vector<std::vector<unsigned> > LookupTable;
// vector of pair<parentIndex, LIS_size>
typedef std::pair<unsigned, unsigned> TableEntry;
typedef std::vector<TableEntry > LookupTable;

#else
typedef std::vector<unsigned> LookupTable;
#endif

#if IS_ITERATIVE
std::vector<unsigned> 
longest_increasing_subsequence( std::vector<int> const& sequence ) {
    //allocated/reserve table, init all to 0 - including init case
	LookupTable table(sequence.size(), std::make_pair(0, 0));

	unsigned LISIndex = 0;
	table[0] = std::make_pair(0, 1); // first element
	for (unsigned int i = 1; i < sequence.size(); ++i) {
		TableEntry offlineResult(i, 1);
		for (unsigned int j = 0; j < i; ++j) {
			if(sequence[i] > sequence[j] 
				&& table[j].second >= offlineResult.second) {
				offlineResult.first = j;
				offlineResult.second = table[j].second + 1;
			}
		}
		if (offlineResult.second > table[LISIndex].second)
			LISIndex = i;
		table[i] = offlineResult;
	}

	unsigned int length = table[LISIndex].second;
	std::vector<unsigned> answer(length);
	for (unsigned int i = length - 1; i != 0; --i) {
		answer[i] = LISIndex;
		LISIndex = table[LISIndex].first;
	}

	answer[0] = table[LISIndex].first;
	return answer;

}
#else
std::vector<unsigned>
longest_increasing_subsequence(std::vector<int> const& sequence) {
	//allocated/reserve table, init all to 0 - including init case
	LookupTable table;

	//main logic
	int length = sequence.size();
	//reconstruct subsequence
	std::vector<unsigned> answer(length, 0); //vector of indices corresponding to the LIS
											 //....
	return answer;
}
#endif