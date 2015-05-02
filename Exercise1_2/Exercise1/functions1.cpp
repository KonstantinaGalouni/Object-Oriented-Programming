#include <iostream>
#include <cstdlib>
#include "functions1.h"

using namespace std;


const string Protash::dictionary[ ]= 
{"All","Work","And","No","Play","Makes","Jack", "A ","Dull","Boy"};
const string Protash::dictionary_False[ ]= {"wrong1", "wrong2", 
"wrong3", "wrong4", "wrong5"};



void Protash:: spell_correct(string* s)
{
	int i, j;
	for(i=0; i<count1; i++)
	{
		j=0;
		while (j<10 && s[i]!= dictionary[j])
			j++;
		if (j==10)
			s[i]= "SPELLING_MISTAKE";
	}
}

int Protash:: word_count( )
{
	return count1;
}



string* Protash:: read_phrase( )
{
	return s;
}


Protash::~Protash( )
{
	int i;
	for(i=0; i<count1; i++)
		{
			cout << s[i] << " ";
		}
	cout << endl;
	cout<< "Forget phrase: " << " ";
	delete[] s;
}


Protash::Protash(int n)
{
	N=n;

	int i,k;
	count1= rand() % N +1;			/* mia protash prepei na 
exei panta toulaxiston mia leksh */
	s= new string[count1+1];
	for (i=0; i<count1; i++)
	{
		k= rand() % 15;
		if(k<=9)
		{
			s[i]=dictionary[k];
		}
		else
		{
			s[i]=dictionary_False[k-10];
		}
	}
	for(i=0; i<count1; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "I just composed a phrase with content: "<< " ";
}



void Paragraphos:: spell_correct(Protash* par[10])
{
	int i;
	for (i=0; i<10; i++)
	{
		string* str;
		str=par[i]->read_phrase( );
		par[i]->spell_correct(str);
	}
}

int Paragraphos:: word_count( )
{
	int i;
	count2=0;
	for(i=0; i<10; i++)
	{
		count2= par[i]->word_count( ) + count2;
	}
	return count2;
}


Paragraphos:: ~Paragraphos( )
{
	int j;
	for (j=0; j<10; j++)
	{
		delete par[j];
		cout<< j+1 << endl;
	}
	cout<< endl<< "I can forget this paragraph!"<< " ";
}


Paragraphos:: Paragraphos(int n)
{
	int i;
	for(i=0; i<10; i++)
		{
			par[i]=new Protash(n);
			cout<< i+1 << endl;
		}
	cout<< endl << "I just composed a paragraph with content...: "<< 
" ";
}




void Ekthesh:: spell_correct(Paragraphos* ek[7])
{
	int i;
	for(i=0; i<7; i++)
		ek[i]->spell_correct(ek[i]->par);
}


void Ekthesh:: evaluate_length(int maxWords, int minWords)
{
	MaxWords= maxWords;
	MinWords= minWords;

	int i;
	count3=0;
	for(i=0; i<7; i++)
		count3= ek[i]->word_count( ) + count3;
	if(count3 < MinWords)
		cout<< endl<< "Length too short ..." <<endl <<endl;
	else if(count3 > MaxWords)
		cout<< endl<< "Lenght too long ..." <<endl <<endl;
	else
		cout<< endl<< "Length OK!!!!" <<endl <<endl;
}


Ekthesh:: Ekthesh(string t, int n)
{
	title= t;
	int i;
	for(i=0; i<7; i++)
	{
		ek[i]=new Paragraphos(n);
		cout << i+1 << endl<< endl;
	}
	cout<< "I just composed a composition with title: " << title << 
endl;
}


Ekthesh:: ~Ekthesh( )
{
	int j;
	for(j=0; j<7; j++)
		{
			delete ek[j];
			cout<< j+1 << endl<< endl;
		}
	cout<< "Another composition is over!" << endl;
}

