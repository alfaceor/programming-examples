#!/usr/bin/env python3

import appdirs
import os

dirs = appdirs.AppDirs('myapp', 'myname', version='0.1.0')

print(dirs.user_data_dir)



