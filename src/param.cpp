#include "param.h"

using namespace std;
map<string, string> ma;
list< pair<string, string> > lst;

const char *cstr ;

bool IsSpace(char c)
{
    if (' ' == c || '\t' == c)
        return true;
    return false;
}

bool IsCommentChar(char c)
{
    switch(c) {
    case COMMENT_CHAR:
        return true;
    default:
        return false;
    }
}

void Trim(string & str)
{
    if (str.empty()) {
        return;
    }
    int i, start_pos, end_pos;
    for (i = 0; i < str.size(); ++i) {
        if (!IsSpace(str[i])) {
            break;
        }
    }
    if (i == str.size()) { 
        str = "";
        return;
    }
    
    start_pos = i;
    
    for (i = str.size() - 1; i >= 0; --i) {
        if (!IsSpace(str[i])) {
            break;
        }
    }
    end_pos = i;
    
    str = str.substr(start_pos, end_pos - start_pos + 1);
}

bool AnalyseLine(const string & line, string & key, string & value)
{
    if (line.empty())
        return false;
    int start_pos = 0, end_pos = line.size() - 1, pos;
    if ((pos = line.find(COMMENT_CHAR)) != -1) {
        if (0 == pos) {  //
        	key = "#";
		value = line;
		return true;
            //return false;
        }
        end_pos = pos - 1;
    }
	if ((pos = line.find(GROUP_CHAR)) != -1) {
		if (0 == pos) {  //
	        	key = "@";
			value = line;
			return true;
	            //return false;
	        }
	}

	
    string new_line = line.substr(start_pos, start_pos + 1 - end_pos);  //
    
    if ((pos = new_line.find('=')) == -1)
        return false;  //
        
    key = new_line.substr(0, pos);
    value = new_line.substr(pos + 1, end_pos + 1- (pos + 1));
    
    Trim(key);
    if (key.empty()) {
        return false;
    }
    Trim(value);
    return true;
}

bool param_load(const string & filename)
{
    lst.clear();
    ifstream infile(filename.c_str());
    if (!infile) {
        cout << "file open error" << endl;
        return false;
    }
    string line, key, value;
    while (getline(infile, line)) {
		//cout << "Read from file: " << line << endl; 
        if (AnalyseLine(line, key, value)) {
            lst.push_back(make_pair(key, value));
        }
    }
    
    infile.close();
    return true;
}

void param_save()
{
	ofstream outFile("config.txt");

	list< pair<string, string> >::iterator lst_it = lst.begin();
	
	int rd_size, pos;
	string line;
	int len;

	while(lst_it != lst.end())
	{

		if(lst_it->first == "#" || lst_it->first == "@" )
		{
			outFile <<  lst_it->second <<endl;
		}
		else{		
			outFile << lst_it->first << "=" << lst_it->second <<endl;
		}

		lst_it++;
	}

	outFile.close();

	//param_load("config.txt");
}

void param_show()
{
	list< pair<string, string> >::iterator lst_it = lst.begin();

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first != "#")
		{
			if(lst_it->first == "@")
			{
				cout << "------------------------" << endl;
				cout << lst_it->second << endl;
			}
			else{
				cout << lst_it->first << "=" << lst_it->second << endl;
			}
		}
	}
	cout << "------------------------" << endl;
}

void param_show(string group)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first != "#")
		{
			if(lst_it->second == group)
			{
				cout << "------------------------" << endl;
				cout << lst_it->second << endl;
				for(++lst_it; lst_it != lst.end() && lst_it->first != "@"; ++lst_it)
				{
					if(lst_it->first != "#")
					{
						cout << lst_it->first << "=" << lst_it->second << endl;
					}
				}
				cout << "------------------------" << endl;
				return;
			}

		}
	}
	cout << "Can't find the group!!" << endl;
}

