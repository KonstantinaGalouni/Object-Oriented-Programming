#include <iostream>
#include "functions3.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main( )
{
	int curtime;
	curtime = time(NULL);
	srand((unsigned int) curtime);

	Plane plane("747!", "Boeing");	//creating a Plane

	SecurityEmployee e1("Security Employee!");			//creating a Security Employee
	MaintenanceEmployee e2("Maintenance Employee!");	//creating a Maintenance Employee
	CleaningEmployee e3("Cleaning Employee!");			//creating a Cleaning Employee

	cout<<endl;

	plane.process(e1);		//Employee e1 will work at plane
	e1.report( );

	plane.process(e2);		//Employee e2 will work at plane
	e2.report( );

	plane.process(e3);		//Employee e3 will work at plane
	e3.report( );

	plane.ready_check( );
	cout<<"Plane ready to take off!"<<endl<<endl;

	clone_encrypt_and_print(plane);

	return 0;
}

