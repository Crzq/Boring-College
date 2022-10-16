# Packet Tracer命令大全

转载于 https://blog.csdn.net/VariatioZbw/article/details/108212741

#### 1.基本配置

```
R> enable   从用户模式进入特权模式
R# disable  从特权模式退到用户模式
R# logout (或exit)   退出Cisco设备
R# show history 查看先前输入的命令（默认10个）
R# terminal history size #_of_commands  改变历史缓存的大小（最大256）
R# terminal no editing  禁用编辑特性（移去no参数为启用）
R# configure terminal   进入配置模式（退出为end或CTRL-Z）
R(config)# hostname name    改变路由器的名称
R(config)# banner motd delimiting_character banner_character delimiting_character   设置登录横幅
R(config-line)# exec-timeout minutes_# seconds_#    更改休止超时（默认10分钟）
R# show hosts   查看路由器解析表中的静态和动态DNS条目
R> show version 查看路由器综合信息
R# show line    验证线路的配置
R# show processes   查看设备的各个进程的CPU使用率
R# show users   查看登录到这台设备上的所有用户
R# show sessions    查看当前挂起的已经打开的telnet会话
R# term ip netmask-format bit-count|decimal|hexadecimal 改变子网掩码显示方式（在当前登录会话期间有效，在子线路模式下即可保存）
R(config)# ip host name_of_host [TCP_port_#] IP_address […] 创建主机静态解析表（可指定多达8个IP地址）
R(config)# ip name-server IP_address_of_DNS_server […]  配置通过访问DNS服务器动态解析主机（可指定多达6个DNS服务器）
R(config)# no ip domain-lookup  禁用DNS查询
R> ping destination_IP_address_or_host_name 查看与目的主机的连通性
R> traceroute destination_IP_address_or_host_name   查看与目的主机间的路由器
R# [telnet|connect] name_of_the_destination|destination_IP_address  打开telnet会话
R# resume connection_#  恢复一个特定的会话
R# disconnect connection_#  结束一已挂起的telnet会话无须恢复它并随后从中退出
R# clear line line_#    结束某人的会话
R# no debug all (或undebug all)  禁用debug
R(config)# service timestamps debug datetime msec   在debug输出中显示时间戳
R# terminal monitor 从VTY或辅助线路端口登录执行，路由器将在屏幕上显示报告消息
R(config-line)# logging synchronous在该线路上报告信息后路由器在新提示符后重新显示未打完的命令
```

#### 2.文件操作

```
R# show running-config  查看正在运行（当前）的配置文件
R# show startup-config  查看NVRAM中的配置文件
R# copy running-config|startup-config tftp  将配置备份到TFTP服务器
R# copy tftp startup-config|running-config  从TFTP服务器将配置恢复到路由器
R# copy startup-config running-config   从NVRAM中将配置恢复到RAM中
R# copy running-config startup-config   将RAM中的配置文件保存到NVRAM
R# erase startup-config 删除NVRAM中的配置文件
R# copy flash tftp  备份IOS镜像到TFTP服务器
R# show flash   查看闪存中的文件
```

#### 3.启动配置

```
R# setup    运行系统配置会话
R(config)# boot system flash name_of_IOS_file_in_flash  启动时加载闪存中的指定IOS文件
R(config)# boot system tftp IOS_image_name IP_address_of_server 启动时加载TFTP服务器里的IOS文件
R(config)# boot system rom  启动时加载ROM中的迷你IOS文件（启动与这三个命令的顺序有关）
R(config)# config-register 0x hexadecimal_value 改变寄存器的值
rommon 5> confreg 0x2142    2600、3600系列启动后按CTRL-BREAK进入ROMMON模式，改变寄存器的值
R> o/r 0x2142   其他系列路由器改变寄存器的值的方法
```

#### 4.密码设置

```
R(config)# line console 0   进入控制台接口配置模式
R(config-line)# password console_password   配置控制台口令
R(config)# line vty 0 4 进入虚拟终端线路配置模式（根据路由器及IOS最少5个直到很多）
R(config-line)# login   接上条命令，允许进行Telnet访问
R(config-line)# password telnet_password    接上条命令，配置Telnet口令
R(config)# line aux 0   进入辅助端口配置模式
R(config-line)# password console_password   接上条命令，配置辅助端口口令
R(config)# enable password privileged_password  配置特权EXEC口令（不加密）
R(config)# enable secret privileged_password    配置特权EXEC口令（加密）
```

