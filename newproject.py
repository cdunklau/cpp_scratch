#!/usr/bin/env python
import sys
import os
import shutil


subdirs = ['bin', 'build', 'doc', 'include', 'src']


def main():
    prog, project = sys.argv
    for d in subdirs:
        os.makedirs(os.path.join(project, d))
    shutil.copy('Makefile.template', os.path.join(project, 'Makefile'))


if __name__ == '__main__':
    main()
