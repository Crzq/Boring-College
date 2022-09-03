直接从纯净机开始
11:40
发现没装 git,以及要处理虚拟机真机复制问题

#### 安装 pip
``` bash
# 这里遇到了问题
sudo apt install python3-pip
sudo pip install --upgrade pip
# 注意不是 tester
sudo pip install -U os-testr
```

This is your host IP address: 192.168.116.164
This is your host IPv6 address: ::1
Horizon is now available at http://192.168.116.164/dashboard
Keystone is serving at http://192.168.116.164/identity/
The default users are: admin and demo
The password: secret

Services are running under systemd unit files.
For more information see: 
https://docs.openstack.org/devstack/latest/systemd.html

DevStack Version: zed
Change: aac6b6c7912b3feae4b68789508bee4bf1544731 Merge "Drop setup.py and setup.cfg" 2022-03-29 17:50:05 +0000
OS Version: Ubuntu 20.04 focal

2022-04-07 04:54:14.187 | stack.sh completed in 1944 seconds.


12:56 终于成功了！
