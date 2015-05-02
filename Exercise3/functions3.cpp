#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "functions3.h"

using namespace std;

int Object:: no=0;

bool Object:: equal(Object* o)
{
	if(id == o->id)		//id IS THE ONLY DATA MEMBER OF CLASS Object
		return true;
	else
		return false;
}


bool Object:: identical(Object* o)
{
	if(this == o)		//COMPARES THE 2 OBJECTS AS REAL ENTITIES
		return true;
	else
		return false;
}


Object:: Object( )		//CONSTRUCTOR
{
	id=no;
	no++;
	cout<<"Object just created!"<<endl;
}

Object:: ~Object( )		//DESTRUCTOR
{
	cout<<"Object to be destroyed!"<<endl;
}

Object:: Object(const Object& o)	//COPY CONSTRUCTOR
{
	id = o.id;
	no = o.no;
	cout<<"Object just created! COPY"<<endl;
}

String Object:: toString( )
{
	ostringstream os;				//BY USING ostringstream WE CAN HANDLE A string LIKE AN OUTPUT STREAM
	os<<"Object:: id- "<<id<<" ";
	String st(os.str( ));
	return st;
}


String:: String(string a)			//CONSTRUCTOR
{
	s=a;
	cout<<" String just created!"<<endl;
}

String:: String(const char* ch)		//CONSTRUCTOR
{
	s=ch;
	cout<<" String just created!"<<endl;
}

String:: ~String( )					//DESTRUCTOR
{
	cout<<" String to be destroyed!"<<endl;
}

String:: String(const String& st) : Object(st)		//COPY CONSTRUCTOR
{
	s=st.s;
	cout<<" String just created! COPY"<<endl;
}

int String:: length( )		//RETURNS THE LENGTH OF string s
{
	return s.length( );
}

void String:: clear( )		//CLEARS string s - AFTER CALLING THIS FUNCTION s IS EMPTY
{
	s.clear( );
}

String String:: concat(const String& s1)	//CONCATS s WITH s1
{
	String s2(s.append(s1.s));
	return s2;
}

char& String:: at(unsigned int i)		//RETURNS THE CHARACTER OF s WHICH IS IN THE POSITION i
{
	return s.at(i);
}

String& String:: updateAt(unsigned int i, char c)	//REPLACES THE CHARACTER OF s WHICH IS IN THE POSITION i BY c
{
	s.replace(i, 1, 1, c);
	return *this;
}

void String:: print( )		//PRINTS string s
{
	cout<< s <<endl;
}

string String:: get_string( )		//RETURNS string s
{
	return s;
}


bool String:: equal(Object* ob)
{
	String* st = (String*) ob;
	if(Object::equal(ob) == true)
		{
			if(s==st->get_string( ))
				return true;
			else
				return false;
		}
	else
		return false;
}



Object* String:: clone( )
{
	Object* st = new String(*this);
	return st;
}

String String:: toString( )
{
	String st(Object:: toString( ));
	st.concat(" String:: contents- ");
	st.concat(s);
	return st;
}