#### 5.接口配置

```
R(config)# interface type [slot_#/] port_#  进入接口子配置模式
R(config-if)# description interface_description 添加接口描述
R(config-if)# no shutdown   启用该接口
R(config)# interface loopback port_#    创建环回接口
R(config-if)# media-type aui|10baset|100baset|mii   指定该接口连接的介质类型
R(config-if)# speed 10|100|auto 指定该接口速率
R(config-if)# [no] half-duplex  指定该接口双工模式
R(config-if)# clock rate rate_in_bits_per_second    指定该DCE串行接口速率
R> show controller serial [slot_#/] port_#  验证该接口是DCE还是DTE，注意空格
R(config-if)# bandwidth rate_in_Kbps    改变该接口的带宽值
R(config-if)# ip address IP_address subnet_mask 配置该接口IP地址
R(config)# ip subnet-zero   IOS12.0前默认禁用0子网，此命令为启用
R(config-if)# ip directed-broadcast IOS12.0后默认禁用定向广播，此命令为启用
R# show interfaces [type [slot_#/] port_#]  验证接口配置
R# show ip interfaces [type [slot_#/] port_#] [brief]   验证接口IP配置
```

#### 6.CDP

```
R(config)# [no] cdp run 启用/禁用CDP
R(config-if)# [no] cdp enable   基于接口启用/禁用CDP
R# show cdp 查看CDP状态
R# show cdp interface   查看基于接口的CDP配置
R# show cdp neighbors [detail]  查看与用户Cisco设备相连的CDP邻居的摘要/详细清单
R# show cdp entry neighbor's_name   查看一个指定邻居的详细信息
R# show cdp traffic 查看CDP通信量的统计信息
```

#### 7.路由

```
R(config)# ip route destination_network_# [subnet_mask] IP_address_of_next_hop_neighbor|interface_to_exit [administrative_distance] [permanent] 配置IP静态路由
R(config)# ip route 0.0.0.0 0.0.0.0 IP_address_of_next_hop_neighbor|interface_to_exit [administrative_distance] [permanent] 配置默认路由
R(config)# ip classless 使有类协议接受非一致性子网掩码或不连续子网
R(config)# interface type [slot_#/] port_#. subinterface_# [point-to-point|multipoint]  创建子接口
R(config-subif)# encapsulation isl|dotlq VLAN_# 指定子接口中继类型和相关的VLAN
R(config)# router name_of_the_IP_routing_protocol   进入路由选择协议的配置模式
R# show ip route    查看IP路由表
```

#### 8.RIP

```
R(config)# router rip   配置IP RIP
R(config-router)# network IP_network_#  指定哪些接口参与路由选择进程
R(config-router)# version 1|2   只接受和发送RIP版本1或2（默认只产生RIPv1更新，而两个版本的更新都接收）
R(config-router)# ip rip send|receive version 1 | version 2 | version 1 2   在特定接口上控制在发送或接收RIP更新时使用哪个版本的RIP
R# show ip protocols    查看在路由器上已配置并运行的所有IP路由选择协议
R# show ip route [name_of_the_IP_routing_protocol]  查看路由选择表
R# debug ip rip 帮助进行故障排除
```

#### 9.IGRP

```
R(config)# router igrp AS_# 配置IP IGRP
R(config-router)# network IP_network_#  通告网络号
R(config-router)# neighbor IP_address_of_neighbor   配置单播更新
R(config-router)# passive-interface type [slot_#/] port_#   允许该接口在IGRP中通告但它不监听或发送IGRP更新
R(config-router)# traffic-share min across-interfaces   使路由器只使用最佳路径但又在路由选择表中放入替代路径
R(config-router)# timers basic update_# invalid_# holddown_# flush_# [sleeptime_#]  调整定时器（默认时，update=90，invalid=270，holddown=280，flush=630）
R(config-router)# no metric holddown    关闭压制定时器（默认）
R(config-router)# distance administrative_distance_#    调整管理距离（取值范围是1-255，默认为100）
R(config-router)# default-metric bandwidth_# delay_# reliability_# load_# MTU_# 调整度量值
R(config-router)# metric weights tos_# K1_# K2_# K3_# K4_# K5_# 调整度量权重值（默认时，K1(带宽)=K3(可靠性)=1，K2(延迟)=K4(负载)=K5(MTU)=0）
R(config-router)# variance multiplier_# 启用IGRP非同等成本路径（变化因子值1-128默认为1）
R(config-router)# traffic-share balanced    配置负载均衡
R(config-router)# maximum-paths paths_# 配置负载均衡的路径条数（取值范围是1-6）
R# debug ip igrp events 提供路由器和邻居间发生的每一步操作信息
R# debug ip igrp transactions   提供有关包含在路由更新中路由的详细信息
```

