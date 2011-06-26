/*---------------------------------------------------------------------------*\
machinePrecision - Find the machine epsilon

Copyright Information
    Copyright (C) 2011 Alberto Passalacqua

License
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

Application
    machinePrecision

Description
    Finds the machine epsilon

\*---------------------------------------------------------------------------*/

#include <iostream>
#include <float.h>

using namespace std;

template <class T>
T machPrecision(void)
{
	T epsilon;

	epsilon = (T)(1.0);

	do
	{
		epsilon /= (T)(2.0);
	}
	while (((T)(1.0) + epsilon/2.0) != 1.0);

	return epsilon;
}

int main()
{
    cout << "\nMachine precision" << endl;
    cout << "-----------------" << endl;

    cout << "\nValues obtained from float.h:" << endl;
	cout << "\nFloat       " << FLT_EPSILON << endl;
	cout << "Double      " << DBL_EPSILON << endl;
	cout << "Long double " << LDBL_EPSILON << endl;

	cout << "\nApproximated values computed on this machine:" << endl;
	cout << "\nFloat       " << machPrecision<float>() << endl;
	cout << "Double      " << machPrecision<double>() << endl;
	cout << "Long double " << machPrecision<long double>() << endl;

	return 0;
}
