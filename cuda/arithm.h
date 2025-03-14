#ifndef _OPENCV3_CUDA_ARITHM_H_
#define _OPENCV3_CUDA_ARITHM_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/cudaarithm.hpp>
extern "C" {
#endif
#include "cuda.h"

#ifdef __cplusplus
typedef cv::Ptr< cv::cuda::LookUpTable >* LookUpTable;
#else
typedef void* LookUpTable;
#endif

DLL_EXPORT void GpuAbs(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuAbsDiff(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuAdd(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuBitwiseAnd(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuBitwiseNot(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuBitwiseOr(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuBitwiseXor(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuDivide(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuExp(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuLog(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuMax(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuMin(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuMultiply(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuSqr(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuSqrt(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuSubtract(GpuMat src1, GpuMat src2, GpuMat dst, Stream s);
DLL_EXPORT void GpuThreshold(GpuMat src, GpuMat dst, double thresh, double maxval, int typ, Stream s);
DLL_EXPORT void GpuFlip(GpuMat src, GpuMat dst, int flipCode, Stream s);
DLL_EXPORT void GpuMerge(struct GpuMats mats, GpuMat dst, Stream s);
DLL_EXPORT void GpuTranspose(GpuMat src, GpuMat dst, Stream s);
DLL_EXPORT void GpuAddWeighted(GpuMat src1, double alpha, GpuMat src2, double beta, double gamma, GpuMat dst, int dType, Stream s);
DLL_EXPORT void GpuCopyMakeBorder(GpuMat src, GpuMat dst, int top, int bottom, int left, int right, int borderType, Scalar value, Stream s);

//LookUpTable
DLL_EXPORT LookUpTable Cuda_Create_LookUpTable(GpuMat lut);
DLL_EXPORT void Cuda_LookUpTable_Close(LookUpTable lt);
DLL_EXPORT void Cuda_LookUpTable_Transform(LookUpTable lt, GpuMat src, GpuMat dst, Stream s);

DLL_EXPORT bool Cuda_LookUpTable_Empty(LookUpTable lut);

DLL_EXPORT void Cuda_Split(GpuMat src, GpuMats dst, Stream s);
#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_CUDA_ARITHM_H_
