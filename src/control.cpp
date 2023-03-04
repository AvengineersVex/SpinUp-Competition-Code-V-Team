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
        if (Controller.ButtonY.pressing()) {
          expansionSpinning = true;
          Expansion.setVelocity(100, velocityUnits::pct);
          Expansion.spin(directionType::fwd);
          wait(1000, msec);
          expansionSpinning = false;
          Expansion.setVelocity(0, velocityUnits::pct);
          Expansion.stop();
        }
    }
}

void setupExpansion(controller::button Button) {
    Expansion.setVelocity(0, velocityUnits::pct);
    Expansion.stop();
    Button.pressed(expansion);
}

void shortHighGoal() {
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
        Storage.setVelocity(0, velocityUnits::pct);
        Intake.setVelocity(0, velocityUnits::pct);
        Storage.stop();
        Intake.stop();
        Flywheel1.setVelocity(55, velocityUnits::pct);
        Flywheel2.setVelocity(55, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        wait(2500, msec);
        Storage.setVelocity(100, velocityUnits::pct);
        Intake.setVelocity(100, velocityUnits::pct);
        Storage.spin(directionType::rev);
        Intake.spin(directionType::rev);
    }
}

void longHighGoal() {
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
        Storage.setVelocity(0, velocityUnits::pct);
        Intake.setVelocity(0, velocityUnits::pct);
        Storage.stop();
        Intake.stop();
        Flywheel1.setVelocity(65, velocityUnits::pct);
        Flywheel2.setVelocity(65, velocityUnits::pct);
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
        Flywheel1.setVelocity(10, velocityUnits::pct);
        Flywheel2.setVelocity(10, velocityUnits::pct);
        Flywheel1.spin(directionType::fwd);
        Flywheel2.spin(directionType::fwd);
        wait(500, msec);
        Storage.setVelocity(50, velocityUnits::pct);
        Intake.setVelocity(100, velocityUnits::pct);
        Storage.spin(directionType::rev);
        Intake.spin(directionType::rev);
    }
}

void roller() {
    if (intakeSpinning) {
        intakeSpinning = false;
        Intake.setVelocity(0, velocityUnits::pct);
        Intake.stop();
    } else {
        intakeSpinning = true;
        if (Controller.ButtonDown.pressing()) {
            Intake.setVelocity(50, velocityUnits::pct);
            Intake.spin(directionType::fwd);
        } else {
            Intake.setVelocity(50, velocityUnits::pct);
            Intake.spin(directionType::rev);
        }
    }
}

void setupRoller(controller::button Button) {
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
        Flywheel1.spin(directionType::fwd, 12.0, voltageUnits::volt);
        Flywheel2.spin(directionType::fwd, 12.0, voltageUnits::volt);
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
