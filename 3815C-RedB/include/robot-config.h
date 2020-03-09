using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftF;
extern motor LeftB;
extern motor RightF;
extern motor RightB;
extern motor ArmL;
extern motor Stacker;
extern motor IntakeL;
extern motor IntakeR;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );