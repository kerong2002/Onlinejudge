#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <windows.h>
#define gccVersion 14

using namespace std;

void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

int main() {
    string filePath;
    string sysCommit_answer;
    string sysCommit_test;

//call classmates_code
    sysCommit_test
        .append("\ng++ ")
        .append("-std=c++17 ")
        .append("./classmate_code.cpp ")
        .append("-o ./out.exe");

    cout << sysCommit_test<< endl;

    system(sysCommit_test.c_str());

    sysCommit_test = "";
    sysCommit_test.append("type ")
        .append("\"./input.txt\" ")
        .append("| ")
        .append("\"./out.exe\"")
        .append("> ")
        .append("\"./classmates_output.txt\"");
    system(sysCommit_test.c_str());

//verify
    int file_count=1;
	FILE *stream1=fopen("answer_output.txt", "r");
	FILE *stream2=fopen("classmates_output.txt", "r");
	char answer[999];
	char classmates[999];
	int no_ok=0;
	while((fscanf(stream1, "%[^\n]", answer)!= EOF)and(fscanf(stream2, "%[^\n]", classmates)!= EOF))
	{
	    fgetc(stream1);
		fgetc(stream2);
		if(!strcmp(answer , classmates)){
			SetColor(175);
		    printf("[NO.%d]pass\n\n",file_count);
		    SetColor(7);
		    file_count++;
		}
		if(strcmp(answer , classmates)){
			SetColor(207);
		    printf("[NO.%d]Output isn't currect :",file_count);
		    SetColor(7);
		    printf("%s\n",classmates);
		    SetColor(13);
			printf("The currect answer is this :");
			SetColor(7);
			printf("%s\n\n",answer);
			file_count++;
			no_ok=1;
		}

	}
    if(no_ok==0){
        printf("@ALL PASS~~\\(^o^)//\n");
    }
	fclose(stream1);
	fclose(stream2);

}
