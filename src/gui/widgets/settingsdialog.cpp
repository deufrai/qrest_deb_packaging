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

#include <QMessageBox>

#include "settingsdialog.h"
#include "../../settings/settings.h"
#include "../../helpers/widgetsizehelper.h"
#include "../../midi/midicontroller.h"
#include "midilearndialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
        QDialog(parent) {
    ui.setupUi(this);

#ifdef Q_WS_MAC
    // set default font sizes
    WidgetSizeHelper::setDefaultFontSize( this );
#endif

#ifndef Q_WS_WIN
    ui.devicesCombo->setHidden(true);
    ui.connectDeviceLabel->setHidden(true);
#endif

    // we don't want the "what's this" button on this dialog
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    // poulpate left-side sections list
    _mainSection = new QListWidgetItem(tr("Main"), ui.sectionsList);
    _midiSection = new QListWidgetItem(tr("MIDI"), ui.sectionsList);
    ui.sectionsList->addItem(_mainSection);
    ui.sectionsList->addItem(_midiSection);

    // check 'remember window position' according to saved prefs
    ui.chkRememberWindowPos->setChecked(

            Settings::getInstance()->getSettings().value(

                    Settings::REMEMBER_WINDOW_POSITION,
                    Settings::REMEMBER_WINDOW_POSITION_DEFAULT).toBool());

    // prefill 'midi input port name' according to saved prefs
    ui.midiPortNameLineEdit->setText(

            Settings::getInstance()->getSettings().value(

                    Settings::MIDI_PORT_NAME,
                    Settings::MIDI_PORT_NAME_DEFAUT).toString());

#ifdef Q_WS_WIN
    /*
     * populate devices comboBox
     * and make devices comboBox show the currently used device (if found)
     */
    ui.devicesCombo->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    std::vector<std::string> devices = MidiController::getInstance()->getDeviceNames();
    QString currentlyUsedDevice = Settings::getInstance()->getSettings().value(

        Settings::MIDI_DEVICE,
        Settings::MIDI_DEVICE_DEFAULT).toString();

    int currentlyUsedDeviceIndex = 0;


    for (unsigned int i=0; i<devices.size(); i++) {

        ui.devicesCombo->addItem(QString::fromStdString(devices.at(i)));

        if ( 0 == devices.at(i).compare(currentlyUsedDevice.toStdString()) ) {

            currentlyUsedDeviceIndex = i;
        }
    }

    ui.devicesCombo->setCurrentIndex(currentlyUsedDeviceIndex);
#endif

    // wet set main section active by default
    ui.sectionsList->setItemSelected(_mainSection, true);

    // setup a RegExp validator for midi input name. Only 7bit ASCII
    QRegExp* midiPortNameRegExp = new QRegExp("[A-Za-z0-9 ]+");

    QRegExpValidator* midiInputPortNameValidator = new QRegExpValidator(
            *midiPortNameRegExp, this);

    ui.midiPortNameLineEdit->setValidator(midiInputPortNameValidator);
}

SettingsDialog::~SettingsDialog() {

}

void SettingsDialog::on_triggerButton_clicked() {

    MidiLearnDialog dlg(this);
    dlg.exec();
}

void SettingsDialog::accept() {

    // MIDI Input port name cannot be empty
    QString midiInputPortNewName =
            ui.midiPortNameLineEdit->text().trimmed().simplified();

    if (midiInputPortNewName.isEmpty()) {

        QMessageBox::critical(this, tr("Invalid data"),
                              tr("MIDI input port name cannot be empty"));
        return;
    }

    // save 'remember window position' settings
    _rememberWidnowPosition = ui.chkRememberWindowPos->isChecked();

    // save midi input port name
    _inputPortName = midiInputPortNewName;



#ifdef Q_WS_WIN

    // save midi device name
    _deviceName = ui.devicesCombo->currentText();


#endif

    QDialog::accept();
}
