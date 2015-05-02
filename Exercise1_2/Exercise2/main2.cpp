#include "functions2.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int TotalNoofStudents;		/* plh8os Students */
int M;						/* Students sthn 
ekswterikh oura pou perimenoun na eksetastoun apo ena Synergath */
						/* M= M* Quant , 
opou Quant= 1, 1.5, 2 analoga an o Synergaths eksetazei 1, 2 ,3 Students */
int MaxIn;					/* megisto plh8os Students pou perimenoun sthn oura ka8e Synergath */
int T;						/* ka8e kyklos diarkei T monades xronou */
int MaxTime;				/* ginetai elegxos an Synergaths.tps > MaxTime */
int MaxRecentTime;			/* ginetai elegxos an Synergaths.tpsl> MaxRecentTime */

int main (int argc, char* argv[])
{
	int curtime;
		curtime = time(NULL);
		srand((unsigned int) curtime);


	TotalNoofStudents= atoi(argv[1]);
	M=atoi(argv[2]);
	MaxIn=atoi(argv[3]);
	T=atoi(argv[4]);
	MaxTime=atoi(argv[5]);
	MaxRecentTime=atoi(argv[6]);


	Exam e;
	e.foithtes( );
	if(e.all_examined_students == TotalNoofStudents)
	{
		e.statistika( );
		cout<<endl <<"All OK!" << endl;
	}
	else
	{
		e.statistika( );
		cout<<endl << (TotalNoofStudents- e.all_examined_students) << endl;
		cout<<endl << "Bad time management, must hurry up! Try again!"<< endl;
	}
}


