#include "vex.h"
using namespace vex;

extern controller Controller;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Storage;
extern motor Flywheel1;
extern motor Flywheel2;
extern motor Roller;

void roller() {
    if (Roller.isSpinning()) {
        Roller.setVelocity(0, velocityUnits::pct);
        Roller.stop();
    } else {
        Roller.setVelocity(50, velocityUnits::pct);
        Roller.spin(fwd);
    }
}

void setupRoller(controller::button Button) {
    Roller.setVelocity(0, velocityUnits::pct);
    Roller.stop();
    Button.pressed(roller);
}

void intake() {
    if (Storage.isSpinning()) {
        Storage.setVelocity(0, velocityUnits::pct);
        Storage.stop();
    } else {
        if (Controller.ButtonDown.pressing()) {
            Storage.setVelocity(75, velocityUnits::pct);
            Storage.spin(directionType::rev);
        } else {
            Storage.setVelocity(75, velocityUnits::pct);
            Storage.spin(fwd);
        }
    }
}

void setupIntake(controller::button Button) {
    Storage.setVelocity(0, velocityUnits::pct);
    Storage.stop();
    Button.pressed(intake);
}

void flywheel() {
    if (Flywheel1.isSpinning()) {
        Flywheel1.setVelocity(0, velocityUnits::pct);
        Flywheel2.setVelocity(0, velocityUnits::pct);
        Storage.setVelocity(0, velocityUnits::pct);
        Flywheel1.stop();
        Flywheel2.stop();
        Storage.stop();
    } else {
        Flywheel1.setVelocity(100, velocityUnits::pct);
        Flywheel2.setVelocity(100, velocityUnits::pct);
        Storage.setVelocity(75, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        Storage.spin(directionType::fwd);
    }
}

void setupFlywheel(controller::button Button) {
    Flywheel1.setVelocity(0, velocityUnits::pct);
    Flywheel2.setVelocity(0, velocityUnits::pct);
    Storage.setVelocity(0, velocityUnits::pct);
    Flywheel1.stop();
    Flywheel2.stop();
    Storage.stop();
    Button.pressed(flywheel);
}
