/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/


#include "Repetier.h"
#include "FSR.h"

/**
 * FSR-Glatzemann board firmware and links on https://github.com/Glatzemann/FsrBoardFirmware.
 *
 * The board listen default at address 77 all is G-Codes. And will get feedback over the i2c bus.
 */
void FSR::i2cSendString( char *gcode) {

	// initialize i2c bus wor writing
    HAL::i2cStart(FSR_I2C_PORT  << 1 | I2C_WRITE);

    while (*gcode != 0) {
      HAL::i2cWrite(*gcode++);
    }
    // Send a string termination
    HAL::i2cWrite(0);

    HAL::i2cStop();
//
//    // Awaiting at least a 0-Byte for no feedback.
//    HAL::i2cStart(FSR_I2C_PORT  << 1 | I2C_READ);
//
//    uint8 c = HAL::i2cReadAck();
//
//    while(c != 0) {
//    	// Write out on Serial device
//    	HAL::serialWriteByte(c);
//
//    	// read next byte
//    	c = HAL::i2cReadNak();
//
//    }
//
//    HAL::i2cStop();

}


