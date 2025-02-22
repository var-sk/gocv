#ifndef _OPENCV3_FACE_H_
#define _OPENCV3_FACE_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::face::LBPHFaceRecognizer>* LBPHFaceRecognizer;
#else
typedef void* LBPHFaceRecognizer;
#endif

struct PredictResponse {
    int label;
    double confidence;
};

DLL_EXPORT LBPHFaceRecognizer CreateLBPHFaceRecognizer();
DLL_EXPORT void LBPHFaceRecognizer_Train(LBPHFaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT void LBPHFaceRecognizer_Update(LBPHFaceRecognizer fr, Mats images, IntVector labels);
DLL_EXPORT int LBPHFaceRecognizer_Predict(LBPHFaceRecognizer fr, Mat sample);
DLL_EXPORT struct PredictResponse LBPHFaceRecognizer_PredictExtended(LBPHFaceRecognizer fr, Mat sample);
DLL_EXPORT void LBPHFaceRecognizer_SetThreshold(LBPHFaceRecognizer fr, double threshold);
DLL_EXPORT void LBPHFaceRecognizer_SetRadius(LBPHFaceRecognizer fr, int radius);
DLL_EXPORT void LBPHFaceRecognizer_SetNeighbors(LBPHFaceRecognizer fr, int neighbors);
DLL_EXPORT void LBPHFaceRecognizer_SaveFile(LBPHFaceRecognizer fr, const char*  filename);
DLL_EXPORT void LBPHFaceRecognizer_LoadFile(LBPHFaceRecognizer fr, const char*  filename);
DLL_EXPORT int LBPHFaceRecognizer_GetNeighbors(LBPHFaceRecognizer fr);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FACE_H_
