###### 17:28
``` bash
# 安装 python3-pip
sudo apt-get install python3-pip
```

###### 报错 ：没有可用的软件包 python3-pip，但是它被其它的软件包引用了。这可能意味着这个缺失的软件包可能已被废弃，或者只能在其他发布源中找到
``` bash
sudo apt-get update
```

``` bash
# 再次尝试安装 python3-pip
sudo apy-get isntall python3-pip
```

###### 在安装组件的时候，我意识到我有必要在真机上弄一份，要不然每次都是漫长的等待

###### 18:07 组件传完了
``` bash
su root
# 更改目录下所有文件所有者为 stack
chwon -R stack:stack *
```
###### 18:12 ./stack.sh
###### 报错：: /usr/bin/env: "bash\r": 没有那个文件或目录。原因可能是因为我在Windows下下载的组件 stack.sh 格式是 dos ()


## 第二天
13:12
13:31 使用 vim stack.sh :set ff 查看格式为 unix
13:33 ./stack.sh
报错无法解决，告辞