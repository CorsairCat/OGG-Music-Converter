#include <iostream>
#include <fstream>
#include "include/formatConvert.h"
#include "include/musicMetadata.h"

int writeSdefConfig(const char* filepath, struct mp3Metadata *tempStruct)
{
    std::string file_path_str(filepath);
    
    // 以写模式打开文件
    std::ofstream outfile;
    outfile.open(file_path_str.replace(file_path_str.find(".mp3"), 4, ".sdef"));
    
    // write to the file
    outfile << ANSItoUTF8("wave = \"MP3Player/") << tempStruct->file_name;

    outfile << ANSItoUTF8("\" \n\rinner_radius = 100 \n\router_radius = 100 \n\rposition = {0.0, 0.0, 0.0} \n\rgain = 1");
    
    // close files
    outfile.close();
        
    return 0;
}

int writePlayListConfig(struct mp3Metadata *tempStruct, int isSignal)
{
    std::ofstream outfile;
    switch (isSignal)
    {
    case 1:
        outfile.open("..\\Output\\MusicPlayerConfig.lua", std::ios::trunc);
        outfile << ANSItoUTF8("MusicPlayerList = {}") << std::endl;
        break;
    case 2:
        outfile.open("..\\Output\\MusicPlayerConfig.lua", std::ios::app);
        break;
    default:
        outfile.open("..\\Output\\MusicPlayerConfig.lua", std::ios::app);
        std::string length_str = std::to_string(tempStruct->length);
        outfile << ANSItoUTF8("MusicPlayerList[#MusicPlayerList+1] = {\"Mp3Player/") << tempStruct->file_name << "\",\"" << tempStruct->music_name << "\",\"" << tempStruct->artist << "\"," << ANSItoUTF8(length_str.c_str()) << "}" << std::endl;
        break;
    }
    outfile.close();
    return 1;
}