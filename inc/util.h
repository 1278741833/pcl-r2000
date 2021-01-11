#ifndef __UTIL__H__
#define __UTIL__H__

#include <sstream>
#include <string>

#include <ctime>

#include "main.h"



namespace util {




#if 0



template <typename Derived>
struct ColComparator
{	
	const Derived& matrix;	
	const int row; 	
	ColComparator(const MatrixBase<Derived>& m, int r)
		: matrix(m.derived()), row(r)	
		{} 	
	bool operator()(int i, int j) const	
	{		
		return matrix(row, i) < matrix(row, j);	
	}
}; 
template <typename Derived>
struct RowComparator
{	
	const Derived& matrix;	
	const int col; 	
	
	RowComparator(const MatrixBase<Derived>& m, int c)
		: matrix(m.derived()), col(c)	
		{} 	
	
	bool operator()(int i, int j) const
	{		
		return matrix(i , col) < matrix(j , col);	
	}
}; 
template <typename Derived>
VectorXi columnArgSort(const MatrixBase<Derived>& matrix, int row)
{	
	// Start with indices [0 1 2 ... N-1]	
	VectorXi indexes = VectorXi::LinSpaced(matrix.cols(), 0, matrix.cols() - 1); 	
	// Sort using our custom comparator, that will compare matrix values indirectly.	
	std::sort(indexes.data(), indexes.data() + indexes.size(),		
		ColComparator<Derived>(matrix, row)); 	
		
		return indexes;
} 
template <typename Derived>
VectorXi rowArgSort(const MatrixBase<Derived>& matrix, int col)
{	
	// Start with indices [0 1 2 ... N-1]	
	VectorXi indexes = VectorXi::LinSpaced(matrix.rows(), 0, matrix.rows() - 1); 	
	// Sort using our custom comparator, that will compare matrix values indirectly.	
	std::sort(indexes.data(), indexes.data() + indexes.size(),		
		RowComparator<Derived>(matrix, col)); 	
		
		return indexes;
} 




#endif






/*
Sleep current thread for a few milliseconds.
*/
inline void sleep(const long ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


}




#if 1






class GLOG
{
public:
	GLOG();
	
	~GLOG();

	void initGlogSystem(char* filename);

};
void split(string&,vector<int>&,const char);

bool cmpStr(char * s1,char * s2,int cnt);

void sleepMs(int num);

unsigned long CRC_32(const unsigned char * aData, int aSize );
void SplitString(const string& s, vector<string>& v, const string& c);



bool bufferCrcCheck(char* buffer,int total_len);
uint16_t getbufferCrc(const char* buffer,int total_len);





typedef struct{
	MatrixXf m;
	long int ts;
	float height;
}FRAME_DATA;
typedef enum{
	S_FEA_DIST = 0,
	S_FEA_ANG,
}SOURCE_DATA_FEA;
typedef enum{
	U_FEA_X = 0,
	U_FEA_Y,
}USE_DATA_FEA;


#define PRINT_FB(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",31,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);}}
#define PRINT_ERRMEM(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",32,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);exit(0);}}
#define PRINT_ATTCB(x,...) {if(x){printf("\x1b[%dm%s(%d)-<%s>:\x1b[0m",33,__FILE__, __LINE__, __FUNCTION__);printf(__VA_ARGS__);}}









#endif

//void 

#endif
