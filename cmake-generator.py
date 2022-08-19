import hashlib
import os
from os.path import *

template = """
cmake_minimum_required(VERSION 3.21)
project(learnBoost)

set(CMAKE_CXX_STANDARD 14)

"""
root = abspath(dirname(__file__))


def md5(s: str):
    x = hashlib.md5()
    x.update(bytes(s, encoding='utf8'))
    return x.hexdigest()


a = []


def add_folder(folder):
    for parent, folders, files in os.walk(folder):
        for i in files:
            if not i.endswith('.cpp'):
                continue
            target_name = "target" + md5(os.path.abspath(i))
            a.append(f"""
add_executable({target_name} {relpath(join(parent, i), root)})
target_link_libraries({target_name}  ${{CONAN_LIBS}})""")


add_folder(join(root, '001-learnCpp'))
add_folder(join(root, '016-学习boost'))
add_folder(join(root, '033-json'))
add_folder(join(root, '030-http'))
add_folder(join(root, '150-protobuf'))
template += '\n'.join(a)
print(template)
with open('./gen.cmake', 'w') as f:
    f.write(template)
