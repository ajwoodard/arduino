/*
 * The MIT License
 *
 * Copyright 2019 aaron.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/* 
 * File:   TLV0832.hpp
 * Author: aaron
 *
 * Created on December 23, 2018, 4:27 PM
 */

#ifndef TLV0832_HPP
#define TLV0832_HPP
#include <avr/io.h>
#include <stdint.h>
#include "../Utility/Pin/Pin.hpp"

/**
 * @class TLV0832 TLV0832.hpp "src/TLV0832/TLV0832.hpp"
 * 
 * @details
 * This class provides methods for interfacing with the TLV0832 ADC.
 * 
 * This class is unlikely to work for the TLV0831 due to the configuration
 * required at the start of each read, but if you understand this code you can
 * probably figure out how to make it work.
 * 
 * @see <http://www.ti.com/lit/ds/slas148/slas148.pdf>
 * 
 */
class TLV0832 {
public:
    /// No need for default constructor
    TLV0832() = delete;
    virtual ~TLV0832() = default;
    
    /**
     * read data from the TLV0832 pin
     * @param dataPin : The pin on the MCU that will receive the data (connected to pin 6 on the TLV0832)
     * @param clockPin : The pin on the MCU to be pulsed HIGH/LOW (connected to pin 7 on the TLV0832)
     * @param clearPin : The pin on the MCU to be set LOW to initialize conversion (connected to pin 1 on the TLV0832)
     * @param configPin : The pin on the MCU that will configure the TLV0832 input modes (connected to pin 5 on the TLV0832)
     * @param channel : The channel or mode to read from (see initRead below)
     * @return byte : the converted analog signal
     */
    static uint8_t read(uint8_t dataPin, uint8_t clockPin, uint8_t clearPin, uint8_t configPin, uint8_t channel);
    
private:
    /**
     * initialize the TLV0832 to read either from CH0 or CH1 or some differential of the two channels.
     * 
     * The channel parameter can have the following values.
     * 
     * - 0 = read from CH0
     * - 1 = read from CH1
     * - 2 = differential of +CH0 and -CH1
     * - 3 = differential of -CH0 and +CH1
     * 
     * @param clockPin: same as above
     * @param clearPin: same as above
     * @param configPin : same as above
     * @param channel: 0, 1, 2, 3.
     */
    static void initRead(uint8_t clockPin, uint8_t clearPin, uint8_t configPin, uint8_t channel);

};

#endif /* TLV0832_HPP */

