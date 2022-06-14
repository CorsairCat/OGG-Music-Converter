# OGG 音乐转换器
+ 这是 DCS-World MOD 航电MP3 的配套用户软件
+ 这个音乐转换器能自动化转换MP3音乐到OGG格式并生成对应的lua/sdef配置文件
+ 相关的 航电 lua 脚本/该软件源码 在 https://github.com/CorsairCat/OGG-Music-Converter 可以找到
 
## 使用说明
+ 将 .mp3 音乐文件复制到 ```inputMusic``` 文件夹
+ 运行主文件夹中的 ogg_converter.exe 程序
+ 一个 cmd/终端 窗口会被启动
+ 等待执行完成
+ 复制 ```Output/Sounds``` 文件夹到 ```<你的mod文件夹>/Sounds``` 文件夹
+ 复制 ```Output/configxxx.lua``` 文件到 ```<你的mod文件夹>/Cockpit/Config``` 文件夹

## License

+ This software uses code of <a href=http://ffmpeg.org>FFmpeg</a> licensed under the <a href=http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>LGPLv2.1</a> and its source can be downloaded <a href=https://github.com/CorsairCat/OGG-Music-Converter>here</a>
+ FFmpeg is a trademark of Fabrice Bellard, originator of the FFmpeg project.
+ This software uses code of <a href=https://taglib.org>TagLib</a> licensed under the <a href=http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>LGPLv2.1</a> and its source can be downloaded <a href=https://github.com/CorsairCat/OGG-Music-Converter>here</a>
+ TagLib is a library for reading and editing the metadata of several popular audio formats. 
[LGPL2.1 © Corsaircat](LICENSE)