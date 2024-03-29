
#include <stdio.h>

void init_print();
int option_user();
int option_month();
int option_day();
int option_day_number();
int option_year();
int calc_num_year(int, int, int);
int day_week(int, int);
int find_month(int, int);
void display_results(int, int, int);
void display_results2(int, int, int, int);
void printCalendar(int, int);
int findDay(int, int, int);
int findDayW(int, int, int);
int findDayNumM(int, int, int);

int main()
{
  // Local Declarations
  int option; // the user input option choice
  int month; // user input month value
  int day; // user input day value
  int day2; // user input day value for option 2
  int year; // user input year value
  int day_num; // number of days in the year
  int day_word; // value of day of the week for option 2
  int dayNumM; //number of days in the month
  int dayW; // value of days of week for option 3
  //int dayNum;
  int day3; // total days in year before specified month 

  init_print();
  option = option_user();

  switch (option)
  {
    case 1: month = option_month();
            day = option_day();
            year = option_year();
            day_num = calc_num_year(month, day, year); // added numdaysM
            day_word = day_week(year, day_num);
            display_results(year, day_num, day_word);
            break;
    case 2:
            day2 = option_day_number();
            year = option_year();
            day_word = day_week(year, day2);
            month = find_month(year, day2);
            display_results2(month, day2, day_word, year);
            break;
    case 3: month = option_month();
            year = option_year();
            dayNumM = findDayNumM(month, year, option);
            day3 = findDay(month, year, option);
            dayW = findDayW(month, year, day3); 
            printCalendar(dayW, dayNumM); // these variables were weekday, startday, days
  }

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: init_print
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Displays the initial print statements
*
***************************************************************************/

void init_print()
{
  // Executable Statements
  printf("Calculator Tool\n");
  printf("\n1. Enter month, day, year to calculate day number.");
  printf("\n2. Enter day number and year to calculate month and day.");
  printf("\n3. Display the calendar for a given month.\n");

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: option_user
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Takes the user input of option
*
***************************************************************************/

int option_user()
{
  // Local Declarations
  int user_option; // user input option choice

  // Executable Statements
  printf("\nEnter desired option -> ");
  scanf("%d", &user_option);

  return(user_option);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: option_month
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Takes the user input of month
*
***************************************************************************/

int option_month()
{
	// Local Declarations
  int user_month; // user input month value
  
  // Executable Statements
  printf("Enter month -> ");
  scanf("%d", &user_month);

  return(user_month);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: option_day
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Takes the user input of day
*
***************************************************************************/

int option_day()
{
  // Local declarations
  int user_day; // user input day value
  // Executable Statements
  printf("Enter day -> ");
  scanf("%d", &user_day);

  return(user_day);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: option_day_number
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Takes the user input of day for option two
*
***************************************************************************/

int option_day_number()
{
	// local declarations
  int user_day2; // user input day value for option 2
  
  // Executable Statements
  printf("Enter day number -> ");
  scanf("%d", &user_day2);

  return(user_day2);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: option_year
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. None
*
*  Function Description: Takes the user input of year
*
***************************************************************************/

int option_year()
{
	// local declarations
  int user_year; // user input year value
  
  // Executable Statements
  printf("Enter year -> ");
  scanf("%d", &user_year);

  return(user_year);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calc_num_year
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. month //User input of month
*    2. day //User input of day
*    3. year, user input year
*
*  Function Description: Takes the inputs and calculates the day number within the year.
*
***************************************************************************/

int calc_num_year(int month, int day, int year)
{
	// local declarations
  int daycount; //Variable for counting the day number within year

  //Selection & Executables
  switch (month)
  {
    case 1: daycount = day;
           break;
    case 2: daycount = day + 31;
           break;
    case 3: daycount = day + 59;
           break;
    case 4: daycount = day + 90;
           break;
    case 5: daycount = day + 120;
           break;
    case 6: daycount = day + 151;
           break;
    case 7: daycount = day + 181;
           break;
    case 8: daycount = day + 212;
           break;
    case 9: daycount = day + 243;
           break;
    case 10: daycount = day + 273;
            break;
    case 11: daycount = day + 304;
            break;
    case 12: daycount = day + 334;
            break;
  }

  return(daycount); //Return total count to main function
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: day_week
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. year //User input of year
*    2. day_num //Calculated day number from previous function
*
*  Function Description:
*
***************************************************************************/

int day_week(int year, int day_num)
{
  //Local Declarations
  int yearDiff; //Setting the base to 2019, find the year difference value        
  int dayFind; //Find the day as a count from 0 to 6

  //Executables
  yearDiff = year - 2019; //Find the difference of input year from 2019
  dayFind = (day_num % 7 + 7 + yearDiff) % 7;                       

  return(dayFind); //Returns the number to main function for final print
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: find_month
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. year
*    2. day2
*
*  Function Description: Uses inputs to find the wanted month including the variation of leap year
*
***************************************************************************/

int find_month(int year, int day2)
{
	// local declarations
  int month_find; // month of year
  
  // Executable Statements
  if ((year % 4 == 0 && day2 >= 60) == 1) //Calculation to find leap year
  {
    day2 = day2 - 1; //If there is a leap year add 1 day after 2/28
  }

  if (day2 >= 0 && day2 <= 31)
  {
    month_find = 1;
  }
  else if ((day2 - 31) >= 0 && (day2 - 31) <= 28)
  {
    month_find = 2;
  }
  else if ((day2 - 59) >= 0 && (day2 - 59) <= 31)
  {
    month_find = 3;
  }
  else if ((day2 - 90) >= 0 && (day2 - 90) <= 30)
  {
    month_find = 4;
  }
  else if ((day2 - 120) >= 0 && (day2 - 120) <= 31)
  {
    month_find = 5;
  }
  else if ((day2 - 151) >= 0 && (day2 - 151) <= 30)
  {
    month_find = 6;
  }
  else if ((day2 - 181) >= 0 && (day2 - 181) <= 31)
  {
    month_find = 7;
  }
  else if ((day2 - 212) >= 0 && (day2 - 212) <= 31)
  {
    month_find = 8;
  }
  else if ((day2 - 243) >= 0 && (day2 - 243) <= 30)
  {
    month_find = 9;
  }
  else if ((day2 - 273) >= 0 && (day2 - 273) <= 31)
  {
    month_find = 10;
  }
  else if ((day2 - 304) >= 0 && (day2 - 304) <= 30)
  {
    month_find = 11;
  }
  else if ((day2 - 334) >= 0 && (day2 - 334) <= 31)
  {
    month_find = 12;
  }
  
  return(month_find);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: display_results2
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. month
*    2. day
*    3. day_word
*    4. year
*
*  Function Description: Takes previous calculations to display the wanted date and the day of week
*
***************************************************************************/

void display_results2(int month, int day, int day_word, int year)
{
	// Executable Statements
  switch (month)
  { 
    case 1: printf("\nDate: January ");
    case 2: day = day - 31;
            printf("\nDate: February ");
           break;
    case 3: day = day - 59;
            printf("\nDate: March ");
           break;
    case 4: day = day - 90;
            printf("\nDate: April ");
           break;
    case 5: day = day - 120;
            printf("\nDate: May ");
           break;
    case 6: day = day - 151;
            printf("\nDate: June ");
           break;
    case 7: day = day - 181;
            printf("\nDate: July ");
           break;
    case 8: day = day - 212;
            printf("\nDate: August ");
           break;
    case 9: day = day - 243;
            printf("\nDate: September ");
           break;
    case 10: day = day - 273;
             printf("\nDate: Decemeber ");
            break;
    case 11: day = day - 304;
             printf("\nDate: Novemeber ");
            break;
    case 12: day = day - 334;
             printf("\nDate: December ");
            break;
  }

  if (((month != 1) &&  (month != 2) && ((year % 4) == 0)) == 1)
  {
    day = day - 1;
  }

  switch(day)
  {
    case 1: printf("%dst", day);
            break;
    case 2: printf("%dnd", day);
            break;
    case 3: printf("%drd", day);
            break;
    case 11: printf("%dth", day);
             break;
    case 12: printf("%dth", day);
             break;
    case 13: printf("%dth", day);
             break;
    case 21: printf("%dst", day);
             break;
    case 22: printf("%dnd", day);
             break;
    case 23: printf("%drd", day);
             break;
    case 31: printf("%dst", day);
             break;
    default: printf("%dth", day);
             break;
  } 

  if (day_word == 1) //Value of 1 equals Tuesday
  {
    printf("\nDay of week: Tuesday\n");
  }
  else if (day_word == 2) //Value of 2 equals Wednesday
  {
    printf("\nDay of week: Wednesday\n");
  }
  else if (day_word == 3) //Value of 3 equals Thursday
  { 
    printf("\nDay of week: Thursday\n");
  }
  else if (day_word == 4) //Value of 4 equals Friday
  {  
    printf("\nDay of week: Friday\n");
  }
  else if (day_word == 5) //Value of 5 equals Saturday
  {  
    printf("\nDay of week: Saturday\n");
  }
  else if (day_word == 6) //Value of 6 equals Sunday
  {  
    printf("\nDay of week: Sunday\n");
  }
  else if (day_word == 0) //Value of 0 equals Monday
  { 
    printf("\nDay of week: Monday\n");
  }  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: display_results
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. year
*    2. day_num
*    3. day_word
*
*  Function Description: Takes the inputs to display the day number of year and the day of week.
*
***************************************************************************/

void display_results(int year, int day_num, int day_word)
{
  //Local Declarations
  //Executables

  //Leap Year Selection
  if ((year % 4 == 0 && day_num > 60) == 1) //Calculation to find leap year
  {
    day_num = day_num + 1; //If there is a leap year add 1 day after 2/28
    day_word = (day_word + 1) % 7; //In case additional day is not between 0 to 6.
  }

  //Selection for Day Number of Year and format of print
  if (day_num % 100 >= 10 && day_num % 100 <= 20) //Specific selection for 10~20th
  {
    printf("\nDay number of year: %dth\n", day_num);
  }
  else if (day_num % 10 == 1) //Selection for 1st
  {
    printf("\nDay number of year: %dst\n", day_num);
  }
  else if (day_num % 10 == 2) //Selection for 2nd
  {
    printf("\nDay number of year: %dnd\n", day_num);
  }
  else if (day_num % 10 == 3) //Selection for 3rd
  {
    printf("\nDay number of year: %drd\n", day_num);
  }
  else //Else prints **th for value
  {
    printf("\nDay number of year: %dth\n", day_num);
  }

  //Selection for Day of Week set in base 2019
  if (day_word == 1) //Value of 1 equals Tuesday
  {
    printf("Day of week: Tuesday\n");
  }
  else if (day_word == 2) //Value of 2 equals Wednesday
  {
    printf("Day of week: Wednesday\n");
  }
  else if (day_word == 3) //Value of 3 equals Thursday
  { 
    printf("Day of week: Thursday\n");
  }
  else if (day_word == 4) //Value of 4 equals Friday
  {  
    printf("Day of week: Friday\n");
  }
  else if (day_word == 5) //Value of 5 equals Saturday
  {  
    printf("Day of week: Saturday\n");
  }
  else if (day_word == 6) //Value of 6 equals Sunday
  {  
    printf("Day of week: Sunday\n");
  }
  else if (day_word == 0) //Value of 0 equals Monday
  { 
    printf("Day of week: Monday\n");
  }

  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printCalendar
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, startDay, the day of the week the desired month starts on
*    2. int days, the number of days in the month
*    3.
*
*  Function Description: prints final output to user
*
***************************************************************************/

void printCalendar(int startDay, int days) //dayCount = dayword
{
  // Local Declarations
  int dayCount; // current day of month in iteration
  int weekNum = 1; // the number week (for left side)
  int weekDay = 0; // current day of the week
  
  // Executable Statements
  switch(startDay) // was weekday
  {
    case 6: startDay = 0; // resets week to start at sunday (sunday = 0)
             break;
    default: startDay++;
             break;
  }

  printf("\nHeader:  S  M  T  W  R  F  S\n");
   //

  printf("Week 1:");
  for(weekDay = 0; weekDay < startDay; weekDay++)
  {
    printf("   "); // three spaces for empty day
  }

  for(dayCount = 1; dayCount <= days; dayCount++) // repl dayCount w/ weekDay? p.331, daycount > days
  {
    if(weekDay > 6) 
    {
      weekNum++;
      printf("\nWeek %d:", weekNum);
      weekDay = 1; // 0
    }
    else
    { 
      weekDay++;
    }
    printf("%3d", dayCount);
  }

  printf("\n\n");
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: findDay
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int, month, the month value, as input by the user
 *    2. int, day, day of the week of the specified date
 *    3. int, year, the year of the given date
 *
 *  Function Description: This function calculates the number of days in the year before the specified month given by the user
 *
 ***************************************************************************/

int findDay(int month, int year, int pick)
{
  // Local Declarations
  int dayNum = 0; // the number of days in the year before the specified month

  // Executable Statements
  switch(month)
  {
    case 12:  dayNum += 30; // if the month is december, add the number of days in the month before (november), as well as all previous months
    case 11:  dayNum += 31;
    case 10:  dayNum += 30;
    case 9:   dayNum += 31;
    case 8:   dayNum += 31;
    case 7:   dayNum += 30;
    case 6:   dayNum += 31;
    case 5:   dayNum += 30;
    case 4:   dayNum += 31;
    case 3:   dayNum += 28;
              if ((!(year % 4) && (year % 100)) || !(year % 400)) // formula provided on p. 300 of the programming text
              {
                dayNum++;
              }
              break;
    case 2:   dayNum += 31;
              break;
  }
  
  return(dayNum);
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: findDayW
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int, day, day of the week of the specified date
 *    2. int, month, the month value, as input by the user 
 *    3. int, year, the year of the given date
 *    4. int, dayNum, the number of days in the year before the user specified month
 *
 *  Function Description: This function calculates the (number value of the) day of the week of the specified date
 *
 ***************************************************************************/

int findDayW(int month, int year, int dayNum)
{
  // Local Declarations
  int maxDay; // day of the week for december 31st of the previous year
  int dayW; // the day of the week

  // Executable Statements
  maxDay = ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
  dayW = ((dayNum + maxDay) % 7);

  return(dayW);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findDayNumM
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, month, the user input month
*    2. int, year, user input year
*    3. int, pick, user option choice
*
*  Function Description: this function calculates the number of days in a month
*
***************************************************************************/

int findDayNumM(int month, int year, int pick)
{
  // Local Declarations
  int dayNumM; // number of days per month

  // Executable Statements
  switch(month)
  {
    case 12:  dayNumM = 31;
              break;
    case 11:  dayNumM = 30;
               break;
    case 10:  dayNumM = 31;
               break;
    case 9:  dayNumM = 30;
               break;
    case 8:   dayNumM = 31;
               break;
    case 7:   dayNumM = 31;
               break;
    case 6:   dayNumM = 30;
               break;
    case 5:   dayNumM = 31;
               break;
    case 4:   dayNumM = 30;
               break;
    case 3:   dayNumM = 31;
               break;
    case 2:   dayNumM = 28;
              if ((!(year % 4) && (year % 100)) || !(year % 400)) // formula provided on p. 300 of the programming text
              {
                dayNumM++;
              }
              break;
    case 1:   dayNumM = 31;
              break;
  }
  return(dayNumM);
}
