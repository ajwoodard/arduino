/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Motor28BYJ48.hpp
 * Author: aaron
 *
 * Created on January 5, 2019, 5:40 PM
 */

#ifndef MOTOR28BYJ48_HPP
#define MOTOR28BYJ48_HPP

class Motor28BYJ48 {
public:
    Motor28BYJ48() = default;
    virtual ~Motor28BYJ48() = default;
    
    /**
     * If we are writing directly to the motor use this constructor to specify
     * how the motor is connected to the board.
     */
    Motor28BYJ48(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3);
    
    /**
     * If we are using a motor manager (ie not directly writing to the pins),
     * use these functions to return the current pin order. The motor manager
     * will write the bits to the pins
     * 
     * These functions will increment/decrement the currentStep counter
     * 
     * @return step#: the 4 bits for the current step.
     */
    uint8_t getNextStep();
    uint8_t getLastStep();
    
    /**
     * If we are writing to the pins directly use these functions. It will use
     * Pin::set() to set the corresponding pins with the current step.
     * 
     * These functions will increment/decrement the currentStep counter
     */
    void stepForward();
    void stepBackward();
    
    
private:
    /**
     * If we are writing directly to the pins, these will be set so we know which
     * pins to write to.
     */
    uint8_t pin0, pin1, pin2, pin3;
    /**
     * keeps track of what step we are on:
     */
    uint8_t currentStep;

    /**
     * The motor works by setting 4 pins in a specific order and controlling
     * the delay between each step.
     * 
     * This sequence was found here:
     * <https://www.instructables.com/id/28BYJ-48-Stepper-Motor/>
     * 
     * @note the sequence below will move the motor CCW (reverse the order for CW)
     */
    static const uint8_t step[8] = {
        0b0001,
        0b0011,
        0b0010,
        0b0110,
        0b0100,
        0b1100,
        0b1000,
        0b1001
    };
};

#endif /* MOTOR28BYJ48_HPP */

