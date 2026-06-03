#!/usr/bin/python3

import os
import subprocess
import argparse

BUILDDIR = os.getenv('BUILD_DIR')

def cmake():
    pass


def build():
    if not BUILDDIR:
        raise f'BUILDDIR variable not set'
    # cmake -S . -B build
    subprocess.run(["cmake", "-S", ".", "-B", BUILDDIR], check=True)
    # cmake --build build
    subprocess.run(["cmake", "--build", BUILDDIR], check=True)


def target():
    pass


def main():
    parser = argparse.ArgumentParser(description="CMake Wrapper Script")
    parser.add_argument('-b', '--build', action='store_true', help='Build CMake')
    parser.add_argument('-t', '--target', action='store_true', help='Run CMake target')
    args = parser.parse_args()

    if args.build:
        build()
    elif args.target:
        target()


if __name__ == "__main__":
    main()
