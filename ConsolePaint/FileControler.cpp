#include "FileControler.h"

FileControler::FileControler(const std::string& initialPath)
    : file_path(initialPath)
{

}

int FileControler::getFileIndex(const std::string& filename)
{
    std::string numberPart;
    for (char c : filename) {
        if (isdigit(c)) {
            numberPart += c;
        }
    }
    return numberPart.empty() ? -1 : std::stoi(numberPart);
}

int FileControler::filesFoundMax(const std::string& filepath)
{
    std::vector<int> lastNumbers;
    try {
        for (auto& file : std::filesystem::directory_iterator(filepath)) {
            if (file.is_regular_file()) {
                std::string name = file.path().filename().string();

                if (isTargetFile(name))
                    lastNumbers.push_back(getFileIndex(name));
            }
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        DBG_CERR("Filesystem error: " << e.what() << "\n");
        return 0;
    }

    if (lastNumbers.empty()) return 0;
    return *std::max_element(lastNumbers.begin(), lastNumbers.end());
}

bool FileControler::isTargetFile(const std::string& filename)
{
    return filename.rfind("file", 0) == 0 && filename.size() > 4 &&
        filename.substr(filename.size() - 4) == ".txt";
}

std::string FileControler::createNewFileName(const std::string& filepath)
{
    std::string newFileName;

    int maxElem = filesFoundMax(filepath);

    newFileName = "file" + std::to_string(maxElem + 1) + ".txt";

    return newFileName;
}

void FileControler::createFile()
{

    if (file_path.empty()) {
        DBG("file_path is empty");
        return;
    }

    std::string fileName = createNewFileName(file_path);
    std::string fullPath = file_path + "\\" + fileName;

    std::ofstream file(fullPath);
    if (!file.is_open()) {
        DBG("Failed to open file: " << fullPath);
        return;
    }

    file << "File is saved";
    file.close();
}

std::string FileControler::getFilePath() {

    return file_path;
}

