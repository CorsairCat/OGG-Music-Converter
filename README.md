# OGG-Music-Converter
A music converter for an DCS World avionic based in-game virtual media player
## Basic Tool 
+ ffmpeg
    * base command: ffmpeg -i in.mp3 -ar 48000 -vn -c:a libvorbis out.ogg
+ TagLib
    * used for control the metadata extract

## Compile guidence
+ install of Taglib
    ```https://github.com/taglib/taglib/blob/master/INSTALL.md```
+ the taglib in the folder is compiled under win10 x64 MSVC 17 2022