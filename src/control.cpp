#include "vex.h"
using namespace vex;

extern controller Controller;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Storage;
extern motor Flywheel1;
extern motor Flywheel2;
extern motor Roller;

bool intakeSpinning = false;
bool flywheelSpinning = false;
bool rollerSpinning = false;

void shoot() {
    Intake.setVelocity(75, velocityUnits::pct);
    Intake.spin(directionType::rev);
    wait(500, msec);
    Intake.setVelocity(0, velocityUnits::pct);
    Intake.stop();
}

void roller() {
    if (rollerSpinning) {
        rollerSpinning = false;
        Roller.setVelocity(0, velocityUnits::pct);
        Roller.stop();
    } else {
        rollerSpinning = true;
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
    if (intakeSpinning) {
        intakeSpinning = false;
        Intake.setVelocity(0, velocityUnits::pct);
        Intake.stop();
    } else {
        intakeSpinning = true;
        if (Controller.ButtonDown.pressing()) {
            Intake.setVelocity(75, velocityUnits::pct);
            Intake.spin(directionType::rev);
        } else {
            Intake.setVelocity(75, velocityUnits::pct);
            Intake.spin(directionType::rev);
        }
    }
}

void setupIntake(controller::button Button) {
    Intake.setVelocity(0, velocityUnits::pct);
    Intake.stop();
    Button.pressed(intake);
}

void flywheel() {
    if (flywheelSpinning) {
        flywheelSpinning = false;
        Flywheel1.setVelocity(0, velocityUnits::pct);
        Flywheel2.setVelocity(0, velocityUnits::pct);
        Storage.setVelocity(0, velocityUnits::pct);
        Flywheel1.stop();
        Flywheel2.stop();
        Storage.stop();
    } else {
        flywheelSpinning = true;
        Flywheel1.setVelocity(100, velocityUnits::pct);
        Flywheel2.setVelocity(100, velocityUnits::pct);
        Storage.setVelocity(75, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        Storage.spin(directionType::rev);
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
