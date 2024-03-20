#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "raylib.h"

int cycle = 60*60; // minutes
int stand = 10*60; // minutes
int ticker = 0;
int end_ticking = 0;

void *ticking(void *vargp) {
	while(!end_ticking) {
		sleep(1);
		ticker += 1;
	}
	return NULL;
}

int should_stand() {
	int tick = ticker%(cycle);
	return 0 <= tick && tick < stand;
}

int main(void) {
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, ticking, NULL);

	while (1) {
		if (should_stand()) {
			InitWindow(30, 30, "stand");
			while (!WindowShouldClose() && should_stand()) {
				BeginDrawing();
				ClearBackground(RED);
				SetWindowPosition(0, 0);
				EndDrawing();
			}
			CloseWindow();
		}
		sleep(60);
	}
	pthread_join(thread_id, NULL);
	return 0;
}