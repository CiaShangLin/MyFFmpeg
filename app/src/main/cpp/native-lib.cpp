#include <jni.h>
#include <string>




//要包在Ｃ裡面才可以使用,連include都要放在裡面
extern "C" {

#include "libavcodec/avcodec.h"

JNIEXPORT jstring JNICALL
Java_com_example_myffmpeg_Jni_ffmpegInfo(JNIEnv *env, jclass clazz) {


    char info[40000] = {0};
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL) {
        if (c_temp->decode != NULL) {
            sprintf(info, "%sdecode:", info);
        } else {
            sprintf(info, "%sencode:", info);
        }
        switch (c_temp->type) {
            case AVMEDIA_TYPE_VIDEO:
                sprintf(info, "%s(video):", info);
                break;
            case AVMEDIA_TYPE_AUDIO:
                sprintf(info, "%s(audio):", info);
                break;
            default:
                sprintf(info, "%s(other):", info);
                break;
        }
        sprintf(info, "%s[%s]\n", info, c_temp->name);
        c_temp = c_temp->next;
    }

    return env->NewStringUTF(info);
}
}
