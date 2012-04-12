/*
 *  qrest
 *
 *  Copyright (C) 2008 - Frédéric CORNU
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

#include "observable.h"

////////////////////////////////////////////////////////////////////////////////
//
// INIT
//
////////////////////////////////////////////////////////////////////////////////

Observable::Observable() {
}




Observable::~Observable() {
}




////////////////////////////////////////////////////////////////////////////////
//
// MEMBER FUNCTIONS
//
////////////////////////////////////////////////////////////////////////////////

void Observable::registerObserver(Observer* observer) {

    _observers.push_back(observer);
}




void Observable::removeObserver(Observer* observer) {

    vector<Observer*>::iterator it = _observers.begin();

    bool found = false;

    while ( it != _observers.end() && ! found ) {

        if ( *it == observer ) {

            _observers.erase(it);
            found = true;
        }
        it++;
    }
}




void Observable::notifyObservers() const {


    vector<Observer*>::const_iterator it = _observers.begin();

    while ( it != _observers.end() ) {

        (*it)->updateView();
        it++;
    }
}
