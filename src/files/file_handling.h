#include <Arduino.h>
#include "FS.h"
#include <LittleFS.h>


#define FORMAT_LITTLEFS_IF_FAILED true
#define FILE_WRITE "w"
#define FILE_READ "r"
#define FILE_APPEND "a"

void createDir(fs::FS &fs, const char * path);
void removeDir(fs::FS &fs, const char * path);
void readFile(fs::FS &fs, const char * path);
void writeFile(fs::FS &fs, const char * path, const char * message);
void appendFile(fs::FS &fs, const char * path, const char * message);
void renameFile(fs::FS &fs, const char * path1, const char * path2);
void deleteFile(fs::FS &fs, const char * path);