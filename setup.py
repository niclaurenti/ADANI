import sys, os

try:
    from skbuild import setup
except ImportError:
    print(
        "Please update pip, you need pip 10 or greater,\n"
        " or you need to install the PEP 518 requirements in pyproject.toml yourself",
        file=sys.stderr,
    )
    raise

from setuptools import find_packages

# load long description from README
this_directory = os.path.abspath(os.path.dirname(__file__))
with open(os.path.join(this_directory, "README.md"), encoding="utf-8") as f:
    long_description = f.read()

setup(
    name="adani",
    version="0.10", # el diez
    description="Un codice scritto a cazzo di cane",
    author="Niccolò Laurenti",
    license="Fateci il cazzo che vi pare, basta che non mi rompete i coglioni",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    cmake_install_dir="src/adani",
    cmake_args=['-DPYTHON_ONLY:BOOL=ON'],
    python_requires=">=3.8",
    long_description=long_description,
    long_description_content_type="text/markdown",
)
