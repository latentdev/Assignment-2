#include "Array2D.h"
#include "Row.h"
#include <iostream>
using namespace std;

template<typename a_type>
void output(Array2D<a_type>& array);
template<typename a_type>
void fill(Array2D<a_type>& array);
template<typename a_type>
void fillnick(Array2D<a_type>& array);

/****************************************************
*Function void driver()
*	driver that test various aspects of my class
*****************************************************/
void driver()
{
	cout << "Creating 2D array C(2,5)" << endl;
	Array2D<int> c(2, 5);
	cout << "Filling C with numbers" << endl;
	fill(c);
	cout << "Outputting C" << endl;
	output(c);
	cout << "Setting C's Rows to 4" << endl;
	c.setRow(4);
	cout << "Outputting C" << endl;
	output(c);
	cout << "Setting C's Columns to 4" << endl;
	c.setColumn(4);
	cout << "Outputting C" << endl;
	output(c);
	cout << "Filling C with numbers" << endl;
	fill(c);
	cout << "Outputting C" << endl;
	output(c);
	cout << "Creating new 2D array A with C" << endl;
	Array2D<int> a(c);
	cout << "Outputting A" << endl;
	output(a);
	cout << "Creating new 2D array B and setting it equal to C with equals operator" << endl;
	Array2D<int> b(4, 4);
	b = c;
	output(b);
	cout << "Creating new 2D array of chars D and filling it with the word nick" << endl;
	Array2D<char> d(4, 4);
	fillnick(d);
	cout << "Outputting D" << endl;
	output(d);
	cout << "Setting row to 3" << endl;
	d.setRow(3);
	cout << "Outputting D" << endl;
	output(d);
	cout << "Setting column to 3" << endl;
	d.setColumn(3);
	cout << "Outputting D" << endl;
	output(d);
	cout << "Trying to access D[0][-3]" << endl;
	try {
		cout << d[0][-3] << endl;
	}
	catch (const Exception& e) {
		cout << e << endl;
	}
}

/****************************************************
*outputs every value stored in the passed in Array2D object
*****************************************************/
template<typename a_type>
void output(Array2D<a_type>& array)
{
	int row = array.getRow();
	int col = array.getColumn();
	for (int i = 0; i <row; i++)
	{
		for (int m = 0; m < col; m++)
		{
			cout << array[i][m];
		}
		cout << endl;
	}
	cout << array.getRow() << " Rows" << endl << array.getColumn() << " Columns" << endl;
}

/****************************************************
*fills the passed in Array2D object with numbers
*****************************************************/
template<typename a_type>
void fill(Array2D<a_type>& array)
{
	int row = array.getRow();
	int col = array.getColumn();
	for (int i = 0; i <row; i++)
	{
		for (int m = 0; m < col; m++)
		{
			array[i][m] = m;
		}
	}
}

/****************************************************
*fills passed in Array with the word nick
*only works on arrays that have a number of columns that is greater than 4
*****************************************************/
template<typename a_type>
void fillnick(Array2D<a_type>& array)
{
	int row = array.getRow();
	int col = array.getColumn();
	for (int i = 0; i <row; i++)
	{
		array[i][0] = 'n';
		array[i][1] = 'i';
		array[i][2] = 'c';
		array[i][3] = 'k';
	}
}