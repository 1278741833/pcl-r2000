#ifndef __PARAM_H__
#define __PARAM_H__

#include <utility> 
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <unistd.h>
#include <list> 

using namespace std;

typedef enum param_type_e {
	/* globally-known parameter types */
	PARAM_TYPE_INT32 = 0,
	PARAM_TYPE_FLOAT,
	PARAM_TYPE_STRING,
	PARAM_TYPE_UNKNOWN = 0xffff
} param_type_t;
typedef uint16_t	param_t;

 
#define COMMENT_CHAR '#'
#define COMMENT_STR "#"
#define GROUP_CHAR '@'
#define GROUP_STR "@"

bool param_load(const string & filename);
void param_save();
void param_show(string group);
void param_show();
void param_find(string str);
void param_set(string key, string val);
void param_add(string group);
void param_add(string group, string key, string val);
void param_del(string key);
int param_get(string str, void * val);
int	param_get(string str,void *val, void * val2);


unsigned int param_count(void);
enum param_type_e param_type(param_t param);
const char * param_name(param_t param);


#endif
