#ifndef DEFINES_H
#define DEFINES_H

	//#define DEBUG_MODE


	#ifdef DEBUG_MODE
		#define DBG_CERR(x) std::cerr << x << std::endl
	#else
		#define DBG_CERR(x)
	#endif

	#ifdef DEBUG_MODE
		#define DBG(x) std::cout<< x << std::endl	
	#else 
		#define DBG(x)
	#endif


	// FILE PATH TO SCETCH DIRECTORY
	#define FILE_PATH "D:\\my_projects\\c++\\ConsolePaint\\ConsolePaint\\savedScatches"

	// UI OFFSET
	#define PANEL_Y_OFFSET 20 
	#define LOGPANEL_Y_OFFSET 22	
	// USED TO REPLACE TEXT WITH EMPTY STRING
	#define STRING_REPALCE 450


#endif 
