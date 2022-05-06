cmd loop

``` bash
for /l %x in (1, 1, 9) do copy test.exe \\507-0%x\Users\Administrator\Desktop

for /l %x in (10, 1, 50) do copy test.exe \\507-%x\Users\Administrator\Desktop

```

Msg

``` bash
Msg /server:192.168.1.154 * "你好，局域网用户！"

# bat
for /l %i in (1, 1, 254) do Msg /server:192.168.37.%i * "你好！"
```

用IP代替主机名可省一条命令

