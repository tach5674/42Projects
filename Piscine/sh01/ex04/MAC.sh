ifconfig | grep ether | awk '{print $2}' | grep -v "autoselect"
