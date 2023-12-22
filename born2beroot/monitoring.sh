#!/bin/bash

arc=$(uname -a)
phycpu=$(grep 'physical id' /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep 'processor' /proc/cpuinfo | uniq | wc -l)
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free -m | awk '$1 == "Mem:" {printf("%.2f%%"), $3/$2*100}')
tdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{td += $2} END {print td}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ud += $3} END {print ud}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{td += $2} {ud += $3} END {printf("%d%%"), ud/td*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
sysb=$(who -b | grep 'system boot' | xargs | awk '{print $3, $4}')
lvm=$(lsblk | grep 'lvm' | wc -l | awk '{lvm = ($1 > 0) ? "yes" : "no"; print lvm}')
tcp=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')
sudos=$(journalctl _COMM=sudo | grep 'COMMAND' | wc -l)

wall "	#Architecture: $arc
	#CPU physical: $phycpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${tram}MB ($pram)
	#Disk Usage: $udisk/${tdisk}Gb ($pdisk)
	#CPU load: $cpul
	#Last boot: $sysb
	#Lvm use: $lvm
	#Connections TCP : $tcp ESTABLISHED
	#User log: $ulog 
	#Network: IP $ip ($mac)
	#Sudo: $sudos cmd"
	
