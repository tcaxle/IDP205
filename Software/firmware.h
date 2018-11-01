/*
Interfaces between software and hardware
Allows for easy reconfiguration if I/O changes
Makes programming rest of files easier:
	"LED0=1" instead of "0x679=xx10xx1" etc.
*/

#include <iostream>
#include "classes.h"
