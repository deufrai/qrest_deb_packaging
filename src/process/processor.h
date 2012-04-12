/*
 *  qrest
 *
 *  Copyright (C) 2008-2011 - Frédéric CORNU
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

/**
 * Interface of all objects in charge of data processing.
 */
class Processor {

protected:

	// INIT

	Processor();
	virtual ~Processor();

public:

	// INTERFACE

	/**
	 * Perform processing according to concrete type
	 */
	virtual void process(void) = 0;
};

#endif /* PROCESSOR_H_ */
