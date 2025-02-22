#ifndef _OPENCV3_CUDABGSEGM_H_
#define _OPENCV3_CUDABGSEGM_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudabgsegm.hpp>

extern "C" {
#endif

#include "../core.h"
#include "cuda.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::cuda::BackgroundSubtractorMOG2>* CudaBackgroundSubtractorMOG2;
typedef cv::Ptr<cv::cuda::BackgroundSubtractorMOG>* CudaBackgroundSubtractorMOG;
#else
typedef void* CudaBackgroundSubtractorMOG2;
typedef void* CudaBackgroundSubtractorMOG;
#endif

DLL_EXPORT CudaBackgroundSubtractorMOG2 CudaBackgroundSubtractorMOG2_Create();
DLL_EXPORT void CudaBackgroundSubtractorMOG2_Close(CudaBackgroundSubtractorMOG2 b);
DLL_EXPORT void CudaBackgroundSubtractorMOG2_Apply(CudaBackgroundSubtractorMOG2 b, GpuMat src, GpuMat dst, Stream s);

DLL_EXPORT CudaBackgroundSubtractorMOG CudaBackgroundSubtractorMOG_Create();
DLL_EXPORT void CudaBackgroundSubtractorMOG_Close(CudaBackgroundSubtractorMOG b);
DLL_EXPORT void CudaBackgroundSubtractorMOG_Apply(CudaBackgroundSubtractorMOG b, GpuMat src, GpuMat dst, Stream s);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDABGSEGM_H_
