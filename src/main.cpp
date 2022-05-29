#include "meta_data_collect.h"

int main()
{
    std::string filename = "../Sample/朴树-平凡之路.mp3";
    DCSToolBox::Mp3ID1Tag container;
    int status = DCSToolBox::collectMP3MetaDataResult(filename.c_str(), &container);
    DCSToolBox::Tag4Display metaData;
    if (status == _LOAD_METADATE_FAIL_)
    {
        // use the direct file name
        metaData.title = filename;
        metaData.artist = "unknow";
        metaData.album = "unknow";
        metaData.year = 2000;
    }
    else
    {
        metaData.title.assign(container.title, 30);
        metaData.artist.assign(container.artist, 30);
        metaData.album.assign(container.album, 30);
        metaData.year = ((int)container.year[0]-48) * 1000 + ((int)container.year[1]-48) * 100 + ((int)container.year[2]-48) * 10 + ((int)container.year[3]-48);
    }

    DCSToolBox::printCollectedMetaData(metaData);
    return 1;
}
