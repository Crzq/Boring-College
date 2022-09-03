## OpenStack搭建

#### 环境
* VMware Workstation

* Ubuntu 20.04 LTS  
  下载地址：
  * [清华大学开源软件镜像站](https://mirrors.tuna.tsinghua.edu.cn/ubuntu-releases/ '清华大学开源软件镜像站')
  * [Ubuntu 中文站](https://cn.ubuntu.com/download/desktop/ 'cn.ubuntu.com')
  * [Ubuntu 官网(动态地址)](https://ubuntu.com/download/desktop/thank-you?version=20.04.4&architecture=amd64 'ubuntu.com')

**<font size=1>一个小提示：如果你的 VMware Tools 安装成功，那么你可直接点击右侧的复制代码进行操作</font>**

#### 软件环境安装
```
# 安装 git
sudo apt install git

# 安装 pip
sudo apt-get install python3-pip
sudo pip install --upgrade pip
sudo pip install -U os-testr

# 安装 vim
sudo apt install vim
```

#### 添加堆栈用户（可选）
``` bash
sudo useradd -s /bin/bash -d /opt/stack -m stack

# 由于该用户将对您的系统进行许多更改，因此它应该具有 sudo 权限：
echo "stack ALL=(ALL) NOPASSWD: ALL" | sudo tee /etc/sudoers.d/stack

# 切换到 stack 用户
sudo -u stack -i
```

#### 安装组件
```
# 以下命令可制作批处理文件，示例：
vim test.sh

# 将以下安装组件的代码复制进来，保存

# 执行批处理文件前，赋执行权
sudo chmod 777 test.sh

# 执行批处理文件
./test.sh
```

``` bash
# 由于网络问题，最好使用 Github 的镜像(第二条命令)

# 安装 DevStack
# git clone https://opendev.org/openstack/decstack.git
git clone https://github.com/openstack/devstack.git

# 安装 Horizon
# git clone https://opendev.org/openstack/horizon.git
git clone https://github.com/openstack/horizon.git

# 安装 Cinder
# git clone https://opendev.org/openstack/cinder.git
git clone https://github.com/openstack/cinder.git

# 安装 Placement
# git clone https://opendev.org/openstack/placement.git
git clone https://github.com/openstack/placement.git

# 安装 Neutron
# git clone https://opendev.org/openstack/neutron.git
git clone https://github.com/openstack/neutron.git

# 安装 Nova
# git clone https://opendev.org/openstack/nova.git
git clone https://github.com/openstack/nova.git

# 安装 Glance
# git clone https://opendev.org/openstack/glance.git
git clone https://github.com/openstack/glance.git

# 安装 Keystone
# git clone https://opendev.org/openstack/keystone.git
git clone https://github.com/openstack/keystone.git



```

#### 在 DevStack 根目录下创建 local.conf 配置文件，包含 admin 密码、数据库密码、RabbitMQ 密码以及 Service 密码：
``` bash
# 进入 DevStack
cd devstack

# 创建 local.conf, 并将以下配置写入文件中
vim local.conf
```
```ini
[[local|localrc]]
ADMIN_PASSWORD=secret
DATABASE_PASSWORD=$ADMIN_PASSWORD
RABBIT_PASSWORD=$ADMIN_PASSWORD
SERVICE_PASSWORD=$ADMIN_PASSWORD
```

#### Python pip 修改镜像源为豆瓣源
``` bash
# 创建 pip.conf 
mkdir ~/.pip
vim ~/.pip/pip.conf
```
``` ini
[global]
index-url = http://pypi.douban.com/simple/
trusted-host = pypi.douban.com
```

#### 开始安装
``` bash
./stack.sh
```

#### 常见问题
* Q: 真机与虚拟机之间不能实现复制、粘贴操作  
A: 重新安装 VMware Tools
``` bash
# 除了第一个询问回答Y之外，其他按默认的N就好
sudo apt-get install open-vm-tools-desktop

# 重启
reboot
```  


* Q: 没有可用的软件包××，但是它被其他的软件包引用了
``` bash
sudo apt-get update
```


* Q: E: 无法获得锁 /var/lib/dpkg/lock-frontend。锁正由进程 2688（unattended-upgr）持有
``` bash
# 强制删除
sudo rm /var/lib/dpkg/lock-frontend
sudo rm /var/lib/dpkg/lock
```


* Q: sudo apt-get install 软件包没有可安装候选  
A: 无下载源。我遇到这个问题是因为当时改了下载源，原来默认的备份了，结果更改失败，故出现这样的报错。最后我还是使用了默认的下载源。



* Q: launchpadlib 1.10.6 requires testresources, which is not installed.
``` bash
python3.6 get-pip.py
python3.6 -m pip install launchpadlib
```


* Q: error: RPC failed; curl 56 GnuTLS recv error (-9)  
原因：http 缓存不够或者网络不稳定等。git clone 较大的工程产生如上报错，查资料应该是由于 git 默认缓存大小不足导致的。
``` bash
# 修改git的配置
sudo apt install gnutls-bin
git config --global http.sslVerify false
git config --global http.postBuffer 1048576000 # httpBuffer加大(增大缓存空间)
git config --global core.compression -1 # 压缩配置

# 修改配置文件
export GIT_TRACE_PACKET=1
export GIT_TRACE=1
export GIT_CURL_VERBOSE=1
```


* Q: error: RPC failed; curl 56 GnuTLS recv error (-54): Error in the pull function.
``` bash
# 修改下载方式 https 改为 ssh (非命令)
https://github.com/openstack/devstack.git => git@github.com:openstack/devstack.git
```


* Q: error: invalid command 'bdist_wheel'
``` bash
sudo pip install wheel
sudo pip install uwsgi
sudo pip install --upgrade setuptools
```



#### 推荐文献
* [OpenStack 文档](https://docs.openstack.org/devstack/latest/ 'devstack')
* [深入理解 OpenStack 自动化部署](https://www.bookstack.cn/read/deployopenstackwithpuppet/deployment_tool-devstack.md/ '深入理解 OpenStack 自动化部署')
* [OpenStack入门科普，看这一篇就够啦！](https://zhuanlan.zhihu.com/p/35598437/ 'OpenStack入门科普')
* [Openstack组件（原理篇）--nova、cinder、swift](https://blog.csdn.net/qq_43257377/article/details/104279625/ 'Openstack组件（原理篇）')
* [如何通过控制台访问openstack实例_OpenStack架构](https://blog.csdn.net/weixin_39639568/article/details/110907279/ 'OpenStack架构')
