#include <string>

class String;		//CLASS FORWARDING
class Object		//ABSTRACT CLASS
{
private:
	int id;
	static int no;

public:
	virtual bool equal(Object* );
	bool identical(Object* );
	virtual Object* clone( )=0;
	virtual String toString( );

	int get_id( ) { return id; }
	void set_id(int i) { id=i; }

	Object( );					//CONSTRUCTOR
	virtual ~Object( );			//DESTRUCTOR
	Object(const Object&);		//COPY CONSTRUCTOR
};


class String : public Object
{
private:
	std::string s;
public:
	int length( );
	void clear( );
	String concat(const String&);
	char& at(unsigned int);
	String& updateAt(unsigned int, char);
	void print( );

	std::string get_string( );

	bool equal(Object*);
	Object* clone( );
	String toString( );

	String(const char*);		//CONSTRUCTOR
	String(std::string);		//CONSTRUCTOR
	~String( );					//DESTRUCTOR
	String(const String&);		//COPY CONSTRUCTOR
};


class Employee;

class PlaneComponent : public Object
{
private:
	String st;
public:
	virtual bool equal(Object*);
	virtual String toString( );

	virtual void ready_check( )=0;
	virtual void process(Employee&)=0;

	String get_st( );

	PlaneComponent(String );				//CONSTRUCTOR
	virtual ~PlaneComponent( );				//DESTRUCTOR
	PlaneComponent(const PlaneComponent&);	//COPY CONSTRUCTOR
};

class PassengerCompartment : public PlaneComponent
{
private:
	PassengerCompartment* p;		//INNER PAassengerCompartment
public:
	void ready_check( );
	void process(Employee&);

	Object* clone( );
	bool equal(Object*);
	String toString( );

	void inside( );
	void inside_copy(const PassengerCompartment& );
	PassengerCompartment& get_passComp( );
	bool exists_inside( );

	PassengerCompartment(String);		//CONSTRUCTOR - ARGUMENT NECESSARY FOR PlaneComponent's CONSTRUCTOR
	~PassengerCompartment( );			//DESTRUCTOR
	PassengerCompartment(const PassengerCompartment&);	//COPY CONSTRUCTOR
};


class PrivateCompartment : public PlaneComponent	//ABSTRACT CLASS
{
public:
	virtual bool equal(Object*);

	PrivateCompartment(String);			//CONSTRUCTOR
	virtual ~PrivateCompartment( );		//DESTRUCTOR
	PrivateCompartment(const PrivateCompartment&);	//COPY CONSTRUCTOR
};


class EquipmentCompartment : public PrivateCompartment
{
public:
	void ready_check( );
	void process(Employee&);

	Object* clone( );
	bool equal(Object*);
	String toString( );

	EquipmentCompartment(String);		//CONSTRUCTOR
	~EquipmentCompartment( );			//DESTRUCTOR
	EquipmentCompartment(const EquipmentCompartment&);	//COPY CONSTRUCTOR
};


class CargoBay : public PrivateCompartment
{
private:
	EquipmentCompartment equipment;
public:
	void ready_check( );
	void process(Employee&);

	Object* clone( );
	bool equal(Object*);
	String toString( );

	EquipmentCompartment& get_equipment( );

	CargoBay(String);			//CONSTRUCTOR - ARGUMENT FOR CargoBay's DESCRIPTION
	~CargoBay( );				//DESTRUCTOR
	CargoBay(const CargoBay&);	//COPY CONSTRUCTOR
};



class Plane : public Object
{
private:
	String description;
	String title;
	int capacity;

	CargoBay cargobay;
	EquipmentCompartment* equipmentcompartment[3];
	PassengerCompartment** passengercompartment;

	int p_compartment_capacity;		//HOW MANY PassengerCompartmentS ARE IN THE Plane
public:
	void ready_check( );
	void process(Employee&);

	Object* clone( );
	bool equal(Object*);
	String toString( );

	String get_desription( );
	String get_title( );
	int get_capacity( );
	int get_compartment_capacity( );

	CargoBay& get_cargobay( );
	EquipmentCompartment& get_equipmentcompartment(int);		//ARGUMENT MENTION WHICH PassengerCompartment OR EquipmentCompartment WE WANT TO GET
	PassengerCompartment& get_passengercompartment(int);		//e.g. equipmentcompartment[2], passengercompartment[0]

	Plane(String, String);		//CONSTRUCTOR - 1st ARGUMENT FOR description - 2nd ARGUMENT FOR title
	~Plane( );					//DESTRUCTOR
	Plane(const Plane&);		//COPY CONSTRUCTOR
};



class Employee : public Object		//ABSTRACT CLASS
{
private:
	String name;
public:
	virtual void workOn(PassengerCompartment&)=0;
	virtual void workOn(EquipmentCompartment&)=0;
	virtual void workOn(CargoBay&)=0;
	void workOn(Plane&);

	virtual void report( )=0;

	bool equal(Object*);
	String toString( );

	String get_name( );

	Employee(String);				//CONSTRUCTOR - ARGUMENT FOR name
	virtual ~Employee( );			//DESTRUCTOR
	Employee(const Employee&);		//COPY CONSTRUCTOR
};

class SecurityEmployee : public Employee
{
public:
	void workOn(PassengerCompartment&);
	void workOn(EquipmentCompartment&);
	void workOn(CargoBay&);

	void report( );

	Object* clone( );

	SecurityEmployee(String);		//CONSTRUCTOR - ARGUMENT NECESSARY FOR Employee's CONSTRUCTOR
	~SecurityEmployee( );			//DESTRUCTOR
	SecurityEmployee(const SecurityEmployee&);		//COPY CONSTRUCTOR
};

class MaintenanceEmployee : public Employee
{
public:
	void workOn(PassengerCompartment&){ };	//MaintenanceEmployee IS NOT ALLOWED TO WORK IN PassengerCompartment
	void workOn(EquipmentCompartment&);
	void workOn(CargoBay&);

	void report( );

	Object* clone( );

	MaintenanceEmployee(String);		//CONSTRUCTOR - ARGUMENT NECESSARY FOR Employee's CONSTRUCTOR
	~MaintenanceEmployee( );			//DESTRUCTOR
	MaintenanceEmployee(const MaintenanceEmployee&);	//COPY CONSTRUCTOR
};

class CleaningEmployee : public Employee
{
public:
	void workOn(PassengerCompartment&);
	void workOn(EquipmentCompartment&){ };	//CleaningEmployee IS NOT ALLOWED TO WORK IN EquipmentCompartment
	void workOn(CargoBay&);

	void report( );

	Object* clone( );

	CleaningEmployee(String);			//CONSTRUCTOR - ARGUMENT NECESSARY FOR Employee's CONSTRUCTOR
	~CleaningEmployee( );				//DESTRUCTOR
	CleaningEmployee(const CleaningEmployee&);		//COPY CONSTRUCTOR
};


void clone_encrypt_and_print(Object& );
