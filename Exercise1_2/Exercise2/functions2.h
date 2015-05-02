#include <iostream>
#include <string>

using namespace std;

extern int TotalNoofStudents;

class Student
{
private:
	int a_m;				/* ari8mos mhtroou */
	int ask1;				/* askhsh 1 */
	int ask2;				/* askhsh 2 */
	int ask3;				/* askhsh 3 */
	int erg;				/* ergasia */
	int with;				/* o symfoithths me ton 
opoio paredwse thn ergasia mazi */
	int bw;					/* (by who) apo poion 
paradw8hke h ergasia */
	int flag_askhseis;		/* an exei eksetastei gia tis 
askhseis */
	int flag_ergasia;		/* an exei eksetastei gia thn 
ergasia */
	int exei_ftasei;		/* pairnei timh 1 otan brisketai 
se kapoia oura kai timh 0 eite otan den exei ftasei akoma */
							/* sthn 
ekswterikh oura eite otan eksetazetai kai feugei */
	int exei_ftasei_partner;/* 1 otan o symfoithths tou brisketai 
sto xwro eksetashs se kapoia oura alliws 0 */
	int is_here;			/* eksasfalizei an o foithths 
brisketai se mia oura h krataei th 8esh enw eksetazetai allou */

public:
	int ar_m( );
	int askhseis( );
	void set_ask1( );
	int ergasia( );
	void set_ergasia( );
	void set_with(int);
	int give_with( );
	void set_bw(int);
	int give_bw( );
	void set_flag_askhseis(int);
	int get_flag_askhseis( );
	void set_flag_ergasia(int);
	int get_flag_ergasia( );
	void couts( );
	int lhgontas( );
	int get_exei_ftasei( );
	void set_exei_ftasei(int);
	int get_exei_ftasei_partner( );
	void set_exei_ftasei_partner(int);
	int get_is_here( );
	void set_is_here(int);




	bool equal (const Student& right) const
		{
			return a_m == right.a_m;
		}


	Student(int, int, int, int);
	~Student( );

	Student(const Student&);
};

/* ********************** */

typedef Student Data;





class List
{

	struct Node
	{
		Data 	data;
		Node* 	next;

		Node (Data data_, Node* next_ = NULL) : data(data_), 
next(next_) {}
	};


	Node* 		first;
	Node* 		last;
	unsigned int 	nodes;


public:


	class Iterator
	{
		Node* node;

	public:

		Iterator (Node* node_) : node(node_) {}

		Iterator next (int amount = 1)
		{
			for ( int i = 0 ; i < amount ; i++ ) node = 
node->next;
			return Iterator (node);
		}




		bool equal (Iterator right)
		{
			return node == right.node;
		}

		Data& data () { return node->data; }

		Node* container () { return node; }
	};

	// Iterator at the beginning of the list
	Iterator begin () { return Iterator (first); }
	// Iterator *after* the end of the list
	Iterator end () { return Iterator (NULL); }


	Iterator insert (Data data_, bool atEnd = true)
	{
		nodes++;
		Node* tmp;
		if ( atEnd )
		{
			tmp = new Node (data_);

			// list is empty
			if ( last == NULL )
			{
				first = tmp;
				last = tmp;
			}
			else
			{
				last->next = tmp;
				last = last->next;
			}
		}
		else
		{
			tmp = new Node (data_, first);

			// list is empty
			if ( first == NULL )
			{
				first = tmp;
				last = tmp;
			}
			else
				first = tmp;
		}
		return Iterator (tmp);
	}

	// Insert after position
	Iterator insert (Data data_, Iterator position)
	{
		Node* current = position.container();
		if ( current == NULL ) return insert (data_, false);

		current->next = new Node (data_, current->next);

		nodes++;

		return position.next();
	}

	Iterator find (Data data_, Iterator after = Iterator(NULL))
	{
		Node* afterPos = after.container();
		Node* tmp = (afterPos == NULL ? first : afterPos->next);
		while ( tmp != NULL )
		{
			//if ( tmp->data == data_ ) break;
			if ( tmp->data.equal(data_) ) break;
			tmp = tmp->next;
		}
		return Iterator (tmp);
	}

	void remove (Data data_, Iterator after = Iterator(NULL))
	{
		Node* afterPos = after.container();
		Node* tmp = (afterPos == NULL ? first : afterPos->next);
		Node* prev = (afterPos == NULL ? NULL : afterPos);
		while ( tmp != NULL )
		{
			//if ( tmp->data == data_ )
			if ( tmp->data.equal(data_) )
			{
				if ( prev != NULL) prev->next = 
tmp->next;
				else first = first->next;
				nodes--;

				if(nodes == 0)
					last = NULL;
				if(tmp == last)
					last = prev;

				delete tmp;
				break;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}

	void update (Data data_, Iterator pos)
	{
		pos.data() = data_;
	}


	int size ( ) { return nodes; }



	List () : first(NULL), last(first), nodes(0) {}

	List (Iterator& itStart, Iterator& itEnd) : first(NULL), 
last(first), nodes(0)
	{
		for ( ; !itStart.equal( itEnd ) ; itStart.next() )
			 insert ( itStart.data() );
	}

	List (const List& original)
	{
		for ( Node* tmp = original.first ; tmp != NULL ; tmp = 
tmp->next )
			insert ( tmp->data );
	}


	~List ()
	{
		Node *temp, *i = first;
		while (i != NULL)
		{
			temp = i;
			i = i->next;
			delete temp;
		}
	}
};






/* ********************** */








class Synergaths
{
private:
	string name;		/* onoma synergath */
	int lhg1;			/* lhgontas pou tou exei 
anate8ei */
	int lhg2;			/* lhgontas pou tou exei 
anate8ei */
	int lhg3;			/* lhgontas pou tou exei 
anate8ei */


public:
	List l;

	float tps;			/* time per student */
	float tpsl;			/* time per student last */
	int n_of_ex_st;		/* number of examined students */
	float mo_prof_ex;	/* mesos oros proforikhs eksetashs */
	int synol_diark_ex;	/* synolikh diarkeia eksetashs;	*/


	string get_name( );
	int get_lhg1( );
	int get_lhg2( );
	int get_lhg3( );
	Synergaths(string, int, int=-1, int=-1);
	~Synergaths( );
};


/* ****************************** */


class Exam
{
private:
	Student** st;
public:
	void foithtes( );

	List* oura[2];
	Synergaths* s[4];

	int max_synol_diark_ex;
	int all_examined_students;

	void statistika( );

	Exam( );
	~Exam( );

};




