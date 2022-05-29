#ifndef _META_DATA_EXTRACT_H
#define _META_DATA_EXTRACT_H

#define _LOAD_METADATA_SUCCESS_ 1
#define _LOAD_METADATE_FAIL_ 0

#include <stdlib.h>

#include <iostream>
#include <string>

namespace DCSToolBox
{

struct Tag4Display
{
    std::string title;
    std::string artist;
    std::string album;
    int year;
};

struct Mp3ID1Tag{
   char tag[3];
   char title[30];
   char artist[30];
   char album[30];
   char year[4];
   char comment[30];
   unsigned char genre;
};

int collectMP3MetaDataResult(const char* file_name, Mp3ID1Tag* tag_buffer)
{
    std::cout << "Trying to load mp3 file: " << file_name << "\n\r";
    // use c style file read tool
    FILE *fp = fopen(file_name, "rb");
	if (!fp)
	{
		std::cout << "Error: File open failed" << "\n\r";
		return _LOAD_METADATE_FAIL_;
	}

	// Seek to 128 bytes before the end of the file
	if (fseek(fp, -1 * sizeof(Mp3ID1Tag), SEEK_END) == -1)
	{
        std::cout << "Error: Can't find END" << "\n\r";
		return _LOAD_METADATE_FAIL_;
	}

	// Read the tag
	if (fread(tag_buffer, sizeof(Mp3ID1Tag), 1, fp) != 1)
	{
		std::cout << "Error: Failed reading tag" << "\n\r";
		return _LOAD_METADATE_FAIL_;
	}

	if (memcmp(tag_buffer->tag, "TAG", 3) == 0)
	{
        return _LOAD_METADATA_SUCCESS_;
	}
	else
	{
		fprintf(stderr, "Error: TAG Undefined\n");
		return _LOAD_METADATE_FAIL_;
	}
}

int printCollectedMetaData(Tag4Display tag_buffer)
{
    std::cout << "Title: " << tag_buffer.title << "\n\r";
    std::cout << "Artist: " << tag_buffer.artist << "\n\r";
    std::cout << "Album: " << tag_buffer.album << "\n\r";
    std::cout << "Year: " << tag_buffer.year << "\n\r";
    return 0;
}

}

#endif