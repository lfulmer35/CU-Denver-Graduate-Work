#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string>

using namespace std;

int main(){

	system("clear");
	system("echo '**********Welcome to Lab2**********\n'");
	
	while(true){
	//display prompt
	//cout << getcwd(NULL, 0) << ">>" << flush;
	cout << "MyShell>>" << flush;
	char command[128];
	cin.getline(command, 128);//getting input from user
	
	if(strlen(command) == 0)//user pressed enter
		system("\n");
	
	else{//text entered
		vector<char*> args;
		string testString(command);
		int n = testString.length();
		char message[n+1];
		strcpy(message, testString.c_str());
		char* prog = strtok(command, " ");//converting input to char* with string tokens
		char* temp = prog;

		while(temp != NULL){
			args.push_back(temp);
			temp = strtok(NULL, " ");
		}

		char** argv = new char*[args.size()+1];
		for(int k=0; k < args.size(); k++)
			argv[k] = args[k];//converting our tokens into an argument list

		argv[args.size()] = NULL;

		if(strcmp(command, "exit")==0){//user wants to exit
			printf("Goodbye\n");
			return 0;
		}


		else{//not exit
			if(!strcmp(prog, "cd")){//we don't want to fork for cd
				if (argv[1] == NULL)
					chdir("/");
				else
					chdir(argv[1]);
				perror(command);
			}

		else if(testString.find(">")!=-1
			|| testString.find("<")!= -1
			|| testString.find("<<") != -1
			|| testString.find(">>") != -1){//looking for >> << < > tokens
			system(message);
		}
		else{
			pid_t child = fork();
			if(child < 0){//error
				perror("Internal Error: Cannot fork.\n");
				return -1;
			}

		else if(child == 0){//child process
			execvp(prog, argv);
			//in case of any errors
			perror(command);
			return -1;
		}

		else{//parent
			if (waitpid(child, 0, 0) < 0){//error again
				perror("Internal error\n");
				return -1;
				}
			}//else parent
		}//else
		}//else cd
		}//else no text
	}//while true
	return 0;
}
