#include <cpp_viz/lib.hpp>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
constexpr auto byref = py::return_value_policy::reference_internal;

PYBIND11_MODULE(CPPViz, m) {
  py::class_<RejectionSample>(m, "RejectionSample")
      .def(py::init<>())
      .def("rejection_sample", &RejectionSample::rejection_sample,
           py::call_guard<py::gil_scoped_release>())
      .def_readonly("res", &RejectionSample::res, byref);
}
