#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	int cel = 0;
	for(int person = 1; person < n; ++person){
		if(knows(cel, person)){
			cel = person;
		}
	}
	for(int person = 0; person < n; ++person){
		if(person != cel){
			if(knows(cel, person) || !knows(person, cel)){
				return -1;
			}
		}
	}
	return cel;
}
