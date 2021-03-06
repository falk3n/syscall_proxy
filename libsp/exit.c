#include "libsp.h"

void sp_exit(int status)
{
	struct syscall_regs regs;
	
	SEND_LEN(sizeof(regs));
	GET_ESP(NULL);

	SET_REGS(&regs, __NR_exit, status, 0, 0, 0, 0);
	SEND_REGS(&regs);
	RECV_REGS(&regs);
}
