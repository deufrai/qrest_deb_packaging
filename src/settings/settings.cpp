/*
 *  qrest
 *
 *  Copyright (C) 2008-2012 - Frédéric CORNU
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

#include "settings.h"

Settings* Settings::_instance = 0;

const char* Settings::WINDOW_POSITION = "windowPosition";
const char* Settings::REMEMBER_WINDOW_POSITION = "rememberWindowPosition";

const char* Settings::MIDI_PORT_NAME = "midiPortName";
const char* Settings::MIDI_PORT_NAME_DEFAUT = "Qrest MIDI IN";

const char* Settings::MIDI_DEVICE = "midiDevice";
const char* Settings::MIDI_DEVICE_DEFAULT = "neverused";

const char* Settings::MIDI_TRIGGER_EVENT = "triggerEvent";

Settings::Settings() 
: _settings("wardsback", "qrest") {

}

Settings::~Settings() {

}

Settings* Settings::getInstance() {

    if (0 == _instance) {

        _instance = new Settings();
    }

    return _instance;
}

