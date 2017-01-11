/*
 * jni.cpp
 *
 *  Created on: 2015
 *  Author: kongdeming
 */

#include <jni.h>
#include <stddef.h>


#define GONGJIA_TEST
#ifdef GONGJIA_TEST //ANDROID
#include <android/log.h>
#define LOG_TAG 	"recoderJNI"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__) 
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__) 
#else
#define LOGI(...) printf
#define LOGE(...) printf
#endif


static const char *RECORDER_CLASS_NAME =
		"com/kuaipai/fangyan/core/shooting/jni/RecorderJni";


static JavaVM* jvm = NULL;
static jobject obj = NULL;




jstring sztoJstring(JNIEnv* env, const char* str)
{
  jclass strClass = (*env)->FindClass(env,"java/lang/String");
  jmethodID ctorID = (*env)->GetMethodID(env,strClass, "<init>", "([BLjava/lang/String;)V");
  jbyteArray bytes = (*env)->NewByteArray(env,strlen(str));
  (*env)->SetByteArrayRegion(env,bytes, 0, strlen(str), (jbyte*)str);
  jstring encoding = (*env)->NewStringUTF(env,"utf-8");
  return (jstring)(*env)->NewObject(env,strClass, ctorID, bytes, encoding);
}


static jint Mp4_Recorder_do_faststart(JNIEnv *env, jobject thiz, jstring inPath, jstring outPath)
{

	const char* psrcpath = (*env)->GetStringUTFChars(env, inPath, NULL );
	const char* pdstpath = (*env)->GetStringUTFChars(env, outPath, NULL );
	
	LOGE("[gdebug %s, %d] psrcpath= %p-%s\n",__FUNCTION__, __LINE__,psrcpath, psrcpath); 	
	LOGE("[gdebug %s, %d] pdstpath= %p-%s\n",__FUNCTION__, __LINE__,pdstpath, pdstpath);
	
	
	//jint res = FYRecorder_do_faststart(psrcpath, "/sdcard/out.mp4");
	jint res = FYRecorder_do_faststart(psrcpath, pdstpath);
	
	LOGE("[gdebug %s, %d] res = %d\n",__FUNCTION__, __LINE__, res);
	(*env)->ReleaseStringUTFChars(env, inPath, psrcpath);
	(*env)->ReleaseStringUTFChars(env, outPath, pdstpath);
	
	LOGE("[gdebug %s, %d] res2 = %d\n",__FUNCTION__, __LINE__, res);
	return res;
}




static JNINativeMethod gMethods[] = {
    { "Mp4_Recorder_do_faststart","(Ljava/lang/String;Ljava/lang/String;)I",   (void *) Mp4_Recorder_do_faststart},

};


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{

	jvm = vm;
	JNIEnv* env;
	int result = -1;
	if ((*vm)->GetEnv(vm, (void**)&env, JNI_VERSION_1_4) != JNI_OK) {
		//av_log(NULL, AV_LOG_ERROR, "[gdebug %s, %d]. \n",__FUNCTION__, __LINE__);
		LOGE("[gdebug %s, %d] \n",__FUNCTION__, __LINE__);
		return result;
	}
	jclass class = (*env)->FindClass(env, RECORDER_CLASS_NAME);
	if (class == NULL) {
		//av_log(NULL, AV_LOG_ERROR, "[gdebug %s, %d]. \n",__FUNCTION__, __LINE__);
		LOGE("[gdebug %s, %d] \n",__FUNCTION__, __LINE__);
		return result;
	}
	int mothodcount = sizeof(gMethods)/sizeof(JNINativeMethod);
	(*env)->RegisterNatives(env, class, gMethods, mothodcount);
	//av_log(NULL, AV_LOG_ERROR, "[gdebug %s, %d]. \n",__FUNCTION__, __LINE__);
	LOGE("[gdebug %s, %d] \n",__FUNCTION__, __LINE__);
	return JNI_VERSION_1_4;
}






