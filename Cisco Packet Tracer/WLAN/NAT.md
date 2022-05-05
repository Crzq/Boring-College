# NAT - Network Address Translation

内部局部（inside local）地址：在内部网络中使用的地址，通常是RFC1918（私有地址）；
内部全局（inside global）地址：用来代替一个或多个本地IP地址的、对外的、注册过的合法的公有IP地址；
外部局部（outside local）地址：一个外部主机相对于内部网络所用的IP地址，不一定是合法的公有IP地址；
外部全局（outside global）地址：外部网络主机的合法的公有IP地址

#### RIP

``` 
router rip
version 2
network + 网络地址
```



动态NAT的过期时间是86400秒，PAT的过期时间是60秒，通过命令 “show ip nat translations verbose” 可以查看

修改过期时间：

(config)# ip nat translation timeout 过期时间 (0-2147483)



如果主机的数量不是很多，可以直接使用outside接口地址配置PAT，不用定义地址池：

ip nat inside source list 序号 interface s0/0 overload

映射的内部全局地址尽量不使用outside的地址（s口地址）



 [Cisco Packet Tracer 命令大全 【思科交换机模拟器命令大全】](https://blog.csdn.net/VariatioZbw/article/details/108212741?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165164632316781483798231%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=165164632316781483798231&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-108212741.nonecase&utm_term=cisco&spm=1018.2226.3001.4450)



