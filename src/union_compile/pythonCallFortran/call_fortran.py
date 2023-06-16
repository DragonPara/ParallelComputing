'''
Author: wrry 
email: wangrry@hotmail.com
Date: 2023-06-16 01:01:32
LastEditors: wrry wangrry@hotmail.com
LastEditTime: 2023-06-16 01:16:29
FilePath: /nonsense/pycallfortran/call_fortran.py
Description: 
'''
import ctypes
import numpy as np

# 加载.so文件
lib = ctypes.CDLL('./libadd_arrays.so')

# 定义函数原型
add_arrays = lib.add_arrays_
# add_arrays.restype = None
add_arrays.argtypes = [
    np.ctypeslib.ndpointer(dtype=np.float32, flags='C_CONTIGUOUS'),  # array1
    np.ctypeslib.ndpointer(dtype=np.float32, flags='C_CONTIGUOUS'),  # array2
    np.ctypeslib.ndpointer(dtype=np.float32, flags='C_CONTIGUOUS'),  # result
    ctypes.POINTER(ctypes.c_int)                                     # size
]

# 创建输入数组
array1 = np.array([1.0, 2.0, 3.0, 4.0], dtype=np.float32)
array2 = np.array([5.0, 6.0, 7.0, 8.0], dtype=np.float32)
size = len(array1)

# 创建输出数组
result = np.zeros_like(array1)
# 调用函数
add_arrays(array1, array2, result, ctypes.pointer(ctypes.c_int(size)))

# 输出结果
print("Result:", result)
