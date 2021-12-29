import hashlib
import os

template = """
cmake_minimum_required(VERSION 3.21)
project(learnBoost)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS filesystem)
"""


def md5(s: str):
    x = hashlib.md5()
    x.update(bytes(s, encoding='utf8'))
    return x.hexdigest()


a = []
for ind, i in enumerate(os.listdir('.')):
    if not i.endswith('.cpp'):
        continue
    target_name = "target" + md5(os.path.abspath(i))
    a.append(f"""
add_executable({target_name} {i})
    """)
template += '\n'.join(a)
print(template)
with open('./CMakeLists.txt', 'w') as f:
    f.write(template)
