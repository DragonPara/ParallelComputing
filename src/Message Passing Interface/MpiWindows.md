在Windows上，使用MPICH2来使用MPI

[下载链接](http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/1.4.1p1/mpich2-1.4.1p1-win-ia32.msi)

打开MPICH2安装目录的bin目录，打开 wmpiregister,填入用户名和密码(必须是实际电脑的用户名和密码)，点击register

注册后，用管理员权限的cmd 打开MPICH2安装目录的bin目录

\> smpd -install -phrase behappy

behappy 是你在安装MPICH2时设置的口令，默认为behappy

打开wmpiexec

选择样例 ~\MPICH2\examples\cpi.exe

选择wmpiexec中的run in an separate window

Number of processes 选择 2, 即使用两个进程

点击Execute开始执行

输入100000，程序将给出圆周率计算结果