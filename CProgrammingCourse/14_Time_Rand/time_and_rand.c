/*******************************************************
*                                                     *
* Author        : Sanjeet Prasad                      *
* Email         : sanjeet8.23@gmail.com               *
* Description   : Demonstrates the use of C time and  *
*                 randomness functions. Includes       *
*                 conversion of epoch time to local    *
*                 and UTC formats, extracting detailed *
*                 time components using `struct tm`,   *
*                 and generating random numbers with   *
*                 `rand()` and `srand()` for use cases *
*                 like OTP generation.                *
* Created On    : 12th June 2025                      *
* Compiler      : GCC 14.2.0                          *
* Standard      : C99                                 *
*                                                     *
*******************************************************/


#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(int argc ,char *argv[])
{
   
   //time_t time(time_t *timer); //time_t == long int 8 bytes,typedef long int  time_t ;
   
   time_t current_time = 0;//typedef long int  time_t
   //time_t *timer = NULL;
   
   current_time = time(NULL);//It will return the number of seconds from 1st jan 1970 ->epoch time 
   
   printf("Current time in seconds from 1st jan 1970 = %ld seconds\n",current_time);
   
   //convert this epoch time into local time IST 
   //char *ctime(const time_t *timer)
   char *clocal_time = ctime(&current_time);
   //char *localtime = ctime(&time(NULL));
   printf("Local time IST = %s \n",clocal_time);
   
   
   //struct tm *localtime = localtime(&currenttime) IST 
   struct tm *local_time = localtime(&current_time);
   
   printf("Year = %d\n",local_time->tm_year+1900);
   printf("Month = %d\n",local_time->tm_mon+1);
   printf("Day = %d\n",local_time->tm_mday);
   printf("Hour = %d\n",local_time->tm_hour);
   printf("Min = %d\n",local_time->tm_min);
   printf("Second = %d\n",local_time->tm_sec);
   
   //add time in seconds hour minutes etc 
   
   printf("IST/Local time %d-%02d-%02d  %02d:%02d:%02d\n",
   local_time->tm_year+1900,local_time->tm_mon+1,local_time->tm_mday,local_time->tm_hour,local_time->tm_min,local_time->tm_sec);
   
   //UTC time = 12 noon ,IST 5:30 pm  
   //UTC = GMT+5:30 ,GMT+1 ->this reference time for whole world 
   struct tm *utc_time = gmtime(&current_time);
   printf("GMT/UTC %d-%02d-%02d  %02d:%02d:%02d\n",
   utc_time->tm_year+1900,utc_time->tm_mon+1,utc_time->tm_mday,utc_time->tm_hour,utc_time->tm_min,utc_time->tm_sec);
   


  //rand()  stdlib.h
  int random = rand();//this is generate a ramdom number but it is not unique 
  
  printf("Generate ramdom number = %d\n",random); 
  printf("max ramdom number range = %d\n",RAND_MAX);

  //For getting unique ramdom number 
  srand(time(NULL)); //come together srand() --> rand()
  printf("use srand Generate ramdom number = %d\n",rand()); 
  
  int min = 1000, max = 5000;
  int random_number = (rand() % (max - min + 1)) + min;
  printf("Min 10000 to 50000 4 digit OTP = %d\n",random_number);
  
  return 0;
}
