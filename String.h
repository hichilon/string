
/*************************************************************************************************
Simple String Class

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
Software: Simple String Class
Author: Ezequiel Miravalles
Website: http://www.neoegm.com/tech/programming/c-cpp/simple-string-class/
License: GNU GPL v3 (attached, read above)
Last modification: 08/09/2009
*************************************************************************************************/

#pragma once

#include <iostream>
#include <cstring>

class String
{
	char *m_pszString;	//Allocated buffer
	int m_nAllocated;	//Allocated length
	
public:
	//Construction and destruction
	String() { m_pszString = NULL; m_nAllocated = 0; }
	~String() { if (m_pszString) delete [] m_pszString; }

	//Copy constructors
	String(const char *pszString) { m_pszString = NULL; m_nAllocated = 0; operator=(pszString); }
	String(const String& rsString) { m_pszString = NULL; m_nAllocated = 0; operator=(rsString); }

	//Operators (assignment)
	String& operator=(const char *pszString);
	String& operator=(const String& rsString) { return operator=(rsString.m_pszString); }

	//Operators (concatenation)
	String& operator+=(const char *pszString);
	String& operator+=(String& rsString) { return operator+=(rsString.m_pszString); }
	String operator+(String rsString);

	//Operators (comparison)
	bool operator<(String sString) { return strcmp(operator const char*(), (const char*)sString) < 0; }
	bool operator<=(String sString) { int nCmp = strcmp(operator const char*(), (const char*)sString); return nCmp < 0 || nCmp == 0; }

	bool operator>(String sString) { return strcmp(operator const char*(), (const char*)sString) > 0; }
	bool operator>=(String sString) { int nCmp = strcmp(operator const char*(), (const char*)sString); return nCmp > 0 || nCmp == 0; }

	bool operator==(String sString) { return strcmp(operator const char*(), (const char*)sString) == 0; }
	bool operator!=(String sString) { return !operator==(sString); }

	//Operations
	void Clear();
	String Lower() { String sTmp = *this; sTmp.MakeLower(); return sTmp; }
	String Upper() { String sTmp = *this; sTmp.MakeUpper(); return sTmp; }

	//Information
	int Length() { return m_pszString?strlen(m_pszString):0; }

	//Cast operators
	operator const char*() { return m_pszString?m_pszString:""; }

protected:	//Helper functions
	bool Reallocate(int nSize);

	String& MakeLower();
	String& MakeUpper();
};

//Output e input
std::ostream& operator<<(std::ostream& oStream, String& rsString);
std::istream& operator>>(std::istream& iStream, String& rsString);
