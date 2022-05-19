# 统信USO备赛20题

#### 忘记 ROOT 密码

###### UOS 1030 以前的版本

> 启动/重启系统时，按 e ，进入 grub 界面
>
> <img src="img/GNU GRUB 界面.png" style="zoom: 67%;" align="left" />
>
> 

> 光标向下移动，找到 linux /vmlinuz 开头所在行，再找到 `ro splash quiet`
>
> <img src="img/ro splash quiet.png" style="zoom: 67%;" align="left" />

> 修改 `ro splash quiet` 为 `rw  splash quiet init=/bin/bash`
>
> <img src="img/rw.png" style="zoom: 67%;" align="left" />

> 修改完后，按 Ctrl + X 或 F10 继续启动

进入 BOOT 单用户模式后，在命令行中输入：

 ``` bash
 root (none):/# password root
 ```

重启 Linux 即可登录 root 用户

*参考资料* 

- [解决kali默认不能root用户登录](https://blog.csdn.net/weixin_45571987/article/details/115487088 "解决kali默认不能root用户登录")

以上方法不适用于 UOS 1031 以后的版本，系统会照常启动

###### UOS 1031 以后的版本

首先需要制作 UOS 安装盘

进入 [deepin 官网]("https://www.deepin.org/zh/download/") ，找到 **深度启动盘制作工具** 选择 官方下载

......

(以下操作在虚拟机中进行)

按 F2 进入 BIOS

> 选择 CD-ROM 优先启动
>
> <img src="img/CD-ROM.png" style="zoom:67%;" align="left" />

> 按 TAB 键，配置启动
>
> <img src="img/edit entry.png" style="zoom:67%;" align="left" />
>
> 删除 `livecd-installer`
>
> <img src="img/live1.png" style="zoom:67%;" align="left" />
>
> <img src="img/live2.png" style="zoom:67%;" align="left" />
>
> 配置完后，回车启动
>
> 创建目录用于挂载原先系统的root目录;
>
> > uos@UOS:~$ sudo mkdir 
>
> 输入 `lsblk -f` ，查看 root 路径，root 所在路径是sda5;
>
> > uos@UOS:~$ lsblk -f
> >
> > NAME   FSTYPE  LABEL     UUID                                 FSAVAIL FSUSE% MOUNTPOINT
> > loop0  squashf                                                      0   100% /usr/lib/li
> > sda                                                                          
> > ├─sda1 ext4    Boot      8b621e9c-1e4a-44f0-91f2-1c83a2797dda                
> > ├─sda2                                                                       
> > ├─sda3 ext4    Backup    ec658bb1-0b39-4801-8c8d-3a2efd208412                
> > ├─sda4 swap    SWAP      d05021c5-0244-4aaa-9bcc-fb6400004c5c                
> > ├─sda5 ext4    Roota     bb994e9d-b251-438c-8965-371faf63a7bf                
> > ├─sda6 ext4    Rootb     62834f30-2871-495c-b118-a60923a113c5                
> > └─sda7 ext4    _dde_data e4089404-542d-4fc2-b5ca-51ac44367158                
> > sr0    iso9660 Deepin 20 2021-09-29-03-17-27-00                     0   100% /run/live/m
>
> 挂载 sda5 到 /mnt/systmp 目录下(是挂载 *Roota*目录);
>
> > uos@UOS:~$ sudo mount -t ext4 /dev/sda5 /mnt/systmp
>
> 用 chroot 命令改变当前根目录到 /mnt/systmp 下;
>
> > uos@UOS:~$ sudo chroot /mnt/systmp
>
> 用 passwd 命令修改用户密码.
>
> > root@UOS:/# passwd
>
> 修改后登录系统会提示 “您用来登录计算机的密码与登录密钥环里的密码不再匹配。”
>
> <img src="img/ring.png" style="zoom:67%;" align="left" />
>
> 解决：如果登录用户正常，在显示页面有上面得图片提示，密钥环不正确，就在终端输入下面得命令删除用户的密钥环：
>
> > root@UOS:/# rm -rf /home/用户/.local/share/keyrings/login.keyring
>
> 完成后重启
>
> > root@UOS:/# reboot -f
>
> 别忘了把启动项配置回来



#### 修改主机名称

全程操作需 root 权限

**临时 **修改 hostname 为 temname

> root@uos:# hostname tmpname

**永久** 修改 hostname 为 myhostname

> root@uos:# hostnamectl set-hostname myhostname

更改完后，/etc/hostname 文件内容变成了 `myhostname` ，但是通过修改该文件来达到修改主机名的目的是不可取的

通过 `hostnamectl` 命令查看:

> root@uos:# hostnamectl
>
>    Static hostname: Canyou
>          Icon name: computer-vm
>            Chassis: vm
>         Machine ID: 0e5cb5666eac4d759b16eb9884feaa7e
>            Boot ID: 366da32edafc4421a9575f19badd1594
>     Virtualization: vmware
>   Operating System: Deepin 20.2.4
>             Kernel: Linux 5.10.60-amd64-desktop
>       Architecture: x86-64















#### 补充

Deepin 是基于 `Debian` 的系统

