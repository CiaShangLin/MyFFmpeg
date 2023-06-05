# MyFFmpeg

記錄一下自己編譯ffmpeg然後放在Android裡面跑

編譯環境
mac cpu=intel

ndk 21.4.7075529
https://github.com/android/ndk/wiki/Unsupported-Downloads

ffmpeg 4.4
https://github.com/FFmpeg/FFmpeg/tree/release/4.4


configure修改和build_android.sh看下面這篇
https://juejin.cn/post/6844904103470956557

CMakeList.txt編寫看這篇
https://cloud.tencent.com/developer/article/1773965

其他的結構位置跟本專案一樣配置就可
特別注意:FFmpeg編譯出來的include資料夾放在cpp這層
so放在自己創立的jniLibs還要再加上arm64-v8a架構資料夾的名稱


