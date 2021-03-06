#include <math.h>
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pybind11/complex.h"
#include "pybind11/operators.h"
#include "Operator/PauliOperator.h"

namespace py = pybind11;
USING_QPANDA
PYBIND11_MODULE(pyQPandaPauliOperator, m)
{
    m.doc() = "";

    py::class_<PauliOperator>(m, "PauliOperator")
        .def(py::init<>())
        .def(py::init<>([](const complex_d &val)
            { return PauliOperator(val); }))
        .def(py::init<>([](const std::string &key, const complex_d &val)
            { return PauliOperator(key, val); }))
        .def(py::init<>([](const PauliOperator::PauliMap &map)
            { return PauliOperator(map); }))
        .def("dagger", &PauliOperator::dagger)
        .def("toHamiltonian", &PauliOperator::toHamiltonian)
        .def("getMaxIndex", &PauliOperator::getMaxIndex)
        .def("isEmpty", &PauliOperator::isEmpty)
        .def("isAllPauliZorI", &PauliOperator::isAllPauliZorI)
        .def("setErrorThreshold", &PauliOperator::setErrorThreshold)
        .def("error_threshold", &PauliOperator::error_threshold)
        .def("remapQubitIndex", &PauliOperator::remapQubitIndex)
		.def("data", &PauliOperator::data)
        .def(py::self + py::self)
        .def(py::self - py::self)
        .def(py::self * py::self)
        .def(py::self += py::self)
        .def(py::self -= py::self)
        .def(py::self *= py::self)
        .def(py::self + QPanda::complex_d())
        .def(py::self * QPanda::complex_d())
        .def(py::self - QPanda::complex_d())
        .def(QPanda::complex_d() + py::self)
        .def(QPanda::complex_d() * py::self)
        .def(QPanda::complex_d() - py::self)
        .def("toString", &PauliOperator::toString)
        .def("__str__", &PauliOperator::toString);
}
