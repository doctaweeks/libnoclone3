#define _GNU_SOURCE
#include <stdlib.h>
#include <seccomp.h>
#include <errno.h>

void __attribute__((constructor)) init(void)
{
	char *use = secure_getenv("NOCLONE3");

	scmp_filter_ctx ctx;
	ctx = seccomp_init(SCMP_ACT_ALLOW);
	seccomp_rule_add(ctx, SCMP_ACT_ERRNO(ENOSYS), SCMP_SYS(clone3), 0);
	if (use != NULL)
		seccomp_load(ctx);
}
