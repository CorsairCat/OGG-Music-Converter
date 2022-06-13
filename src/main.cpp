#define TAGLIB_STATIC
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include "musicMetadata.h"
#include "formatConvert.h"
#include "../taglib/include/taglib/taglib.h"
#include "../taglib/include/taglib/fileref.h"
#include "../taglib/include/taglib/tfile.h"
#include "../taglib/include/taglib/tiostream.h"
#pragma comment(lib, "tag.lib")

int main()
{
    std::cout << "Converter auto start:" << std::endl;
    std::string folder_path = "../Sample/";
    std::string finder_path = folder_path + "*.mp3";
    std::string file_path_buffer;
    struct _finddata_t c_file;
    intptr_t hFile;

    // Find first .c file in current directory
    if( (hFile = _findfirst( finder_path.c_str(), &c_file )) == -1L )
        printf( "No *.exe files in current directory!\n" );
    else
    {
        printf( "Listing of .mp3 files:\n\r" );
        do {
            std::string temp(c_file.name);
            file_path_buffer = folder_path + temp;
            printf( " %-12s %9ld\n", c_file.name, c_file.size);
            TagLib::FileRef f(file_path_buffer.c_str());
            TagLib::String artist = f.tag()->artist();
            std::cout << "Artist string type is " << UTF8toANSI(f.tag()->title().toCString(true)) << std::endl;
            std::cout << "Artist is " << UTF8toANSI(artist.toCString(true)) << std::endl;
        } while( _findnext( hFile, &c_file ) == 0 );
        _findclose( hFile );
    }
    std::cout << "Press any key to exit" << std::endl;
    std::cin.get();
    return 1;
}
