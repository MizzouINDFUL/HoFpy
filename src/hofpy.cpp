#include <iostream>
#include "hofpy.h"
#include "HoF_Raster.hpp"


py::array_t<double> FRHist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, double typeForce, int numberDirections) {

    py::buffer_info bufA = imageA.request();
    py::buffer_info bufB = imageB.request();

    if (bufA.ndim != 2 || bufB.ndim != 2)
    {
        throw std::runtime_error("Image dimensions must be 2");
    }
    if ((bufA.shape[0] != bufB.shape[0]) || (bufA.shape[1] != bufB.shape[1]))
    {
        throw std::runtime_error("Images must have same shape");
    }

    auto histogram = py::array_t<double>(numberDirections + 1);

    py::buffer_info buf_histogram = histogram.request();

    unsigned char* ptrA = (unsigned char*)bufA.ptr;
    unsigned char* ptrB = (unsigned char*)bufB.ptr;
    double* ptr_histogram = (double*)buf_histogram.ptr;

    int M = bufA.shape[0];
    int N = bufA.shape[1];

    hof::HoF_Raster raster_obj;

    raster_obj.FRHistogram_CrispRaster(ptr_histogram, numberDirections, typeForce, ptrA, ptrB, M, N);

    return histogram;
}

py::array_t<double> F0Hist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, int numberDirections) {
    return FRHist(imageA, imageB, 0.0, numberDirections);
}

py::array_t<double> F2Hist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, int numberDirections) {
    return FRHist(imageA, imageB, 2.0, numberDirections);
}