void param_find(string str)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
        //cout << lst_it->first << "=" << lst_it->second << endl;
		if(lst_it->first ==  str)
		{
			break;
		}
	}

	if(lst_it !=lst.end())
	{
		cout << lst_it->first << "=" << lst_it->second << endl;
	}else{
		cout << "Can't find the param !" << endl;
	}
}

int param_get(string str, void * val)
{
	int get_result = 1;
	list< pair<string, string> >::iterator lst_it = lst.begin();

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
        //cout << lst_it->first << "=" << lst_it->second << endl;
		if(lst_it->first ==  str)
		{
			break;
		}
	}
	if(lst_it !=lst.end())
	{
		string value = lst_it->second;
		//cout <<"value = " << value << endl;
		//cout <<"value[0] = " << value[0] << endl;
		if(34 ==value[0])
		{
			const char *cstr = value.c_str();
			memcpy((char*)val,&cstr[1],strlen(cstr)-2);
			((char *)val)[strlen(cstr)-2] = '\0';
			//cout << " ---- string ----"<<endl;
			
		}else{
			if(value.find('.')==-1)
			{
				*((int*)val) = stoi(value);
				//cout << " ---- int ----"<<endl;
			}else{
				*((float *)val) = stof(value);
				//cout << " ---- fload ----"<<endl;
			}
		}
		
	}else{
		get_result = -1;
		cout << "Can't find the param !" << endl;
		return get_result;
	}
	return get_result;
}

int	param_get(string str,void *val, void * val2)
{
	int get_result = 1;
	list< pair<string, string> >::iterator lst_it = lst.begin();
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
        //cout << lst_it->first << "=" << lst_it->second << endl;
		if(lst_it->first ==  str)
		{
			break;
		}
	}
	//cout << lst_it->first << "=" << lst_it->second << endl;
	if(lst_it !=lst.end())
	{
		string value = lst_it->second;

		int	index = value.find_first_of(',',0);

		int index2 = value.find_first_of(',',index+1);

		string str_val1 = value.substr(0,index);
		string str_val2 = value.substr(index+1,value.length());

		//cout<<" val1:  "<<str_val1<<endl;
		//cout<<" val2:  "<<str_val2<<endl;

		//cout<<"index1: "<<index<<"index 2: "<<index2<<endl;


		//cout <<"value = " << value << endl;
		//cout <<"value[0] = " << value[0] << endl;
		if(34 ==value[0])
		{
			const char *cstr = value.c_str();
			memcpy((char*)val,&cstr[1],strlen(cstr)-2);
			((char *)val)[strlen(cstr)-2] = '\0';
			//cout << " ---- string ----"<<endl;
			
		}else{
			if(str_val1.find('.')==-1)
			{
				*((int*)val) = stoi(str_val1);
				//cout << " ---- int ----"<<endl;
			}else{
				*((float *)val) = stof(str_val1);
				//cout << " ---- fload ----"<<endl;
			}
		}
		
		if(str_val2.find('.')==-1)
		{
			*((int*)val2) = stoi(str_val2);
			//cout << " ---- int ----"<<endl;
		}else{
			*((float *)val2) = stof(str_val2);
			//cout << " ---- fload ----"<<endl;
		}

	}else{
		get_result = -1;
		cout << "Can't find the param !" <<str<< endl;
		return get_result;
	}

	return get_result;

}

void param_set(string key, string val)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
        //cout << lst_it->first << "=" << lst_it->second << endl;
		if(lst_it->first ==  key)
		{
			break;
		}
	}
	if(lst_it !=lst.end())
	{
		lst_it->second = val;
	}else{
		cout << "Can't find the param !" << endl;
		return;
	}

	param_save();
}

