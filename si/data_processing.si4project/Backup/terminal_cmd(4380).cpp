#include "main.h"


static Terminal terminal; 




int help(const vector<string> ,int);
int recordSourceData(const vector<string> ,int);


enum{
	FUNC_RET_NOT_MATCH = 0,
	FUNC_RET_MATCH,
	FUNC_RET_PARAM_ERR,
}FUNC_RESULT;

TERMINAL_CMD cmd_list[10]={
	{0,"help",help},
	{1,"record",recordSourceData},


	{-1,"",NULL}
};

Terminal::Terminal():
	bufferin(NULL),
	buffer(NULL),
	buffer_idx(0),
	bufferin_idx(0)
{
	bufferin = new char[BUF_LEN];
	buffer = new char[BUF_LEN];

}
Terminal::~Terminal()
{
	if(NULL!=bufferin)
	{
		delete []bufferin;
		bufferin = NULL;
	}

	if(NULL!=buffer)
	{
		delete []buffer;
		buffer = NULL;
	}

}
bool is_num_string(string a)
{
	char buf[20];
	memset(buf,0,20);
	strcpy(buf,a.c_str());

	for(int i=0;i<20 && buf[i]!=0;i++)
	{
		if(!(buf[i]<=0x39 && buf[i]>=0x30))
			return false;
			
	}
	return true;
}

int recordSourceData(const vector<string> param,int cmd)
{
	int ret = FUNC_RET_NOT_MATCH;
	string name = cmd_list[cmd].name;
	if(0 == param[0].compare(name) && param.size() == 2)
	{
	    int recode_cnt = std::stoi(param[1]);	
		ret = FUNC_RET_MATCH;
	//	Nav->r2000.record_start = true;
	}

	
	return ret;
}

int help(const vector<string> param,int cmd)
{
	int ret = FUNC_RET_NOT_MATCH;
	string name = cmd_list[cmd].name;
	if(0 == param[0].compare(name))
	{
		ret = FUNC_RET_MATCH;

		printf("############All CMDS############\n");
		for(int i=0;cmd_list[i].id !=-1;i++)
		{
			printf("[%d]   name:%s\n",i,cmd_list[i].name.c_str());
		}
		printf("########################\n");
	}

	
	return ret;
}
int Terminal::get_input()
{
	memset(bufferin,0,sizeof(char)*BUF_LEN);
	bufferin_idx = 0;
	buffer_idx = 0;

	printf(">");
	fgets(bufferin,100,stdin);

	if(bufferin[0]==0x0a)
		return -1;

	param.clear();
	
	int last_index = 0;
	while(true)
	{
		if(bufferin[bufferin_idx] == ' ' || bufferin[bufferin_idx] == 0x0a)
		{
			memset(buffer,0,sizeof(char)*BUF_LEN);
			memcpy(buffer,bufferin+last_index,bufferin_idx-last_index);
			string temp = buffer;
			param.push_back(temp);
			last_index=bufferin_idx+1;
		}
		if(bufferin[bufferin_idx] == 0x0a)	
			break;
		bufferin_idx++;
	}
	return 0;

}

void *pThread_terminal_main(void *arg)
{

	while(1)
	{
		
		if(-1 == terminal.get_input())
		{
			util::sleep(1);
			continue;
		}

		for(int i=0;;i++)
		{
			int ret = cmd_list[i].func(terminal.param,i);
			if(FUNC_RET_MATCH == ret)
				break;
			else if(FUNC_RET_PARAM_ERR == ret)
			{
				printf("# input param err\n");
				break;
			}
			
			if(cmd_list[i+1].id==-1)
			{
				printf("All cmd not match\n");
				break;
			}
		}
		
	}

    return (void *)0;
}

void startThreadTerminal()
{
	pthread_t tid;
	pthread_create(&tid,NULL,pThread_terminal_main,NULL); 
}


