// this is main c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"			// for user-defined header, use double quotes
#include "sound.h"
#include "comm.h"
int main(int argc, char **argv){
	if(argc == 2 ){
		int ch;
		printf("how many channels ? 1;mono, 2;stereo:)");
		scanf("%d", &ch);
		float duration;
		printf("how long is the test tone? (1-10 sec):");
		scanf("%f", &duration);
		testTone(ch,atoi( argv[1]), duration);
		return 0;
	}
	FILE*f;
	short sd[RATE]; 			// for all samples in 1 sec
	while(1){
		int ret = system(CMD);
		if (ret == SIGINT)break; 
		f = fopen("test.wav", "r");		// open the file for read only
		clearScreen();
		setColors(YELLOW, bg(BLACK));
		if(f == NULL){
			printf("cannot open the wav file\n");
			return 1;
	}
	struct WAVHDR h;		// instance of wav header
	fread(&h, sizeof(h), 1, f);		// read wav header to h
	displayWAVHDR(h);		// show wav header information
	fread(&sd, sizeof(sd), 1,f);
	displayWAVDATA(sd);
	fclose(f);				// close the opened file
	sendDATA(sd);
}
	resetColors();
	printf("Another message\n");
	getchar();
}
