#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 30000
#define BRAINFUCK_ARRAY_SIZE 30000

int getMatchingClose(int pos, char buffer[]){
	int c = 1;
	for (int i = pos+1; i < BUFFER_SIZE; i++){
		switch(buffer[i]){
			case '[':
				c++;
				break;
			case ']':
				c--;
				break;
		}
		if (c == 0)
			return i;
	}
	fprintf(stderr, "Invalid Code!\n");
	exit(-1);
}

int getMatchingOpen(int pos, char buffer[]){
        int c = 1;
        for (int i = pos-1; i >= 0; i--){
                switch(buffer[i]){
                        case '[':
                                c--;
                                break;
                        case ']':
                                c++;
                                break;
                }
                if (c == 0)
                        return i;
        }
        fprintf(stderr, "Invalid Code!\n");
        exit(-1);
}

int main(int argc, char *argv[]){

	if (argc != 2){
		fprintf(stderr, "Incorrect Arguments!\n");
		exit(-1);
	}

	FILE *fp = fopen(argv[1],"r");

	if (fp == NULL){
		fprintf(stderr, "Invalid file or directory!\n");
		exit(-1);
	}

	char buffer[BUFFER_SIZE];
	char c;
	int i;
	for (i = 0; i < BUFFER_SIZE && (c = fgetc(fp)) != EOF;){
		switch(c){
			case '+':
				buffer[i++] = c;
				break;
			case '-':
				buffer[i++] = c;
				break;
			case '>':
				buffer[i++] = c;
				break;
			case '<':
				buffer[i++] = c;
				break;
			case ']':
				buffer[i++] = c;
				break;
			case '[':
				buffer[i++] = c;
				break;
			case '.':
				buffer[i++] = c;
				break;
			case ',':
				buffer[i++] = c;
				break;
		}
	}
	buffer[i] = '\0';

	char bfarray[BRAINFUCK_ARRAY_SIZE] = {0};
	int bfcurr = 0;
	for (i = 0; buffer[i] != '\0';){
		switch(buffer[i]){
			case '+':
				bfarray[bfcurr]++;
				i++;
                                break;
                        case '-':
				bfarray[bfcurr]--;
				i++;
                                break;
                        case '>':
				bfcurr++;
				i++;
                                break;
                        case '<':
				bfcurr--;
				i++;
                                break;
                        case ']':
				if (bfarray[bfcurr] != 0)
					i = getMatchingOpen(i, buffer);
				else
					i++;
                                break;
                        case '[':
				if (bfarray[bfcurr] == 0)
					i = getMatchingClose(i, buffer);
				else
					i++;
                                break;
                        case '.':
                               	putchar(bfarray[bfcurr]);
				i++;
                                break;
                        case ',':
				bfarray[bfcurr] = getchar();
				i++;
                                break;
		}
	}
}