#### 10.EIGRP

```
R(config)# router eigrp AS_#    配置EIGRP
R(config-router)# network IP_network_#  通告网络号
R(config-if)# ip bandwidth-percent eigrp AS_# percent_# 设置pacing（调速）占给定接口带宽的百分数（默认为50%）
R(config-router)# distance administrative_distance_#    调整管理距离（取值范围是1-255，默认对于内部路由是90而外部是170）
R(config-router)# default-metric bandwidth_# delay_# reliability_# load_# MTU_# 调整度量值
R(config-router)# metric weights tos_# K1_# K2_# K3_# K4_# K5_# 调整度量权重值（默认时，K1(带宽)=K3(可靠性)=1，K2(延迟)=K4(负载)=K5(MTU)=0）
R(config-if)# ip hello-interval eigrp AS_# seconds_#    在给定接口上设置Hello间隔（默认对于低速的NBMA网络是60秒，其他是5秒）
R(config-if)# ip hold-time eigrp AS_# seconds_# 在给定接口上设置Hello保持定时器（默认是3倍的Hello间隔）
R(config-router)# passive-interface type [slot_#/] port_#   允许该接口在EIGRP中通告但它不监听或发送EIGRP更新
R(config-router)# no auto-summary   取消对路由的自动汇总
R(config-if)# ip summary-address eigrp AS_# network_address network_mask    创建不在有类边界上的汇总地址
R(config)# eigrp log-neighbor-changes   记录在某个邻居上发生的变化
R# show ip route eigrp  查看被EIGRP学习到的路由
R# show ip route network_address    查看指定目的地的路由信息
R# show ip eigrp topology   查看EIGRP的拓扑表
R# show ip eigrp interfaces     查看加入到EIGRP路由器所有接口的概述
R# show ip eigrp neighbor [detail]  显示和本路由器已形成邻居关系的所有路由器
R# show ip eigrp traffic    显示每个包类型的发出和接收的数量
R# show ip eigrp events 查看每个EIGRP事件的日志
R# debug ip eigrp   提供路由器和它的邻居之间发生的每一步操作
R# debug eigrp packets  查看在该路由器和它的邻居之间发送的数据包类型
R# debug eigrp neighbors    查看邻居的信息
```

#### 11.OSPF

```
R(config)# router ospf process_ID   配置OSPF
R(config-router)# network IP_address wildcard_mask area area_#  指定接口进入OSPF区域
R(config-if)# ip ospf cost cost_value   给接口指定成本（取值范围是1-65535）
R(config-router)# neighbor IP_address_of_neighbor   手动配置邻居
R(config-router)# neighbor IP_address_of_neighbor priority value    指定邻居的优先级（取值范围是0-255，255为DR，0为不可能成为DR）
R(config-if)# ip ospf network non-broadcast 手工配置非广播网络类型
R(config-router)# area area_id stub 允许创建存根区域
R(config-router)# area area_id stub no-summary  允许创建完全存根区域
R(config-router)# area area_id nssa 允许创建次存根区域
R(config-router)# area area_id virtual-link router_id   连接不连续区域为骨干区域0
R(config-router)# area area_id range network_address network_mask   在区域边界路由器上汇总在给定区域中的路由器使用的IP地址空间到其他的区域
R(config-router)# summary-address network_address network_mask  在自治系统边界路由器上汇总外部路由
R# show ip ospf 概述所有OSPF相关的信息
R# show ip ospf process-id  与上相同，而不仅仅是指定的进程
R# show ip ospf border-routers  显示在此自治系统中所有ABR和ASBR的路由器ID
R# show ip ospf database    显示链路状态数据库
R# show ip ospf interface   显示接口的OSPF参数和其他的指定到此接口上的OSPF信息
R# show ip ospf neighbor [detail]   显示每个OSPF邻居和邻接状态
R# debug ip ospf adj    报告路由器建立到其他路由器的邻接关系进程
R# debug ip ospf events 报告路由器上的OSPF事件
R# debug ip ospf packet 报告OSPF LSA分组的内容
```

