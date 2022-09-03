## CentOS Stream 9 OpenStack 体验

``` bash
# 安装 python3-pip

```

安装组件十分顺利

12:39 ./stack.sh

12:46 报错：
```
[Call Trace]
./stack.sh:513:check_path_perm_sanity
/opt/stack/devstack/functions:612:die
[ERROR] /opt/stack/devstack/functions:612 Invalid path permissions
```


12:50 ./stack.sh

12:56 报错：

```
ERROR: Cannot uninstall requests 2.25.1, RECORD file not found. Hint: The package was installed by rpm.
+inc/python:pip_install:1                  exit_trap
+./stack.sh:exit_trap:521                  local r=1
++./stack.sh:exit_trap:522                  jobs -p
+./stack.sh:exit_trap:522                  jobs=
+./stack.sh:exit_trap:525                  [[ -n '' ]]
+./stack.sh:exit_trap:531                  '[' -f '' ']'
+./stack.sh:exit_trap:536                  kill_spinner
+./stack.sh:kill_spinner:431               '[' '!' -z '' ']'
+./stack.sh:exit_trap:538                  [[ 1 -ne 0 ]]
+./stack.sh:exit_trap:539                  echo 'Error on exit'
Error on exit
+./stack.sh:exit_trap:541                  type -p generate-subunit
+./stack.sh:exit_trap:544                  [[ -z /opt/stack/logs ]]
+./stack.sh:exit_trap:547                  /bin/python3.9 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-10-125553.txt for details
+./stack.sh:exit_trap:556                  exit 1

```

发现了一个意外的警告：
``` bash
WARNING: Running pip as the 'root' user can result in broken permissions and conflicting behaviour with the system package manager. It is recommended to use a virtual environment instead: https://pip.pypa.io/warnings/venv
```

用 rpm -qa | grep requests 查询：
```
python3-requests-2.25.1-6.el9.noarch
```

用 pip show --files requests 查询：
```
Name: requests
Version: 2.27.1
......
```

```
bin/python3.9 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-10-132517.txt for details
+./stack.sh:exit_trap:556                  exit 1
```

烦死了！重启！

14:15 ./stack.sh

14:25 报错：
```
/opt/stack/devstack/functions-common: line 2458: openstack: command not found
++functions-common:oscwrap:2465             return 127
+lib/keystone:create_keystone_accounts:310  admin_project=
+lib/keystone:create_keystone_accounts:1   exit_trap
+./stack.sh:exit_trap:521                  local r=127
++./stack.sh:exit_trap:522                  jobs -p
+./stack.sh:exit_trap:522                  jobs=48841
+./stack.sh:exit_trap:525                  [[ -n 48841 ]]
+./stack.sh:exit_trap:525                  [[ -n '' ]]
+./stack.sh:exit_trap:531                  '[' -f /tmp/tmp.YrSlDxwfQR ']'
+./stack.sh:exit_trap:532                  rm /tmp/tmp.YrSlDxwfQR
+./stack.sh:exit_trap:536                  kill_spinner
+./stack.sh:kill_spinner:431               '[' '!' -z '' ']'
+./stack.sh:exit_trap:538                  [[ 127 -ne 0 ]]
+./stack.sh:exit_trap:539                  echo 'Error on exit'
Error on exit
+./stack.sh:exit_trap:541                  type -p generate-subunit
+./stack.sh:exit_trap:544                  [[ -z /opt/stack/logs ]]
+./stack.sh:exit_trap:547                  /bin/python3.9 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-10-142547.txt for details
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
+./stack.sh:exit_trap:556                  exit 127

```
14:36 报错：
```
/opt/stack/devstack/functions-common: line 2458: openstack: command not found
++functions-common:oscwrap:2465             return 127
+lib/keystone:create_keystone_accounts:310  admin_project=
+lib/keystone:create_keystone_accounts:1   exit_trap
+./stack.sh:exit_trap:521                  local r=127
++./stack.sh:exit_trap:522                  jobs -p
+./stack.sh:exit_trap:522                  jobs=89645
+./stack.sh:exit_trap:525                  [[ -n 89645 ]]
+./stack.sh:exit_trap:525                  [[ -n '' ]]
+./stack.sh:exit_trap:531                  '[' -f /tmp/tmp.G1DrYg9H3K ']'
+./stack.sh:exit_trap:532                  rm /tmp/tmp.G1DrYg9H3K
+./stack.sh:exit_trap:536                  kill_spinner
+./stack.sh:kill_spinner:431               '[' '!' -z '' ']'
+./stack.sh:exit_trap:538                  [[ 127 -ne 0 ]]
+./stack.sh:exit_trap:539                  echo 'Error on exit'
Error on exit
+./stack.sh:exit_trap:541                  type -p generate-subunit
+./stack.sh:exit_trap:544                  [[ -z /opt/stack/logs ]]
+./stack.sh:exit_trap:547                  /bin/python3.9 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-10-143630.txt for details
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
+./stack.sh:exit_trap:556                  exit 127

```
始终报错，没办法



4月17日留言：虽然如此，但我感觉这是最后一个且无法解决的错误
