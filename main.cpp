
/*************************************************************************************************
This file is part of Simple String Class Sample Project

Copyright (C) 2009 Ezequiel Gastón Miravalles

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************************************/

/*************************************************************************************************
Software: Simple String Class Sample Project
Author: Ezequiel Miravalles
Website: http://www.neoegm.com/tech/programming/c-cpp/simple-string-class/
License: GNU GPL v3 (attached, read above)
Last modification: 08/09/2009
*************************************************************************************************/

#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;
#include "String.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "String sample project" << endl;
	cout << "---------------------" << endl << endl;

	String a("This"), b("is"), c("a"), d("test");
	String e = a + " " + b + " " + c + " " + d;

	cout << "String parts:" << endl;
	cout << '\t' << a << endl;
	cout << '\t' << b << endl;
	cout << '\t' << c << endl;
	cout << '\t' << d << endl << endl;

	cout << "Concatenated with spaces:" << endl;
	cout << '\t' << e << endl << endl;

	String f, g;

	cout << "Please input a string (empty to break): ";
	cin >> f;
	cout << "Please input other string (empty to break): ";
	cin >> g;

	cout << endl;

	cout << "1st string (" << f << ") is " << f.Length() << " chars long." << endl;
	cout << "2nd string (" << g << ") is " << g.Length() << " chars long." << endl;

	cout << endl;

	cout << "1st string in lowercase is " << f.Lower() << endl;
	cout << "1st string in uppercase is " << f.Upper() << endl << endl;

	cout << "2nd string in lowercase is " << g.Lower() << endl;
	cout << "2nd string in uppercase is " << g.Upper() << endl << endl;

	cout << "1 < 2\t=> " << (f<g?"true":"false") << endl;
	cout << "1 <= 2\t=> " << (f<=g?"true":"false") << endl;
	cout << "1 > 2\t=> " << (f>g?"true":"false") << endl;
	cout << "1 >= 2\t=> " << (f>=g?"true":"false") << endl;
	cout << "1 == 2\t=> " << (f==g?"true":"false") << endl;
	cout << "1 != 2\t=> " << (f!=g?"true":"false") << endl << endl;

	if (f == g)
		cout << "Strings are equal." << endl;
	else
		cout << "Strings are not equal." << endl;

	cout << endl;

	cout << "1+2\t=> " << f+g << endl;
	cout << "2+1\t=> " << g+f << endl;

	cout << endl;

    return 0;
}
