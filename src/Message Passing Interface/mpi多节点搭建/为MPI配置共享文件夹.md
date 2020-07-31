# 使用 nfs rpcbind实现共享文件夹操作
> 经过搜集资料和猜测，配置成功
## 在主机端和设备端都安装 nfs和rpcbind
`sudo yum install -y nfs-util rpcbind`

## 主机端
建立共享文件夹

`mkdir /mpiShareDir` 在根目录下建立，否则可能导致没有权限访问上级目录

添加要分享的节点，在此之前可以改一下/etc/hosts 本地域名

推荐一下nano编辑器，`yum install nano`

`sudo nano /etc/hosts`
```
192.168.0.2 node1 #本机内网ip
192.168.0.3 node2 #要共享的子节点
```
设置完之后别忘了保存，之后就可以用node2代指192.168.0.3

设置谁能访问共享文件夹

`sudo nano /etc/exports`
```
/mpiShareDir node2(rw,sync,root_squash)
```
**rw :** 可读可写

**ro :** 只读

**sync :** 同步写入（文件同时写入硬盘和内存）

**async :** 异步写入，不建议

**root_squash** 客户端root权限访问共享文件，在服务端上不具有root权限


启动nfs 和 rpcbind
```
sudo service rpcbind start
sudo service nfs-server start 
```
如果一开始就启动，改了配置文件之后还要重启nfs和rpcbind

`sudo service rpcbind restart`

`sudo service nfs-server restart`

原本是sudo service nfs start，后来改成了nfs-server

设置服务器开机自启 nfs 和 rpcbind
```
sudo systemctl enable nfs-server
sudo systemctl enable rpcbind
```

## 客户端
第一步安装好了 nfs 和 rpcbind 了

`sudo nano /etc/hosts`
```
192.168.0.2 node1 #本机内网ip
192.168.0.3 node2 #要共享的子节点
```

现在可以看看服务端共享的目录

`showmount -e node1`

想必你看到了
```
Export list for node1:
/mpiShareDir node2
```

创建目录

`sudo mkdir /mpiShareDir`

名字可以不是mpiShareDir，如果换名字，后面也要改

挂载共享目录到本地

`sudo mount -t nfs node1:/mpiShareDir /mpiShareDir`

设置上述命令开机自动运行一遍

`nano /etc/rc.d/rc.local`

在后面加上手动挂载的命令

`sudo mount -t nfs node1:/mpiShareDir /mpiShareDir`

如果你重启之后发现并没有挂上，在前面加一条

`sleep 1`

等待前置程序完成之后连接

# 可能会出现服务端未开启时，客户端无法开机的现象，服务端开启后，客户端也跟着开机。

## 有建议的话，请动动您尊贵的小手，发个评论