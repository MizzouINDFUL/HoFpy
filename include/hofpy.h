#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> FRHist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, double typeForce, int numberDirections);
py::array_t<double> F0Hist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, int numberDirections);
py::array_t<double> F2Hist(py::array_t<unsigned char>& imageA, py::array_t<unsigned char>& imageB, int numberDirections);

PYBIND11_MODULE(hofpy, m) {
    m.def("FRHist", &FRHist, "Histogram of Forces",
          py::arg("imageA"), py::arg("imageB"), py::arg("typeForce"), py::arg("numberDirections") = 180);
    m.def("F0Hist", &F0Hist, "Histogram of Constant Forces (F0)",
          py::arg("imageA"), py::arg("imageB"), py::arg("numberDirections") = 180);
    m.def("F2Hist", &F2Hist, "Histogram of Gravitational Forces (F2)",
          py::arg("imageA"), py::arg("imageB"), py::arg("numberDirections") = 180);
}