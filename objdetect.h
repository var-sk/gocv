#ifndef _OPENCV3_OBJDETECT_H_
#define _OPENCV3_OBJDETECT_H_

#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"

#ifdef __cplusplus
//typedef cv::CascadeClassifier* CascadeClassifier;
//typedef cv::HOGDescriptor* HOGDescriptor;
typedef cv::QRCodeDetector* QRCodeDetector;
typedef cv::Ptr<cv::FaceDetectorYN>* FaceDetectorYN;
typedef cv::Ptr<cv::FaceRecognizerSF>* FaceRecognizerSF;
#else
typedef void* CascadeClassifier;
typedef void* HOGDescriptor;
typedef void* QRCodeDetector;
typedef void* FaceDetectorYN;
typedef void* FaceRecognizerSF;
#endif

// CascadeClassifier
/*DLL_EXPORT CascadeClassifier CascadeClassifier_New();
DLL_EXPORT void CascadeClassifier_Close(CascadeClassifier cs);
DLL_EXPORT int CascadeClassifier_Load(CascadeClassifier cs, const char* name);
DLL_EXPORT struct Rects CascadeClassifier_DetectMultiScale(CascadeClassifier cs, Mat img);
DLL_EXPORT struct Rects CascadeClassifier_DetectMultiScaleWithParams(CascadeClassifier cs, Mat img,
        double scale, int minNeighbors, int flags, Size minSize, Size maxSize);

DLL_EXPORT HOGDescriptor HOGDescriptor_New();
DLL_EXPORT void HOGDescriptor_Close(HOGDescriptor hog);
DLL_EXPORT int HOGDescriptor_Load(HOGDescriptor hog, const char* name);
DLL_EXPORT struct Rects HOGDescriptor_DetectMultiScale(HOGDescriptor hog, Mat img);
DLL_EXPORT struct Rects HOGDescriptor_DetectMultiScaleWithParams(HOGDescriptor hog, Mat img,
        double hitThresh, Size winStride, Size padding, double scale, double finalThreshold,
        bool useMeanshiftGrouping);
DLL_EXPORT Mat HOG_GetDefaultPeopleDetector();
DLL_EXPORT void HOGDescriptor_SetSVMDetector(HOGDescriptor hog, Mat det);

DLL_EXPORT struct Rects GroupRectangles(struct Rects rects, int groupThreshold, double eps);*/

DLL_EXPORT QRCodeDetector QRCodeDetector_New();
DLL_EXPORT const char* QRCodeDetector_DetectAndDecode(QRCodeDetector qr, Mat input,Mat points,Mat straight_qrcode);
DLL_EXPORT bool QRCodeDetector_Detect(QRCodeDetector qr, Mat input,Mat points);
DLL_EXPORT const char* QRCodeDetector_Decode(QRCodeDetector qr, Mat input,Mat inputPoints,Mat straight_qrcode);
DLL_EXPORT void QRCodeDetector_Close(QRCodeDetector qr);
DLL_EXPORT bool QRCodeDetector_DetectMulti(QRCodeDetector qr, Mat input, Mat points);
DLL_EXPORT bool QRCodeDetector_DetectAndDecodeMulti(QRCodeDetector qr, Mat input, CStrings* decoded ,Mat points, struct Mats* mats);

// FaceDetectorYN
FaceDetectorYN FaceDetectorYN_Create(const char* model, const char* config, Size size);
FaceDetectorYN FaceDetectorYN_Create_WithParams(const char* model, const char* config, Size size, float score_threshold, float mms_threshold, int top_k, int backend_id, int target_id);
FaceDetectorYN FaceDetectorYN_Create_FromBytes(const char* framework, void* bufferModel, int model_size, void* bufferConfig, int config_size, Size size);
FaceDetectorYN FaceDetectorYN_Create_FromBytes_WithParams(const char* framework, void* bufferModel, int model_size, void* bufferConfig, int config_size, Size size, float score_threshold, float mms_threshold, int top_k, int backend_id, int target_id);
void FaceDetectorYN_Close(FaceDetectorYN fd); 
int FaceDetectorYN_Detect(FaceDetectorYN fd, Mat image, Mat faces);
Size FaceDetectorYN_GetInputSize(FaceDetectorYN fd);
float FaceDetectorYN_GetNMSThreshold(FaceDetectorYN fd);
float FaceDetectorYN_GetScoreThreshold(FaceDetectorYN fd);
int FaceDetectorYN_GetTopK(FaceDetectorYN fd);
void FaceDetectorYN_SetInputSize(FaceDetectorYN fd, Size input_size);
void FaceDetectorYN_SetNMSThreshold(FaceDetectorYN fd, float nms_threshold);
void FaceDetectorYN_SetScoreThreshold(FaceDetectorYN fd, float score_threshold);
void FaceDetectorYN_SetTopK(FaceDetectorYN fd, int top_k);

// FaceRecognizerSF
FaceRecognizerSF FaceRecognizerSF_Create(const char* model, const char* config);
FaceRecognizerSF FaceRecognizerSF_Create_WithParams(const char* model, const char* config, int backend_id, int target_id);
void FaceRecognizerSF_Close(FaceRecognizerSF fr);
void FaceRecognizerSF_AlignCrop(FaceRecognizerSF fr, Mat src_img, Mat face_box, Mat aligned_img);
void FaceRecognizerSF_Feature(FaceRecognizerSF fr, Mat aligned_img, Mat face_feature);
float FaceRecognizerSF_Match(FaceRecognizerSF fr, Mat face_feature1, Mat face_feature2);
float FaceRecognizerSF_Match_WithParams(FaceRecognizerSF fr, Mat face_feature1, Mat face_feature2, int dis_type);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_OBJDETECT_H_
