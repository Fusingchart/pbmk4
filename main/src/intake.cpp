#include "main.h"
#include "intake.h"
#include "pneumatics.h"

/**
 * \file intake.cpp
 *
 * Intake subsystem implementation
 */

pros::Motor intake_motor(INTAKE_MOTOR_PORT, pros::v5::MotorGears::blue, pros::v5::MotorUnits::degrees);

// Current intake state
static IntakeState current_state = IDLE;

void intake_init() {
	// Initialize intake motor
	intake_motor.tare_position();
	intake_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	intake_motor.move_velocity(0);
	current_state = IDLE;
}

void intake_spin(double velocity) {
	intake_motor.move_velocity(velocity);
}

void intake_stop() {
	intake_motor.move_velocity(0);
}

void intake_set_state(IntakeState state) {
	current_state = state;
	
	// Handle state-specific behavior
	switch (state) {
		case INTAKE:
			score_high_piston = false;
			score_mid_piston = false;
			intake_spin(600);
			break;
		case SCORE_MID:
			score_high_piston = false;
			score_mid_piston = true;
			intake_spin(100);
			break;
		case SCORE_LOW:
			score_high_piston = false;
			score_mid_piston = false;
			intake_spin(-50);
			break;
		case SCORE_HIGH:
			score_high_piston = true;
			score_mid_piston = false;
			intake_spin(600);
			break;
		case IDLE:
			score_high_piston = false;
			score_mid_piston = false;
			intake_stop();
			break;
	}
}

IntakeState intake_get_state() {
	return current_state;
}
