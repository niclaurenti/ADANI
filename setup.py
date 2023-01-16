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
setup(
    name="adani",
    version="0.1",
    description="Un codice scritto a cazzo di cane",
    author="Chittesencula",
    license="Fateci il cazzo che vi pare, non me ne frega un cazzo",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    cmake_args=['-DPYTHON_ONLY:BOOL=ON'],
    python_requires=">=3.8",
)