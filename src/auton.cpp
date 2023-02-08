#include "vex.h"
#include "drive.h"
#include "control.h"
using namespace vex;

void auton() {
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);

    RightDrive.spin(directionType::fwd);
    LeftDrive.spin(directionType::fwd);
    Roller.setVelocity(100, velocityUnits::pct);
    Roller.spin(fwd);
    wait(100, msec);
    Roller.setVelocity(0, velocityUnits::pct);
    Roller.stop();
    backwardInches(8);
    turnDegrees(135);
    forwardInches(76);
    turnDegrees(90);
    forwardInches(5);
    // shoot 75 inches
    highGoal();
    wait(3000, msec);
    highGoal();
}