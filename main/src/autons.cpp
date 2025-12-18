#include "autons.h"

/**
 * \file autons.cpp
 *
 * Autonomous mode implementation
 */

constexpr float WALL_COORD = 71;

constexpr float MATCHLOAD_ENTER_SPEED = 80;
constexpr uint32_t MATCHLOAD_DURATION = 2000;

constexpr float LONG_GOAL_ENTER_SPEED = 60;
constexpr uint32_t LONG_GOAL_DURATION = 2000;

constexpr float LONG_GOAL_CROSS_MIN_SPEED = 80;
constexpr int LONG_GOAL_DIST_ALIGN = 435;

constexpr uint32_t WALL_FLUSH_TIME = 400;
constexpr float WALL_FLUSH_Y = 61.8;

void long_goals(const bool first)
{

#define pn (first?1:-1)
#define aj(a, b) (first?a:b)
    // move to matchloader 1
    chassis.moveToPose(pn* -47.5 +aj(0, 0), pn* 47 +aj(0, 0), -90, 2000, {}, false);
    match_load_reset(100, 0, aj(2,4));
    set_matchloader(true);
    // enter matchloader 1
    chassis.moveToPoint(pn* -61, pn* 47, 800, {.minSpeed = MATCHLOAD_ENTER_SPEED}, false);
    // finish matchloading
    pros::delay(MATCHLOAD_DURATION);

    // cross to other side
    chassis.moveToPoint(pn* -23, pn* 60, 1000, {.forwards = false, .minSpeed = LONG_GOAL_CROSS_MIN_SPEED, .earlyExitRange = 4}, false);
    chassis.moveToPoint(pn* 30, pn* 61, 1500, {.forwards = false}, false);
    set_matchloader(false);
    // flush with wall
    chassis.turnToHeading(aj(0, 180), 600);
    chassis.arcade(90, 0);
    pros::delay(WALL_FLUSH_TIME);
    const float side_distance = static_cast<float>(find_dist(right_dist, right_dist_offset, 0, Dir::Right, 100));
    chassis.setPose(pn* (WALL_COORD - side_distance), pn* WALL_FLUSH_Y, aj(0, 180));

    // move to long goal
    chassis.moveToPoint(chassis.getPose().x, pn* 47, 800, {.forwards = false}, false);
    chassis.turnToHeading(aj(90, -90), 600, {}, false);
    chassis.moveToPoint(pn* 0, pn* 47, 300, {.forwards = false, .minSpeed = LONG_GOAL_ENTER_SPEED}, false);
    // scoring
    intake_set_state(SCORE_HIGH);
    chassis.arcade(-LONG_GOAL_ENTER_SPEED, 0);
    pros::delay(LONG_GOAL_DURATION);

    // reset pose at long goal
    chassis.setPose(pn* 30, pn* 47, aj(90, -90));

    // enter matchloader 2
    intake_set_state(INTAKE);
    set_matchloader(true);
    chassis.moveToPoint(pn* 61, pn* 47, 800, {.minSpeed = MATCHLOAD_ENTER_SPEED}, false);
    chassis.arcade(-MATCHLOAD_ENTER_SPEED, 0);
    // finish matchloading while running reset
    match_load_reset(MATCHLOAD_DURATION, 0, aj(1, 3));

    // move to long goal
    chassis.moveToPoint(pn* 0, pn* 47, 1500, {.forwards = false, .minSpeed = LONG_GOAL_ENTER_SPEED}, true);
    pros::delay(700);
    // scoring
    intake_set_state(SCORE_HIGH);
    chassis.arcade(-LONG_GOAL_ENTER_SPEED, 0);
    pros::delay(LONG_GOAL_DURATION);

    // reset pose at long goal
    chassis.setPose(pn* 30, pn* 47, aj(90, -90));
}

void skills() {
    // for coordinates and heading, they are in the format of `[target] +[adjustment] +[tuning]`
    // target is the point of interest, adjustment is the number added during routing, and tuning is to adjust when tuning.

    chassis.setPose(-47, 14.5, 90);

    set_wing(true);

    // 1. score matchload +1 in mid goal

    // collect 4 stack
    intake_set_state(INTAKE);
    chassis.moveToPoint(-23.5 +4 , 23.5 +4, 1000, {}, false);

    // position to mid goal
    chassis.swingToHeading(-45, DriveSide::RIGHT, 600, {}, false);
    chassis.moveToPoint(-14 +0, 14 +0, 1000, {.forwards = false}, true);
    // begin scoring early
    pros::delay(500);
    intake_set_state(SCORE_MID);
    chassis.waitUntilDone();
    // finish scoring
    pros::delay(800);

    // reset pose at mid goal
    chassis.setPose(-14, 14, chassis.getPose().theta);

    // 2. long goal 1

    long_goals(true);

    // 3. mid goal

    // position to park zone
    intake_set_state(IDLE);
    chassis.moveToPose(63.5, 24, 170, 1500, {.horizontalDrift = 8, .minSpeed = 60, .earlyExitRange = 2}, false);
    chassis.arcade(60, 0);
    pros::delay(1000);

    // enter park zone
    intake_set_state(INTAKE);
    // sharp to initially enter
    chassis.arcade(90, 0);
    pros::delay(300);
    // slow cross
    chassis.arcade(60, 0);
    pros::delay(1000);
    // correct heading
    chassis.turnToHeading(180, 600, {}, false);
    // back up
    chassis.arcade(-60, 0);
    pros::delay(800);
    chassis.arcade(0, 0);

    // reset pose
    const float side_distance = find_dist(left_dist, left_dist_offset, M_PI, Dir::Left, 100);
    chassis.setPose(WALL_COORD - side_distance, -17.5, chassis.getPose().theta);

    // collect one from four stack
    chassis.turnToPoint(25.25, -22, 800, {}, false);
    chassis.moveToPoint(25.25 -3, -22 -1, 1000, {}, false);

    // move to mid goal
    chassis.turnToHeading(135, 600, {}, false);
    chassis.moveToPoint(14, -14, 800, {.forwards = false, .minSpeed = 32, .earlyExitRange = 2}, false);
    chassis.arcade(-32, 0);
    pros::delay(600);

    // score
    score_7_mid();

    // 4. long goal 2

    long_goals(false);

    // 5. park

    // position to park zone
    intake_set_state(IDLE);
    chassis.moveToPose(-63.5, -24, -80, 1500, {.horizontalDrift = 8, .minSpeed = 60, .earlyExitRange = 2}, false);
    chassis.arcade(60, 0);
    pros::delay(1000);

    // enter park zone
    intake_set_state(IDLE);
    // sharp to initially enter
    chassis.arcade(90, 0);
    pros::delay(300);
    // slow cross
    chassis.arcade(60, 0);
    pros::delay(700);
}