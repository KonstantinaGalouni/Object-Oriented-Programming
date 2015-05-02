#include <iostream>
#include "functions2.h"
#include <cstdlib>
using namespace std;



int Student:: ar_m( )
{
	return a_m;
}

int Student:: askhseis( )
{
	return (ask1==1 || ask2==1 || ask3==1);
}

void Student:: set_ask1( )
{
	ask1 = 1;
}

int Student:: ergasia( )
{
	return (erg==1);
}

void Student:: set_ergasia( )
{
	erg = 1;
}

void Student:: set_with(int w)
{
	with = w;			/*to with pairnei ws timh ton 
ari8mo mhtroou tou symfoithth pou ekane mazi thn ergasia */
}

int Student:: give_with( )
{
	return with;
}

void Student:: set_bw(int bwho)
{
	bw = bwho;			/* to bw pairnei ws timh ton 
ari8mo mhtroou tou foithth pou paredwse thn ergasia */
}

int Student:: give_bw( )
{
	return bw;
}

void Student:: set_flag_askhseis(int x)
{
	flag_askhseis = x;			/* otan x==1 tote exei 
eksetastei gia tis askhseis */
}

int Student:: get_flag_askhseis( )
{
	return flag_askhseis;
}

void Student:: set_flag_ergasia(int x)
{
	flag_ergasia = x;			/* otan x==1 tote exei 
eksetastei gia thn ergasia */
}

int Student:: get_flag_ergasia( )
{
	return flag_ergasia;
}

void Student:: couts( )
{
	cout<<"ari8mos mhtroou "<< a_m<<endl;
	if(ask1==1)
		cout<<"askhsh 1: yes"<<endl;
	else
		cout<<"askhsh 1: no"<< endl;
	if(ask2==1)
		cout<<"askhsh 2: yes"<<endl;
	else
		cout<<"askhsh 2: no"<< endl;
	if(ask3==1)
		cout<<"askhsh 3: yes"<<endl;
	else
		cout<<"askhsh 3: no"<< endl;
	if(ergasia( ))
		{
			cout<<"ergasia : yes"<< endl;
			cout<<"synergasia me "<< with<< endl;
			cout<<"h ergasia parado8hke apo "<< bw<<endl;
		}
	else
		cout<<"ergasia : no"<<  endl;
}

int Student:: lhgontas( )
{
	return a_m % 10;
}

int Student:: get_exei_ftasei( )
{
	return exei_ftasei;
}

void Student:: set_exei_ftasei(int x)
{
	exei_ftasei = x;			/* otan x==0 eite den 
exei prosel8ei akoma, eite hr8e eksetasthke kai efyge */
}

int Student:: get_exei_ftasei_partner( )
{
	return exei_ftasei_partner;
}

void Student:: set_exei_ftasei_partner(int x)
{
	exei_ftasei_partner = x;	/* otan x==0 eite den exei 
prosel8ei akoma o symfoithths, eite hr8e eksetasthke kai efyge */
}

int Student:: get_is_here( )
{
	return is_here;
}

void Student:: set_is_here(int x)
{
	is_here = x;				/* otan x==1 tote einai 
edw. Diaforetika krataei th 8esh kai leipei proswrina */
}



Student:: Student(int a, int b, int c, int d)
{
	a_m=a;
	ask1=b;
	ask2=c;
	ask3=d;

	erg=0;
	with=0;
	bw=0;
	flag_askhseis=0;
	flag_ergasia=0;
	exei_ftasei=0;
	exei_ftasei_partner=0;
	is_here=1;
}


Student:: Student(const Student& k )	/* copy constructor */
{
	a_m= k.a_m;
	ask1= k.ask1;
	ask2= k.ask2;
	ask3= k.ask3;
	erg= k.erg;
	with= k.with;
	bw= k.bw;
}



Student:: ~Student( )
{
	/* destructor */
}


/* ******************************* */

string Synergaths:: get_name( )
{
	return name;
}

int Synergaths:: get_lhg1()
{
	return lhg1;
}

int Synergaths:: get_lhg2()
{
	return lhg2;
}

int Synergaths:: get_lhg3()
{
	return lhg3;
}


Synergaths:: Synergaths(string nm, int l1, int l2, int l3)
: name(nm), lhg1(l1), lhg2(l2), lhg3(l3)
{
	tps=0;
	tpsl=0;
	n_of_ex_st=0;
	synol_diark_ex=0;
}


Synergaths:: ~Synergaths( )
{
	/* destructor */
}




/* ****************** */





Exam:: Exam( )
{
	s[0]=new Synergaths("Periklhs", 0, 1);
	s[1]=new Synergaths("Konstantina", 2, 3);
	s[2]=new Synergaths("Thanos", 4, 5, 6);
	s[3]=new Synergaths("Sophia", 7, 8, 9);

	oura[0]=new List;
	oura[1]=new List;

	max_synol_diark_ex=0;
	all_examined_students=0;
}


Exam:: ~Exam( )
{
	int i;
	for (i=0; i<4; i++)
	{
		delete s[i];
	}

	for(i=0; i<2; i++)
	{
		delete oura[i];
	}
}



void Exam:: statistika( )
{
	int i;
	for(i=0; i<4; i++)
	{
		cout<<"Synergaths "<< i << ":"<< endl;
		cout<<"Ari8mos foithtwn: "<< s[i]->n_of_ex_st <<endl;
		if(s[i]->n_of_ex_st != 0)
		{
			s[i]->mo_prof_ex = s[i]->synol_diark_ex / s[i]->n_of_ex_st;
			cout<<"Mesos oros proforikhs eksetashs: "<< s[i]->mo_prof_ex <<endl;
		}
		else
			cout<<"Den eksetasthkan foithtes apo to sygkekrimeno synergath"<<endl;
		if(s[i]->synol_diark_ex > max_synol_diark_ex)
			max_synol_diark_ex = s[i]->synol_diark_ex;
		all_examined_students = all_examined_students + s[i]->n_of_ex_st;
	}
	cout<<"Megisth synolikh diarkeia eksetashs: "<<max_synol_diark_ex<< endl;
	cout<<"Synolikos ari8mos foithtwn pou eksetasthkan: "<<all_examined_students<< endl;
}





