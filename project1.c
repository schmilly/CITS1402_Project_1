#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


// CITS2002 Project 1 2022
// Student1: 23086983 WILLIAM VAN DEN WALL BAKE
// Student2: 22902133 JIOW JOSHUA


// TOREMOVE == Marking lines for debugging
// TODO == Does this need to be explained?

// defining size of chrachter array for files
#define Filesize 10000
#define len 1000


// Yonked from FileIO lecture (very useful thanks)
void trim_line(char line[0])
{
    int i = 0;
//  LOOP UNTIL WE REACH THE END OF line
    while(line[i] != '\0') {
//        if( line[i] == ' ') { 
//    }
// TODO Remove spaces, would help but we simply do not have the time to run around with this stuff
// Might end up being easier to account for  them and leave them all in

//  CHECK FOR CARRIAGE-RETURN OR NEWLINE
        if( line[i] == '\r' || line[i] == '\n' ) {
            line[i] = '\0'; // overwrite with nul-byte
            break;          // leave the loop early
        }
        i = i+1;            // iterate through character array
    }
}
// use with if statment for if it's the string version, we'll relie on string
// version for this stuff I rekon



void monthcalc(char *month, int *monthNum, int *daysinmonth){
	if(month == "jan"){
				*monthNum = 1;}
	else if(month == "feb"){
				*monthNum = 2;}
	else if(month == "mar"){
				*monthNum = 3;}
	else if(month == "apr"){
				*monthNum = 4;}
	else if(month == "may"){
				*monthNum = 5;}
	else if(month == "jun"){
				*monthNum = 6;}
	else if(month == "jul"){
				*monthNum = 7;}
	else if(month == "aug"){
				*monthNum = 8;}
	else if(month == "sep"){
				*monthNum = 9;}
	else if(month == "oct"){
				*monthNum = 10;}
	else if(month ==  "nov"){
				*monthNum = 11;}
	else if(month == "dec"){
				*monthNum = 12;}	
	else{
		printf("Invalid month");
		}
	if(isdigit(month)==1){ //the Isdigit function evaluates to 1 or 0 (as opposed to true or false) so I fixed it for ya ;)
    *monthNum = atoi(month);
  }
	else{		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			daysinmonth = 31;
		}
		else if(month == 2){
			daysinmonth = 28;
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11){
			daysinmonth = 30;
		}
		else{
			printf("Invalid month");
		}
  }
}

void lineprocess(int Line, char *line,char *estcron){
  if (line[0]='#'){return;} //Line is a comment, so exit the function as no data can be parsed of use
  int dailyCount = 0;
  int weeklyCount = 0;
  int deepCount = 0;
  int submitCount = 0;
  int sendCount= 0;  
  int *monthNum=0;
  int *daysinmonth=0;
  char *month = "jan"; 

  monthcalc(month,monthNum,daysinmonth);
  //This stuff only useful after we process file.
  //the mains stuffs

  //I REPLACED all the data stuff 
  if (estcron == "cron"){
  //Process for getting parsing cron files
  for(int i = 0; i < Line; i++){
	  for(int j = 0; j < Line; j++){
		  if(line[0] == '*' || line[0] == monthNum){	
			  //daily count
			  if(line[0] == '*' && line[0] == '*'){
			  	dailyCount = 1440 * *daysinmonth;
			  }
			  else if(line[0] == '*' && line[0] != '*'){
			dailyCount = (24 - (line[1])-1) * 60 * *daysinmonth;
			}
			else if(line[0] != '*' && line[0] == '*'){
				dailyCount = 24 * *daysinmonth;
			}
			else if(line[0] != '*' && line[0] != '*'){
				dailyCount = (24 - (line[1])-1) * *daysinmonth;
			}
		  }
		  //weekly
		  if (line[0] == '*' || line[0] == monthNum){
		  }
		  //deepthought
		  if(line[0] == '*' || line[0]  == monthNum){
		  }
	  //submit-project
		  if(line[0] == '*' || line[0] == monthNum){
		  }
		  //send-monthly
		  if(line[0] == '*' || line[0] == monthNum){
			  sendCount = 1;
      }
  }}}
    //did a find and replace since were 
  else if (estcron == "est"){
      //Code for processing est verson
    }
}


//just did some file error and opening stuff. converted it into an array of string
void reading_file(char *filename, char *estcron) {
  // TODO
  printf("Reading file %s\n", filename);
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("cannot open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  printf("File sucesfully opened \n");
  // fseek(file, 0L, SEEK_END);
  // int sz = ftell(*file);
  // printf("file size is: %s\n",sz);
  // TODO Code doesn't work, fix later if time allows
  
  
  char Line[100];
  //File read loop
  while ( fgets(Line, sizeof Line, file)){
    trim_line( Line );
    int sizef = sizeof(Line);  
    lineprocess( sizef, Line, estcron );
  } 
//count use to find out the most used command

}
void argumentcheck(int argcount){
  if (argcount > 4){
    printf("Error, too many arguments\n");
    exit(EXIT_FAILURE);
  }
  else if (argcount < 4) {
    printf("Error, not enough arguments\n");
    exit(EXIT_FAILURE);
  }
}

//calculate the most called command
//just did ladder, required less lines
//most likely make it its own function

void error_check(char *filename) {
  // opening file of name passed via parameter of filename
  printf("Attempting to check %s actually exists\n", filename);
  int file = open(filename, O_RDONLY);
  if (file == -1) {
    printf("Cannot open %s\n", file);
    exit(EXIT_FAILURE);
  }
  printf("File Found!\n");
  //TODO fix this so it doesn't core dump or seg faults
  //every time it trys to read a file that doesn't exist
}

int main(int argcount, char *argvalue[]) {

  // checking to see we have the correct number of arguments (debuggin bs)
  printf("Spinning up program now!\n");
  
  //Converted to function for sake of it looking nicer
  argumentcheck(argcount);

  char *estfile = argvalue[3];
  char *month = argvalue[1];
  char *Crontab = argvalue[2];
// printf("Sucesfully assigned Terminal arguments; moving on...\n"); //toremove, user doesn't care

  //Error Checking of files
  error_check(Crontab);
  error_check(estfile);
  printf("All files exist; moving on....\n");
  //Reading files specifically

  reading_file(Crontab, "cron");
  reading_file(estfile, "est");
  return(0);
  exit(EXIT_SUCCESS); 
}





//printf(most frequent command executed, total num of commands invoked, maximum num of commands running);
