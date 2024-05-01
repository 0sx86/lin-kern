#include <stdlib.h>
#include <stdio.h>

int left(int p) { return p; }
int right(int p) { return (p + 1) % 5;}

void get_forks(int p){
	if (p == 4){
		sem_wait(&forks[right(p)]);
		sem_wait(&forks[left(p)]);
	} else {
		sem_wait(&forks[left(p)]);
		sem_wait(&forks[right(p)]);
	}
}

void put_forks(int p){
	sem_post(&forks[left(p)]);
	sem_post(&forks[right(p)]);
}

int main(int argc, char * argv[]){

	while (1){
		think();
		get_forks(p);
		eat();
		put_forks(p);
	}

	return 0;
}
