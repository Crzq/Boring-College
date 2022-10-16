转载于 https://blog.csdn.net/m0_46374969/article/details/116007606

计算机网络—路由器（Cisco Packet Tracer）常用的命令总结

    最近朋友上课在使用思科模拟器做实验的时候，经常会在查找命令上花费了很多时间，但是我们最重要的是记住命令，而不是花费太多的时间在查找命令，今天我就来跟大家介绍一下思科模拟器的一些常用命令，希望可以帮到大家。

![image-20221016201456990](D:\Qiavo\Desktop\网络实训\CISCO PACKET TRACER COMMAND\assets\image-20221016201456990.png)

一、路由器口令设置

    router>enable 进入特权模式
    
    router#config terminal 进入全局配置模式
    
    router(config)#hostname 设置交换机的主机名
    
    router(config)#enable secret xxx 设置特权加密口令
    
    router(config)#enable password xxb 设置特权非密口令
    
    router(config)#line console 0 进入控制台口
    
    router(config-line)#line vty 0 4 进入虚拟终端
    
    router(config-line)#login 要求口令验证
    
    router(config-line)#password xx 设置登录口令xx
    
    router(config)#(Ctrl+z) 返回特权模式
    
    router#exit 返回命令

二、路由器配置

    router(config)#int s0/0 进入Serail接口
    
    router(config-if)#no shutdown 激活当前接口
    
    router(config-if)#clock rate 64000 设置同步时钟
    
    router(config-if)#ip address 设置IP地址
    
    router(config-if)#ip address second 设置第二个IP
    
    router(config-if)#int f0/0.1 进入子接口
    
    router(config-subif.1)#ip address 设置子接口IP
    
    router(config-subif.1)#encapsulation dot1q 绑定vlan中继协议
    
    router(config)#config-register 0x2142 跳过配置文件
    
    router(config)#config-register 0x2102 正常使用配置文件
    
    router#reload 重新引导

三、路由器文件操作

    router#copy running-config startup-config 保存配置
    
    router#copy running-config tftp 保存配置到tftp
    router#copy startup-config tftp 开机配置存到tftp
    router#copy tftp flash: 下传文件到flash
    router#copy tftp startup-config 下载配置文件

ROM状态：

    Ctrl+Break 进入ROM监控状态
    
    rommon>confreg 0x2142 跳过配置文件
    
    rommon>confreg 0x2102 恢复配置文件
    
    rommon>reset 重新引导
    
    rommon>copy xmodem: flash: 从console传输文件
    
    rommon>IP_ADDRESS=10.65.1.2 设置路由器IP
    
    rommon>IP_SUBNET_MASK=255.255.0.0 设置路由器掩码
    
    rommon>TFTP_SERVER=10.65.1.1 指定TFTP服务器IP
    
    rommon>TFTP_FILE=c2600.bin 指定下载的文件
    
    rommon>tftpdnld 从tftp下载
    
    rommon>dir flash: 查看闪存内容
    
    rommon>boot 引导IOS

四、静态路由

    ip route 命令格式
    
    router(config)#ip route 2.0.0.0 255.0.0.0 1.1.1.2 静态路由举例
    
    router(config)#ip route 0.0.0.0 0.0.0.0 1.1.1.2 默认路由举例123123

五、动态路由

    router(config)#ip routing 启动路由转发
    router(config)#router rip 启动RIP路由协议
    router(config-router)#network 设置发布路由
    router(config-router)#negihbor 点对点帧中继用。12341234

六、帧中继命令

    router(config)#frame-relay switching 使能帧中继交换
    
    router(config-s0)#encapsulation frame-relay 使能帧中继
    
    router(config-s0)#fram-relay lmi-type cisco 设置管理类型
    
    router(config-s0)#frame-relay intf-type DCE 设置为DCE
    
    router(config-s0)#frame-relay dlci 16
    
    router(config-s0)#frame-relay local-dlci 20 设置虚电路号
    
    router(config-s0)#frame-relay interface-dlci 16
    
    router(config)#log-adjacency-changes 记录邻接变化
    
    router(config)#int s0/0.1 point-to-point 设置子接口点对点
    
    router#show frame pvc 显示永久虚电路
    
    router#show frame map 显示映射

七、基本访问控制列表

    router(config)#access-list permit|deny
    
    router(config)#interface ;default:deny any
    
    router(config-if)#ip access-group in|out ;defaultut123123

例1：

    router(config)#access-list 1 deny host 10.65.1.1
    router(config)#access-list 1 permit any
    router(config)#int f0/0
    router(config-if)#ip access-group 4 in

例2：

    router(config)#access-list 4 permit 10.8.1.1
    
    router(config)#access-list 4 deny 10.8.1.0 0.0.0.255
    router(config)#access-list 4 permit 10.8.0.0 0.0.255.255
    router(config)#access-list 4 deny 10.0.0.0 0.255.255.255
    router(config)#access-list 4 permit any
    router(config)#int f0/1
    router(config-if)#ip access-group 4 in

扩展访问控制列表：
　　access-list permit|deny icmp [type]
　　access-list permit|deny tcp [port]
　　例1：

    router(config)#access-list 101 deny icmp any 10.64.0.2 0.0.0.0 echo
    router(config)#access-list 101 permit ip any any
    router(config)#int s0/0
    router(config-if)#ip access-group 101 in

例2：

    router(config)#access-list 102 deny tcp any 10.65.0.2 0.0.0.0 eq 80
    
    router(config)#access-list 102 permit ip any any
    
    router(config)#interface s0/1
    
    router(config-if)#ip access-group 102 out

删除访问控制例表:

    router(config)#no access-list 102
    router(config-if)#no ip access-group 101 in

路由器的nat配置

    Router(config-if)#ip nat inside 当前接口指定为内部接口
    
    Router(config-if)#ip nat outside 当前接口指定为外部接口
    
    Router(config)#ip nat inside source static [p] <私有IP><公网IP> [port]
    
    Router(config)#ip nat inside source static 10.65.1.2 60.1.1.1
    
    Router(config)#ip nat inside source static tcp 10.65.1.3 80 60.1.1.1
    80
    
    Router(config)#ip nat pool p1 60.1.1.1 60.1.1.20 255.255.255.0
    
    Router(config)#ip nat inside source list 1 pool p1
    
    Router(config)#ip nat inside destination list 2 pool p2
    
    Router(config)#ip nat inside source list 2 interface s0/0 overload
    
    Router(config)#ip nat pool p2 10.65.1.2 10.65.1.4 255.255.255.0 type
    rotary
    
    Router#show ip nat translation
    
    rotary 参数是轮流的意思，地址池中的IP轮流与NAT分配的地址匹配。
    
    overload参数用于PAT 将内部IP映射到一个公网IP不同的端口上。

外部网关协议配置

    routerA(config)#router bgp 100
    
    routerA(config-router)#network 19.0.0.0
    
    routerA(config-router)#neighbor 8.1.1.2 remote-as 200

配置PPP验证：

    RouterA(config)#username password
    RouterA(config)#int s0
    RouterA(config-if)#ppp authentication {chap|pap}

八、路由器子接口封装为8021Q

    Encapsulation dot1q 2 封装类型设置为 802.1Q,2是子接口号标识，这里是示范，可以随意设置。

九、代码截图

![image-20221016201323639](D:\Qiavo\Desktop\网络实训\CISCO PACKET TRACER COMMAND\assets\image-20221016201323639.png)