#### 12.ACL

```
R(config)# access-list 1-99|1300-1999 permit|deny source_IP_address [wildcard_mask] [log]    创建标准编号IP ACL
R(config-if)# ip access-group ACL_# in|out  在指定接口上启动ACL
R(config-line)# access-class standard_ACL_# in|out  在指定若干线路上启动ACL以限制对路由器的Telnet访问
R(config)# access-list 100-199|2000-2699 permit|deny IP_protocol source_address source_wildcard_mask [protocol_information] destination_address destination_wildcard_mask [protocol_information] [log]  创建扩展编号IP ACL
R(config)# ip access-list standard ACL_name 创建标准命名ACL（从IOS11.2开始支持）
R(config-std-acl)# permit|deny source_IP_address [wildcard_mask]    输入标准ACL命令
R(config)# ip access-list extended ACL_name 创建扩展命名ACL（从IOS11.2开始支持）
R(config-ext-acl)# permit|deny IP_protocol source_IP_address wildcard_mask [protocol_information] destination_IP_address wildcard_mask [protocol_information] [log] 输入扩展ACL命令
R(config-if)# ip access_group ACL_name in|out   启动命名ACL
R# show ip interfaces   验证访问列表
R# show access-lists [ACL_#_or_name]    显示ACL中的语句
R# show ip access-list [ACL_#_or_name]  显示IP ACL中的语句
R# clear access-list counters [ACL_#_or_name]   对指定ACL中的匹配计数器清零
```

#### 13.NAT PAT 配置负载分发

```
R(config)# ip nat inside source static inside_local_source_IP_address inside_global_source_IP_address   定义NAT静态转换
R(config)# ip nat outside source static outside_global_destination_IP_address outside_local_destination_IP_address  定义NAT静态转换
R(config-if)# ip nat inside|outside 指定路由器上哪些接口在内部，哪些在外部
R(config)# ip nat outside source list standard_IP_ACL_# pool NAT_pool_name  为重叠地址转换配置NAT
R(config)# ip nat inside source list standard_IP_ACL_# pool NAT_pool_name   定义动态NAT，指定转换哪些内部设备的源地址
R(config)# ip nat pool NAT_pool_name beginning_inside_global_IP_address ending_inside_global_IP_address netmask subnet_mask_of_addresses|prefix-length length   创建源内部全局IP地址池
R(config)# ip nat inside source list standard_IP_ACL_# pool NAT_pool_name overload  定义PAT，指定哪台内部设备会转换其源地址
R(config)# ip nat pool pool_name beginning_inside_local_IP_address ending_inside_local_IP_address prefix-length subnet_mask_bits type rotary    指定提供服务的设备上配置的内部IP地址
R(config)# ip nat inside destination list standard_ACL_# pool pool_name 指定外部设备用来访问内部资源的全局IP地址
R# show ip nat translations [verbose]   查看路由器上的（详细）地址转换信息
R# show ip nat statistics   查看路由器上的地址转换的统计信息
R# clear ip nat translation *   清除所有NAT表项
R# clear ip nat translation inside|outside global_IP_address|local_IP_address   清除转换表中的指定动态条目
R# clear ip nat translation protocol inside global_IP_address global_port local_IP_address local_port   清除转换表中的指定动态条目
R# debug ip nat 提供IOS对每个已转换分组所做的转换
```

#### 14.DHCP

