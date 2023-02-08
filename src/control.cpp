#include "vex.h"
using namespace vex;

bool intakeSpinning = false;
bool flywheelSpinning = false;
bool rollerSpinning = false;
bool expansionSpinning = false;

void expansion() {
    if (expansionSpinning) {
        expansionSpinning = false;
        Expansion.setVelocity(0, velocityUnits::pct);
        Expansion.stop();
    } else {
        expansionSpinning = true;
        Expansion.setVelocity(100, velocityUnits::pct);
        Expansion.spin(directionType::rev);
    }
}

void setupExpansion(controller::button Button) {
    Expansion.setVelocity(0, velocityUnits::pct);
    Expansion.stop();
    Button.pressed(expansion);
}

void highGoal() {
    if (flywheelSpinning) {
        flywheelSpinning = false;
        Flywheel1.setVelocity(0, velocityUnits::pct);
        Flywheel2.setVelocity(0, velocityUnits::pct);
        Storage.setVelocity(0, velocityUnits::pct);
        Intake.setVelocity(0, velocityUnits::pct);
        Flywheel1.stop();
        Flywheel2.stop();
        Storage.stop();
        Intake.stop();
    } else {
        flywheelSpinning = true;
        Flywheel1.setVelocity(100, velocityUnits::pct);
        Flywheel2.setVelocity(100, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        wait(2500, msec);
        Storage.setVelocity(100, velocityUnits::pct);
        Intake.setVelocity(100, velocityUnits::pct);
        Storage.spin(directionType::rev);
        Intake.spin(directionType::rev);
    }
}

void lowGoal() {
    if (flywheelSpinning) {
        flywheelSpinning = false;
        Flywheel1.setVelocity(0, velocityUnits::pct);
        Flywheel2.setVelocity(0, velocityUnits::pct);
        Storage.setVelocity(0, velocityUnits::pct);
        Intake.setVelocity(0, velocityUnits::pct);
        Flywheel1.stop();
        Flywheel2.stop();
        Storage.stop();
        Intake.stop();
    } else {
        flywheelSpinning = true;
        Flywheel1.setVelocity(25, velocityUnits::pct);
        Flywheel2.setVelocity(25, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        wait(1500, msec);
        Storage.setVelocity(50, velocityUnits::pct);
        Intake.setVelocity(100, velocityUnits::pct);
        Storage.spin(directionType::rev);
        Intake.spin(directionType::rev);
    }
}

void roller() {
    if (rollerSpinning) {
        rollerSpinning = false;
        Roller.setVelocity(0, velocityUnits::pct);
        RightDrive.setVelocity(0, velocityUnits::pct);
        LeftDrive.setVelocity(0, velocityUnits::pct);
        Roller.stop();
        RightDrive.stop();
        LeftDrive.stop();
    } else {
        rollerSpinning = true;
        Roller.setVelocity(100, velocityUnits::pct);
        RightDrive.setVelocity(75, velocityUnits::pct);
        LeftDrive.setVelocity(75, velocityUnits::pct);
        Roller.spin(fwd);
        RightDrive.spin(fwd);
        LeftDrive.spin(fwd);
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
            Intake.setVelocity(100, velocityUnits::pct);
            Intake.spin(directionType::fwd);
        } else {
            Intake.setVelocity(100, velocityUnits::pct);
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
        Storage.setVelocity(100, velocityUnits::pct);
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
