#include "vex.h"
#include <cmath>
#include <math.h>
using namespace vex;
extern controller Controller;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Intake;
extern motor Storage;

int mainDrive() { // one joystick
    RightDrive.setVelocity(0, velocityUnits::pct);
    LeftDrive.setVelocity(0, velocityUnits::pct);
    Intake.setVelocity(0, velocityUnits::pct);
    Storage.setVelocity(0, velocityUnits::pct);
    RightDrive.spin(fwd);
    LeftDrive.spin(fwd);
    Intake.spin(directionType::rev);
    Storage.spin(directionType::rev);
    
    while (true) { // loop forever
        if ((abs(Controller.Axis3.value()) > 20 || abs(Controller.Axis4.value()) > 20) && Controller.ButtonDown.pressing()) { // reverse
            Intake.setVelocity(75, velocityUnits::pct);
            Intake.spin(directionType::fwd);
            Storage.setVelocity(75, velocityUnits::pct);
            Storage.spin(directionType::fwd);
        } else if ((abs(Controller.Axis3.value()) > 20 || abs(Controller.Axis4.value()) > 20)) { // regular direction
            Intake.setVelocity(75, velocityUnits::pct);
            Intake.spin(directionType::rev);
            Storage.setVelocity(75, velocityUnits::pct);
            Storage.spin(directionType::rev);
        } else { // not moving
            Intake.setVelocity(0, velocityUnits::pct);
            Storage.setVelocity(0, velocityUnits::pct);
        }

        if (abs(Controller.Axis3.value()) < 20) { // rotating on the spot
            RightDrive.setVelocity(-Controller.Axis4.position(), velocityUnits::pct); // right motor is negated because it needs to go in the opposite direction to turn on the spot
            LeftDrive.setVelocity(Controller.Axis4.position(), velocityUnits::pct);
        }
        else { // moving forward or back
            RightDrive.setVelocity(Controller.Axis3.position(), velocityUnits::pct); // left and right motor go in the same direction
            LeftDrive.setVelocity(Controller.Axis3.position(), velocityUnits::pct); 
        }
        wait(20, msec); // some delay to prevent wasted resources
    }
    return 0;
}

// drive controls:

double inchesToDegrees(double inches) {
    return
     (inches / (4 * 3.14)) * 360;
}

void goForward() {
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);
    RightDrive.spin(directionType::fwd);
    LeftDrive.spin(directionType::rev);
}

void goBackward() {
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);
    RightDrive.spin(directionType::rev);
    LeftDrive.spin(directionType::fwd);
}

void turnLeft() {
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);
    RightDrive.spin(directionType::fwd);
    LeftDrive.spin(directionType::fwd);
}

void turnRight() {
    RightDrive.setVelocity(100, velocityUnits::pct);
    LeftDrive.setVelocity(100, velocityUnits::pct);
    RightDrive.spin(directionType::rev);
    LeftDrive.spin(directionType::rev);
}

void stop() {
    LeftDrive.stop();
    RightDrive.stop();
}

void forwardInches(double inches) {
    LeftDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
    RightDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
}

void backwardInches(double inches) {
    LeftDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
    RightDrive.rotateFor(inchesToDegrees(inches), rotationUnits::deg, true);
}

void turnDegrees(double deg) {
    const double width = 15.25;
    const double length = 11.1;
    const double circum = 12.5663706144;
    double r = sqrt(pow(width, 2) + pow(length, 2)); // radius of the circle
    double a = (deg * M_PI * r / 180) * (60) * (1 / circum);    // exact rpm to move in degrees/180 seconds
    LeftDrive.setVelocity((a), velocityUnits::rpm);
    RightDrive.setVelocity((-a), velocityUnits::rpm);
    RightDrive.spin(directionType::fwd);
    LeftDrive.spin(directionType::fwd);
    wait((deg/180), sec);
    RightDrive.setVelocity(0, velocityUnits::rpm);
    LeftDrive.setVelocity(0, velocityUnits::rpm);
}