```
R(config)# [no] service dhcp    启用/禁用DHCP（默认启用）
R(config)# ip dhcp pool pool_name   创建地址池
R(config-dhcp)# network network_number [subnet_mask|/prefix_length] 指定分配给客户的IP地址范围
R(config-dhcp)# domain-name domain_name 向客户分配域名
R(config-dhcp)# dns-server IP_address […]   指定最多8台DNS服务器分配给客户
R(config-dhcp)# netbios-name-server IP_address […]  指定最多8台WINS服务器分配给客户
R(config-dhcp)# netbios-node-type node_type 向微软客户分配节点类型
R(config-dhcp)# default-router IP_address […]   指定最多8条默认路由给客户用于该地址范围
R(config-dhcp)# lease days [hours] [minutes] |infinite  指定租约的期限（默认一天）
R(config)# ip dhcp ping timeout milliseconds    指定测试服务器地址池中的可用地址是否正在使用时服务器应等待时间
R(config)# ip dhcp excluded-address beginning_IP_address [ending_IP_address]    排除一些地址
R(config-if)# ip address dhcp   在路由器上建立DHCP客户
R# show ip dhcp binding [client_address]    查看分配给客户的地址
R# clear ip dhcp binding client_address|*   清除分配给客户的指定/所有地址
R# debug ip dhcp server events|packet|linkage   查看DHCP服务器相关信息
```

#### 15.HDLC

```
R(config-if)# encapsulation hdlc    封装同步串行接口为HDLC（默认）
```

> 补充一下，熊老师说过 `no encapsulation ppp` 也能恢复默认 HDLC

#### 16.PPP

```
R(config-if)# encapsulation ppp 在WAN接口上使用PPP
R(config-if)# ppp pap sent-username your_hostname password password 指定PAP用于认证并且提供在服务端用于执行认证的用户名和口令（此为客户端配置）
R(config)# hostname your_router's_hostname  为路由器指定惟一主机名（以下三个为服务端配置）
R(config)# username remote_hostname password matching_password  指定认证路由器时所使用的远端主机名称和口令
R(config-if)# ppp authentication pap    指定PAP认证
R(config-if)# ppp authentication chap|pap|chap pap|pap chap 批定PPP认证类型
R# debug ppp negotiation    查看LCP协商时的信息
R# debug ppp authentication 查看PPP认证情况
```

#### 17.FR

```
R(config-if)# encapsulation frame-relay [cisco|ietf]    指定封装类型为帧中继(默认cisco）
R(config-if)# frame-relay lmi-type ansi|cisco|q933a 给该串行接口指定LMI类型
R# show frame-relay lmi 查看详细的LMI统计信息
R# debug frame-relay lmi    报告路由器正在发送与接收的实际LMI信息
R(config-if)# frame-relay map protocol_name destination_address local_dlci_# [broadcast] [ietf|cisco]   将远端第3层地址手动映射到本地DLCI号
R(config-if)# [no] frame-relay inverse-arp [protocol_name] [DLCI_#] 启用/禁用逆向
```

#### 18.ARP（默认启用）

```
R(config-if) clear frame-relay-inarp    清除逆向ARP解析表
R# show frame-relay traffic 查看逆向ARP统计
R# show frame-relay pvc [DLCI_#]    查看终止于路由器的所有（指定）帧中继PVC及其统计信息
R# show frame-relay map 查看将第3层地址映射成本地DLCI号的虚电路解析表
R(config)# interface type [slot_#/] port_#. subinterface_# [point-to-point|multipoint]  创建子接口
R(config-subif)# frame-relay interface-dlci local_DLCI_#    配置子接口的帧中继
```

#### 19.ISDN

