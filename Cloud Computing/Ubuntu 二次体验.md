## ubuntu
17:42
Alt+F7 拖拽窗口
（下语言包、软件包花费了太多时间）
用我安好的纯净版罢了
18:31

提示：如果你成功安装了 VMware Tools,那么你可直接点击右侧的复制代码进行操作

sudo apt install vim
sudo apt install git

开始安装组件
18:57  组件安装完成(取决于网速)

19：00 ./stack.sh
19:15 分 ENTER A PASSWORD TO USE FOR THE DATABASE
ENTER A PASSWORD TO USE FOR ......
...... (原因找到了，要在 devstack目录创建 local.conf)
19:33 中途报错 ERROR: launchpadlib 1.10.13 requires testresources, which is not installed.（这个要提前安装？？）
19：34 报错 bdist_whell (其实是警告)


21：00 安装完毕，报错
-------------------------------------------------------------------------------------------------------------------------------------------

+lib/nova:create_flavors:1222              openstack --os-region-name=RegionOne flavor create --id 5 --ram 16384 --disk 160 --vcpus 8 --property hw_rng:allowed=True m1.xlarge
/usr/lib/python3/dist-packages/secretstorage/dhcrypto.py:15: CryptographyDeprecationWarning: int_from_bytes is deprecated, use int.from_bytes instead
  from cryptography.utils import int_from_bytes
/usr/lib/python3/dist-packages/secretstorage/util.py:19: CryptographyDeprecationWarning: int_from_bytes is deprecated, use int.from_bytes instead
  from cryptography.utils import int_from_bytes
+----------------------------+-----------------------+
| Field                      | Value                 |
+----------------------------+-----------------------+
| OS-FLV-DISABLED:disabled   | False                 |
| OS-FLV-EXT-DATA:ephemeral  | 0                     |
| description                | None                  |
| disk                       | 160                   |
| id                         | 5                     |
| name                       | m1.xlarge             |
| os-flavor-access:is_public | True                  |
| properties                 | hw_rng:allowed='True' |
| ram                        | 16384                 |
| rxtx_factor                | 1.0                   |
| swap                       |                       |
| vcpus                      | 8                     |
+----------------------------+-----------------------+
[4945 Async create_flavors:148098]: finished create_flavors with result 0 in 27 seconds
+inc/async:async_wait:197                  return 0
+./stack.sh:main:1364                      is_service_enabled horizon
+functions-common:is_service_enabled:2052  local xtrace
++functions-common:is_service_enabled:2053  set +o
++functions-common:is_service_enabled:2053  grep xtrace
+functions-common:is_service_enabled:2053  xtrace='set -o xtrace'
+functions-common:is_service_enabled:2054  set +o xtrace
+functions-common:is_service_enabled:2081  return 0
+./stack.sh:main:1365                      echo_summary 'Starting Horizon'
+./stack.sh:echo_summary:440               [[ -t 3 ]]
+./stack.sh:echo_summary:440               [[ True != \T\r\u\e ]]
+./stack.sh:echo_summary:446               echo -e Starting Horizon
2022-04-06 13:03:06.351 | Starting Horizon
+./stack.sh:main:1366                      init_horizon
+lib/horizon:init_horizon:145              sudo rm -f '/var/log/apache2/horizon_*'
+lib/horizon:init_horizon:148              local django_admin
+lib/horizon:init_horizon:149              type -p django-admin
+lib/horizon:init_horizon:152              django_admin=django-admin.py
+lib/horizon:init_horizon:156              DJANGO_SETTINGS_MODULE=openstack_dashboard.settings
+lib/horizon:init_horizon:156              django-admin.py collectstatic --noinput
/opt/stack/devstack/lib/horizon: line 156: django-admin.py: command not found
+lib/horizon:init_horizon:1                exit_trap
+./stack.sh:exit_trap:521                  local r=127
++./stack.sh:exit_trap:522                  jobs -p
+./stack.sh:exit_trap:522                  jobs=101574
+./stack.sh:exit_trap:525                  [[ -n 101574 ]]
+./stack.sh:exit_trap:525                  [[ -n '' ]]
+./stack.sh:exit_trap:531                  '[' -f /tmp/tmp.QNeaAxAxxz ']'
+./stack.sh:exit_trap:532                  rm /tmp/tmp.QNeaAxAxxz
+./stack.sh:exit_trap:536                  kill_spinner
+./stack.sh:kill_spinner:431               '[' '!' -z '' ']'
+./stack.sh:exit_trap:538                  [[ 127 -ne 0 ]]
+./stack.sh:exit_trap:539                  echo 'Error on exit'
Error on exit
+./stack.sh:exit_trap:541                  type -p generate-subunit
+./stack.sh:exit_trap:542                  generate-subunit 1649242702 7484 fail
+./stack.sh:exit_trap:544                  [[ -z /opt/stack/logs ]]
+./stack.sh:exit_trap:547                  /usr/bin/python3.8 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-06-130307.txt for details
+./stack.sh:exit_trap:556                  exit 127
stack@ibuntu:~/devstack$ cat /opt/stack/logs/worlddump-2022-04-06-130307.txt

-------------------------------------------------------------------------------------------------------------------------------------------
尝试安装了 uwsgi
(发现自己虚拟机启动好慢呐)


报错
-------------------------------------------------------------------------------------------------------------------------------------------
openvswitch/ovnnb_db.sock not found'
+functions-common:die:264                  local exitcode=0
+functions-common:die:265                  set +o xtrace
[Call Trace]
./stack.sh:1282:start_ovn_services
/opt/stack/devstack/lib/neutron-legacy:516:start_ovn
/opt/stack/devstack/lib/neutron_plugins/ovn_agent:698:wait_for_sock_file
/opt/stack/devstack/lib/neutron_plugins/ovn_agent:178:die
[ERROR] /opt/stack/devstack/lib/neutron_plugins/ovn_agent:178 Socket /var/run/openvswitch/ovnnb_db.sock not found
Error on exit
World dumping... see /opt/stack/logs/worlddump-2022-04-06-232216.txt for details
-------------------------------------------------------------------------------------------------------------------------------------------

8:06  ./clean.sh（真的什么都给我卸了。。。）
调整local.conf的位置，开始重装
-------------------------------------------------------------------------------------------------------------------------------------------

+lib/neutron_plugins/ovn_agent:install_ovn:363  sudo ln -s /var/run/openvswitch /var/run/ovn
ln: 无法创建符号链接 '/var/run/ovn/openvswitch': 文件已存在
+lib/neutron_plugins/ovn_agent:install_ovn:1  exit_trap
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
+./stack.sh:exit_trap:542                  generate-subunit 1649289989 148 fail
+./stack.sh:exit_trap:544                  [[ -z /opt/stack/logs ]]
+./stack.sh:exit_trap:547                  /usr/bin/python3.8 /opt/stack/devstack/tools/worlddump.py -d /opt/stack/logs
World dumping... see /opt/stack/logs/worlddump-2022-04-07-000857.txt for details
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
ovs-vsctl: unix:/var/run/openvswitch/db.sock: database connection failed (No such file or directory)
-------------------------------------------------------------------------------------------------------------------------------------------


......

由于关机开机，许多服务停止了，加上一些新的报错，决定重开


关于教室演示：
教室网是局域网吗
多人同时下东西影响网速吗

局域网互相访问





