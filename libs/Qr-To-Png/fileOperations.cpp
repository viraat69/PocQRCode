#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;


// using the linux kernel system call library
bool exists_byStat (const std::string& fileName)
{
  struct stat buffer;
  return (stat (fileName.c_str(), &buffer) == 0);
}

// using the File stream libraries
bool exists_byIO (const std::string& filename)
{
    if (FILE *file = fopen(filename.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// using the access libraries
bool exists_byposixAccess(const std::string &fileName)
{
    return ( access( fileName.c_str(), F_OK ) != -1 );
}

// Checks if contents of both files are same
bool compareFiles(const std::string& p1, const std::string& p2)
{
  std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    return false; //file problem
  }

  if (f1.tellg() != f2.tellg()) {
    return false; //size mismatch
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}


// Copies source to destination with result of copy as boolean
bool copyfile(const std::string &fromfileName, const std::string &tofileName)
{
    bool copyResult;
    std::string sourceFile(fromfileName);
    std::string destinationFile(tofileName);
    destinationFile = destinationFile + ".tmp";

    // Perform copy oeprations.
    ifstream source(sourceFile, ios::binary);
    ofstream dest(destinationFile, ios::binary);

    dest << source.rdbuf();

    source.close();
    dest.close();

    // Check if copy oeprations were sucessful by comparing two files.
    copyResult = compareFiles(sourceFile,destinationFile);
    return copyResult;
}


