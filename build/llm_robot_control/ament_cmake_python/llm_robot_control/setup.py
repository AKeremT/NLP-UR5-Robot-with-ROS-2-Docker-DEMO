from setuptools import find_packages
from setuptools import setup

setup(
    name='llm_robot_control',
    version='0.0.1',
    packages=find_packages(
        include=('llm_robot_control', 'llm_robot_control.*')),
)
