#pragma once

/**
 * @file config.h
 * @brief Robot hardware configuration for VEX V5
 * 
 * Defines all motor ports, sensor ports, and pneumatic actuator ports
 */

#ifndef CONFIG_H
#define CONFIG_H

// ============================================================================
// DRIVETRAIN CONFIGURATION
// ============================================================================

// One 5.5W motor per side (geared for speed)
#define LEFT_FRONT_5_5W_PORT 15
#define RIGHT_FRONT_5_5W_PORT 17

// Left side drivetrain motors (11W - higher torque)
#define LEFT_BACK_11W_PORT 5
#define LEFT_MID_11W_PORT 6
#define LEFT_FRONT_11W_PORT 7

// Right side drivetrain motors (11W - higher torque)
#define RIGHT_BACK_11W_PORT 8
#define RIGHT_MID_11W_PORT 9
#define RIGHT_FRONT_11W_PORT 10

// ============================================================================
// INTAKE SYSTEM
// ============================================================================

// Intake motor (11W)
#define INTAKE_MOTOR_PORT 11

// ============================================================================
// SENSOR CONFIGURATION
// ============================================================================

// IMU sensor (for gyro heading)
#define IMU_PORT 15

// ============================================================================
// PNEUMATIC ACTUATORS (ADI Ports)
// ============================================================================

// Pneumatics for goal mechanisms
#define MATCHLOADER_SOLENOID_PORT 'A'    // Matchloader piston
#define PTO_SOLENOID_A_PORT 'B'          // PTO piston A
#define PTO_SOLENOID_B_PORT 'C'          // PTO piston B
#define SCORE_MIDDLE_SOLENOID_PORT 'D'   // Middle goal piston
#define SCORE_HIGH_SOLENOID_PORT 'E'     // Long goal piston
#define PARK_SOLENOID_A_PORT 'F'         // Park piston A
#define PARK_SOLENOID_B_PORT 'G'         // Park piston B 

// ============================================================================
// MOTOR CONFIGURATION CONSTANTS
// ============================================================================

// Motor gearing ratios
#define MOTOR_SPEED_GEAR_RATIO 3.6   // 5.5W motors (36:100)
#define MOTOR_TORQUE_GEAR_RATIO 2.0  // 11W motors (20:100)

// Wheel diameter (in inches)
#define DRIVETRAIN_WHEEL_DIAMETER 4.0

// Track width (distance between left and right wheels in inches)
#define DRIVETRAIN_TRACK_WIDTH 9.8

0.5714


// ============================================================================
// SENSOR CALIBRATION
// ============================================================================

// Distance sensor calibration (raw values)
#define FRONT_LEFT_OFFSET 0
#define FRONT_RIGHT_OFFSET 0

// Maximum distance sensor readings (in mm)
#define MAX_DISTANCE_READING 2000

#endif // CONFIG_H