void param_add(string group, string key, string val)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();

	if(group[0] != '@')
	{
		cout << "In front of group name must have a '@'!" << endl;
		return;
	}

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first ==  key)
		{
			cout << "Config file have contained the param already!!" << endl;
			return;
		}
	}
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->second ==  group)
		{
			lst.insert(++lst_it,1,make_pair(key,val));
			break;
		}
	}

	if(lst_it == lst.end())
	{
		lst.push_back(make_pair("@",group));
		lst.push_back(make_pair(key,val));
	}
	
	//lst.push_back(make_pair(key,val));
	
	param_save();
}

void param_add(string group)
{
	if(group[0] != '@')
	{
		cout << "In front of group name must have a '@'!" << endl;
		return;
	}
	
	list< pair<string, string> >::iterator lst_it = lst.begin();

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->second ==  group)
		{
			cout << "This group has exist already!!" << endl;
			return;
		}
	}

	lst.push_back(make_pair("@",group));
	
	//lst.push_back(make_pair(key,val));
	
	param_save();
}

void param_del(string key)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();

	if(key[0] == '@')
	{
		for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) 
		{
			if(lst_it->second == key)
			{
				list< pair<string, string> >::iterator lst_it_e_g = lst_it++;
				lst.erase(lst_it_e_g);
				for(lst_it; lst_it != lst.end() && lst_it->first != "@"; )
				{
					list< pair<string, string> >::iterator lst_it_e_k = lst_it++;				
					//cout << lst_it_e_k->first << "=" << lst_it_e_k->second << endl;
					lst.erase(lst_it_e_k);
				}
				param_save();				
				return;
			}
		}
		cout << "Can't find the group!!" << endl;
	}
	else if (key[0] != '#')
	{
		for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
	        //cout << lst_it->first << "=" << lst_it->second << endl;
			if(lst_it->first ==  key)
			{
				break;
			}
		}

		if(lst_it !=lst.end())
		{
			lst.remove(make_pair(lst_it->first,lst_it->second));
		}else{
			cout << "Can't find the param !" << endl;
			return;
		}
		param_save();
	}
	
}

unsigned int param_count(void)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();
	unsigned int cnt = 0;

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first != "#" && lst_it->first != "@")
		{
			cnt++;
		}
	}

	return cnt;
}

enum param_type_e param_type(param_t param)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();
	unsigned int cnt = 0;
	unsigned int i = 0;

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first != "#" && lst_it->first != "@")
		{
			cnt++;
		}
	}
	if(cnt <= param)
	{
		return PARAM_TYPE_UNKNOWN;
	}

	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) {
		if(lst_it->first != "#" && lst_it->first != "@")
		{
			if(i == param)
			{
				break;
			}
			i++;
		}
	}
	
	string value = lst_it->second;
	//cout <<"value = " << value << endl;
	//cout <<"value[0] = " << value[0] << endl;
	if(34 ==value[0])
	{
		//cout << " ---- string ----"<<endl;
		return PARAM_TYPE_STRING;
			
	}else{
		if(value.find('.')==-1)
		{
			//cout << " ---- int ----"<<endl;
			return PARAM_TYPE_INT32;
		}else{
			//cout << " ---- fload ----"<<endl;
			return PARAM_TYPE_FLOAT;
		}
	}
			
}

const char * param_name(param_t param)
{
	list< pair<string, string> >::iterator lst_it = lst.begin();
	unsigned int i = 0;
	
	for (lst_it = lst.begin(); lst_it != lst.end(); ++lst_it) 
	{
		if(lst_it->first != "#" && lst_it->first != "@")
		{
			if(i == param)
			{
				break;
			}
			i++;
		}
	}

	string value = lst_it->first;
	//cout <<"value = " << value << endl;

	cstr = value.c_str();

	return cstr;
			
}

#if 0
int main()
{
    param_load("config.txt");

	int a;
	float f;
//	string str;
//	cin >> str;

//	param_set("D",str);

//	param_get("D", &a);
//	param_get("F", &f);

	
//	param_save();
	param_show();

	cout << a << endl;
//	cout << f << endl;

    return 0;
}
#endif

