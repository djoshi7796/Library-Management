/*This file is a part of Library-Management

    Library-Management is a free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


#include"libman.h"

/*Calculates fine to be paid*/
int calcfine(date actual, date due){
	if(actual.year < due.year)
		return 0;
	if(actual.year > due.year)
		return 300;
	else {
		if(actual.day > due.day && actual.month == due.month)
			return 5*(actual.day - due.day);
		else if(actual.month > due.month)
			return 30*(actual.month - due.month);
		else
			return 0;
		}
}
