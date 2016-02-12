#include<iostream>
using namespace std;
void take_data(int a[][10], int b[][10], int r1, int c1, int r2, int c2)    // function to take data from user  
{
	int i, j;
	cout << endl << "Enter elements of matrix 1:" << endl;
	for (i = 0; i<r1; ++i)
	for (j = 0; j<c1; ++j)
	{
		cout << "Enter element a" << i + 1 << j + 1 << " : ";
		cin >> a[i][j];
	}

	cout << endl << "Enter elements of matrix 2:" << endl;
	for (i = 0; i<r2; ++i)
	for (j = 0; j<c2; ++j)
	{
		cout << "Enter element b" << i + 1 << j + 1 << " : ";
		cin >> b[i][j];
	}
}

void multiplication(int a[][10], int b[][10], int mult[][10], int r1, int c1, int r2, int c2)  // computing multiplication of matrices
{
	int i, j, k;
	/* Initializing elements of matrix mult to 0.*/
	for (i = 0; i<r1; ++i)
	for (j = 0; j<c2; ++j)
	{
		mult[i][j] = 0;
	}
	/* Multiplying matrix a and b and storing in array mult. */
	for (i = 0; i<r1; ++i)
	for (j = 0; j<c2; ++j)
	for (k = 0; k<c1; ++k)
	{
		mult[i][j] += a[i][k] * b[k][j];
	}
}

void display(int mult[][10], int r1, int c2)    // displaying output result
{
	int i, j;
	cout << endl << "Output Matrix: " << endl;
	for (i = 0; i < r1; ++i)
	for (j = 0; j < c2; ++j)
	{
		cout << " " << mult[i][j];
		if (j == c2 - 1)
			cout << endl;
	}
}
	/*
	Strassen algorithm
	*/

	void strassenMUL()
	{
		int a[2][2], b[2][2], c[2][2];
		int m1, m2, m3, m4, m5, m6, m7, i, j;
		cout << "Enter the elements of 2x2 Matrix 1:\n";
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				cin >> a[i][j];
			}
		}
		cout << "Enter the elements of 2x2 Matrix 2:\n";
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				cin >> b[i][j];
			}
		}
		cout << "\nFirst matrix is:\n";
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				cout << a[i][j];
			}
			cout << "\n";
		}
		cout << "\nSecond matrix is\n";
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				cout << b[i][j];
			}
			cout << "\n";
		}
		m1 = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
		m2 = (a[1][0] + a[1][1])*b[0][0];
		m3 = a[0][0] * (b[0][1] - b[1][1]);
		m4 = a[1][1] * (b[1][0] - b[0][0]);
		m5 = (a[0][0] + a[0][1])*b[1][1];
		m6 = (a[1][0] - a[0][0])*(b[0][0] + b[0][1]);
		m7 = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);
		c[0][0] = m1 + m4 - m5 + m7;
		c[0][1] = m3 + m5;
		c[1][0] = m2 + m4;
		c[1][1] = m1 - m2 + m3 + m6;
		cout << "\nProduct of both is:\n";
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < 2; j++)
			{
				cout << c[i][j];
			}
			cout << "\n";
		}
	}
