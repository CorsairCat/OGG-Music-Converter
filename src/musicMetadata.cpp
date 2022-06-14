#include "include/musicMetadata.h"

int storeMetaData(struct mp3Metadata* tempStruct, TagLib::FileRef file)
{
    std::string temp_tag_string;
    temp_tag_string = file.tag()->artist();
    if (temp_tag_string != NULL)
    {
        tempStruct->artist = temp_tag_string.toCString(true);
    }
    else
    {
        tempStruct->artist = u8"unknow";
    }
    temp_tag_string = file.tag()->title();
    if (temp_tag_string != NULL)
    {
        tempStruct->music_name = temp_tag_string.toCString(true);
    }
    else
    {
        tempStruct->music_name = tempStruct->file_name;
    }
    temp_tag_string = file.tag()->album();
    if (temp_tag_string != NULL)
    {
        tempStruct->album = temp_tag_string.toCString(true);
    }
    else
    {
        tempStruct->album = u8"unknow";
    }
    if (file.tag()->year != 0)
    {
        tempStruct->year = file.tag()->year;
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