```
R(config[-if])# isdn switch-type ISDN_switch_type   在全局或接口配置模式下配置交换机类型
R(config-if)# isdn spid1 spid_#__for_1st_BRI local_dial_#   为第一个B信道配置SPID
R(config-if)# isdn spid2 spid_#__for_2st_BRI local_dial_#   为第二个B信道配置SPID
R(config)# controller t1|e1 [slot_#/] port_#    以下6个命令为控制卡配置
R(config-controller)# framing esf|sf|crc4|nocrc4    在T1或E1上使用物理成帧
R(config-controller)# linecode ami|b8zs|hdb3    线路编码，定义1与0如何在线路上物理表示
R(config-controller)# clock source line primary|secondary|internal  定义路由器如何获得其时钟以用于同步数字连接
R(config-controller)# pri-group timeslots [1-24|1-31]   指定路由器哪个或哪些时隙用于ISDN连接
R(config-controller)# [no] shutdown 启用/禁用控制器
R# show controllers t1|e1 [slot_#/port_#]   验证控制器卡配置
R(config)# interface serial [slot_#/] port_#:23 设置逻辑串口（T1使用）
R(config)# interface serial [slot_#/] port_#:15 设置逻辑串口（E1使用）
R# show interface bri [slot_#/] port_#[:1|2|1 2]    验证ISDN连接的状态（查看B信道）
R# show isdn status 查看ISDN详细的物理层和数据链路层信息
R# debug isdn q921  报告ISDN数据链路层详细信息
R(config)# ip route IP_network_# subnet_mask remote_router's_IP_address|router_interface [administrative_distance]  配置静态路由。以下7个命令配置传统DDR
R(config)# dialer-list list_# protocol protocol_name permit|deny [access-list ACL_#]    定义敏感流量
R(config-if)# dialer-group dialer_list_#    激活拨号列表
R(config-if)# dialer map protocol_name address_of_destination_router [name remote_router_name] [speed 56|64] [broadcast] destination_phone_number   表明利用传统DDR进行电话呼叫
R(config-if)# dialer idle-timeout #_of_seconds  定义空闲超时周期
R(config-if)# dialer fast-idle #_of_seconds 定义快速空闲计时器
R(config-if)# dialer load-threshold load either|inbound|outbound    通过BRI的两条B信道执行负载均衡（分配带宽）
R# show dialer  查看哪个DDR接口进行了电话呼叫及其状态
R# show isdn active 查看激活的ISDN呼叫
R# show isdn history    查看路由器发出的呼叫或以前接收的呼叫
R# debug dialer 显示建立或拆除一个连接的DDR过程
R# debug isdn q931  显示ISDN电话连接建立及挂断的详细信息
R(config)# interface dialer port_#  创建逻辑拨号接口。以下全为配置拨号配置文件。以下8个为拨号接口配置
R(config-if)# encapsulation ppp 指定封装类型
R(config-if)# ppp authentication pap|chap|chap pap|pap chap 指定认证类型
R(config-if)# ip address IP_address subnet_mask 指定接口IP地址
R(config-if)# dialer remote-name name   指定远端路由器的名称
R(config-if)# dialer string phone_# [class map_name]    指定映射类名称
R(config-if)# dialer pool pool_#    指定拨号接口能使用哪组物理接口
R(config-if)# dialer-group dialer_list_#    激活拨号列表
R(config-if)# dialer pool-member pool_# [priority priority_#] [min-link #_of_B_channels] [max-link #_of_B_channels] 指定哪些拨号接能使用物理接口
R(config)# map-class dialer map_name    进入映射子配置模式。以下4个为创建映射类
R(config-map)# dialer isdn speed 56 指定ISDN中的B信道的速度（默认64kbps）
R(config-map)# dialer idle-timeout #_of_seconds 定义空闲超时周期
R(config-map)# dialer fast-idle #_of_seconds    定义快速空闲计时器
R# show dialer interface bri|{serial:23|15} [slot_#/]port_# 显示与拨号接口关联的物理接口的进入和离开呼叫的DDR统计信息
```

#### 20.IS-IS

```
R(config)# router isis  启动IS-IS
R(config-router)# net areaID.systemID.SEL   配置NET
R(config-router)# is-type level_of_router   配置路由器的层次
R(config-if)# ip router isis    在接口上启动IS-IS
R(config-if)# isis priority value level-1|level-2   手动配置第一层或第二层路由器的优先级
R(config-if)# clns router isis  为无连接网络服务启动IS-IS
R# show ip route isis   查看通过IS-IS学习到的路由
R# show isis database [detail level_of_router]  查看IS-IS链路状态数据库中的所有（某层）LSP信息
R# show clns protocol   显示IS-IS详细配置信息
R# show clns interface  显示配置为IS-IS接口的相关信息
R# show clns is-neighbors   查看路由器的邻居
R# show isis spf-log    查看SPF计算情况
R# debug isis adj-packets   查看路由器发送和接收Hello PDU的情况
R# debug isis update-packets    提供路由器发送和接收的所有LSP详细内容及SNP信息
R# debug isis spf-events    查看写入路由表的IS-IS路由
R# debug isis spf-triggers  查看触发SPF计算的原因
R# debug isis spf-statistics    查看执行SPF计算所用的时间
```

#### 21.BGP

