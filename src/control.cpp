#include "vex.h"
using namespace vex;

extern controller Controller;
extern motor RightDrive;
extern motor LeftDrive;
extern motor Storage;

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
