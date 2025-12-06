#include "main.h"
#include "autons_utils.h"

/**
 * \file autons_utils.cpp
 *
 * Autonomous utility implementations
 */

bool auton_align_straight(double target_distance, int timeout) {	
	uint32_t start_time = pros::millis();
	const double ALIGNMENT_TOLERANCE = 5.0;  // mm tolerance between sensors
	const double MAX_CORRECTION_SPEED = 50.0;  // max turning speed
	
	while (pros::millis() - start_time < timeout) {
		// TODO: Get distance readings from sensors
		double left_distance = left_sensor.get();
		double right_distance = right_sensor.get();
		
		// Calculate difference between sensors
		double difference = left_distance - right_distance;
		
		// If aligned within tolerance, we're done
		if (fabs(difference) < ALIGNMENT_TOLERANCE) {
		    return true;
		}
		
		// Calculate correction speed based on difference
		double correction = difference * 0.5;  // P controller gain
		correction = fmax(fmin(correction, MAX_CORRECTION_SPEED), -MAX_CORRECTION_SPEED);
		
		left_motors.move(correction);
		right_motors.move(-correction);
		
		pros::delay(20);
	}
	
	left_motors.move(0);
	right_motors.move(0);
	
	return false;  // Timeout occurred
}
