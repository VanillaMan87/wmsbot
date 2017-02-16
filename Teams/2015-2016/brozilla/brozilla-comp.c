#pragma config(Motor,  port1,           dr,            tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           stl,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           sbl,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           str,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           sbr,           tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           intakefront,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           intakeback,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           m8,            tmotorNone, openLoop)
#pragma config(Motor,  port9,           m9,            tmotorNone, openLoop)
#pragma config(Motor,  port10,          dl,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)


//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)?
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


//////////////////////////////////////////////////////////
//
// FUNCTIONS
//


void shooterMotors(int speed) {
	motor[stl] = speed;
	motor[sbl] = speed;
	motor[str] = speed;
	motor[sbr] = speed;
}

void intakeMotors(int speed) {
	motor[intakefront] = speed;
	motor[intakeback] = speed;
}

// Required
void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	// .....................................................................................
	// Insert user code here.
	// .....................................................................................


}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	shooterMotors(0);
	intakeMotors(0);

	while (true)
	{


		int shooterSpeed = 127;

		// Used to filter out joystick abberations
		int threshold = 10;

		//////////////////////////////////////////////////////////
		//
		// DRIVE
		//
		// This code has filtering in place
		// Because the joystick returns a value that is not always
		// exactly zero.

		if(abs(vexRT[Ch3]) > threshold)
		{
			motor[dl]  = (vexRT[Ch3] );
		}
		else
		{
			motor[dl]  = 0;
		}

		if(abs(vexRT[Ch2]) > threshold)
		{
			motor[dr] = (vexRT[Ch2]);
		}
		else
		{
			motor[dr] = 0;
		}

		//////////////////////////////////////////////////////////
		//
		// SHOOTERS
		//

		if (vexRT[Btn6U] == 1) {
			shooterMotors(shooterSpeed);
			} else {
			shooterMotors(0);
		}

		//////////////////////////////////////////////////////////
		//
		// INTAKE MECHANISM
		//

		if (vexRT[Btn5U] == 1) {
			intakeMotors(127);
			} else {

			// If 5U isn't pressed
			// check for 5D which is
			// reverse. If neither, turn off.

			if (vexRT[Btn5D] == 1) {
				intakeMotors(-127);
				} else {

				// No buttons pressed? Stop motors
				intakeMotors(0);
			}
		}



	}
}