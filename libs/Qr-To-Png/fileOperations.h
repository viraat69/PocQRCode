#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H


#include <string>

/* Function call that returns true/false if file exists */

inline bool exists_byStat (const std::string& fileName);
inline bool exists_byIO (const std::string& fileName);
inline bool exists_byposixAccess (const std::string& fileName);
bool copyfile(const std::string& fromfileName,const std::string& tofileName );
bool compareFiles(const std::string& p1, const std::string& p2);


#endif // FILEOPERATIONS_H
