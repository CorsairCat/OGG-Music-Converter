#include "include/musicMetadata.h"
#include "../taglib/include/taglib/taglib.h"
#include "../taglib/include/taglib/fileref.h"
#include "include/formatConvert.h"

int storeMetaData(struct mp3Metadata* tempStruct, TagLib::FileRef file)
{
    tempStruct->artist = file.tag()->artist().toCString(true);
    if (tempStruct->artist == "")
    {
        tempStruct->artist = ANSItoUTF8("unknow");
    }
    tempStruct->music_name = file.tag()->title().toCString(true);
    if (tempStruct->music_name == "")
    {
        tempStruct->music_name = tempStruct->file_name;
    }
    tempStruct->album = file.tag()->album().toCString(true);
    if (tempStruct->album == "")
    {
        tempStruct->album = ANSItoUTF8("unknow");
    }
    if (file.tag()->year() != 0)
    {
        tempStruct->year = file.tag()->year();
    }
    else
    {
        tempStruct->year = 1970;
    }
    if (file.audioProperties() != NULL)
    {
        tempStruct->length = file.audioProperties()->lengthInSeconds();
    }
    else
    {
        tempStruct->length = 0;
    }
    return 1;
}