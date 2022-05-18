# ACL

ACL Access Control Lists 访问控制列表

---

#### 交换机标准访问控制的配置 P158

第一步：定义标准访问控制

> Switch (config) # access-list `access-list number` { permit / deny } source { source mask }

access-list number: 访问列表序号，范围是1~99；

permit / deny: 允许/禁止满足条件的数据包通过；

source: 过滤数据包的源 IP 地址；

source mask: 通配屏蔽码，1：不检查位，0：必须匹配位。

> S3560 (config) # access-list 1 deny 192.168.2.0 0.0.0.255
>
> S3560 (config) # access-list 1 permit 192.168.1.0 0.0.0.255

第二步：应用在三层交换机 S3560 的 VLAN30 虚拟接口输出方向上

> S3560 (config) # interface vlan 30
>
> S3560 (config-if) # ip access-group 1 out
>
> S3560 (config-if) # exit



###### 拒绝特定主机 192.168.10.1 的流量，但允许其他的所有主机

> Switch (config) # access-list 1 deny host 192.168.10.1
>
> Switch (config) # access-list 1 permit any
