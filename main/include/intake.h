#ifndef _INTAKE_H_
#define _INTAKE_H_

/**
 * \file intake.h
 *
 * Intake subsystem declarations
 */

#include "config.h"
#include "api.h"

// Intake states
enum IntakeState {
	INTAKE = 0,
	SCORE_MID = 1,
	SCORE_LOW = 2,
	SCORE_HIGH = 3,
	IDLE = 4
};

void intake_init();
void intake_spin(double velocity);
void intake_stop();
void intake_set_state(IntakeState state);
IntakeState intake_get_state();

#endif // _INTAKE_H_
