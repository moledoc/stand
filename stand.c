#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "raylib.h"

#define CYCLE 60 * 60 // seconds
#define STAND 10 * 60 // seconds

int ticker = 0;
int end_ticking = 0;

void *ticking(void *vargp) {
  while (!end_ticking) {
    sleep(1);
    ticker += 1;
  }
  return NULL;
}

int should_stand() {
  int tick = ticker % (CYCLE);
  return 0 <= tick && tick < STAND;
}

int main(void) {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, ticking, NULL);

  while (1) {
    if (should_stand()) {
      InitWindow(30, 30, "stand");
      SetTargetFPS(5);
      while (!WindowShouldClose() && should_stand()) {
        BeginDrawing();
        SetWindowState(FLAG_WINDOW_TOPMOST);
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
