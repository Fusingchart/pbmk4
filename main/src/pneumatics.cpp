#include "main.h"
#include "pneumatics.h"

/**
 * \file pneumatics.cpp
 *
 * Pneumatics subsystem implementation
 */

// Current pneumatics state
static PneumaticsState current_state = {
	.matchloader = false,
	.pto = false,
	.park = false,
	.score_mid = false,
	.score_low = false
};

void pneumatics_init() {
	// TODO: Initialize pneumatics solenoids
	current_state = {
		.matchloader = false,
		.pto = false,
		.park = false,
		.score_mid = false,
		.score_low = false
	};
}

void pneumatics_set_state(const PneumaticsState& state) {
	current_state = state;
	
	// TODO: Update solenoids based on state
	// Handle matchloader
	if (current_state.matchloader) {
		// TODO: Actuate matchloader solenoid
	}
	
	// Handle PTO
	if (current_state.pto) {
		// TODO: Actuate PTO solenoid
	}
	
	// Handle park
	if (current_state.park) {
		// TODO: Actuate park solenoid
	}
	
	// Handle score_mid
	if (current_state.score_mid) {
		// TODO: Actuate score_mid solenoid
	}
	
	// Handle score_low
	if (current_state.score_low) {
		// TODO: Actuate score_low solenoid
	}
}

PneumaticsState pneumatics_get_state() {
	return current_state;
}

void pneumatics_set_matchloader(bool enable) {
	current_state.matchloader = enable;
	// TODO: Actuate matchloader solenoid
}

void pneumatics_set_pto(bool enable) {
	current_state.pto = enable;
	// TODO: Actuate PTO solenoid
}

void pneumatics_set_park(bool enable) {
	current_state.park = enable;
	// TODO: Actuate park solenoid
}

void pneumatics_set_score_mid(bool enable) {
	current_state.score_mid = enable;
	// TODO: Actuate score_mid solenoid
}

void pneumatics_set_score_low(bool enable) {
	current_state.score_low = enable;
	// TODO: Actuate score_low solenoid
}
