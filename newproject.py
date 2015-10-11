#!/usr/bin/env python
import sys
import os
import shutil


subdirs = ['bin', 'build', 'doc', 'include', 'src']


def main():
    prog, project = sys.argv
    for d in subdirs:
        os.makedirs(os.path.join(project, d))
    makefile = os.path.join(project, 'Makefile')
    if not os.path.exists(makefile):
        shutil.copy('Makefile.template', makefile)


if __name__ == '__main__':
    main()
