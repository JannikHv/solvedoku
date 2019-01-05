#!/usr/bin/env python3

from setuptools import setup


exec(compile(
    open('solvedoku/info.py', 'r').read(),
    'solvedoku/info.py', 'exec'
))

DESCRIPTION = 'A simple Sudoku solver'
LONG_DESCRIPTION = 'A simple Sudoku solver'

setup(
    name = 'solvedoku',
    version = __version__,
    description = DESCRIPTION,
    long_description = LONG_DESCRIPTION,
    url = 'https://github.com/JannikHv/solvedoku',
    author = __author__,
    author_email = __email__,
    maintainer = __author__,
    maintainer_email = __email__,
    license = __license__,
    packages= ['solvedoku'],
)
