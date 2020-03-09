/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Emerald                                                   */
/*    Created:      Mon Nov 18 2019                                           */
/*    Description:  3815 Josh                                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

int main() {
vexcodeInit();

brain Brain;
motor LeftFMotor(PORT1, gearSetting::ratio18_1, false);
motor RightFMotor(PORT2, gearSetting::ratio18_1, true);
motor LeftBMotor(PORT7, gearSetting::ratio18_1, false);
motor RightBMotor(PORT8, gearSetting::ratio18_1, true);

motor ArmMotorL(PORT3, gearSetting::ratio18_1, true);
motor Stacker(PORT4, gearSetting::ratio18_1, true);
motor IntakeL(PORT5, gearSetting::ratio18_1, true);
motor IntakeR(PORT6, gearSetting::ratio18_1,true);
ArmMotorL.setStopping(hold);
IntakeR.setVelocity(100,pct);
IntakeL.setVelocity(100,pct);
controller Controller1 = controller();

 while (true) {

      //LeftFMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct); 
      //RightFMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);
      LeftFMotor.spin(directionType::fwd,Controller1.Axis3.value(),velocityUnits::pct);
      LeftBMotor.spin(directionType::fwd,Controller1.Axis3.value(),velocityUnits::pct);
      RightFMotor.spin(directionType::fwd,Controller1.Axis2.value(),velocityUnits::pct);
      RightBMotor.spin(directionType::fwd,Controller1.Axis2.value(),velocityUnits::pct);
      //ArmMotorR.setVelocity(200,pct);
      ArmMotorL.setVelocity(100,pct);


/// Arm
    if (Controller1.ButtonUp.pressing()) {
      ArmMotorL.spin(forward);
    }
    else if (Controller1.ButtonDown.pressing()) {
      ArmMotorL.spin(reverse);
    }   
    else{
      ArmMotorL.stop();
    }

/// Stacker
    if (Controller1.ButtonX.pressing()){
      Stacker.spin(forward);
    }
    else if(Controller1.ButtonB.pressing()){
      Stacker.spin(reverse);
    }
    else{
      Stacker.stop();
    }

///  Intake
    if(Controller1.ButtonL2.pressing()){
      IntakeR.spin(forward);
      IntakeL.spin(forward);
    }
    else if(Controller1.ButtonL1.pressing()){
      IntakeR.spin(reverse);
      IntakeL.spin(reverse);
    }
    else{
      IntakeL.stop();
      IntakeR.stop();
    }

/// Horizontal Movement
    if(Controller1.ButtonY.pressing()){
      LeftFMotor.spin(directionType::fwd,50,velocityUnits::pct);
      LeftBMotor.spin(directionType::rev,50,velocityUnits::pct);
      RightFMotor.spin(directionType::rev,50,velocityUnits::pct);
      RightBMotor.spin(directionType::fwd,50,velocityUnits::pct);
    }
    else if(Controller1.ButtonA.pressing()){
      LeftFMotor.spin(directionType::rev,50,velocityUnits::pct);
      LeftBMotor.spin(directionType::fwd,50,velocityUnits::pct);
      RightFMotor.spin(directionType::fwd,50,velocityUnits::pct);
      RightBMotor.spin(directionType::rev,50,velocityUnits::pct);
    }
    
    }
        task::sleep(20);
    } 

