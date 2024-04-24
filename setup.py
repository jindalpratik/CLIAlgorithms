from pathlib import Path

from pybind11.setup_helpers import Pybind11Extension
from setuptools import find_packages, setup

ext_modules = [
    Pybind11Extension(
        "cppalgorithm",
        sorted([str(p) for p in Path('./src/clialgorithms/cpp_src/').rglob('*.cpp')]),
        include_dirs       = ['lib/include', 'lib/pybind11/'],
        language           = 'c++',
        extra_compile_args = ['-std=c++11'],
    ),
]

setup(name = 'cppalgorithm',
  version      = '0.2',
  description  = 'cpp sources for python project',
  author       = 'Pratik Jindal',
  author_email = '',
  license      = 'MIT',
  packages     = find_packages(),
  ext_modules  = ext_modules
)
