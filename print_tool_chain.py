import os

"""
需要在Preference的build/cmake中添加一个配置
"""
print(f"-DCMAKE_TOOLCHAIN_FILE={os.environ['VCPKG_ROOT']}/scripts/buildsystems/vcpkg.cmake")
