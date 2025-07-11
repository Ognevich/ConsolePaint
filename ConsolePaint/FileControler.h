#ifndef FILE_CONTROLER_H
#define FILE_CONTROLER_H
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Defines.h"

class FileControler {
public:
	
	FileControler(const std::string& initialPath);

	int getFileIndex(const std::string& filename);
	int filesFoundMax(const std::string& filepath);
	bool isTargetFile(const std::string& filename);
	std::string createNewFileName(const std::string& filepath);
	void createFile(std::string fileData);

	std::string promptFilenameInput();
	std::string getFileData(std::string & filepath);

	std::string getFilePath();


private:

	std::string file_path;

};


#endif
