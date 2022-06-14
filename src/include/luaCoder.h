#ifndef _LUA_CODER_H
#define _LUA_CODER_H

#include <string>
#include "musicMetadata.h"

int writeSdefConfig(const char* filepath, struct mp3Metadata *tempStruct);
// is signal will ask the write playlist to export the end struct or start struct of the lua config
// 1 is start, 2 is end, 0 is data lines
int writePlayListConfig(struct mp3Metadata *tempStruct, int isSignal);

#endif