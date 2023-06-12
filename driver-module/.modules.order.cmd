cmd_/home/ryan/driver-convert/driver/modules.order := {   echo /home/ryan/driver-convert/driver/driver_cd.ko; :; } | awk '!x[$$0]++' - > /home/ryan/driver-convert/driver/modules.order
