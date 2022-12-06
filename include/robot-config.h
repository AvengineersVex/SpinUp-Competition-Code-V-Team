using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftDrive;
extern motor RightDrive;
extern motor Storage;
extern motor Intake;

extern controller Controller;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);