bool PlaneComponent:: equal(Object* ob)
{
	PlaneComponent* pl = (PlaneComponent*) ob;
	if(Object::equal(ob) == true)
		{
			if(st.get_string( )==pl->st.get_string( ))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	else
	{
		return false;
	}
}

String PlaneComponent:: toString( )
{
	String st1(Object:: toString( ));
	st1.concat(" Plane Component:: descriprion- ");
	st1.concat(st.toString( ).get_string( ));
	return st1;
}

String PlaneComponent:: get_st( )		//RETURNS String st WHICH IS DATA MEMBER OF CLASS PlaneComponent
{
	return st;
}


PlaneComponent:: PlaneComponent(String str) : st(str)		//CONSTRUCTOR
{
	cout<<" PlaneComponent just created!"<<endl;
}

PlaneComponent:: ~PlaneComponent( )		//DESTRUCTOR
{
	cout<<" Plane Component to be destroyed!"<<endl;
}

PlaneComponent:: PlaneComponent(const PlaneComponent& pl) : Object(pl), st(pl.st)	//COPY CONSTRUCTOR - INITIALIZING st
{
	cout<<" Plane Component just created! COPY"<<endl;
}


void PassengerCompartment:: ready_check( )		//ANNOUNCEMENT IF PassengerCompartment IS OK
{
	if(p != NULL)
		p->ready_check( );
	cout<<get_st( ).get_string( )<<endl;
	cout<<"Passenger Compartment is OK!"<<endl;
}

void PassengerCompartment:: process(Employee& e)
{
	e.workOn(*this);
}

Object* PassengerCompartment:: clone( )
{
	PassengerCompartment* pC = new PassengerCompartment(*this);
	return pC;
}

bool PassengerCompartment:: equal(Object* ob)
{
	PassengerCompartment* pC = (PassengerCompartment*) ob;
	if(PlaneComponent::equal(ob) == true)
		{
			if((p != NULL) && (pC->p != NULL))	//IF BOTH HAVE INNER PASSENGERCOMPARTMENT
			{
				if(p->equal(pC->p))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if((p!= NULL) ^ (pC->p != NULL))	//IF ONLY ONE HAS INNER PASSENGERCOMPARTMENT
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	else
		return false;
}

String PassengerCompartment:: toString( )
{
	String st1(PlaneComponent:: toString( ));

	if(p != NULL)
		{
			st1.concat(" Passenger Compartment:: Inner Passenger Compartment- ");
			st1.concat(p->toString( ).get_string( ));
		}
	return st1;
}

PassengerCompartment& PassengerCompartment:: get_passComp( )	//RETURNS INNER PassengerCompartment
{
	return *p;
}

bool PassengerCompartment:: exists_inside( )	//RETURNS 1 IF THERE IS INNER PassengerCompartment ELSE RETURNS 0
{
	if(p!=NULL)
		return true;
	else
		return false;
}



PassengerCompartment:: PassengerCompartment(String st1) : PlaneComponent(st1)	//CONSTRUCTOR
{
	p = NULL;
	cout<<"  Passenger Compartment just created!"<<endl;
}

void PassengerCompartment:: inside( )	//CONTROLS EVERYTHING ABOUT INNER PassengerCompartment
{
	int random = rand( ) % 2;
	if(random == 1)
	{
		p = new PassengerCompartment("innerPassengerCompartment!");
	}
}

PassengerCompartment:: ~PassengerCompartment( )		//DESTRUCTOR
{
	delete p;
	cout<<"  Passenger Compartment to be destroyed!"<<endl;
}

void PassengerCompartment:: inside_copy(const PassengerCompartment& pass1)	//CONTROLS EVERYTHING ABOUT INNER PassengerCompartment WHEN CREATING A PassengerCompartment BY COPY
{
if(pass1.p != NULL)
	p = new PassengerCompartment(*pass1.p);
else
	p = NULL;
}

PassengerCompartment:: PassengerCompartment(const PassengerCompartment& pass) : PlaneComponent(pass)	//COPY CONSTRUCTOR
{
	p = NULL;
	cout<<"  Passenger Compartment just created! COPY"<<endl;
}

bool PrivateCompartment:: equal(Object* ob)
{
	return PlaneComponent:: equal(ob);
}

PrivateCompartment:: PrivateCompartment(String st1) : PlaneComponent(st1)	//CONSTRUCTOR
{
	cout<<"  Private Compartment just created!"<<endl;
}

PrivateCompartment:: ~PrivateCompartment( )		//DESTRUCTOR
{
	cout<<"  Private Compartment to be destroyed!"<<endl;
}

PrivateCompartment:: PrivateCompartment(const PrivateCompartment& pr) : PlaneComponent(pr)	//COPY CONSTRUCTOR
{
	cout<<"  Private Copmartment just created! COPY"<<endl;
}

void EquipmentCompartment:: ready_check( )		//ANNOUNCEMENT IF EquipmentCompartment IS OK
{
	cout<<get_st( ).get_string( )<<endl;
	cout<<"Equipment Compartment is OK!"<<endl;
}

void EquipmentCompartment:: process(Employee& e)
{
	e.workOn(*this);
}

Object* EquipmentCompartment:: clone( )
{
	EquipmentCompartment* eq = new EquipmentCompartment(*this);
	return eq;
}

bool EquipmentCompartment:: equal(Object* ob)
{
	return PrivateCompartment:: equal(ob);
}

String EquipmentCompartment:: toString( )
{
	return PlaneComponent:: toString( );
}

EquipmentCompartment:: EquipmentCompartment(String st1) : PrivateCompartment(st1)	//CONSTRUCTOR
{
	cout<<"   Equipment Compartment just created!"<<endl;
}

EquipmentCompartment:: ~EquipmentCompartment( )		//DESTRUCTOR
{
	cout<<"   Equipment Compartment to be destroyed!"<<endl;
}

EquipmentCompartment:: EquipmentCompartment(const EquipmentCompartment& equip) : PrivateCompartment(equip)	//COPY CONSTRUCTOR
{
	cout<<"   Equipment Compartment just created! COPY"<<endl;
}

void CargoBay:: ready_check( )			//ANNOUNCEMENT IF CargoBay IS OK
{
	equipment.ready_check( );
	cout<<get_st( ).get_string( )<<endl;
	cout<<"CargoBay is OK!"<<endl;
}

void CargoBay:: process(Employee& e)
{
	e.workOn(*this);

}

Object* CargoBay:: clone( )
{
	CargoBay* cargoB = new CargoBay(*this);
	return cargoB;
}

bool CargoBay:: equal(Object* ob)
{
	CargoBay* cBay = (CargoBay*) ob;
	if(PlaneComponent::equal(ob) == true)
		{
			if(equipment.equal(&cBay->equipment))
				return true;
			else
				return false;
		}
	else
		return false;
}

String CargoBay:: toString( )
{
	String st1(PlaneComponent:: toString( ));
	st1.concat(" CargoBay:: Equipment Compartment- ");
	st1.concat(equipment.toString( ).get_string( ));
	return st1;
}

EquipmentCompartment& CargoBay:: get_equipment( )		//RETURNS CargoBay's EquipmentCompartment
{
	return equipment;
}

CargoBay:: CargoBay(String st1) : PrivateCompartment(st1), equipment("cargobay:: equipment!")	//CONSTRUCTOR - INITIALIZING DATA MEMBER equipment
{
	cout<<"   CargoBay just created!"<<endl;
}

CargoBay:: ~CargoBay( )			//DESTRUCTOR
{
	cout<<"   CargoBay to be destroyed!"<<endl;
}

CargoBay:: CargoBay(const CargoBay& cB) : PrivateCompartment(cB), equipment(cB.equipment)	//COPY CONSTRUCTOR
{
	cout<<"   CargoBay just created! COPY"<<endl;
}


Object* Plane:: clone( )
{
	Plane* plane = new Plane(*this);
	return plane;
}

bool Plane:: equal(Object* ob)
{
	Plane* pl = (Plane*) ob;
	if(Object::equal(ob) == true)
		{
			if((pl->capacity == capacity) && (pl->description.equal(&description)) && (pl->title.equal(&title)) && (pl->cargobay.equal(&cargobay)) )
			{
				int i=0;
				for(i=0; i<3; i++)
				{
					if(pl->equipmentcompartment[i]->equal(equipmentcompartment[i]) == false)
						{
							return false;
							break;
						}
				}
				i=0;
				while((pl->passengercompartment[i] != NULL) && (passengercompartment[i] != NULL))
					{
						if(i == p_compartment_capacity)
							break;
						if(pl->get_passengercompartment(i).equal(&get_passengercompartment(i)) == false)
							{
								return false;
								break;
							}
						else
							{
								i++;
							}
					}
				if((pl->passengercompartment[i-1] != NULL) ^ (passengercompartment[i-1] != NULL))	// i-1 BECAUSE IT HAS ALREADY BECOME i++ WITHOUT A REASON
				{
					return false;
				}
				return true;
			}
			else
				return false;
		}
	else
	{
		return false;
	}
}

String Plane:: toString( )
{
	String st(Object:: toString( ));

	st.concat(" Plane:: description- ");
	st.concat(description.get_string( ));

	st.concat(" Plane:: title- ");
	st.concat(title.get_string( ));

	ostringstream os1, os2;
	os1<<" Plane::capacity- "<<capacity;
	st.concat(os1.str( ));

	os2<<" Plane:: compartment_capacity- "<<p_compartment_capacity;
	st.concat(os2.str( ));

	st.concat(" Plane:: CargoBay- ");
	st.concat(cargobay.toString( ).get_string( ));
	int i;
	for(i=0; i<3; i++)		//Plane HAS 3 EquipmentCompartments
	{
		st.concat(" Plane:: Equipment Compartment- ");
		st.concat(equipmentcompartment[i]->toString( ).get_string( ));
	}
	for(i=0; i < p_compartment_capacity; i++)		//Plane HAS p_compartment_capacity PassengerCompartments
	{
		st.concat(" Plane:: Passenger Compartment- ");
		st.concat(passengercompartment[i]->toString( ).get_string( ));
	}
	return st;
}

String Plane:: get_desription( )	//RETURNS DATA MEMBER String description
{
	return description;
}

String Plane:: get_title( )			//RETURNS DATA MEMBER String title
{
	return title;
}

int Plane:: get_capacity( )			//RETURNS DATA MEMBER String capacity
{
	return capacity;
}

int Plane:: get_compartment_capacity( )		//RETURNS DATA MEMBER String p_compartment_capacity
{
	return p_compartment_capacity;
}

CargoBay& Plane:: get_cargobay( )		//RETURNS DATA MEMBER CargoBay cargobay
{
	return cargobay;
}

EquipmentCompartment& Plane:: get_equipmentcompartment(int i)
{
	if(i < 3)
		return *equipmentcompartment[i];	//RETURNS DATA MEMBER EquipmentCompartment *equipmentcompartment[i]
	else
		{
			//Plane HAS ONLY 3 EquipmentCompartmentS
			cout<<endl<<"There is not such an equipmentcompartment! PROBLEM!!!"<<endl<<endl;
			return *equipmentcompartment[i];
		}
}

PassengerCompartment& Plane:: get_passengercompartment(int i)
{
	if(i <= p_compartment_capacity)
		return *passengercompartment[i];		//RETURNS DATA MEMBER EquipmentCompartment *passengercompartment[i]
	else
	{
		//Plane HAS ONLY p_compartment_capacity PassengerCompartmentS
		cout<<endl<<"There is not such a passengercompartment! PROBLEM!!!"<<endl<<endl;
		return *passengercompartment[i];
	}
}


void Plane:: ready_check( )		//ANNOUNCEMENT IF Plane IS OK - CHECKING DATA MEMBERS' ANNOUNCEMENTS
{
	cargobay.ready_check( );
	int i;
	for(i=0; i<3; i++)
		equipmentcompartment[i]->ready_check( );
	for(i=0; i<p_compartment_capacity; i++)
		passengercompartment[i]->ready_check( );
	cout<<"Plane:: "<<description.get_string( )<<" - "<<title.get_string( )<<endl;
	cout<<"Plane is OK!"<<endl<<endl;
}

void Plane:: process(Employee& e)
{
	e.workOn(*this);
}

Plane:: Plane(String st1, String st2) : description(st1), title(st2), cargobay("C_Bay")		//CONSTRUCTOR - INITIALIZING DATA MEMEBERS String description , title , CargoBay cargobay
{
	capacity = rand( ) % 1000;
	p_compartment_capacity = rand( ) % ((capacity / 45) + 1) + 5;

	int i;
	for(i=0; i<3; i++)
	{
		equipmentcompartment[i] = new EquipmentCompartment("Eq_Comp");
	}

	passengercompartment = new PassengerCompartment*[p_compartment_capacity];
	for(i=0; i< p_compartment_capacity; i++)
	{
		passengercompartment[i] = new PassengerCompartment("Pass_Comp");
		passengercompartment[i]->inside( );
	}

	cout<<" Plane just created!"<<endl;
}

Plane:: ~Plane( )		//DESTRUCTOR
{
	int i;
	for(i = 0; i<3; i++)
	{
		delete equipmentcompartment[i];
	}

	for(i = 0; i<p_compartment_capacity; i++)
	{
		delete passengercompartment[i];
	}
	delete [ ]passengercompartment;
	cout<<" Plane to be destroyed!"<<endl;
}

Plane:: Plane(const Plane& plane) : Object(plane), description(plane.description), title(plane.title), cargobay(plane.cargobay)	//COPY CONSTRUCTOR
{
	capacity = plane.capacity;
	p_compartment_capacity = plane.p_compartment_capacity;
	int i;
	for(i=0; i<3; i++)
	{
		equipmentcompartment[i] = new EquipmentCompartment(*plane.equipmentcompartment[i]);
	}
	passengercompartment = new PassengerCompartment*[p_compartment_capacity];
	for(i=0; i<p_compartment_capacity; i++)
	{
		passengercompartment[i] = new PassengerCompartment(*plane.passengercompartment[i]);
		passengercompartment[i]->inside_copy(*plane.passengercompartment[i]);
	}
	cout<<" Plane just created! COPY"<<endl;
}


void Employee:: workOn(Plane& plane_)
{
	workOn(plane_.get_cargobay( ));
	int i;
	for(i=0; i<3; i++)
		workOn(plane_.get_equipmentcompartment(i));
	int plane_compartment_capacity = plane_.get_compartment_capacity( );
	for(i=0; i<plane_compartment_capacity; i++)
		workOn(plane_.get_passengercompartment(i));
}

bool Employee:: equal(Object* ob)
{
	Employee* em = (Employee*) ob;
	if(Object::equal(ob) == true)
		{
			if(name.get_string( )==em->name.get_string( ))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	else
	{
		return false;
	}
}

String Employee:: toString( )
{
	String st1(Object:: toString( ));
	st1.concat(name.get_string( ));
	return st1;
}

String Employee:: get_name( )		//RETURNS DATA MEMBER String name
{
	return name;
}

Employee:: Employee(String name_) : name(name_)		//CONSTRUCTOR - INITIALIZING DATA MEMBER String name
{
	cout<<" Employee just created!"<<endl;
}

Employee:: ~Employee( )		//DESTRUCTOR
{
	cout<<" Employee to be destroyed!"<<endl;
}

Employee:: Employee(const Employee& emp) : Object(emp), name(emp.name)		//COPY CONSTRUCTOR
{
	cout<<" Employee just created! COPY"<<endl;
}


SecurityEmployee:: SecurityEmployee(String name_) : Employee(name_)		//CONSTRUCTOR
{
	cout<<"  Security Employee just created!"<<endl;
}

SecurityEmployee:: ~SecurityEmployee( )		//DESTRUCTOR
{
	cout<<"  Security Employee to be destroyed!"<<endl;
}

SecurityEmployee:: SecurityEmployee(const SecurityEmployee& sec_em) : Employee(sec_em)		//COPY CONSTRUCTOR
{
	cout<<"  Security Employee just created! COPY"<<endl;
}

Object* SecurityEmployee:: clone( )
{
	SecurityEmployee* security = new SecurityEmployee(*this);
	return security;
}

void SecurityEmployee:: workOn(PassengerCompartment& p_C)
{
	cout<<"Passenger Compartment processed!"<<endl;
	if(p_C.exists_inside( ) != false)
		workOn(p_C.get_passComp( ));
}

void SecurityEmployee:: workOn(EquipmentCompartment& e_C)
{
	cout<<"Equipment Compartment processed!"<<endl;
}

void SecurityEmployee:: workOn(CargoBay& c_C)
{
	workOn(c_C.get_equipment( ));
	cout<<"CargoBay processed!"<<endl;
}

void SecurityEmployee:: report( )		//SecurityEmployee ANNOUNCES THAT EVERYTHING IS OK
{
	cout<<"Security report: Everything OK!"<<endl<<endl;
}


MaintenanceEmployee:: MaintenanceEmployee(String name_) : Employee(name_)		//CONSTRUCTOR
{
	cout<<"  Maintenance Employee just created!"<<endl;
}

MaintenanceEmployee:: ~MaintenanceEmployee( )		//DESTRUCTOR
{
	cout<<"  Maintenance Employee to be destroyed!"<<endl;
}

MaintenanceEmployee:: MaintenanceEmployee(const MaintenanceEmployee& m_em) : Employee(m_em)		//COPY CONSTRUCTOR
{
	cout<<"  Maintenance Employee just created! COPY"<<endl;
}

Object* MaintenanceEmployee:: clone( )
{
	MaintenanceEmployee* maintenance = new MaintenanceEmployee(*this);
	return maintenance;
}

void MaintenanceEmployee:: workOn(EquipmentCompartment& e_C)
{
	cout<<"Equipment Compartment processed!"<<endl;
}

void MaintenanceEmployee:: workOn(CargoBay& c_C)
{
	workOn(c_C.get_equipment( ));
	cout<<"CargoBay processed!"<<endl;
}

void MaintenanceEmployee:: report( )		//MaintenanceEmployee ANNOUNCES THAT EVERYTHING IS OK
{
	cout<<"Maintenance report: Everything OK!"<<endl<<endl;
}

CleaningEmployee:: CleaningEmployee(String name_) : Employee(name_)		//CONSTRUCTOR
{
	cout<<"  Cleaning Employee just created!"<<endl;
}

CleaningEmployee:: ~CleaningEmployee( )		//DESTRUCTOR
{
	cout<<"  Cleaning Employee to be destroyed!"<<endl;
}

CleaningEmployee:: CleaningEmployee(const CleaningEmployee& c_em) : Employee(c_em)		//COPY CONSTRUCTOR
{
	cout<<"  Cleaning Employee just created! COPY"<<endl;
}

Object* CleaningEmployee:: clone( )
{
	CleaningEmployee* cleaning = new CleaningEmployee(*this);
	return cleaning;
}

void CleaningEmployee:: workOn(PassengerCompartment& p_C)
{
	cout<<"Passenger Compartment processed!"<<endl;
	if(p_C.exists_inside( ) != false)
		workOn(p_C.get_passComp( ));
}

void CleaningEmployee:: workOn(CargoBay& c_C)
{
	cout<<"CargoBay processed!"<<endl;
}

void CleaningEmployee:: report( )		//CleaningEmployee ANNOUNCES THAT EVERYTHING IS OK
{
	cout<<"Cleaning report: Everything OK!"<<endl<<endl;
}

