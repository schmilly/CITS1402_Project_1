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

//Initalise of process 
struct {
  char *processname;
  int monthnum;
  int weeknum;
  int daynum;
  int hournum;
  int minutenum;
  int calls;
} ignore = {
  "ignoretestcase",
  30,
  144,
  144,
  144,
  144,
  144

};

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



int weekcalc(char *week){
	int numberweek = 0;
  printf("First string in array is %c\n",week[0]);
  printf("isdigit is reutrning %d\n",isdigit(week[0]));
  if ((isdigit(week[0]))==2048){ //Outputted as 2048 everytime it tested for interger, I have no idea why
    printf("Week is digit\n");
    sscanf(week, "%d", &numberweek);
    return numberweek;
  }
  printf("Isn't digit!\n");
  if(strcmp(week, "mon")==0){
				return 0;}
	else if(strcmp(week, "tue")==0){
				return 1;}
	else if(strcmp(week, "wed")==0){
				return 2;}
	else if(strcmp(week, "thu")==0){
				return 3;}
	else if(strcmp(week, "fri")==0){
				return 4;}
	else if(strcmp(week, "sat")==0){
				return 5;}
	else if(strcmp(week, "sun")==0){
				return 6;}
	else{
		printf("Invalid Weekday\n");
    exit(EXIT_FAILURE);
		}
  return numberweek;
}

int monthcalcday(int monthNum){
    if( monthNum == 0 || monthNum == 2 || monthNum == 4 || monthNum == 6 || monthNum == 7 || monthNum == 9 || monthNum == 11){
			return 31;
		}
	else if(monthNum == 1){
		  return 28;
		}
		else if(monthNum == 3 || monthNum == 5 || monthNum == 8 || monthNum == 10){
			return 30;
		}
		else{
			printf("Invalid month\n");
      exit(EXIT_FAILURE);
		}
}



int timevalue(char *line){\
  int pointer = 0;
  if ((line[pointer]) == '*'){
    return -1;
  }
  if ((line[pointer]) == '0'){
    return 0;
  }
  printf("%s\n",line);
  int value = (int) (line[pointer]);
  value = value - 48; //This is dumb but no of the char -> String conversion would work
  if (line[pointer+1]!=' '){
      pointer++;
      value = value * 10;
      value = value + (line[pointer]-48);
     }
  return value;
}

void lineprocess(int Line, char *line,char *estcron){
  if (line[0]=='#'){return;} //Line is a comment, so exit the function as no data can be parsed of use 
  if (estcron=="cron"){
  int pointer = 0;
  char linepasser[30]; 
  strcpy(linepasser,line);
  int minuteval = timevalue(strtok(linepasser, " "));
  printf("\nminute value %d", minuteval);
  while(linepasser != NULL ) {
      printf( " %s\n",  linepasser); //printing each token
  }
   return 0;



//  char week2[4];
//  strcpy(week2,"tue");
//  puts (week2);
//  int weeknum = weekcalc(week2);
// printf("days in week numerical value%d\n", weeknum);
//  int monthDay = monthcalcday(montNum);
//  printf("Amount of Days in month: %i\n", monthDay);
//  char week1[4];
//  strcpy(week1,"sun");
//  puts (week1);
//  int weeknum = weekcalc(week1);
//  printf("days in week numerical value %d\n", weeknum);


  //This stuff only useful after we process file.
  //the mains stuffs
  }
  if (estcron=="est"){
    printf("est file (this still needs to be programmed //todo) \n");
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
    printf("processing line: %s\n",Line);
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
