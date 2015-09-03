
/*************************************************************************************************
This file is part of Simple String Class

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

#include <iostream>

using std::ostream;
using std::istream;

#include "String.h"
#include <cstring>

//Consts
const int cnStringReadBufferSize = 16;
//------

String& String::operator=(const char *pszString)
{
	if (!pszString)
	{
		Clear();
		return *this;
	}

	int nLen = strlen(pszString);

	if (nLen < m_nAllocated)	//If allocated space is enough
		strcpy(m_pszString, pszString);
	else
	{
		if (m_pszString)
		{
			delete [] m_pszString;
			m_pszString = NULL;
		}

		m_nAllocated = nLen+1;
		m_pszString = new char[m_nAllocated];
		
		if (!m_pszString)	//Couldn't allocate
			m_nAllocated = 0;
		else
			strcpy(m_pszString, pszString);
	}

	return *this;
}

void String::Clear()
{
	if (m_pszString)
		delete [] m_pszString;

	m_pszString = NULL;
	m_nAllocated = 0;
}

String& String::operator+=(const char *pszString)
{
	int nLen = Length() + strlen(pszString);

	if (nLen >= m_nAllocated)	//Reallocation needed
		if (!Reallocate(nLen+1))
			return *this;

	strcat(m_pszString, pszString);

	return *this;
}

String String::operator+(String rsString)
{
	String sString(*this);

	sString += rsString;
	
	return sString;
}

bool String::Reallocate(int nSize)
{
	char *pszOldStr = m_pszString;

	m_nAllocated = nSize;
	m_pszString = new char [nSize];

	if (!m_pszString)	//Couldn't allocate
	{
		if (pszOldStr)
			delete [] pszOldStr;
		m_nAllocated = 0;
		return false;
	}

	if (pszOldStr)
	{
		strcpy(m_pszString, pszOldStr);
		delete [] pszOldStr;
	}
	else
		m_pszString[0] = '\0';

	return true;
}

String& String::MakeLower()
{
	if (m_pszString)
		for (int i = 0; m_pszString[i]; i++)
			m_pszString[i] = tolower(m_pszString[i]);

	 return *this;
}

String& String::MakeUpper()
{
	if (m_pszString)
		for (int i = 0; m_pszString[i]; i++)
			m_pszString[i] = toupper(m_pszString[i]);

	 return *this;
}

ostream& operator<<(ostream& oStream, String& rsString)
{
	oStream << (const char*)rsString;
	return oStream;
}

istream& operator>>(istream& iStream, String& rsString)
{
	char pszBuffer[cnStringReadBufferSize];
	pszBuffer[0] = '\0';	//Just in case, we make it a valid string

	rsString.Clear();

	do
	{
		iStream.clear();
		iStream.getline(pszBuffer, cnStringReadBufferSize);
		rsString += pszBuffer;
	} while (iStream.fail() && (!iStream.eof()));

	return iStream;
}
