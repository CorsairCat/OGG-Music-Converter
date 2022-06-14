#define TAGLIB_STATIC
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include "include/musicMetadata.h"
#include "include/formatConvert.h"
#include "include/cmdExecuteProxy.h"
#include "../taglib/include/taglib/taglib.h"
#include "../taglib/include/taglib/fileref.h"
#include "../taglib/include/taglib/tfile.h"
#include "../taglib/include/taglib/tiostream.h"
#pragma comment(lib, "tag.lib")

int main()
{
    std::cout << "Music Converter auto start:" << std::endl;
    std::cout << "Note: Dont worry too much if the console export is wrong" << std::endl;
    std::string folder_path = "../Sample/";
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
        printf( "Listing of .mp3 files:\n\r" );
        //create folder
        convert_command = "mkdir ..\\Output\\Sounds\\MP3Player\\Effect";
        ExecuteCmd(convert_command.c_str(), strList);
        convert_command = "mkdir ..\\Output\\Sounds\\MP3Player\\sdef";
        ExecuteCmd(convert_command.c_str(), strList);

        do {
            std::string temp(c_file.name);
            file_path_buffer = folder_path + temp;
            // output the files located in current folder
            printf( " %-12s %9ld\n", c_file.name, c_file.size);
            // use taglib to extract the files
            TagLib::FileRef f(file_path_buffer.c_str());
            if (f != NULL)
            {
                metadata_store.file_name = ANSItoUTF8(c_file.name.c_str());
                //storeMetaData(&metadata_store, f);
            }
            std::cout << "Music Length is " << file.audioProperties()->lengthInSeconds() << " Sec" << std::endl;
                        
            // output the result file using utf8
            std::cout << "Music Title is " << UTF8toANSI(f.tag()->title().toCString(true)) << std::endl;
            std::cout << "Artist is " << UTF8toANSI(artist.toCString(true)) << std::endl;
            // start using the cmd to execute the ffmpeg here
            convert_command = "ffmpeg -i ../Sample/" + temp + " -ar 48000 -vn -c:a libvorbis ../output/Sounds/Effect/";
            convert_command = convert_command + temp.replace(temp.find(".mp3"), 4, ".ogg");
            std::cout << "Execute Command: " << convert_command << std::endl;
            ExecuteCmd(convert_command.c_str(), strList);
            std::cout << "\n\r converted to ogg" << std::endl;
        } while( _findnext( hFile, &c_file ) == 0 );
        _findclose( hFile );
    }
    std::cout << "Press any key to exit" << std::endl;
    std::cin.get();
    return 1;
}