```
R(config)# router bgp AS_#  启动BGP
R(config-router)# neighbor IP_address_remote_device remote-as AS_#_remote_device    指定远端路由器作为对等体
R(config-router)# no synchronization    关闭BGP与IGP同步（默认启用）
R(config-router)# neighbor IP_address_remote_device update-source loopback #    使用环回接口作为对等体
R(config-router)# neighbor IP_address_remote_device ebgp-multihop [ttl] 配置eBGP多跳（允许BGP邻居可以不在直连网络上）
R(config-router)# neighbor IP_address_remote_device route-reflector-client  配置邻居为路由反射器客户
R(config-router)# network network_address mask subnet_mask  向对等体通告路由（手动向BGP注入路由）
R(config-router)# redistribute protocol process_ID  将路由重新分配到BGP
R(config-router)# redistribute connected    将直连接口地址重新分配到BGP
R(config-router)# bgp cluster-id cluster_ID 分配簇ID
R(config-router)# bgp confederation identifier confederation_ID 配置联邦ID
R(config-router)# bgp confederation peers AS_#  配置联邦的对等自治系统成员
R(config-router)# neighbor IP_address_remote_device distribute-list access_list_# [in|out]  过滤到或来自邻居的更新信息
R(config)# ip prefix-list list_name [seq seq_value] permit|deny network_address/length [ge ge_value] [le le_value]  配置前缀列表
R(config-router)# neighbor IP_address_remote_device prefix-list list_name [in|out]  应用从邻居输入的前缀列表
R(config)# route-map route_map_name permit|deny [sequence_number]   创建路由映射序列
R(config-route-map)# match as-path AS_path_accesslist_# 匹配BGP自治系统路径访问列表
R(config-route-map)# match community-list community_list_#  匹配BGP团体
R(config-route-map)# match interface type [slot_#/] port_#  发布任何下一跳是指定接口的路由
R(config-route-map)# match ip address access_list_#|prefix_list_name    匹配任何目的网络地址被指定的标准访问列表、扩展访问列表或前缀列表允许的路由
R(config-route-map)# match ip next-hop access_list_#|prefix_list_name   匹配任何下一跳地址被指定的标准访问列表、扩展访问列表或前缀列表允许的路由
R(config-route-map)# match ip route-source access_list_#|prefix_list_name   匹配任何由被指定的标准访问列表、扩展访问列表或前缀列表允许的地址通告的路由
R(config-route-map)# match metric value 匹配任何具有指定的度量值的路由
R(config-route-map)# match route-type type_of_route 匹配任何具有指定类型的路由
R(config-route-map)# match tag value    匹配任何具有指定标识的路由
R(config-route-map)# set as-path prepend AS_#   向AS_PATH属性添加自治系统号
R(config-route-map)# set as-path tag    设置作为AS_PATH属性的标记
R(config-route-map)# set automatic-tag  自动计算标记值
R(config-route-map)# set community number|aa:nn|additive|local-as|no-advertise|no-export|none   设置BGP COMMUNITIES属性
R(config-route-map)# set dampening half_life start_reusing start_suppressing duration_to_suppress   设置BGP路由冷落参数
R(config-route-map)# set default interface type [slot_#/] port_#    设置默认的输出接口
R(config-route-map)# set interface type [slot_#/] port_#    设置输出接口
R(config-route-map)# set ip default next-hop IP_address 设置路径的默认下一跳地址
R(config-route-map)# set ip next-hop IP_address 设置下一跳地址
R(config-route-map)# set ip precedence [precedence] 设置“IP Precedence”字段
R(config-route-map)# set ip tos type_of_service 设置“IP服务类型”字段
R(config-route-map)# set level level    设置导入路由的位置
R(config-route-map)# set local-preference value 设置BGP LOCAL_PREF路径属性
R(config-route-map)# set metric value   设置目标路由协议的度量值
R(config-route-map)# set metric-type type_of_route  设置目标路由协议的度量类型
R(config-route-map)# set origin origin_code 设置BGP源代码
R(config-route-map)# set tag value  设置目标路由协议的标记值
R(config-route-map)# set weight value   设置路由表的BGP权重
R(config-router)# neighbor IP_address_remote_device route-map route_map_name [in|out]   应用从邻居输入的路由映射
R(config-router)# neighbor IP_address_remote_device send-community  向该邻居发送COMMUNITY属性
R(config)# ip community-list community_list_# [permit|deny] community_list_#    创建团体列表
R(config-router)# neighbor peer_group_name peer-group   创建对等组
R(config-router)# neighbor peer_group_name option_to_use_in_update_policy   给对等组分配选项
R(config-router)# neighbor IP_address_remote_device peer-group peer_group_name  给对等组分配对等体
R(config-router)# no auto-summary   取消BGP的自动路由汇总功能
R(config-router)# aggregate-address IP_address mask [summary-only]  创建汇聚地址（禁止通告其他特定路由）
R(config-router)# aggregate-address IP_address mask as-set  创建汇聚地址，在AS_PATH中添加AS_SET类型
R# clear ip bgp peer_address    重设特定BGP对等会话
R# clear ip bgp AS_#    重设指定自治系统的所有对等体的BGP会话
R# clear ip bgp *   重设路由器上所有BGP会话
R# show ip bgp  查看路由器从BGP学习到的所有路由
R# show ip bgp summary  提供和路由器具有对等关系的所有路由器汇总
R# show ip bgp neighbors    查看对等体连接详细信息
R# debug ip bgp 查看在本地路由器与试图和其建立对等关系的路由器之间所发送和接收的OPEN信息
R# debug ip bgp updates 提供路由器发送和接收所有UPDATE消息的信息
R# debug ip bgp peer_address upadtes    提供关于BGP对等体之间发送的UPDATE消息
R# debug ip bgp dampening   显示关于被冷落路由的信息
R# debug ip bgp events  提供关于尝试成为BGP对等体的路由器的状态转换信息
R# debug ip bgp keepalives  提供关于路由器发送和接收KEEPALIVE消息的信息
```

