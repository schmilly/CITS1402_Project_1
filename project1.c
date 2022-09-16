#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
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
void trim_line(char line[])
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

void fileprocess(int line,char *Line,char *estcron){
  if (Line[0]='#'){return;} //Line is a comment, so exit the function as no data can be parsed of use
  char data[Filesize][len];
  int dailyCount = 0;
  int weeklyCount = 0;
  int deepCount = 0;
  int submitCount = 0;
  int sendCount= 0;  
  int monthNum;
  int daysinmonth;
  

  monthcalc(monthNum,daysinmonth);

  //the mains stuffs
  if (estcron == "cron"){
    //Process for getting parsing cron files
  for(int i = 0; i < line; i++){
	  for(int j = 0; j < line; j++){
		  if(data[0][6] == '*' || data[0][6] == monthNum){	
			  //daily count
			  if(data[0][0] == '*' && data[0][2] == '*'){
			  	dailyCount = 1440 * daysinmonth;
			  }
			  else if(data[0][0] == '*' && data[0][2] != '*'){
			dailyCount = (24 - (data[0][2])-1) * 60 * daysinmonth;
			}
			else if(data[0][0] != '*' && data[0][2] == '*'){
				dailyCount = 24 * daysinmonth;
			}
			else if(data[0][0] != '*' && data[0][2] != '*'){
				dailyCount = (24 - (data[0][2])-1) * daysinmonth;
			}

		  }
		  //weekly
		  if (data[1][6] == '*' || data[1][6] == monthNum){

		  }
		  //deepthought
		  if(data[2][6] == '*' || data [2][6] == monthNum){

		  }
	  //submit-project
		  if(data[3][6] == '*' || data[3][6] == monthNum){

		  }
		  //send-monthly
		  if(data[4][6] == '*' || data[4][6] == monthNum){
			  sendCount = 1;
      }
  }}}
  else if (estcron == "est"){
      //Code for processing est verson
    }
}

void monthcalc(int *monthNum, int *daysinmonth){
	int monthNum = 0;
	int daysinmonth = 0;

	if(isdigit(month)==0){ //the Isdigit function evaluates to 1 or 0 (as opposed to true or false) so I fixed it for ya ;)
		monthNum = month;
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
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


	else{
	if(month == "jan"){
		daysinmonth = 31;
		monthNum = 1
		}
	else if(month == "feb"){
		daysinmonth = 28;
		monthNum = 2;
		}
	else if(month == "mar"){
		daysinmonth = 31;
		monthNum = 3;
		}
	else if(month == "apr"){
		daysinmonth = 30;
		monthNum = 4;
		}
	else if(month == "may"){
		daysinmonth = 31;
		monthNum = 5;
		}
	else if(month == "jun"){
		daysinmonth = 30;
		monthNum = 6;
		}
	else if(month == "jul"){
		daysinmonth = 31;
		monthNum = 7;
		}
	else if(month == "aug"){
		daysinmonth = 31;
		monthNum = 8;
		}
	else if(month == "sep"){
		daysinmonth = 30;
		monthNum = 9;
		}
	else if(month == "oct"){
		daysinmonth = 31;
		monthNum = 10;
		}
	else if(month ==  "nov"){
		daysinmonth = 30;
		monthNum = 11;
		}
	else if(month == "dec"){
		daysinmonth = 31;
		monthNum = 12;
		}
	else{
		printf("Invalid month")
		}
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
  
  int line = 0;
  char Line[100];
  //File read loop
  while ( fgets(Line, sizeof Line, file)){
    trim_line( Line );
    fileprocess( line, Line, estcron );
  } 
//count use to find out the most used command

}


//calculate the most called command
//just did ladder, required less lines
//most likely make it its own function

//THIS WILL NOT WORK< IT NEEDS TO HAVE THE COMMAND NAME PUT IN, YOU CAN'T JUST
//ADD THE NAMES MANUALLY, WHERE IS THE DATA STRUCUTE THAT WAS SUPPOSED TO BE SETUP???
char most_called_command(command){
	if(dailyCount > weeklyCount && dailyCount > deepCount && dailyCount > submitCount && dailyCount > sendCount){
		char *most_called_command = "daily-backup";
	}
	else if(weeklyCount > dailyCount && weeklyCount > deepCount && weeklyCount > submitCount && weeklyCount > sendCount){
		char *most_called_command = "weekly-backup";
	}

	else if(deepCount > dailyCount && deepCount > weeklyCount && deepCount > submitCount && deepCount > sendCount){
		char *most_called_command = "deep-thought";
	}
	else if(submitCount > dailyCount && submitCount > weeklyCount && submitCount> deepCount && submitCount > sendCount){
		char *most_called_command = "submit_project";
	}
	else{
		char *most_called_command = "send-monthly-newsletter";
	}

  //total amount of commands
  //can make its own function, but kinda of small so not required
  int total_commands = 0;
  int total_commands = dailyCount + weeklyCount + deepCount + submitCount + sendCount;


  printf("Readingfile");
  return most_called_command;

}

int main(int argcount, char argvalue[]) {

  // checking to see we have the correct number of arguments (debuggin bs)
  printf("Spinning up program now!\n");
  
  //Converted to function for sake of it looking nicer
  argumentcheck(argcount);

  char *estfile = argvalue[3];
  char *month = argvalue[1];
  char *Crontab = argvalue[2];
  printf("Sucesfully assigned Terminal arguments; moving on...\n"); //toremove, user doesn't care
  //Error Checking of files
  error_check(Crontab);
  error_check(estfile);
  printf("All files exist; moving on....\n");
  //Reading files specifically

  reading_file(Crontab, "cron");
  reading_file(estfile, "est");
  exit(EXIT_SUCCESS);
}





//printf(most frequent command executed, total num of commands invoked, maximum num of commands running);
