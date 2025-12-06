#ifndef _AUTONS_UTILS_H_
#define _AUTONS_UTILS_H_

/**
 * \file autons_utils.h
 *
 * Autonomous utility functions
 */

/**
 * Aligns the robot straight using two front distance sensors
 * 
 * Uses the distance readings from two front distance sensors to ensure
 * the robot is parallel to a wall. Adjusts robot heading until both
 * sensors read approximately the same distance.
 * 
 * @param target_distance The desired distance from the wall (in mm)
 * @param timeout Maximum time to spend aligning (in ms)
 * @return true if alignment was successful, false if timeout occurred
 */
bool auton_align_straight(double target_distance, int timeout = 2000);

#endif // _AUTONS_UTILS_H_
