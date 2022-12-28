#include <cpp_viz/lib.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;
constexpr auto byref = py::return_value_policy::reference_internal;

PYBIND11_MODULE(RejectionSample, m) {
  py::class_<RejectionSample>(m, "RejectionSample")
      .def(py::init<>())
      .def("rejection_sample", &RejectionSample::rejection_sample,
           py::call_guard<py::gil_scoped_release>())
      .def_readonly("res", &RejectionSample::res, byref);
}
