#include "meta_data_collect.h"

int main()
{
    std::string filename = "../Sample/sample.mp3";
    DCSToolBox::Mp3ID1Tag container;
    int status = DCSToolBox::collectMP3MetaDataResult(filename.c_str(), &container);
}
