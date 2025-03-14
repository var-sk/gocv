#ifndef _OPENCV3_VIDEOIO_H_
#define _OPENCV3_VIDEOIO_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/videoio/registry.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
typedef cv::VideoCapture* VideoCapture;
typedef cv::VideoWriter* VideoWriter;
#else
typedef void* VideoCapture;
typedef void* VideoWriter;
#endif

// VideoCapture
DLL_EXPORT VideoCapture VideoCapture_New();
DLL_EXPORT void VideoCapture_Close(VideoCapture v);
DLL_EXPORT bool VideoCapture_Open(VideoCapture v, const char* uri);
DLL_EXPORT bool VideoCapture_OpenWithAPI(VideoCapture v, const char* uri, int apiPreference);
DLL_EXPORT bool VideoCapture_OpenWithAPIParams(VideoCapture v, const char* uri, int apiPreference, int *paramsv, int paramsc);
DLL_EXPORT bool VideoCapture_OpenDevice(VideoCapture v, int device);
DLL_EXPORT bool VideoCapture_OpenDeviceWithAPI(VideoCapture v, int device, int apiPreference);
DLL_EXPORT bool VideoCapture_OpenDeviceWithAPIParams(VideoCapture v, int device, int apiPreference, int *paramsv, int paramsc);
DLL_EXPORT void VideoCapture_Set(VideoCapture v, int prop, double param);
DLL_EXPORT double VideoCapture_Get(VideoCapture v, int prop);
DLL_EXPORT int VideoCapture_IsOpened(VideoCapture v);
DLL_EXPORT int VideoCapture_Read(VideoCapture v, Mat buf);
DLL_EXPORT void VideoCapture_Grab(VideoCapture v, int skip);
DLL_EXPORT int VideoCapture_Retrieve(VideoCapture v, Mat buf);

// VideoWriter
DLL_EXPORT VideoWriter VideoWriter_New();
DLL_EXPORT void VideoWriter_Close(VideoWriter vw);
DLL_EXPORT void VideoWriter_Open(VideoWriter vw, const char* name, const char* codec, double fps, int width,
                      int height, bool isColor);
DLL_EXPORT void VideoWriter_OpenWithAPI(VideoWriter vw, const char* name, int apiPreference, const char* codec, double fps,
                      int width, int height, bool isColor);
DLL_EXPORT void VideoWriter_OpenWithAPIParams(VideoWriter vw, const char* name, int apiPreference, const char* codec, double fps,
                      int width, int height, IntVector params);

DLL_EXPORT int VideoWriter_IsOpened(VideoWriter vw);
DLL_EXPORT void VideoWriter_Write(VideoWriter vw, Mat img);

//Videoio Query I/O API backends registry
DLL_EXPORT char* Videoio_Registry_GetBackendName(int api);
DLL_EXPORT IntVector Videio_Registry_GetBackends();
DLL_EXPORT char* Videoio_Registry_GetCameraBackendPluginVersion(int api, int* version_ABI, int* version_API);
DLL_EXPORT IntVector Videoio_Registry_GetCameraBackends();
DLL_EXPORT char* Videoio_Registry_GetStreamBackendPluginVersion(int api, int* version_ABI, int* version_API);
DLL_EXPORT IntVector Videoio_Registry_GetStreamBackends();
DLL_EXPORT char* Videoio_Registry_GetWriterBackendPluginVersion(int api, int* version_ABI, int* version_API);
DLL_EXPORT IntVector Videoio_Registry_GetWriterBackends();
DLL_EXPORT bool Videoio_Registry_HasBackend(int api);
DLL_EXPORT bool Videoio_Registry_IsBackendBuiltIn(int api);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_VIDEOIO_H_