#### 22.路由优化

```
R(config-router)# distribute-list ACL_#|prefix prefix_list_name in|out [type [slot_#/] port_#]   配置分配列表
R(config-if)# ip policy route-map map_tag   识别一个接口上基于策略的路由选择使用的路由映射
R# show ip policy   列出所有配置为基于策略的路由选择的接口及它们相关的路由映射
R# show route-map   查看所有路由映射
R# debug ip policy  提供在该路由器上执行的路由策略的信息
R(config-router)# default-information originate 重新分配默认路由到OSPF和IS-IS
R(config-router)# default-information originate always  引起一个默认路由到OSPF不管路由表中是否有一个默认路由
R(config-router)# redistribute protocol [process-ID] level-1|level-1-2|level-2 [metric metric_value] [metric-type type_value] [match internal|external 1|external 2] [tag tag_value] [route-map map_tag] [weight weight_value] [subnets]    重新分配路由选择信息从一个路由选择域到另一个路由选择域
R(config-router)# summary-address network_address network_mask [level-1|level-1-2|level-2]  为起源于和重新分配到IS-IS的路由创建一个汇总地址
```

#### 23.异步连接

```
R# line number  进入线路配置模式
R(config-line)# login   允许一个连接
R(config-line)# password password   提供线路上使用的口令
R(config-line)# flowcontrol hardware|software   选择硬件流控制或软件流控制
R(config-line)# speed number    指定调制解调器和访问服务器或路由器之间使用的最大速度（单位：bps）
R(config-line)# transport input lat|mop|nasi|pad|rlogin|telnet|v120|all 定义反向Telnet连接使用的协议
R(config-line)# stopbits 1|1.5|2    定义每个字节的结束
R(config-line)# modem autoconfigure type modem_type 指示路由器使用modemcap数据库中的命令按照指定的类型对连接到一个端口上的调制解调器进行自动配置
R# show modemcap    显示modemcap数据库
R(config-line)# modem edit modem_profile_name   向modemcap数据库增加条目
R(config-line)# modemcap edit new_profile_name template existing_profile_name   创建名为new_profile_name的条目并从existing_profile_name中拷贝所有的配置
R(config-line)# modem autoconfigure discovery   发现和自动配置连接到一个端口上的调制解调器
```

#### 24.QoS

```
R(config-if)# standby ip IP_address 配置HSRP
R(config-if)# standby preempt   配置占先操作
R(config-if)# standby track type_of_interface   配置接口跟踪
R# show standby 查看HSRP组的动态信息
R(config-if)# glbp group_number ip [IP_address [secondary]] 配置GLBP
R(config-if)# glbp group_number priority priority_number    配置优先级
```

