cmd_/home/ryan/driver-convert/driver/Module.symvers := sed 's/\.ko$$/\.o/' /home/ryan/driver-convert/driver/modules.order | scripts/mod/modpost -m -a  -o /home/ryan/driver-convert/driver/Module.symvers -e -i Module.symvers   -T -