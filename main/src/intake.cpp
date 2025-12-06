#include "main.h"
#include "intake.h"

/**
 * \file intake.cpp
 *
 * Intake subsystem implementation
 */

// Current intake state
static IntakeState current_state = INTAKE;

void intake_init() {
	// TODO: Initialize intake motors
	current_state = INTAKE;
}

void intake_spin(double velocity) {
	// TODO: Spin intake at given velocity
}

void intake_stop() {
	// TODO: Stop intake motors
}

void intake_set_state(IntakeState state) {
	current_state = state;
	
	// Handle state-specific behavior
	switch (state) {
		case INTAKE:
			// TODO: Set intake velocity for intaking
			break;
		case SCORE_MID:
			// TODO: Set intake velocity for mid scoring
			break;
		case SCORE_LOW:
			// TODO: Set intake velocity for low scoring
			break;
		case SCORE_HIGH:
			// TODO: Set intake velocity for high scoring
			break;
	}
}

IntakeState intake_get_state() {
	return current_state;
}
