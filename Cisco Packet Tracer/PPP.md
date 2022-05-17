# 广域网链路层协议

PPP Point-to-Point Protocol 点对点协议

HDLC High-Level Data Link Control 高级数据链路控制

PAP Password Authentication Protocol 密码认证协议

CHAP Challege Handshake Authentication Protocol 挑战握手认证协议

---

## 配置 PPP 协议

###### 使用 `show interface` 来查看串口封装协议

> Router # show interface [interface name]

配置完后，注意通过 `show interface` 查看端口情况

> Router (config) # interface Serial 0/0/0
>
> Router (config-if) # encapsulation ppp

###### 配置 R1 和 R2 之间的 PPP PAP 身份验证

> > R1 (config) # username R2 secret class
> >
> > R1 (config) # interface Serial 0/0/0
> >
> > R1 (config-if) # ppp authentication pap
> >
> > R1 (config-if) # ppp pap sent-username R1 password cisco
>
> `ppp pap sent-username R1 password cisco` 中的 `password` 指的就是密码，包括明文形式的 **password** 和 加密的 **secret**
>
> > R2 (config) # username R1 secret cisco
> >
> > R2 (config) # interface Serial 0/0/0
> >
> > R2 (config-if) # ppp authentication pap
> >
> > R2 (config-if) # ppp pap sent-username R2 password class

###### 配置 R3 和 ISP 之间的 PPP CHAP 身份验证

> >  Router (config) # hostname ISP
> >
> >  ISP (config) # username R3 secret cisco
> >
> > ISP (config) # interface Serial 0/0/0
> >
> > ISP (config-if) # ppp authentication chap
>
> > R3 (config) # username ISP secret cisco
> >
> > R3 (config) # interface Serial 0/1/0
> >
> > R3 (config-if) # ppp authentication chap


## show interface 与 show ip interface

字段项是 up ，则表示处理行协议和软件过程相信此接口可用，因为它正在接收 keep alives 的目的也是如此，其他设备可以确定某个空闲连接是否仍然活动； down 则相反。



###### show interface

`show interface` 查看的是某个 interface 的物理层和数据链路层的信息。它给出了硬件地址、逻辑地址和封装方式的信息。

1. 注意第一行的分析：

> Serial 0 is administratively down, line protocol is down

这种情况，第一个参数涉及**物理层**，如果它接收到载波检测信号，该 interface 就是激活的。

2. 如果这是一个 DTE 的 Serial 口，在端口配置模式下，用 `no shutdown` ，结果如下：

> Serial 0 is up, line protocol is down

这是物理层已经激活了，但 `line protocol is down` 是什么意思呢？其实，这个涉及到**数据链路层**，它从连接端查找保持激活信息（保持激活信息是用于两个设备之间确认连通性的可用的），如果这个线路是激活的，但协议是关闭的，则说明出现了时钟（保持激活信息）或帧方面的问题，应该是对应的 DCE 端的**时钟**（clock rate）没有配置或**封装类型**（encapsulation）配置不一致或者**电缆**坏了。这是数据链路层的问题。

3. 我们在对应的 DCE 端设置：

> Router (config-if) # clock rate 64000

接下来再查看如下：

> Serial 0 is up, line protocol is up

4. 如果我们画蛇添足，在 DCE 端设置：

> Router (config-if) # encapsulation ppp // 或 Router (config-if) # encapsulation frame-relay

那在 DTE 端结果如下：

> Serial 0 is up, line protocol is down

显然这是数据链路层的问题，因为 DTE 端默认的封装类型是 HDLC。



###### show ip interface

`show ip interface` 提供路由器 interface 的第三层配置信息。包括接口状态、 IP 地址、子网掩码、基本的 IP 信息和访问列表。



###### show protocols

`show protocols` 查看每个端口的第一、二层连接情况，包括 IP 地址的状态。





## 七层模型 OSI (Open System Interconnection)

| 模型       | 主要协议                                                   | 数据单位 |
| ---------- | ---------------------------------------------------------- | -------- |
| 应用层     | Telnet, FTP, HTTP, WWW, SMTP                               |          |
| 表示层     | ASCII, JPEG, GIF, HTML                                     |          |
| 会话层     | SQL, NFS                                                   |          |
| 传输层     | TCP, UDP                                                   |          |
| 网络层     | IP, RIP, OSPF, ARP, RARP                                   |          |
| 数据链路层 | Frame Relay, HDLC, PPP, IEEE 802.3/802.2, IEEE 802.5/802.2 |          |
| 物理层     | RJ45, Ethernet                                             |          |

SMTP Simple Mail Transfer Protocol



