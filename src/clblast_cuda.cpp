
// =================================================================================================
// This file is part of the CLBlast project. The project is licensed under Apache Version 2.0. This
// project loosely follows the Google C++ styleguide and uses a tab-size of two spaces and a max-
// width of 100 characters per line.
//
// Author(s):
//   Cedric Nugteren <www.cedricnugteren.nl>
//
// This file implements all the BLAS API calls (CUDA version). In all cases, it does not much more
// than creating a new object of the appropriate type, and calling the main routine on that object.
// It forwards all status codes to the caller.
//
// =================================================================================================

#include <string>

#include "routines/routines.hpp"
#include "clblast_cuda.h"

namespace clblast {

// =================================================================================================
// BLAS level-1 (vector-vector) routines
// =================================================================================================

// Generate givens plane rotation: SROTG/DROTG
template <typename T>
StatusCode Rotg(CUdeviceptr, const size_t,
                CUdeviceptr, const size_t,
                CUdeviceptr, const size_t,
                CUdeviceptr, const size_t,
                const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Rotg<float>(CUdeviceptr, const size_t,
                                           CUdeviceptr, const size_t,
                                           CUdeviceptr, const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Rotg<double>(CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);

// Generate modified givens plane rotation: SROTMG/DROTMG
template <typename T>
StatusCode Rotmg(CUdeviceptr, const size_t,
                 CUdeviceptr, const size_t,
                 CUdeviceptr, const size_t,
                 const CUdeviceptr, const size_t,
                 CUdeviceptr, const size_t,
                 const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Rotmg<float>(CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Rotmg<double>(CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUcontext, const CUdevice);

// Apply givens plane rotation: SROT/DROT
template <typename T>
StatusCode Rot(const size_t,
               CUdeviceptr, const size_t, const size_t,
               CUdeviceptr, const size_t, const size_t,
               const T,
               const T,
               const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Rot<float>(const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const float,
                                          const float,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Rot<double>(const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const double,
                                           const double,
                                           const CUcontext, const CUdevice);

// Apply modified givens plane rotation: SROTM/DROTM
template <typename T>
StatusCode Rotm(const size_t,
                CUdeviceptr, const size_t, const size_t,
                CUdeviceptr, const size_t, const size_t,
                CUdeviceptr, const size_t,
                const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Rotm<float>(const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Rotm<double>(const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);

// Swap two vectors: SSWAP/DSWAP/CSWAP/ZSWAP/HSWAP
template <typename T>
StatusCode Swap(const size_t n,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xswap<T>(queue_cpp, nullptr);
    routine.DoSwap(n,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Swap<float>(const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Swap<double>(const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Swap<float2>(const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Swap<double2>(const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Swap<half>(const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Vector scaling: SSCAL/DSCAL/CSCAL/ZSCAL/HSCAL
template <typename T>
StatusCode Scal(const size_t n,
                const T alpha,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xscal<T>(queue_cpp, nullptr);
    routine.DoScal(n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Scal<float>(const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Scal<double>(const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Scal<float2>(const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Scal<double2>(const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Scal<half>(const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Vector copy: SCOPY/DCOPY/CCOPY/ZCOPY/HCOPY
template <typename T>
StatusCode Copy(const size_t n,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xcopy<T>(queue_cpp, nullptr);
    routine.DoCopy(n,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Copy<float>(const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Copy<double>(const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Copy<float2>(const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Copy<double2>(const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Copy<half>(const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Vector-times-constant plus vector: SAXPY/DAXPY/CAXPY/ZAXPY/HAXPY
template <typename T>
StatusCode Axpy(const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xaxpy<T>(queue_cpp, nullptr);
    routine.DoAxpy(n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Axpy<float>(const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Axpy<double>(const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Axpy<float2>(const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Axpy<double2>(const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Axpy<half>(const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Dot product of two vectors: SDOT/DDOT/HDOT
template <typename T>
StatusCode Dot(const size_t n,
               CUdeviceptr dot_buffer, const size_t dot_offset,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xdot<T>(queue_cpp, nullptr);
    routine.DoDot(n,
                  Buffer<T>(dot_buffer), dot_offset,
                  Buffer<T>(x_buffer), x_offset, x_inc,
                  Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Dot<float>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Dot<double>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Dot<half>(const size_t,
                                         CUdeviceptr, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// Dot product of two complex vectors: CDOTU/ZDOTU
template <typename T>
StatusCode Dotu(const size_t n,
                CUdeviceptr dot_buffer, const size_t dot_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xdotu<T>(queue_cpp, nullptr);
    routine.DoDotu(n,
                   Buffer<T>(dot_buffer), dot_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Dotu<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Dotu<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Dot product of two complex vectors, one conjugated: CDOTC/ZDOTC
template <typename T>
StatusCode Dotc(const size_t n,
                CUdeviceptr dot_buffer, const size_t dot_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xdotc<T>(queue_cpp, nullptr);
    routine.DoDotc(n,
                   Buffer<T>(dot_buffer), dot_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Dotc<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Dotc<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Euclidian norm of a vector: SNRM2/DNRM2/ScNRM2/DzNRM2/HNRM2
template <typename T>
StatusCode Nrm2(const size_t n,
                CUdeviceptr nrm2_buffer, const size_t nrm2_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xnrm2<T>(queue_cpp, nullptr);
    routine.DoNrm2(n,
                   Buffer<T>(nrm2_buffer), nrm2_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Nrm2<float>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Nrm2<double>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Nrm2<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Nrm2<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Nrm2<half>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Absolute sum of values in a vector: SASUM/DASUM/ScASUM/DzASUM/HASUM
template <typename T>
StatusCode Asum(const size_t n,
                CUdeviceptr asum_buffer, const size_t asum_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xasum<T>(queue_cpp, nullptr);
    routine.DoAsum(n,
                   Buffer<T>(asum_buffer), asum_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Asum<float>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Asum<double>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Asum<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Asum<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Asum<half>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Sum of values in a vector (non-BLAS function): SSUM/DSUM/ScSUM/DzSUM/HSUM
template <typename T>
StatusCode Sum(const size_t n,
               CUdeviceptr sum_buffer, const size_t sum_offset,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsum<T>(queue_cpp, nullptr);
    routine.DoSum(n,
                  Buffer<T>(sum_buffer), sum_offset,
                  Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Sum<float>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sum<double>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sum<float2>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sum<double2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sum<half>(const size_t,
                                         CUdeviceptr, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// Index of absolute maximum value in a vector: iSAMAX/iDAMAX/iCAMAX/iZAMAX/iHAMAX
template <typename T>
StatusCode Amax(const size_t n,
                CUdeviceptr imax_buffer, const size_t imax_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xamax<T>(queue_cpp, nullptr);
    routine.DoAmax(n,
                   Buffer<unsigned int>(imax_buffer), imax_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Amax<float>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amax<double>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amax<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amax<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amax<half>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Index of absolute minimum value in a vector (non-BLAS function): iSAMIN/iDAMIN/iCAMIN/iZAMIN/iHAMIN
template <typename T>
StatusCode Amin(const size_t n,
                CUdeviceptr imin_buffer, const size_t imin_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xamin<T>(queue_cpp, nullptr);
    routine.DoAmin(n,
                   Buffer<unsigned int>(imin_buffer), imin_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Amin<float>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amin<double>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amin<float2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amin<double2>(const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Amin<half>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Index of maximum value in a vector (non-BLAS function): iSMAX/iDMAX/iCMAX/iZMAX/iHMAX
template <typename T>
StatusCode Max(const size_t n,
               CUdeviceptr imax_buffer, const size_t imax_offset,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xmax<T>(queue_cpp, nullptr);
    routine.DoMax(n,
                  Buffer<unsigned int>(imax_buffer), imax_offset,
                  Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Max<float>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Max<double>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Max<float2>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Max<double2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Max<half>(const size_t,
                                         CUdeviceptr, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// Index of minimum value in a vector (non-BLAS function): iSMIN/iDMIN/iCMIN/iZMIN/iHMIN
template <typename T>
StatusCode Min(const size_t n,
               CUdeviceptr imin_buffer, const size_t imin_offset,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xmin<T>(queue_cpp, nullptr);
    routine.DoMin(n,
                  Buffer<unsigned int>(imin_buffer), imin_offset,
                  Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Min<float>(const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Min<double>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Min<float2>(const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Min<double2>(const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Min<half>(const size_t,
                                         CUdeviceptr, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// =================================================================================================
// BLAS level-2 (matrix-vector) routines
// =================================================================================================

// General matrix-vector multiplication: SGEMV/DGEMV/CGEMV/ZGEMV/HGEMV
template <typename T>
StatusCode Gemv(const Activation actv, const Layout layout, const Transpose a_transpose,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    std::string name;
    switch (actv) {
      case Activation::kTanh:
        name = "ACTV_TANH";
        break;

      case Activation::kSigmoid:
        name = "ACTV_SIGMOID";
        break;

      case Activation::kReLU:
        name = "ACTV_RELU";
        break;

      case Activation::kLeakyReLU:
        name = "ACTV_LEAKYRELU";
        break;

      case Activation::kELU:
        name = "ACTV_ELU";
        break;

      default:
        name = "GEMV";
        break;
    }
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xgemv<T>(queue_cpp, nullptr, name);
    routine.DoGemv(layout, a_transpose,
                   m, n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Gemv<float>(const Activation, const Layout, const Transpose,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gemv<double>(const Activation, const Layout, const Transpose,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gemv<float2>(const Activation, const Layout, const Transpose,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gemv<double2>(const Activation, const Layout, const Transpose,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gemv<half>(const Activation, const Layout, const Transpose,
                                          const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// General banded matrix-vector multiplication: SGBMV/DGBMV/CGBMV/ZGBMV/HGBMV
template <typename T>
StatusCode Gbmv(const Layout layout, const Transpose a_transpose,
                const size_t m, const size_t n, const size_t kl, const size_t ku,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xgbmv<T>(queue_cpp, nullptr);
    routine.DoGbmv(layout, a_transpose,
                   m, n, kl, ku,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Gbmv<float>(const Layout, const Transpose,
                                           const size_t, const size_t, const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gbmv<double>(const Layout, const Transpose,
                                            const size_t, const size_t, const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gbmv<float2>(const Layout, const Transpose,
                                            const size_t, const size_t, const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gbmv<double2>(const Layout, const Transpose,
                                             const size_t, const size_t, const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gbmv<half>(const Layout, const Transpose,
                                          const size_t, const size_t, const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Hermitian matrix-vector multiplication: CHEMV/ZHEMV
template <typename T>
StatusCode Hemv(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhemv<T>(queue_cpp, nullptr);
    routine.DoHemv(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hemv<float2>(const Layout, const Triangle,
                                            const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hemv<double2>(const Layout, const Triangle,
                                             const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Hermitian banded matrix-vector multiplication: CHBMV/ZHBMV
template <typename T>
StatusCode Hbmv(const Layout layout, const Triangle triangle,
                const size_t n, const size_t k,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhbmv<T>(queue_cpp, nullptr);
    routine.DoHbmv(layout, triangle,
                   n, k,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hbmv<float2>(const Layout, const Triangle,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hbmv<double2>(const Layout, const Triangle,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Hermitian packed matrix-vector multiplication: CHPMV/ZHPMV
template <typename T>
StatusCode Hpmv(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr ap_buffer, const size_t ap_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhpmv<T>(queue_cpp, nullptr);
    routine.DoHpmv(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(ap_buffer), ap_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hpmv<float2>(const Layout, const Triangle,
                                            const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hpmv<double2>(const Layout, const Triangle,
                                             const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Symmetric matrix-vector multiplication: SSYMV/DSYMV/HSYMV
template <typename T>
StatusCode Symv(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsymv<T>(queue_cpp, nullptr);
    routine.DoSymv(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Symv<float>(const Layout, const Triangle,
                                           const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symv<double>(const Layout, const Triangle,
                                            const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symv<half>(const Layout, const Triangle,
                                          const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Symmetric banded matrix-vector multiplication: SSBMV/DSBMV/HSBMV
template <typename T>
StatusCode Sbmv(const Layout layout, const Triangle triangle,
                const size_t n, const size_t k,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsbmv<T>(queue_cpp, nullptr);
    routine.DoSbmv(layout, triangle,
                   n, k,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Sbmv<float>(const Layout, const Triangle,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sbmv<double>(const Layout, const Triangle,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Sbmv<half>(const Layout, const Triangle,
                                          const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Symmetric packed matrix-vector multiplication: SSPMV/DSPMV/HSPMV
template <typename T>
StatusCode Spmv(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr ap_buffer, const size_t ap_offset,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const T beta,
                CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xspmv<T>(queue_cpp, nullptr);
    routine.DoSpmv(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(ap_buffer), ap_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   beta,
                   Buffer<T>(y_buffer), y_offset, y_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Spmv<float>(const Layout, const Triangle,
                                           const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spmv<double>(const Layout, const Triangle,
                                            const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spmv<half>(const Layout, const Triangle,
                                          const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Triangular matrix-vector multiplication: STRMV/DTRMV/CTRMV/ZTRMV/HTRMV
template <typename T>
StatusCode Trmv(const Layout layout, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t n,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtrmv<T>(queue_cpp, nullptr);
    routine.DoTrmv(layout, triangle, a_transpose, diagonal,
                   n,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Trmv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmv<half>(const Layout, const Triangle, const Transpose, const Diagonal,
                                          const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Triangular banded matrix-vector multiplication: STBMV/DTBMV/CTBMV/ZTBMV/HTBMV
template <typename T>
StatusCode Tbmv(const Layout layout, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t n, const size_t k,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtbmv<T>(queue_cpp, nullptr);
    routine.DoTbmv(layout, triangle, a_transpose, diagonal,
                   n, k,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Tbmv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbmv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbmv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbmv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbmv<half>(const Layout, const Triangle, const Transpose, const Diagonal,
                                          const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Triangular packed matrix-vector multiplication: STPMV/DTPMV/CTPMV/ZTPMV/HTPMV
template <typename T>
StatusCode Tpmv(const Layout layout, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t n,
                const CUdeviceptr ap_buffer, const size_t ap_offset,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtpmv<T>(queue_cpp, nullptr);
    routine.DoTpmv(layout, triangle, a_transpose, diagonal,
                   n,
                   Buffer<T>(ap_buffer), ap_offset,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Tpmv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t,
                                           const CUdeviceptr, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpmv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpmv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpmv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t,
                                             const CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpmv<half>(const Layout, const Triangle, const Transpose, const Diagonal,
                                          const size_t,
                                          const CUdeviceptr, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Solves a triangular system of equations: STRSV/DTRSV/CTRSV/ZTRSV
template <typename T>
StatusCode Trsv(const Layout layout, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t n,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtrsv<T>(queue_cpp, nullptr);
    routine.DoTrsv(layout, triangle, a_transpose, diagonal,
                   n,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(x_buffer), x_offset, x_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Trsv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Solves a banded triangular system of equations: STBSV/DTBSV/CTBSV/ZTBSV
template <typename T>
StatusCode Tbsv(const Layout, const Triangle, const Transpose, const Diagonal,
                const size_t, const size_t,
                const CUdeviceptr, const size_t, const size_t,
                CUdeviceptr, const size_t, const size_t,
                const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Tbsv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbsv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbsv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tbsv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Solves a packed triangular system of equations: STPSV/DTPSV/CTPSV/ZTPSV
template <typename T>
StatusCode Tpsv(const Layout, const Triangle, const Transpose, const Diagonal,
                const size_t,
                const CUdeviceptr, const size_t,
                CUdeviceptr, const size_t, const size_t,
                const CUcontext, const CUdevice) {
  return StatusCode::kNotImplemented;
}
template StatusCode PUBLIC_API Tpsv<float>(const Layout, const Triangle, const Transpose, const Diagonal,
                                           const size_t,
                                           const CUdeviceptr, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpsv<double>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpsv<float2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                            const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Tpsv<double2>(const Layout, const Triangle, const Transpose, const Diagonal,
                                             const size_t,
                                             const CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// General rank-1 matrix update: SGER/DGER/HGER
template <typename T>
StatusCode Ger(const Layout layout,
               const size_t m, const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
               CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xger<T>(queue_cpp, nullptr);
    routine.DoGer(layout,
                  m, n,
                  alpha,
                  Buffer<T>(x_buffer), x_offset, x_inc,
                  Buffer<T>(y_buffer), y_offset, y_inc,
                  Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Ger<float>(const Layout,
                                          const size_t, const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Ger<double>(const Layout,
                                           const size_t, const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Ger<half>(const Layout,
                                         const size_t, const size_t,
                                         const half,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// General rank-1 complex matrix update: CGERU/ZGERU
template <typename T>
StatusCode Geru(const Layout layout,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xgeru<T>(queue_cpp, nullptr);
    routine.DoGeru(layout,
                   m, n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Geru<float2>(const Layout,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Geru<double2>(const Layout,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// General rank-1 complex conjugated matrix update: CGERC/ZGERC
template <typename T>
StatusCode Gerc(const Layout layout,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xgerc<T>(queue_cpp, nullptr);
    routine.DoGerc(layout,
                   m, n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Gerc<float2>(const Layout,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Gerc<double2>(const Layout,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Hermitian rank-1 matrix update: CHER/ZHER
template <typename T>
StatusCode Her(const Layout layout, const Triangle triangle,
               const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xher<std::complex<T>,T>(queue_cpp, nullptr);
    routine.DoHer(layout, triangle,
                  n,
                  alpha,
                  Buffer<std::complex<T>>(x_buffer), x_offset, x_inc,
                  Buffer<std::complex<T>>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Her<float>(const Layout, const Triangle,
                                          const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Her<double>(const Layout, const Triangle,
                                           const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);

// Hermitian packed rank-1 matrix update: CHPR/ZHPR
template <typename T>
StatusCode Hpr(const Layout layout, const Triangle triangle,
               const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               CUdeviceptr ap_buffer, const size_t ap_offset,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhpr<std::complex<T>,T>(queue_cpp, nullptr);
    routine.DoHpr(layout, triangle,
                  n,
                  alpha,
                  Buffer<std::complex<T>>(x_buffer), x_offset, x_inc,
                  Buffer<std::complex<T>>(ap_buffer), ap_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hpr<float>(const Layout, const Triangle,
                                          const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hpr<double>(const Layout, const Triangle,
                                           const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUcontext, const CUdevice);

// Hermitian rank-2 matrix update: CHER2/ZHER2
template <typename T>
StatusCode Her2(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xher2<T>(queue_cpp, nullptr);
    routine.DoHer2(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Her2<float2>(const Layout, const Triangle,
                                            const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Her2<double2>(const Layout, const Triangle,
                                             const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Hermitian packed rank-2 matrix update: CHPR2/ZHPR2
template <typename T>
StatusCode Hpr2(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr ap_buffer, const size_t ap_offset,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhpr2<T>(queue_cpp, nullptr);
    routine.DoHpr2(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(ap_buffer), ap_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hpr2<float2>(const Layout, const Triangle,
                                            const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hpr2<double2>(const Layout, const Triangle,
                                             const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUcontext, const CUdevice);

// Symmetric rank-1 matrix update: SSYR/DSYR/HSYR
template <typename T>
StatusCode Syr(const Layout layout, const Triangle triangle,
               const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsyr<T>(queue_cpp, nullptr);
    routine.DoSyr(layout, triangle,
                  n,
                  alpha,
                  Buffer<T>(x_buffer), x_offset, x_inc,
                  Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Syr<float>(const Layout, const Triangle,
                                          const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr<double>(const Layout, const Triangle,
                                           const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr<half>(const Layout, const Triangle,
                                         const size_t,
                                         const half,
                                         const CUdeviceptr, const size_t, const size_t,
                                         CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// Symmetric packed rank-1 matrix update: SSPR/DSPR/HSPR
template <typename T>
StatusCode Spr(const Layout layout, const Triangle triangle,
               const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               CUdeviceptr ap_buffer, const size_t ap_offset,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xspr<T>(queue_cpp, nullptr);
    routine.DoSpr(layout, triangle,
                  n,
                  alpha,
                  Buffer<T>(x_buffer), x_offset, x_inc,
                  Buffer<T>(ap_buffer), ap_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Spr<float>(const Layout, const Triangle,
                                          const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spr<double>(const Layout, const Triangle,
                                           const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spr<half>(const Layout, const Triangle,
                                         const size_t,
                                         const half,
                                         const CUdeviceptr, const size_t, const size_t,
                                         CUdeviceptr, const size_t,
                                         const CUcontext, const CUdevice);

// Symmetric rank-2 matrix update: SSYR2/DSYR2/HSYR2
template <typename T>
StatusCode Syr2(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsyr2<T>(queue_cpp, nullptr);
    routine.DoSyr2(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(a_buffer), a_offset, a_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Syr2<float>(const Layout, const Triangle,
                                           const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2<double>(const Layout, const Triangle,
                                            const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2<half>(const Layout, const Triangle,
                                          const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Symmetric packed rank-2 matrix update: SSPR2/DSPR2/HSPR2
template <typename T>
StatusCode Spr2(const Layout layout, const Triangle triangle,
                const size_t n,
                const T alpha,
                const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
                const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
                CUdeviceptr ap_buffer, const size_t ap_offset,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xspr2<T>(queue_cpp, nullptr);
    routine.DoSpr2(layout, triangle,
                   n,
                   alpha,
                   Buffer<T>(x_buffer), x_offset, x_inc,
                   Buffer<T>(y_buffer), y_offset, y_inc,
                   Buffer<T>(ap_buffer), ap_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Spr2<float>(const Layout, const Triangle,
                                           const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spr2<double>(const Layout, const Triangle,
                                            const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Spr2<half>(const Layout, const Triangle,
                                          const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t,
                                          const CUcontext, const CUdevice);

// =================================================================================================
// BLAS level-3 (matrix-matrix) routines
// =================================================================================================

// General matrix-matrix multiplication: SGEMM/DGEMM/CGEMM/ZGEMM/HGEMM
template <typename T>
StatusCode Gemm(const Activation actv, const Layout layout, const Transpose a_transpose, const Transpose b_transpose,
                const size_t m, const size_t n, const size_t k,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                const T beta,
                CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                const CUcontext context, const CUdevice device,
                CUdeviceptr temp_buffer) {
  try {
    std::string name;
    switch (actv) {
      case Activation::kTanh:
        name = "ACTV_TANH";
        break;

      case Activation::kSigmoid:
        name = "ACTV_SIGMOID";
        break;

      case Activation::kReLU:
        name = "ACTV_RELU";
        break;

      case Activation::kLeakyReLU:
        name = "ACTV_LEAKYRELU";
        break;

      case Activation::kELU:
        name = "ACTV_ELU";
        break;

      default:
        name = "GEMM";
        break;
    }
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xgemm<T>(queue_cpp, nullptr, name);
    const auto temp_buffer_provided = temp_buffer != 0;
    auto temp_buffer_cpp = temp_buffer_provided ? Buffer<T>(temp_buffer) : Buffer<T>(0);
    routine.DoGemm(layout, a_transpose, b_transpose,
                   m, n, k,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(b_buffer), b_offset, b_ld,
                   beta,
                   Buffer<T>(c_buffer), c_offset, c_ld,
                   temp_buffer_cpp, temp_buffer_provided);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Gemm<float>(const Activation, const Layout, const Transpose, const Transpose,
                                           const size_t, const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice, CUdeviceptr);
template StatusCode PUBLIC_API Gemm<double>(const Activation, const Layout, const Transpose, const Transpose,
                                            const size_t, const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice, CUdeviceptr);
template StatusCode PUBLIC_API Gemm<float2>(const Activation, const Layout, const Transpose, const Transpose,
                                            const size_t, const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice, CUdeviceptr);
template StatusCode PUBLIC_API Gemm<double2>(const Activation, const Layout, const Transpose, const Transpose,
                                             const size_t, const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice, CUdeviceptr);
template StatusCode PUBLIC_API Gemm<half>(const Activation, const Layout, const Transpose, const Transpose,
                                          const size_t, const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice, CUdeviceptr);

// Symmetric matrix-matrix multiplication: SSYMM/DSYMM/CSYMM/ZSYMM/HSYMM
template <typename T>
StatusCode Symm(const Layout layout, const Side side, const Triangle triangle,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                const T beta,
                CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsymm<T>(queue_cpp, nullptr);
    routine.DoSymm(layout, side, triangle,
                   m, n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(b_buffer), b_offset, b_ld,
                   beta,
                   Buffer<T>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Symm<float>(const Layout, const Side, const Triangle,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symm<double>(const Layout, const Side, const Triangle,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symm<float2>(const Layout, const Side, const Triangle,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symm<double2>(const Layout, const Side, const Triangle,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Symm<half>(const Layout, const Side, const Triangle,
                                          const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Hermitian matrix-matrix multiplication: CHEMM/ZHEMM
template <typename T>
StatusCode Hemm(const Layout layout, const Side side, const Triangle triangle,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                const T beta,
                CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhemm<T>(queue_cpp, nullptr);
    routine.DoHemm(layout, side, triangle,
                   m, n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(b_buffer), b_offset, b_ld,
                   beta,
                   Buffer<T>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Hemm<float2>(const Layout, const Side, const Triangle,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Hemm<double2>(const Layout, const Side, const Triangle,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// Rank-K update of a symmetric matrix: SSYRK/DSYRK/CSYRK/ZSYRK/HSYRK
template <typename T>
StatusCode Syrk(const Layout layout, const Triangle triangle, const Transpose a_transpose,
                const size_t n, const size_t k,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const T beta,
                CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsyrk<T>(queue_cpp, nullptr);
    routine.DoSyrk(layout, triangle, a_transpose,
                   n, k,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   beta,
                   Buffer<T>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Syrk<float>(const Layout, const Triangle, const Transpose,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syrk<double>(const Layout, const Triangle, const Transpose,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syrk<float2>(const Layout, const Triangle, const Transpose,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syrk<double2>(const Layout, const Triangle, const Transpose,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syrk<half>(const Layout, const Triangle, const Transpose,
                                          const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const half,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Rank-K update of a hermitian matrix: CHERK/ZHERK
template <typename T>
StatusCode Herk(const Layout layout, const Triangle triangle, const Transpose a_transpose,
                const size_t n, const size_t k,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                const T beta,
                CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xherk<std::complex<T>,T>(queue_cpp, nullptr);
    routine.DoHerk(layout, triangle, a_transpose,
                   n, k,
                   alpha,
                   Buffer<std::complex<T>>(a_buffer), a_offset, a_ld,
                   beta,
                   Buffer<std::complex<T>>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Herk<float>(const Layout, const Triangle, const Transpose,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Herk<double>(const Layout, const Triangle, const Transpose,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);

// Rank-2K update of a symmetric matrix: SSYR2K/DSYR2K/CSYR2K/ZSYR2K/HSYR2K
template <typename T>
StatusCode Syr2k(const Layout layout, const Triangle triangle, const Transpose ab_transpose,
                 const size_t n, const size_t k,
                 const T alpha,
                 const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                 const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                 const T beta,
                 CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                 const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xsyr2k<T>(queue_cpp, nullptr);
    routine.DoSyr2k(layout, triangle, ab_transpose,
                    n, k,
                    alpha,
                    Buffer<T>(a_buffer), a_offset, a_ld,
                    Buffer<T>(b_buffer), b_offset, b_ld,
                    beta,
                    Buffer<T>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Syr2k<float>(const Layout, const Triangle, const Transpose,
                                            const size_t, const size_t,
                                            const float,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const float,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2k<double>(const Layout, const Triangle, const Transpose,
                                             const size_t, const size_t,
                                             const double,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const double,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2k<float2>(const Layout, const Triangle, const Transpose,
                                             const size_t, const size_t,
                                             const float2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const CUdeviceptr, const size_t, const size_t,
                                             const float2,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2k<double2>(const Layout, const Triangle, const Transpose,
                                              const size_t, const size_t,
                                              const double2,
                                              const CUdeviceptr, const size_t, const size_t,
                                              const CUdeviceptr, const size_t, const size_t,
                                              const double2,
                                              CUdeviceptr, const size_t, const size_t,
                                              const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Syr2k<half>(const Layout, const Triangle, const Transpose,
                                           const size_t, const size_t,
                                           const half,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const half,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);

// Rank-2K update of a hermitian matrix: CHER2K/ZHER2K
template <typename T, typename U>
StatusCode Her2k(const Layout layout, const Triangle triangle, const Transpose ab_transpose,
                 const size_t n, const size_t k,
                 const T alpha,
                 const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                 const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                 const U beta,
                 CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld,
                 const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xher2k<T,U>(queue_cpp, nullptr);
    routine.DoHer2k(layout, triangle, ab_transpose,
                    n, k,
                    alpha,
                    Buffer<T>(a_buffer), a_offset, a_ld,
                    Buffer<T>(b_buffer), b_offset, b_ld,
                    beta,
                    Buffer<T>(c_buffer), c_offset, c_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Her2k<float2,float>(const Layout, const Triangle, const Transpose,
                                                   const size_t, const size_t,
                                                   const float2,
                                                   const CUdeviceptr, const size_t, const size_t,
                                                   const CUdeviceptr, const size_t, const size_t,
                                                   const float,
                                                   CUdeviceptr, const size_t, const size_t,
                                                   const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Her2k<double2,double>(const Layout, const Triangle, const Transpose,
                                                     const size_t, const size_t,
                                                     const double2,
                                                     const CUdeviceptr, const size_t, const size_t,
                                                     const CUdeviceptr, const size_t, const size_t,
                                                     const double,
                                                     CUdeviceptr, const size_t, const size_t,
                                                     const CUcontext, const CUdevice);

// Triangular matrix-matrix multiplication: STRMM/DTRMM/CTRMM/ZTRMM/HTRMM
template <typename T>
StatusCode Trmm(const Layout layout, const Side side, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtrmm<T>(queue_cpp, nullptr);
    routine.DoTrmm(layout, side, triangle, a_transpose, diagonal,
                   m, n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(b_buffer), b_offset, b_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Trmm<float>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmm<double>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmm<float2>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmm<double2>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trmm<half>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                          const size_t, const size_t,
                                          const half,
                                          const CUdeviceptr, const size_t, const size_t,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);

// Solves a triangular system of equations: STRSM/DTRSM/CTRSM/ZTRSM
template <typename T>
StatusCode Trsm(const Layout layout, const Side side, const Triangle triangle, const Transpose a_transpose, const Diagonal diagonal,
                const size_t m, const size_t n,
                const T alpha,
                const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xtrsm<T>(queue_cpp, nullptr);
    routine.DoTrsm(layout, side, triangle, a_transpose, diagonal,
                   m, n,
                   alpha,
                   Buffer<T>(a_buffer), a_offset, a_ld,
                   Buffer<T>(b_buffer), b_offset, b_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Trsm<float>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                           const size_t, const size_t,
                                           const float,
                                           const CUdeviceptr, const size_t, const size_t,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsm<double>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const double,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsm<float2>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                            const size_t, const size_t,
                                            const float2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Trsm<double2>(const Layout, const Side, const Triangle, const Transpose, const Diagonal,
                                             const size_t, const size_t,
                                             const double2,
                                             const CUdeviceptr, const size_t, const size_t,
                                             CUdeviceptr, const size_t, const size_t,
                                             const CUcontext, const CUdevice);

// =================================================================================================
// Extra non-BLAS routines (level-X)
// =================================================================================================

// Element-wise vector product (Hadamard): SHAD/DHAD/CHAD/ZHAD/HHAD
template <typename T>
StatusCode Had(const size_t n,
               const T alpha,
               const CUdeviceptr x_buffer, const size_t x_offset, const size_t x_inc,
               const CUdeviceptr y_buffer, const size_t y_offset, const size_t y_inc,
               const T beta,
               CUdeviceptr z_buffer, const size_t z_offset, const size_t z_inc,
               const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xhad<T>(queue_cpp, nullptr);
    routine.DoHad(n,
                  alpha,
                  Buffer<T>(x_buffer), x_offset, x_inc,
                  Buffer<T>(y_buffer), y_offset, y_inc,
                  beta,
                  Buffer<T>(z_buffer), z_offset, z_inc);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Had<float>(const size_t,
                                          const float,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const CUdeviceptr, const size_t, const size_t,
                                          const float,
                                          CUdeviceptr, const size_t, const size_t,
                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Had<double>(const size_t,
                                           const double,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const double,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Had<float2>(const size_t,
                                           const float2,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const CUdeviceptr, const size_t, const size_t,
                                           const float2,
                                           CUdeviceptr, const size_t, const size_t,
                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Had<double2>(const size_t,
                                            const double2,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const CUdeviceptr, const size_t, const size_t,
                                            const double2,
                                            CUdeviceptr, const size_t, const size_t,
                                            const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Had<half>(const size_t,
                                         const half,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const CUdeviceptr, const size_t, const size_t,
                                         const half,
                                         CUdeviceptr, const size_t, const size_t,
                                         const CUcontext, const CUdevice);

// Scaling and out-place transpose/copy (non-BLAS function): SOMATCOPY/DOMATCOPY/COMATCOPY/ZOMATCOPY/HOMATCOPY
template <typename T>
StatusCode Omatcopy(const Layout layout, const Transpose a_transpose,
                    const size_t m, const size_t n,
                    const T alpha,
                    const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld,
                    CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld,
                    const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xomatcopy<T>(queue_cpp, nullptr);
    routine.DoOmatcopy(layout, a_transpose,
                       m, n,
                       alpha,
                       Buffer<T>(a_buffer), a_offset, a_ld,
                       Buffer<T>(b_buffer), b_offset, b_ld);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Omatcopy<float>(const Layout, const Transpose,
                                               const size_t, const size_t,
                                               const float,
                                               const CUdeviceptr, const size_t, const size_t,
                                               CUdeviceptr, const size_t, const size_t,
                                               const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Omatcopy<double>(const Layout, const Transpose,
                                                const size_t, const size_t,
                                                const double,
                                                const CUdeviceptr, const size_t, const size_t,
                                                CUdeviceptr, const size_t, const size_t,
                                                const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Omatcopy<float2>(const Layout, const Transpose,
                                                const size_t, const size_t,
                                                const float2,
                                                const CUdeviceptr, const size_t, const size_t,
                                                CUdeviceptr, const size_t, const size_t,
                                                const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Omatcopy<double2>(const Layout, const Transpose,
                                                 const size_t, const size_t,
                                                 const double2,
                                                 const CUdeviceptr, const size_t, const size_t,
                                                 CUdeviceptr, const size_t, const size_t,
                                                 const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Omatcopy<half>(const Layout, const Transpose,
                                              const size_t, const size_t,
                                              const half,
                                              const CUdeviceptr, const size_t, const size_t,
                                              CUdeviceptr, const size_t, const size_t,
                                              const CUcontext, const CUdevice);

// Im2col function (non-BLAS function): SIM2COL/DIM2COL/CIM2COL/ZIM2COL/HIM2COL
template <typename T>
StatusCode Im2col(const KernelMode kernel_mode,
                  const size_t channels, const size_t height, const size_t width, const size_t kernel_h, const size_t kernel_w, const size_t pad_h, const size_t pad_w, const size_t stride_h, const size_t stride_w, const size_t dilation_h, const size_t dilation_w,
                  const CUdeviceptr im_buffer, const size_t im_offset,
                  CUdeviceptr col_buffer, const size_t col_offset,
                  const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xim2col<T>(queue_cpp, nullptr);
    routine.DoIm2col(kernel_mode,
                     channels, height, width, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w,
                     Buffer<T>(im_buffer), im_offset,
                     Buffer<T>(col_buffer), col_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Im2col<float>(const KernelMode,
                                             const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                             const CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Im2col<double>(const KernelMode,
                                              const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                              const CUdeviceptr, const size_t,
                                              CUdeviceptr, const size_t,
                                              const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Im2col<float2>(const KernelMode,
                                              const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                              const CUdeviceptr, const size_t,
                                              CUdeviceptr, const size_t,
                                              const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Im2col<double2>(const KernelMode,
                                               const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                               const CUdeviceptr, const size_t,
                                               CUdeviceptr, const size_t,
                                               const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Im2col<half>(const KernelMode,
                                            const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);

// Col2im function (non-BLAS function): SCOL2IM/DCOL2IM/CCOL2IM/ZCOL2IM/HCOL2IM
template <typename T>
StatusCode Col2im(const KernelMode kernel_mode,
                  const size_t channels, const size_t height, const size_t width, const size_t kernel_h, const size_t kernel_w, const size_t pad_h, const size_t pad_w, const size_t stride_h, const size_t stride_w, const size_t dilation_h, const size_t dilation_w,
                  const CUdeviceptr col_buffer, const size_t col_offset,
                  CUdeviceptr im_buffer, const size_t im_offset,
                  const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xcol2im<T>(queue_cpp, nullptr);
    routine.DoCol2im(kernel_mode,
                     channels, height, width, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w,
                     Buffer<T>(col_buffer), col_offset,
                     Buffer<T>(im_buffer), im_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Col2im<float>(const KernelMode,
                                             const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                             const CUdeviceptr, const size_t,
                                             CUdeviceptr, const size_t,
                                             const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Col2im<double>(const KernelMode,
                                              const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                              const CUdeviceptr, const size_t,
                                              CUdeviceptr, const size_t,
                                              const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Col2im<float2>(const KernelMode,
                                              const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                              const CUdeviceptr, const size_t,
                                              CUdeviceptr, const size_t,
                                              const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Col2im<double2>(const KernelMode,
                                               const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                               const CUdeviceptr, const size_t,
                                               CUdeviceptr, const size_t,
                                               const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Col2im<half>(const KernelMode,
                                            const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                            const CUdeviceptr, const size_t,
                                            CUdeviceptr, const size_t,
                                            const CUcontext, const CUdevice);

// Batched convolution as GEMM (non-BLAS function): SCONVGEMM/DCONVGEMM/HCONVGEMM
template <typename T>
StatusCode Convgemm(const KernelMode kernel_mode,
                    const size_t channels, const size_t height, const size_t width, const size_t kernel_h, const size_t kernel_w, const size_t pad_h, const size_t pad_w, const size_t stride_h, const size_t stride_w, const size_t dilation_h, const size_t dilation_w, const size_t num_kernels, const size_t batch_count,
                    const CUdeviceptr im_buffer, const size_t im_offset,
                    const CUdeviceptr kernel_buffer, const size_t kernel_offset,
                    CUdeviceptr result_buffer, const size_t result_offset,
                    const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = Xconvgemm<T>(queue_cpp, nullptr);
    routine.DoConvgemm(kernel_mode,
                       channels, height, width, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w, num_kernels, batch_count,
                       Buffer<T>(im_buffer), im_offset,
                       Buffer<T>(kernel_buffer), kernel_offset,
                       Buffer<T>(result_buffer), result_offset);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API Convgemm<float>(const KernelMode,
                                               const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                               const CUdeviceptr, const size_t,
                                               const CUdeviceptr, const size_t,
                                               CUdeviceptr, const size_t,
                                               const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Convgemm<double>(const KernelMode,
                                                const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                                const CUdeviceptr, const size_t,
                                                const CUdeviceptr, const size_t,
                                                CUdeviceptr, const size_t,
                                                const CUcontext, const CUdevice);
template StatusCode PUBLIC_API Convgemm<half>(const KernelMode,
                                              const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t, const size_t,
                                              const CUdeviceptr, const size_t,
                                              const CUdeviceptr, const size_t,
                                              CUdeviceptr, const size_t,
                                              const CUcontext, const CUdevice);

// Batched version of AXPY: SAXPYBATCHED/DAXPYBATCHED/CAXPYBATCHED/ZAXPYBATCHED/HAXPYBATCHED
template <typename T>
StatusCode AxpyBatched(const size_t n,
                       const T *alphas,
                       const CUdeviceptr x_buffer, const size_t *x_offsets, const size_t x_inc,
                       CUdeviceptr y_buffer, const size_t *y_offsets, const size_t y_inc,
                       const size_t batch_count,
                       const CUcontext context, const CUdevice device) {
  try {
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = XaxpyBatched<T>(queue_cpp, nullptr);
    auto alphas_cpp = std::vector<T>();
    auto x_offsets_cpp = std::vector<size_t>();
    auto y_offsets_cpp = std::vector<size_t>();
    for (auto batch = size_t{0}; batch < batch_count; ++batch) {
      alphas_cpp.push_back(alphas[batch]);
      x_offsets_cpp.push_back(x_offsets[batch]);
      y_offsets_cpp.push_back(y_offsets[batch]);
    }
    routine.DoAxpyBatched(n,
                          alphas_cpp,
                          Buffer<T>(x_buffer), x_offsets_cpp, x_inc,
                          Buffer<T>(y_buffer), y_offsets_cpp, y_inc,
                          batch_count);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API AxpyBatched<float>(const size_t,
                                                  const float*,
                                                  const CUdeviceptr, const size_t*, const size_t,
                                                  CUdeviceptr, const size_t*, const size_t,
                                                  const size_t,
                                                  const CUcontext, const CUdevice);
template StatusCode PUBLIC_API AxpyBatched<double>(const size_t,
                                                   const double*,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   CUdeviceptr, const size_t*, const size_t,
                                                   const size_t,
                                                   const CUcontext, const CUdevice);
template StatusCode PUBLIC_API AxpyBatched<float2>(const size_t,
                                                   const float2*,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   CUdeviceptr, const size_t*, const size_t,
                                                   const size_t,
                                                   const CUcontext, const CUdevice);
template StatusCode PUBLIC_API AxpyBatched<double2>(const size_t,
                                                    const double2*,
                                                    const CUdeviceptr, const size_t*, const size_t,
                                                    CUdeviceptr, const size_t*, const size_t,
                                                    const size_t,
                                                    const CUcontext, const CUdevice);
template StatusCode PUBLIC_API AxpyBatched<half>(const size_t,
                                                 const half*,
                                                 const CUdeviceptr, const size_t*, const size_t,
                                                 CUdeviceptr, const size_t*, const size_t,
                                                 const size_t,
                                                 const CUcontext, const CUdevice);

// Batched version of GEMM: SGEMMBATCHED/DGEMMBATCHED/CGEMMBATCHED/ZGEMMBATCHED/HGEMMBATCHED
template <typename T>
StatusCode GemmBatched(const Activation actv, const Layout layout, const Transpose a_transpose, const Transpose b_transpose,
                       const size_t m, const size_t n, const size_t k,
                       const T *alphas,
                       const CUdeviceptr a_buffer, const size_t *a_offsets, const size_t a_ld,
                       const CUdeviceptr b_buffer, const size_t *b_offsets, const size_t b_ld,
                       const T *betas,
                       CUdeviceptr c_buffer, const size_t *c_offsets, const size_t c_ld,
                       const size_t batch_count,
                       const CUcontext context, const CUdevice device) {
  try {
    std::string name;
    switch (actv) {
      case Activation::kTanh:
        name = "ACTV_TANH";
        break;

      case Activation::kSigmoid:
        name = "ACTV_SIGMOID";
        break;

      case Activation::kReLU:
        name = "ACTV_RELU";
        break;

      case Activation::kLeakyReLU:
        name = "ACTV_LEAKYRELU";
        break;

      case Activation::kELU:
        name = "ACTV_ELU";
        break;

      default:
        name = "GEMMBATCHED";
        break;
    }
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = XgemmBatched<T>(queue_cpp, nullptr, name);
    auto alphas_cpp = std::vector<T>();
    auto betas_cpp = std::vector<T>();
    auto a_offsets_cpp = std::vector<size_t>();
    auto b_offsets_cpp = std::vector<size_t>();
    auto c_offsets_cpp = std::vector<size_t>();
    for (auto batch = size_t{0}; batch < batch_count; ++batch) {
      alphas_cpp.push_back(alphas[batch]);
      betas_cpp.push_back(betas[batch]);
      a_offsets_cpp.push_back(a_offsets[batch]);
      b_offsets_cpp.push_back(b_offsets[batch]);
      c_offsets_cpp.push_back(c_offsets[batch]);
    }
    routine.DoGemmBatched(layout, a_transpose, b_transpose,
                          m, n, k,
                          alphas_cpp,
                          Buffer<T>(a_buffer), a_offsets_cpp, a_ld,
                          Buffer<T>(b_buffer), b_offsets_cpp, b_ld,
                          betas_cpp,
                          Buffer<T>(c_buffer), c_offsets_cpp, c_ld,
                          batch_count);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API GemmBatched<float>(const Activation, const Layout, const Transpose, const Transpose,
                                                  const size_t, const size_t, const size_t,
                                                  const float*,
                                                  const CUdeviceptr, const size_t*, const size_t,
                                                  const CUdeviceptr, const size_t*, const size_t,
                                                  const float*,
                                                  CUdeviceptr, const size_t*, const size_t,
                                                  const size_t,
                                                  const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmBatched<double>(const Activation, const Layout, const Transpose, const Transpose,
                                                   const size_t, const size_t, const size_t,
                                                   const double*,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   const double*,
                                                   CUdeviceptr, const size_t*, const size_t,
                                                   const size_t,
                                                   const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmBatched<float2>(const Activation, const Layout, const Transpose, const Transpose,
                                                   const size_t, const size_t, const size_t,
                                                   const float2*,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   const CUdeviceptr, const size_t*, const size_t,
                                                   const float2*,
                                                   CUdeviceptr, const size_t*, const size_t,
                                                   const size_t,
                                                   const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmBatched<double2>(const Activation, const Layout, const Transpose, const Transpose,
                                                    const size_t, const size_t, const size_t,
                                                    const double2*,
                                                    const CUdeviceptr, const size_t*, const size_t,
                                                    const CUdeviceptr, const size_t*, const size_t,
                                                    const double2*,
                                                    CUdeviceptr, const size_t*, const size_t,
                                                    const size_t,
                                                    const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmBatched<half>(const Activation, const Layout, const Transpose, const Transpose,
                                                 const size_t, const size_t, const size_t,
                                                 const half*,
                                                 const CUdeviceptr, const size_t*, const size_t,
                                                 const CUdeviceptr, const size_t*, const size_t,
                                                 const half*,
                                                 CUdeviceptr, const size_t*, const size_t,
                                                 const size_t,
                                                 const CUcontext, const CUdevice);

// StridedBatched version of GEMM: SGEMMSTRIDEDBATCHED/DGEMMSTRIDEDBATCHED/CGEMMSTRIDEDBATCHED/ZGEMMSTRIDEDBATCHED/HGEMMSTRIDEDBATCHED
template <typename T>
StatusCode GemmStridedBatched(const Layout layout, const Transpose a_transpose, const Transpose b_transpose,
                              const size_t m, const size_t n, const size_t k,
                              const T alpha,
                              const CUdeviceptr a_buffer, const size_t a_offset, const size_t a_ld, const size_t a_stride,
                              const CUdeviceptr b_buffer, const size_t b_offset, const size_t b_ld, const size_t b_stride,
                              const T beta,
                              CUdeviceptr c_buffer, const size_t c_offset, const size_t c_ld, const size_t c_stride,
                              const size_t batch_count,
                              const CUcontext context, const CUdevice device) {
  try {
    std::string name;
    switch (actv) {
      case Activation::kTanh:
        name = "ACTV_TANH";
        break;

      case Activation::kSigmoid:
        name = "ACTV_SIGMOID";
        break;

      case Activation::kReLU:
        name = "ACTV_RELU";
        break;

      case Activation::kLeakyReLU:
        name = "ACTV_LEAKYRELU";
        break;

      case Activation::kELU:
        name = "ACTV_ELU";
        break;

      default:
        name = "GEMMSTRIDEDBATCHED";
        break;
    }
    const auto context_cpp = Context(context);
    const auto device_cpp = Device(device);
    auto queue_cpp = Queue(context_cpp, device_cpp);
    auto routine = XgemmStridedBatched<T>(queue_cpp, nullptr, name);
    routine.DoGemmStridedBatched(layout, a_transpose, b_transpose,
                                 m, n, k,
                                 alpha,
                                 Buffer<T>(a_buffer), a_offset, a_ld, a_stride,
                                 Buffer<T>(b_buffer), b_offset, b_ld, b_stride,
                                 beta,
                                 Buffer<T>(c_buffer), c_offset, c_ld, c_stride,
                                 batch_count);
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API GemmStridedBatched<float>(const Activation, const Layout, const Transpose, const Transpose,
                                                         const size_t, const size_t, const size_t,
                                                         const float,
                                                         const CUdeviceptr, const size_t, const size_t, const size_t,
                                                         const CUdeviceptr, const size_t, const size_t, const size_t,
                                                         const float,
                                                         CUdeviceptr, const size_t, const size_t, const size_t,
                                                         const size_t,
                                                         const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmStridedBatched<double>(const Activation, const Layout, const Transpose, const Transpose,
                                                          const size_t, const size_t, const size_t,
                                                          const double,
                                                          const CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const double,
                                                          CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const size_t,
                                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmStridedBatched<float2>(const Activation, const Layout, const Transpose, const Transpose,
                                                          const size_t, const size_t, const size_t,
                                                          const float2,
                                                          const CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const float2,
                                                          CUdeviceptr, const size_t, const size_t, const size_t,
                                                          const size_t,
                                                          const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmStridedBatched<double2>(const Activation, const Layout, const Transpose, const Transpose,
                                                           const size_t, const size_t, const size_t,
                                                           const double2,
                                                           const CUdeviceptr, const size_t, const size_t, const size_t,
                                                           const CUdeviceptr, const size_t, const size_t, const size_t,
                                                           const double2,
                                                           CUdeviceptr, const size_t, const size_t, const size_t,
                                                           const size_t,
                                                           const CUcontext, const CUdevice);
template StatusCode PUBLIC_API GemmStridedBatched<half>(const Activation, const Layout, const Transpose, const Transpose,
                                                        const size_t, const size_t, const size_t,
                                                        const half,
                                                        const CUdeviceptr, const size_t, const size_t, const size_t,
                                                        const CUdeviceptr, const size_t, const size_t, const size_t,
                                                        const half,
                                                        CUdeviceptr, const size_t, const size_t, const size_t,
                                                        const size_t,
                                                        const CUcontext, const CUdevice);

// =================================================================================================

// Retrieves the required size of the temporary buffer for the GEMM kernel (optional)
template <typename T>
StatusCode GemmTempBufferSize(const Layout layout, const Transpose a_transpose, const Transpose b_transpose,
                              const size_t m, const size_t n, const size_t k,
                              const size_t a_offset, const size_t a_ld,
                              const size_t b_offset, const size_t b_ld,
                              const size_t c_offset, const size_t c_ld,
                              const CUdevice device, size_t& temp_buffer_size) {
  try {

    // Retrieves the tuning database
    const auto device_cpp = Device(device);
    const auto kernel_names = std::vector<std::string>{"Xgemm", "GemmRoutine"};
    Databases db(kernel_names);
    Routine::InitDatabase(device_cpp, kernel_names, PrecisionValue<T>(), {}, db);

    // Computes the buffer size
    if (Xgemm<T>::UseDirectKernel(m, n, k, db["XGEMM_MIN_INDIRECT_SIZE"])) {
      temp_buffer_size = 0;
    }
    else {
      temp_buffer_size = Xgemm<T>::GetTempSize(layout, a_transpose, b_transpose, m, n, k,
                                               a_offset, a_ld, b_offset, b_ld, c_offset, c_ld,
                                               db["MWG"], db["NWG"], db["KWG"] * db["KREG"],
                                               db["GEMMK"]);
    }
    temp_buffer_size *= sizeof(T); // translate from num-elements to bytes
    return StatusCode::kSuccess;
  } catch (...) { return DispatchException(); }
}
template StatusCode PUBLIC_API GemmTempBufferSize<float>(const Layout, const Transpose, const Transpose,
                                                         const size_t, const size_t, const size_t,
                                                         const size_t, const size_t, const size_t, const size_t,
                                                         const size_t, const size_t, const CUdevice, size_t&);
template StatusCode PUBLIC_API GemmTempBufferSize<double>(const Layout, const Transpose, const Transpose,
                                                          const size_t, const size_t, const size_t,
                                                          const size_t, const size_t, const size_t, const size_t,
                                                          const size_t, const size_t, const CUdevice, size_t&);
template StatusCode PUBLIC_API GemmTempBufferSize<float2>(const Layout, const Transpose, const Transpose,
                                                          const size_t, const size_t, const size_t,
                                                          const size_t, const size_t, const size_t, const size_t,
                                                          const size_t, const size_t, const CUdevice, size_t&);
template StatusCode PUBLIC_API GemmTempBufferSize<double2>(const Layout, const Transpose, const Transpose,
                                                           const size_t, const size_t, const size_t,
                                                           const size_t, const size_t, const size_t, const size_t,
                                                           const size_t, const size_t, const CUdevice, size_t&);
template StatusCode PUBLIC_API GemmTempBufferSize<half>(const Layout, const Transpose, const Transpose,
                                                        const size_t, const size_t, const size_t,
                                                        const size_t, const size_t, const size_t, const size_t,
                                                        const size_t, const size_t, const CUdevice, size_t&);

// =================================================================================================
} // namespace clblast
