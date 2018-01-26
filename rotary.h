/*
 * rotary.h
 *
 *  Created on: Jun 27, 2015
 *      Author: Martijn van Dijk
 * 		License: MIT
 */

//! @file 
//! This library implements a microcontroller-agnostic rotary encoder handler.

/**
 * @brief Enable or disable warp around
 * @details If this is enabled, the encoder value will go to the minimum value if the maximum value is reached, and vice versa.
 * 
 * @param set 1 for enable, 0 for disable.
 */
void rotarySetWarpAround(int set);

/**
 * @brief Get the warp around setting
 * @details see rotayrSetWarpAround
 * @return 1 for enabled, 0 for disabled.
 */
int rortaryGetWarpARound(void);

/**
 * @brief Set the rotary encoder position.
 * @details 
 * 
 * @param position the position to jump to.
 */
void rotarySetPosition(int position);

/**
 * @brief Get the rotary encoder position.
 * @return The current position
 */
int rotaryGetPosition(void);


/**
 * @brief Set the minimum rotary encoder value.
 * 
 * @param min The minimum value.
 */
void rotarySetMin(int min);

/**
 * @brief Get the minimum rotary encoder vaule.
 * 
 * @return The currently set minimum value.
 */
int rotaryGetMin(void);


/**
 * @brief Set the maximum rotary encoder value.
 * 
 * @param max The maximum value 
 */
void rotarySetMax(int max);

/**
 * @brief Get the maximum rotary encoder value.
 * 
 * @return The maximum value
 */
int rotaryGetMax(void);


/**
 * @brief Update the rotary encoder position
 * @details Call this funciton as often as possible for maximum accuracy, but take debouncing in mind.
 * 
 * @param a The phase of rotary encoder pin A
 * @param b The phase of rotary encoder pin B
 */
void rotaryUpdate(int a, int b);