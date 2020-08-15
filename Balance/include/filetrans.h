#ifndef _FILE_TRANS_H_
#define _FILE_TRANS_H_

#include "hncdatatype.h"

const unsigned int MAX_DISPLAY_NUM = 512;
const unsigned int MAX_LINE_SIZE = 128;
const unsigned int MAX_PATH_LENGTH = 256;

HNCAPI int UploadFile(const char * remotepath, const char * localpath, const char *ipaddr);
HNCAPI int DownloadFile(const char * remotepath, const char * localpath, const char *ipaddr);
HNCAPI int GetDirInfo(const char *remotepath, const char *ipaddr, char *info);
HNCAPI int RemoveFile(const char *remotepath, const char *ipaddr);
HNCAPI int RenameFile(const char *remotepath, const char *newname, const char *ipaddr);

#endif

