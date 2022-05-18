# NAT

NAT Network Address Translation 网络地址转换

---



## 静态 NAT

PC 与 路由器之间用**交叉线**，我用了直通线，故线不绿。




## 动态 NAT

P204

###### 配置默认路由

> RouterA (config) # ip route 210.1.1.0 255.255.255.0 200.1.1.2
>
> 
>
> RouterB (config) # ip route 192.168.1.0 255.255.255.0 200.1.1.1
>
> RouterB (config) # ip route 192.168.2.0 255.255.255.0 200.1.1.1

###### 定义内部及外部端口

> RouterA (config) # intreface FastEthernet 0/0
>
> RouterA (config-if) # ip nat inside
>
> RouterA (config-if) # exit
>
> 
>
> RouterA (config) # interface FastEthernet 0/1
>
> RouterA (config-if) # ip nat inside
>
> RouterA (config-if) # exit
>
> 
>
> RouterA (config) # interface Serial 0/0/0
>
> RouterA (config-if) # ip nat outside
>
> RouterA (config) # exit

###### 定义内部全局地址池

地址池名称为 test ，范围为从 200.1.1.1 到 200.1.1.2

> RouterA (config) # ip nat pool test 200.1.1.1 200.1.1.3 netmask 255.255.255.252

使用其他范围测试

> RouterA (config) # ip nat pool test 200.1.1.1 200.1.1.4 netmask 255.255.255.252
>
> %Pool test mask 255.255.255.252 too small; should be at least 255.255.255.252
>
> %Start and end addresses on different subnets

尽量不用端口地址 `200.1.1.1` 

###### 定义允许转换的地址

允许 192.168.1.0 和 192.168.2.0 网络地址转换：

> RouterA (config) # access-list 1 permit 192.168.1.0 0.0.0.255
>
> RouterA (config) # access-list 1 permit 192.168.2.0 0.0.0.255

###### 建立映射关系

> RouterA (config) # ip nat inside source list 1 pool test

## 端口 NAT - PAT

###### 定义内部全局地址池

地址池名称为 test ，范围为从 200.1.1.1 到 200.1.1.1

> RouterA (config) # ip nat pool test 200.1.1.1 200.1.1.1 netmask 255.255.255.252

###### 定义允许转换的地址

允许 192.168.1.0 和 192.168.2.0 网络地址转换：

> RouterA (config) # access-list 1 permit 192.168.1.0 0.0.0.255
>
> RouterA (config) # access-list 1 permit 192.168.2.0 0.0.0.255

###### 建立映射关系

> RouterA (config) # ip nat inside source list 1 pool test overload


---
- [Cisco基础(五)：配置静态NAT、配置端口映射、配置动态NAT、PAT配置、办公区Internet的访问](https://www.cnblogs.com/baichuanhuihai/p/8277614.html)  
- [思科模拟器 PacketTracer 删除nat地址池步骤](https://blog.csdn.net/qq_39827677/article/details/103350881)
