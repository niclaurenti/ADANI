#include <pybind11/functional.h>
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <adani/adani.h>

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {

    // Documentation

    m.doc() = "Python wrapper of libadani";

    // ApproximateCoefficientFunction
    // ...
    // AsymptoticCoefficientFunction
    py::class_<AsymptoticCoefficientFunction>(m, "AsymptoticCoefficientFunction")
        .def(py::init<const int&, const char&, const char&, const bool&>())
        .def("MuIndependentTerms", &AsymptoticCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &AsymptoticCoefficientFunction::MuDependentTerms)
        .def("fx", &AsymptoticCoefficientFunction::fx);

    // ExactCoefficientFunctions
    py::class_<ExactCoefficientFunction>(m, "ExactCoefficientFunction")
        .def(py::init<const int&, const char&, const char&, const double&, const double&, const int&, const int&, const int&>())
        .def("MuIndependentTerms", &ExactCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &ExactCoefficientFunction::MuDependentTerms)
        .def("fx", &ExactCoefficientFunction::fx);

    // HighEnergyCoefficientFunction
    py::class_<HighEnergyCoefficientFunction>(m, "HighEnergyCoefficientFunction")
        .def(py::init<const int&, const char&, const char&, const bool&>())
        .def("MuIndependentTerms", &HighEnergyCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &HighEnergyCoefficientFunction::MuDependentTerms)
        .def("fx", &HighEnergyCoefficientFunction::fx);

    // HighEnergyHighScaleCoefficientFunction
    py::class_<HighEnergyHighScaleCoefficientFunction>(m, "HighEnergyHighScaleCoefficientFunction")
        .def(py::init<const int&, const char&, const char&, const bool&>())
        .def("MuIndependentTerms", &HighEnergyHighScaleCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &HighEnergyHighScaleCoefficientFunction::MuDependentTerms)
        .def("fx", &HighEnergyHighScaleCoefficientFunction::fx);

    // PowerTermsCoefficientFunction
    py::class_<PowerTermsCoefficientFunction>(m, "PowerTermsCoefficientFunction")
        .def(py::init<const int&, const char&, const char&, const bool&>())
        .def("MuIndependentTerms", &PowerTermsCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &PowerTermsCoefficientFunction::MuDependentTerms)
        .def("fx", &PowerTermsCoefficientFunction::fx);

    // HighScaleCoefficientFunction
    py::class_<HighScaleCoefficientFunction>(m, "HighScaleCoefficientFunction")
        .def(py::init<const int&, const char&, const char&>())
        .def("MuIndependentTerms", &HighScaleCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &HighScaleCoefficientFunction::MuDependentTerms)
        .def("fx", &HighScaleCoefficientFunction::fx);

    // MasslessCoefficientFunction
    py::class_<MasslessCoefficientFunction>(m, "MasslessCoefficientFunction")
        .def(py::init<const int&, const char&, const char&>())
        .def("MuIndependentTerms", &MasslessCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &MasslessCoefficientFunction::MuDependentTerms)
        .def("fx", &MasslessCoefficientFunction::fx);

    // SplittingFunction
    py::class_<SplittingFunction>(m, "SplittingFunction")
        .def(py::init<const int&, const char&, const char&>())
        .def("Regular", &SplittingFunction::Regular)
        .def("Singular", &SplittingFunction::Singular)
        .def("SingularIntegrated", &SplittingFunction::SingularIntegrated)
        .def("Local", &SplittingFunction::Local);

    // ConvolutedSplittingFunctions
    py::class_<ConvolutedSplittingFunctions>(m, "ConvolutedSplittingFunctions")
        .def(py::init<const int&, const char&, const char&, const int&, const char&, const char&>())
        .def("Regular", &ConvolutedSplittingFunctions::Regular)
        .def("Singular", &ConvolutedSplittingFunctions::Singular)
        .def("SingularIntegrated", &ConvolutedSplittingFunctions::SingularIntegrated)
        .def("Local", &ConvolutedSplittingFunctions::Local);

    // ThresholdCoefficientFunction
    py::class_<ThresholdCoefficientFunction>(m, "ThresholdCoefficientFunction")
        .def(py::init<const int&, const char&, const char&>())
        .def("MuIndependentTerms", &ThresholdCoefficientFunction::MuIndependentTerms)
        .def("MuDependentTerms", &ThresholdCoefficientFunction::MuDependentTerms)
        .def("fx", &ThresholdCoefficientFunction::fx);
}
