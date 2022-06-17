#define TAGLIB_STATIC
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include "include/musicMetadata.h"
#include "include/formatConvert.h"
#include "include/cmdExecuteProxy.h"
#include "include/luaCoder.h"
#include "../taglib/include/taglib/taglib.h"
#include "../taglib/include/taglib/fileref.h"
#include "../taglib/include/taglib/tfile.h"
#include "../taglib/include/taglib/tiostream.h"
#pragma comment(lib, "tag.lib")

int main()
{
    std::cout << "OGG Music Converter V0.1.2:" << std::endl;
    std::cout << "Note: Dont worry if the console export wrong text (its GB2312 Support)" << std::endl;
    std::cout << "Press Anykey to Continue/" << UTF8toANSI("按任意键继续") << std::endl;
    std::cin.get();
    std::string folder_path = "InputMusic/";
    std::string sdef_folder_path = "Output\\Sounds\\MP3Player\\sdef\\";
    std::string finder_path = folder_path + "*.mp3";
    std::string file_path_buffer;
    std::string convert_command;
    TagLib::String temp_tag_string;
    std::list<std::string> strList;
    struct _finddata_t c_file;
    intptr_t hFile;
    struct mp3Metadata metadata_store;

    // Find first .mp3 file in current directory
    if( (hFile = _findfirst( finder_path.c_str(), &c_file )) == -1L )
        printf( "No *.mp3 files in current directory!\n" );
    else
    {
        //printf( "Listing of .mp3 files:\n\r" );
        //create folder
        convert_command = "mkdir Output\\Sounds\\Effects\\MP3Player";
        ExecuteCmd(convert_command.c_str(), strList);
        convert_command = "mkdir Output\\Sounds\\sdef\\MP3Player";
        ExecuteCmd(convert_command.c_str(), strList);
        writePlayListConfig(&metadata_store, 1);
        
        do {
            std::string temp(c_file.name);
            file_path_buffer = folder_path + temp;
            std::string filenamewt(c_file.name);
            filenamewt.replace(filenamewt.find(".mp3"),4,"");
            // output the files located in current folder
            printf( " %-12s %9ld\n", c_file.name, c_file.size);
            // use taglib to extract the files
            TagLib::FileRef f(file_path_buffer.c_str());
            if( f.audioProperties() != NULL )
            {
                metadata_store.file_name = ANSItoUTF8(filenamewt.c_str());
                storeMetaData(&metadata_store, f);
                // output the result file using utf8
                std::cout << "Music Title is " << UTF8toANSI(f.tag()->title().toCString(true)) << std::endl;
                std::cout << "Artist is " << UTF8toANSI(f.tag()->artist().toCString(true)) << std::endl;
                std::cout << "Music Length is " << f.audioProperties()->lengthInSeconds() << " Sec" << std::endl;
                sdef_folder_path = "Output\\Sounds\\sdef\\MP3Player\\" + temp;
                writeSdefConfig(sdef_folder_path.c_str(), &metadata_store);
                // start using the cmd to execute the ffmpeg here
                convert_command = "\"\"bin\\ffmpeg\" -i \"" + folder_path + temp + "\" -ar 48000 -vn -c:a libvorbis \"output/Sounds/Effects/MP3Player/";
                convert_command = convert_command + temp.replace(temp.find(".mp3"), 4, ".ogg") + "\"\"";
                std::cout << "Execute Command: " << convert_command << std::endl;
                ExecuteCmd(convert_command.c_str(), strList);
                std::cout << "\n\r converted to ogg" << std::endl;
                writePlayListConfig(&metadata_store, 0);
            }
        } while( _findnext( hFile, &c_file ) == 0 );
        _findclose( hFile );
    }
    std::cout << "Press any key to exit" << std::endl;
    std::cin.get();
    return 1;
}
