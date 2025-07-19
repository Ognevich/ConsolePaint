#include "FileControler.h"

FileControler::FileControler(const std::string& initialPath)
    : file_path(initialPath)
{

}

void FileControler::createFile(std::string fileData)
{

    std::string filename;

    if (file_path.empty()) {
        DBG("file_path is empty");
        return;
    }

    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::string fullFileName = filename + ".txt";

    std::string fullPath = file_path + "\\" + fullFileName;

    std::ofstream file(fullPath);
    if (!file.is_open()) {
        DBG("Failed to open file: " << fullPath);
        return;
    }

    file << fileData;
    file.close();
}

std::string FileControler::promptFilenameInput()
{

    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::string filepath = "D:\\my_projects\\c++\\ConsolePaint\\ConsolePaint\\savedScatches\\" + filename + ".txt";
    std::string fileData = getFileData(filepath);

    return fileData;
}

std::string FileControler::getFileData(std::string& filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filepath << '\n';
        return {};
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string fileData = buffer.str();

    return fileData;
}

std::string FileControler::getFilePath() {
    return file_path;
}

