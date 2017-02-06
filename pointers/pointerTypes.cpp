#include <iostream> 

using namespace std;

void fooA(int* p_ptr)
{
	int local = 99;
	*p_ptr = local; 	//modify the dereferenced value
	p_ptr = &local;		//assign p_ptr to another address
}

void fooB(int*& p_ptr)
{
	int local = 99;
	*p_ptr = local; 	//modify the dereferenced value
	p_ptr = &local;		//assign p_ptr to another address
}

void fooC(const int* p_ptr)
{
	int local = 99;
//	*p_ptr = local; 	Impossible because p_ptr is const data
	p_ptr = &local;		//assign p_ptr to another address
}

void fooD(const int*& p_ptr)
{
	int local = 99;
//	*p_ptr = local; 	Impossible because p_ptr is const data
	p_ptr = &local;		//assign p_ptr to another address
}

void fooE(const int*const p_ptr)
{
	int local = 99;
//	*p_ptr = local; 	Impossible because p_ptr is const data
//	p_ptr = &local;		Impossible because p_ptr is const pointer
}

void fooF(const int*const &p_ptr)
{
	int local = 99;
	//	*p_ptr = local; 	Impossible because p_ptr is const data
	//	p_ptr = &local;		Impossible because p_ptr is const pointer
}

int main()
{
	int num1 = 1;

	int *const ptr1 = &num1; //Type 1
	const int *ptr2 = &num1; //Type 2
	const int *const ptr3 = &num1; //Type 3  

	cout << "ptr1 is declared as type 1..." << endl;
	fooA(ptr1);
	cout << *ptr1 << endl;      //Expected result:  99

	num1 = 1;
//	ptr1 = &num1;	Impossible because ptr1 is const pointer
//	fooB(ptr1);		Impossible because ptr1 is const pointer
	cout << *ptr1 << endl;      //Expected result:  1

	num1 = 1;
//	ptr1 = &num1;	Impossible because ptr1 is const pointer
	fooC(ptr1);
	cout << *ptr1 << endl;      //Expected result:  1 

	num1 = 1;
//	ptr1 = &num1;	Impossible because ptr1 is const pointer
//	fooD(ptr1);	Impossible because ptr1 is const pointer
	cout << *ptr1 << endl;      //Expected result:  1

	num1 = 1;
//	ptr1 = &num1;	Impossible because ptr1 is const pointer
	fooE(ptr1);
	cout << *ptr1 << endl;      //Expected result:  1

	num1 = 1;
//	ptr1 = &num1;	Impossible because ptr1 is const pointer
	fooF(ptr1);
	cout << *ptr1 << endl;      //Expected result:  1

	
	cout << "ptr2 is declared as type 2..." << endl;

	num1 = 1;
	ptr2 = &num1;
//	fooA(ptr2);	Impossible because ptr2 is const data
	cout << *ptr2 << endl;      //Expected result:  1

	num1 = 1;
	ptr2 = &num1;
//	fooB(ptr2);	Impossible because ptr2 is const data
	cout << *ptr2 << endl;      //Expected result:  1

	num1 = 1;
	ptr2 = &num1;
	fooC(ptr2);
	cout << *ptr2 << endl;      //Expected result:  1

	num1 = 1;
	ptr2 = &num1;
	fooD(ptr2);
	cout << *ptr2 << endl;      //Expected result:  99

	num1 = 1;
	ptr2 = &num1;
	fooE(ptr2);
	cout << *ptr2 << endl;      //Expected result:  1

	num1 = 1;
	ptr2 = &num1;
	fooF(ptr2);
	cout << *ptr2 << endl;      //Expected result:  1

	
		cout << "ptr3 is declared as type 3..." << endl;
	num1 = 1;
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
//	fooA(ptr3);	Impossible because ptr3 is const data and pointer
	cout << *ptr3 << endl;      //Expected result:	1 

	num1 = 1;
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
//	fooB(ptr3);	Impossible because ptr3 is const data and pointer
	cout << *ptr3 << endl;      //Expected result:	1

	num1 = 1;
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
	fooC(ptr3);
	cout << *ptr3 << endl;      //Expected result:  1

	num1 = 1;
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
//	fooD(ptr3);	Impossible because ptr3 is const data and pointer
	cout << *ptr3 << endl;      //Expected result:  

	num1 = 1;	
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
	fooE(ptr3); 
	cout << *ptr3 << endl;      //Expected result:  1

	num1 = 1;
//	ptr3 = &num1;	Impossible because ptr3 is const data and pointer
	fooF(ptr3);
	cout << *ptr3 << endl;      //Expected result:  1

	fooF(&ptr1);
	
	return 0;
}

