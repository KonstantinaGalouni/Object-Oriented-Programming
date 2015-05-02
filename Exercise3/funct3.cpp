#include <iostream>
#include <cstdlib>
#include "functions3.h"

using namespace std;


void clone_encrypt_and_print(Object& o)
{
	Object* o1;
	o1 = o.clone( );

	if(o.equal(o1) == false)		//if object* o is equal to object* o1
		cout<<endl<<endl<<"NOT EQUAL"<<endl;
	else
		cout<<endl<<endl<<"EQUAL"<<endl;

	if(o.identical(o1) == false)	//if object* o is identical to object* o1
		cout<<endl<<"NOT IDENTICAL"<<endl<<endl<<endl;
	else
		cout<<endl<<"IDENTICAL"<<endl<<endl<<endl;

	String a(o.toString( ));

	String b(o1->toString( ));
	int i;
	do {
		i=(rand( ) % 100);		//i is which character of b i want to change
	}while(i > b.length( ));

	b.updateAt(i, 'Z');			//Z is the character that will replace the character in position i
	cout<<endl;
	a.print( );					//printing string
	cout<<endl;
	b.print( );					//printing string after changing one character - this string before the change was the clone of the above
	cout<<endl;
	String c(a.concat(b));		//concat a and b
	cout<<endl<< "Concat length is: "<< c.length( ) <<endl;

	if((c.length( ) % 2) == 0 )
		cout<< "Middle characters are: "<< c.at((c.length( ) / 2) -1)<<" "<<c.at((c.length( ) /2) )<<endl;
	else
		cout<< "Middle character is: "<< c.at(c.length( ) / 2)<<endl;

	c.clear( );
	cout<< "Concat length is: "<<c.length( ) << " after clear"<<endl<<endl;

	delete o1;
}

