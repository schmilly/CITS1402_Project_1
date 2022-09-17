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

// This codes a mess and will be handed in late but Josh decided to just stop responding to my messages
// and left me with some of the worst code I have ever seen so you know, fun
// I am just trying to get to the end at this point how the code looks doesn't matter to me anymore
// Im sorry - Will ;_;


// TOREMOVE == Marking lines for debugging
// TODO == Does this need to be explained?

// defining size of chrachter array for files
#define Filesize 10000
#define len 1000

//Initalise of process 
struct commands {
  char *processname;
  int minutenum;
  int hournum;
  int daynum;
  int monthnum;
  int weeknum;
  int calls;
  int timetakes;
};

struct commands tasks[99]; ;//array of strucutes give us over 100 commands to look at
// Yonked from FileIO lecture (very useful thanks)
void trim_line(char line[0])
{
    int i = 0;
//  LOOP UNTIL WE REACH THE END OF line
    while(line[i] != '\0') {

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
  if ((isdigit(week[0]))==2048){ //Outputted as 2048 everytime it tested for interger, I have no idea why
    sscanf(week, "%d", &numberweek);
    return numberweek;
  }
  if(strcmp(week, "mon")==0){
				return 0;}
	else if(strcmp(week, "tue")==0){
				return 1; }

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



int timevalue(char *line){
  if (line[0] == '*'){
    return -1;
  }
  if (isdigit(line[0])==1){
  int value = atoi(line);
  return value;
  }
  else{
      int value = weekcalc(line);
      return value;
    } 
}
                                                        //1=loc, 0=minutes
int estprocess(char *efile, char *name){
  FILE *file = fopen(efile, "r");
  char Line[100];
  int structnum = 0;
  while ( fgets(Line, sizeof Line, file)){
    trim_line( Line ); if (Line[0]!='#'){
      //Skip line if it starts with a hash 
      char *currentword = strtok(Line, " ");
      while (strcmp(currentword, name)==0){
        char *token = strtok(NULL, " ");
        int minutes = atoi(token);
      return minutes; 
      }
//return minute if it's looking for that    counter++;          
      structnum++;
    
    }  
  }
  //File read loop

}



struct commands cronprocess( char line[], char *estfile){
 //Line is a comment, so exit the function as no data can be parsed of use 
  int current = 0;
  char linepasser[30]; 
  strcpy(linepasser,line);
   // Extract the first token
  char *token;
  printf("%s",line);
   token = strtok(linepasser, " ");
   // loop through the string to extract all other token
  int minuteval;
  int hourteval; 
  int monthday; 
  int month;
  int weekday;
  char *name;
   while( token != NULL ) {
      printf(" current while pos: %d, current token: %s\n",current,token);
      switch (current){
        case 0:
          minuteval = timevalue(token);
          break;
        case 1:
          hourteval = timevalue(token);
          break;
        case 2:
          monthday = timevalue(token);
          break;
        case 3:
          month = timevalue(token);
          break;
        case 4:
          weekday = timevalue(token);
          break;
        case 5:
          name = token;
          break;
      }
      token = strtok(NULL, " ");
      current++;
      }
    int timetakes = -1;
    char *taker;
    strcpy(taker,name);
    timetakes = estprocess(estfile,taker);
    struct commands var = {
    .processname = name, 
    .minutenum = minuteval, 
    .hournum = hourteval,
    .daynum = monthday, 
    .weeknum = weekday, 
    .calls = -1, 
    .timetakes = timetakes};
    return var; 
 }


//just did some file error and opening stuff. converted it into an array of string
struct commands *reading_file(char *filename, char *estname) {
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
  
  char Line[1000]; 
  int structnum = 0;
  //File read loop
  while ( fgets(Line, sizeof Line, file) != NULL){
        trim_line( Line );    
        printf("outside cronporc: %s\n",Line);
        if (Line[0]!='#'){ //Skip line if it starts with a hash
        int sizef = sizeof(Line);
        tasks[structnum] = cronprocess( Line, estname );
        printf ("Process found! %s, assigned to array number %d,with values %d, %d, %d, %d, %d, %d, %d\n",
              tasks[structnum].processname, structnum, tasks[structnum].minutenum, tasks[structnum].hournum, tasks[structnum].daynum, tasks[structnum].monthnum, tasks[structnum].weeknum, tasks[structnum].calls, tasks[structnum].timetakes);
      structnum++;
    }
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

  reading_file(Crontab,estfile);
  printf("Crontab made array with name of: %s \n", tasks[0].processname);
  printf("All files read, moving onto simulation!\n");
  exit(EXIT_SUCCESS); 
}





//printf(most frequent command executed, total num of commands invoked, maximum num of commands running);
