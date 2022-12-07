#include "vex.h"
using namespace vex;

extern controller Controller;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Storage;
extern motor Flywheel1;
extern motor Flywheel2;

void storage() {
    Storage.setVelocity(100, velocityUnits::pct);
    Storage.rotateTo(90, rotationUnits::deg);
    Storage.setVelocity(25, velocityUnits::pct);
    Storage.rotateTo(-90, rotationUnits::deg);
    Storage.setVelocity(0, velocityUnits::pct);
}

void setupStorage(controller::button Button) {
    Storage.setVelocity(0, velocityUnits::pct);
    Storage.stop();
    Button.pressed(storage);
}

void flywheel() {
    Flywheel1.setVelocity(100, velocityUnits::pct);
    Flywheel2.setVelocity(100, velocityUnits::pct);
    Flywheel1.spin(directionType::fwd);
    Flywheel2.spin(directionType::fwd);
    wait(10, timeUnits::sec);
    Flywheel1.setVelocity(0, velocityUnits::pct);
    Flywheel2.setVelocity(0, velocityUnits::pct);
}

void setupFlywheel(controller::button Button) {
    Flywheel1.setVelocity(0, velocityUnits::pct);
    Flywheel2.setVelocity(0, velocityUnits::pct);
    Flywheel1.stop();
    Flywheel2.stop();
    Button.pressed(flywheel);
}
