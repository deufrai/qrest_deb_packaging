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

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/**
 * Stores application-wide constants.
 */
class Constants {

private:
    Constants();
    virtual ~Constants();

public:
    /**
     * how many seconds in a minute ?
     */
    static const double SECONDS_PER_MINUTE = 60.0;

    /**
     * how many milliseconds in a second ?
     */
    static const double MILLISEC_PER_SECOND = 1000.0;

    /**
     * String describing version
     */
    static const char* VERSION_STRING;

    /**
     * String describing path to i18n folder.
     *
     * It may be expressed as a relative path from where bianry is,
     * or absolutely.
     */
    static const char* I18N_FOLDER_LOCATION;

    /**
     * String describing path to online help.
     */
    static const char* ONLINE_HELP_LOCATION;

    /**
     * targetted steadiness ration for taps to be considered steady
     */
    static const double STEADINESS_TARGET_RATIO = 0.90;

    /**
     * progressPie widget default value
     */
    static const double PROGRESSPIE_DEFAULT_VALUE = 0.0;

    /**
     * value for a full progresspie
     */
    static const double PROGRESSPIE_FULL = 1.0;

    /**
     * temp messages are shown for 1.5 seconds
     */
    static const int STATUSBAR_TEMP_TIMEOUT = 1500;

    /** Default tempo for app startup */
    static const double TEMPO_DEFAULT = 60.0;

    /** Minimum allowed tempo as input. */
    static const double TEMPO_MIN = 1.0;

    /** Maximum allowed tempo as input. */
    static const double TEMPO_MAX = 999.0;

    /** Size (in points) of widget fonts for mac */
    static const int MAC_FONT_SIZE = 13;

};

#endif /* CONSTANTS_H_ */
