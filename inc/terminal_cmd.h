#ifndef __TERMINAL_H__
#define __TERMINAL_H__


#include "main.h"







#define BUF_LEN 100
#define TERMINAL_CMD_CNT 10
#define TERMINAL_KEY_LEN 50

typedef struct{
	int id;
	string name;
	
	int (*func)(const vector<string>,int); 

}TERMINAL_CMD;








class Terminal{
public:
	Terminal();
	~Terminal();
	int get_input();
	bool match_func();

	
public:
	char * bufferin;
	char * buffer;
	int bufferin_idx;
	int buffer_idx;

	vector<string> param;

private:
	
};

void *pThread_terminal_main(void *arg);   

void startThreadTerminal();


#endif
