#ifndef SERVER_H
#define SERVER_H

#include <semaphore.h>
#include <pthread.h>

void* reader(void* param);
void* writer(void* param);
void* handleClient(void* param);

#endif
