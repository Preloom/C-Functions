
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//global declarations
void initPrint(void);
int getSelect(void);
double inputMass(int);
double inputVel(int);
double inputFinVel(int);
double calc(double, double, double, double, double, double, int, double, double*, double*);
void printOut(double, double, double, double, double, double);

int main(void)
{
  //local declarations
  int pick; // variable accepting user selection
  double mass1;
  double mass2;
  double vel1;
  double vel2;
  double finVel_1;
  double finVel_2;
  double missingVar = 0; // variable accepting the missing variable for all cases
  double* missingVar1 = 0; // pointer variable used to handle variables through the calc function
  double* missingVar2 = 0; // pointer variable used to handle variables through the calc function
  //executable statements

  initPrint();
  pick = getSelect();
  printf("\n"); // necessary to get correct spacing in output

  switch(pick)
  {
    case 1: mass1 = 0;
            mass2 = inputMass(2);     //missing: mass 1
            vel1 = inputVel(1);
            vel2 = inputVel(2);
            finVel_1 = inputFinVel(1);
            finVel_2 = inputFinVel(2);
            mass1 = calc(mass1, mass2, vel1, vel2, finVel_1, finVel_2, pick, missingVar, missingVar1, missingVar2);
      break;
    case 2: mass2 = 0;
            mass1 = inputMass(1);     //missing: mass 2
            vel1 = inputVel(1);
            vel2 = inputVel(2);
            finVel_1 = inputFinVel(1);
            finVel_2 = inputFinVel(2);
            mass2 = calc(mass1, mass2, vel1, vel2, finVel_1, finVel_2, pick, missingVar, missingVar1, missingVar2);
      break;
    case 3: vel1 = 0;
            mass1 = inputMass(1);     //missing: vel 1
            mass2 = inputMass(2);
            vel2 = inputVel(2);
            finVel_1 = inputFinVel(1);
            finVel_2 = inputFinVel(2);
            vel1 =  calc(mass1, mass2, vel1, vel2, finVel_1, finVel_2, pick, missingVar, missingVar1, missingVar2);
      break;
    case 4: vel2 = 0;
            mass1 = inputMass(1);     //missing: vel 2
            mass2 = inputMass(2);
            vel1 = inputVel(1);
            finVel_1 = inputFinVel(1);
            finVel_2 = inputFinVel(2);
            vel2 =  calc(mass1, mass2, vel1, vel2, finVel_1, finVel_2, pick, missingVar, missingVar1, missingVar2);
      break;
    case 5: mass1 = inputMass(1);     //missing: final velocities (both)
            mass2 = inputMass(2);
            vel1 = inputVel(1);
            vel2 = inputVel(2);
            finVel_1 = (-1) * vel1;
            finVel_2 = (-1) * vel2;
      break;
  } //end switch structure
  
  printOut(mass1, mass2, vel1, vel2, finVel_1, finVel_2);

  return(0);
} //end main function

void initPrint(void)
{
  //executable statements
  printf("\nMissing element options\n");
  printf("\n1. Mass of object #1");
  printf("\n2. Mass of object #2");
  printf("\n3. Initial velocity of object #1");
  printf("\n4. Initial velocity of object #2");
  printf("\n5. Final velocity of both objects\n");
  return;
}

int getSelect(void)
{
  //local declarations
  int input; //user input var
  //executable statements
  printf("\nEnter your selection -> ");
  scanf("%d", &input);
  
  return(input);
} //end getSelect


double inputMass(int num)
{
  //local declarations
  double mass; //user input mass
  //executable statements
  printf("Enter mass #%d -> ", num);
  scanf("%lf", &mass);

  return(mass);
}

double inputVel(int num)

{
  //local declarations
  double velocity; //user input velocity
  //executable statements
  printf("Enter initial velocity #%d -> ", num);
  scanf("%lf", &velocity);

  return(velocity);
}

double inputFinVel(int num)
{
  //local variables
  double finVel; //usr input final velocity
  
  //executable statements
  printf("Enter final velocity #%d -> ", num);
  scanf("%lf", &finVel);

  return(finVel);
}

double calc(double mass1, double mass2, double vel1, double vel2, double finVel_1, double finVel_2, int pick, double missingVar, double* missingVar1, double* missingVar2)
{

  //executable statements
  switch(pick)
  {
    case 1: missingVar = (mass2 * (finVel_2 - vel2)) / (vel1 - finVel_1);
           break;
    case 2: missingVar = (mass1 * (finVel_1 - vel1)) / (vel2 - finVel_2);
           break;
    case 3: missingVar = ((((mass1 * finVel_1) + (mass2 * finVel_2)) - (mass2 * vel2)) / mass1);
           break;
    case 4: missingVar = ((((mass1 * finVel_1) + (mass2 * finVel_2)) - (mass1 * vel1)) / mass2);
           break;
    case 5: *missingVar1 = (-1) * vel1;
            *missingVar2 = (-1) * vel2;;
           break;
  }
  
  return(missingVar);
}

void printOut(double m1, double m2, double v1, double v2, double finV1, double finV2)
{
  //executable statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nMass Object #1: %14.1lf (g)", m1);
  printf("\nMass Object #2: %14.1lf (g)", m2);
  printf("\nVelocity Object #1: %7.1lf (cm/s)", v1);
  printf("\nVelocity Object #2: %7.1lf (cm/s)", v2);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nFinal Velocity of Object #1: %8.1lf (cm/s)", finV1);
  printf("\nFinal Velocity of Object #2: %8.1lf (cm/s)\n\n", finV2);

  return;
}

