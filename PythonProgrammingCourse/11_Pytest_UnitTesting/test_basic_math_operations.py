"""
#############################################################################
###  Author       : Sanjeet Prasad                                       ###
###  Description  : Pytest test suite for basic_math_operations.py       ###
###  Created On   : 04-08-2025                                           ###
###  Test Tool    : Pytest                                               ###
#############################################################################
"""

import pytest
from basic_math_operations import add, subtract, multiply, divide

def test_add():
    assert add(5, 3) == 8
    assert add(-1, 1) == 0

def test_subtract():
    assert subtract(10, 4) == 6
    assert subtract(0, 3) == -3

def test_multiply():
    assert multiply(2, 7) == 10
    assert multiply(-5, 2) == -10

def test_divide():
    assert divide(8, 2) == 4.0
    assert divide(9, 3) == 3.0

def test_divide_by_zero():
    with pytest.raises(ValueError):
        divide(5, 0)