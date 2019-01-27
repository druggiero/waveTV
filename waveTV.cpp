//WaveTV
//First Started: 02/20/17
//Last Updated: 03/06/17
//D.Ruggiero 

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int WIDTH = 1200;
const int HEIGHT = 700;

SDL_Window* win = NULL;
SDL_Surface* baseSurface = NULL;

void init();
void close();

void setPix(int x, int y);
void setPix2(int x, int y);
void setPix3(int x, int y);
void setPix4(int x, int y);
void setPix5(int x, int y);
void setPix6(int x, int y);
void setPix7(int x, int y);
void setPix8(int x, int y);


int i = 0;
int j = 1;

int channel = 0;
int frameNum = 0;
int numberOfChannels = 8;


int main(int argc, char* args[]){
	
	init();

	srand(time(NULL));


	SDL_Event event;
	bool running = true;

	//main loop
	while(running){

		char charBuffer [50];
		sprintf(charBuffer, "frames/screen_%04d.png", frameNum);		
		//SDL_SaveBMP(baseSurface, charBuffer);
		frameNum ++;

		if(channel == 0){
			SDL_Delay(30);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix(x,y);
				}
			}
		}

		else if(channel == 1){
			SDL_Delay(15);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix2(x,y);
				}
			}
		}

		else if(channel == 2){
			SDL_Delay(35);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix3(x,y);
				}
			}
		}

		else if(channel == 3){
			SDL_Delay(50);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix4(x,y);
				}
			}
		}

		else if(channel == 4){
			SDL_Delay(50);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix5(x,y);
				}
			}
		}

		else if(channel == 5){
			SDL_Delay(50);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix6(x,y);
				}
			}
		}
		else if(channel == 6){
			SDL_Delay(50);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix7(x,y);
				}
			}
		}

		else if(channel == 7){
			SDL_Delay(50);
			for(int x = 0; x < WIDTH; x++){
				for(int y = 0; y<HEIGHT; y++){
					setPix8(x,y);
				}
			}
		}

		SDL_UpdateWindowSurface(win);
			while(SDL_PollEvent(&event)){
				switch(event.type){
					case SDL_QUIT:
						printf("Exiting DIRT.");
						running = false;
						break;

					case SDL_KEYDOWN:
						switch(event.key.keysym.sym ){
							case SDLK_UP:
								channel = (channel + 1) % numberOfChannels;
								printf("Channel %d \n \n", channel);
								break;

							case SDLK_DOWN:
								channel = channel - 1;
								if(channel<0){
									channel = numberOfChannels -1;
								}
								printf("Channel %d \n \n", channel);
								break;

						}
						break;
				}
			}
	}

	close();

}

void setPix(int x, int y){
	//point to the Uint32 pixel data, 
	//arrow notation gets member (pixel data) from Surface pointer
	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;
	i = i + 1;
}


void setPix2(int x, int y){

	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i = i + 1000;

}


void setPix3(int x, int y){

	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i = i + j;
	j = j + 1;

}

void setPix4(int x, int y){

	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i= i + j;
	j= j + 1500;

}

void setPix5(int x, int y){

	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i= i + j;
	j= j + 88;
}

void setPix6(int x, int y){
	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i= i + j;
	j= j + 2800;

}

void setPix7(int x, int y){

	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i= i + j;
	j= j + 3232;
}

void setPix8(int x, int y){
	Uint32 *pixelPointer = (Uint32*)baseSurface->pixels;
	int width = baseSurface->w;
	pixelPointer[(y * width) + x] = i;

	i= i + j;
	j= j + 6464;
}

void init(){
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL Initialization Failed. How did that happen?");
	}
	else{
		win = SDL_CreateWindow("DIRT", 450,100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		baseSurface = SDL_GetWindowSurface(win);
	}
}

void close(){
	SDL_DestroyWindow(win);
	win = NULL;
	SDL_Quit();
}