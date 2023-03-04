#include "vex.h"
#include "drive.h"
#include "control.h"
using namespace vex;

void auton() {
    Brain.Screen.print("auton started");
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);
    RightDrive.spin(directionType::fwd);
    LeftDrive.spin(directionType::fwd);
    Roller.setVelocity(100, velocityUnits::pct);
    Roller.spinFor(90, rotationUnits::deg);
    Roller.setVelocity(0, velocityUnits::pct);
    Roller.stop();
    RightDrive.setVelocity(0, velocityUnits::pct);
    LeftDrive.setVelocity(0, velocityUnits::pct);
    RightDrive.stop();
    LeftDrive.stop();
    // backwardInches(8);
    // turnDegrees(135);
    // forwardInches(76);
    // turnDegrees(270);
    // backwardInches(5);
    // // shoot 75 inches
    // highGoal();
    // wait(5000, msec);
    // highGoal();
}