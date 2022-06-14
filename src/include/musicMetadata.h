#include <string>
#include "../taglib/include/taglib/taglib.h"
#include "../taglib/include/taglib/fileref.h"

struct mp3Metadata
{
    std::string file_name;
    std::string music_name;
    std::string artist;
    // in sec
    int length;
    std::string album;
    int year;
};

struct albumData
{
    std::string cover_path;
    std::string album_artist;
};

int storeMetaData(struct mp3Metadata* tempStruct, TagLib::FileRef file);