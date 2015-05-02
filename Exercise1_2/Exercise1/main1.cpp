#include <iostream>
#include "functions1.h"
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char* argv[])
{
	int n;
	int maxWords, minWords;

	int curtime;
	curtime = time(NULL);
	srand((unsigned int) curtime);

	n=atoi(argv[1]);
	minWords=atoi(argv[2]);
	maxWords=atoi(argv[3]);

	if(argc != 4)
	{
		cout<< "Arguments must be 3!!! Try again!"<<endl;
		return 1;
	}

	if((n<0) || (minWords<0) || (maxWords<0))
	{
		cout<< "All arguments must be positive!!! Try again!"<<endl;
		return 1;
	}

	if(minWords>maxWords)
	{
		cout<< "Second argument must be less than third!!! Try again!"<<endl;
		return 1;
	}


	Ekthesh e("The Shinning", n);
	e.evaluate_length(maxWords, minWords);
	e.spell_correct(e.ek);

	return 0;

};


